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

#include "CircularLinkedList.h"

struct Node* addToEmptyCircularLinkedList(struct Node* last, int data)
{
    if (last != NULL)
        return last;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    last = newNode;
    last->next = last;

    return last;
}

struct Node* addFrontCircularLinkedList(struct Node* last, int data)
{
    if (last == NULL)
        return addToEmptyCircularLinkedList(last, data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;

    return last;
}

struct Node* addEndCircularLinkedList(struct Node* last, int data)
{
    if (last == NULL)
        return addToEmptyCircularLinkedList(last, data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;

    return last;
}

struct Node* addAfterCircularLinkedList(struct Node* last, int data, int item)
{
    if (last == NULL)
        return NULL;

    struct Node* newNode, * p;

    p = last->next;

    do
    {
        if (p->data == item)
        {
            newNode = (struct Node*)malloc(sizeof(struct Node));

            newNode->data = data;
            newNode->next = p->next;
            p->next = newNode;

            if (p == last)
                last = newNode;

            return last;
        }

        p = p->next;
    } while (p != last->next);

    printf("\nThe given node is not present in the list");

    return last;
}

void deleteNodeCircularLinkedList(struct Node** last, int key)
{
    if (*last == NULL)
        return;

    if ((*last)->data == key && (*last)->next == *last)
    {
        free(*last);
        *last = NULL;
        return;
    }

    struct Node* temp = *last, * d;

    if ((*last)->data == key)
    {
        while (temp->next != *last)
            temp = temp->next;

        temp->next = (*last)->next;
        free(*last);
        *last = temp->next;
    }

    while (temp->next != *last && temp->next->data != key)
        temp = temp->next;

    if (temp->next->data == key)
    {
        d = temp->next;
        temp->next = d->next;
        free(d);
    }
}

void printCircularLinkedList(struct Node* last)
{
    struct Node* p;

    if (last == NULL)
    {
        printf("The list is empty");
        return;
    }

    p = last->next;

    do
    {
        printf("%d ", p->data);
        p = p->next;

    } while (p != last->next);
}