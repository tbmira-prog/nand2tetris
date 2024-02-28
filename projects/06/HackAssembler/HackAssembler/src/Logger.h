#ifndef _LOGGER_
#define _LOGGER_

#include <exception>
#include <string>

namespace logger
{
	void Write(std::string text);
	void Write(std::exception exception);

//	void WriteTitle(std::string text);
}

#endif // _LOGGER_