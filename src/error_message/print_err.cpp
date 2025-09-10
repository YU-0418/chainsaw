#include "print_err.h"

void chainsaw::print_error(string message, string class_msg)
{
    cerr << "ERROR:";
    if (class_msg.size() > 0)
    {
        cerr << "[chainsaw->" << class_msg << "]->";
    }

    cerr << "[" << message << "]" << endl;
}
