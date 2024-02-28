#include "Decoder.h"

#include <stdexcept>

#include "HackLanguageSpecification.h"
#include "StringToolBox.h"

Decoder::Decoder(SymbolTable& symbol_table_ref) : symbol_table(symbol_table_ref)
{}

Decoder::~Decoder()
{}

std::string Decoder::AValue(std::string&& value)
{
	if (string_tool_box::IsNumber(value))
		return string_tool_box::IntegerStringTo16BitNumberText(value);
	else
	{
		try
		{
			return string_tool_box::IntegerTo16BitNumberText(symbol_table.GetSymbolValue(value));
		}
		catch (std::out_of_range) // TODO Melhorar isso e Throw para AInstruction
		{
			return string_tool_box::IntegerTo16BitNumberText(symbol_table.AddVariable(value));
		}
	}	
}

std::string Decoder::Dest(std::string&& dst)
{
	try
	{
		return DESTINATION.at(dst);
	}
	catch (std::out_of_range)
	{
		throw std::runtime_error("Unable to decode the Destination of C Instruction: " + dst);
	}
}

std::string Decoder::Comp(std::string&& cmp)
{
	try
	{
		return COMPUTATION.at(cmp);
	}
	catch (std::out_of_range)
	{
		throw std::runtime_error("Unable to decode the Computation of C Instruction: " + cmp);
	}
}

std::string Decoder::Jmp(std::string&& jmp)
{
	try
	{
		return JUMP.at(jmp);
	}
	catch(std::out_of_range)
	{
		throw std::runtime_error("Unable to decode the Jump of C Instruction: " + jmp);
	}
}