#include "option.h"

chainsaw::option::option(string s)
{
    if (s.empty())
        return;

    if (s[0] != '-')
    {
        print_error("first character must be \'-\'");
        exit(0);
    }

    if (s.size() == 1)
    {
        print_error("no alpha input!");
        exit(0);
    }

    for (int i = 1; i < s.size(); ++i)
    {
        data.push_back(s[i]);
    }
}

void chainsaw::option::print_error(string message)
{
    chainsaw::print_error(message, "option");
}

bool chainsaw::option::is_contain(char c)
{
    return data.end() != std::find(data.begin(), data.end(), c);
}

bool chainsaw::option::is_contain(string str)
{
    bool res = true;

    for (char c : str)
    {
        res &= is_contain(c);
        if (!res)
            break;
    }

    return res;
}
