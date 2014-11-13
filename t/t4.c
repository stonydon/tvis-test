#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

#define MIN_NUM_FILES 7
#define DEBUG 1

int main (int argc, char *argv[])
{
    DIR *dp;
    struct dirent *ep;
    int c = -2;
    dp = opendir ("./");

    if (dp != NULL) {
        while ( (ep = readdir (dp))) {
            c++;
#if DEBUG
            fprintf (stdout, "%s\n", ep->d_name);
#endif
      
        }
    }

    closedir (dp);

    if (c < MIN_NUM_FILES)
        return EXIT_FAILURE;
   
    fprintf (stdout, "%d <=> %d \n", c, MIN_NUM_FILES);

    return EXIT_SUCCESS; 
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
