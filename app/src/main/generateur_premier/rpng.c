#include "rpng.h"

void alea_premiers (mpz_t rpng,gmp_randstate_t r_state,int nb_bits_min,int nb_bits_max)
{	
	//declaration et initialisation des variables
	mpz_t bits_min,deux;
	
	mpz_inits(bits_min,deux,NULL);
	mpz_set_ui(deux,2);
	
	//bits_min = 2^nb_bits_min
	mpz_pow_ui(bits_min,deux,nb_bits_min); 
	
	//nb de répétitions du test de primalité
	int nb_reps = 15;
	
	do {
		mpz_rrandomb (rpng, r_state, nb_bits_max);
		
	}
	while((isProbabPrime(rpng, nb_reps, r_state) == 0)||(mpz_cmp(rpng,bits_min) < 0));		

	mpz_clears(deux,bits_min,NULL);	
}
