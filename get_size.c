#include "main.h"

int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    if (format[curr_i] == 'l')
        size = S_LONG;
    else if (format[curr_i] == 'h')
        size = S_SHORT;

    *i = (size != 0) ? curr_i : curr_i - 1;

    return size;
}
