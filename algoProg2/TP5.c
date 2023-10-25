
#include <stdio.h>
//----------------------------2.Matrices--------------------------


//----------1

void affiche(int matrice[][3], int size){
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size; ++j){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


// int main(){
//     int matrice[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
//     affiche(matrice, 3);
// }

//-------2


int nombreDeZeros(int matrice[][3], int size){
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

int estDiagonale(int matrice[][3], int size){
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


int estSymetrique(int matrice[][3], int size){
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size; ++j){
            if(matrice[i][j] != matrice[j][i]){
                return 0;
            }
        }
    }
    return 1;
}


// int main(){
//     int matrice[3][3] = {{1,4,7},
//                          {4,5,8},
//                          {7,8,9}};
//     affiche(matrice, 3);
//     printf("La matrice est elle symetrique : %d \n", estSymetrique(matrice, 3));
// }


//--------5

void transpose(int matrice[][3],int matrice2[][3], int size){
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size; ++j){
            matrice2[i][j] = matrice[j][i];
            matrice2[j][i] = matrice[i][j];
        }
    }
}


// int main(){
//     int matrice[3][3] = {{1,4,8},
//                          {5,5,8},
//                          {7,8,9}};
//     int matrice2[3][3] = {};
// 
//     affiche(matrice, 3);
//     
//     transpose(matrice,matrice2, 3);
// 
//     affiche(matrice2, 3);
// }


//--------6

void addition(int matrice[][3], int matrice2[][3], int size){
    for(int i = 0; i<size ; ++i){
        for(int j = 0; j<size; ++j){
            matrice[i][j] = matrice[i][j] + matrice2[i][j];
        }
    }
}

// int main(){
//     int matrice[3][3] = {{1,4,8},
//                          {5,5,8},
//                          {7,8,9}};
//     int matrice2[3][3] = {{1,4,8},
//                           {5,5,8},
//                           {7,8,9}};
// 
// 
//     addition(matrice, matrice2, 3);
//     affiche(matrice, 3);
// }


//---------7


void multiplication(int matrice[][3], int matrice2[][3], int size){
    for(int i = 0; i<size; ++i){
        for(int j = 0; j<size; ++j){
            matrice[i][j] = matrice[i][j] * matrice2[i][j];
        }
    }
}


