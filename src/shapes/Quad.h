#pragma once
#include "../SVGObject.h"

class Quad : public SVGObject
{
public:
	Quad(float xTL, float yTL, float xTR, float yTR, float xBL, float yBL, float xBR, float yBR, std::string style = "");
	Quad(float cx, float cy, float width, float height, std::string style = "");
	Quad(float cx, float cy, float edge, std::string style = "");
	~Quad();

protected:
	std::string toSVGStr() const override;

private:
	float xTL, yTL;
	float xTR, yTR;
	float xBL, yBL;
	float xBR, yBR;

	std::string style_class;
};

