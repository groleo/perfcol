#include "metrics.h"

//  TEMPORARY
static __gluey::member_t c1(5, 3, 0);

#define do2 1

#if do2
static __gluey::member_t c2(6, 5, 3);
#endif

void counters_setup()
{
	mag_init();

	member_setup(c2);
	member_setup(c1);

	member_start(c1);
	member_start(c2);
}

void counters_report()
{
	member_read(c1, NULL);
	member_read(c2, NULL);
}
