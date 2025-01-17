#include <stdio.h>
#include <string.h>
#include <ctype.h> 

    struct Planete {
        char name[20];
        int gravité;
        int température;
        int masse;
        double distance;
        char composition[25];
    };


 struct Planete planetes[4] = {
        {"Mars", 38, -65, 1000, 89.0, "CO2, oxygène, azote"},
        {"Mercure", 38, 167, 3300, 57.9, "CO2, sodium, oxygène"},
        {"Vénus", 90, 462, 5000, 108.2, "CO2, azote"},
        {"Pluton", 0, -223, 1300, 5913.0, "mélange de gaz glacés"}
    };

void toLowerCase(char* str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main(){
    char userInput[256];
    printf("Bonjour. Quelle planète du système solaire vous intéresse ?");
    fgets(userInput, sizeof(userInput), stdin);
    for(int i=0 ; i<256; i++){
        if(userInput[i] == '\n'){
            userInput[i] = '\0';
            break;
        }
    }
    toLowerCase(userInput);

    printf("\n");
    for(int i=0; i < 4; i++){
        char lowerPlanetName[20];
        strcpy(lowerPlanetName, planetes[i].name);  // Copie du nom de la planète
        toLowerCase(lowerPlanetName); 

        if(strstr(userInput, lowerPlanetName) != NULL){

                if (strstr(userInput, "gravité") != NULL) {  // Vérifie si "gravité" est mentionné
                printf("Sur %s, la gravité est de %d.\n", planetes[i].name, planetes[i].gravité);
                }
                if (strstr(userInput, "température") != NULL) {   
                printf("Sur %s, la température est de %d degrés Celsius.\n", planetes[i].name, planetes[i].température);
                } 
            } 
            printf("Vous avez mentionné %s, mais aucune information spécifique demandée.\n", planetes[i].name);
            }
          return 0;       
}


//printf("La planète %s a une masse de %d kg. Elle se situe à %f km de la terre. Sa composition est %s. Sur %s la gravité est de %d. La température est de %d degrés Celcius. \n", planetes[i].name, planetes[i].masse, planetes[i].distance, planetes[i].composition, planetes[i].name, planetes[i].gravité, planetes[i].température);