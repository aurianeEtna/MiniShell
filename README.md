## Objectif : coder un minishell en C

## Le projet
## Le shell
l'interface entre l'utilisateur et le noyau, qui permet à l'utilisateur de communiquer avec le système d’exploitation par l'intermédiaire d'un langage de commandes. L'utilisateur peut entrer des commandes dans le terminal. Grâce à l’interpréteur de ligne de commande (tel que bash ou zsh qui sont des shells), les commandes entrées sont exécutées. --> On va créer notre propre petit shell.

## Un process :
A process is an instance of executing a program that has a unique ID. It is basically a programm in execution. 

## Le PID :
Quand le noyau crée un processus, il lui attribue un numéro d’identification unique, sous forme d’un entier positif. Ce numéro, le PID (Process ID) identifie l’entrée du processus dans la table des processus gérée par le noyau. Il est garanti unique.

L’une des caractéristiques des systèmes de type Unix est qu’un processus est toujours créé à la demande d’un autre processus, son processus parent (parent process). Ce dernier, directement ou indirectement, provoque la création d’un processus enfant (child process) par l’appel système fork(), que nous étudierons dans la suite du chapitre.

## D'où l'utililité de fork ():
L’appel système permettant de demander la création d’un processus est fork().  Ses principales phases sont les suivantes : Le processus exécute la fonction enveloppe fork(), qui n’attend aucun argument, et attend le retour de l’appel.

Le noyau duplique le processus pour créer un nouveau processus. Le processus enfant est presque identique au processus parent.
Son identifiant (PID), forcément différent puisque les identifiants de processus sont uniques.

 Identifiants de processus : getpid(), getppid()

Un processus peut connaître son identifiant de processus et celui de son processus parent par les appels système getpid() et getppid().

## Syntaxe
#include <unistd.h> 
pid_t getpid(void); 
pid_t getppid(void); 

## Plan d'attaque
Identifier les etapes clés: 
- D'abord : recueillir la commande de l'utilisateur 
- Ensuite : l'exécuter
Pour cela on va énormément utiliser execve(). Il faut par contre découper la chaine de charactère comme il se doit pour pouvoir la passer à execve. Là réside la difficulté du projet.

## Dificultés rencontrées :
1. Non gestion des commandes simples
Au depart, je me rends compte qu'il y a des commandes pour lesquelles ça fonctionne et d'autres pour lesquelles ça ne fonctionne pas. 
Exemple : 
- afficher la date ou un ls basique, ça marche. 
- faire un pwd, idem. 
- un simple exit fonctionne exactement. 

Donc, à ce stade on exécute un certain nombre de commande afin de tester la validité de notre programme. Mais, pour des commandes plus complexes, dont la taille est supérieure à 1, comme ls -a, un simple exec de l'input n'est pas suffisant. Et d'ailleurs, la commande ne s'exécute pas. Le problème, c'est qu'à ce stade le code ne fonctionnait pas pour des commandes complexes, comme ls -l. En fait, je me suis rendu compte que le shell ne gérait que des commandes simples sans arguments. Par exemple, si je voulais exécuter un ls -l, ça échouait. Pour corriger cela : 
1/ Il fallait donc découper l’entrée utilisateur en une commande et ses arguments. L'une des façons de faire était d'utiliser strtok pour diviser la chaîne en fonction des espaces.

2. Oubli de l'import des bonnes librairies
Oubli de l'ajout des bonnes librairies -> par exemple, pour la fonction exit(0), il fallait ajouter la librairie #include <stdlib.h>


## Etapes
1. Manipulation des tokens
Pour chaques lignes de commandes envoyée à votre programme, plein de choses seront faites mais la plus importante des choses à faire est de se créer une liste chainée de token pour chaques éléments de la ligne de commande.

2. Comprendre le principe du PID
Quand le noyau crée un processus, il lui attribue un numéro d’identification unique, sous forme d’un entier positif. Ce numéro, le PID (Process ID) identifie l’entrée du processus dans la table des processus gérée par le noyau. Il est garanti unique.

