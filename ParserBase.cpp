#include "ParserBase.h"
#include "Rectangle.h"

Shape* ParserBase::parse() const
{
	bool scanFlag = false;
	Shape* result = nullptr;

	while (!scanFlag)
	{
		try
		{
			std::cout << getMessage() << std::endl;

			result = scan();
			scanFlag = true;
		}
		catch (const std::exception& err)
		{
			std::cerr << err.what() << std::endl;
			std::cout << "Repeat please!\n\n";
		}
	}

	return result;
}