# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamizan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 11:55:59 by alamizan          #+#    #+#              #
#    Updated: 2023/01/04 10:30:56 by alamizan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

- FICHIERS DE RENDU:
	- push_swap --> executable.
	- Makefile  --> NAME, all, clean, fclean, re.	
	- *.h
	- *.c

- OBJECTIFS:
	- Trier les donnees.

-------------------------------------------------------------------------------
- REALISER UN PROGRAMME QUI CALCULE ET AFFICHE LE PLUS PETIT PROGRAMME
FAIT D INSTRUCTION PERMETTENT DE TRIER LES ENTIER PASSEE EN PARAMETRE.
-------------------------------------------------------------------------------
	- On a un ensemble d entiers a disposition.
	- Deux piles pour les stocker.
	- Un ensemble d instructions pour les manipuler.
		--> Algorithmie.
	- Trier en moins de coups possibles.

-------------------------------------------------------------------------------- 
- ALGORITHMHE
-------------------------------------------------------------------------------
	- Premiere rencontre avec la notion de complexite.
	 
-------------------------------------------------------------------------------
- FONCTIONS EXTERNE AUTORISEES:
-------------------------------------------------------------------------------
	- read   --> lire depuis un descripteur de fichier.
	- write  --> appel systeme: affiche un caractere a l ecran.
	- malloc --> allocation dynamique de memoire.
	- free   --> liberation dynamique de memoire.
	- exit   --> terminer normalement un processus.
	- ft_printf

-------------------------------------------------------------------------------
- LE PROGRAMME PUSH_SWAP.
-------------------------------------------------------------------------------
	- Libft autorisee.
	- Makefile --> pas de relink.
	- Les variables globales sont interdites.
	- programme push_swap qui prend en parametre:
		--> pile a: liste d entiers.
		--> le premier parametre est au sommet de la pile.
		--> ATTENTION a l ordre.
	
	- Il doit afficher un programme composee de la plus courte suite d ins-
	tructions qui permet de trier la pile a:
		--> le plus petit nombre etant au sommet de la pile.
	- Les instructions doivent etre separees par un '\n'.

	- Le but est de trier les entiers avec le moins d operations possibles:
		--> Le nombres d instructions calculee sera comparer avec un nombre
			d operations maximum tolerees.
		--> Si le nombre d instruction est trop grand ou qu la liste
			n est pas trier, on a 0.

	- En cas d erreur:
		--> Si certains parametres ne sont pas des nombres.
		--> Si les nombres ne tiennent pas dans un int.
		--> Si il y a des doublons.
			--> Afficher "ERROR" suivi d un '\n' sur la SORTIE D ERREUR.

-------------------------------------------------------------------------------
- LES REGLES.
-------------------------------------------------------------------------------
- AU DEPART:
	- Le jeu est constituee de 2 piles -> a et b.
		- La pile "a" contient une quantite aleatoire de nombres:
			--> positfs ou negatifs.
			--> ne peuvent pa etre dupliques.
		- La pile "b" est vide.

- OBJECTIFS:
	- Trier les nombres de la pile "a" par odre croissant.

- INSTRUCTIONS AUTORISEES:

--> sa (swap a):
		- Intervertit les 2 premiers elements au sommet de la pile "a".
		- Ne fait rien si il y en a aucun.
--> sb (swap b):
		- Intervertit les 2 premiers elements au sommet de la pile "b".
		- Ne fait rien si il y en a aucun.
--> ss:
		- sa et sb en meme temps.

--> pa (push a):
		- Prend le 1er elements au sommet de "b" et le met sur "a".
		- Ne fait rien si "b" est vide.
--> pb (push b):
	- Prend le 1er elements au sommet de "a" et le met sur "b".
	- Ne fait rien si "a" est vide.

--> ra (rotate a):
	- Decale d une position vers le haut tous les elements de la pile "a".
	- Le 1er element devient le dernier.
--> rb (rotate b):
	- Decale d une position vers le haut tous les elements de la pile "b".
	- Le 1er element devient le dernier.
--> rr:
	- ra et rb en meme temps.

--> rra (reverse rotate a):
	- Decale d une position vers le bas tous les elements de la pile "a".
	- Le  dernier elements de vient le premier.
--> rrb (reverse rotate b):
	- Decale d une position vers le bas tous les elements de la pile "b".
	- Le  dernier elements de vient le premier.

--> rrr:
	- rra et rrb en meme temps.

-------------------------------------------------------------------------------
- AU BOULOT !!
-------------------------------------------------------------------------------
	(1) Creation du squelette:
		- Makefile
		- push_swap.h
		- check_args.c
		- push_swap.c
		- ft_stacks.c
		- ft_swap.c
		- ft_rotate.c
		- ft_reverse.c
		- push_swap_utils.c

	(2) Gestion sommaire des arguments:
		- Les recuperer.
		- les stockes dans "a".

		--> Creer une pile (liste chainee).

	(3) Implementation des instructions:
		- Longueur de stack_a -> nombres d arguments -1.
		- Longueur de stack_b -> initialisee a 0. 

	(4) Gestion des fonctions et verification valgrind.

	(5) Creation de l algorithme.
		--> Creer un fichier pour ca:
			- ft_algo.c.

		-> trouver une boucle:
		- tant que pile a et b ne sont pas triees.

		- si nb_a[0] > nb_a[1] && nb_b[0] > nb_[1]  --> swap_a.
		- si nb[0] < nb[1] --> push_b.

		- si nb_a[0] > nb_a[1] && nb_b[0] > nb_b[1] --> rotates (ra / rb).
		- si nb_a[0] < nb_a[1] && nb_b[0] > nb_b[1] --> reverses (rra / rrb).

	--> zehd_sort fonctionne mais trop long !	
- gestion des cas avec 3 arguments.
- gerer les cas avec 5 elements.
- cas ou pile a est triee et qu il y a plus rien dans la b.
	- pour 3 chiffres -> 3 coups max.						-> 3
	- pour 5 chiffres -> 12 coups max.						-> 12/13
	- pour 100 chiffres -> entre 700 et 1500 coups max.		-> 3500
	- pour 500 chiffres -> entre 5500 et 11500 coups max.

	(6) Gestion des arguments.
		- parcourir les arguments une 1er fois:
		- si c est pas un chiffre et que c est pas un + ou - ou un ' '
			-> exit(0)
		- split chaque chaine et stocke dans stack_a.
		- Gestion des chaines vide.
		- gestion des doublons.

	(7) Nettoyage fichiers.

-------------------------------------------------------------------------------
- CREATION D UN QUICKSORT.
-------------------------------------------------------------------------------

	- Recuperez la derniere valeur (n).
	- Comparez:
			--> push_b si nb_a[0] < n.
			--> rotate_a si nb_a[0] > n.

	- Vider stack_b dans stack_a.
			-> push_a.
	- Repeter l operation.





