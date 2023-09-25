//-------------------------exercice1---------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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



//-------------------------exercice2---------------------------------