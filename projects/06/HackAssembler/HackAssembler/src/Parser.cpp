#include "Parser.h"

#include <algorithm>

#include "Logger.h"
#include "StringToolBox.h"

Parser::Parser(std::string file_path) :
	assembly_file(),
	instruction(""),
	file_line_counter(0)
{
	std::string extention(std::end(file_path)-3, std::end(file_path));
	if (extention == "asm")
		assembly_file.open(file_path, std::ios::in);
	
	if (assembly_file.is_open() == false)
		throw std::exception("Can't open the file");

	logger::Write("input file: " + file_path);
}

Parser::~Parser()
{
	if (assembly_file.is_open())
		assembly_file.close();
}

void Parser::GoToBegginingOfTheFile()
{
	assembly_file.clear();
	assembly_file.seekg(0);
	file_line_counter = 0;
}

void Parser::NextInstruction()
{
	instruction = "";
	do
	{
		NextLine();

		RemoveCommentsFromInstruction();
		string_tool_box::RemoveSpaces(instruction);
	} while ((instruction == "") && !EndOfFile());
}

void Parser::NextLine()
{
	std::getline(assembly_file, instruction);
	file_line_counter++;
}

std::string Parser::AValue() const
{
	if (IsAInstruction())
		return std::string(++instruction.cbegin(), instruction.cend());
	else
		return "";
}

bool Parser::IsCInstruction() const
{
	auto equal_place = std::find(instruction.cbegin(), instruction.cend(), '=');
	auto semicolons_place = std::find(instruction.cbegin(), instruction.cend(), ';');
	return equal_place != instruction.cend() || semicolons_place != instruction.cend();
}

std::string Parser::Destination() const
{
	if (IsCInstruction())
	{
		auto equal_place = std::find(instruction.cbegin(), instruction.cend(), '=');
		if (equal_place != instruction.cend())
			return std::string(instruction.cbegin(), equal_place);
	}

	return "";
}

std::string Parser::Computation() const
{
	if (IsCInstruction())
	{
		auto equal_place = std::find(instruction.cbegin(), instruction.cend(), '=');
		auto semicolons_place = std::find(instruction.cbegin(), instruction.cend(), ';');

		// dest=comp
		if (equal_place != instruction.cend() && semicolons_place == instruction.cend())
			return std::string(equal_place + 1, instruction.cend());
		// comp;jmp
		else if (equal_place == instruction.cend() && semicolons_place != instruction.cend())
			return std::string(instruction.cbegin(), semicolons_place);
		// dest=comp;jmp
		else if (equal_place != instruction.cend() && semicolons_place != instruction.cend())
			return std::string(equal_place + 1, semicolons_place);
		// TODO throw?
		else
			return "";
	}

	return "";
}

std::string Parser::Jump() const
{
	if (IsCInstruction())
	{
		auto semicolons_place = std::find(instruction.cbegin(), instruction.cend(), ';');
		if (semicolons_place != instruction.cend())
			return std::string(semicolons_place + 1, instruction.cend());
	}

	return "";
}

bool Parser::IsThereAComment() const
{
	auto slash_slash_place = std::find(instruction.cbegin(), instruction.cend(), '/');
	return slash_slash_place != instruction.cend() && *slash_slash_place == *(++slash_slash_place);
}

std::string Parser::Comment() const
{
	if (IsThereAComment())
	{
		auto slash_slash_place = std::find(instruction.cbegin(), instruction.cend(), '/');
		return std::string(slash_slash_place+2, instruction.cend());
	}
	else
		return comment;
}

void Parser::RemoveCommentsFromInstruction()
{
	if (IsThereAComment())
	{
		auto slash_slash_place = std::find(instruction.begin(), instruction.end(), '/');
		comment = std::string(slash_slash_place + 2, instruction.end());
		instruction = std::string(instruction.begin(), slash_slash_place);
	}
}