#pragma once

#include <stdint.h>

typedef struct Command
{
    uint8_t command;
    uint32_t length;
    char* data;
} Command;

void run(int port);