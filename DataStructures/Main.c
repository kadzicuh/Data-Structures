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

//#include "Stack/Stack.h"
//#include "Queue/Queue.h"
//#include "CircularQueue/CircularQueue.h"
//#include "Deque/Deque.h"
//#include "SinglyLinkedList/SinglyLinkedList.h"
//#include "DoublyLinkedList/DoublyLinkedList.h"
//#include "CircularLinkedList/CircularLinkedList.h"

int main() 
{
    /*
    ---------------------------------------------STACK---------------------------------------------
        stack* s = createStack(2);
        pushStack(s, 10);
        pushStack(s, 20);
        pushStack(s, 30);
        peekStack(s);
        popStack(s);
        printStack(s);
        deleteStack(s);
    ---------------------------------------------STACK END-----------------------------------------
    */

    /*
    ---------------------------------------------QUEUE---------------------------------------------
        queue* q = createQueue(2);
        enQueue(q, 10);
        enQueue(q, 20);
        enQueue(q, 30);
        peekQueue(q);
        deQueue(q);
        printQueue(q);
        deleteQueue(q);
    ---------------------------------------------QUEUE END-----------------------------------------
    */

    /*
    ---------------------------------------------CIRCULAR QUEUE------------------------------------
        circularQueue* c = createCircularQueue(2);
        enCircularQueue(c, 10);
        enCircularQueue(c, 20);
        enCircularQueue(c, 30);
        peekCircularQueue(c);
        deCircularQueue(c);
        printCircularQueue(c);
        deleteCircularQueue(c);
    ---------------------------------------------CIRCULAR QUEUE END--------------------------------
    */

    /*
    ---------------------------------------------DEQUE---------------------------------------------
        deque* d = createDeque(4);
        addFrontDeque(d, 7);
        addRearDeque(d, 12);
        addFrontDeque(d, 5);
        addRearDeque(d, 6);
        printDeque(d);
        delFrontDeque(d);
        printDeque(d);
        delRearDeque(d);
        printDeque(d);
        deleteDeque(d);
    ---------------------------------------------DEQUE END-----------------------------------------
    */

    /*
    ---------------------------------------------SINGLY LINKED LIST--------------------------------
        struct Node* head = NULL;

        insertAtEndSinglyLinkedList(&head, 1);
        insertAtBeginSinglyLinkedList(&head, 2);
        insertAtBeginSinglyLinkedList(&head, 3);
        insertAtEndSinglyLinkedList(&head, 4);
        insertAfterSinglyLinkedList(head->next, 5);

        printf("Linked list: ");
        printSinglyLinkedList(head);

        printf("\nAfter deleting an element: ");
        deleteNodeSinglyLinkedList(&head, 3);
        printSinglyLinkedList(head);

        int itemToFind = 3;

        if (searchNodeSinglyLinkedList(&head, itemToFind))
            printf("\n%d is found", itemToFind);
        else
            printf("\n%d is not found", itemToFind);

        sortSinglyLinkedList(&head);
        printf("\nSorted List: ");
        printSinglyLinkedList(head);
    ---------------------------------------------SINGLY LINKED LIST END----------------------------
    */

    /*
    ---------------------------------------------DOUBLY LINKED LIST--------------------------------
        struct Node* head = NULL;

        insertEndDoublyLinkedList(&head, 5);
        insertFrontDoublyLinkedList(&head, 1);
        insertFrontDoublyLinkedList(&head, 6);
        insertEndDoublyLinkedList(&head, 9);
        insertAfterDoublyLinkedList(head, 11);
        insertAfterDoublyLinkedList(head->next, 15);
        printDoublyLinkedList(head);
        deleteNodeDoublyLinkedList(&head, head->next->next->next->next->next);
        printDoublyLinkedList(head);
    ---------------------------------------------DOUBLY LINKED LIST END----------------------------
    */

    /*
    ---------------------------------------------CIRCULAR LINKED LIST------------------------------
        struct Node* last = NULL;

        last = addToEmptyCircularLinkedList(last, 6);
        last = addEndCircularLinkedList(last, 8);
        last = addFrontCircularLinkedList(last, 2);
        last = addAfterCircularLinkedList(last, 10, 2);

        printCircularLinkedList(last);
        deleteNodeCircularLinkedList(&last, 8);

        printf("\n");
        printCircularLinkedList(last);
    ---------------------------------------------CIRCULAR LINKED LIST END--------------------------
    */
}