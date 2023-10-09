#include <stdio.h>


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


int main(){
    int tab[6] = {2,23,28,12, 16, 27};
    for (int i = 0;i<6;++i){
        printf("%d ", tab[i]);
    }
    printf("\n");
    permutation(tab, 6);
    for (int i = 0;i<6;++i){
        printf("%d ", tab[i]);
    }
    printf("\n");
}
//--------------------exercic8-----------------------------



