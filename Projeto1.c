/*Projeto 1 - Algoritmo e Programação II

Grupo:
 
- Klaus Gustavo Castelein Ricieri Moura - 10735808
- Bruno Matheus Garutti Pinto - 10736747

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu();
void lerPolinomio(double coeficientes[], int expoentes[], int *grau);
void imprimirPolinomio(double coeficientes[], int expoentes[], int grau);
double calcularValor(double coeficientes[], int expoentes[], int grau, double x);
void somarPolinomios(double coeficientes1[], int expoentes1[], int grau1, double coeficientes2[], int expoentes2[], int grau2, double resultadoCoeficientes[], int resultadoExpoentes[], int *resultadoGrau);
void multiplicarPolinomios(double coeficientes1[], int expoentes1[], int grau1, double coeficientes2[], int expoentes2[], int grau2, double resultadoCoeficientes[], int resultadoExpoentes[], int *resultadoGrau);

int main() {
    int opcao;
    double p1_coefs[10], p2_coefs[10], resultado_coefs[20];
    int p1_exps[10], p2_exps[10], resultado_exps[20];
    int p1_grau, p2_grau, resultado_grau;
    double x, valor;

    do {
        menu();
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("\n--- Calcular Valor de um Polinomio ---\n");
            lerPolinomio(p1_coefs, p1_exps, &p1_grau);
            printf("Digite o valor de x: ");
            scanf("%lf", &x);
            valor = calcularValor(p1_coefs, p1_exps, p1_grau, x);
            printf("\nO valor do polinomio P(x) e: %.2lf\n", valor);

        } else if (opcao == 2) {
            printf("\n--- Somar Polinomios ---\n");
            printf("Polinomio 1:\n");
            lerPolinomio(p1_coefs, p1_exps, &p1_grau);

            printf("Polinomio 2:\n");
            lerPolinomio(p2_coefs, p2_exps, &p2_grau);

            somarPolinomios(p1_coefs, p1_exps, p1_grau, p2_coefs, p2_exps, p2_grau, resultado_coefs, resultado_exps, &resultado_grau);
            printf("\nO polinomio resultado da soma e: ");
            imprimirPolinomio(resultado_coefs, resultado_exps, resultado_grau);

        } else if (opcao == 3) {
            printf("\n--- Multiplicar Polinomios ---\n");
            printf("Polinomio 1:\n");
            lerPolinomio(p1_coefs, p1_exps, &p1_grau);

            printf("Polinomio 2:\n");
            lerPolinomio(p2_coefs, p2_exps, &p2_grau);

            multiplicarPolinomios(p1_coefs, p1_exps, p1_grau, p2_coefs, p2_exps, p2_grau, resultado_coefs, resultado_exps, &resultado_grau);
            printf("\nO polinomio resultado da multiplicacao e: ");
            imprimirPolinomio(resultado_coefs, resultado_exps, resultado_grau);

        } else if (opcao == 0) {
            printf("\nSaindo da calculadora. Ate logo!\n");

        } else {
            printf("\nOpcao invalida. Por favor, tente novamente.\n");

        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}

void menu() {
    printf("--- Calculadora de Polinomios ---\n");
    printf("1. Calcular o valor de um polinomio\n");
    printf("2. Somar dois polinomios\n");
    printf("3. Multiplicar dois polinomios\n");
    printf("0. Sair\n");
}

void lerPolinomio(double coeficientes[], int expoentes[], int *grau) {
    int i;
    printf("Digite o grau do polinomio (maximo 10): ");
    scanf("%d", grau);

    if (*grau > 10) {
        printf("Grau muito alto. Usando o grau maximo.\n");
        *grau = 10;
    }

    for (i = *grau; i >= 0; i--) {
        printf("Digite o coeficiente de x^%d: ", i);
        scanf("%lf", &coeficientes[i]);
        expoentes[i] = i;
    }
}

void imprimirPolinomio(double coeficientes[], int expoentes[], int grau) {
    int i;
    printf("P(x) = ");
    int primeiroTermo = 1;
    for (i = grau; i >= 0; i--) {
        if (coeficientes[i] != 0) {
            if (!primeiroTermo && coeficientes[i] > 0) {
                printf(" + ");
            }
            if (expoentes[i] > 1) {
                printf("%.0lfx^%d", coeficientes[i], expoentes[i]);
            } else if (expoentes[i] == 1) {
                printf("x", coeficientes[i]);
            } else {
                printf("%.0lf", coeficientes[i]);
            }
            primeiroTermo = 0;
        }
    }
    printf("\n");
}

double calcularValor(double coeficientes[], int expoentes[], int grau, double x) {
    double resultado = 0.0;
    int i;
    for (i = 0; i <= grau; i++) {
        resultado += coeficientes[i] * pow(x, expoentes[i]);
    }
    return resultado;
}

void somarPolinomios(double coeficientes1[], int expoentes1[], int grau1, double coeficientes2[], int expoentes2[], int grau2, double resultadoCoeficientes[], int resultadoExpoentes[], int *resultadoGrau) {
    int i;
    if (grau1 > grau2) {
        *resultadoGrau = grau1;
    } else {
        *resultadoGrau = grau2;
    }

    for (i = 0; i <= *resultadoGrau; i++) {
        resultadoCoeficientes[i] = 0.0;
        resultadoExpoentes[i] = i;
    }

    for (i = 0; i <= grau1; i++) {
        resultadoCoeficientes[i] += coeficientes1[i];
    }
    for (i = 0; i <= grau2; i++) {
        resultadoCoeficientes[i] += coeficientes2[i];
    }
}

void multiplicarPolinomios(double coeficientes1[], int expoentes1[], int grau1, double coeficientes2[], int expoentes2[], int grau2, double resultadoCoeficientes[], int resultadoExpoentes[], int *resultadoGrau) {
    int i, j;
    *resultadoGrau = grau1 + grau2;

    for (i = 0; i <= *resultadoGrau; i++) {
        resultadoCoeficientes[i] = 0.0;
        resultadoExpoentes[i] = i;
    }

    for (i = 0; i <= grau1; i++) {
        for (j = 0; j <= grau2; j++) {
            resultadoCoeficientes[i + j] += coeficientes1[i] * coeficientes2[j];
        }
    }
}
