#pragma once

#include <stdio.h>
#include <stdlib.h>
namespace LinkList {

    typedef struct LinkList {
        int data = 0;
        struct LinkList* next;
    }Node, LinkList;

    Node* insertLinkList(struct LinkList* head, int value) {
        struct LinkList* L = (struct LinkList*)malloc(sizeof(struct LinkList));
        L->data = value;
        L->next = NULL;

        if (head == NULL)
        {
            head = L;
        }
        else {
            struct LinkList* curHead = head;
            while (curHead->next != NULL) {
                curHead = curHead->next;
            }
            curHead->next = L;
        }
        return head;
    }

    Node* algo(struct LinkList* head) {
        Node* p = head->next;
        Node* q = p->next;
        while (p->next != NULL)
        {
            if (p->data < q->data) {
                p = p->next;
                q = p->next;
            }
            else {
                Node* tmp = q;
                q = q->next;
                p->next = tmp->next;
                tmp->next = NULL;
                free(tmp);
            }
        }
        return head;
    }

    void test() {
        int n = 10;
        struct LinkList* head = NULL;
        //for (int i = 0; i < n; i++) {
        //	head = insertLinkList(head,i);
        //}

        head = insertLinkList(head, 1);
        head = insertLinkList(head, 2);
        head = insertLinkList(head, 2);
        head = insertLinkList(head, 3);
        head = insertLinkList(head, 4);
        head = insertLinkList(head, 4);

        head = algo(head);
        while (head != NULL) {
            printf("%d\n", head->data);
            head = head->next;
        }
    }


}// namespace end
