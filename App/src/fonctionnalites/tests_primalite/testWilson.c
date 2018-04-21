#include "../../../head/fonctionnalites/tests_primalite/testWilson.h"

void Fact (mpz_t retour, mpz_t n)
{
	mpz_t nmoin1;
	mpz_init(nmoin1);

	if (mpz_cmp_ui(n,1) == 0)
		mpz_set_ui(retour, 1);
	
	else if (mpz_cmp_ui(n,0) == 0)
		mpz_set_ui(retour, 1);
	
	else {
		mpz_sub_ui(nmoin1, n, 1);
		Fact(retour, nmoin1);
		mpz_mul(retour, retour, n);
	}
}

int testWilson(mpz_t n)
{
	int retour = 0;
	mpz_t wil, tmp;
	mpz_inits(wil, tmp, NULL);
	mpz_set(tmp, n);
	
	//(n-1)
	mpz_sub_ui(tmp,tmp,1);
	
	//(n-1)!
	mpz_set_ui(wil,1);
	Fact(wil, tmp);
	
	//(n-1)! + 1
	mpz_add_ui(wil, wil, 1);
	
	//(n-1)! + 1 mod(n)
	mpz_mod(wil, wil, n);
	
	if (mpz_cmp_ui(wil,0) == 0) 
		retour = 2; //premier
	else 
		retour = 0; //composé
	
	mpz_clears(wil, tmp, NULL);
	
	return retour;
}
