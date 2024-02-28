#include "HackAssembler.h"
#include "Logger.h"

HackAssembler::HackAssembler(std::string file_path) : 
	parser(file_path),
	symbol_table(), 
	decoder(symbol_table), 
	binary_file()
{
	std::string binary_file_path(file_path);
	binary_file_path.replace(binary_file_path.end() - 3, binary_file_path.end(), "hack");
	binary_file.open(binary_file_path, std::ios::out);
	
	logger::Write("output file: " + binary_file_path);
}

HackAssembler::~HackAssembler()
{
	if (binary_file.is_open())
		binary_file.close();
}

void HackAssembler::GenerateBinaryCode()
{
	symbol_table.FirstPass(parser);

	logger::Write("\nConversion");
	parser.GoToBegginingOfTheFile();
	while (parser.EndOfFile() == false)
	{
		parser.NextInstruction();
		
		std::string binary_command("");
		if (parser.IsAInstruction())
			binary_command = "0" + decoder.AValue(parser.AValue());
		else if (parser.IsCInstruction())
		{
			binary_command = "111" +
				decoder.Comp(parser.Computation()) +
				decoder.Dest(parser.Destination()) +
				decoder.Jmp(parser.Jump());
		}
		
		if (binary_command != "")
		{
			binary_file << binary_command << '\n';
		
			logger::Write(parser.Instruction() + '\t' + '\t' + " => " + '\t' + binary_command + '\r');
		}
	}
}