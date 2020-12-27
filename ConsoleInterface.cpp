#include "ConsoleInterface.h"
#include "TriangleParser.h"
#include "RectangleParser.h"
#include "Scanner.h"
#include <memory>

void ConsoleInterface::startInterface()
{
	int command = INT32_MAX;
	

	while (command)
	{
		system("cls");
		printMenu();
		
		command = numberScanner();

		switch (command)
		{
		case 1:
		{
			addShape();
		}
		break;
		case 2:
		{
			
			system("pause");
		}
		break;
		case 3:
		{
			areaCalculating();
			system("pause");
		}
		break;
		case 4:
		{
			system("pause");
		}
		break;
		case 5:
		{
			system("pause");
		}
		break;
		case 0:
		break;
		default:		
		{
			std::cout << "Not found this command!\n";
			std::cout << "Repeat please!\n\n";
		}
		break;
		}

	}	
	
}

const char* ConsoleInterface::getShapeTypeMessage() const
{
	return "Enter the shape type (Triangle/Rectangle): ";
}

void ConsoleInterface::printMenu() const
{
	std::cout << "Select the action you want to perform:\n";
	std::cout << "1. Create new shape.\n";
	std::cout << "2. Delete existing shape.\n";
	std::cout << "3. Calculate area.\n";
	std::cout << "4. Print info.\n";
	std::cout << "5. Compare radiuses.\n";
	std::cout << "6. Compare area.\n";
	std::cout << "7. Find a shape by name.\n";
	std::cout << "8. Find a shape by area.\n";
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

void ConsoleInterface::areaCalculating(const ShapeStorage& vec) const
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
				std::cout << "Area of figure number " << number << ": " << area << std::endl << std::endl;
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
		std::cout << "Your choice: ";
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
	std::cout << std::endl;
	return command;
}

void ConsoleInterface::addShape()
{
	std::unique_ptr<IShapeParser> parser(IShapeParser::createParser(typeScanner()));

	std::cout << "Enter index which you want to use with this shape: ";
	int index;
	Scanner().Scan(std::cin, "%d", &index);

	_shapes.add(parser->parse(), index);

	std::cout << std::endl;
	system("pause");
}