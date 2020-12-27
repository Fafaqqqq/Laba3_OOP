#include "ShapeStorage.h"
#include <exception>

void ShapeStorage::add(std::unique_ptr<Shape> source, int index)
{
	if (_defaultStorage.find(index) == _defaultStorage.end())
	{
		_defaultStorage[index] = std::move(source);

		_indexByArea[_defaultStorage[index]->getArea()].insert(index);
		_indexByName[_defaultStorage[index]->getName()].insert(index);
		_indexes.insert(index);
		return;
	}
	
	throw std::logic_error("Shape with this index already exists!");
}

Shape& ShapeStorage::operator[](int index)
{
	if (_defaultStorage.find(index) != _defaultStorage.end())
	{
		return *_defaultStorage[index];
	}
	
	throw std::range_error("No such element!");
}

void ShapeStorage::erase(int index)
{
	if (_defaultStorage.find(index) != _defaultStorage.end())
	{
		_indexByArea[_defaultStorage[index]->getArea()].erase(index);
		_indexByName[_defaultStorage[index]->getName()].erase(index);

		if (_indexByArea[_defaultStorage[index]->getArea()].size() == 0)
		{
			_indexByArea.erase(_defaultStorage[index]->getArea());
		}
		
		if (_indexByName[_defaultStorage[index]->getName()].size() == 0)
		{
			_indexByName.erase(_defaultStorage[index]->getName());
		}

		_defaultStorage.erase(index);

		return;
	}

	throw std::logic_error("No such element!");
}

const std::set<int>& ShapeStorage::findByArea(double area)
{
	if (_indexByArea.find(area) != _indexByArea.end())
	{
		return _indexByArea[area];
	}
	else
	{
		return std::move(std::set<int>());
	}
}

const std::set<int>& ShapeStorage::findByName(const std::string& name)
{
	if (_indexByName.find(name) != _indexByName.end())
	{
		return _indexByName[name];
	}
	else
	{
		return std::move(std::set<int>());
	}
}

const std::set<int>& ShapeStorage::getIndexes()
{
	return _indexes;
}

bool ShapeStorage::empty() const
{
	return _defaultStorage.empty();
}

int ShapeStorage::size() const
{
	return _defaultStorage.size();
}