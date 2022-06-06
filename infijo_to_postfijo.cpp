#include <iostream>
#include <stdio.h>
#include <conio.h>
#define max 50

using namespace std;

/*
Gramática de la expresión infija:
Exp --> Term Resto
Resto --> + Term {printf("+")} Resto
Resto --> - Term {printf("-")} Resto
Resto -->
Term --> {printf("0")} 0
Term --> {printf("1")} 1
...
Term --> {printf("9")} 9

*/

int preanalisis;

void error(){
    printf("Error de sintaxis\n");
}

void parea(int t){
    if (preanalisis == t)
        preanalisis = getchar();
    else
        error();
}

void Term() {

    if (preanalisis == '0') {
        printf("0"); parea('0');
    }
    else if (preanalisis == '1') {
        printf("1"); parea('1');
    }
    else if (preanalisis == '2') {
        printf("2"); parea('2');
    }
    else if (preanalisis == '3') {
        printf("3"); parea('3');
    }
    else if (preanalisis == '4') {
        printf("4"); parea('4');
    }
    else if (preanalisis == '5') {
        printf("5"); parea('5');
    }
    else if (preanalisis == '6') {
        printf("6"); parea('6');
    }
    else if (preanalisis == '7') {
        printf("7"); parea('7');
    }
    else if (preanalisis == '8') {
        printf("8"); parea('8');
    }
    else if (preanalisis == '9') {
        printf("9"); parea('9');
    }
    else {
    error();
    }
}

void Resto() {
    if (preanalisis == '+'){
        parea('+'); Term(); printf("+"); Resto();
    }
    else if (preanalisis == '-') {
        parea('-'); Term(); printf("-"); Resto();
    }
    else if (preanalisis != '+' && preanalisis != '-') {
        printf("\n");
    }
    else {
        error();
    }
}

void Exp(){
    if (isdigit(preanalisis)){
        Term(); Resto();
    }
    else {
        error();
    }
}

int main(){

    cout << "Ingrese la expresion infija: ";
    preanalisis = getchar();
    
    Exp();
}