# Avancement

Journal de développement de Push-swap : le plan de travail d'origine, ce qui a été réalisé, et les points de blocage rencontrés en route. Ce document conserve les étapes telles qu'elles avaient été notées pendant le projet, avec les fichiers tels qu'ils existent aujourd'hui.

## Chronologie

| Repère | Date | Source |
| --- | --- | --- |
| Début du travail | 03 – 09/12/2022 | En-têtes de `utils/list.c` et `utils/zehd_sort.c` |
| Écriture des sources du rendu | 14/12/2022 | En-têtes de `main.c`, `Makefile`, `push_swap.h` |
| Dernières retouches des sources | 26/01/2023 | En-têtes de `main.c` et `ft_radix.c` |
| Première entrée dans l'historique git | 22/03/2023 | `git log --reverse` |
| Dernier commit avant reprise | 04/09/2024 | `git log -1` |
| Correctif de compilation et documentation | 17/10/2026 | Ce dépôt |

> [!NOTE]
> Les en-têtes de fichiers sont antérieurs au premier commit : le travail a commencé hors dépôt, puis a été versé dans l'historique git en mars 2023.

---

## Le plan de travail d'origine

### (1) Création du squelette

Liste des fichiers prévus au départ :

```text
Makefile
push_swap.h
check_args.c
push_swap.c
ft_stacks.c
ft_swap.c
ft_rotate.c
ft_reverse.c
push_swap_utils.c
```

**Ce qui existe aujourd'hui.** Le squelette a été conservé, avec des renommages :

| Prévu | Réalisé |
| --- | --- |
| `push_swap.c` | `main.c` |
| `check_args.c` | `ft_check.c` et `ft_errors.c` |
| `push_swap_utils.c` | `push_swap_utils.c` (inchangé) |
| `ft_stacks.c`, `ft_swap.c`, `ft_rotate.c`, `ft_reverse.c` | inchangés |

Se sont ajoutés en cours de route : `ft_init_stack.c`, `ft_push.c`, `ft_split.c`, `ft_sorts.c`, `ft_sort_three.c`, `ft_sort_five.c` et `ft_radix.c`.

### (2) Gestion sommaire des arguments

Objectif :

```text
- Les recuperer.
- les stockes dans "a".
	--> Creer une pile (liste chainee).
```

Réalisé dans `ft_init_stack.c` et `ft_stacks.c` : les arguments sont convertis puis empilés dans `a` sous forme de liste chaînée `t_list`.

### (3) Implémentation des instructions

```text
- Longueur de stack_a -> nombres d arguments -1.
- Longueur de stack_b -> initialisee a 0.
```

Réalisé dans `ft_swap.c`, `ft_push.c`, `ft_rotate.c` et `ft_reverse.c`, avec pour chaque famille une fonction simple et une fonction double (`ss`, `rr`, `rrr`). Le comptage passe par `ft_lstsize()`.

### (4) Gestion des fonctions et vérification valgrind

```text
- Gestion des fonctions et verification valgrind.
```

La libération de la mémoire est centralisée dans `ft_lstclear()`, appelée à la fin de `main()` et dans les chemins d'erreur (`ft_errors.c`). Les fuites ont été surveillées à la main pendant le développement, faute d'intégration continue.

### (5) Création de l'algorithme

Le plan prévoyait un fichier dédié :

```text
(5) Creation de l algorithme.
	--> Creer un fichier pour ca:
		- ft_algo.c.
```

**C'est l'étape qui a demandé le plus de temps.** Les itérations successives (`zehd_sort` v1 à v3, `ft_algo`, `ft_algo_2`) sont archivées dans [`../utils/`](../utils/) et détaillées dans [ALGORITHMES.md](ALGORITHMES.md).

Le premier algorithme fonctionnel a été écarté pour une raison simple, notée telle quelle à l'époque :

```text
--> zehd_sort fonctionne mais trop long !
```

Il fallait ensuite traiter les petites tailles séparément :

```text
- gestion des cas avec 3 arguments.
- gerer les cas avec 5 elements.
- cas ou pile a est triee et qu il y a plus rien dans la b.
	- pour 3 chiffres -> 3 coups max.						-> 3
	- pour 5 chiffres -> 12 coups max.						-> 12/13
	- pour 100 chiffres -> entre 700 et 1500 coups max.		-> 3500
	- pour 500 chiffres -> entre 5500 et 11500 coups max.
```

Deux observations de l'époque méritent d'être relevées :

