#include "ConsoleInterface.h"
#include "TriangleParser.h"
#include "RectangleParser.h"
#include "Operations.h"
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
			deleteShape();
		}
		break;
		case 3:
		{
			printShapeStorage();
		}
		break;
		case 4:
		{
			compareRadius();
		}
		break;
		case 5:
		{
			compareArea();
		}
		break;
		case 6:
		{
			findByName();
		}
		break;
		case 7:
		{
			findByArea();
		}
		break;
		case 0:
		break;
		default:		
		{
			std::cout << "Not found this command!\n";
			std::cout << "Repeat please!\n\n";
			system("pause");
		}
		break;
		}

	}	
	
}

const char* ConsoleInterface::getShapeTypeMessage() const
{
	return "Enter the shape type (T/R): ";
}

void ConsoleInterface::printMenu() const
{
	std::cout << "Select the action you want to perform:\n";
	std::cout << "1. Create new shape.\n";
	std::cout << "2. Delete existing shape.\n";
	std::cout << "3. Print info.\n";
	std::cout << "4. Compare radiuses.\n";
	std::cout << "5. Compare area.\n";
	std::cout << "6. Find a shape by name.\n";
	std::cout << "7. Find a shape by area.\n";
	std::cout << "0. Exit.\n";
}

char ConsoleInterface::typeScanner() const
{
	char type;
	bool scanFlag = false;

	while (!scanFlag)
	{
		std::cout << getShapeTypeMessage();

		try
		{
			Scanner().Scan(std::cin, "%c", &type);

			if (type != 'T' && type != 'R')
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

void ConsoleInterface::printShapeStorage()
{
	for (auto i : _shapes.getIndexes())
	{
		try
		{
			std::cout << "Index of shape: " << i << std::endl;
			std::cout << _shapes[i].info() << std::endl;
			std::cout << "Area of shape with this index: " << _shapes[i].getArea() << std::endl;
			std::cout << "Name of shape with this index: " << _shapes[i].getName() << std::endl;
			std::cout << "==================================================\n\n";
		}
		catch (const std::exception& err)
		{
			std::cerr << err.what() << std::endl << std::endl;
		}
	}
	system("pause");
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
	try
	{
		std::unique_ptr<IShapeParser> parser(IShapeParser::createParser(typeScanner()));

		std::cout << "Enter index which you want to use with this shape: ";
		int index;
		Scanner().Scan(std::cin, "%d", &index);

		_shapes.add(parser->parse(), index);

		std::cout << std::endl;
	}
	catch (const std::exception& err)
	{
		std::cerr << err.what() << std::endl << std::endl;
	}
	system("pause");
}

void ConsoleInterface::deleteShape()
{
	try
	{
		std::cout << "Enter the index of the shape you want to remove: ";
		int index;
		Scanner().Scan(std::cin, "%d", &index);


		_shapes.erase(index);
	}
	catch (const std::exception& err)
	{
		std::cerr << err.what() << std::endl << std::endl;
	}
	system("pause");
}

void ConsoleInterface::compareArea()
{
	try
	{
		std::cout << "Enter the 2 indexes of the shapes you want to compare: ";
		int index1, index2;

		Scanner().Scan(std::cin, "%d %d", &index1, &index2);

		if (Operations().compareArea(_shapes[index1], _shapes[index2]) > 0)
		{
			std::cout << "\nThe area of the first figure is larger than the area of the second.\n\n";
		}

		if (Operations().compareArea(_shapes[index1], _shapes[index2]) < 0)
		{
			std::cout << "\nThe area of the second figure is larger than the area of the first.\n\n";
		}

		if (Operations().compareArea(_shapes[index1], _shapes[index2]) == 0)
		{
			std::cout << "\nThe areas of the figures are equal.\n\n";
		}
	}
	catch (const std::exception& err)
	{
		std::cerr << err.what() << std::endl << std::endl;
	}
	system("pause");
}

void ConsoleInterface::compareRadius()
{
	try
	{
		std::cout << "Enter the 2 indexes of the shapes you want to compare: ";
		int index1, index2;

		Scanner().Scan(std::cin, "%d %d", &index1, &index2);

		std::cout << "Difference between the radii of two shapes: " << Operations().radiusDifference(_shapes[index1], _shapes[index2]);
	}
	catch (const std::exception& err)
	{
		std::cerr << err.what() << std::endl << std::endl;
	}
	system("pause");
}

void ConsoleInterface::findByName()
{
	std::string name;
	try
	{
		std::cout << "Enter the name you want to search for: ";
		Scanner().Scan(std::cin, "%s", &name);

		std::set<int> index = _shapes.findByName(name);
		
		if (!index.empty())
		{
			for (int i : index)
			{
				std::cout << "Index of shape: " << i << std::endl;
				std::cout << _shapes[i].info() << std::endl;
				std::cout << "Name of shape with this index: " << _shapes[i].getName() << std::endl;
				std::cout << "==================================================\n\n";
			}
		}
		else
		{
			std::cout << "No such shapes.\n\n";
		}
	}
	catch (const std::exception& err)
	{
		std::cerr << err.what() << std::endl << std::endl;
	}
	system("pause");
}

void ConsoleInterface::findByArea()
{
	double area;
	try
	{
		std::cout << "Enter the area you want to search for: ";
		Scanner().Scan(std::cin, "%f", &area);

		std::set<int> index = _shapes.findByArea(area);

		if (!index.empty())
		{
			for (int i : index)
			{
				std::cout << "Index of shape: " << i << std::endl;
				std::cout << _shapes[i].info() << std::endl;
				std::cout << "Area of shape with this index: " << _shapes[i].getName() << std::endl;
				std::cout << "==================================================\n\n";
			}
		}
		else
		{
			std::cout << "No such shapes.\n\n";
		}
	}
	catch (const std::exception& err)
	{
		std::cerr << err.what() << std::endl << std::endl;
	}
	system("pause");
}