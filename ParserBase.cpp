#include "ParserBase.h"
#include "Rectangle.h"

std::unique_ptr<Shape> ParserBase::parse() const
{
	bool scanFlag = false;
	std::unique_ptr<Shape> result = nullptr;

	while (!scanFlag)
	{
		try
		{
			std::cout << getMessage() << std::endl;

			return std::make_unique<Shape>(scan());
			scanFlag = true;
		}
		catch (const std::exception& err)
		{
			std::cerr << err.what() << std::endl;
			std::cout << "Repeat please!\n\n";
		}
	}

	
}