#include "../cut.h"

chainsaw::cut::cut(string data) : ori(data)
{
}

chainsaw::cut::cut(string s, char c)
{
    ori = s;
    set_delimiter(c);
}

vector<string> cut_string(string s, char c)
{
    vector<string> res;
    string buffer;
    for (char t : s)
    {
        if (t == c)
        {
            if (!buffer.empty())
            {
                res.push_back(buffer);
                buffer.clear();
            }
        }
        else
        {
            buffer += t;
        }
    }

    if (!buffer.empty())
    {
        res.push_back(buffer);
    }
    return res;
}

void chainsaw::cut::set_delimiter(char c)
{
    lists = cut_string(ori, c);
}

string chainsaw::cut::fields(int f)
{
    string res;

    if (f > 0 && f <= lists.size())
    {
        res = lists[f - 1];
    }

    return res;
}

vector<string> chainsaw::cut::fields(vector<int> f)
{
    vector<string> res;
    for (int i : f)
    {
        res.push_back(fields(i));
    }
    return res;
}

vector<string> chainsaw::cut::fields(string list)
{
    vector<string> res;

    vector<string> t = cut_string(list, ',');

    vector<int> nums;
    for (string s : t)
    {
        nums.push_back(std::stoi(s));
    }

    return fields(nums);
}
