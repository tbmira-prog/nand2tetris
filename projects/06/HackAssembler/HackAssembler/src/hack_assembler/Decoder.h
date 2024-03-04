#ifndef _DECODER_
#define _DECODER_

#include <string>

#include "SymbolTable.h"

namespace hack_assembler
{
	class Decoder
	{
	public:
		Decoder(SymbolTable& symbol_table);
		virtual ~Decoder();

		std::string AValue(std::string&& value);

		std::string Dest(std::string&& dst);
		std::string Comp(std::string&& cmp);
		std::string Jmp(std::string&& jmp);

	private:
		SymbolTable& symbol_table;
	};
}

#endif // _DECODER_