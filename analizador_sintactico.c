#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
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

void B()
{
	if (preanalisis == 'b')
		parea('b');
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
	if (preanalisis == 'x')
	{
		parea('x'); S();
	}
	else if (preanalisis == 'a')
	{
		A(); B(); parea('c');
	}
	else
		error();
}

int main()
{
	preanalisis = getchar(); //lee un carácter
	 //de la entrada
	S();
}//*/