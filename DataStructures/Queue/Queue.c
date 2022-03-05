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

#include "Queue.h"

queue* createQueue(unsigned int size)
{
    if (size <= 0)
        size = 10;

    queue* ptr = (queue*)malloc(sizeof(queue));

    ptr->data = (queueValue*)malloc(size * sizeof(queueValue));
    ptr->capacity = size;
    ptr->front = -1;
    ptr->rear = -1;

    return ptr;
}

void deleteQueue(queue* q)
{
    free(q->data);
    free(q);
}

void enQueue(queue* q, queueValue value)
{
    if (q->rear == q->capacity - 1)
        printf("Queue is Full \n");
    else
    {
        if (q->front == -1)
            q->front = 0;

        q->rear++;
        q->data[q->rear] = value;

        printf("Inserted -> %d \n", q->data[q->rear]);
    }
}

void deQueue(queue* q)
{
    if (q->front == -1)
        printf("Queue is Empty \n");
    else
    {
        printf("Deleted -> %d \n", q->data[q->front]);

        q->front++;

        if (q->front > q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
    }
}

void peekQueue(queue* q)
{
    if (q->front == -1)
        printf("Queue is Empty \n");
    else
        printf("Peeked -> %d \n", q->data[q->front]);
}

void printQueue(queue* q)
{
    if (q->front == -1)
        printf("Queue is Empty \n");
    else
    {
        printf("\nQueue: \n");

        for (int i = q->front; i <= q->rear; i++)
            printf("index -> %d, value -> %d \n", i, q->data[i]);
    }
}