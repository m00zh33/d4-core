#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <getopt.h>
#include <string.h>

#include "d4.h"
//Returns -1 on error, 0 otherwise
int d4_load_config(d4_t* d4)
{
    return -1;
}

void usage(void)
{
    printf("d4 client help\n");
}

d4_t* d4_init(char* confdir)
{
    d4_t* out;
    out = calloc(1,sizeof(d4_t));
    if (out) {
        strncpy(out->confdir, confdir, FILENAME_MAX);
    }
    // Do other inititalization stuff here
    return out;
}

int main (int argc, char* argv[])
{
    int opt;
    char* confdir;
    d4_t* d4;

    confdir=calloc(1,FILENAME_MAX);
    if (!confdir)
        return EXIT_FAILURE;

    while ((opt = getopt(argc, argv, "c:h")) != -1) {
        switch (opt) {
            case 'h':
                usage();
                return EXIT_SUCCESS;
            case 'c':
                strncpy(confdir, optarg, FILENAME_MAX);
                break;
            default:
                fprintf(stderr,"An invalid command line argument was specified\n");
        }
    }
    if (!confdir[0]){
        fprintf(stderr,"A config directory must be specified\n");
        return EXIT_FAILURE;
    }


    d4_init(confdir);
    free(confdir);
    d4_load_config(d4);
    return EXIT_SUCCESS;
}
