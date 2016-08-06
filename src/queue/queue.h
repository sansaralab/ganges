#pragma once

#include <stdbool.h>

typedef struct gg_queue_item
{
    char *data;
    struct gg_queue_item *next;
} gg_queue_item;

typedef struct gg_queue
{
    gg_queue_item *first;
    gg_queue_item *last;
} gg_queue;

gg_queue *gg_queue_new();

bool gg_queue_push(gg_queue *queue, char *data);

char *gg_queue_pop(gg_queue *queue);

bool gg_queue_free(gg_queue *queue);
