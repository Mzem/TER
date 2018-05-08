#ifndef AKS_H
#define AKS_H

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
  mpz_t table;
  unsigned int size;		/* Bit set 1: composite */
} Sieve;

typedef struct {
  mpz_t* coef;
  unsigned int deg;
} Polynomial;

void initialize_sieve (Sieve*);

void destroy_sieve (Sieve*);

int sieve_primality_test (unsigned int, Sieve*);

void initialize_polynomial (Polynomial** , unsigned int);

void destroy_polynomial (Polynomial**);

void clone_polynomial(Polynomial**, Polynomial*);

void compact_polynomial (Polynomial* );

int is_equal_polynomial (Polynomial* , Polynomial* );

void get_polynomial_coef (mpz_t* ,Polynomial*, unsigned int );

void set_polynomial_coef (Polynomial* , unsigned int, mpz_t* );

void set_polynomial_coef_si (Polynomial* , unsigned int, int);

void polynomial_modular_multiplication (Polynomial**, Polynomial*, Polynomial*, mpz_t, unsigned int);

void polynomial_modular_power (Polynomial** , Polynomial* , mpz_t , unsigned int );

int testAKS(const mpz_t);

#endif
