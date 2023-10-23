
#include <stdio.h>
//----------------------------2.Matrices--------------------------


//----------1

void affiche(int matrice[3][3], int size){
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size; ++j){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(){
    int matrice[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    affiche(matrice, 3);
}

//-------2


int nombreDeZeros(int matrice[3][3], int size){
    int total = 0;
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size; ++j){
            if(matrice[i][j] == 0){
                total++;
            }
        }
    }
    return total;
}


//-----3

int estDiagonale(int matrice[3][3], int size){
    int diag = matrice[0][0];
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size; ++j){
            if(matrice[i][j] != diag){
                return 0;
            }
        }
    }
    return 1;
}


//------4

