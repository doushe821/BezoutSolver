#ifndef USER_MENU_H_INCLUDED
#define USER_MENU_H_INCLUDED

const char MENU_INPUT[]= "Type \"s\" to start solving equations, type \"q\" to exit program.\n";
const char INVALID_IN[]= "Invalid input\n";
const int MAX_N = 10000;

struct coefficients_input{
    int coefficients[MAX_N];
    int coefficients_number;
    bool quit_flag;
    bool eof_flag;
};

struct coefficients_input user_menu();
void answers_output(const struct solve_output ans);

#endif // USER_MENU_H_INCLUDED
