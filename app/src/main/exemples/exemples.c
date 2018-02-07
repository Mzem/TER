#include "exemples.h"

void essai_rsa(gmp_randstate_t r_state) {
	// RSA-1024 : p, q 512 bits, messages 1024 bits
	
	mpz_t m1, m2, c;	//message clair et chiffré
	mpz_t n, e;			//cle publique
	mpz_t p, q, d;		//cle privée
	mpz_inits(m1, m2, c, p, q, n, e, d, NULL);
    
    //initialisation des cles pour RSA
	creationCles(
		n, e,
		p, q, d,
		r_state
	);
		
	//affectation d'une valeur aléatoire à m
	do {
		mpz_urandomb(m1, r_state, 1024); //msg 1024 bits
		mpz_mod(m1, m1, n);
	}while((mpz_cmp_ui(m1, 0) == 0)||(mpz_cmp_ui(m1, 1) == 0)||(mpz_cmp(m1, n) > 0));
	
	gmp_printf("Chiffrement de M1 :\n%Zd\n\n", m1);
	chiffrement(c, m1, e, n);
	dechiffrement(m2, c, d, n);
	gmp_printf("Resultat du dechiffrement M2 :\n%Zd\n\n", m2);
	
	gmp_printf("M1 %s M2\n", (mpz_cmp(m1, m2) == 0) ? "=" : "!=");

	mpz_clears(m1, m2, c, p, q, n, e, d, NULL);
}
