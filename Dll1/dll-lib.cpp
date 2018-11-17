#include "stdafx.h"
#include "dll-lib.h"

int discrim(int a, int b, int c)
{
	int d;
	d = b * b - 4 * a*c;
	return d;// pow(b,2)
}
