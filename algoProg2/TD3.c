#include <stdio.h>
#include <stdbool.h>

//------------------------------------exercice1--------------------------------

void initTab(float tab[], int size){
    for (int i = 0; i<size;++i){
        tab[i] = 0.f;
    }
}


//--------------------------exercice2----------------------------------


void entreTab(float tab[], int size){
    for (int i = 0; i<size; ++i){
        printf("Entrez la valleur tab[%d] : ", i);
        scanf("%f", &tab[i]);
    }
}


//---------------------------exercice3----------------------------


void copieTab(char tab[], char tabCopie[], int size){
    for (int i = 0;i<size;++i){
        tabCopie[i] = tab[i];
    }
}


//-------------------------------exercice4--------------------------


int maximum(int tab[], int size){
    int max = tab[0];
    for(int i = 1;i<size;++i){
        if (tab[i] > max){
            max = tab[i];
        }
    }
    return max;
}

int indiceMax(int tab[], int size){
    int max = tab[0];
    int indiceMax = 0;
    for (int i = 1;i<size;++i){
        if (tab[i]>max){
            max = tab[i];
            indiceMax = i;
        }
    }
    return indiceMax;
}


//---------------------------exercice5----------------------------


void permutation(int tab[], int size){
    int last = tab[size-1];
    for(int i = size-1;i>0;--i){
        tab[i]=tab[i-1];
        tab[0]=last;
    }
}


void permutationN(int tab[], int size, int n){
    for (int i = 0;i<n;++i){
        permutation(tab,size);
    }
}


// int main(){
//     int tab[6] = {2,23,28,12, 16, 27};
//     for (int i = 0;i<6;++i){
//         printf("%d ", tab[i]);
//     }
//     printf("\n");
//     permutation(tab, 6);
//     for (int i = 0;i<6;++i){
//         printf("%d ", tab[i]);
//     }
//     printf("\n");
// }
//--------------------exercic6-----------------------------



//+32 

void Maj(char str[]){
    printf("Entrez une chaine : ");
    scanf("%s", str);
    int i = 0;
    while (str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'i'){
            str[i] = str[i - ('a' - 'A')];
        }
        i++;
    }
    
}




//----------------------------------exercice7-------------------------------


int rechercheChar(const char str[], char character){
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == character){
            return 1;
        }
        i++;
    }
    return 0;
    
}

int rechercheMot(const char str[], const char mot[]){
    int i = 0;
    while (mot[i] != '\0')
    {
        if (!rechercheChar(str, mot[i])){
            return 0;
        }
        i++;
    }
    return 1;
    
}


void supprimeVoy(char str[]){
    int p = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if(str[i] != 'a' || str[i] != 'e' || str[i] != 'i' || str[i] != 'o' || str[i] != 'u' || str[i] != 'y'){
            str[p] == str[i];
            p++;
        }
        i++;
    }
    str[p] = '\0';
    
}



//------------------------exercice8--------------------------------



void mirroir(int tab[],int size){
    int temp = 0;
    for(int i = 0; i< size / 2; i++){
        temp = tab[i];
        tab[i] = tab[size - i -1];
        tab[size - i - 1] = temp;

    }
}


// int main(){
//     int tab[5] = {1,2,3,4,5};
//     mirroir(tab, 5);
//     for (int i = 0; i<5; ++i){
//         printf("%d\t", tab[i]);
//     }
//     printf("\n");
// }



//------------------------------exercice9-----------------------------------


int estPalindrome(char tab[]){
    int size = 0;
    int i = 0;
    while (tab[size] != '\0')
    {
        size++;
    }
    
    while (tab[i] != '\0')
    {
        if (tab[i] != tab[size - i - 1]){
            return 0;
        }
        i++;
    }
    return 1;
    
}


// int main(){
//     char str[] = "raar";
//     printf("%d\n", estPalindrome(str));
// }


//--------------------------------exercice10------------------------------


int estEgaux(const int tab1[], const int tab2[], int size){
    for(int i = 0; i<size; ++i){
        if (tab1[i] != tab2[i]){
            return 0;
        }
    }
    return 1;
}


