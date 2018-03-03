#include "fermat.h"

int Fermat(mpz_t n, int k)
{
	
	mpz_t a;
	mpz_t res;
	mpz_t n2;
	mpz_init (n2);
	mpz_init (a);
	mpz_init (res);
	clock_t temps;
	
	for (int i = 0; i < k ; i++)
	{
		//genere a aleatoirement
		gmp_randstate_t etat;
		gmp_randinit_mt (etat);
		temps=clock();
		gmp_randseed_ui (etat, (unsigned long int) temps);
		mpz_sub_ui(n2,n,(unsigned long int)3);
		mpz_urandomm (a, etat, n2);
		mpz_add_ui(a,a,(unsigned long int)2);
		
		mpz_sub_ui(n2,n,(unsigned long int)1);
		mpz_powm(res,a,n2,n);
		if(mpz_cmp_d(res,1) != 0) //si il est pas premier
			return 0;
	}
	return 1;
}
