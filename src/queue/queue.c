#include <stdlib.h>
#include <string.h>
#include "queue.h"


gg_queue* gg_queue_new()
{
    gg_queue* queue = malloc(sizeof(gg_queue));
    return queue;
}

bool gg_queue_push(gg_queue* queue, char* data)
{
    gg_queue_item* newItem = malloc(sizeof(gg_queue_item));
    newItem->data = data;

    if (queue->last == NULL) {
        queue->first = newItem;
    } else {
        queue->last->next = newItem;
    }

    queue->last = newItem;

    return true;
}

char* gg_queue_pop(gg_queue* queue)
{
    char* result = malloc(sizeof(queue->first->data));
    strcpy(result, queue->first->data);
    gg_queue_item* newFirst = queue->first->next;
    free(queue->first);
    queue->first = newFirst;

    return result;
}

bool gg_queue_free(gg_queue* queue)
{
    if (queue->first == NULL) {
        return true;
    }

    gg_queue_item* temp = queue->first;

    while (temp->next) {
        temp = queue->first->next;
        free(queue->first);
        queue->first = temp;
    }

    free(queue->first);
    free(queue);

    return true;
}
