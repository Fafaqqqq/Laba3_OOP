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
	char typeScanner() const;
	int numberScanner() const;
	void addShape();
	void deleteShape();
	void printShapeStorage();
	void compareArea();
	void compareRadius();
	void findByName();
	void findByArea();

	ShapeStorage _shapes;
};