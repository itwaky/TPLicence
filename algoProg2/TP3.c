#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// void toursHanoi(int n, char D, char A, char I) {
//     if (n == 1)
//       printf("Disque 1 de %c a %c \n" , D , A);
//     else {
//       // D à A
//       toursHanoi(n - 1, D, I, A);
//       printf("Disque %d de %c a %c \n", n , D ,A);
//       //I à A
//       toursHanoi(n - 1, I, A, D);
//     }
// }

//-------------------------exercice1---------------------

/*




int hasard(int min, int max){
    return (int) (min + ((float) rand() / RAND_MAX * (max - min + 1)));
}



int main(){
    srand(time(NULL));
    int nbEssaie = 1;
    int entreUtil = 0;
    int nb = hasard(1,100);
    printf("Devinez le nombre entre 1 et 100 : ");
    while (nb != entreUtil)
    {
        scanf("%d", &entreUtil);
        if(entreUtil<1 || entreUtil>100){
            printf("Entree invalide veuillez l'entre a nouveau : ");
            continue;
        }else{
            if(entreUtil == nb){
                printf("Bravo le nombre etait bien %d ! Vous avez mis %d essaie.\n", nb, nbEssaie);
                continue;
            }else{
                if(entreUtil<nb){
                    printf("Plus grand : ");
                }else{
                    printf("Plus petit : ");
                }
            }
        }
        nbEssaie++;
    }
    
    return 0;
}

*/

//-------------------------exercice2---------------------------------


/*

int hasard(int min, int max){
    return (int) (min + ((float) rand() / RAND_MAX * (max - min + 1)));
}

void afficheBarre(int r){
    for (int i = 0; i<r;i++){
        printf(" | ");
    }
    printf("\n");
}


int retireBarre(int r){
    int choix = 0;
    printf("Entrez le nombres d'allumettes que vous souhaitez enlevez : ");
    scanf("%d", &choix);
    return r - choix;
}

int joueurVirtuel(int r){
    srand(time(NULL));
    int choix = hasard(1,r);
    return r - choix;
}


int main(){
    int barres = 10;
    int joueur = 1;
    while (barres != 0)
    {
        afficheBarre(barres);
        if (joueur % 2 == 0){
            barres = joueurVirtuel(barres);
        }else{
            barres = retireBarre(barres);
        }
        joueur++;
    }
    if (joueur % 2 != 0){
        printf("Vous avez perdu.\n");
    }else{
        printf("Vous avez gagner.\n");
    }
    
}
*/

//------------------exercice3-------------------------



// int factoriel(int n){
//     if (n == 0 || n == 1){
//         return 1;
//     }else{
//         return factoriel(n-1) * n;
//     }
// }
// 
// float neper(float eps){
//     float s = 0.f;
//     float t = 0.f;
//     int k = 0;
// 
//     do{
//         t = 1.0/factoriel(k);
//         s+=t;
//         k++;
//     }
//     while (t>eps/3);
// 
//     return s;
//     
// }
// int main(){
//     float e = 0.00001;
//     printf("e= %.12f a %.12f pres \n", neper(e), e);
// }



//------------------------exercice4--------------------



void hanoi(int n, int depart, int inter, int arrive ){
    if (n == 1){
        printf("Deplacer de la tour %d a la tour %d\n", depart,arrive);
    }else{
        hanoi(n-1, depart, arrive,inter);
        printf("Deplacer de la tour %d a la tour %d\n", depart, arrive);
        hanoi(n-1,inter,depart,arrive);
    }
}




int main(){
    hanoi(3, 1, 2, 3);
}
