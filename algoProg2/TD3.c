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


//------------------------------------exercice18-------------------------


//---------1

int nombreDeZero(int matrice[], int sizey , int sizex){
    int total = 0;
    for(int i = 0; i<sizey; i++){
        for(int j = 0; j<sizex; j++){
            if(matrice[i][j] == 0){
                total++;
            }
        }
    }
    return total;
}


//---------2

int estDiagonale(int matrice[], int sizey, int sizex){
    int nb = matrice[0][0];
    for(int i = 0; i<sizey; ++i){
        for(int j = 0; j<sizex; ++j){
            if(i == j){
                if(matrice[i][j] != nb){
                    return 0;
                }
            }
        }
    }
    return 1;
}


//--------3


int estSymetrique(int matrice[], int sizey, int sizex){
    for(int i = 0; i<sizey; ++i){
        for(int j = 0; j<sizex; ++j){
            if(matrice[i][j] != matrice[j][i]){
                return 0;
            }
        }
    }
    return 1;
}


//---------4

void transpose(int matrice[], int sizey, int sizex){
    int temp = 0;
    for(int i = 0; i<sizey; ++i){
        for(int j = 0; j<sizex; ++j){
            temp = matrice[i][j];
            matrice[i][j] = matrice[j][i];
            matrice[j][i] = temp;
        }
    }
}


//-----------5

void addition(int matrice1[], int matrice2[], int sizey, int sizex){
    for(int i = 0; i<sizey; ++i){
        for(int j = 0; j<sizex; ++j){
            matrice1[i][j] += matrice2[i][j];
        }
    }
}

//----------6

void multiplication(int matrice1[], int matrice2[], int sizey, int sizex){
    for(int i = 0; i<sizey; ++i){
        for(int j = 0; j<sizex; ++j){
            matrice1[i][j] *= matrice2[i][j];
        }
    }
}


//-------------------------------exercice19-----------------------------


