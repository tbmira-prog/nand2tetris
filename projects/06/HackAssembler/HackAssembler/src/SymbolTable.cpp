#include "HackLanguageSpecification.h"
#include "Logger.h"
#include "SymbolTable.h"

SymbolTable::SymbolTable() : 
	symbol_table(PREDEFINED_SYMBOLS.begin(),PREDEFINED_SYMBOLS.end()),
	instruction_counter(0),
	variable_counter(16)
{}

SymbolTable::~SymbolTable()
{}

void SymbolTable::FirstPass(Parser& parser)
{
	parser.GoToBegginingOfTheFile();

	while (parser.EndOfFile() == false)
	{
		parser.NextInstruction();
		if (parser.IsLabel())
			symbol_table.insert({parser.Label(), instruction_counter--});
		instruction_counter++;
	}

	// Log
	logger::Write("symbol table after first pass");
	for (auto it = symbol_table.cbegin(); it != symbol_table.cend(); it++)
		logger::Write(it->first + '\t' + '\t' + '\t' + std::to_string(it->second));
}

int16_t SymbolTable::GetSymbolValue(const std::string& symbol)
{
	return symbol_table.at(symbol);
}

int16_t SymbolTable::AddVariable(const std::string& variable_name)
{
	symbol_table.insert({ variable_name, variable_counter });
	return variable_counter++;
}