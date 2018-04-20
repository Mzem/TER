#include "../../../head/fonctionnalites/tests_primalite/testSolovay.h"

int Solovay(mpz_t n, gmp_randstate_t r_state)
{	
	//Initialisations
	int retour,x;
	mpz_t i,a,res,puiss,nmoins1,mod;
	mpz_inits(i,a,res,puiss,nmoins1,mod,NULL);
	
	////////////////////////Test si n est impair/////////////////////////////
	mpz_mod_ui(mod,n,2);
	
	if(mpz_cmp_ui(mod,0)==0){
	gmp_printf("Composé\n");
	retour=0;
	return retour;
				}
	/////////////////////////////////////////////////////////////////////////
	
	
	//Choix du "a" aléatoire
	do{
	mpz_urandomm (a,r_state,n);
	}
	while((mpz_cmp_ui(a,2)<0));
	
	//Symbole de legendre "x"
	 x=mpz_legendre(a,n);
	
	//nmoins1 = n-1
	mpz_sub_ui(nmoins1,n,1);
	//puiss= (n-1)/2
	mpz_cdiv_q_ui(puiss,nmoins1,2);
	
	
		 //Initialisation de "i" pour la boucle
		 mpz_set(i,a);
		 //Tant que (i>0 et a>=2)
		while(((mpz_cmp_ui(i,1)) > 0) && (mpz_cmp_ui(a,2)>=0))
		{
		
		//Re-calcul du symbole de légendre "x" car a est decrementée à chaque fois
		x=mpz_legendre(a,n);
			
		//res=a^((n-1)/2)mod n
		mpz_powm_sec(res, a, puiss, n);
			
		//si res =-1[n] et x=-1 alors res=x
		if((x==-1)&&(mpz_cmp(res,nmoins1)==0)){
			mpz_set_d(res,x);}
			
		//si x=0 ou si x!=res
		if((mpz_cmp_d(res,x)!=0)||(x==0)){
			gmp_printf("Composé\n");
			retour=0;
			return retour;
				}
					
		else {mpz_sub_ui(a,a,1);}
						
			 mpz_sub_ui(i,i,1);
		}
		 gmp_printf("Premier\n");
		
	
	mpz_clears (i,a,res,puiss,nmoins1,mod,NULL);
	retour=1;
	return retour;
}
