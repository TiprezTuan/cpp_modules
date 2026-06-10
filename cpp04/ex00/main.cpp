/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:10:23 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 17:56:13 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <string>

int main(void)
{
	/*__________________________________________________________________________*/
	std::cout << "---------- Animal ----------"						<< std::endl;
	
	const Animal*	animal	= new Animal();
	const Animal*	dog		= new Dog();
	const Animal*	cat		= new Cat();

	std::cout << "Animal type  = " << animal->getType()				<< std::endl;
	std::cout << "Dog    type  = " << dog->getType()				<< std::endl;
	std::cout << "Cat    type  = " << cat->getType()				<< std::endl;

	std::cout << "Animal sound = ";
	animal->makeSound();
	std::cout << "Dog    sound = ";
	dog->makeSound();
	std::cout << "Cat    sound = ";
	cat->makeSound();

	/*__________________________________________________________________________*/
	std::cout << "\n---------- WrongAnimal ----------"				<< std::endl;
	
	const WrongAnimal*	wrongAnimal	= new WrongCat();
	const WrongCat*		wrongCat	= new WrongCat();
	
	std::cout << "WrongAnimal type  = " << wrongAnimal->getType()	<< std::endl;
	std::cout << "WrongCat    type  = " << wrongCat->getType()		<< std::endl;

	std::cout << "WrongAnimal sound = ";
	wrongAnimal->makeSound();
	std::cout << "WrongCat    sound = ";
	wrongCat->makeSound();

	delete wrongAnimal, wrongCat, animal, dog, cat;

	return (0);
}
