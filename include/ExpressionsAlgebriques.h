#ifndef EA_H
#define EA_H


typedef enum tagtypeFeuille
{
	OPERATEUR,
	VALEUR
}typeFeuille;

#include "chaine.h"



/*
	Noeud:
	La structure est constitué d’un entier (un opérateur de l'opération)
	et de trois pointeurs (un pointant sur le Noeud parent,
	les autres pointant chacun un noeud ou une feuille).
*/

struct Operation
{
	typeFeuille type;				// Dit si chiffre ou operateur
	char operateur; // Operateur si Noeud, Valeur si chiffre
	reel valeur;
	struct Operation* G;
	struct Operation* D;
};




/*
	Arbre:
	Tous les Noeuds descendent de lui.
	Il est constitué de deux pointeurs qui pointent chacun sur une Feuille ou un Noeud.
*/

typedef struct Operation EA; // EA pour Expression Algebrique bien entendu.

char* PointeurParentheseFermante(char* s, entier IndexOuvrante);
entier ChercheOperateurHorsParenthese(char Operateur, char*s);
entier ChercheOperateur(char *s);
void Creer_Oper(EA **ppArbre, char *s1);
entier Detruire_Oper(EA *pArbre);
reel Calcule_Oper(EA **ppArbre);
reel CalculeEA(EA* a);

#endif
