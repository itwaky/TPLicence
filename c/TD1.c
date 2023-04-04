#include <stdio.h>

/*
#include <stdio.h>
int main() {
    int a = 21;
    int* ptr1;
    int* ptr2 = &a;
    ptr1 = ptr2;
    *ptr1 = *ptr1 + 10;//31
    *ptr2 = *ptr1 + 5;//36
    a = a + 6;//42
    printf("%d\n", a);
    return 0;
}
*/

/*
#include <stdio.h>
    int main() {
        int tab[2] = {38, 34};
        int* ptr = tab;
        *tab = *tab + 1;//{39, 34}
        tab[0] = tab[0] + 1;//{40, 34}
        *ptr = *ptr + 1;//{41, 34}
        ptr[0] = ptr[0] + 1;//{42, 34}
        *(tab + 1) = *(tab + 1) + 2;//{42, 36}
        tab[1] = tab[1] + 2;//{42, 38}
        *(ptr + 1) = *(ptr + 1) + 2;//{42, 40}
        ptr[1] = ptr[1] + 2; //{42, 42}
        printf("%d\n", tab[0]);
        printf("%d\n", tab[1]);
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
int main() {
    int* tab = malloc(2 * sizeof(int));
    *tab = 21;//{21}
    tab[0] = tab[0] + 21;//{42}
    *(tab + 1) = 21;//{42, 21}
    tab[1] = tab[1] + 21;//{42, 42}
    printf("%d\n", tab[0]);
    printf("%d\n", tab[1]);
    free(tab);
    return 0;
}
*/

//----------------------------------------2.4-------------------------------

/*
int triple(int* x){
    *x = *x * 3;
}

int main() {
    int x = 14;
    triple(&x);
    printf("%d\n", x);
    return 0;
}
*/


//----------------------------------------2.5---------------------------------
#include <stdlib.h>


int init(int* tab1, int* tab2){
    for (int i = 0; i<4; i++){
        *(tab1 + i) = 0;
        *(tab2 + i) = 0;
    }

}

int main(){
    int tab1[4];
    int* ptr = tab1;
    int* tab2 = malloc(4*sizeof(int));
    init(ptr, tab2);
    for (int i = 0; i<4; i++){
        printf("%d\n", tab1[i]);
        printf("%d\n", *(tab2 + i));
    }
}
