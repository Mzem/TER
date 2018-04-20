#ifndef SOLOVAY_H
#define SOLOVAY_H

#include <gmp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int Solovay(mpz_t n, gmp_randstate_t r_state);

#endif
