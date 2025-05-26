#include "../table.h"

void chainsaw::html_table::print_error(string message)
{
    chainsaw::print_error(message, "html_table");
}

chainsaw::html_table::html_table(string config_file)
{
    ReadConfigMessage rcm(config_file);
    vector<string> data;

    data = rcm.get_value_prefix("symb");

    if (data.empty())
    {
        print_error("config read error.There is no symbol after # symbol");
        exit(0);
    }

    symbol = data[0][0];

    data = rcm.get_value_prefix("br");
    if (data.empty())
    {
        print_error("config read error.There is no number after # br");
        exit(0);
    }
    br_number = std::stoi(data[0]);

    data = rcm.get_value_prefix("# tittle color");
    if (data.empty())
    {
        print_error("config read error.There is no color after # tittle color");
        exit(0);
    }

    tittle_color = data[0];
}

void chainsaw::html_table::read_symbol_char(char c)
{
    symbol = c;
}

void chainsaw::html_table::read_bread_number(int number)
{
    br_number = number;
}

void chainsaw::html_table::read_tittle_color(string color)
{
    tittle_color = color;
}

string addbr(string s, int number)
{
    string res;
    int num = 0;

    int f_chinese = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        ++num;
        res += s[i];

        // ¼ÇÂ¼ÖÐÎÄ
        if (f_chinese || (unsigned int)s[i] > 0x7f)
        {
            f_chinese = 1 - f_chinese;
        }

        if (num == number)
        {
            if (!f_chinese)
            {
                res += "<br>";
                num = 0;
            }
            else
            {
                --num;
                continue;
            }
        }
    }
    return res;
}

void chainsaw::html_table::print_tr(string file, string save_file)
{

    vector<string> save_data;

    vector<string> data = read_file(file);

    for (string s : data)
    {
        // <tr>
        save_data.push_back("<tr>");

        chainsaw::stringtool tool(s);

        vector<int> pos = tool.find_all(symbol);
        if (pos.empty())
        {
            print_error("no symbol");
            break;
        }

        vector<string> s_data = tool.split(pos);

        for (string &s : s_data)
        {
            s = stringtool(s).trimmed();
        }

        for (string s : s_data)
        {
            save_data.push_back("<td>" + addbr(s, br_number) + "</td>");
        }

        // </tr>
        save_data.push_back("</tr>");
    }

    write_file(save_file, 0b10).write(save_data);
}

void chainsaw::html_table::print_tr_1td(string file, string save_file)
{
    vector<string> save_data;

    vector<string> data = read_file(file);

    for (string s : data)
    {
        // <tr>
        save_data.push_back("<tr>");

        save_data.push_back("<td colspan=2 align=\"center\" bgcolor=\"" + tittle_color + "\">" + s + "</td>");

        // </tr>
        save_data.push_back("</tr>");
    }

    write_file(save_file, 0b10).write(save_data);
}

void chainsaw::html_table::print()
{
    PRP(symbol);
    PRP(br_number);
}
