/*
 * tp.c
 *
 *  Created on: 25 Nov 2019
 *      Author: Lokesh
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Les fonctions

void clef(){

	//initialisation des variables/
	int  i , j ;// indices des boucles
	char ch, c ;// characteres pour les conversions
	int K = 0;
	int hash = 0;
	char pass[50];
	char texte[50];
	int decalage;
	int n = strlen (pass); //Cette fonction permet de calculer la longueur de la chaine de caracteres

	printf("Entrez un texte\n");
	getchar(); //Cette fonction attends que l'utilisateur entre un caractere.
	gets(texte); //fonction permettant de lire une chaine de caracteres

	printf("Entrez le decalage\n\n");
	scanf("%d", &decalage); //'%d' pour stoquer les nombre de base decimale.
	printf("Entrez le mot de passe\n");
	scanf("%s" ,pass); // '%s'pour stoquer tous les caracteres de la chaine saisie

	//calcule du hash entre les characteres
	for ( i = 0 ; i < n ; i++){
	c= pass[i] ;

	// hash
	hash ^= c ; // '^' est la fonction qui fait le XOR du hash
	}

	for ( j = 0 ; texte[j] != '\0' ; ++j ){
		ch = texte[j] ;

		// pour les characteres minuscules
		if ( ch >= 'a' && ch <= 'z' ){
			ch = ch + decalage ;
			if ( ch > 'z'){
				ch = ch - 26 ;
			}
			texte[j]= ch ;
		}

		// pour les characteres majuscules
		else if ( ch >= 'A' && ch <= 'Z' ){
			ch = ch + decalage ;
			if ( ch > 'Z'){
				ch = ch - 26 ;
			}
			texte[j]= ch ;
		}
	}

	char c1;
	int k;
	int m = strlen(texte);

	for (k = 0 ; k < m ; k++){
		c1 = texte[k];
		c1 = c1 ^ K ;
		texte[k]= c1 ;
	}
}

void clefd (){

	int  i , j ;// indices des boucles
	char ch, c ;// characteres pour les conversions
	int K = 0;
	char pass[50];
	int hash = 0;
	int n = strlen (pass); //Cette fonction permet de calculer la longueur de la chaine de caracteres
	char texte[50];
	int decalage;

	//calcule du hash entre les characteres
	for ( i = 0 ; i < n ; i++){
		c= pass[i] ;
		// hash
		hash ^= c ;
	}

	char c1;
	int k;
	int m = strlen(texte);

	for (k = 0 ; k < m ; k++){
		c1 = texte[k];
		c1 = c1 ^ K ;
	    texte[k]= c1 ;
	}

	for ( j = 0 ; texte[j] != '\0' ; ++j ){
		ch = texte[j] ;
		// pour les characteres minuscules
		if ( ch >= 'a' && ch <= 'z' ){
			ch = ch - 3 ;
			if ( ch > 'z'){
				ch = ch + 26 ;
			}
			texte[j]= ch ;
	    }

	    // pour les characteres majuscules
	    else if ( ch >= 'A' && ch <= 'Z' ){
	    	ch = ch - 3 ;
	    	if ( ch > 'Z'){
	    		ch = ch + 26 ;
	    	}
	    	texte[j]= ch ;
	    }
	}
}


void encrypt (){

	// initialisations des variables locaux
	char texte[40];
	char pass[50];
	char nom_fichier[20];
	int fic;
	char nom[20];
	int decalage ;

	FILE * fichier; //Vous pouvez ouvrir ce fichier pour voir de quoi est constitué le type FILE.

	// choix méthode cryptage
	printf("\n2:crypter un fichier existant? \n");
	printf("\n3:Ou Ecrire vos caracteres?\n");
	scanf("%d", &fic);

	switch(fic){

	case 2 :

	printf("Entrez le nom du fichier existant\n");
	scanf("%s", nom_fichier);
	fichier = fopen(nom_fichier,"r");

	printf("Entrez le decalage\n\n");
	scanf("%d", &decalage);

	//condition mauvaise ou bonne lecture
	if ( fichier == NULL ){
		printf("fichier ne peut pas etre creer\n");
		exit(1);
	}

	fscanf(fichier,"%s",texte);// lecture du string depuits le fichier txt
	printf("Nom du fichier\n");
	scanf("%s", nom);

	//ouvrir le fichier txt
	fichier = fopen(nom,"w");

	//condition mauvaise ou bonne lecture
	if ( fichier == NULL ){
		printf("fichier ne peut pas etre creer\n");
		exit(1);
	}

	printf("Entrez le mot de passe\n");
	scanf("%s" ,pass);

	int n = strlen(pass);

	printf("le nombre de characteres du mot de pass est : %d\n" , n ) ;
	fprintf(fichier,"le texte entrer est:%s\n", texte);

	clef(pass,texte,decalage);
	fprintf(fichier,"%s", texte);
	fclose(fichier);
	break;

	case 3:
	{
		printf("Nom du fichier\n");
		scanf("%s", nom);
		//ouvrir le fichier txt
		fichier = fopen(nom,"w");

		//condition mauvaise ou bonne lecture
		if ( fichier == NULL ){
			printf("fichier ne peut pas etre creer\n");
			exit(1);
		}

		clef(pass,texte,decalage);
		fprintf(fichier,"%s", texte);
		fclose(fichier);
	}
}

void decrypt()
{
	// initialisations des variables locaux

	char nom[20];
	char nom_fichier[20];// nom du fichier a lire
	int fic ;// choix de type de lecture
	int decalage;
	char texte[40];
	char pass[50];

	FILE * fichier;

	// choix méthode cryptage
	printf("\n4:decrypter fichier exterieur? \n");
	printf("\n5:decrypter vos carracteres?\n");
	scanf("%d", &fic);

	switch(fic){

	case 4:

	printf("Entrez le nom du fichier\n");
	scanf("%s", nom_fichier);
	fichier = fopen(nom_fichier,"r");

	//condition mauvaise ou bonne lecture
	if ( fichier == NULL ){
		printf("fichier ne peut pas etre creer\n");
		exit(1);
	}

	fscanf(fichier,"%s",texte );
	printf("%s\n", texte);

	printf("Entrez le decalage\n\n");
	scanf("%d", &decalage);

	printf("Nom du fichier\n");
	scanf("%s" , nom);

	//ouvrir le fichier txt
	fichier = fopen(nom,"w");

	//condition mauvaise ou bonne lecture
	if ( fichier == NULL ){
		printf("fichier ne peut pas etre creer\n");
		exit(1);
	}

	printf("Entrez le mot de pass\n");
	scanf("%s" ,pass);

	fprintf(fichier,"%s\n", texte);


	clefd(pass,texte, decalage);

	fprintf(fichier,"%s", texte);
	fclose(fichier);
	break;

	case 5:

	printf("Entrez le mot crypter\n");
	scanf("%s", texte);

	printf("Entrez le decalage\n\n");
	scanf("%d", &decalage);

	printf("Nom du fichier\n");
	scanf("%s" , nom);

	//ouvrir le fichier txt
	fichier = fopen(nom,"w");

	//condition mauvaise ou bonne lecture
	if ( fichier == NULL ){
		printf("fichier ne peut pas etre creer\n");
		exit(1);
	}

	printf("Entrez le mot de passe\n");
	scanf("%s" ,pass);

	fprintf(fichier,"le texte initial est:%s\n", texte);
	clefd(pass,texte,decalage);
	fprintf(fichier,"%s", texte);
	fclose(fichier);
	}
}


int main(){
	// variables
	char texte[40] ;// code ou phrase
	char pass[50]; // mot de passe
	char  choix;
	int choix2; // choix de decryptage ou de decryptage

	printf("Voulez-vous commencer ou recommencer?(o/n)\n");
	scanf("%c",&choix);

	while (choix=='o')
	   {
	   printf("\nVoulez vous encrypter ou decrypter:\n");
	   printf("\n0:quitter\n");
	   printf("\n1: encrypter\n");
	   printf("\n2: decrypter\n");
	   scanf("%d",&choix2);
	   getchar();


	   switch(choix2)
	   {
	   case 0:
		   printf("Au Revoir :)");
		   break;

	   case 1 :
		   encrypt(texte,pass);
	printf("le mot crypter est: %s\n\n", texte);
	break;
	   case 2:
	decrypt(texte,pass);
	printf("le mot decrypter est: %s\n\n", texte);
	break;
	   }
	 }
	}
	scanf("\n");
}

