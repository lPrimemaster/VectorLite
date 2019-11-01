#include "SVGWriter.h"
#include "SVGObject.h"

#include "shapes/Circle.h"

SVGWriter::SVGWriter(const std::string& fp)
{
	std::filesystem::path relative = "data";

	std::error_code ec;
	bool newP = std::filesystem::create_directory(relative, ec);

	this->fp = relative / fp;

	std::string path = this->fp.string();

	fopen_s(&f_ptr, "data/test.svg", "w");
	if (!f_ptr) std::cerr << __FILE__ << " - " << __FUNCTION__ << "(): Could not create file" << std::endl;
}

SVGWriter::~SVGWriter()
{
	fclose(f_ptr);
}

void SVGWriter::storeObject(SVGObject* obj)
{
	objects.push_back(obj);
}

void SVGWriter::storeObjects(std::initializer_list<SVGObject*> list)
{
	for (auto obj : list)
	{
		objects.push_back(obj);
	}
}

void SVGWriter::addStyle(SVGStyle style)
{
	std::string allStyles;
	allStyles += "\n";
	allStyles += style.name;
	allStyles += " {\n";
	for (auto s : style.styles)
	{
		allStyles += s.first;
		allStyles += ": ";
		allStyles += s.second;
		allStyles += ";\n";
	}
	allStyles += "}";

	styles.push_back(allStyles);
}

bool SVGWriter::write() const noexcept
{
	std::string buffer = concatAll();
	std::string all_styles = allStyles();

	if (f_ptr)
	{
		fwrite("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n\n<svg xmlns=\"http://www.w3.org/2000/svg\"\nxmlns:xlink=\"http://www.w3.org/1999/xlink\" width=\"1280\" height=\"720\">\n", sizeof(char), 151 - 1, f_ptr);
		
		fwrite("<defs><style type = \"text/css\"><![CDATA[", sizeof(char), 41 - 1, f_ptr);

		fwrite("\ncircle{ stroke: black; fill: none; }", sizeof(char), 38 - 1, f_ptr);
		fwrite("\npath  { stroke: black; fill: none; }", sizeof(char), 38 - 1, f_ptr);

		fwrite(all_styles.c_str(), sizeof(char), all_styles.length(), f_ptr);

		fwrite("]]></style></defs>\n", sizeof(char), 20 - 1, f_ptr);
		
		fwrite(buffer.c_str(), sizeof(char), buffer.length(), f_ptr);

		fwrite("</svg>", sizeof(char), 7 - 1, f_ptr);

		return true;
	}
	return false;
}

std::string SVGWriter::concatAll() const
{
	std::string raw;
	for (auto obj : objects)
	{
		raw += obj->toSVGStr();
		raw += '\n';
	}
	return raw;
}

std::string SVGWriter::allStyles() const
{
	std::string all;
	for (auto s : styles)
	{
		all += s;
	}
	return all;
}
