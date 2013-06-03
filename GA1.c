#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main( void )
{
  srand( time( NULL ));

	int i, j, melhorApt = 0, ind_pai, ind_mae, pai, mae, indiceNovaPop = 1;
	double pop[ 30 ], apt[ 30 ], newPop[ 30 ];

	for ( i = 0; i < 30; ++i )
	{
		pop[ i ] = (double)rand() / RAND_MAX * 9;
		apt[ i ] = pop[ i ] + 10 * sin( 5 * pop[ i ]) + 7 * cos( 4 * pop[ i ]);
	}

	for ( i = 1; i < 100; ++i )
	{
		for ( j = 0; j < 30; ++j )
			if ( melhorApt > apt[ j ])
				melhorApt = j;

		newPop[ 0 ] = pop[ melhorApt ];

		for ( j = 1; i < 30; ++j )
		{
			ind_pai = rand() % 30;
			ind_mae = rand() % 30;

			pai = ( apt[ pai ] > apt[ mae ] ? pop[ pai ] : pop[ mae ]);

			ind_pai = rand() % 30;
			ind_mae = rand() % 30;

			mae = ( apt[ pai ] > apt[ mae ] ? pop[ pai ] : pop[ mae ]);

			newPop[ indiceNovaPop ] = ( pai + mae ) / 2;
		}


	}
	return 0;
}
