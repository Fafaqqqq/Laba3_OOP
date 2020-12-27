#pragma once
#include "IShapeParser.h"
#include "ShapeStorage.h"
#include <vector>

class ConsoleInterface
{
public:
	void startInterface();
private:
	const char* getShapeTypeMessage() const;
	void printMenu() const;
	std::string typeScanner() const;
	void areaCalculating(const ShapeStorage& vec) const;
	int numberScanner() const;
	void addShape();

	ShapeStorage _shapes;
};