#ifndef _STRING_TOOL_BOX_
#define _STRING_TOOL_BOX_

#include <string>

namespace string_tool_box
{
	bool IsNumber(const std::string&);
	std::string IntegerTo16BitNumberText(int16_t decimal_number);
	std::string IntegerStringTo16BitNumberText(std::string decimal_number_in_text);
	
	void RemoveSpaces(std::string& str);
}

#endif // !_STRING_TOOL_BOX_
