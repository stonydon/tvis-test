#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>

#define TEST_DIR_NAME "t"
#define MAX_STR_LEN 128 

int main (int argc, char *argv[])
{
    char b[MAX_STR_LEN] = {'\0'};
    char *bn = NULL;

    if (!getcwd (b, MAX_STR_LEN))
        return EXIT_FAILURE;
 
    bn = basename (b);

    if (strncmp (TEST_DIR_NAME, bn, MAX_STR_LEN) != 0)
        return EXIT_FAILURE; 

    fprintf (stdout, "%s <=> %s\n", bn, TEST_DIR_NAME); 

    return EXIT_SUCCESS; 
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
