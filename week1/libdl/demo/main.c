/*
 * This program is a demo of libdl usage (dynamic linking).
 */

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>

// hello_message is a pointer to function which is NULL
// since it is defined in global area
void (*hello_message) (const char *);

bool init_library() {
    // open shared object (dynamic library)
    void *hdl = dlopen("./libHello.so", RTLD_LAZY);
    if( NULL == hdl )
        return false;
    // obtain address of hello_message func
    void * p_func = dlsym(hdl, "hello_message");
    hello_message = (void (*)(const char*)) p_func;
    if( NULL == hello_message)
        return false;

    return true;
}

int main() {
    if ( init_library() ) {
        // here hello_message func pointer is initialized, we are ok to use it
        hello_message("Vasya");
    } else {
        printf("init_library failed\n");
    }
    return 0;
}
