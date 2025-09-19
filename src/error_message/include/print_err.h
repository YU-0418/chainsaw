#ifndef CHAINSAW_ERRORRMESSAGE_PRINTTERR_H
#define CHAINSAW_ERRORRMESSAGE_PRINTTERR_H

#include "head.h"

namespace chainsaw
{
    // "ERROR: ([chainsaw->class_msg]->)[message]"
    void print_error(std::string message, std::string class_msg = "");

} // namespace chainsaw

#endif // !CHAINSAW_ERRORRMESSAGE_PRINTTERR_H
