#include "ExpressionsAlgebriques.h"

char* PointeurParentheseFermante(char* s, entier IndexOuvrante)
{
	entier index = IndexOuvrante;
	entier CptP = 0;
	
	do
	{
		if(s[index] == '(')
			CptP++;
		if(s[index] == ')')
		{
			CptP--;
			if(CptP == 0)
				return &s[index];
		}
		index++;
		
	}while(*s != '\0');

	return NULL;

}

entier ChercheOperateurHorsParenthese(char Operateur, char*s)
{
	char* Fin = &s[strlen(s) - 1];
	entier CptP = 0;
	
	for(; Fin >=s; Fin--)
	{
		if(*Fin == ')')
			CptP++;
		if(*Fin == '(')
			CptP--;
		if(*Fin == Operateur && CptP == 0)
			return  (Fin - s);
	}
	return -1;
}

/*
	Renvoie la position de l'opération principale.
	Sinon renvoie -1 si pas d'opérateurs dans la chaine.
*/
entier ChercheOperateur(char *s)
{

	entier r;
	
	r = ChercheOperateurHorsParenthese('+', s);
	
	if(r == -1)
		r = ChercheOperateurHorsParenthese('-', s);
	if(r == -1)
		r = ChercheOperateurHorsParenthese('/', s);
	if(r == -1)
		r = ChercheOperateurHorsParenthese('*', s);

	return r ;
}


/*
	Crée une Operation a partir d'une Chaine.
	Crée un noeud si la chaine contient une expression (plus d'un nombre).
	Crée une feuille si la Chaine ne contient qu'un nombre.
*/
void Creer_Oper(EA **ppArbre, char *s1){

	char* Sg;
	char* Sd;
	entier i;

	char* Debut = s1;
	char* Fin = &s1[strlen(s1) - 1];

	// Suppression des parentheses lorsqu'elles englobent toute l'expression
	
	if(*Debut == '(' && PointeurParentheseFermante(Debut, 0) == Fin)
	{
		*Debut = '\0';
		Debut++;
		*Fin = '\0';
		s1++;
	}


	i = ChercheOperateur(s1);
	
	if(i >= 0)
	{
		*ppArbre= (EA *) malloc (sizeof(EA));
		(*ppArbre)->operateur = s1[i];
		(*ppArbre)->valeur = 0.0f;
		(*ppArbre)->type = OPERATEUR;
		s1[i] = '\0';
		(*ppArbre)->D = NULL;
		(*ppArbre)->G = NULL;
		Sg = &s1[0];
		Sd = &s1[i+1];
		Creer_Oper(&((*ppArbre)->D), Sd);
		Creer_Oper(&((*ppArbre)->G), Sg);
		printf("noeuds  %c\n",(*ppArbre)->operateur);
	}
	else 
	{
		*ppArbre= (EA *) malloc (sizeof(EA));
		(*ppArbre)->valeur = (reel)strtod(s1, NULL);
		(*ppArbre)->operateur = 0;
		(*ppArbre)->type = VALEUR;
		(*ppArbre)->D = NULL;
		(*ppArbre)->G = NULL;
		printf("feuille  %f\n",(reel)strtod(s1, NULL));
	}
}

/*
	Détruit l'arbre.
*/
entier Detruire_Oper(EA *pArbre)
{
	if(pArbre->G != NULL){
		Detruire_Oper(pArbre->G);
		}
	
	if(pArbre->D != NULL){
		Detruire_Oper(pArbre->D);
		}
		
	free(pArbre); // Je me détruis
	
	return 0;
}

/*
	Calcule le resultat de l'expression a partir de l'arbre cree.
*/
reel Calcule_Oper(EA **ppArbre)
{
	reel resultat;
	if((*ppArbre)->type == 0){
		switch((*ppArbre)->operateur)
		{
		case '+' : 
			resultat = Calcule_Oper(&((*ppArbre)->G)) + Calcule_Oper(&((*ppArbre)->D)); 
			break;
		case '-' : 
			resultat = Calcule_Oper(&((*ppArbre)->G)) - Calcule_Oper(&((*ppArbre)->D)); 
			break;
		case '*' : 
			resultat = Calcule_Oper(&((*ppArbre)->G)) * Calcule_Oper(&((*ppArbre)->D)); 
			break;
		case '/' : 
			resultat = Calcule_Oper(&((*ppArbre)->G)) / Calcule_Oper(&((*ppArbre)->D)); 
			break;
		default: printf("Ptit probleme d'operateur."); break;

		}}
	else resultat = (*ppArbre)->valeur;

	return resultat;
}
