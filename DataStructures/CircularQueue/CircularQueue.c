/*
MIT License

Copyright (c) 2022 kadzicu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "CircularQueue.h"

circularQueue* createCircularQueue(unsigned int size)
{
    if (size <= 0)
        size = 10;

    circularQueue* ptr = (circularQueue*)malloc(sizeof(circularQueue));

    ptr->data = (circularQueueValue*)malloc(size * sizeof(circularQueueValue));
    ptr->capacity = size;
    ptr->front = -1;
    ptr->rear = -1;

    return ptr;
}

void deleteCircularQueue(circularQueue* c)
{
    free(c->data);
    free(c);
}

void enCircularQueue(circularQueue* c, circularQueueValue value)
{
    if ((c->front == c->rear + 1) || (c->front == 0 && c->rear == c->capacity - 1))
        printf("Circular Queue is Full \n");
    else
    {
        if (c->front == -1)
            c->front = 0;

        c->rear = (c->rear + 1) % c->capacity;
        c->data[c->rear] = value;

        printf("Inserted -> %d \n", c->data[c->rear]);
    }
}

void deCircularQueue(circularQueue* c)
{
    if (c->front == -1)
        printf("Circular Queue is Empty \n");
    else
    {
        printf("Deleted -> %d \n", c->data[c->front]);

        if (c->front == c->rear)
        {
            c->front = -1;
            c->rear = -1;
        }
        else
            c->front = (c->front + 1) % c->capacity;
    }
}

void peekCircularQueue(circularQueue* c)
{
    if (c->front == -1)
        printf("Circular Queue is Empty \n");
    else
        printf("Peeked -> %d \n", c->data[c->front]);
}

void printCircularQueue(circularQueue* c)
{
    if (c->front == -1)
        printf("Circular Queue is Empty \n");
    else
    {
        printf("\nCircular Queue:\n");

        int i;
        for (i = c->front; i != c->rear; i = (i + 1) % c->capacity)
            printf("index -> %d, value -> %d \n", i, c->data[i]);

        printf("index -> %d, value -> %d \n", i, c->data[i]);
    }
}