// int main(){
//     int tab1[5] = {1,2,3,4,5};
//     int tab2[5] = {1,2,3,5,5};
//     printf("%d\n", estEgaux(tab1, tab2, 5));
// }



//--------------------------------exercice11-----------------------------


int rechercheIndice(const int tab[], int size, int elem){
    for(int i = 0; i<size; ++i){
        if (tab[i] == elem){
            return i;
        }
    }
    return -1;
}


//--------------------------------exercice12---------------------------


int occurence(const int tab[], int size, int elem){
    int nb = 0;
    for(int i = 0; i<size; ++i){
        if(tab[i] == elem){
            nb++;
        }
    }
    return nb;
}


//-------------------------------exercice13-----------------------------

//--------------------------Exercice15----------------------------------

int dichotomie(int t[], int taille, int x){
    if (t[taille] == x){
        return 1;
    }else if (taille == 0){
        return 0;
    }else if (t[taille / 2] > x){
        printf("Inferieur : %d\n", taille/2);
        return dichotomie(t, taille/2, x);
    }else{
        printf("Superieur : %d\n", (taille + taille/2)/2);
        return dichotomie(t, (taille + taille/2)/2, x);
    }
}


// int main(){
//     int t[5] = {1,3,4,5,6};
//     int nb = 4;
//     printf("Entier %d est dans le tableau T ? : %d\n", nb, dichotomie(t, 4, nb));
// }



//---------------------------exercice16--------------------------


// typedef struct fraction
// {
//     int denominateur;
//     int numerateur;
// 
// }Fraction;
// 
// Fraction simplifie(Fraction frac){
//     frac.denominateur = frac.denominateur / pgcd(frac.denominateur, frac.numerateur);
//     frac.numerateur = frac.numerateur / pgcd(frac.denominateur, frac.numerateur);
//     return frac;
// }
// 
// 
// 
// int main(){
//     Fracttion a = {12,6};
//     a = simplifie(a);
// }
// 
// 
// 
// Fraction multiFrac(Fraction frac1, Fraction frac2){
//     frac1.denominateur *= frac2.denominateur;
//     frac1.numerateur *= frac2.numerateur;
//     frac1 = simplifie(f);
//     return frac1;
// }








//----------------------------exercice17----------------------


typedef struct Polynome
{
    float coeff[10];
    int degre;
}Polynome;


Polynome derivePoly(Polynome f){
    if(f.degre == 0){
        return f;
    }
    for (int i = 0; i<f.degre; i++){
        f.coeff[i] *= f.degre - i;
    }
    f.degre--;
    return f;
}


void PrintPoly(Polynome f){
    printf("f(x) = ");
    for(int i = 0; i<f.degre; ++i){
        printf("%f x^%d + ",f.coeff[i], f.degre - i);
        // if(i+1 == f.degre){
        //     printf("%f", f.coeff[i+1]);
        // }
    }
    printf("%f", f.coeff[f.degre]);
    printf("\n");
}


Polynome saisiePoly(){
    Polynome f;
    printf("degres : ");
    scanf("%d", &f.degre);
    char c = 'a';
    for(int i = 0; i <= f.degre; ++i){
        printf("%c : ", c++);
        scanf("%f", &f.coeff[i]);
    }
    return f;

}

// int main(){
//     Polynome p = saisiePoly();
// 
//     PrintPoly(p);
// 
//     p = derivePoly(p);
// 
//     PrintPoly(p);
// 
//     return 0;
// }


//------------------------------------exercice18-------------------------


#define N 3
typedef int Matrice[N][N];

//---------1

int nombreDeZero(const Matrice matrice){
    int total = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(matrice[i][j] == 0){
                total++;
            }
        }
    }
    return total;
}


//---------2

int estDiagonale(const Matrice matrice){
    for(int i = 0; i<N; ++i){
        for(int j = 0; j<N; ++j){
            if(i == j){
                if(i != j && matrice[i][j] != 0){
                    return 0;
                }
            }
        }
    }
    return 1;
}


//--------3


int estSymetrique(const Matrice matrice){
    for(int i = 0; i<N; ++i){
        for(int j = 0; j<N; ++j){
            if(matrice[i][j] != matrice[j][i]){
                return 0;
            }
        }
    }
    return 1;
}


//---------4

