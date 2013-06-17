
#include <stdio.h>

int add( int num1, int num2 )
{
	return num1 + num2;
}

int sub( int num1, int num2 )
{
	return num1 - num2;
}

int (*select(char opCode))(int, int)
{
	return opCode == '+' ? add : sub;
}

typedef int (*fptrOperation)(int, int);

int compute( fptrOperation op, int num1, int num2 )
{
	return op( num1, num2 );
}

int compute( char opCode, int num1, int num2 )
{
	fptrOperation op = select( opCode );
	return op( num1, num2 );
}

int (*operations[])(int, int) = { add, sub };

int main(void)
{
	printf( "%d\n%d\n%d\n%d\n%d\n%d\n",
			compute( add, 5, 6 ), compute( sub, 5, 6 ),
			compute( '+', 5, 6 ), compute( '-', 5, 6 ),
			operations[ '+' - 43 ]( 5, 6 ),
			operations[ '-' - 44 ]( 5, 6 ));

	return 0;
}