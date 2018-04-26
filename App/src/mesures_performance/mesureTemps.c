#include "../../head/mesures_performance/mesureTemps.h"


void mesureTemps(double tps[6][1024])
{
	mpz_t premier;
	mpz_init(premier);
	clock_t debut, fin;
	
	//Pour chaque test
	for (int testPrim = 0; testPrim < 5; testPrim++)
	{
		for (int nbBits = 0; nbBits < 16; nbBits++)
		{
			debut = clock();
			switch (testPrim)
			{
				case 0 : RPNG_det(testNaif, nbBits, premier); break;
				case 1 : RPNG_det(testWilson, nbBits, premier); break;
				case 2 : RPNG_prob(testFermat, nbBits, premier); break;
				case 3 : RPNG_prob(testMillerRabin, nbBits, premier); break;
				case 4 : RPNG_prob(testSolovay, nbBits, premier); break;
				//case 5 : RPNG_det(testAKS, nbBits, premier); break;
				default: printf("/!\\    ERREUR : test non trouvé    /!\\\n"); break;	
			}
			fin = clock();
			tps[testPrim][nbBits] = (double)(fin - debut) / (double) CLOCKS_PER_SEC;
		}
		
	}
	
	mpz_clear(premier);
		
}
