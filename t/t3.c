#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>

#define TEST_DIR_NAME1 "tvis"
#define TEST_DIR_NAME2 "sharness"
#define MAX_STR_LEN 128 

int main (int argc, char *argv[])
{
    char b[MAX_STR_LEN] = {'\0'};
    char *dn = NULL;
    char *bn = NULL;

    if (!getcwd (b, MAX_STR_LEN))
        return EXIT_FAILURE;
 
    dn = dirname (b);
    bn = basename (dn);

    if (strncmp (TEST_DIR_NAME1, bn, MAX_STR_LEN) != 0)
        if (strncmp (TEST_DIR_NAME2, bn, MAX_STR_LEN) != 0)
            return EXIT_FAILURE; 

    fprintf (stdout, "%s <=> %s, %s\n", bn, TEST_DIR_NAME1, TEST_DIR_NAME2); 

    return EXIT_SUCCESS; 
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
