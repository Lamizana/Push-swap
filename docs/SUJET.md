# Sujet — référence

Récapitulatif des exigences du sujet officiel de Push-swap ([`../utils/fr.subject.pdf`](../utils/fr.subject.pdf)) et de la façon dont ce dépôt y répond. Sert de référence quand on reprend le code plus tard.

## Fichiers de rendu

| Fichier | Attendu | Présent |
| --- | --- | --- |
| `push_swap` | Exécutable, compilé depuis les sources | généré par `make` |
| `Makefile` | Règles `$(NAME)`, `all`, `clean`, `fclean`, `re` | [`../push_swap/Makefile`](../push_swap/Makefile) |
| `*.h` | En-têtes | `push_swap.h` |
| `*.c` | Sources | 15 fichiers dans `push_swap/` |

Le `Makefile` doit compiler avec `-Wall`, `-Wextra` et `-Werror`, et **ne doit pas relink**. Les deux points sont respectés.

## Objectifs du projet

Le sujet demande un programme qui **calcule et affiche le plus court programme d'instructions** permettant de trier les entiers passés en paramètre, en ne disposant que de deux piles et d'un jeu d'instructions restreint.

Le sujet présente l'exercice comme la première rencontre avec la **notion de complexité** : d'une configuration d'entiers à une autre, un même algorithme de tri n'est pas forcément le plus efficace. Le radix retenu répond à ce problème en devenant insensible à la permutation d'entrée (voir [ALGORITHMES.md](ALGORITHMES.md)).

## Contraintes d'implémentation

| Contrainte | Source | Respectée |
| --- | --- | --- |
| Projet écrit en C | Règles communes | Oui |
| Code à la Norme 42 | Règles communes | Non vérifiable ici — `norminette` n'est pas installé sur la machine de travail |
| `Makefile` avec `-Wall -Wextra -Werror`, sans relink | Règles communes | Oui |
| Variables globales interdites | Partie obligatoire | Oui |
| Libft autorisée | Partie obligatoire | Non utilisée : le rendu est autonome (`ft_split`, `ft_strlen`, `ft_atoi` recodés dans le projet) |

> [!NOTE]
> La libft est **autorisée mais facultative**. Si elle avait été utilisée, ses sources auraient dû être copiées dans un dossier `libft/` à la racine, et le `Makefile` aurait dû la compiler au préalable via son propre `Makefile`. Ce dépôt ne dépend d'aucune bibliothèque externe.

## Fonctions externes autorisées

| Fonction | Rôle |
| --- | --- |
| `read` | Lire depuis un descripteur de fichier |
| `write` | Écrire sur un descripteur de fichier |
| `malloc` | Allocation dynamique de mémoire |
| `free` | Libération de mémoire |
| `exit` | Terminer un processus |
| `ft_printf` | Sortie formatée — **et tout équivalent codé par vous** |

Le projet n'utilise que `write`, `malloc`, `free` et `exit`. Aucune fonction de `printf`, aucune fonction de tri de la libc.

## Comportement attendu du programme

- `push_swap` prend en paramètre la pile `a` sous la forme d'une **liste d'entiers**.
- Le **premier paramètre est au sommet** de la pile. L'ordre a son importance.
- Le programme affiche la suite d'instructions qui trie la pile `a`, le **plus petit nombre au sommet**.
- Les instructions sont **séparées par un `\n` et rien d'autre**.
- Si aucun argument n'est donné, le programme s'arrête et n'affiche rien.

```console
$>./push_swap 2 1 3 6 5 8
sa
pb
...
$>
```

## Cas d'erreur

Le programme doit afficher `Error` suivi d'un `\n` sur la **sortie d'erreur** si :

- certains paramètres ne sont pas des nombres ;
- des nombres ne tiennent pas dans un `int` ;
- la liste contient des doublons.

> [!IMPORTANT]
> Les notes d'origine du projet mentionnaient `"ERROR"` en majuscules. Le sujet demande `Error` : c'est bien ce que le code écrit (`ft_errors.c`), et la documentation a été alignée sur le sujet.

## Seuils d'évaluation

Le nombre d'instructions produites est comparé à un **nombre maximum toléré**. Un programme trop long, ou une liste non triée, vaut 0.

Les valeurs chiffrées ci-dessous proviennent de la **grille d'évaluation**, pas du texte du sujet (qui n'énonce que le principe) :

| Taille | Note maximale | Seuil de validation |
| --- | --- | --- |
| 100 nombres | ≤ 700 opérations | ≤ 1 500 opérations |
| 500 nombres | ≤ 5 500 opérations | ≤ 11 500 opérations |

Résultats mesurés de la version actuelle : **1 081** opérations à 100 nombres et **6 778** à 500 (détail dans [ALGORITHMES.md](ALGORITHMES.md)).

## Bonus

Le sujet propose un bonus : écrire son propre `checker`, un programme qui prend la pile `a` puis lit sur l'entrée standard une liste d'instructions, les exécute, et affiche `OK` ou `KO` sur la sortie standard.

| Bonus | État |
| --- | --- |
| Programme `checker` | Non réalisé |
| Règle `bonus` dans le `Makefile` | Absente |

Le dépôt s'appuie à la place sur le `checker_linux` fourni avec le testeur (voir [../push_swap/push_swap-testeur-max/](../push_swap/push_swap-testeur-max/)).
