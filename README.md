<div align="center">

<!-- ▸ Row de badges cliquables (https://shields.io) : un badge = un lien. -->
<p align="center">
  <a href="https://en.cppreference.com/w/c"><img src="https://img.shields.io/badge/Langage-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white" alt="C"></a>
  <a href="https://www.gnu.org/software/make/"><img src="https://img.shields.io/badge/Build-Makefile-427819?style=for-the-badge&logo=gnu&logoColor=white" alt="Makefile"></a>
  <a href="https://github.com/Lamizana/Push-swap"><img src="https://img.shields.io/badge/Projet-42-000000?style=for-the-badge&logo=42&logoColor=white" alt="Projet 42"></a>
</p>

<h1>Push-swap</h1>

<p><strong>Trier une liste d'entiers avec deux piles et un jeu d'instructions restreint, en un minimum d'opérations.</strong></p>

<p><em>Projet de l'école 42.</em></p>
<p>Créé le 22/03/2023 · Dernière mise à jour : 04/09/2024</p>

<a href="https://lamizana.github.io/ZehdBox/">
  <img src="https://img.shields.io/badge/Portfolio-ZehdBox-8A2BE2?style=for-the-badge&logo=githubpages&logoColor=white" alt="Portfolio ZehdBox">
</a>

</div>

---

## Sommaire

<details>
<summary>Afficher le sommaire</summary>

- [Sommaire](#sommaire)
- [À propos](#à-propos)
- [Règles du jeu](#règles-du-jeu)
- [Instructions autorisées](#instructions-autorisées)
- [Stack technique](#stack-technique)
- [Algorithme](#algorithme)
- [Installation](#installation)
  - [Prérequis](#prérequis)
  - [Compilation](#compilation)
- [Utilisation](#utilisation)
- [Structure du projet](#structure-du-projet)
- [Documentation](#documentation)
- [Contribuer](#contribuer)
- [Auteur](#auteur)
- [Remerciements](#remerciements)

</details>

---

## À propos

**Push-swap** est un projet d'algorithmique de l'école 42. Le programme reçoit une liste d'entiers en paramètre, la place dans une pile, puis affiche sur la sortie standard la suite d'instructions qui trie cette pile par ordre croissant.

Le nombre d'instructions produites détermine la qualité du résultat : l'objectif est donc de trouver un algorithme à la fois correct et économe. Le projet implémente un **tri radix** précédé de cas particuliers pour les petites listes, ce qui maintient le nombre d'opérations à un niveau constant jusqu'à 500 éléments.

| Ressource | Lien |
| --- | --- |
| *Fiche du projet (portfolio)* | [ZehdBox](https://lamizana.github.io/ZehdBox/projets/push_swap/) |
| *Spécifications* | [`docs/SPECIFICATIONS.md`](docs/SPECIFICATIONS.md) |

---

## Règles du jeu

Au départ, le jeu est constitué de deux piles :

- la pile **`a`**, remplie d'une quantité aléatoire d'entiers, positifs ou négatifs, sans doublon ;
- la pile **`b`**, vide.

L'objectif est de trier les entiers de la pile `a` par ordre croissant, le plus petit au sommet, en manipulant les deux piles avec les instructions autorisées.

Le programme doit gérer les cas d'erreur suivants en affichant `Error` suivi d'un `\n` sur la **sortie d'erreur**, puis en quittant :

- un paramètre qui n'est pas un nombre ;
- un nombre qui ne tient pas dans un `int` ;
- un doublon.

> [!NOTE]
> Le premier paramètre est au **sommet** de la pile `a`. Les instructions sont séparées par un `\n` et un programme qui trie correctement mais dépasse le seuil d'opérations est compté comme un échec.

---

## Instructions autorisées

| Instruction | Nom | Effet |
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

---

## Stack technique

| Catégorie | Technologie | Détail |
| --- | --- | --- |
| **Langage** | C | Aucune dépendance externe |
| **Structures de données** | Liste chaînée | `t_list { value, index, next }` |
| **Algorithme** | Tri radix (tri par bits) | Cas particuliers pour 3 et 5 éléments |
| **Compilation** | clang, `-Wall -Werror -Wextra` | Makefile fourni |
| **Contrainte** | Norme 42 | Pas de variable globale |

---

## Algorithme

Le programme choisit sa stratégie selon la taille de la pile `a` :

1. **Jusqu'à 3 éléments** : tri direct par cas particuliers (`sort_three`), en au plus 3 opérations.
2. **Jusqu'à 5 éléments** : les plus petits éléments sont envoyés dans la pile `b` pour ne garder que 3 éléments dans `a`, puis la pile `b` est reversée (`sort_five`).
3. **Plus de 5 éléments** : **tri radix** (`radix`). Les valeurs sont d'abord **normalisées** : chaque élément reçoit un index de `1` à `n` selon son rang. Le tri compare ensuite les bits de ces index, du bit de poids faible au bit de poids fort — pour chaque bit, les éléments dont le bit vaut `0` partent sur `b`, les autres tournent dans `a`, puis `b` est reversée dans `a`.

```console
        pile a (valeurs)                pile a (index normalisés)
        [ 42, 7, 900, -3 ]       →      [ 3, 2, 4, 1 ]

        bits de l'index, du LSB au MSB
        bit 0 : 0 → pb        bit 1 : 0 → pb        bit 2 : 0 → pb
                1 → ra                1 → ra                1 → ra
        puis pa jusqu'à vider b, à chaque tour

        résultat : pile a triée par ordre croissant
```

> [!NOTE]
> La normalisation est l'étape clé : elle ramène des valeurs quelconques (positives, négatives, jusqu'à `INT_MAX`) dans l'intervalle `[1, n]`, ce qui borne le nombre de bits à parcourir et rend le tri indépendant de l'amplitude des valeurs. Le radix a une complexité en O(n · log n) tours de pile, soit environ 1 100 opérations pour 100 éléments et 6 800 pour 500.

---

## Installation

### Prérequis

- [Clang](https://clang.llvm.org/) ou [GCC](https://gcc.gnu.org/)
- [Make](https://www.gnu.org/software/make/)

### Compilation

```bash
git clone https://github.com/Lamizana/Push-swap.git
cd Push-swap/push_swap
make
```

L'exécutable `push_swap` est généré dans le dossier `push_swap/`.

> [!NOTE]
> Le `Makefile` compile avec `-Wall -Wextra -Werror`. La compilation ne produit aucun avertissement, avec `clang` comme avec `gcc`.

---

## Utilisation

```bash
# Trier une liste de nombres : le programme affiche les instructions, une par ligne
./push_swap 1 5 2 4 3

# Sortie
pb
sa
pb
rra
pb
sa
pa
pa
pa
```

```bash
# Avec 3 éléments, une seule rotation suffit
./push_swap 3 1 2
# ra
```

Pour vérifier le résultat, le dépôt contient un `checker` qui rejoue les instructions et confirme si la pile est triée :

```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap $ARG | ./push_swap-testeur-max/checker_linux $ARG
# OK
```

Repères d'évaluation et résultats du radix actuel, moyenne sur 20 tirages :

| Taille | Note maximale | Seuil de validation | Résultat mesuré |
| --- | --- | --- | --- |
| **3 nombres** | — | — | 1 opération |
| **5 nombres** | — | — | 8 opérations |
| **100 nombres** | ≤ 700 opérations | ≤ 1 500 opérations | **1 081 opérations** |
| **500 nombres** | ≤ 5 500 opérations | ≤ 11 500 opérations | **6 778 opérations** |

> [!NOTE]
> À 100 et 500 nombres, le nombre d'opérations est identique quelle que soit la permutation d'entrée : le radix travaille sur les index normalisés, jamais sur les valeurs elles-mêmes. Le détail des algorithmes essayés avant celui-ci est dans [`docs/ALGORITHMES.md`](docs/ALGORITHMES.md).

> [!TIP]
> Le dossier [`push_swap/push_swap-testeur-max/`](push_swap/push_swap-testeur-max/) fournit un testeur qui fait la moyenne des coups, teste les cas d'erreur et vérifie les fuites mémoire (valgrind). Le dossier [`push_swap/visualizer-push-swap/`](push_swap/visualizer-push-swap/) contient un visualiseur graphique des piles `a` et `b` en GTK.

---

## Structure du projet

```console
Push-swap/
├── push_swap/                        # Code source principal
│   ├── main.c                        # Point d'entrée : parsing, tri, libération
│   ├── push_swap.h                   # Structure t_list et prototypes
│   ├── ft_init_stack.c               # Construction des piles
│   ├── ft_check.c                    # Validation des arguments
│   ├── ft_errors.c                   # Message d'erreur et sortie
│   ├── ft_split.c                    # Découpage d'une chaîne d'arguments
│   ├── ft_stacks.c                   # Utilitaires de listes chaînées
│   ├── ft_swap.c                     # sa, sb, ss
│   ├── ft_push.c                     # pa, pb
│   ├── ft_rotate.c                   # ra, rb, rr
│   ├── ft_reverse.c                  # rra, rrb, rrr
│   ├── ft_sort_three.c               # Cas 3 éléments
│   ├── ft_sort_five.c                # Cas 4 et 5 éléments
│   ├── ft_radix.c                    # Normalisation et tri radix
│   ├── ft_sorts.c                    # Vérification et comptage
│   ├── push_swap_utils.c             # ft_strlen, ft_atoi, ft_lstnew…
│   ├── Makefile                      # all, clean, fclean, re
│   ├── push_swap-testeur-max/        # Testeur (erreurs, moyenne, valgrind)
│   └── visualizer-push-swap/         # Visualiseur des piles (Vala / GTK)
├── utils/                            # Laboratoire d'algorithmes
│   ├── ft_algo.c / ft_algo_2.c       # Pistes par pivot, puis par index
│   ├── zehd_sort.c / _v2 / _v3       # Itérations de l'algorithme maison
│   └── list.c                        # Prototype de pile
├── docs/                             # Documentation du projet
│   ├── SPECIFICATIONS.md             # Interface et contrat d'utilisation
│   ├── ALGORITHMES.md                # Algorithmes essayés et performances
│   └── AVANCEMENT.md                 # Journal de développement
└── README.md
```

---

## Documentation

| Fichier | Descriptif |
| --- | --- |
| [`docs/SPECIFICATIONS.md`](docs/SPECIFICATIONS.md) | Interface du programme : invocation, contrat de sortie, erreurs, performances mesurées |
| [`docs/ALGORITHMES.md`](docs/ALGORITHMES.md) | Les sept algorithmes essayés, de `zehd_sort` au radix, et leurs performances |
| [`docs/AVANCEMENT.md`](docs/AVANCEMENT.md) | Journal de développement : plan d'origine, blocages rencontrés, reste à faire |
| [`push_swap/push_swap-testeur-max/README.md`](push_swap/push_swap-testeur-max/README.md) | Mode d'emploi du testeur (erreurs, moyenne, leaks) |
| [`push_swap/visualizer-push-swap/README.md`](push_swap/visualizer-push-swap/README.md) | Mode d'emploi du visualiseur |

---

## Contribuer

Projet pédagogique 42 : les corrections et les remarques sont bienvenues via une **issue** ou une **pull request**.

Les messages de commit suivent [Conventional Commits](https://www.conventionalcommits.org/fr/) :

```text
<type>(<scope>): <description>
```

| Type | Usage |
| --- | --- |
| `feat` | Nouvelle fonctionnalité |
| `fix` | Correction de bug |
| `docs` | Documentation seule |
| `refactor` | Réécriture sans changement de comportement |
| `chore` | Maintenance (configuration, fichiers annexes) |

**Scopes** : `parsing`, `stack`, `instructions`, `algo`, `readme`.

---

## Auteur

**Alex Lamizana**, étudiant à 42 Angoulême, spécialisation Data & IA

- [Site](https://lamizana.github.io/ZehdBox/)
- [GitHub](https://github.com/Lamizana)
- [Contact](https://lamizana.github.io/ZehdBox/contact/)

---

## Remerciements

- **42 Angoulême** : cadre pédagogique du projet.
- **hydrasho** (42 Angoulême) : auteur du [testeur push_swap](https://gitlab.com/hydrasho/push_swap-testeur-max) et du [visualiseur](https://gitlab.com/hydrasho/visualizer-push-swap) repris dans ce dépôt.

---

<div align="center">

*Ce projet a été réalisé conformément à la norme de 42.*

</div>
