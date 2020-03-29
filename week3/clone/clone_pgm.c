#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define STACK_SIZE 10000
char child_stack[STACK_SIZE + 1];

int child(void *params)
{
    int c = 0;
    while (true)
    {
        usleep(50000);
        printf("child turn %d\n", c++);
    }
}

int main()
{
    int c = 0;
    // так как стек растёт с конца - указываем на конец массива
    int result = clone(child, child_stack + STACK_SIZE, 
        CLONE_PARENT,   // назначить родителем порождаемого процесса родителя текущего процесса
        0);
    // Note: если для порождаемых ПРОЦЕССОВ назначать одного родителя и общую память,
    //       то такую программу будет считать многоПОТОЧНОЙ
    printf("clone result = %d\n", result);

    while (true)
    {
        usleep(50000);
        printf("parent turn %d\n", c++);
    }
}
