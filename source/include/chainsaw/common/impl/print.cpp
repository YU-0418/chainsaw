#include "../print.h"

void head()
{
    cout << "[ chainsaw ]";
}

void chainsaw::print_chainsaw_head(char c)
{
    head();

    if (c == -1)
    {
        cout << "^_^ ";
    }
    else if (c == -2)
    {
        cout << "v_v ";
    }
    else
    {
        cout << " -" << c << " ";
    }
}

string convert2number(int i)
{
    string res = " -- ";

    while (i >= 1000)
    {
        i -= 1000;
    }

    if (i < 10)
    {
        res = "  " + std::to_string(i) + " ";
    }
    else if (i < 100)
    {
        res = " " + std::to_string(i) + " ";
    }
    else
    {
        res = std::to_string(i) + " ";
    }

    return res;
}

void chainsaw::print_chainsaw_number(int number)
{
    head();
    cout << convert2number(number);
}

void chainsaw::print_tips(string tips)
{
    cout << tips << ":";
}
