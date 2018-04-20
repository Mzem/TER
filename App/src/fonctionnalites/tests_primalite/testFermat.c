#include "../../../head/fonctionnalites/tests_primalite/testFermat.h"

int Fermat(mpz_t n, int k, gmp_randstate_t etat)
{
	//initialisations
	mpz_t a,res,n2;
	mpz_inits (n2,a,res,NULL);
	
	//effectuer k tests
	for (int i = 0; i < k ; i++)
	{
		
		mpz_sub_ui(n2,n,(unsigned long int)3);
		//genere a entre 0 et n-4
		mpz_urandomm (a, etat, n2);
		//rajoute 2 au resultat pour avoir 1 < a < n - 1
		mpz_add_ui(a,a,(unsigned long int)2);
		
		mpz_sub_ui(n2,n,(unsigned long int)1);
		mpz_powm(res,a,n2,n);

		// a^(n-1) mod n != 1 donc composé
		if(mpz_cmp_d(res,1) != 0)
		{
			mpz_clears (n2,a,res,NULL);
			return 0;
		}
	}
	//probablement premier
	mpz_clears (n2,a,res,NULL);
	return 1;
}
