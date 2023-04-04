
#include <stdio.h> // 6
int main() {
int tab[10];
int* pt = &tab[7];
tab[7] = 0;
printf("%d", *pt);
return 0;
}