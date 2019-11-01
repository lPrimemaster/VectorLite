#include "Quad.h"

#define SIMILAR_ASSIGN(val) this->val = val

Quad::Quad(float xTL, float yTL, float xTR, float yTR, float xBL, float yBL, float xBR, float yBR, std::string style)
{
	SIMILAR_ASSIGN(xTL);
	SIMILAR_ASSIGN(yTL);
	SIMILAR_ASSIGN(xTR);
	SIMILAR_ASSIGN(yTR);
	SIMILAR_ASSIGN(xBL);
	SIMILAR_ASSIGN(yBL);
	SIMILAR_ASSIGN(xBR);
	SIMILAR_ASSIGN(yBR);

	style_class = style;
}

#undef SIMILAR_ASSIGN

Quad::Quad(float cx, float cy, float width, float height, std::string style) : Quad(cx - width / 2, cy - height / 2, cx + width / 2, cy - height / 2, cx - width / 2, cy + height / 2, cx + width / 2, cy + height / 2, style)
{
}

Quad::Quad(float cx, float cy, float edge, std::string style) : Quad(cx, cy, edge, edge, style)
{
}

Quad::~Quad()
{
}

std::string Quad::toSVGStr() const
{
	char buffer[256];
	sprintf_s(buffer, "<path d = \"M%f %f \
		L%f %f \
		L%f %f \
		L%f %fZ\" class=\"%s\"/>", xTL, yTL, xTR, yTR, xBR, yBR, xBL, yBL, style_class.c_str());
	return std::string(buffer);
}
