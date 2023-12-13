#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Return a "random" int number 0 or 1
int hasard()
{
    return rand() % 2;
}




// -----------------------------1.1


int** allocate_grille (int taille){
    int** h = (int**) malloc(sizeof(int*)*taille);
    if (h == NULL) exit(-1);
    for(int i = 0; i<taille; i++){
        h[i] = (int*) malloc(sizeof(int)*taille);
        if(h[i] == NULL) exit (-1);
    }
    return h;
}


// ------------------------------1.2

void liberer_grille(int** grille,int taille){
    for(int i = 0; i<taille; i++){
        free(grille[i]);
    }
    free(grille);
}



// -------------------------------1.3

void init_grille(int** grille, int size){
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size;j++){
            grille[i][j] = hasard();
        }
    }
}


// ----------------------------1.4 et 1.8


void print_grille(int** grille, int size){
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size;j++){
            if(grille[i][j] == 1){
                printf("\033[1;42m   ");
            }else{
                printf("\033[0;30m   ");
            }
            printf("\x1b[0m");
        }
        printf("\n");
    }
}



// ----------------------------1.5



void densite(int** grille, int** densite, int taille){
    for(int i = 1; i<taille-1; i++){
        for(int j = 1; j<taille-1; j++){
            int total = 0;
            total = grille[i-1][j-1] + grille[i-1][j]+ grille[i-1][j+1]+ grille[i][j-1] + grille[i][j+1] + grille[i+1][j-1]+grille[i+1][j]+grille[i+1][j+1];
            densite[i][j] = total;
            // printf("%d", densite[i][j]);

        }
    }
}


// ------------------------------1.6


void evolution(int** grille, int taille){
    int** tabDensite = allocate_grille(taille);
    densite(grille, tabDensite, taille);
    for(int i = 0; i<taille;i++){
        for(int j = 0; j<taille; j++){
            if(grille[i][j] == 1){
                if(tabDensite[i][j] == 2 || tabDensite[i][j] == 3){
                    grille[i][j] = 1;
                }else if(tabDensite[i][j]>3 && tabDensite[i][j]<9){
                    grille[i][j] = 0;
                }else if(tabDensite[i][j]<2){
                    grille[i][j] = 0;
                }
            }else{
                if(tabDensite[i][j] == 3){
                    grille[i][j] = 1;
                }
            }
        }
    }
    liberer_grille(tabDensite,taille);
}




int main ()
{

    // DO NOT TOUCH : init seed for random number generation with rand()
    srand(time(NULL));
    
    // ...

    // for() simulation iterations
        printf("\033[H\033[J"); // clear terminal screen before printing the grid
        // ...
        usleep(50000); // slow the simulation at the end of each iteration

    
    // ---------------------1.7

    int taille = 0;
    int nbTour = 0;
    printf("entrez la taille de la grille : ");
    scanf("%d", &taille);
    printf("entrez le nombre de tour : ");
    scanf("%d", &nbTour);
    int** grille = allocate_grille(taille);
    init_grille(grille, taille);

    while(nbTour >= 0){
        printf("\033[H\033[J");
        print_grille(grille, taille);
        evolution(grille, taille);
        nbTour--;
        usleep(500000);
    }




    // print_grille(grille, 10);





    liberer_grille(grille, taille);


    return 0;
}

