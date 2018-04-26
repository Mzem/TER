#include "../../../head/fonctionnalites/tests_primalite/testNaif.h"


Liste ajoutFin(Liste L, mpz_t v, int p) {
	if (L == NULL) {
		Element* nouv = malloc(sizeof(Element));
		mpz_init(nouv->val);
		mpz_set(nouv->val, v);
		nouv->prim = p;
		nouv->suiv = L;
		return nouv;
	}
	L->suiv = ajoutFin(L->suiv,v,p);
	return L;
}

void freeListe(Liste L) {
	if (L != NULL) {
		freeListe(L->suiv);
		mpz_clears(L->val, NULL);
		free(L);
	}
}

void afficheListe(Liste L) {
	if (L!=NULL){
		gmp_printf("%Zd : %d | ", L->val, L->prim);
		afficheListe(L->suiv);
	} else
		printf("\n");
}

// Retourne la liste des nombres premiers inférieurs à N
Liste Eratosthene(mpz_t N)
{	
	// On crée une liste de couples (nombre, primalité) pour les nombres 2 ... N, avec une primalité initialisée à premier (1)
	Liste L = NULL;
	mpz_t nb;
	mpz_init(nb);
	for (int i = 2 ; mpz_cmp_ui(N,i) >= 0 ; i++) {
		mpz_set_ui(nb, i);
		L = ajoutFin(L, nb, 1);
	}
	
	// Amélioration : ne garder que les nombres premiers
	// On marque "composé" tous les nombres composés de la liste
	mpz_t plusGrandPremier, pCarre;
	mpz_inits(plusGrandPremier, pCarre, NULL);
	mpz_set(plusGrandPremier, N);
	Liste tmp = L;
	
	while (tmp != NULL)
	{
		if (tmp->prim == 1) 
		{
			//Condition d'arret (amélioration)
			mpz_mul(pCarre,tmp->val,tmp->val);
			if ( mpz_cmp(pCarre, plusGrandPremier) > 0 )
				return L;
			
			//On marque comopsé les multiples d'un nombre premier
			Liste composes = tmp;
			int i = 2;
			mpz_t(iFoisVal);
			mpz_init(iFoisVal);
			mpz_mul_ui(iFoisVal, tmp->val, i);
			
			while( mpz_cmp(iFoisVal, N) <= 0) 
			{
				for (int j = 0 ; mpz_cmp_ui(tmp->val, j) > 0; j++) {
					//Mise à jour du plus grand premier (pour la condition d'arret)
					if (composes->prim == 1)
						mpz_set(plusGrandPremier, composes->val);
					composes = composes->suiv;
				}
				composes->prim = 0;
				i++;
				mpz_mul_ui(iFoisVal, tmp->val, i);
			}
			mpz_clear(iFoisVal);
		}
		tmp = tmp->suiv;
	}
	
	mpz_clears(nb, plusGrandPremier, pCarre, NULL);
	
	return L;
}


//Algo test naif
int testNaif(mpz_t n)
{
	//Premier test si n < 2
	if ( mpz_cmp_ui(n, 2) < 0 )
		return 0;
		
	mpz_t racine_n, resteDivision;
	mpz_inits(racine_n, resteDivision, NULL);
	
	//On crée la liste des nombres premiers inférieurs à racine(n)
	mpz_sqrt(racine_n, n);
	Liste Premiers = NULL;
	Premiers = Eratosthene(racine_n); 
	//afficheListe(Premiers);
	
	//On teste un par un si ces nombres premiers divisent n
	Liste tmp = Premiers;
	while (tmp != NULL)
	{
		//On ne teste que la division par les nombres premiers
		if (tmp->prim == 1)
		{
			mpz_mod(resteDivision, n, tmp->val);
			
			//Cas ou le nombre n'est pas premier
			if ( mpz_cmp_ui(resteDivision, 0) == 0 ) 
			{
				mpz_clears(resteDivision, racine_n, NULL);
				freeListe(Premiers);
				return 0;
			}
		}
		tmp = tmp->suiv;
	}
	
	//Cas ou le nombre est premier
	mpz_clears(resteDivision, racine_n, NULL);
	freeListe(Premiers);
	return 2;
}
