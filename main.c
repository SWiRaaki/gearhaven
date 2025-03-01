#include "gearhaven.h"

int main( void )
{
	gh_init();

	while ( gh_running() )
	{
		gh_update();
		gh_draw();
	}

	gh_close();

	return 0;
}
