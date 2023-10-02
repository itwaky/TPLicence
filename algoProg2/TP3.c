#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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
    
}