#pragma once
#include "../SVGObject.h"

class Circle : public SVGObject
{
public:
	Circle(float center_x, float center_y, float radius, std::string style = "");
	~Circle();

protected:
	std::string toSVGStr() const override;

private:
	float cx;
	float cy;
	float r;
	std::string style_class;
};

