#ifndef EXEMPLES_H
#define EXEMPLES_H
/**
 * Ce module contient des routines pour expérimenter les fonctionnalités développées.
 * */
 
#include <gmp.h>

#include "../cryptosystemes/cryptosystemes.h"
#include "../tests_primalite/tests_primalite.h"
#include "../generateur_premier/rpng.h"

void essai_rsa(gmp_randstate_t r_state);
void test_alea_premiers (mpz_t rpng,gmp_randstate_t r_state, int nb_bits_max);
#endif
