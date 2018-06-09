
#include "stdio.h"
#include "stdlib.h"

#include "Line2d.h"
#include "MathTools.h"
#include "Mat4.h"

#include <cmath>



int main(void)
{
	//using namespace CAX;

	//Line2d line;
	//line.start().x = 10.0;
	//line.end().x = 20.0;

	//Entity2d *p = &line;

	//printf("start = (%lf, %lf), end = (%lf, %lf)\n",
	//	p->head().x, p->head().y, p->tail().x, p->tail().y);

	//system("pause");

	CAX::Mat4d mat(4.0, 1.0, 2.0, 2.2, 1.1, 2.3, 3.2, 1.2, 0.5, 3.2, 3.5, 1.5, 2.6, 2.2, 2.5, 1.9);
	printf("\n%lf\n", mat.determinant());
	system("pause");

	return 0;
}