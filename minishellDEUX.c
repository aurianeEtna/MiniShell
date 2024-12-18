#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h> // Pour wait()

int main(void){

// Boucle infinie 
    while(1){
        // 1. Récupérer la commande de l'utilisateur
    char input[251];
    printf("Minishell > ");
    fgets(input, 250, stdin);
    input[strlen(input) -1]='\0';

    // 2. Découper l'entrée de l'utilisateur en tokens 
    // En fait, ICI, args contient la commande et ses arguments, comme {"ls", "-l", NULL}.

    char *args[10];
    char *command;
    int arg_count = 0;

    char *token = strtok(input, " ");
    while(token != NULL){
        args[arg_count ++]=token;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL; // Le tableau doit se terminer par NULL pour `execvp`

    if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "quit") == 0){
            printf("Exiting shell...\n");
            break; // Quitte la boucle infinie
        }
        
    // 3. Créer un processus enfant pour exécuter la commande
    
    pid_t pid = fork();
    if (pid == -1) {
            perror("fork failed");
        }
    if (pid == 0) {
            // Processus enfant : exécuter la commande
            execvp(args[0], args);
            // Si execvp échoue, afficher une erreur
            perror("execvp failed");
            exit(1);
    } else {
            // Processus parent : attendre la fin du processus enfant
            wait(NULL);
    }
    }
}
