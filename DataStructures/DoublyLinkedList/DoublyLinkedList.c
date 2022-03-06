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

#include "DoublyLinkedList.h"

void insertFrontDoublyLinkedList(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = NULL;

    if ((*head) != NULL)
        (*head)->prev = newNode;

    (*head) = newNode;
}

void insertAfterDoublyLinkedList(struct Node* prev_node, int data)
{
    if (prev_node == NULL)
    {
        printf("previous node cannot be null");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;

    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

void insertEndDoublyLinkedList(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    struct Node* temp = *head;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNodeDoublyLinkedList(struct Node** head, struct Node* del_node)
{
    if (*head == NULL || del_node == NULL)
        return;

    if (*head == del_node)
        *head = del_node->next;

    if (del_node->next != NULL)
        del_node->next->prev = del_node->prev;

    if (del_node->prev != NULL)
        del_node->prev->next = del_node->next;

    free(del_node);
}

void printDoublyLinkedList(struct Node* node)
{
    struct Node* last;

    while (node != NULL)
    {
        printf("%d->", node->data);
        last = node;
        node = node->next;
    }

    if (node == NULL)
        printf("NULL\n");
}