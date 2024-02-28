#ifndef _HACK_ASSEMBLER_
#define _HACK_ASSEMBLER_

#include <fstream>
#include <string>

#include "Decoder.h"
#include "Logger.h"
#include "Parser.h"
#include "SymbolTable.h"

class HackAssembler
{
public:
	HackAssembler(std::string file_path);
	virtual ~HackAssembler();

	void GenerateBinaryCode();
private:
	Parser parser;
	SymbolTable symbol_table;
	Decoder decoder;

	std::ofstream binary_file;

};

#endif // _HACK_ASSEMBLER_
