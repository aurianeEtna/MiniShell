#include <stdio.h>

// Consigne : Ecrire un programme qui lit au clavier les valeurs de trois résistances et de trois capacités et
// calcule leur résistance et leur capacité équivalente

double serie_resistance(double R1, double R2, double R3);
double serie_capacite(double C1, double C2, double C3);
double parallele_resistance(double R1, double R2, double R3);
double parallele_capacité(double C1, double C2, double C3);

int main(){
    double R1, R2, R3;
    double C1, C2, C3;

    printf("Entrez la valeur de trois résistances et de leurs capacités");
    scanf("%lf %lf %lf %lf %lf %lf", &R1, &R2, &R3, &C1, &C2, &C3);
    printf("R1 = %lf\n", R1);
    printf("R2 = %lf\n", R2);
    printf("R3 = %lf\n", R3);

    double R_serie = serie_resistance(R1, R2, R3);
    double C_serie = serie_capacite(C1, C2, C3);
    double R_parallele = parallele_resistance(R1, R2, R3);
    double C_parallele = parallele_capacité(C1, C2, C3);

    printf("Résistance équivalente en série : %.2lf\n", R_serie);
    printf("Résistance équivalente paralèle : %.2lf\n", R_parallele);
    printf("Capacité équivalente en série : %.2e F\n", C_serie);
    printf("Capacité équivalente parallèle : %.2e F\n", C_parallele);


    return 0;
}

// RESISTANCES
double serie_resistance(double R1, double R2, double R3){
    return R1 + R2 + R3;
}

double parallele_resistance(double R1, double R2, double R3){
    return 1.0/ (1.0/R1 + 1.0/R2 + 1.0/R3);
}

// CAPACITE

double serie_capacite(double C1, double C2, double C3){
    double result = 1.0/ (1.0/C1 + 1.0/C2 + 1.0/C3);
    return result;
}

double parallele_capacité(double C1, double C2, double C3){
    return C1 + C2 + C3;
}
