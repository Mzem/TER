#ifndef NAIF_H
#define NAIF_H

#include <gmp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

struct list
{
    mpz_t val;
    struct list *next;
};
typedef struct list List;

int Naif(mpz_t n);
List* premiers(List* l, mpz_t n);

#endif

