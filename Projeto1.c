/*Projeto 1 - Algoritmo e Programação II

Grupo:
 oi 
- Klaus Gustavo Castelein Ricieri Moura - 10735808
- Bruno Matheus Garutti Pinto - 10736747

*/

#include <stdio.h>

int valor_polinomio(int poli[], int x){

}

int main(){
    int grau = 3;
    char x[grau][3];
    int coef[4] = {4, 3, 1, 2};
   
    int *p = 0;
    double poli[*p];

    for(int i=0; i<grau+1; i++){
        int temp = grau-i;
        sprintf(x[i], "x^%d", temp);
    }

    for(int i=0; i<grau+1; i++){
        printf("x%d = %d", i, x[i]);
    }

    for(int i=0; i<grau+1; i+2){
        int temp = grau;        
        *p += 2;

        poli[i] += coef[i];
        poli[i+1] += x[i][3];
    }
    
    

    //Conferência do código
    for(int i=0; i<grau; i++){
        printf("X = %d ", x[i]);
    }

}
