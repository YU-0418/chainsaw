#ifndef CHAINSAW_COMMON_PRINT_H
#define CHAINSAW_COMMON_PRINT_H

#include "head.h"

namespace chainsaw
{
    void print_chainsaw_head(char symbol = '-');

    void print_chainsaw_vector_head();

    void print_chainsaw_number(int number);

    template <typename T>
    void print_message(T message)
    {
        cout << "[" << message << "]" << endl;
    }

    void print_tips(string tips);

    template <typename T>
    void print(T data, string tips = "")
    {
        print_chainsaw_head();
        if (!tips.empty())
        {
            print_tips(tips);
        }
        print_message(data);
    }

    template <>
    inline void print(const char *data, string tips)
    {
        if (string(data) == "hi")
        {
            print_chainsaw_head(-1);
        }
        else if (string(data) == "ih")
        {
            print_chainsaw_head(-2);
        }
        else
        {
            print_chainsaw_head();
        }

        if (!tips.empty())
        {
            print_tips(tips);
        }
        print_message(data);
    }

    template <>
    inline void print(bool data, string tips)
    {
        print_chainsaw_head();
        if (!tips.empty())
        {
            print_tips(tips);
        }
        cout << (data ? "True" : "False") << endl;
    }

    template <typename T>
    void print(vector<T> data, string tips = "")
    {
        print_chainsaw_head('l');
        if (!tips.empty())
        {
            print_tips(tips);
            cout << endl;
        }

        int num = 0; 
        for (T t : data)
        {
            print_chainsaw_number(num++);
            print_message(t);
        }
    }

} // namespace chainsaw

#ifndef PR
#define PR(data) chainsaw::print(#data)
#endif // !PR

#ifndef PRP
#define PRP(data) chainsaw::print(data, #data)
#endif // !PRP

#ifndef PRP2
#define PRP2(data, tips) chainsaw::print(data, #tips)
#endif // !PRP2

#endif // !CHAINSAW_COMMON_PRINT_H
