#ifndef CHAINSAW_COMMON_OPTION_H
#define CHAINSAW_COMMON_OPTION_H

#include "../head.h"
#include "../error_message/print_err.h"

namespace chainsaw
{
    class option
    {
        vector<char> data;

    public:
        // -[char]
        option(string s);

        bool is_contain(char c);

        // Determine whether all the characters exist
        bool is_contain(string s);
        
    private:
        void print_error(string message);
    };
} // namespace chainsaw

#endif // !CHAINSAW_COMMON_OPTION_H
