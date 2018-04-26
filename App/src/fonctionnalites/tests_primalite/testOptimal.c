#include "../../../head/fonctionnalites/tests_primalite/testOptimal.h"

/** 
 * @param n l'entier à tester
 * @param k le nombre de répétitions pour Miller-Rabin
 * 
 * @return retourne 2 si n est premier, 1 si n est probablement premier, 0 s'il est composé.
 * */
 
int testOptimal (mpz_t n, int k) 
{
	return mpz_probab_prime_p(n, k);
}
