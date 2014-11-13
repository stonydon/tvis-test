#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define TEST_SUBDIR_COUNT 6
#define MAX_STR_LEN 128 

static int count_path (const char *p, size_t len)
{
    int i;
    int c = 0;
    char *t = (char *) p;

    for (i=0; (i < len) && (*t !='\0'); ++i) { 
        if (*t == '/') 
            c++;
        t++;
    }

    return c;
}

int main (int argc, char *argv[])
{
    int c = 0;
    char b[MAX_STR_LEN] = {'\0'};

    if (!getcwd (b, MAX_STR_LEN))
        return EXIT_FAILURE;
 
    c = count_path (b, MAX_STR_LEN);
    if (c > TEST_SUBDIR_COUNT )
        return EXIT_FAILURE;
     
    fprintf (stdout, "%d <=> %d\n", c, TEST_SUBDIR_COUNT); 

    return EXIT_SUCCESS; 
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
