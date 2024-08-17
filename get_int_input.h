#ifndef GET_INT_INPUT_H_INCLUDED
#define GET_INT_INPUT_H_INCLUDED

struct user_input {
    int value;
    bool eof_flag;
};

struct user_input get_int_input();

#endif // GET_INT_INPUT_H_INCLUDED
