#ifndef CHAINSAW_COMMON_CHARTOOL_H
#define CHAINSAW_COMMON_CHARTOOL_H

namespace chainsaw
{
    bool is_upper_char(char c);
    bool is_lower_char(char c);

    // [a,z] -> [A,Z]
    char to_upper(char c);

    // [A,Z] -> [a,z]
    char to_lower(char c);

    // [a,z]&[A,Z]?
    bool is_letter(char c);

    // [0,9]?
    bool is_number(char c);

    // letter or number or (-_.)
    bool is_word(char c);
    
} // namespace chainsaw

#endif // !CHAINSAW_COMMON_CHARTOOL_H
