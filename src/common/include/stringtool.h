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
        string data;

    public:
        stringtool(string s) : data(s) {}

        // find c in the data
        // if find c, return c-position
        // else return -1
        //
        // res <- return value
        // if(!~res) <- not find
        int find(char c);

        // find string in the data
        // if fidn, return s-position
        // else return -1
        //
        // res <- return value
        // if(!~res) <- not find
        int find(string s);

        // find all character c
        vector<int> find_all(char c);

        // [beginpos, endpos)
        string substr(int beginpos, int endpos);

        // [0,pos)&&(pos, size]
        // num:
        // 0->[0,pos)
        // 1->(pos, size]
        string split(int pos, int num);

        //
        vector<string> split(vector<int> pos);

        // xxx[p]xxx -> xxx[v]xxx
        // pos:p-position
        // value:v
        string replace(int pos, char value);

        // [hello world!] ->
        // [hello][world][!]
        vector<string> splitWord();

        // [space]xxx[space] -> xxx
        string trimmed();

        // [abcdxxx],n=5 -> [abcdx]
        string left(int n = 0);

        // [abcdxxx],n=4 -> [dxxx]
        string right(int n = 0);

        //
        char head();

        //
        char tail();

        //
        bool startsWith(string s);

        //
        bool endsWith(string s);

        //
        int size();

        // abcd,n=2 -> cd
        void remove_head(int n = 1);

        void remove_tail(int n = 1);

        // print ctor-input data
        void print();

        // return original data
        string operator()();

    private:
        void print_error(string message);
    };

    // aBC -> ABC
    string to_upper(string str);

    // Abc -> abc
    string to_lower(string str);

} // namespace chainsaw

#endif // !CHAINSAW_COMMON_STRINGTOOL_STRINGTOOL_H
