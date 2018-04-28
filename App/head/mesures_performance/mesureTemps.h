#ifndef MESURE_TEMPS_H
#define MESURE_TEMPS_H

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../fonctionnalites/cryptosystemes/RPNG.h"
 

void mesureTemps(double [6][1025]);

//Ecriture des mesures dans un fichier formatté pour le tracage de plots
void ecrireMesures(char*, double [6][1025]);
 
 
#endif
