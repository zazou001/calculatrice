/*
	Auteurs : HAMIDA Rayan et ZANZI Zachary
	Derniere mise a jour : 12/04/2013
	
	ETAT :	Fonctionnel
			Cahier des charges rempli
*/

#include "ExpressionsAlgebriques.h"
#include "chaine.h"
#include "type.h"

entier main(entier argc, char *argv[])
{
	//	Déclarations des variables
	
	char s[100];
	reel res;
	EA *pArbre;
	
	if(argc > 2) {printf("Y en a trop d'arguments.\n"); return 1;}
	if(argc == 1) {printf("Pas assez d'arguments.\n"); return 2;}
	
	SaisieEA(&s, argv);
	if(EAValide(&s) == 1)
	{
		Creer_Oper(&pArbre, &s);
		res = Calcule_Oper(&pArbre);
		printf("Le résultat de l'expression algébrique est : %f\n", res);
		Detruire_Oper(pArbre);
	}
	else 
		printf("Expression invalide.\n");
			
	return 0;

}

