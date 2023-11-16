//---------------------------------Pointueur et allocation dynamique---------------------

//------intro


//1

// 5
// deux fois l'adresse de x
// deux fois l'adresse de x mais par y
// affiche valeur pointer par y qui est x
// affiche 12 car on a ajouter 7 a la valeur pointer pas y


//2


// *px : 5
// *py : 7
// *px : 7
// *py : 5


//3

// 1 2 3
// 124 5 10


//4

// 1 12 3
// 3





//7


void incremente(int* p){
    *p++;
}


//8

void echange(int* p1, int* p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//9

void carre(int* x){
    *x = *x * *x;
}

//10

void disque(float rayon, float* diam, float* peri, flaot* surf){
    *diam = 2.f * rayon;
    *perim = 3.14f * *diam;
    *surf = 3.14f * rayon * rayon;
}


