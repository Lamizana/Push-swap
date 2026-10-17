# Spécifications

Ce document décrit le contrat d'interface du programme `push_swap` de ce dépôt : comment on l'invoque, ce qu'il écrit, comment il signale une erreur, et les performances qu'on a mesurées. Il porte sur le comportement de **ce programme**, vérifiable en l'exécutant, et non sur le devoir dont il est issu.

---

## Invocation

| Appel | Comportement |
| --- | --- |
| `./push_swap 3 1 2` | Entiers passés en arguments séparés |
| `./push_swap "3 1 2"` | Une seule chaîne, découpée par le programme |
| `./push_swap` | Aucun argument : rien n'est écrit, sortie immédiate |

- Le **premier entier de la liste est au sommet** de la pile `a`.
- Les signes `+` et `-` sont acceptés.

---

## Contrat de sortie

Le programme écrit sur la **sortie standard** la suite d'instructions qui trie la pile, une instruction par ligne :

```console
$>./push_swap 3 1 2
ra
$>
```

| Attendu | Interdit |
| --- | --- |
| Une instruction par ligne, terminée par un `\n` | En-tête, ligne vide, séparateur, texte explicatif |

Si la pile est déjà triée, le programme n'écrit **rien**.

Les onze instructions qu'il peut émettre :

| Instruction | Nom | Effet sur la pile |
| --- | --- | --- |
| `sa` | swap a | Intervertit les 2 premiers éléments de `a` |
| `sb` | swap b | Intervertit les 2 premiers éléments de `b` |
| `ss` | swap a + b | `sa` et `sb` en même temps |
| `pa` | push a | Prend le 1er élément de `b` et le pose sur `a` |
| `pb` | push b | Prend le 1er élément de `a` et le pose sur `b` |
| `ra` | rotate a | Décale `a` vers le haut : le 1er devient le dernier |
| `rb` | rotate b | Décale `b` vers le haut : le 1er devient le dernier |
| `rr` | rotate a + b | `ra` et `rb` en même temps |
| `rra` | reverse rotate a | Décale `a` vers le bas : le dernier devient le premier |
| `rrb` | reverse rotate b | Décale `b` vers le bas : le dernier devient le premier |
| `rrr` | reverse rotate a + b | `rra` et `rrb` en même temps |

> [!NOTE]
> Le programme émet six de ces onze instructions : `sa`, `sb`, `pa`, `pb`, `ra` et `rra`. Vérifié exhaustivement sur les 864 permutations de 4, 5 et 6 éléments. Les cinq autres — `ss`, `rb`, `rr`, `rrb` et `rrr` — sont implémentées mais jamais produites : le radix ne se sert que de `pb`, `pa` et `ra`, et les tris de 3 et 5 éléments ajoutent `sa`, `sb` et `rra` (voir [ALGORITHMES.md](ALGORITHMES.md)).

---

## Contrat d'erreur

Le programme signale une erreur dans trois cas :

- un paramètre qui n'est pas un nombre ;
- un nombre qui ne tient pas dans un `int` ;
- un doublon dans la liste.

```console
$>./push_swap 1 2 2
Error
$>
```

| Attendu | Détail |
| --- | --- |
| `Error` suivi d'un `\n` sur la **sortie d'erreur** | Rien n'est écrit sur la sortie standard |

> [!WARNING]
> Le **code de sortie reste 0** après une erreur : `ft_error()` appelle `exit(0)`. Le message est bien sur la sortie d'erreur, mais un script qui teste `$?` ne peut pas distinguer une erreur d'un succès. À corriger si ce comportement doit servir dans un enchaînement de commandes.

---

## Contraintes techniques

Ce que le projet s'impose, vérifiable dans le dépôt :

| Contrainte | État |
| --- | --- |
| Compilation sans avertissement avec `-Wall -Wextra -Werror` | Vérifié sous `clang` et `gcc` |
| `Makefile` sans relink, avec `$(NAME)`, `all`, `clean`, `fclean`, `re` | Présent |
| Aucune variable globale | Respecté |
| Aucune dépendance externe | Pas de libft : `ft_split`, `ft_strlen`, `ft_atoi` sont recodés dans le projet |
| Fonctions de la bibliothèque standard utilisées | `write`, `malloc`, `free`, `exit` — rien d'autre |
| Style de la norme 42 | Non vérifié : `norminette` n'est pas installé sur la machine de travail |

> [!NOTE]
> Le projet est autonome : il n'appelle ni `printf`, ni `read`, ni aucune fonction de tri de la bibliothèque standard.

---

## Seuils et performances

Repères d'évaluation appliqués à la taille des piles :

| Taille | Note maximale | Seuil de validation |
| --- | --- | --- |
| 100 nombres | ≤ 700 opérations | ≤ 1 500 opérations |
| 500 nombres | ≤ 5 500 opérations | ≤ 11 500 opérations |

Mesures du programme, moyenne sur 20 tirages aléatoires, chaque sortie validée par un `checker` (relevés du 17/10/2026) :

| Taille | Moyenne | Minimum | Maximum |
| --- | --- | --- | --- |
| 3 nombres | 1 | 0 (déjà trié) | 2 |
| 5 nombres | 8 | 0 (déjà trié) | 11 |
| 100 nombres | **1 081** | 1 081 | 1 081 |
| 500 nombres | **6 778** | 6 778 | 6 778 |

À 100 et 500 nombres, minimum et maximum sont égaux à la moyenne : le nombre d'opérations ne dépend que de la taille de la pile, jamais de la permutation d'entrée. C'est une propriété du tri radix, expliquée dans [ALGORITHMES.md](ALGORITHMES.md).

---

## Vérifier une exécution

Le dépôt ne fournit pas de programme `checker`. Le contrôle s'appuie sur le `checker_linux` fourni par le testeur tiers inclus :

```bash
ARG=$(shuf -i 0-99999 -n 500 | tr '\n' ' ')
./push_swap $ARG | ./push_swap-testeur-max/checker_linux $ARG
# OK
```

Le testeur complet se trouve dans [`../push_swap/push_swap-testeur-max/`](../push_swap/push_swap-testeur-max/) : il teste aussi les cas d'erreur et vérifie les fuites mémoire.
