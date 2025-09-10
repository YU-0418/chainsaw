#ifndef CHAINSAW_COMMON_COMMAND_H
#define CHAINSAW_COMMON_COMMAND_H

#include "head.h"
#include "error_message.h"
#include "option.h"
#include "stringtool.h"
#include "print.h"

namespace chainsaw
{
    class command
    {
        struct node
        {
            string value;
            vector<string> arg;

            // mode 0 -> arg
            // mode 1 -> value=arg
            int mode = 0;

            bool empty();

            void clear();
        };

        vector<node> all;

    public:
        // --word=xxx -> [word,xxx]
        // -C[space]xxx -> [C,xxx]
        // -Cxxx -> [C,xxx]
        // -c=xxx -> [c,xxx]
        command(string s);

        command(vector<string> arg);

        //
        bool find(string option);

        //
        vector<string> get_option_arg(string option);

        // print all command
        void print();

    private:
        void parse_string_list(vector<string> data);

        void add_data(node &buffer);

        void print_error(string message);
    };
} // namespace chainsaw

#endif // !CHAINSAW_COMMON_COMMAND_H