- les cas 3 et 5 éléments passaient les seuils dès cette version (3 coups, puis 12/13) ;
- les 100 éléments étaient à **3 500 opérations**, très au-dessus du seuil de 1 500. C'est cet écart qui a motivé l'abandon du pivot au profit du tri radix. Le seuil des 500 éléments n'a jamais été renseigné.

Réalisé dans `ft_sort_three.c`, `ft_sort_five.c` puis `ft_radix.c` — ce dernier remplaçant complètement l'approche par pivot.

### (6) Gestion des arguments

```text
(6) Gestion des arguments.
	- parcourir les arguments une 1er fois:
	- si c est pas un chiffre et que c est pas un + ou - ou un ' '
		-> exit(0)
	- split chaque chaine et stocke dans stack_a.
	- Gestion des chaines vide.
	- gestion des doublons.
```

Réalisé en deux fichiers, ce qui explique le découpage actuel :

| Fichier | Rôle |
| --- | --- |
| `ft_check.c` | `check_numbers`, `check_int`, `check_str`, `check_tab`, `ft_doublon`, `check_empty_str` |
| `ft_split.c` | `ft_split`, `nb_bloc`, `ft_copy`, `ft_parsing` |
| `ft_errors.c` | `ft_error` (écrit `Error` sur la sortie d'erreur) |

> [!NOTE]
> Le message d'erreur était noté `"ERROR"` en majuscules dans les notes d'origine. Le sujet demande `Error` : c'est ce que le code implémente, et les notes ont été corrigées ici.

### (7) Nettoyage des fichiers

Dernière étape du plan : retirer les fichiers de travail et ne garder que ceux du rendu. Les fichiers d'expérimentation ont été déplacés dans `utils/` plutôt que supprimés, avec le sujet officiel au même endroit. Ils ne sont pas compilés (absents de la variable `SRC` du `Makefile`).

---

## La tentative de quicksort

En fin de notes, une piste restée inachevée :

```text
## CREATION D UN QUICKSORT.

	- Recuperez la derniere valeur (n).
	- Comparez:
			--> push_b si nb_a[0] < n.
			--> rotate_a si nb_a[0] > n.

	- Vider stack_b dans stack_a.
			-> push_a.
	- Repeter l operation.
```

Cette approche est celle qui a été développée dans `zehd_sort` v2 et v3, puis dans `ft_algo`. Aucune de ces variantes n'a atteint les seuils sur 100 éléments. Elle a été abandonnée au profit du radix, après l'introduction de la normalisation par index dans `ft_algo_2.c`.

---

## État d'avancement

| Étape du plan | État | Fichier(s) |
| --- | --- | --- |
| (1) Squelette | Terminé | `Makefile`, `push_swap.h`, `main.c`, … |
| (2) Gestion des arguments | Terminé | `ft_init_stack.c`, `ft_stacks.c` |
| (3) Instructions | Terminé | `ft_swap.c`, `ft_push.c`, `ft_rotate.c`, `ft_reverse.c` |
| (4) Mémoire et valgrind | Terminé | `ft_stacks.c` (`ft_lstclear`) |
| (5) Algorithme | Terminé par le radix | `ft_radix.c`, `ft_sort_three.c`, `ft_sort_five.c` |
| (6) Parsing et erreurs | Terminé | `ft_check.c`, `ft_split.c`, `ft_errors.c` |
| (7) Nettoyage | Terminé | `utils/` |
| Quicksort | Abandonné | `utils/zehd_sort_v2.c`, `utils/zehd_sort_v3.c` |

---

## Points de blocage rencontrés

| Blocage | Cause | Résolution |
| --- | --- | --- |
| Algorithme trop long | Approche par pivot instable, pivot mal choisi | Passage au tri radix |
| 100 éléments à 3 500 opérations | `zehd_sort` comparait des valeurs non normalisées | Normalisation par index puis tri par bits |
| Cas 3 et 5 éléments | Le radix est inefficace sur les très petites piles | Fonctions dédiées `sort_three` et `sort_five` |
| Compilation impossible avec les outils récents | Deux variables assignées mais non lues, refusées par `-Werror` | Variables mortes supprimées le 17/10/2026 |

---

## Reste à faire

- **Fusion d'instructions** : émettre `rr`, `ss` ou `rrr` à la place de deux instructions simples quand elles s'enchaînent, pour réduire le nombre d'opérations sur 500 nombres.
- **Tests automatisés** : le dépôt s'appuie aujourd'hui sur `push_swap-testeur-max` lancé à la main.
- **Images de démonstration** : aucune capture du visualiseur n'est présente à la racine du dépôt.
