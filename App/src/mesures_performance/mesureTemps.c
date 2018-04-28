#include "../../head/mesures_performance/mesureTemps.h"


void mesureTemps(double tps[6][1025])
{
	mpz_t premier;
	mpz_init(premier);
	int retour;
	clock_t debut, fin;
	
	//Pour chaque test
	for (int testPrim = 0; testPrim < 6; testPrim++)
	{
		switch (testPrim){
			case 0 : printf("Mesure temps exec test Naif...\n"); break;
			case 1 : printf("Mesure temps exec test Wilson...\n"); break;
			case 2 : printf("Mesure temps exec test Fermat...\n"); break;
			case 3 : printf("Mesure temps exec test Miller-Rabin...\n"); break;
			case 4 : printf("Mesure temps exec test Solovay-Strassen...\n"); break;
			case 5 : printf("Mesure temps exec test AKS...\n"); break;
			default: printf("/!\\    ERREUR : test non trouvé    /!\\\n"); break;	
		}
		for (int nbBits = 0; nbBits < 1025; nbBits++)
		{
			//On génère un nombre premier
			RPNG_prob(mpz_probab_prime_p, nbBits, premier);
			//On regarde combien de temps chaque test va mettre pour le vérifier
			switch (testPrim)
			{
				case 0 : debut = clock(); retour = testNaif(premier); fin = clock(); break;
				case 1 : debut = clock(); retour = testWilson(premier); fin = clock(); break;
				case 2 : debut = clock(); retour = testFermat(premier, K+nbBits/100); fin = clock(); break;
				case 3 : debut = clock(); retour = testMillerRabin(premier, K+nbBits/100); fin = clock(); break;
				case 4 : debut = clock(); retour = testSolovay(premier, K+nbBits/100); fin = clock(); break;
				case 5 : debut = clock(); retour = testAKS(premier); fin = clock()+99999; break;	//+99999 à enlever quand AKS sera implementé
				default: printf("/!\\    ERREUR : test non trouvé    /!\\\n"); break;	
			}
			//Cas ou le test est trop lent
			if (retour == -1)
				tps[testPrim][nbBits] = tps[testPrim][nbBits-1]+2;
			//Cas ou le test se comporte mal (erreur de notre part)
			else if (retour == 0)
				tps[testPrim][nbBits] = 0;
			else
				tps[testPrim][nbBits] = (double)(fin - debut) / (double) CLOCKS_PER_SEC;
		}	
	}
	mpz_clear(premier);
}

void ecrireMesures(char* nom, double tps[6][1025])
{
	FILE* fichier = NULL;
		 
    fichier = fopen(nom, "w+");
 
    if (fichier == NULL) {
        printf("/!\\    ERREUR fichier    /!\\\n");
        return;
    }
	
	printf("Ecriture des mesures dans fichier...\n");
    for (int i = 0; i < 6; i++)
	{
		switch (i)
		{
			case 0 : fprintf(fichier, "# Test Naif :\n"); fprintf(fichier,"# BITS TEMPS\n"); break;
			case 1 : fprintf(fichier, "# Test Wilson :\n"); fprintf(fichier,"# BITS TEMPS\n"); break;
			case 2 : fprintf(fichier, "# Test Fermat :\n"); fprintf(fichier,"# BITS TEMPS\n"); break;
			case 3 : fprintf(fichier, "# Test Miller-Rabin :\n"); fprintf(fichier,"# BITS TEMPS\n"); break;
			case 4 : fprintf(fichier, "# Test Solovay-Strassen :\n"); fprintf(fichier,"# BITS TEMPS\n"); break;
			case 5 : fprintf(fichier, "# Test AKS :\n"); fprintf(fichier,"# BITS TEMPS\n"); break;
			default: printf("/!\\    ERREUR : test non trouvé    /!\\\n"); break;	
		}
		for (int j = 0; j < 1025; j++)
		{
			fprintf(fichier, "%d  %f\n",j, (double) tps[i][j]);
		}
		fprintf(fichier,"\n\n");
	}
	fclose(fichier);
	
	//Ouverture du fichier à la sortie du programme
	/*
	if ((fichier = popen("leafpad mesures.txt","r")) != NULL)
		pclose(fichier);
	*/
}
