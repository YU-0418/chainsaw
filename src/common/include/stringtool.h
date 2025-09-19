#ifndef CHAINSAW_COMMON_STRINGTOOL_STRINGTOOL_H
#define CHAINSAW_COMMON_STRINGTOOL_STRINGTOOL_H

#include "head.h"
#include "error_message.h"
#include "chartool.h"
#include "print.h"

namespace chainsaw
{
    class stringtool
    {
        std::string data;

    public:
        stringtool(std::string s) : data(s) {}

        // find c in the data
        // if find c, return c-position
        // else return -1
        //
        // res <- return value
        // if(!~res) <- not find
        int find(char c);

        // find std::string in the data
        // if fidn, return s-position
        // else return -1
        //
        // res <- return value
        // if(!~res) <- not find
        int find(std::string s);

        // find all character c
        std::vector<int> find_all(char c);

        // [beginpos, endpos)
        std::string substr(int beginpos, int endpos);

        // [0,pos)&&(pos, size]
        // num:
        // 0->[0,pos)
        // 1->(pos, size]
        std::string split(int pos, int num);

        //
        std::vector<std::string> split(std::vector<int> pos);

        // xxx[p]xxx -> xxx[v]xxx
        // pos:p-position
        // value:v
        std::string replace(int pos, char value);

        // [hello world!] ->
        // [hello][world][!]
        std::vector<std::string> splitWord();

        // [space]xxx[space] -> xxx
        std::string trimmed();

        // [abcdxxx],n=5 -> [abcdx]
        std::string left(int n = 0);

        // [abcdxxx],n=4 -> [dxxx]
        std::string right(int n = 0);

        //
        char head();

        //
        char tail();

        //
        bool startsWith(std::string s);

        //
        bool endsWith(std::string s);

        //
        int size();

        // abcd,n=2 -> cd
        void remove_head(int n = 1);

        void remove_tail(int n = 1);

        // print ctor-input data
        void print();

        // return original data
        std::string operator()();

    private:
        void print_error(std::string message);
    };

    // aBC -> ABC
    std::string to_upper(std::string str);

    // Abc -> abc
    std::string to_lower(std::string str);

} // namespace chainsaw

#endif // !CHAINSAW_COMMON_STRINGTOOL_STRINGTOOL_H
