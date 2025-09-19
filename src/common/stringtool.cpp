#include "stringtool.h"

void chainsaw::stringtool::print_error(std::string message)
{
    chainsaw::print_error(message, "stringtool");
}

template <typename T>
int find(std::string data, T t)
{
    int pos = data.find(t);
    return pos == std::string::npos ? -1 : pos;
}

int chainsaw::stringtool::find(char c)
{
    return ::find(data, c);
}

int chainsaw::stringtool::find(std::string s)
{
    return ::find(data, s);
}

std::vector<int> chainsaw::stringtool::find_all(char c)
{
    std::vector<int> res;
    for (int i = 0; i < data.size(); ++i)
    {
        if (c == data[i])
            res.push_back(i);
    }
    return res;
}

std::string chainsaw::stringtool::substr(int beginpos, int endpos)
{
    std::string result = "";
    if (endpos > beginpos)
    {
        result = data.substr(beginpos, endpos - beginpos);
    }
    else
    {
        // update
        print_error("end-position < begin-position");
    }
    return result;
}

std::string chainsaw::stringtool::split(int pos, int num)
{
    std::string result = "";
    if (pos >= data.size())
    {
        print_error("position > data.size()");
    }
    switch (num)
    {
    case 0:
        result = substr(0, pos);
        break;
    case 1:
        result = substr(pos + 1, data.size());
        break;
    default:
        print_error("invalid-num");
        break;
    }
    return result;
}

std::vector<std::string> chainsaw::stringtool::split(std::vector<int> pos)
{
    std::vector<std::string> res;

    if (pos.empty())
        return res;

    int last = -1;
    for (int i : pos)
    {
        res.push_back(substr(last + 1, i));
        last = i;
    }

    res.push_back(substr(last + 1, data.size()));

    return res;
}

std::string chainsaw::stringtool::replace(int pos, char value)
{
    std::string res = data;
    res[pos] = value;
    return res;
}

std::vector<std::string> chainsaw::stringtool::splitWord()
{
    std::vector<std::string> res;

    std::string buff = "";

    int n = data.size();
    for (int i = 0; i < n; ++i)
    {
        char c = data[i];
        if (is_word(c))
        {
            buff += c;
        }

        if (!is_word(c) && !buff.empty() || i == n - 1)
        {
            res.push_back(buff);
            res.clear();
        }
    }

    return res;
}

std::string chainsaw::to_upper(std::string str)
{
    std::string result = "";
    for (char c : str)
    {
        result += chainsaw::to_upper(c);
    }
    return result;
}

std::string chainsaw::to_lower(std::string str)
{
    std::string result = "";
    for (char c : str)
    {
        result += chainsaw::to_lower(c);
    }
    return result;
}

std::string chainsaw::stringtool::trimmed()
{
    int pos1 = data.find_first_not_of(' ');
    int pos2 = data.find_last_not_of(' ');
    return substr(pos1, pos2 + 1);
}

std::string chainsaw::stringtool::left(int n)
{
    return substr(0, n);
}

std::string chainsaw::stringtool::right(int n)
{
    return substr(data.size() - n, data.size());
}

char chainsaw::stringtool::head()
{
    return data[0];
}

char chainsaw::stringtool::tail()
{
    return data.back();
}

bool chainsaw::stringtool::startsWith(std::string s)
{
    return s == left(s.size());
}

bool chainsaw::stringtool::endsWith(std::string s)
{
    return s == right(s.size());
}

int chainsaw::stringtool::size()
{
    return data.size();
}

void chainsaw::stringtool::remove_head(int n)
{
    data.erase(data.begin(), data.begin() + n);
}

void chainsaw::stringtool::remove_tail(int n)
{
    data.erase(data.begin() + n, data.end());
}

void chainsaw::stringtool::print()
{
    SafeLogger::instance().single(data);
}

std::string chainsaw::stringtool::operator()()
{
    return data;
}
