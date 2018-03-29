#ifndef RPNG_H
#define RPNG_H

#include <gmp.h>
#include "../tests_primalite/tests_primalite.h"


void alea_premiers (mpz_t rpng, gmp_randstate_t r_state,int nb_bits_min,int nb_bits_max);
#endif
