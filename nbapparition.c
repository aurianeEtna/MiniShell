#include <stdio.h>

// Consigne : si tu as une liste de nombres et que tu dois trouver le nombre qui apparaît un nombre impair de fois, 
// comment fais-tu ?

int main(){
    int liste[12] = {2, 4, 2, 3, 2, 1, 8, 7, 7, 7, 3, 1};
    int nb_apparition[12] = {0};

for(int j=0; j<12; j++){
    for (int i = 0; i < 12; i++){
        printf("liste de liste[%d] = %d | liste de liste[i] = %d\n", j, liste[j], liste[i]);
        if (liste[j] == liste[i]){
            printf("liste[%d]%d = %d. et i = %d. DONC ajout de son numéro dans la liste d'apparition. \n ", j, liste[j], liste[i], i);
            nb_apparition[liste[i]+1]++;
        }
    }

}
   
    for(int i=0; i<12; i++){
        printf("nb_apparition[i] = %d\n", nb_apparition[i]);
    }
    return 0;
}

   
