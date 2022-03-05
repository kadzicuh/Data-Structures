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

#include "Stack.h"

stack* createStack(unsigned int size)
{
    if (size <= 0)
        size = 10;

    stack* ptr = (stack*)malloc(sizeof(stack));

    ptr->data = (stackValue*)malloc(size * sizeof(stackValue));
    ptr->capacity = size;
    ptr->top = -1;

    return ptr;
}

void deleteStack(stack* s)
{
    free(s->data);
    free(s);
}

void push(stack* s, stackValue value)
{
    if (s->top == s->capacity - 1)
        printf("Stack is Full \n");
    else
    {
        s->top++;
        s->data[s->top] = value;

        printf("pushed -> %d \n", s->data[s->top]);
    }
}

void pop(stack* s)
{
    if (s->top == -1)
        printf("Stack is Empty \n");
    else
    {
        printf("popped -> %d \n", s->data[s->top]);

        s->top--;
    }
}

void peek(stack* s)
{
    if (s->top == -1)
        printf("Stack is Empty \n");
    else
        printf("peeked -> %d \n", s->data[s->top]);
}

void printStack(stack* s)
{
    if (s->top == -1)
        printf("Stack is Empty \n");
    else
    {
        printf("\nStack: \n");

        for (int i = 0; i <= s->top; i++)
            printf("index -> %d, value -> %d \n", i, s->data[i]);
    }
}