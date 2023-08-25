#include "main.h"

int get_flags(const char *format, int *i)
{
    // - + 0 # ' '
    const char FLAGS_CH[] = "-+0# ";
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE};
    
    int flags = 0;
    int curr_i = *i + 1;

    while (format[curr_i] != '\0')
    {
        int j;
        for (j = 0; j < sizeof(FLAGS_CH) - 1; j++)
        {
            if (format[curr_i] == FLAGS_CH[j])
            {
                flags |= FLAGS_ARR[j];
                break;
            }
        }

        if (j == sizeof(FLAGS_CH) - 1)
            break;

        curr_i++;
    }

    *i = curr_i - 1;

    return flags;
}
