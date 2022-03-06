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

#include "Deque.h"

deque* createDeque(unsigned int size)
{
    if (size <= 0)
        size = 10;

    deque* ptr = (deque*)malloc(sizeof(deque));

    ptr->data = (dequeValue*)malloc(size * sizeof(dequeValue));
    ptr->capacity = size;
    ptr->front = -1;
    ptr->rear = -1;

    for (int i = 0; i < ptr->capacity; i++)
        ptr->data[i] = 0;

    return ptr;
}

void deleteDeque(deque* d)
{
    free(d->data);
    free(d);
}

int countDeque(deque* d)
{
    int c = 0;

    for (int i = 0; i < d->capacity; i++)
        if (d->data[i] != 0)
            c++;

    return c;
}

void addFrontDeque(deque* d, dequeValue value)
{
    if (d->front == 0 && d->rear == d->capacity - 1)
    {
        printf("Deque is Full \n");

        return;
    }

    if (d->front == -1)
    {
        d->front = 0;
        d->rear = 0;
        d->data[d->front] = value;

        return;
    }

    if (d->rear != d->capacity - 1)
    {
        int c = countDeque(d);
        int k = d->rear + 1;

        for (int i = 1; i <= c; i++)
        {
            d->data[k] = d->data[k - 1];
            k--;
        }

        d->data[k] = value;
        d->front = k;
        d->rear++;
    }
    else
    {
        d->front--;
        d->data[d->front] = value;
    }
}

void addRearDeque(deque* d, dequeValue value)
{
    if (d->front == 0 && d->rear == d->capacity - 1)
    {
        printf("Deque is Full \n");

        return;
    }

    if (d->front == -1)
    {
        d->front = 0;
        d->rear = 0;
        d->data[d->rear] = value;

        return;
    }

    if (d->rear == d->capacity - 1)
    {
        int k = d->front - 1;

        for (int i = d->front - 1; i < d->rear; i++)
        {
            k = i;

            if (k == d->capacity - 1)
                d->data[k] = 0;
            else
                d->data[k] = d->data[i + 1];
        }

        d->rear--;
        d->front--;
    }

    d->rear++;
    d->data[d->rear] = value;
}

void delFrontDeque(deque* d)
{
    if (d->front == -1)
    {
        printf("Deque is Empty \n");

        return;
    }

    printf("\nDeleted -> %d \n", d->data[d->front]);

    d->data[d->front] = 0;

    if (d->front == d->rear)
    {
        d->front = -1;
        d->rear = -1;
    }
    else
        d->front++;
}

void delRearDeque(deque* d)
{
    if (d->front == -1)
    {
        printf("Deque is Empty \n");

        return;
    }

    printf("\nDeleted -> %d \n", d->data[d->rear]);

    d->data[d->rear] = 0;
    d->rear--;

    if (d->rear == -1)
        d->front = -1;
}

void printDeque(deque* d)
{
    printf("\nDeque: ");
    printf("\n front: ");

    for (int i = 0; i < d->capacity; i++)
        printf("  %d", d->data[i]);

    printf("  :rear \n");
}