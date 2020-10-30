#include <stdlib.h>
#include <stdio.h>

int foo(int);

int main() {
    printf("Just a custom string\n");
    int a = foo(5);
    return 5;
}

int foo(int x) {
    return x*123;
}