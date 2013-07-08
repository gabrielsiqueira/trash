#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main( void )
{
  srand( time( NULL ));

  int i, j, ind_pai, ind_mae, pai, mae, indiceNovaPop = 1, ind_maiorApt;
double pop[ 30 ], apt[ 30 ], newPop[ 30 ], melhorApt = -100;

for ( i = 0; i < 30; ++i )
{
pop[ i ] = (double)rand() / RAND_MAX * 9;
apt[ i ] = pop[ i ] + 10 * sin( 5 * pop[ i ]) + 7 * cos( 4 * pop[ i ]);
}

for ( i = 0; i < 100; ++i )
{
for ( j = 0; j < 30; ++j )
if ( melhorApt < apt[ j ])
ind_maiorApt = j;

newPop[ 0 ] = pop[ ind_maiorApt ];

for ( j = 1; j < 30; ++j )
{
ind_pai = rand() % 30;
ind_mae = rand() % 30;

while(ind_pai == ind_mae)
                ind_mae = rand() % 30;

pai = ( apt[ ind_pai ] > apt[ ind_mae ] ? pop[ ind_pai ] : pop[ ind_mae ]);

ind_pai = rand() % 30;
ind_mae = rand() % 30;

while(ind_pai == ind_mae)
                ind_mae = rand() % 30;

mae = ( apt[ ind_pai ] > apt[ ind_mae ] ? pop[ ind_pai ] : pop[ ind_mae ]);

newPop[ j ] = ( pai + mae ) / 2;
}


}
return 0;
}
