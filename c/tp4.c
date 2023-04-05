//-------------------------------------7----------------------------


#include <stdio.h>
/*
void minmax (int a, int b, int* pmin, int* pmax){
    if(a>b){
        *pmin = b;
        *pmax = a;
    }else{
        *pmin = a;
        *pmax = b;
    }
}



int main(){
    int val1 = 42;
    int val2 = 77;
    int min;
    int max;
    minmax(val1, val2, &min, &max);
    printf("min=%d,max=%d\n", min, max);
}
*/



//-----------------------------------------------9-------------------------------

void array_print(int* tab, int size){
    for(int i = 0; i<size; i++){
        printf("%d", tab[i]);
        printf("\n")
    }
}

