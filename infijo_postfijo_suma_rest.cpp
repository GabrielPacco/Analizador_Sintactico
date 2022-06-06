#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
#define max 50

using namespace std;

struct stack {     //ESTRUCTURA DE LA PILA
    char caracter;
    struct stack* next;
};

typedef struct stack* Ptrstack; //definimos estructura tipo pila
typedef struct stack* Ptrlist; //definimos estructura tipo lista


/*                 Apilar
-------------------------------------------------*/
void push(Ptrstack& p, char a)
{
    Ptrstack q = new struct stack;
    q->caracter = a;
    q->next = p;
    p = q;
}

/*                 Desempilar
-------------------------------------------------*/
char pop(Ptrstack& p)
{
    int n;
    Ptrstack aux;

    n = p->caracter;
    aux = p;
    p = p->next;
    delete(aux);
    return n;

}
/*                 Agregar a la Lista
--------------------------------------------------
funcion para agregar caracter a la lista de salida*/
void agregar_atras(Ptrlist& lista, char a)
{
    Ptrlist t, q = new(struct stack);

    q->caracter = a;
    q->next = nullptr;

    if (lista == nullptr)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while (t->next != nullptr)
        {
            t = t->next;
        }
        t->next = q;
    }

}

/*          Prioridad en Notacion Infija
----------------------------------------------------
esta prioridad se usa al momento de leer el caracter
de la cadena*/
int prioridad_infija(char a)
{
    if (a == '+')
        return 1;
    if (a == '-')
        return 1;
}

/*                 Prioridad en Pila
---------------------------------------------------
esta prioridad es usada para los elementos que se
encuentran en la pila */
int prioridad_pila(char a)
{
    if (a == '+')
        return 1;
    if (a == '-')
        return 1;
}

void print(Ptrlist& lista)
{
    Ptrstack aux;
    aux = lista;

    if (lista != nullptr)
    {
        cout << "\t\nNOTACION POSTFIJA\n\n";
        while (aux != nullptr)
        {
            cout << aux->caracter;
            aux = aux->next;
        }
    }
    cout << endl << endl;
}

int main()
{
    Ptrstack p = nullptr;
    Ptrstack M = nullptr;
    Ptrlist lista = nullptr;
    char cad[max], c;
    int tam;

    system("color 0b");

    cout << "CONVERSION DE EXPRESIONES MATEMATICAS DE INFIJA A POSTFIJA\n\n";
    do {
        cout << "INGRESE EXPRESION:";
        gets_s(cad);
    } while (M != nullptr);         //correctamente valanceados

    tam = strlen(cad);  // obtenemos el tamanho de la cadena
    for (int i = 0; i < tam; i++)
    {
        if ((cad[i] >= 49 && cad[i] <= 57) || (cad[i] >= 97 && cad[i] <= 122))//validado para numeros de 1-9 y letras
            agregar_atras(lista, cad[i]);
        if (cad[i] == '+' || cad[i] == '-')
        {
            if (p == nullptr)
                push(p, cad[i]);
            else
            {
                if (prioridad_infija(cad[i]) > prioridad_pila(p->caracter))//compara prioridad de operadores
                    push(p, cad[i]);
                else
                {
                    if (prioridad_infija(cad[i]) == prioridad_pila(p->caracter))
                    {
                        c = pop(p);
                        agregar_atras(lista, c);
                        push(p, cad[i]);
                    }
                    else
                    {
                        c = pop(p);
                        agregar_atras(lista, c);
                    }
                }
            }
        }
    }
    while (p != nullptr) //si es que la pila aun no esta nula pasamos los operadores a lista
    {
        c = pop(p);
        agregar_atras(lista, c);
    }

    print(lista);
    system("pause");
    return 0;
}
