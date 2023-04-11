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




#include <stdlib.h>
#define MAX 100
#define SIZE 16


void array_print(int* tab, int size){
    for(int i = 0; i<size; i++){
        printf("%d", tab[i]);
        printf("\n");
    }
}

int* array_create (int size){
    int* array = malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        *(array + i) = rand() % MAX;
    }
    return array;
}

int* array_copy(int* tab, int size, int n){
    int* tab2 = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        if (i>size){
            *(tab2 + i) = 0;
        }
        else{
            *(tab2 + i) = *(tab + i);
        }
    }
    return tab2;
}

void array_oddeven(int* tab, int* odd, int* even, int size, int* sizeOdd, int* sizeEven){
    for (int i = 0; i<size; i++){
        if (*(tab + i) % 2 == 0){
            *(even + *sizeEven) = *(tab + i);
            *sizeEven = *sizeEven + 1;
        }
        else{
            *(odd + *sizeOdd) = *(tab + i);
            *sizeOdd = *sizeOdd + 1;
        }
    }
}



int main() {
    int test1 = 0;
    int test2 = 0;
    scanf("la valeur de %d est de %d \n", &test1, &test2);
    int sizeOdd = 0;
    int sizeEven = 0;
    int* odd = malloc(SIZE * sizeof(int));
    int* even = malloc(SIZE * sizeof(int));
    int* array = array_create(SIZE);
    array_oddeven(array, odd, even, SIZE, &sizeOdd, &sizeEven);
    int n = 20;
    //int* array_copie = array_copy(array, SIZE, n);
    array_print(array, SIZE);
    printf("-\n");
    array_print(odd, sizeOdd);
    printf("-\n");
    array_print(even, sizeEven);
    //array_print(array_copie, n);
    free(array);
    free(odd);
    free(even);
    return 0;   
}



