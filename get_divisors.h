#ifndef GET_DIVISORS_H_INCLUDED
#define GET_DIVISORS_H_INCLUDED

const int MAX_DIVISORS = 10000;

struct divisors_output{
    int divisors[MAX_DIVISORS];
    int divisors_number;
};

struct divisors_output get_divisors (int dividend);

#endif // GET_DIVISORS_H_INCLUDED
