#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

/*
Reconoce la siguiente gramática:
S --> x S
S --> A B c
A --> a
B --> b
 
****************+
 
Reconoce la siguiente gramática:
S --> r S
S --> A Z a
A --> a
Z --> e
 
*/

///*
int preanalisis;
void error()
{
    printf("Error de sintaxis");
}

void parea(int t)
{
    if (preanalisis == t)
        preanalisis = getchar();
    else
        error();
}

void Z()
{
    if (preanalisis == 'e')
        parea('e');
    else
        error();
}

void A()
{
    if (preanalisis == 'a')
        parea('a');
    else
        error();
}


void S()
{
    if (preanalisis == 'r')
    {
        parea('r'); S();
    }
    else if (preanalisis == 'a')
    {
        A(); Z(); parea('a');
    }
    else
        error();
}

// Reconoce x*abc
// Ejemplo xxxxxxxxxxxx.....xxabc   ---> empieza con x y siempre debe terminar en abc
int main()
{
    preanalisis = getchar(); //lee un carácter
     //de la entrada
    S();
    printf("\nLa cadena se reconocio correctamente =) \n\n");
}//*/

