#include <gmp.h>
#include <time.h>
#include "../head/fonctionnalites/cryptosystemes/RPNG.h"
#include "../head/fonctionnalites/cryptosystemes/RSA.h"
#include "../head/fonctionnalites/tests_primalite/testNaif.h"
#include "../head/fonctionnalites/tests_primalite/testWilson.h"
#include "../head/fonctionnalites/tests_primalite/testFermat.h"
#include "../head/fonctionnalites/tests_primalite/testMillerRabin.h"
#include "../head/fonctionnalites/tests_primalite/testSolovay.h"
#include "../head/fonctionnalites/tests_primalite/testAKS.h"
#include "../head/mesures_performance/mesureTemps.h"

int main(int argc, char *argv[]) 
{
	srand(time(NULL));
    
    double tps[6][1025];
	mesureTemps(tps);
	ecrireMesures("mesures.txt",tps);
	
	//Génération optimale d'un nombre premier
	mpz_t premier;
	mpz_init(premier);
	int bits = 0;
	printf("Entrer la taille en bits du nombre premier à générer (2 - 1024) :\n");
	scanf("%d",&bits);
	RPNG_opt(tps, bits, premier);
	gmp_printf("Génération optimale d'un nombre premier de %d bits : %Zd\n",bits, premier);
	mpz_clear(premier);
	
	/*
	//Test chiffrement et déchiffrement RSA (module RSA mis à 32 bits pour accélérer nos tests)
	mpz_t n, e, d, m, c;
	mpz_inits(n, e, d, m, c, NULL);
	generationClesRSA_opt (tps, n, e, d);
	mpz_set_ui(m, 12345);
	printf("\n######################### RSA ######################\n");
	//risque de probleme chiffrement et déchiffrement RSA si deux des clés générées sont égales (à cause du seed de l'aléatoire)
	chiffrementRSA(m, n, e, c);
	gmp_printf("Chiffrement de %Zd : %Zd\n", m, c);
	dechiffrementRSA(c, n, d, m);
	gmp_printf("Déchiffrement de %Zd : %Zd\n", c, m);
    */
    
    return EXIT_SUCCESS;
}
