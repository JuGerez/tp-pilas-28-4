#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

void cargaDatosUsuario(Pila *p);
void pasaPila (Pila *p, Pila *q);
void pasaPilaOrdenada(Pila *p, Pila *q);
int datoMenor(Pila *p);
void pilaOrdenadaMenorMayor (Pila *p, Pila *q);
void insertarOrdenado(Pila *p, int dato);
int sumaDosDatos (Pila p);
int sumaTotal (Pila p);
int cuentaDigitos (Pila p);
void cargaDatosUnDigito (Pila *p);


int main()
{
    srand(time(NULL));

    Pila origen;
    Pila reversa;
    Pila ordenada;
    Pila menorMayor;
    Pila insertada;
    inicpila(&origen);
    inicpila(&reversa);
    inicpila(&ordenada);
    inicpila(&menorMayor);
    inicpila(&insertada);

    cargaDatosUsuario(&origen);
    printf("Pila original: \n");
    mostrar(&origen);
    pasaPila(&origen, &reversa);
    printf("Pila reversa: \n");
    mostrar(&reversa);

    pasaPilaOrdenada(&reversa, &ordenada);
    printf("Pila ordenada: \n");
    mostrar(&ordenada);

    int menor;
    menor = datoMenor(&ordenada);
    printf("El dato menor de la pila es: %d \n\n", menor);

    printf("La pila ordenada de menor a mayor es: \n");
    pilaOrdenadaMenorMayor(&ordenada, &menorMayor);
    mostrar(&menorMayor);

    printf("La pila con el dato insertado es: \n");
    insertarOrdenado(&menorMayor, 6);
    mostrar(&menorMayor);

    int suma;
    suma = sumaDosDatos(menorMayor);
    printf("La suma de los dos ultimos numeros es: %d \n", suma);

    int total;
    total = sumaTotal(menorMayor);
    printf("El total de la pila es: %d \n", total);

    int digitos;
    digitos = cuentaDigitos(menorMayor);
    printf("La cantidad de digitos son: %d \n", digitos);

    int promedio;
    promedio = promedioPila(menorMayor);
    printf("El promedio de la pila es: %d \n", promedio);

    return 0;
}
//1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.
void cargaDatosUsuario(Pila *p)
{
    char opcion;
    int dato;

    while (opcion != 27 ){
        printf("Ingrese un dato: \n");
        scanf("%d", &dato);
        apilar(p, dato);

        printf("\n");
        printf("Quiere continuar? Presione cualquier tecla, sino ESC para salir \n");
        opcion = getch();
        system("cls");
    }
}
//Hacer una función que pase todos los elementos de una pila a otra.
void pasaPila (Pila *p, Pila *q)
{
    while(!pilavacia (p)){
        apilar(q, desapilar(p));
    }
}
//Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden
void pasaPilaOrdenada(Pila *p, Pila *q)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p)){
        apilar(&aux, desapilar(p));
        }
    while(!pilavacia(&aux)){
        apilar(q, desapilar(&aux));
    }
}
//Hacer una función que encuentre el menor elemento de una pila y lo retorna. La
//misma debe eliminar ese dato de la pila.
int datoMenor (Pila *p)
{
    int menor;
    Pila aux;
    inicpila(&aux);

   if(!pilavacia(p)){
        menor = desapilar(p);
   }
    while(!pilavacia(p)){
        if (tope(p) < menor){
            apilar(&aux, menor);
            menor = desapilar(p);
        } else {
            apilar(&aux, desapilar(p));
        }
    }
    pasaPila(&aux, p);

    return menor;
}
//Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
//nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)
void pilaOrdenadaMenorMayor (Pila *p, Pila *q)
{
    while(!pilavacia(p)){
        apilar(q, datoMenor(p));
    }
}
//6 y 7. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden
//de ésta.
void insertarOrdenado(Pila *p, int dato)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p)&& dato < tope(p)){
        apilar(&aux, desapilar(p));
    }
    apilar(p, dato);
    pasaPila(&aux, p);
}
//8. Hacer una función que sume los dos primeros elementos de una pila (tope y anterior), y retorne
//la suma, sin alterar el contenido de la pila.
int sumaDosDatos (Pila p)
{
    int total = 0;
    int numero1;
    int numero2;

    if(!pilavacia(&p)){
        numero1 = desapilar(&p);
        numero2 = tope(&p);

        total = numero1 + numero2;
    }

    return total;
}
//9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también
//una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro
//funciones, y la función que calcula el promedio invoca a las otras 3.
int sumaTotal (Pila p)
{
    int acumulador = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p)){
        acumulador = acumulador + tope(&p);
        apilar(&aux, desapilar(&p));
    }

    return acumulador;
}
int cuentaDigitos (Pila p)
{
    int cantidad = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p)){
        apilar(&aux, desapilar(&p));
        cantidad++;
    }

    return cantidad;
}
int promedioPila (Pila p)
{
    int promedio = 0;
    int total = sumaTotal(p);
    int cantidad = cuentaDigitos(p);

    if(!pilavacia(&p)){
        promedio = total / cantidad;
    }

    return promedio;
}
//10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de
//quien usa el programa) y que transforme esos dígitos en un número decimal.
void cargaDatosUnDigito (Pila *p)
{

}
