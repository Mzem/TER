#include "../../../head/fonctionnalites/tests_primalite/testFermat.h"


int testFermat(mpz_t n, int k)
{
	mpz_t a, nMoins1, ferm;
	mpz_inits (a, nMoins1, ferm, NULL);
	gmp_randstate_t r_state;
	unsigned long int seed = time(NULL)*(rand()%100+1);
	gmp_randinit_default(r_state);
    gmp_randseed_ui(r_state, seed);
	
	//Répéter le test k fois
	for (int i = 0; i < k ; i++)
	{
		//nMoins1 = n - 1
		mpz_sub_ui(nMoins1, n, 1);
		
		//Générer a aléatoire dans [1, n-1]
		int nbBits = mpz_sizeinbase(n, 2);
		//Boucle do while pour sécurité, on sait jamais si le générateur aléatoire a un probleme
		do {
			mpz_urandomb(a, r_state, nbBits-1);
			mpz_add_ui(a, a, 1);
			//gmp_printf("a = %Zd\n", a);
		} while ( mpz_cmp_ui(a,1) <= 0 || mpz_cmp(a,nMoins1) >= 0);
		
		//ferm = a^(n-1) mod(n)
		mpz_powm(ferm, a, nMoins1, n);

		//a^(n-1) mod n != 1
		if(mpz_cmp_ui(ferm, 1) != 0)
		{
			mpz_clears (nMoins1, a, ferm, NULL);
			return 0;
		}
	}
	//Probablement premier
	mpz_clears (nMoins1, a, ferm, NULL);
	return 1;
}
