
#include "stdio.h"
#include "stdlib.h"

#include "Entity2d.h"
#include "Line2d.h"
#include "MathTools.h"
#include "Mat4.h"
#include "DxfParser.h"
#include "Chain2dConnector.h"
#include "StlParser.h"
#include "ObjParser.h"

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
	//printf("\n%lf\n", mat.determinant());

	mat.transpose();

	using namespace CAX;

	Point2d *p = Entity2d::newPoint();
	Line2d *pLine = Entity2d::newLine();

	Arc2d* pArc = Entity2d::newArc();
	Circle2d* pCircle = Entity2d::newCircle();


	DxfParser parser;
	parser.polylineToLines(true);
	parser.lwPolylineToLineArcs(true);
	bool ret = parser.parse("C:/Users/smallpi/Desktop/NCUtilTest/20160306/1.dxf");
	Chain2dConnector connector;
	connector.fromList(parser.entities());

	BoundingBox2d box = connector.chains().front().boundingBox2d();


	StlParser stlParser;
	stlParser.parse("C:/Users/smallpi/Desktop/NCUtilTest/xichuang/fresadora_convencional.stl");

	ObjParser objParser;
	objParser.parse("C:/Users/smallpi/Desktop/NCUtilTest/cylinder_d100.obj");


	printf("### %p ###\n", (&Vec3d::z));

	system("pause");

	return 0;
}