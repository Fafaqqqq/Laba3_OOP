#include "ShapeStorage.h"
#include <exception>

void ShapeStorage::add(std::unique_ptr<Shape>&& source, int index)
{
	if (_defaultStorage.find(index) == _defaultStorage.end())
	{
		try
		{
			_defaultStorage[index] = std::move(source);

			_indexByArea[_defaultStorage[index]->getArea()].insert(index);
			_indexByName[_defaultStorage[index]->getName()].insert(index);
			_indexes.insert(index);
			
		}
		catch (const std::exception& err)
		{
			_defaultStorage.erase(index);
		}
		return;
	}
	
	throw std::logic_error("Shape with this index already exists!");
}

const Shape& ShapeStorage::operator[](int index)
{
	std::map<int, std::unique_ptr<Shape>>::iterator it = _defaultStorage.find(index);

	if (it != _defaultStorage.end())
	{
		return *(it->second);
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
		_indexes.erase(index);
		return;
	}

	throw std::logic_error("No such element!");
}

std::set<int> ShapeStorage::findByArea(double area)
{
	auto it = _indexByArea.find(area);

	if (it != _indexByArea.end())
	{
		return it->second;
	}
	else
	{
		return std::set<int>();
	}
}

std::set<int> ShapeStorage::findByName(const std::string& name)
{
	auto it = _indexByName.find(name);

	if (it != _indexByName.end())
	{
		return it->second;
	}
	else
	{
		return std::set<int>();
	}
}

bool ShapeStorage::empty() const
{
	return _defaultStorage.empty();
}

int ShapeStorage::size() const
{
	return _defaultStorage.size();
}

const std::set<int>& ShapeStorage::getIndexes() const
{
	return _indexes;
}
