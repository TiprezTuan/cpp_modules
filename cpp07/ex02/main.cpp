#include <iostream>
#include <string>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

int	main()
{
	std::cout	<<	"=== 1. Test du constructeur par defaut ==="	<<	std::endl;
	Array<int>	emptyArray;
	std::cout	<<	"Taille du tableau vide : "	<<	emptyArray.size()	<<	std::endl;

	std::cout	<<	"\n=== 2. Test du constructeur avec taille & initialisation ==="	<<	std::endl;
	Array<int>	numbers(MAX_VAL);
	std::cout	<<	"Taille du tableau numbers : "	<<	numbers.size()	<<	std::endl;

	bool	allZero	=	true;
	for	(int	i	=	0;	i	<	MAX_VAL;	i++)
	{
		if	(numbers[i]	!=	0)
		{
			allZero	=	false;
			break;
		}
	}
	if	(allZero)
		std::cout	<<	"[OK] Tous les elements sont correctement initialises a 0."	<<	std::endl;
	else
		std::cout	<<	"[ERREUR] Les elements ne sont pas initialises a 0."	<<	std::endl;

	std::cout	<<	"\n=== 3. Test d'ecriture et de lecture ==="	<<	std::endl;
	for	(int	i	=	0;	i	<	MAX_VAL;	i++)
	{
		numbers[i]	=	i;
	}

	bool	success	=	true;
	for	(int	i	=	0;	i	<	MAX_VAL;	i++)
	{
		if	(numbers[i]	!=	i)
		{
			std::cerr	<<	"[ERREUR] Valeur incorrecte a l'index "	<<	i	<<	std::endl;
			success	=	false;
			break;
		}
	}
	if	(success)
		std::cout	<<	"[OK] Lecture et ecriture reussies sur tout le tableau."	<<	std::endl;

	std::cout	<<	"\n=== 4. Test de la copie profonde (Deep Copy) ==="	<<	std::endl;
	
	Array<int>	copy(numbers);
	
	numbers[0]	=	42;
	
	if	(copy[0]	==	0	&&	numbers[0]	==	42)
	{
		std::cout	<<	"[OK] Constructeur par copie : Copie profonde verifiee."	<<	std::endl;
	}
	else
	{
		std::cout	<<	"[ERREUR] Constructeur par copie : Copie superficielle detectee !"	<<	std::endl;
	}

	Array<int>	assigned;
	assigned	=	copy;
	copy[1]	=	99;

	if	(assigned[1]	==	1	&&	copy[1]	==	99)
	{
		std::cout	<<	"[OK] Operateur d'affectation : Copie profonde verifiee."	<<	std::endl;
	}
	else
	{
		std::cout	<<	"[ERREUR] Operateur d'affectation : Copie superficielle detectee !"	<<	std::endl;
	}

	std::cout	<<	"\n=== 5. Test des exceptions (Depassement de limites) ==="	<<	std::endl;
	
	try
	{
		numbers[-1]	=	0;
		std::cout	<<	"[ERREUR] Aucune exception lancee pour un index negatif !"	<<	std::endl;
	}
	catch	(const	std::exception&	e)
	{
		std::cout	<<	"[OK] Exception attrapee avec succes pour l'index -1 : "	<<	e.what()	<<	std::endl;
	}

	try
	{
		numbers[MAX_VAL]	=	0;
		std::cout	<<	"[ERREUR] Aucune exception lancee pour un index superieur a la taille !"	<<	std::endl;
	}
	catch	(const	std::exception&	e)
	{
		std::cout	<<	"[OK] Exception attrapee avec succes pour l'index MAX_VAL : "	<<	e.what()	<<	std::endl;
	}

	std::cout	<<	"\n=== 6. Test avec un type complexe (std::string) ==="	<<	std::endl;
	Array<std::string>	strArray(3);
	strArray[0]	=	"Bonjour";
	strArray[1]	=	"CPP98";
	strArray[2]	=	"42";

	for	(unsigned	int	i	=	0;	i	<	strArray.size();	i++)
	{
		std::cout	<<	"strArray["	<<	i	<<	"] = "	<<	strArray[i]	<<	std::endl;
	}

	std::cout	<<	"\n=== Fin des tests ==="	<<	std::endl;
	return	0;
}