#include <stdio.h>
#include <math.h>

/*
float perimetre(float cote){
    return cote * 4;
}

float diagonale(float cote){
    return sqrt(2) * cote;
}



int main(){
    float cote = 0;
    printf("Entrez la valeur d'un coté d'un carré : ");
    scanf("%f", &cote);
    printf("Le périmètre du carré est de : %f et sa diagonale est de : %f\n", perimetre(cote), diagonale(cote));

}

*/

//----------------exercice2-------------


void afficheMois (int nb){
    switch (nb)
    {
    case 1:
        printf("%d", 31);
        break;
    case 2:
        printf("%d", 28);
        break;
    case 3:
        printf("%d", 31);
        break;
    case 4:
        printf("%d", 30);
        break;
    case 5:
        printf("%d", 31);
        break;
    case 6:
        printf("%d", 30);
        break;
    case 7:
        printf("%d", 31);
        break;
    case 8:
        printf("%d", 31);
        break;
    case 9:
        printf("%d", 30);
        break;
    case 10:
        printf("%d", 31);
        break;
    case 11:
        printf("%d", 30);
        break;
    case 12:
        printf("%d", 31);
        break;
    default:
        printf("Ce nombre ne correspond a aucuns mois.");
        break;
    }
}


int main(){
    int mois = 0;
    printf("Entrez le numero du mois : ");
    scanf("%d", &mois);
    afficheMois(mois);
    printf(" jours \n");

}