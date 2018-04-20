#ifndef NAIF_H
#define NAIF_H

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

struct element {
    mpz_t val;
    int prim;	//rajouté pour garder info sur la primalité de val
    struct element* suiv;
};

typedef struct element Element;

typedef Element* Liste;

int testNaif(mpz_t);

Liste Eratosthene(mpz_t);

#endif

