#ifndef _PARSER_
#define _PARSER_

#include <fstream>
#include <string>

namespace hack_assembler
{
	class Parser
	{
	public:
		Parser(std::string file_path);
		virtual ~Parser();

		void GoToBegginingOfTheFile();
		void NextInstruction();
		void NextLine();
		inline bool EndOfFile() const { return assembly_file.eof(); }

		std::string Instruction() const { return instruction; }

		inline bool IsAInstruction() const { return instruction[0] == '@'; }
		std::string AValue() const;

		bool IsCInstruction() const;
		std::string Destination() const;
		std::string Computation() const;
		std::string Jump() const;

		inline bool IsLabel() const { return instruction[0] == '(' && *(instruction.cend() - 1) == ')'; }
		inline std::string Label() const { return std::string(instruction.cbegin() + 1, instruction.cend() - 1); }

		bool IsThereAComment() const;
		std::string Comment() const;

	private:
		std::ifstream assembly_file;
		std::string instruction;
		std::string comment;

		unsigned int file_line_counter;

		void RemoveCommentsFromInstruction();
	};
}

#endif // _PARSER_