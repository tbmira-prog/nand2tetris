#ifndef _SYMBOL_TABLE_
#define _SYMBOL_TABLE_

#include <stdint.h>

#include <map>
#include <string>

#include "Parser.h"

namespace hack_assembler
{
	class SymbolTable
	{
	public:
		SymbolTable();
		virtual ~SymbolTable();

		void FirstPass(Parser& parser);

		int16_t GetSymbolValue(const std::string& symbol);
		int16_t AddVariable(const std::string& variable_name); // TODO retornar par key value

	private:
		std::map<std::string, int16_t> symbol_table;

		int16_t instruction_counter;
		int16_t variable_counter;
	};
}

#endif // _SYMBOL_TABLE_