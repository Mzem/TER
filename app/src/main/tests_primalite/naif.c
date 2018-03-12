#include "naif.h"

struct list
{
    mpz_t val;
    struct list *next;
};
typedef struct list List;

void premiers(List l, mpz_t n)
{//cette fonction va mettre tout les nombres premiers inferieurs a racine(n) dans l
	mpz_t racine;
	mpz_init (racine);
	mpz_sqrt(racine,n);
	mpz_t i;
	mpz_init (i);
	for (i = 0; i < racine; i++)
	{
		l.val = i;
		l = l.next;
	}
	//non fonctionnel pour le moment
	//deuxieme partie de la fonction consiste a supprimer les multiples des valeurs qui sont deja dans la liste 
}

int Naif(mpz_t n)
{
	List l;
	mpz_t res_mod;
	mpz_init (res_mod);
	premiers(l,n);
	while(l != NULL)
	{
		mpz_mod(res_mod,n,l.val);
		if(	mpz_cmp_ui(res_mod,0)==0)
			return 0;
		else
			l = l.next;
	}
	//premier
	return 2;
}
