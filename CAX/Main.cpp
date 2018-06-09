
#include "stdio.h"
#include "stdlib.h"

#include "Line2d.h"
#include "MathTools.h"

#include <cmath>

int main(void)
{
	using namespace CAX;

	Line2d line;
	line.start().x = 10.0;
	line.end().x = 20.0;

	Entity2d *p = &line;

	printf("start = (%lf, %lf), end = (%lf, %lf)\n",
		p->head().x, p->head().y, p->tail().x, p->tail().y);

	system("pause");

	return 0;
}