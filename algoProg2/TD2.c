#include <stdio.h>

//----------------exercice5--------------------------





int somme1(int n){
    if (n == 0){
        return 0;
    }else{
        return somme1(n-1) + n;
    }
}

int sommeCarres(int n){
    if (n == 0){
        return 0;
    }else{
        return sommeCarres(n-1) + n * n;
    }
}


int sommeImpaire(int n){
    if (n == 0){
        return 0;
    }else if (n % 2 != 0){
        return sommeImpaire(n-1) + n;
    }else{
        return sommeImpaire(n-1);
    }
}

int sommePaire(int n){
    if (n == 0){
        return 0;
    }else if (n % 2 == 0){
        return sommePaire(n-1) + n;
    }else{
        return sommePaire(n-1);
    }
}

float sommeDiv(int n){
    if (n == 0){
        return 0;
    }else{
        sommeDiv(n-1) + 1/n;
    }
}


//-------------------exercice6----------------------


int somme2recusif(int n){
    if (n == 0){
        return 0;
    }else{
        return somme2recusif(n-1) + somme1(n);
    }
}


//---------------------exercice7---------------------

// entre : entier n
// sortie : void
// Affiche un triangle isocèle comportant n ligne en entree 
void dessineTriangle(int n){
    for (int i = 0; i <= n; i++){
        printf("\n");
        for (int y = 0;y<= n; y++){
            if (n - i <= y){
                printf("*");
            }else{
                printf(" ");
            }
        }
    }
    printf("\n");
}

int main(){
    dessineTriangle(5);
}


//-------------------------exercice8------------------


float suite_rec(int n){
    if (n == 0){
        return 1.f;
    }else{
        return suite(n-1)/n;
    }
}


//-----------------------exercice9----------------------


int estDivisible (int a,int n){
    if (a % n == 0){
        return 1;
    }else{
        return 0;
    }
}

