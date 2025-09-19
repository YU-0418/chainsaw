#include "print_err.h"

void chainsaw::print_error(std::string message, std::string class_msg)
{
    std::cerr << "ERROR:";
    if (class_msg.size() > 0)
    {
        std::cerr << "[chainsaw->" << class_msg << "]->";
    }

    std::cerr << "[" << message << "]" << std::endl;
}
