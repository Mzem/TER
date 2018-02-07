#ifndef RSA_H
#define RSA_H

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

#define NB_BITS_CLE 512
#define NB_BITS_MSG 1024
#define NB_REPS_MILLER_RABIN 50

/**
 * @param c
 * @param m
 * @param e
 * @param n
 * */
void chiffrement(mpz_t c, const mpz_t m, const mpz_t e, const mpz_t n);

/**
 * @param m
 * @param c
 * @param e
 * @param n
 * */
void dechiffrement(mpz_t m, const mpz_t c, const mpz_t d, const mpz_t n);

/**
 * @param n
 * @param e
 * @param p
 * @param q
 * @param d
 * */
void creationCles(mpz_t n, mpz_t e, mpz_t p, mpz_t q, mpz_t d);
#endif
