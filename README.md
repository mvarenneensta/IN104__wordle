# IN104__wordle
Dans ce projet, notre objectif principal est de recréer Wordle, un jeu devenu très populaire ces derniers mois 

Régles du jeu :

- Vous avez 6 essais pour deviner un mot aléatoirement choisi dans le dictionnaires.

- Des indices sont donnés à chaque tour, avec la signification suivante pour chaque lettre :

    O -> bien placé

    X -> mal placé et pas dans le mot

    ~ -> dans le mot et mal placé
    
- Il est nécessaire d'écrire les mots en majuscules.

Nous avons également programmé un résolveur du jeu, donnant le meilleur mot à jouer pour chaque tour. 

Il y a aussi des fonctionnalités supplémentaires : le choix du nombre de lettres ainsi qu'un un mode difficile.
Vous pouvez choisir d'utiliser ces deux fonctionnalités au début du jeu.
Le résolveur ne pourra pas être utilisé en mode difficile.


## Commencer avec notre jeu

Ce paragraphe vous permet d'avoir une copie du projet et de l'exécuter en local sur votre machine afin de le tester.


### Installation du projet

Il vous faut déja faire une copie du projet. Placez vous dans votre terminal et écrivez la commande suivante : 

```
git clone git@github.com:mvarenneensta/IN104__wordle.git
```

### Instructions de compilation
Cette commande vous permettra d'éxécuter le projet :
```
gcc jeu.c actualise_dico.c meilleur_mot.c chargerdico.c tentative_valide.c afficher_indice.c -lm
```
## Auteurs

* **Arthur Paradis** 
* **Matthieu Varenne** 
