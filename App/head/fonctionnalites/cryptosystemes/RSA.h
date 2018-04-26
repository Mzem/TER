#ifndef RSA_H
#define RSA_H

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "RPNG.h"

#define BITS_MODULE_RSA 32

void chiffrementRSA (mpz_t m, const mpz_t n, const mpz_t e, mpz_t c);

void dechiffrementRSA (mpz_t c, const mpz_t n, const mpz_t d, mpz_t m);

// Génération clés : trois variantes : génération avec test de primalité déterministe et probabiliste et générique
void generationClesRSA_det (int (*testPrimalite)(mpz_t), mpz_t n, mpz_t e, mpz_t d);
void generationClesRSA_prob (int (*testPrimalite)(mpz_t, int), mpz_t n, mpz_t e, mpz_t d);
void generationClesRSA_opt (mpz_t n, mpz_t e, mpz_t d);

#endif
