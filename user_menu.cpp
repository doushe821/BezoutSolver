#include <stdio.h>
#include "get_divisors.h"
#include "bezout_solver_io.h"
#include "get_int_input.h"

struct coefficients_input get_coefficients(int n);

struct coefficients_input user_menu()
{
    printf("%s", MENU_INPUT);
    int ch = 0;
    struct coefficients_input menu_input = {};
    while ((ch = getchar()) != 'q')
    {
        if (ch == '\n')
        {
            printf("%s%s", INVALID_IN, MENU_INPUT);
            continue;
        }
        if (ch == 's' && getc(stdin) == '\n')
        {
            printf("Enter number of coefficients:\n");
            struct user_input degree_input = get_int_input();
            if (degree_input.value == 0)
            {
                printf("Equation has no roots.\n");
                printf("%s", MENU_INPUT);
                continue;
            }
            int c_num = degree_input.value;
            printf("Enter integer coefficients:\n");
            menu_input = get_coefficients(c_num);
            if (menu_input.eof_flag == true)
            {
                printf("%s", MENU_INPUT);
                continue;
            }
            return menu_input;
        }
        else
        {
            printf("%s%s", INVALID_IN, MENU_INPUT);
            if (ch != EOF)
            {
                while (getchar() != '\n')
                    continue;
            }
        }
    }
    menu_input.quit_flag = true;
    return menu_input;
}

struct coefficients_input get_coefficients(int n)
{
    struct coefficients_input get_cfs_output = {};
    int i = 0;
    while (get_cfs_output.coefficients_number < n)
    {
        struct user_input get_input = get_int_input();
        if (get_input.eof_flag == true)
        {
            get_cfs_output.eof_flag = true;
            return get_cfs_output;
        }
        get_cfs_output.coefficients[get_cfs_output.coefficients_number++] = get_input.value;
    }
    for (int j = 0; j < get_cfs_output.coefficients_number; j++)
    {
        switch (get_cfs_output.coefficients[j])
        {
            case 1:
            {
                printf("+x^%d", get_cfs_output.coefficients_number - j - 1);
                break;
            }
            case -1:
            {
                printf("-x^%d", get_cfs_output.coefficients_number - j - 1);
                break;
            }
            case 0:
            {
                printf("+0");
                break;
            }
            default:
            {
                printf("%+dx^%d", get_cfs_output.coefficients[j], get_cfs_output.coefficients_number - j - 1);
                break;
            }
        }
    }
    printf("=0\n");
    int last_c = 0;
    i = 0;
    while (last_c == 0)
    {
        get_cfs_output.coefficients_number -= 1*i++;
        last_c = get_cfs_output.coefficients[get_cfs_output.coefficients_number - 1];
    }
    return get_cfs_output;
}
