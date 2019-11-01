#include "Circle.h"

Circle::Circle(float center_x, float center_y, float radius, std::string style)
{
	cx = center_x;
	cy = center_y;
	r = radius;
	style_class = style;
}

Circle::~Circle()
{
}

std::string Circle::toSVGStr() const
{
	char buffer[256];
	sprintf_s(buffer, "<circle cx=\"%f\" cy=\"%f\" r=\"%f\" class=\"%s\"/>", cx, cy, r, style_class.c_str());
	return std::string(buffer);
}