// void transpose(Matrice matrice,Matrice matrice2){
//     for(int i = 0; i<N; ++i){
//         for(int j = 0; j<N; ++j){
//             matrice2[i][j] = matrice[j][i];
//             matrice2[j][i] = matrice[i][j];
//         }
//     }
// }


void transpose(Matrice matrice){
    for(int i = 0; i<N; ++i){
        for(int j = 0; j<i; ++j){
            int temp = matrice[i][j];
            matrice[i][j] = matrice[j][i];
            matrice[j][i] = temp;
        }
    }
}

//-----------5

void addition(Matrice matrice1, Matrice matrice2){
    for(int i = 0; i<N; ++i){
        for(int j = 0; j<N; ++j){
            matrice1[i][j] += matrice2[i][j];
        }
    }
}

//----------6

// void multiplication(Matrice matrice1, Matrice matrice2){
//     Matrice temp = {{0}};// chiant a innitialiser donc marche pas;
//     for(int i = 0; i<N; ++i){
//         for(int j = 0; j<N; ++j){
//             int total = 0;
//             for(int k = 0; k<N; ++k){
//                 total += matrice1[i][k] * matrice2[k][j];
//             }
//             temp[i][j] = total;
//         }
//     }
//     for(int i = 0 ; i<N ; ++i){
//         for(int j = 0; j<N; ++j){
//             matrice1[i][j] = temp[i][j];
//         }
//     }
// }


//-------------------------------exercice19-----------------------------

#define M 3

int rechercheTab(int tab[], int size, int elem){
    for(int i = 0; i<size; ++i){
        if(tab[i] == elem){
            return 0;
        }
    }
    return 1;
}

void afficheMat3(const int matrice[M][M]){
    for(int i = 0; i<M; ++i){
        printf("\n");
        for(int j = 0; j<M; ++j){
            printf("%d ", matrice[i][j]);
        }
    }
    printf("\n");
}

// for(int i = 0 ; i<M ; ++i){
//     int premierLigne = matrice[i][0];
//     int premierCol = matrice[0][i];
//     for(int j = 1 ; j<M ; ++j){
//         if (premierLigne == matrice[i][j]){
//             return 0;
//         }
//         if (premierCol == matrice[j][i]){
//             return 0;
//         }
//     }
// }


int sudoku(const int matrice[M][M]){
    for(int i = 0 ; i<M ; ++i){
        int premierLigne = matrice[i][0];
        int premierCol = matrice[0][i];
        for(int j = 1 ; j<M ; ++j){
            if (premierLigne == matrice[i][j]){
                return 0;
            }
            if (premierCol == matrice[j][i]){
                return 0;
            }
        }
    }
    return 1;
}



#define Z 9
typedef int Matrice9[Z][Z];

int sudoku9(const int matrice[Z][Z]){
    int copieMat[3][3] = {{0},{0},{0}};
    afficheMat3(copieMat);
    for(int i = 2; i<=Z; i+=3){
        for(int j = 2; j<=Z; j+=3){
            printf("i = %d, j = %d \n", i, j);
            int finK = i + 3;
            int finL = j + 3; 
            for (int k = i; k<=finK; k++){
                for(int l = j; l<=finL; j++){
                    copieMat[k][l] = matrice[k][l];
                }
            }
            afficheMat3(copieMat);
            if(sudoku(copieMat)){
                return 0;
            }
        }
    }
    return 1;
}





int main(){
    Matrice9 matriceValide = {{2,8,9,2,8,9,2,8,9},
                              {7,3,5,7,3,5,7,3,5},
                              {1,6,4,1,6,4,1,6,4},
                              {2,8,9,2,8,9,2,8,9},
                              {7,3,5,7,3,5,7,3,5},
                              {1,6,4,1,6,4,1,6,4},
                              {2,8,9,2,8,9,2,8,9},
                              {7,3,5,7,3,5,7,3,5},
                              {1,6,4,1,6,4,1,6,4}};
    
    Matrice matrice = {{1,4,8},
                       {5,5,8},
                       {7,8,9}};
    
    // printf("Matrice valide : %d \n", sudoku(matriceValide));

    printf("Matrice invalide : %d \n", sudoku9(matriceValide));
}