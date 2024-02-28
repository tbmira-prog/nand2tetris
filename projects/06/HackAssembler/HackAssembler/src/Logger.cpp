#include "Logger.h"

#ifdef _DEBUG

#include <iostream>

void logger::Write(std::string text)
{
	std::cout << "log :: " << text << std::endl;
}

void logger::Write(std::exception exception)
{
	std::cout << "log :: error :: " << exception.what() << std::endl;
}

#else

void logger::Write(std::string text)
{}

void logger::Write(std::exception exception)
{}

#endif // _DEBUG