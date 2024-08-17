#include <stdio.h>
#include <stdlib.h>
#include "solve_bezout.h"
#include "get_divisors.h"
#include "bezout_solver_io.h"

int main(void)
{
    printf("This application solves polynomial equations in integer numbers.\n");
    while (1)
    {
        struct coefficients_input main_input = user_menu();
        if (main_input.quit_flag == true)
            break;
        struct solve_output answers = solve_bezout(get_divisors(main_input.coefficients[main_input.coefficients_number - 1]), main_input);
        answers_output(answers);
    }
    printf("Bye!");
}

