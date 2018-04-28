#include "../../../head/fonctionnalites/cryptosystemes/RSA.h"


void chiffrementRSA (mpz_t m, const mpz_t n, const mpz_t e, mpz_t c)
{
	//c = m ^ e modulo n
	mpz_powm_sec(c, m, e, n);
}

void dechiffrementRSA (mpz_t c, const mpz_t n, const mpz_t d, mpz_t m)
{			
	//m = c ^ d modulo n
	mpz_powm_sec(m, c, d, n);
}

void generationClesRSA_det (int (*testPrimalite)(const mpz_t), mpz_t n, mpz_t e, mpz_t d)
{   
    mpz_t p, q, pmoins1, qmoins1, phi_n, pgcd;
	mpz_inits(p, q, pmoins1, qmoins1, phi_n, pgcd, NULL);
	
	//Génération p et p - 1
	RPNG_det(testPrimalite, BITS_MODULE_RSA/2, p);
	mpz_sub_ui(pmoins1, p, 1);
	
	//Génération q et q - 1
	RPNG_det(testPrimalite, BITS_MODULE_RSA/2, q);
	mpz_sub_ui(qmoins1, q, 1);
	
	//n = p*q	 
	mpz_mul(n, p, q);
	
	//phi_n = (p-1)*(q-1)
	mpz_mul(phi_n, pmoins1, qmoins1);
	
	//Génération e premier avec phi_n 
	do {
		//Combien de bits pour e ???
		gmp_randstate_t r_state;
		unsigned long int seed = time(NULL)*(rand()%100+1);
		gmp_randinit_default(r_state);
		gmp_randseed_ui(r_state, seed);
	
		mpz_urandomb(e, r_state, BITS_MODULE_RSA/2);
		mpz_gcd(pgcd, e, phi_n);
	} while ( mpz_cmp_ui(pgcd, 1) != 0 || mpz_cmp(e, phi_n) >= 0 || mpz_cmp_ui(e, 3) < 0 );
	
	//Génération d = e^-1 mod(phi_n)
	mpz_invert(d, e, phi_n);
		
	mpz_clears(p, q, pmoins1, qmoins1, phi_n, pgcd, NULL);
}

void generationClesRSA_prob (int (*testPrimalite)(const mpz_t, int), mpz_t n, mpz_t e, mpz_t d)
{   
    mpz_t p, q, pmoins1, qmoins1, phi_n, pgcd;
	mpz_inits(p, q, pmoins1, qmoins1, phi_n, pgcd, NULL);
	
	//Génération p et p - 1
	RPNG_prob(testPrimalite, BITS_MODULE_RSA/2, p);
	mpz_sub_ui(pmoins1, p, 1);
	
	//Génération q et q - 1
	RPNG_prob(testPrimalite, BITS_MODULE_RSA/2, q);
	mpz_sub_ui(qmoins1, q, 1);
	
	//n = p*q	 
	mpz_mul(n, p, q);
	
	//phi_n = (p-1)*(q-1)
	mpz_mul(phi_n, pmoins1, qmoins1);
	
	//Génération e premier avec phi_n 
	do {
		//Combien de bits pour e ???
		gmp_randstate_t r_state;
		unsigned long int seed = time(NULL)*(rand()%100+1);
		gmp_randinit_default(r_state);
		gmp_randseed_ui(r_state, seed);
	
		mpz_urandomb(e, r_state, BITS_MODULE_RSA/2);
		mpz_gcd(pgcd, e, phi_n);
	} while ( mpz_cmp_ui(pgcd, 1) != 0 || mpz_cmp(e, phi_n) >= 0 || mpz_cmp_ui(e, 3) < 0 );
	
	//Génération d = e^-1 mod(phi_n)
	mpz_invert(d, e, phi_n);
		
	mpz_clears(p, q, pmoins1, qmoins1, phi_n, pgcd, NULL);
}

void generationClesRSA_opt (double tps[6][1025], mpz_t n, mpz_t e, mpz_t d)
{   
    mpz_t p, q, pmoins1, qmoins1, phi_n, pgcd;
	mpz_inits(p, q, pmoins1, qmoins1, phi_n, pgcd, NULL);
	
	//Génération p et p - 1
	RPNG_opt(tps, BITS_MODULE_RSA/2, p);
	mpz_sub_ui(pmoins1, p, 1);
	
	//Génération q et q - 1
	RPNG_opt(tps, BITS_MODULE_RSA/2, q);
	mpz_sub_ui(qmoins1, q, 1);
	
	//n = p*q	 
	mpz_mul(n, p, q);
	
	//phi_n = (p-1)*(q-1)
	mpz_mul(phi_n, pmoins1, qmoins1);
	
	//Génération e premier avec phi_n 
	do {
		//Combien de bits pour e ???
		gmp_randstate_t r_state;
		unsigned long int seed = time(NULL)*(rand()%100+1);
		gmp_randinit_default(r_state);
		gmp_randseed_ui(r_state, seed);
	
		mpz_urandomb(e, r_state, BITS_MODULE_RSA/2);
		mpz_gcd(pgcd, e, phi_n);
	} while ( mpz_cmp_ui(pgcd, 1) != 0 || mpz_cmp(e, phi_n) >= 0 || mpz_cmp_ui(e, 3) < 0 );
	
	//Génération d = e^-1 mod(phi_n)
	mpz_invert(d, e, phi_n);
		
	mpz_clears(p, q, pmoins1, qmoins1, phi_n, pgcd, NULL);
}


