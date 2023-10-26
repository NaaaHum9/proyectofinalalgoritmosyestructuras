#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Este codigo lo que hace es pedir al usuario que ingrese elementos para dos pilas, el usuario puede elegir 
 * la pila en donde ingresar los elemntos, despues hace un mesclado de los lementos para despues ordenarlos
 * con el metodo de ordenamiento por burbuja, despues se le sa la opcion al usuario de buscar un elemto en 
 * la pila ya ordenada, esto lo hace por el metodo de busqueda binaria 
*/

#define TAM 100
#define TRUE 1
#define FALSE 0

typedef struct{
    int items[TAM];
    int tope;
}Stack;

typedef Stack* STACK;

STACK initStack();
int isEmpty(STACK S);
bool isFull(STACK S);
void push(STACK S, int value);
int pop(STACK S);
void liberarMem(STACK S, STACK S2, STACK S3, STACK S4);
void datosStack(STACK S);
void mostrarStack(STACK S);
void mezclaStack(STACK S, STACK S2, STACK S3);
void ordenaStack(STACK S3);
int busquedaBinaria(STACK S3, int elemento);

int main() {
    STACK S, S2, S3, S4;
    S = initStack();
    S2 = initStack();
    S3 = initStack();
    S4 = initStack();

    int selec=0, aux;

    printf("Tamanio de la pila: %d\n", TAM);
    do{
        printf("\nSeleccione una opcion\n");
        printf("1 - Igresar elemento para Stack 1 \n");
        printf("2 - Ingresar elementos para Stack 2\n");
        printf("3 - Mezclar Stacks \n");
        printf("4 - Ornedar Stacks \n");
        printf("5 - Buscar en el Stack \n");
        printf("6 - Mostrar elementos \n");
        printf("7 - Salir\n");
        scanf("%i", &selec);
        printf("\n");
        switch (selec){
            case 1:
                datosStack(S);
                break;
            case 2: 
                datosStack(S2);
                break;
            case 3:
                mezclaStack(S, S2, S3);
                //mostrarStack(S3);
                break;
            case 4:
                ordenaStack(S3);
                //mostrarStack(S3);
                break;
            case 5:
                printf("\nIngrese el elemto a buscar: \n");
                scanf("%i", &aux);
                busquedaBinaria(S3, aux);
            if (busquedaBinaria(S3, aux) == -1){
                printf("ELEMENTO NO ENCONTRADO\n");
            }else{
                printf("Elmento encontrado\n");
            }
                break;
            case 6:
                mostrarStack(S3);
                break;

        }
    } while (selec != 7);
    liberarMem(S, S2, S3, S4);
}

void datosStack(STACK S){
    int value;
    printf("Ingrese un valor: \n");
    scanf("%i", &value);
    push(S, value);
}

void mezclaStack(STACK S, STACK S2, STACK S3){
    int aux1, aux2;
    while (isEmpty(S) == FALSE || isEmpty(S2) == FALSE){
        if (isEmpty(S) == FALSE){
            aux1 = pop(S);
            push(S3, aux1);
        }
        if (isEmpty(S2) == FALSE){
            aux2 = pop(S2);
            push(S3, aux2);
        }
    }
    printf("\nElementos mezclados\n");
    
}

void ordenaStack(STACK S4){
    int i, j;
    int n = S4->tope + 1;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (S4->items[j] > S4->items[j + 1]) {
                int temp = S4->items[j];
                S4->items[j] = S4->items[j + 1];
                S4->items[j + 1] = temp;
            }
        }
    }
    printf("\nElementos Ordenados\n");
}

int busquedaBinaria(STACK S3, int elemento){
    int inicio = 0;
    int fin = S3->tope;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (S3->items[medio] == elemento) {
            return medio;
        } else if (S3->items[medio] < elemento) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1; // El elemento no se encontró en la pila
}

void mostrarStack(STACK S3){
    int aux;
    printf("Elmentos ingresados: \n");
    while (isEmpty(S3) == FALSE){
        aux = pop(S3);
        printf("%i \n", aux);
    }
    
}

STACK initStack(){
    STACK S;
    S = (STACK)malloc(sizeof(Stack));
    if (S==NULL){
        exit(0);
    }
    S->tope = -1;
    return S;
}

int isEmpty(STACK S) {
    if (S->tope == -1){
        return TRUE;
    }
    return FALSE;
}

bool isFull(STACK S) {
    return S->tope == TAM - 1;
    printf("\nPila llena\n");
}

void push(STACK S, int value) {
    if (S->tope == TAM-1){
        exit(0);
    }
    (S->tope)++;
    S->items[S->tope] = value;
}

int pop(STACK S) {
    int aux;
    if (isEmpty(S) == TRUE){
        exit(0);
    }
    aux = S->items[S->tope];
    (S->tope)--;
    return aux;
}

void liberarMem(STACK S, STACK S2, STACK S3, STACK S4){
    free(S);
    free(S2);
    free(S3);
    free(S4);
}
