#ifndef RPNG_H
#define RPNG_H

#include <gmp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../tests_primalite/testOptimal.h"

#define K 15	//Nombre de répétition des tests probabilistes

// Renvoie un nombre premier d'un nombre de bits souhaité, généré à partir de la fonction de test de primalitée passée en paramètre
// Deux variantes : RPNG pour les tests de primalité déterministes et probabiliste (1 paramètre en plus) et générique

void RPNG_det (int (*testPrimalite)(mpz_t), int bits, mpz_t retour);

void RPNG_prob (int (*testPrimalite)(mpz_t, int), int bits, mpz_t retour);

void RPNG_opt (int bits, mpz_t retour);

#endif
