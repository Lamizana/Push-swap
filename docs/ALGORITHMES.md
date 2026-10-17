# Algorithmes

Ce document retrace les algorithmes essayés sur Push-swap, du premier prototype au tri finalement retenu. Les implémentations historiques sont conservées dans [`../utils/`](../utils/) : elles ne sont **pas** compilées par le `Makefile` (la variable `SRC` ne les référence pas) et servent de traces de recherche.

## Vue d'ensemble

| Étape | Fichier | Approche | Statut |
| --- | --- | --- | --- |
| 1 | [`list.c`](../utils/list.c) | Prototype de pile, manipulation seule | Abandonné |
| 2 | [`zehd_sort.c`](../utils/zehd_sort.c) | Boucle de comparaisons entre les sommets de `a` et `b` | Fonctionne mais trop long |
| 3 | [`zehd_sort_v2.c`](../utils/zehd_sort_v2.c) | Pivot sur la dernière valeur de `a` | Trop long |
| 4 | [`zehd_sort_v3.c`](../utils/zehd_sort_v3.c) | Variante du pivot, sans les comparaisons croisées | Trop long |
| 5 | [`ft_algo.c`](../utils/ft_algo.c) | Pivot explicite, `push_b` / `rotate` selon comparaison | Trop long |
| 6 | [`ft_algo_2.c`](../utils/ft_algo_2.c) | **Normalisation par index** puis réinsertion ordonnée | Piste décisive |
| 7 | [`ft_radix.c`](../push_swap/ft_radix.c) | **Tri radix** sur les index normalisés | Retenu |

---

## 1. Le prototype de pile

`utils/list.c` (en-tête daté du 03/12/2022, sous le nom `list_v2.c`) est le tout premier jet. Il définit une structure différente de celle du rendu final :

```c
typedef struct pile
{
	int			donnee;
	struct pile	*precedent;
}	t_pile;
```

Le fichier fournit `pile_push`, `pile_pop`, `init_stack_a`, `swap_a` et un `affichage_stack` de mise au point, avec un `main` de test. L'objectif à ce stade n'est pas de trier mais de **manipuler** les deux piles correctement.

> [!NOTE]
> La structure `t_pile` du prototype a été remplacée par `t_list { value, index, next }` dans le rendu final. L'ajout du champ `index` est ce qui a débloqué l'algorithme final : c'est lui qui porte la normalisation.

---

## 2. `zehd_sort` v1 — la boucle de comparaisons

Première tentative d'algorithme complet, décrite ainsi dans les notes d'origine :

```text
-> trouver une boucle:
- tant que pile a et b ne sont pas triees.

- si nb_a[0] > nb_a[1] && nb_b[0] > nb_b[1]  --> swap_a.
- si nb[0] < nb[1] --> push_b.

- si nb_a[0] > nb_a[1] && nb_b[0] > nb_b[1] --> rotates (ra / rb).
- si nb_a[0] < nb_a[1] && nb_b[0] > nb_b[1] --> reverses (rra / rrb).
```

L'implémentation (`utils/zehd_sort.c`, `zehd_sort_v1`) compare effectivement les deux premiers éléments de chaque pile et enchaîne `swaps`, `swap_a`, `push_b`, `rotates` ou `reverses`, en alternant une passe sur `a` et une passe sur `b` jusqu'à ce que les deux piles soient triées.

Le constat d'époque est sans appel : **« zehd_sort fonctionne mais trop long ! »**

---

## 3. `zehd_sort` v2 et v3 — le pivot sur la dernière valeur

Deux réécritures introduisent l'idée de pivot, décrite dans les notes sous le titre « CREATION D UN QUICKSORT » :

```text
- Recuperez la derniere valeur (n).
- Comparez:
		--> push_b si nb_a[0] < n.
		--> rotate_a si nb_a[0] > n.

- Vider stack_b dans stack_a.
		-> push_a.
- Repeter l operation.
```

Dans `utils/zehd_sort_v2.c` et `utils/zehd_sort_v3.c`, le pivot est obtenu par un `ft_lstlast()` local. Les deux versions partagent la même ossature : `ft_stack_a` répartit les éléments de `a` par rapport au pivot, `ft_stack_b` et `ft_push_a` ramènent ensuite les éléments dans l'ordre.

La différence tient aux comparaisons : la v2 croise les valeurs de `a` et de `b`, la v3 se contente de comparer les deux premiers éléments de `a`. Aucune des deux ne passe sous les seuils d'opérations.

---

## 4. `ft_algo` — le pivot explicite

`utils/ft_algo.c` (23/01/2023) formalise l'approche, avec l'en-tête suivant :

```c
/* - Choisir un pivot.
 * - si A1 < pivot -> push_b.
 * - si A1 > pivot -> rotate.
 *
 * - une fois a avec 1 element.
 * - push_a.
 * - recommencer l operation.
 */
```

Le fichier expose `tour_1()` et `sort_big_1()`. L'idée est de répéter des tours de partitionnement : chaque tour vide progressivement `a` vers `b`, puis `b` est reversée dans `a`.

