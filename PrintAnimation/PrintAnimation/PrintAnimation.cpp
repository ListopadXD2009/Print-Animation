#include <windows.h>
#include <stdio.h>
#include <thread>

INT
main( )
{
	INT x = 120;
	INT y = 400;
	INT t = 0;

	for ( ;; )
	{
		printf( "\033[2J\033[H" );

		for ( INT y2 = 0; y2 < y; y2++ ) 
		{
			for ( INT x2 = 0; x2 < x; x2++ )
			{
				INT v = ( 3 + x + t ) & 63;

				CHAR ramp[ ] = "No se";
				CHAR c = ramp[ v % ( sizeof( ramp ) - 1 ) ];

				printf( "%c", c );
			}

			printf( "\n" );
		}

		fflush( stdout ); 
		std::this_thread::sleep_for( std::chrono::milliseconds( 40 ) );
		t++;
	}
}