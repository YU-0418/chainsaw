#ifndef CHAINSAW_HTML_TABLE_H
#define CHAINSAW_HTML_TABLE_H

#include "head.h"
#include "common.h"

namespace chainsaw
{
    // create a simple html-table
    class html_table
    {
        char symbol = 0;
        int br_number = -1;
        std::string tittle_color = "";

    public:
        html_table() {}

        html_table(char c) : symbol(c) {}

        // read symbol character from config-file
        // # symbol
        // s
        // -> modify symbol is s.
        //
        // # br
        // 100
        // -> modify each line character number is 100.
        //
        // # tittle color
        // #000000
        // ->modify title color is black(#000000).
        html_table(std::string config_file);

        // xxxSxxx -> [xxx] [xxx]
        void read_symbol_char(char c);

        // xxxxxxxxx -> xxxx<br>xxxx
        void read_bread_number(int number);

        //
        void read_tittle_color(std::string color);

        // <tr>
        //     <td>xxx</td>
        //     <td>xxx</td>
        // </tr>
        void print_tr(std::string file, std::string save_file);

        // <tr>
        //     <td colspan=2 align="center">xxx</td>
        // </tr>
        void print_tr_1td(std::string file, std::string save_file);

        void print();

    private:
        void print_error(std::string message);
    };
} // namespace chainsaw

#endif // !CHAINSAW_HTML_TABLE_H