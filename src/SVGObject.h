#pragma once
#include <iostream>

class SVGObject
{
public:
	friend class SVGWriter;
	SVGObject() = default;
	~SVGObject() = default;

protected:
	virtual std::string toSVGStr() const = 0;
};

