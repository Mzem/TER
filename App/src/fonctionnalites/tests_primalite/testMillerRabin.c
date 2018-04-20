#include "../../../head/fonctionnalites/tests_primalite/testMillerRabin.h"

int MillerRabin(mpz_t n, int k, gmp_randstate_t etat)
{
	//initialisation
	mpz_t a,res,res2,t,modulo,n2,temp;
	mpz_inits (t,modulo,n2,a,temp,res,res2,NULL);
	int s=0;
	//clock_t temps;
	
	//on decompose en (2pui s) * t
	mpz_sub_ui(t,n,(unsigned long int)1);
	mpz_mod_ui(modulo,t, (unsigned long int)2);
	while(mpz_cmp_d(modulo,0) == 0)
	{
		mpz_div_ui(t,t,(unsigned long int)2);
		s++;
		mpz_mod_ui (modulo,t,(unsigned long int) 2);
	}

	//on effectue k tests 
	for (int i = 0; i < k ; i++)
	{
		
		mpz_sub_ui(n2,n,(unsigned long int)1);
		//genere a entre 0 et n-2
		mpz_urandomm (a, etat, n2);
		//augment a de 1 pour avoir 0 < a < n
		mpz_add_ui(a,a,(unsigned long int)1);
		
		//calcule a^n-1 mod n
		mpz_set(temp,t);
		mpz_powm(res,a,temp,n);
		mpz_set(res2,res);

		//si le resultat different de 1 et de -1 (ou n-1)
		if((mpz_cmp_d(res2,1) != 0)&&(mpz_cmp(res2,n2) != 0))
		{
			int j;
			for ( j = 0; j < (s-1) ; j++)
			{
				mpz_mul(res,res,res);
				mpz_mod (res,res, n);
				if(mpz_cmp_d(res,1) == 0)
					{
						mpz_clears(t,modulo,n2,a,temp,res,res2,NULL);
						return 0;
					}
				if(mpz_cmp(res,n2) == 0)
					{
						j=s;
					}
			}
			if( (j == (s-1)) || (j == 0) )
				//on ne retourne pas 0 si j = s
			{
				mpz_clears(t,modulo,n2,a,temp,res,res2,NULL);
				return 0;
			}
		}
	}
	//tres probablement premier
	mpz_clears(t,modulo,n2,a,temp,res,res2,NULL);
	return 1;
}