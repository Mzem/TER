#ifndef RPNG_H
#define RPNG_H

#include <gmp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../tests_primalite/testNaif.h"
#include "../tests_primalite/testWilson.h"
#include "../tests_primalite/testFermat.h"
#include "../tests_primalite/testMillerRabin.h"
#include "../tests_primalite/testSolovay.h"
#include "../tests_primalite/testAKS.h"

#define K 5	//Nombre minimal de répétitions des tests probabilistes

// Renvoie un nombre premier d'un nombre de bits souhaité, généré à partir de la fonction de test de primalitée passée en paramètre
// Deux variantes : RPNG pour les tests de primalité déterministes et probabiliste (1 paramètre en plus) et générique

void RPNG_det (int (*testPrimalite)(const mpz_t), int bits, mpz_t retour);

void RPNG_prob (int (*testPrimalite)(const mpz_t, int), int bits, mpz_t retour);

// Générateur qui choisit le meilleur test de primalité à utiliser selon le nombre de bits à générer
void RPNG_opt (double [6][1025], int bits, mpz_t retour);

#endif
