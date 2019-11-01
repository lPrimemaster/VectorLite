#pragma once
#include <iostream>
#include <filesystem>
#include <iostream>
#include <unordered_map>

class SVGObject;

struct SVGStyle
{
	friend class SVGWriter;

	SVGStyle(std::string name) : name(name) {};
	SVGStyle() {};

	std::string& operator[](std::string val)
	{
		return styles[val];
	}

	std::string name;

private:
	std::unordered_map<std::string, std::string> styles;
};

class SVGWriter
{
public:
	SVGWriter(const std::string& fp);
	~SVGWriter();

	void storeObject(SVGObject* obj);
	void storeObjects(std::initializer_list<SVGObject*> list);

	void addStyle(SVGStyle style);

	bool write() const noexcept;

private:
	std::string concatAll() const;
	std::string allStyles() const;

private:
	std::vector<SVGObject*> objects;
	std::vector<std::string> styles;
	std::filesystem::path fp;
	FILE* f_ptr;
};

