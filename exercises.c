#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
    List *lista = create_list(); // Creamos una lista vacía

    // Iteramos sobre los números del 1 al 10
    for (int i = 1; i <= 10; i++) {
        int *dato = (int*)malloc(sizeof(int)); // Reservamos memoria para un entero
        if (dato == NULL) {
            // Manejar error de asignación de memoria
            printf("Error: No se pudo asignar memoria.\n");
            exit(EXIT_FAILURE);
        }
        *dato = i; // Asignamos el valor del número

        pushBack(lista, dato); // Agregamos el puntero a la lista
    }

    return lista;
}



/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/

int sumaLista(List *L) {
    int suma = 0; // Variable para almacenar la suma
    int *elemento; // Variable para almacenar cada elemento de la lista

    // Iterar sobre la lista y sumar cada elemento
    elemento = (int*)first(L); // Obtenemos el primer elemento
    while (elemento != NULL) {
        suma += *elemento; // Sumamos el elemento actual a la suma
        elemento = (int*)next(L); // Pasamos al siguiente elemento
    }

    return suma; // Retornamos la suma total
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List *L, int elem) {
    int *elemento;
    
    elemento = (int*)first(L); 
    while (elemento != NULL) {
   
       if (*elemento == elem) {
            popCurrent(L);
       }
       elemento = next(L);
       
     
}
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
    List *lista = create_list(); 
    
    for (int i = 1; i <= 10; i++) {
        int *dato = (int*)malloc(sizeof(int)); 
        if (dato == NULL) {
            
            printf("Error: No se pudo asignar memoria.\n");
            exit(EXIT_FAILURE);
        }
        *dato = i;
        pushBack(lista, dato); 
    }

    return lista;
}



/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/

int sumaLista(List *L) {
    int suma = 0; 
    int *elemento;
    
    elemento = (int*)first(L);
    while (elemento != NULL) {
        suma += *elemento; 
        elemento = (int*)next(L); 
    }

    return suma; 
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List *L, int elem) {
    int *elemento;
    
    elemento = (int*)first(L); 
    while (elemento != NULL) {
   
       if (*elemento == elem) {
            popCurrent(L);
       }
       elemento = next(L);
       
     
}
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/
void copia_pila(Stack *P1, Stack *P2) {
    Stack *aux_stack = create_stack(); 
  
    while (top(P1) != NULL) {
        push(aux_stack, pop(P1));
    }

    while (top(aux_stack) != NULL) {
        push(P1, top(aux_stack)); 
        push(P2, pop(aux_stack)); 
    }

    free(aux_stack);
}


/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
    Stack *pila = create_stack();
    int longitud = strlen(cadena);

    for (int i = 0; i < longitud; i++) {
        if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{') {

            push(pila, &cadena[i]);
        } else if (cadena[i] == ')' || cadena[i] == ']' || cadena[i] == '}') {
        
            if (top(pila) == NULL) {

                free(pila);
                return 0;
            }

            char *ultimo_abierto = (char *)pop(pila);

            if ((cadena[i] == ')' && *ultimo_abierto != '(') ||
                (cadena[i] == ']' && *ultimo_abierto != '[') ||
                (cadena[i] == '}' && *ultimo_abierto != '{')) {
                free(pila);
                return 0;
            }
        }
    }

    if (top(pila) != NULL) {
        free(pila);
        return 0;
    }


    free(pila);
    return 1;
}


