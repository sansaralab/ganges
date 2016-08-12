#include <stdio.h>
#include <stdlib.h>
#include "server/async.h"


int main(int argc, char *argv[])
{
    uint16_t portno;

    if (argc != 2) {
        printf("usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = (uint16_t) atoi(argv[1]);

    printf("Starting server at %d port...\n", portno);
    run(portno);

    return 0;
}
