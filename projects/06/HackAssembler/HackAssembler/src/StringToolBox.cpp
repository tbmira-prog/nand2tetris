#include <algorithm>
#include <bitset>

#include "StringToolBox.h"

//const TWO_POWER[] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536 };

bool string_tool_box::IsNumber(const std::string& str)
{
	for (auto it = str.cbegin(); it < str.cend(); it++)
		if (!( *it >= '0' && *it <= '9'))// || *it == '.'))
			return false;

	return true;
}

std::string string_tool_box::IntegerTo16BitNumberText(int16_t integer)
{
	std::bitset<15> binary(integer);
	return binary.to_string();
}

std::string string_tool_box::IntegerStringTo16BitNumberText(std::string decimal_number_in_text)
{
	auto n = std::stoi(decimal_number_in_text);
	return IntegerTo16BitNumberText(n);
}

void string_tool_box::RemoveSpaces(std::string& str)
{
	auto new_end = std::remove_if(str.begin(), str.end(), isspace);
	str = std::string(str.begin(), new_end);
}