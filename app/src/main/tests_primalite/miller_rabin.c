#include "miller_rabin.h"

int MillerRabin(mpz_t n, int k)
{
	mpz_t a,res,res2,t,modulo,n2,temp;
	mpz_init (t);
	mpz_init (modulo);
	mpz_init (n2);
	mpz_init (a);
	mpz_init (temp);
	mpz_init (res);
	mpz_init (res2);
	int s=0;
	clock_t temps;
	
	//on decompose en (2pui s) * t
	mpz_sub_ui(t,n,(unsigned long int)1);
	mpz_mod_ui(modulo,t, (unsigned long int)2);
	while(mpz_cmp_d(modulo,0) == 0)
	{
		mpz_div_ui(t,t,(unsigned long int)2);
		s++;
		mpz_mod_ui (modulo,t,(unsigned long int) 2);
	}
	for (int i = 0; i < k ; i++)
	{
		//genere a aleatoirement
		gmp_randstate_t etat;              
		gmp_randinit_mt (etat);
		temps=clock();
		gmp_randseed_ui (etat, (unsigned long int) temps);
		mpz_sub_ui(n2,n,(unsigned long int)1);
		mpz_urandomm (a, etat, n2);
		mpz_add_ui(a,a,(unsigned long int)1);
		
		mpz_set(temp,t);
		mpz_powm(res,a,temp,n);
		mpz_set(res2,res);
		if((mpz_cmp_d(res2,1) != 0)&&(mpz_cmp(res2,n2) != 0))
		{
			int j;
			for ( j = 0; j < (s-1) ; j++)
			{
				mpz_mul(res,res,res);
				mpz_mod (res,res, n);
				if(mpz_cmp_d(res,1) == 0)
					{
						return 0;
					}
				if(mpz_cmp(res,n2) == 0)
					{
						j=s;
					}
			}
			if( (j == (s-1)) || (j == 0) )
				//on ne retourne pas 0 si j = s
				return 0;
		}
	}
	return 1;
}
