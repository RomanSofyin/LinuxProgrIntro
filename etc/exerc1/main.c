#include <stdlib.h>
#include <stdio.h>

#define SWAP(t, x, y)  { (t) = (x); (x) = (y); (y) = (t); }

#define my_printf(str,...)  printf("MY_PRINTF: " str, __VA_ARGS__);

/* Define a variable with type of varType and name super_%varName%_1 and initialized with value */
#define super_var_1(varType, varName, value)   varType super_ ## varName ## _1 = (value);

#define RETURN_CODE_1_ARG(rc)               { return(rc); }
#define RETURN_CODE_2_ARG(msg, rc)          { printf(msg); return(rc); }
#define GET_3RD_ARG(arg1, arg2, arg3, ...)  arg3
#define RETURN_CODE_MACRO_CHOOSER(...)      GET_3RD_ARG(__VA_ARGS__, RETURN_CODE_2_ARG, RETURN_CODE_1_ARG, )
#define RETURN_CODE(...)                    RETURN_CODE_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)

int foo(int);

int main() {
    int a = foo(-5);
    int b = foo(6);
    int tmp;
    SWAP(tmp, a, b);
    my_printf("Just a custom string; a=%d, b=%d\n", a, b);
    super_var_1(double, abc, 3.14 + 10);
    my_printf("super_var_1 generated var = %f\n", super_abc_1);

    if (b > 0) {
        RETURN_CODE(0);                     // return(0)
    } else {
        RETURN_CODE("test string\n", b);    // print the message then return(b)
    }
}

int foo(int x) {
    return x*123;
}