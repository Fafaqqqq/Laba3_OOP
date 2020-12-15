#pragma once
#include "IShapeParser.h"
#include <vector>

class ConsoleInterface
{
public:
	void startInterface() const;
private:
	IShapeParser* createParser(const std::string& str) const;
	const char* getShapeTypeMessage() const;
	void printMenu() const;
	std::string typeScanner() const;
	void shapesDeleter(std::vector<Shape*>& vec) const;
	void areaCalculating(const std::vector<Shape*>& vec) const;
	int numberScanner() const;
};