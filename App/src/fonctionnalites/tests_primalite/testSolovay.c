#include "../../../head/fonctionnalites/tests_primalite/testSolovay.h"


int testSolovay (const mpz_t n, int k)
{	
	//Premier test si n est pair ou <= 2
	if ( mpz_cmp_ui(n, 2) < 0 )
		return 0;
	if ( mpz_cmp_ui(n, 2) == 0 )
		return 2;
	mpz_t parite;
	mpz_init(parite);
	mpz_mod_ui(parite, n, 2);
	if ( mpz_cmp_ui(parite, 0) == 0 )
		return 0;
	mpz_clear(parite);
	
	//Sinon (n est impair)
	mpz_t a, nMoins1, exposant, euler, reste;
	mpz_inits (a, nMoins1, exposant, euler, reste, NULL);
	gmp_randstate_t r_state;
	unsigned long int seed = time(NULL)*(rand()%100+1);
	gmp_randinit_default(r_state);
    gmp_randseed_ui(r_state, seed);
	
	//On répète le test k fois 
	for (int i = 0; i < k ; i++)
	{
		//Générer a aléatoire dans ]1, n[
		mpz_sub_ui(nMoins1, n, 1);
		int nbBits = mpz_sizeinbase(n, 2);
		//Boucle do while pour sécurité, on sait jamais si le générateur aléatoire a un problème
		do { 
			mpz_urandomb(a, r_state, nbBits-1);
			mpz_add_ui(a, a, 1);
			//gmp_printf("a = %Zd\n", a);
		} while ( mpz_cmp_ui(a,1) <= 0 || mpz_cmp(a,nMoins1) > 0);
		
		int x = mpz_jacobi(a, n);
		
		//Calcul du critère d'Euler
		mpz_cdiv_q_ui(exposant, nMoins1, 2);
		mpz_mod_ui(reste, nMoins1, 2);
		mpz_sub(exposant, exposant, reste);
		mpz_powm(euler, a, exposant, n);
		
		if ( x == 0 || (x != -1 && mpz_cmp_ui(euler, x) != 0) || (x == -1 && mpz_cmp(euler, nMoins1) != 0) ) 
		{
			mpz_clears(a, nMoins1, exposant, euler, reste, NULL);
			gmp_randclear(r_state);
			return 0;
		}
	
	}
	mpz_clears(a, nMoins1, exposant, euler, reste, NULL);
	gmp_randclear(r_state);
	return 1;
}
