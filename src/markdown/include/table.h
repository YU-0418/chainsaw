#ifndef CHAINSAW_MARKDOWN_TABLE_H
#define CHAINSAW_MARKDOWN_TABLE_H

#include "head.h"
#include "common.h"

namespace chainsaw
{
    class markdown_table
    {
        char symbol = 0;

    public:
        markdown_table() {}

        // read symbol.
        //
        // # symb
        // 7
        // -> symbol is 7
        markdown_table(std::string config_file);

        // read symbol
        // also you can set the symbol in config file.
        void read_symbol(char c);
        
        void print(std::string file, std::string save_file, bool has_tittle = true);

    private:
        void print_error(std::string message);
    };

} // namespace chainsaw

#endif // !CHAINSAW_MARKDOWN_TABLE_H
