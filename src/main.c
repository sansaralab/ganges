#include <stdio.h>
#include "queue/queue.h"


int main(int argc, char *argv[])
{
    gg_queue *queue = gg_queue_new();
    gg_queue_push(queue, "ololo1111!");
    gg_queue_push(queue, "ololo2222!");
    gg_queue_push(queue, "ololo3333!");
    gg_queue_pop(queue);
    gg_queue_pop(queue);
    gg_queue_pop(queue);
    gg_queue_pop(queue);
    gg_queue_push(queue, "ololo4444!");
    gg_queue_push(queue, "ololo5555!");
    gg_queue_free(queue);

    puts("Hello!");

    return 0;
}
