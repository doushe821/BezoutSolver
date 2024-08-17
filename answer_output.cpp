#include <stdio.h>
#include "solve_bezout.h"

void answers_output(const struct solve_output ans)
{
    if (ans.roots_num == 0)
        printf("Equation has no roots.\n");
    else if (ans.roots_num == INF_ROOTS)
        printf("Equation has infinite roots.\n");
    else
    {
        printf("Equation has %d integer roots.\n", ans.roots_num);
        for (int i = 0; i < ans.roots_num; i++)
            printf("Root %d: %d\n", i+1, ans.roots[i]);
    }
}


