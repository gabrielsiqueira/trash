#include <cstdlib>

typedef unsigned short uint16_t;

int main()
{
	const uint16_t z = 50;

	uint16_t i, j, k, l;
	unsigned long long m = 5;
	long long *****v;

	while ( m-- )
	{
		v = (long long *****) malloc( sizeof( long long **** ) * z );

		for ( i = 0; i < z; ++i )
		{
			v[ i ] = (long long ****) malloc( sizeof( long long *** ) * z );

			for ( j = 0; j < z; ++j )
			{
				v[ i ][ j ] = (long long ***) malloc( sizeof( long long ** ) * z );

				for ( k = 0; k < z; ++k )
				{
					v[ i ][ j ][ k ] = (long long **) malloc( sizeof( long long *) * z );

					for ( l = 0; l < z; ++l )
						v[ i ][ j ][ k ][ l ] = (long long *) malloc( sizeof( long long ) * z );
				}
			}
		}

		for ( i = 0; i < z; ++i )
		{
			for ( j = 0; j < z; ++j )
			{
				for ( k = 0; k < z; ++k )
				{
					for ( l = 0; l < z; ++l )
						free( v[ i ][ j ][ k ][ l ] );
					free( v[ i ][ j ][ k ] );
				}
				free( v[ i ][ j ] );
			}
			free( v[ i ] );
		}
		free( v );
	}
}
