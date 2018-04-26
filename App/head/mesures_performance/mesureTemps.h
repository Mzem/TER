#ifndef MESURE_TEMPS_H
#define MESURE_TEMPS_H

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../fonctionnalites/cryptosystemes/RPNG.h"
#include "../fonctionnalites/tests_primalite/testNaif.h"
#include "../fonctionnalites/tests_primalite/testWilson.h"
#include "../fonctionnalites/tests_primalite/testFermat.h"
#include "../fonctionnalites/tests_primalite/testMillerRabin.h"
#include "../fonctionnalites/tests_primalite/testSolovay.h"
 

void mesureTemps(double [6][1024]);
 
 
#endif
