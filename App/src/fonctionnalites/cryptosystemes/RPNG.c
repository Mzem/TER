#include "../../../head/fonctionnalites/cryptosystemes/RPNG.h"


void RPNG_det ( int (*testPrimalite)(mpz_t), int bits, mpz_t retour)
{
	//Initialisation nombre aléatoire
	mpz_t alea;
	gmp_randstate_t r_state;
	unsigned long int seed = time(NULL)*(rand()%100+1);
	printf("\n######################### RPNG ######################\nSeed = %ld\n",seed);
	mpz_init(alea);
    gmp_randinit_default(r_state);
    gmp_randseed_ui(r_state, seed);
	
	//Générer aléatoire et tester la primalité, jusqu'à trouver un nombre premier
	int primalite = 0;
	do {
		mpz_urandomb(alea, r_state, bits);
		//mpz_set_ui(alea,11998843);
		
		primalite = (*testPrimalite)(alea);
		
		gmp_printf("Test primalité sur alea %Zd : %d\n", alea, primalite);
	} while (primalite == 0);
	
	mpz_set(retour, alea);
	mpz_clear(alea);
	gmp_randclear(r_state);
}

void RPNG_prob ( int (*testPrimalite)(mpz_t, int), int bits, mpz_t retour)
{
	//Initialisation nombre aléatoire
	mpz_t alea;
	gmp_randstate_t r_state;
	unsigned long int seed = time(NULL)*(rand()%100+1);
	printf("\n######################### RPNG ######################\nSeed = %ld\n",seed);
	mpz_init(alea);
    gmp_randinit_default(r_state);
    gmp_randseed_ui(r_state, seed);
	
	//Générer aléatoire et tester la primalité, jusqu'à trouver un nombre premier
	int primalite = 0;
	do {
		mpz_urandomb(alea, r_state, bits);
		//mpz_set_ui(alea,11998843);
		
		primalite = (*testPrimalite)(alea, 15);
		
		gmp_printf("Test primalité sur alea %Zd : %d\n", alea, primalite);
	} while (primalite == 0);
	
	mpz_set(retour, alea);
	mpz_clear(alea);
	gmp_randclear(r_state);
}

void RPNG_gen (int bits, mpz_t retour)
{
	//Initialisation nombre aléatoire
	mpz_t alea;
	gmp_randstate_t r_state;
	unsigned long int seed = time(NULL)*(rand()%100+1);
	printf("\n######################### RPNG ######################\nSeed = %ld\n",seed);
	mpz_init(alea);
    gmp_randinit_default(r_state);
    gmp_randseed_ui(r_state, seed);
	
	//Générer aléatoire et tester la primalité, jusqu'à trouver un nombre premier
	int primalite = 0;
	do {
		mpz_urandomb(alea, r_state, bits);
		//mpz_set_ui(alea,11998843);
		
		primalite = testGenerique(alea, 15);
		
		gmp_printf("Test primalité sur alea %Zd : %d\n", alea, primalite);
	} while (primalite == 0);
	
	mpz_set(retour, alea);
	mpz_clear(alea);
	gmp_randclear(r_state);
}
