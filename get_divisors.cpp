#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "get_divisors.h"

struct divisors_output get_divisors (int dividend)
{
    struct divisors_output divs = {};
    int d_num = 0;
    int abs_dividend = abs(dividend);
    for (int i = 1; i*i <= abs_dividend; i++)
    {
        if (abs_dividend % i == 0)
        {
            if(i*i == abs_dividend)
            {
                divs.divisors[d_num++] = i;
                divs.divisors[d_num++] = -i;
            }
            else
            {
                divs.divisors[d_num++] = i;
                divs.divisors[d_num++] = -i;
                divs.divisors[d_num++] = dividend/i;
                divs.divisors[d_num++] = -dividend/i;
            }
        }
    }
    divs.divisors_number = d_num;
    return divs;
}
