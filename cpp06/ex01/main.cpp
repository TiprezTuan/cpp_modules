/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:41:11 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/01 15:13:00 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

static void printHeader(const std::string& title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << " " << title << std::endl;
	std::cout << "========================================" << std::endl;
}

int main(void)
{
	/* --------------------------------------------------------------------- */
	/* 1. TEST SUR LA PILE (STACK)                                          */
	/* --------------------------------------------------------------------- */
	printHeader("1. Test allocation sur la Pile (Stack)");

	Data dataStack;
	dataStack.id = 42;
	dataStack.message = "Hello 42 Paris!";

	std::cout << "[Origine]  Pointeur: " << &dataStack
	          << " | ID: " << dataStack.id
	          << " | Msg: \"" << dataStack.message << "\"" << std::endl;

	uintptr_t rawStack = Serializer::serialize(&dataStack);
	std::cout << "[RAW]      uintptr_t: 0x" << std::hex << rawStack << std::dec << std::endl;

	Data* deserializedStack = Serializer::deserialize(rawStack);
	std::cout << "[Restauré] Pointeur: " << deserializedStack
	          << " | ID: " << deserializedStack->id
	          << " | Msg: \"" << deserializedStack->message << "\"" << std::endl;

	if (&dataStack == deserializedStack)
		std::cout << "--> SUCCÈS : Les adresses de pointeurs sont identiques !" << std::endl;
	else
		std::cout << "--> ÉCHEC : Les adresses diffèrent !" << std::endl;


	/* --------------------------------------------------------------------- */
	/* 2. TEST SUR LE TAS (HEAP)                                            */
	/* --------------------------------------------------------------------- */
	printHeader("2. Test allocation sur le Tas (Heap)");

	Data* dataHeap = new Data;
	dataHeap->id = 100;
	dataHeap->message = "Allocation dynamique";

	std::cout << "[Origine]  Pointeur: " << dataHeap
	          << " | ID: " << dataHeap->id
	          << " | Msg: \"" << dataHeap->message << "\"" << std::endl;

	uintptr_t rawHeap = Serializer::serialize(dataHeap);
	Data* deserializedHeap = Serializer::deserialize(rawHeap);

	std::cout << "[Restauré] Pointeur: " << deserializedHeap
	          << " | ID: " << deserializedHeap->id
	          << " | Msg: \"" << deserializedHeap->message << "\"" << std::endl;

	// Modification de la donnée via le pointeur désérialisé
	deserializedHeap->message = "Modifié via le pointeur désérialisé";
	std::cout << "[Modifié]  Nouveau message dans l'original: \"" << dataHeap->message << "\"" << std::endl;

	if (dataHeap == deserializedHeap)
		std::cout << "--> SUCCÈS : Les adresses de pointeurs sont identiques !" << std::endl;
	else
		std::cout << "--> ÉCHEC : Les adresses diffèrent !" << std::endl;

	// Libération de la mémoire pour éviter les leaks sous Valgrind
	delete dataHeap;


	/* --------------------------------------------------------------------- */
	/* 3. TEST POINTEUR NULL                                                */
	/* --------------------------------------------------------------------- */
	printHeader("3. Test cas limite : Pointeur NULL");

	Data* nullPtr = NULL;
	uintptr_t rawNull = Serializer::serialize(nullPtr);
	Data* deserializedNull = Serializer::deserialize(rawNull);

	std::cout << "[NULL] Pointeur d'origine : " << nullPtr << std::endl;
	std::cout << "[NULL] raw uintptr_t     : " << rawNull << std::endl;
	std::cout << "[NULL] Pointeur restauré : " << deserializedNull << std::endl;

	if (deserializedNull == NULL)
		std::cout << "--> SUCCÈS : La sérialisation de NULL est correctement gérée !" << std::endl;
	else
		std::cout << "--> ÉCHEC !" << std::endl;

	return 0;
}