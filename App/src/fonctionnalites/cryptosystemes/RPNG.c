#include "../../../head/fonctionnalites/cryptosystemes/RPNG.h"


void RPNG_det ( int (*testPrimalite)(const mpz_t), int bits, mpz_t retour)
{
	//Un nombre premier contient au moins 2 bits
	if (bits < 2) {
		mpz_set_ui(retour,0);
		return;
	}
	//Initialisation nombre aléatoire
	mpz_t alea;
	gmp_randstate_t r_state;
	unsigned long int seed = time(NULL)*(rand()%100+1);
	//printf("\n######################### RPNG ######################\nSeed = %ld\n",seed);
	mpz_init(alea);
    gmp_randinit_default(r_state);
    gmp_randseed_ui(r_state, seed);
	
	//Générer aléatoire et tester la primalité, jusqu'à trouver un nombre premier
	int primalite = 0;
	do {
		mpz_urandomb(alea, r_state, bits);
		
		primalite = (*testPrimalite)(alea);
		
		//gmp_printf("Test primalité sur alea %Zd : %d\n", alea, primalite);
	} while (primalite == 0);
	
	if (primalite == -1)
		mpz_set_ui(retour, 0);
	else
		mpz_set(retour, alea);
	mpz_clear(alea);
	gmp_randclear(r_state);
}

void RPNG_prob ( int (*testPrimalite)(const mpz_t, int), int bits, mpz_t retour)
{	
	//Un nombre premier contient au moins 2 bits
	if (bits < 2) {
		mpz_set_ui(retour,0);
		return;
	}
	
	//Initialisation nombre aléatoire
	mpz_t alea;
	gmp_randstate_t r_state;
	unsigned long int seed = time(NULL)*(rand()%100+1);
	//printf("\n######################### RPNG ######################\nSeed = %ld\n",seed);
	mpz_init(alea);
    gmp_randinit_default(r_state);
    gmp_randseed_ui(r_state, seed);
	
	//Générer aléatoire et tester la primalité, jusqu'à trouver un nombre premier
	int primalite = 0;
	do {
		mpz_urandomb(alea, r_state, bits);
		
		primalite = (*testPrimalite)(alea, K+bits/100);
		
		//gmp_printf("Test primalité sur alea %Zd : %d\n", alea, primalite);
	} while (primalite == 0);
	
	mpz_set(retour, alea);
	mpz_clear(alea);
	gmp_randclear(r_state);
}


void RPNG_opt (double tps[6][1025], int bits, mpz_t retour)
{
	if (bits > 1024 || bits < 0) {
		printf("/!\\    ERREUR : génération optimale pour %d bits impossible    /!\\\n",bits);
		return;
	}
	//Choix du test qui prend le temps minimal
	int min = 0;
	for (int i = 1; i < 6; i++)
	{
		if (tps[i][bits] < tps[min][bits])
			min = i;
	}
	
	switch (min)
	{
		case 0 : printf("Test optimal pour %d bits : test Naif.\n",bits); RPNG_det(testNaif, bits, retour); break;
		case 1 : printf("Test optimal pour %d bits : test Wilson.\n",bits); RPNG_det(testWilson, bits, retour); break;
		case 2 : printf("Test optimal pour %d bits : test Fermat.\n",bits); RPNG_prob(testFermat, bits, retour); break;
		case 3 : printf("Test optimal pour %d bits : test Miller-Rabin.\n",bits); RPNG_prob(testMillerRabin, bits, retour); break;
		case 4 : printf("Test optimal pour %d bits : test Solovay-Strassen.\n",bits); RPNG_prob(testSolovay, bits, retour); break;
		case 5 : printf("Test optimal pour %d bits : test AKS.\n",bits); RPNG_det(testAKS, bits, retour); break;
		default: printf("/!\\    ERREUR : test minimal non trouvé    /!\\\n"); break;
	}	
}
