#include "ConsoleInterface.h"
#include "TriangleParser.h"
#include "RectangleParser.h"
#include "Scanner.h"
#include <memory>

void ConsoleInterface::startInterface() const
{
	int command = INT32_MAX;

	std::vector<Shape*> shapes;
	

	while (command)
	{
		printMenu();
		
		command = numberScanner();

		switch (command)
		{
		case 1:
		{
			std::unique_ptr<IShapeParser> parser(createParser(typeScanner()));
			
			shapes.push_back(parser->parse());

			std::cout << std::endl << std::endl;
		}
		break;
		case 2:
		{
			areaCalculating(shapes);
		}
		break;
		case 3:
		{

		}
		break;
		case 4:
		{

		}
		break;
		case 5:
		{

		}
		break;
		case 0:
		{

		}
		break;
		default:		
		{
			std::cout << "Not found this command!\n";
			std::cout << "Repeat please!\n\n";
		}
		break;
		}
	}
	
	shapesDeleter(shapes);
	
}

IShapeParser* ConsoleInterface::createParser(const std::string& str) const
{
	if (str == "Triangle")
	{
		return new TriangleParser();
	}

	if (str == "Rectangle")
	{
		return new RectangleParser();
	}

	throw std::invalid_argument("Bad argument!");
}

const char* ConsoleInterface::getShapeTypeMessage() const
{
	return "Enter the shape type (Triangle/Rectangle): ";
}

void ConsoleInterface::printMenu() const
{
	std::cout << "Select the action you want to perform:\n";
	std::cout << "1. Create new shape.\n";
	std::cout << "2. Calculate area.\n";
	std::cout << "3. Print info.\n";
	std::cout << "4. Compare radiuses.\n";
	std::cout << "5. Compare area.\n";
	std::cout << "0. Exit.\n";
}

std::string ConsoleInterface::typeScanner() const
{
	std::string type = "";
	bool scanFlag = false;

	while (!scanFlag)
	{
		std::cout << getShapeTypeMessage();

		try
		{
			Scanner().Scan(std::cin, "%s", &type);

			if (type != "Triangle" && type != "Rectangle")
			{
				throw std::logic_error("Uncorrect input line!");
			}
			scanFlag = true;
		}
		catch (const std::exception& err)
		{
			std::cerr << err.what() << std::endl;
			std::cout << "Repeat enter please!\n\n";
		}
	}
	
	std::cout << std::endl;

	return type;
}

void ConsoleInterface::shapesDeleter(std::vector<Shape*>& vec) const
{
	for (auto x : vec)
	{
		delete x;
	}
}

void ConsoleInterface::areaCalculating(const std::vector<Shape*>& vec) const
{
	if (vec.empty())
	{
		std::cout << "You haven't created any shapes!\n\n";
	}
	else
	{
		int number;
		std::cout << "Enter the figure number from 1 to " << vec.size() << ": ";
		
		number = numberScanner();

		if (number < 1 || number > vec.size())
		{
			std::cout << "No such element!\n";
		}
		else
		{
			try
			{
				double area = vec[number - 1]->getArea();
				std::cout << "Area of figure number " << number << ": " << area << std::endl;
			}
			catch (const std::exception& err)
			{
				std::cerr << err.what() << std::endl;
			}
		}
	}
}

int ConsoleInterface::numberScanner() const
{
	int command;
	bool scanFlag = false;

	while (!scanFlag)
	{
		try
		{
			Scanner().Scan(std::cin, "%d", &command);
			scanFlag = true;
		}
		catch (const std::exception& err)
		{
			std::cerr << err.what() << std::endl;
			std::cout << "Repeat please!\n\n";
		}
	}

	return command;
}