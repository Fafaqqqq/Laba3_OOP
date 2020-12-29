#pragma once
#include "Shape.h"
#include "IShapeParser.h"
#include <memory>
#include <map>
#include <vector>
#include <set>

class ShapeStorage
{
public:
	ShapeStorage() = default;
	void add(std::unique_ptr<Shape>&& source, int index);
	void erase(int index);
	std::set<int> findByArea(double area);
	std::set<int> findByName(const std::string& name);

	const Shape& operator[](int index);

	bool empty() const;
	int size() const;

	const std::set<int>& getIndexes() const;

private:
	std::map<int, std::unique_ptr<Shape>> _defaultStorage;
	std::map<double, std::set<int>> _indexByArea;
	std::map<std::string, std::set<int>> _indexByName;
	std::set<int> _indexes;
};	