Le problème reste le **choix du pivot** : sans garantie sur sa position, le nombre de tours et donc d'opérations dérive rapidement.

---

## 5. `ft_algo_2` — la normalisation par index

`utils/ft_algo_2.c` (24/01/2023) marque un tournant. Son en-tête :

```c
/*
 * - Creer un index pour normalisez les nombres.
 * - Push_b sauf la derniere valeur.
 * - Remet dans A trier par l index.
 * - Utilise des rotates ou reverse pour aller chercher la valeur suivante
 * */
```

Le fichier définit `ft_normalize()`, `value_min()`, `insert_sort()`, `replace_last_value()`, `find_last_value()` et `sort_big()`.

**C'est l'introduction de la normalisation**, et l'ancêtre direct de l'algorithme du rendu. Une fois chaque valeur remplacée par son rang (de `1` à `n`), trier ne consiste plus à comparer des entiers quelconques, mais des positions — un terrain de jeu beaucoup plus régulier.

La réinsertion se fait encore par rotations successives, ce qui reste coûteux. La suite logique est de traiter les index **bit par bit**.

---

## 6. Le tri radix retenu

L'algorithme du rendu final est dans [`../push_swap/ft_radix.c`](../push_swap/ft_radix.c). Il repose sur deux fonctions :

| Fonction | Rôle |
| --- | --- |
| `ft_normalize()` | Attribue à chaque élément son rang de `1` à `n` |
| `len_bit()` | Calcule le nombre de bits nécessaires pour représenter `n` |
| `radix()` | Trie bit par bit, du bit de poids faible au bit de poids fort |

À chaque passe sur un bit donné :

- l'élément en sommet de `a` a ce bit à `0` → `pb` (il part sur `b`) ;
- ce bit vaut `1` → `ra` (il tourne dans `a`) ;
- après la passe, `b` est entièrement reversée dans `a` par `pa`.

```console
		pile a (valeurs)                pile a (index normalisés)
		[ 42, 7, 900, -3 ]       →      [ 3, 2, 4, 1 ]

		bits de l'index, du LSB au MSB
		bit 0 : 0 → pb        bit 1 : 0 → pb        bit 2 : 0 → pb
		        1 → ra                1 → ra                1 → ra
		puis pa jusqu'à vider b, à chaque tour

		résultat : pile a triée par ordre croissant
```

**Pourquoi ce choix.** Le nombre de passes ne dépend que de `n`, jamais des valeurs elles-mêmes. La normalisation ramène des entiers quelconques (négatifs, jusqu'à `INT_MAX`) dans l'intervalle `[1, n]`, ce qui borne le nombre de bits à parcourir. Le coût est donc en O(n · log n) tours de pile, avec une constante acceptable.

> [!TIP]
> Conséquence mesurable : à `n` fixé, le nombre d'opérations est **constant** quelle que soit la permutation d'entrée. Le radix ne connaît pas de « mauvais cas » à 100 ou 500 éléments.

---

## Performances

Repères d'évaluation appliqués à la taille des piles :

| Taille | Note maximale | Seuil de validation |
| --- | --- | --- |
| 100 nombres | ≤ 700 opérations | ≤ 1 500 opérations |
| 500 nombres | ≤ 5 500 opérations | ≤ 11 500 opérations |

Résultats de la version historique `zehd_sort`, tels que notés pendant le développement :

| Taille | Attendu | Obtenu |
| --- | --- | --- |
| 3 nombres | 3 coups maximum | 3 |
| 5 nombres | 12 coups maximum | 12 / 13 |
| 100 nombres | entre 700 et 1 500 | **3 500** — au-dessus du seuil |
| 500 nombres | entre 5 500 et 11 500 | non mesuré |

Résultats de la version **radix** actuelle (moyenne sur 20 tirages aléatoires, mesurée le 17/10/2026, vérifiée par le `checker`) :

| Taille | Moyenne | Minimum | Maximum | Checker |
| --- | --- | --- | --- | --- |
| 3 nombres | 1 | 0 (déjà trié) | 2 | 20/20 OK |
| 5 nombres | 8 | 0 (déjà trié) | 11 | 20/20 OK |
| 100 nombres | **1 081** | 1 081 | 1 081 | 20/20 OK |
| 500 nombres | **6 778** | 6 778 | 6 778 | 20/20 OK |

À 100 et 500 éléments, les colonnes minimum et maximum sont identiques à la moyenne : c'est la conséquence directe du fonctionnement du radix décrite plus haut.

> [!NOTE]
> À 500 nombres, 6 778 opérations passent le seuil de validation (11 500) sans atteindre le seuil de note maximale (5 500). La piste la plus directe est de fusionner les paires d'instructions (`rr`, `ss`, `rrr`) pendant les passes, puisque le programme les implémente déjà sans jamais les émettre (constat détaillé dans [SPECIFICATIONS.md](SPECIFICATIONS.md)).
