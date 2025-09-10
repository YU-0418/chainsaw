#include "readwritefile.h"

bool chainsaw::isFileExists(const string &name)
{
    return std::ifstream(name.c_str()).good();
}

vector<string> chainsaw::read_file(string file, bool is_null_line_save)
{
    vector<string> data;

    std::ifstream rf(file, std::ios::in);
    if (!rf.good())
        print_error("no file -> [" + file + "]");

    string str;
    while (std::getline(rf, str))
    {
        if (is_null_line_save || !str.empty())
        {
            data.push_back(str);
        }
    }

    return data;
}

chainsaw::write_file::write_file(string file, bool is_exist)
{
    if (!is_exist && isFileExists(file))
    {
        print_error("the file is exists!->[" + file + "]", "write_file");
        exit(0);
    }

    wf.open(file, std::ios::out | std::ios::app);
}

chainsaw::write_file::write_file(string file, int mode)
{
    int append = mode & 1;
    int exist = mode & 2;
    if (!exist && isFileExists(file))
    {
        print_error("the file is exists!->[" + file + "]", "write_file");
        exit(0);
    }

    std::ios::openmode openmode = std::ios::out;
    if (append)
        openmode |= std::ios::app;
    wf.open(file, openmode);
}

void chainsaw::write_file::write(string data, bool line)
{
    wf << data;
    if (line)
        wf << endl;
}

void chainsaw::write_file::write(vector<string> data)
{
    for (string s : data)
    {
        wf << s << endl;
    }
}

chainsaw::write_file::~write_file()
{
    wf.close();
}
