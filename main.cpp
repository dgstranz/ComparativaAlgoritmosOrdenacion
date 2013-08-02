#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
int generar(int[],int);
int ordenarSeleccion(int[],int);
int ordenarInsercion(int[],int);
int ordenarIntercambio(int[],int);
int ordenarBurbuja(int[],int);
int ordenarMezcla(int[],int);
int intercambiar(int*,int*);
int visualizar(int[],int);

int main()
{
    int n=100000;           //Es necesario darle un valor inicial y que no lo sobrepase.
    int array[n];
    int opcion;
    char resp;              //Respuesta de tipo sí o no.
    clock_t tiempo;         //Contador de tiempo para ver qué algoritmo es más eficiente.
    cout << "Elige un tamaño para el array (de 0 a 100.000): ";
    cin >> n;
    cout << "Opciones" << endl << "--------" << endl;
    cout << "1. Ordenar por selección directa" << endl;
    cout << "2. Ordenar por inserción directa" << endl;
    cout << "3. Ordenar por intercambio directo" << endl;
    cout << "4. Ordenar por burbuja" << endl;
    cout << "5. Ordenar por mezcla" << endl;
    cout << "6. Comparar todas las anteriores" << endl;
    cout << "Elige una opción: ";
    cin >> opcion;
    switch(opcion)
    {
        case 1:
            generar(array,n);
            tiempo=clock();
            ordenarSeleccion(array,n);
            tiempo=clock()-tiempo;
            cout << "La ordenación de " << n << " elementos por selección directa ha tardado " << tiempo << " ms.";
            break;
        case 2:
            generar(array,n);
            tiempo=clock();
            ordenarInsercion(array,n);
            tiempo=clock()-tiempo;
            cout << "La ordenación de " << n << " elementos por inserción directa ha tardado " << tiempo << " ms.";
            break;
        case 3:
            generar(array,n);
            tiempo=clock();
            ordenarIntercambio(array,n);
            tiempo=clock()-tiempo;
            cout << "La ordenación de " << n << " elementos por intercambio directo ha tardado " << tiempo << " ms.";
            break;
        case 4:
            generar(array,n);
            tiempo=clock();
            ordenarBurbuja(array,n);
            tiempo=clock()-tiempo;
            cout << "La ordenación de " << n << " elementos por burbuja ha tardado " << tiempo << " ms.";
            break;
        case 5:
            generar(array,n);
            tiempo=clock();
            ordenarMezcla(array,n);
            tiempo=clock()-tiempo;
            cout << "La ordenación de " << n << " elementos por mezcla ha tardado " << tiempo << " ms.";
            break;
        case 6:
            generar(array,n);
            tiempo=clock();
            ordenarSeleccion(array,n);
            tiempo=clock()-tiempo;
            cout << "La ordenación de " << n << " elementos por selección directa ha tardado " << tiempo << " ms." << endl;
            generar(array,n);
            tiempo=clock();
            ordenarInsercion(array,n);
            tiempo=clock()-tiempo;
            cout << "La ordenación de " << n << " elementos por inserción directa ha tardado " << tiempo << " ms." << endl;
            generar(array,n);
            tiempo=clock();
            ordenarIntercambio(array,n);
            tiempo=clock()-tiempo;
            cout << "La ordenación de " << n << " elementos por intercambio directo ha tardado " << tiempo << " ms." << endl;
            generar(array,n);
            tiempo=clock();
            ordenarBurbuja(array,n);
            tiempo=clock()-tiempo;
            cout << "La ordenación de " << n << " elementos por burbuja ha tardado " << tiempo << " ms." << endl;
            generar(array,n);
            tiempo=clock();
            ordenarMezcla(array,n);
            tiempo=clock()-tiempo;
            cout << "La ordenación de " << n << " elementos por mezcla ha tardado " << tiempo << " ms.";
            break;
        default:
            return 0;
    }
    if(opcion>=1 && opcion<=5)
    {
        cout << endl << "¿Quieres ver los elementos del array ya ordenados? ";
        cin >> resp;
        if(resp=='s' || resp=='S')
        {
            visualizar(array,n);
        }
    }
    return 0;
}

int generar(int array[],int n)
{
    int i;
    srand((unsigned)time(0));
    for(i=0;i<n;i++)
    {
        array[i]=(RAND_MAX+1)*rand()+rand();                //De esta manera se supera el límite de 32767 para la generación
    }                                                       //de números aleatorios.
    return 0;
}

int ordenarSeleccion(int array[],int n)
{
    int i,j,menor;
    for(i=0;i<n-1;i++)
    {
        menor=i;
        for(j=i+1;j<n;j++)
        {
            if(array[j]<array[menor]) menor=j;
        }
        if(menor>i) intercambiar(&array[i],&array[menor]);
    }
    return 0;
}

int ordenarInsercion(int array[],int n)
{
    int i,j,aux;
    for(i=1;i<n;i++)                //Array desordenado
    {
        j=i-1;
        aux=array[i];               //Aparto el primero de los valores desordenados, de índice i,
        while(array[j]>aux && j>=0) //y voy comparándolo con los ordenados, de índice i-1 para abajo.
        {
            array[j+1]=array[j];    //Mientras los ordenados sean mayores, voy haciendo sitio echándolos a la derecha.
            j--;
        }
        array[j+1]=aux;             //En cuanto encuentro uno que es menor o he agotado la búsqueda, pongo el desordenado en su sitio.
    }
    return 0;
}

int ordenarIntercambio(int array[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(array[i]>array[j]) intercambiar(&array[i],&array[j]);
        }
    }
    return 0;
}

int ordenarBurbuja(int array[],int n)
{
    int i,aux,orden;
    orden=0;
    while (orden==0)
    {
        orden=1;
        for (i=0;i<=n-2;i++)
        {
            if (array[i] > array[i+1])
            {
                aux=array[i];
                array[i]=array[i+1];
                array[i+1]=aux;
                orden=0;
            }
        }
    }
    return 0;
}

int ordenarMezcla(int array[],int n)
{
    int mitadizq=n/2;
    int mitadder=mitadizq+n%2;                              //Si n es impar, mitadder=mitadizq+1, si n es par mitadder=mitadizq
    int izq[mitadizq];
    int der[mitadder];
    int i,j,k;
    for(i=0;i<mitadizq;i++) izq[i]=array[i];
    for(i=0;i<mitadder;i++) der[i]=array[mitadizq+i];
    if(mitadizq>1) ordenarMezcla(izq,mitadizq);             //Si los arrays resultantes tienen más de un elemento,
    if(mitadder>1) ordenarMezcla(der,mitadder);             //se aplica la recursividad y se vuelven a dividir.
    j=0;
    k=0;
    for(i=0;i<n;i++)                                        //Ahora toca volcar los elementos de los subarrays
    {                                                       //en el array padre, en su orden correcto.
        if(j<mitadizq)
        {
            if(k<mitadder)
            {
                if(izq[j]<der[k])
                {
                    array[i]=izq[j];
                    j++;
                }
                else
                {
                    array[i]=der[k];
                    k++;
                }
            }
            else
            {
                array[i]=izq[j];
                j++;
            }
        }
        else
        {
            array[i]=der[k];
            k++;
        }
    }
    return 0;
}

int intercambiar(int *a,int *b)
{
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
    return 0;
}

int visualizar(int array[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}
