#ifndef CHAINSAW_COMMON_STRINGTOOL_CUT_H
#define CHAINSAW_COMMON_STRINGTOOL_CUT_H

#include "../../head.h"

namespace chainsaw
{
    class cut
    {
        string ori;
        vector<string> lists;

    public:
        cut(string data);

        cut(string s, char c);

        void set_delimiter(char c);

        // select only these fields
        // f=1,2,...
        string fields(int f);

        // select only these fields
        vector<string> fields(vector<int> f);

        // select only these fields
        // list=[1,3] string
        vector<string> fields(string list);
    };

} // namespace chainsaw

#endif // !CHAINSAW_COMMON_STRINGTOOL_CUT_H