#include "chartool.h"

bool chainsaw::is_upper_char(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool chainsaw::is_lower_char(char c)
{
    return c >= 'a' && c <= 'z';
}

char chainsaw::to_upper(char c)
{
    return is_lower_char(c) ? c - ' ' : c;
}

char chainsaw::to_lower(char c)
{
    return is_upper_char(c) ? c + ' ' : c;
}

bool chainsaw::is_letter(char c)
{
    return is_lower_char(c) || is_upper_char(c);
}

bool chainsaw::is_number(char c)
{
    return c >= '0' && c <= '9';
}

bool chainsaw::is_word(char c)
{
    return is_letter(c) || is_number(c) || c == '.' || c == '_' || c == '-';
}