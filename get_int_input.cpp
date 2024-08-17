#include <stdio.h>
#include "get_int_input.h"

struct user_input get_int_input()
{
    struct user_input input = {};
    while (1)
    {
        int check = 0;
        if ((check = scanf("%d", &input.value)) == 1 && getchar() == '\n')
            break;
        else if (check == -1)
        {
            input.eof_flag = true;
            return input;
        }
        else
        {
            int miss_input = 0;
            while ((miss_input = getchar()) != '\n')
                printf("%c", miss_input);
            printf(" is not a integer number, try again.\n");
        }
    }
    return input;
}
