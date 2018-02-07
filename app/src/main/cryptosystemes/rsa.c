#include "rsa.h"

void chiffrement(mpz_t c, const mpz_t m, const mpz_t e, const mpz_t n)
{
	//c = m ^ e modulo n
	mpz_powm_sec(c, m, e, n);
}

void dechiffrement(mpz_t m, const mpz_t c, const mpz_t d, const mpz_t n)
{			
	//m = c ^ d modulo n
	mpz_powm_sec(m, c, d, n);
}

void creationCles(mpz_t n, mpz_t e, mpz_t p, mpz_t q, mpz_t d,
	gmp_randstate_t r_state)
{   
    //Création des clés
	mpz_t pgcd;
	mpz_t pmoins1, qmoins1, phi_n;
	mpz_inits(pgcd, pmoins1, qmoins1, phi_n, NULL);
	
	//initialisation p et p - 1
	do {
		mpz_urandomb(p, r_state, NB_BITS_CLE);
	}while(mpz_cmp_ui(p, 0) == 0 || mpz_probab_prime_p(p, NB_REPS_MILLER_RABIN) == 0);
	mpz_sub_ui(pmoins1, p, 1);
	
	//initialisation q et q - 1
	do {
		mpz_urandomb(q, r_state, NB_BITS_CLE);
	}while(mpz_cmp_ui(q, 0) == 0 || mpz_cmp(p, q) == 0 || mpz_probab_prime_p(q, NB_REPS_MILLER_RABIN) == 0);
	mpz_sub_ui(qmoins1, q, 1);
	
	//n = p * q et phi_n = (p - 1) * (q - 1)
	mpz_mul(n, p, q);
	mpz_mul(phi_n, pmoins1, qmoins1);
	
	//initialisation e et d = e ^ -1 modulo phi_n
	do{
		mpz_urandomb(e, r_state, NB_BITS_CLE);
		mpz_gcd(pgcd, e, phi_n);
	}while(mpz_cmp_ui(pgcd, 1) != 0 || mpz_cmp(e, phi_n) >= 0);
	mpz_invert(d, e, phi_n);
		
	mpz_clears(pmoins1, qmoins1, phi_n, NULL);
}
















