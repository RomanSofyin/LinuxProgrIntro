#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

/*
 * Syntax: ./quotation [--brackets] [-l#|--length=#] [-a|--authornameshouldbeprinted]
 */

int main(int c, char **v)
{
    int is_brackets = 0;
    int opindex = 0;
    int opchar = 0;
    char string[] = "My dear Frodo, you asked me once if I had told you everything there was to know about my adventures. And while I can honestly say I have told you the truth, I may not have told you all of it. I am old now, Frodo. I'm not the same hobbit as I once was. I think it is time for you to know what really happened.";
    int length = 0;

    struct option opts[] = {
        {"brackets", no_argument, &is_brackets, 1},
        {"length", required_argument, 0, 'l'},
        {"authornameshouldbeprinted", no_argument, 0, 'a'},
        {0, 0, 0, 0},
    };

    while (-1 != (opchar = getopt_long(c, v, "bl:aq", opts, &opindex)))
    {
        switch (opchar)
        {
        case 0:
            printf("0\n");
            break;
        case 'l':
            length = atoi(optarg);
            printf("length=%d\n", length);
            break;
        case 'a':
            printf("(c) Bilbo Baggins\n");
            break;
        default:
            printf("opchar: %c\n", opchar);
        }
    }
    if (strlen(string) > length && 0 != length)
        string[length] = '\0';
    if (is_brackets)
        printf("[%s]\n", string);
    else
        printf("%s\n", string);
    printf("Done\n");
    return 0;
}
