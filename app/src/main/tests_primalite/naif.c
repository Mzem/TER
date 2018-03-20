#include "naif.h"



List* premiers(List* l, mpz_t n)
{//cette fonction va mettre tout les nombres premiers inferieurs a racine(n) dans l
	List* l2;
	List* l3;
	mpz_t racine,valeur,res_mod,i;
	mpz_inits(res_mod,valeur,racine,i,NULL);
	mpz_sqrt(racine,n);
	mpz_set_ui(i,2);
	l = malloc(sizeof(List)); 
	l2 = l;
	while(mpz_cmp(i, racine) <= 0)
	{
		mpz_init(l->val);
		mpz_set(l->val,i);
		l->next = malloc(sizeof(List));
		l = l->next;
		mpz_add_ui(i,i,1);
	}
	l = l2;
	//deuxieme partie de la fonction consiste a supprimer les multiples des valeurs qui sont deja dans la liste 
	while(l!= NULL)
	{
		mpz_set(valeur,l->val);
		l3=l;
		while(l3->next != NULL)
		{
			mpz_mod(res_mod,l3->next->val,valeur);
			if(mpz_cmp_ui(res_mod,0) == 0)
				l3->next = l3->next->next;
			else
				l3 = l3->next;
		}
		l = l->next;
	}
	mpz_clears(res_mod,valeur,racine,i,NULL);
	return l2;
}

int Naif(mpz_t n)
{
	List* l;
	List* l2;
	mpz_t res_mod;
	mpz_init (res_mod);
	//on cree une liste de nombre premiers inferieurs a racine(n)
	l=premiers(l,n);
	//on teste un par un si ils divisent n
	while(l != NULL)
	{
		mpz_mod(res_mod,n,l->val);
		if(	mpz_cmp_ui(res_mod,0)==0)
		{
			mpz_clear(res_mod);
			return 0;
		}
		else
			l = l->next;
	}
	//sinon il est premier
	mpz_clear(res_mod);
	return 2;
}
