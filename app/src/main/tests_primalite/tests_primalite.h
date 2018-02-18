#ifndef TESTS_PRIMALITE_H
#define TESTS_PRIMALITE_H

#include <gmp.h>

#include "fermat.h"
#include "miller_rabin.h"

int isProbabPrime(mpz_t n, int k, gmp_randstate_t r_state);

#endif
