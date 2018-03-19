#include "Wilson.h"

void Fact(mpz_t retour,mpz_t n)
{
	mpz_t nmoin1;
	mpz_init(nmoin1);

	if(mpz_cmp_ui(n,1)==0)
	{
		mpz_set_ui(retour,1);
	}
	else if(mpz_cmp_ui(n,0)==0)
	{
		mpz_set_ui(retour,1);
	}
	else 
	{
		mpz_sub_ui(nmoin1,n,1);
		Fact(retour,nmoin1);
		mpz_mul(retour,retour,n);
	}
}


int Wilson(mpz_t n)
{
	int retour;
	mpz_t res,p;
	mpz_inits(res,p,NULL);

	//variable tmp
	mpz_set(p,n);

	mpz_sub_ui(p,p,1);
	mpz_set_ui(res,1);
	Fact(res,p);
	mpz_add_ui(res,res,1);
	mpz_mod(res,res,n);
	if(mpz_cmp_ui(res,0)==0) 
		retour = 2; //premier
	else retour = 0; //composé
	
	mpz_clears(res,p,NULL);
	
	return retour;
}
