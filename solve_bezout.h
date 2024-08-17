#ifndef SOLVE_BEZOUT_H_INCLUDED
#define SOLVE_BEZOUT_H_INCLUDED

const int INF_ROOTS = -1;
const int MAX_ROOTS = 10000;

struct solve_output{
    int roots[MAX_ROOTS];
    int roots_num;
};

struct solve_output solve_bezout(struct divisors_output divs, struct coefficients_input cffs);

#endif // SOLVE_BEZOUT_H_INCLUDED
