#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

/* Разработать программу solution, обеспечивающую загрузку динамической библиотеки в режиме исполнения.
 * При запуске, программе передается имя динамической библиотеки, имя функции которая должна быть вызвана, и ее аргумент.
 * Функция в библиотеке принимает на вход int и возвращает int.
 * Результат, возвращаемый функцией, должен быть выведен отдельной строкой (оканчиваться символом новой строки \n) в stdout.
 */

int (*so_func)(int);    // pointer to a func from dynamic library

bool init_library(const char *so_name, const char *f_name) {
    // open shared object (dynamic library)
    void *hdl = dlopen(so_name, RTLD_LAZY);
    if( NULL == hdl )
        return false;
    // obtain address of hello_message func
    void * p_func = dlsym(hdl, f_name);
    so_func = (typeof(so_func)) p_func; // `typeof` is a compiler extension
    if( NULL == so_func)
        return false;

    return true;
}

int main(int argc, const char **argv) {
    const char *so_name = argv[1];
    const char *f_name  = argv[2];
    const int   f_arg   = atoi(argv[3]);
    int ret_val = 0;

    // printf("parms: %s, %s, %d\n", so_name, f_name, f_arg);

    if ( init_library(so_name, f_name) ) {
        ret_val = so_func(f_arg);
    } else {
        printf("init_library failed\n");
        return -1;
    }

    printf("%d\n", ret_val);
    return 0;
}
