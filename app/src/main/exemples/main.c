#include "exemples.h"

int main(int argc, char *argv[]) {
	//initialisation de l'aléatoire
	unsigned long int seed = 1;
	gmp_randstate_t r_state;

    gmp_randinit_default(r_state);
    gmp_randseed_ui(r_state, seed);
	
    //Exemple :
    //essai_rsa(r_state);
    
    //Entrez la fonction à tester
    
    
    return 0;
}
