#include <stdio.h>
#include "solve_bezout.h"
#include "get_divisors.h"
#include "bezout_solver_io.h"

struct solve_output solve_bezout(struct divisors_output divs, struct coefficients_input cffs)
{
    struct solve_output output = {};
    if (divs.divisors_number == 0)
    {
    output.roots_num = INF_ROOTS;
    return output;
    }
    for (int i = 0; i <= divs.divisors_number; i++)
    {
        int residue = 0;
        int b = divs.divisors[i];
        for (int j = 0; j < cffs.coefficients_number; j++)
        {
            if (j == 0)
                residue = cffs.coefficients[j];
            else
                residue = residue*b + cffs.coefficients[j];
        }
        if (residue == 0)
            output.roots[output.roots_num++] = b;
    }
    return output;
}
