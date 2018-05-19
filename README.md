# Projet Primalité
Code source et application (**UNIX**) dans le répertoire "**App**". 
Rapport détaillé dans le répertoire "**Doc**".
**Pré-requis :** installer la bibliothèque **GMP**.  
**Exécution :** utiliser un terminal UNIX et se positionner sur le répertoire "**App**" :    

* Compilation

		make

* Exécution

		 make run
	
* Nettoyage binaires

		 make clean
		
* Nettoyage intégral
		
		 make mrproper


### Fonctionnement du programme :  
Au lancement, l'application va faire appel au fonctionnalités module de mesure de temps d'exécution de chaque test de primalité. Ce module va non seulement exécuter chacun des test de primalité sur des nombres de 1 jusqu'à 1024 bits, mais aussi va enregistrer le temps de cette exécution dans un fichier **mesures.txt**.
Ainsi, on aura testé tous les algorithmes implémentés et mis en place un générateur de nombres premiers optimal.
