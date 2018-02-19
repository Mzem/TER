#include "rpng.h"

void alea_premiers (mpz_t rpng,gmp_randstate_t r_state, int nb_bits_max)
{	
	int nb_reps = 15;
	do {
		mpz_rrandomb (rpng, r_state, nb_bits_max);
	}while(isProbabPrime(rpng, nb_reps, r_state) == 0);		
}
