#include <iostream>

// Misc
#include "SVGWriter.h"

// Shapes
#include "shapes/Circle.h"
#include "shapes/Quad.h"

int main(int argc, char* argv[])
{
	SVGWriter writer("test.svg");

	SVGObject* c = new Circle(300, 300, 300, "c1");
	SVGObject* q = new Quad(300, 300, 300 * 2 / sqrt(2), "p1");

	SVGStyle style("circle.c1");
	style["stroke"] = "red";
	style["stroke-width"] = "5";
	style["fill"] = "none";

	SVGStyle style2("path.p1");
	style2["stroke"] = "blue";
	style2["stroke-width"] = "5";
	style2["fill"] = "none";

	writer.addStyle(style);
	writer.addStyle(style2);

	writer.storeObject(c);
	writer.storeObject(q);

	writer.write();

	delete c;

	return 0;
}