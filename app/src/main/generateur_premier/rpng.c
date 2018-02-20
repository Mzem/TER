#include "rpng.h"

void alea_premiers (mpz_t rpng,gmp_randstate_t r_state, int nb_bits_max)
{	
	//declaration et initialisation des variables
	mpz_t nb_bits_min,deux,taille_rpng,tmp;
	
	mpz_init(nb_bits_min);
	mpz_init(taille_rpng);
	mpz_init(deux);
	mpz_init(tmp);
	mpz_set_ui(deux,2);
	mpz_set(tmp,rpng);
	
	//nb_bits_min = 2^64
	mpz_pow_ui(nb_bits_min,deux,64); 
	
	mpz_get_ui(tmp);//transformation du tmp en unsigned long int
	mpz_pow_ui(taille_rpng,deux,tmp);
	
	//nb de répétitions du test de primalité
	int nb_reps = 15;
	
	do {
		mpz_rrandomb (rpng, r_state, nb_bits_max);
	}while((isProbabPrime(rpng, nb_reps, r_state) == 0)||(mpz_cmp(taille_rpng,nb_bits_min) < 0));		

	mpz_clear(tmp);
	mpz_clear(deux);
	mpz_clear(nb_bits_min);
	mpz_clear(taille_rpng);
}
