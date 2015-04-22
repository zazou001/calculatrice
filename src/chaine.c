#include "chaine.h"
#include "type.h"

/*
	Charge l'expression a partir d'un fichier
	et enleve les espaces dans cette expression.
*/
void SaisieEA(char *s, char *argv[])
{
	entier i, j;
	FILE * pFichier = NULL;
	
	pFichier = fopen(argv[1],"r");
	if (pFichier != NULL)
	{
		fgets(s, 100, pFichier);
		fclose(pFichier);
	}
	
	s[strlen(s) - 1] = '\0';
	
	for(i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			for(j = i; s[j] != '\0'; j++)
				{
					s[j] = s[j+1];
				}
	}
}

/*
	Verifie que l'expression est bien parenthesee
	et ne contient que les caracteres autorises.
*/
entier EAValide(char *s)
{
	entier i;
	entier b = 1, m = 0, n = 0;
	
	for(i = 0; s[i]!='\0'; i++)
	{
		if(s[i] == '(') m++;
		if(s[i] == ')') n++;		
	}
	
	if(m == n) b = 1;
	else b = 0;
	
	for(i = 0; (s[i] != '\0') && b; i++)
	{
		//printf("valeur de s[%d] : %c\n",i,s[i]);
		// Les caractères de 40 à 57 sur la table ASCII
		// contiennent 0123456789+-/*()
			
		if(s[i] < (char)40 || s[i] > (char)57) {b = 0;}
	}
	
	return b;
}
