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
        string tittle_color = "";

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
        html_table(string config_file);

        // xxxSxxx -> [xxx] [xxx]
        void read_symbol_char(char c);

        // xxxxxxxxx -> xxxx<br>xxxx
        void read_bread_number(int number);

        //
        void read_tittle_color(string color);

        // <tr>
        //     <td>xxx</td>
        //     <td>xxx</td>
        // </tr>
        void print_tr(string file, string save_file);

        // <tr>
        //     <td colspan=2 align="center">xxx</td>
        // </tr>
        void print_tr_1td(string file, string save_file);

        void print();

    private:
        void print_error(string message);
    };
} // namespace chainsaw

#endif // !CHAINSAW_HTML_TABLE_H