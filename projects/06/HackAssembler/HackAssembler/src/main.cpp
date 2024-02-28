#include <exception>
#include "HackAssembler.h"

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		try
		{
			HackAssembler assembler(argv[1]);
			assembler.GenerateBinaryCode();
		}
		catch (std::exception exception)
		{
			logger::Write(exception);
		}
	}
	else
		logger::Write("Need a file as program argument");
	
	return 0;
}