#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedList init() {
    LinkedList newLinkedList = {
        .head = NULL,
        .size = 0
    };
    return newLinkedList;
}

static struct ListNode *createNode(Task *task) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("Error allocating memory \n");
        exit(1);
    }
    newNode->task = task;
    newNode->next = NULL;
    return newNode;
}

void pushTask(LinkedList *list, char *name, uint priority) {
    Task *newTask = (Task *)malloc(sizeof(Task));
    newTask->name = strdup(name);
    newTask->priority = (priority > list->size) ? list->size + 1 : priority;
    newTask->state = NEW;

    struct ListNode *newNode = createNode(newTask);
    if (list->head == NULL || newTask->priority < list->head->task->priority) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        struct ListNode *currentNode = list->head;
        while (currentNode->next != NULL && currentNode->next->task->priority <= newTask->priority) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    list->size++;
}

void setTaskState(LinkedList *list, uint priority, TaskState state) {
    struct ListNode *currentNode = list->head;
    while (currentNode != NULL && currentNode->task->priority != priority) {
        currentNode = currentNode->next;
    }
    if (currentNode != NULL) {
        currentNode->task->state = state;
    }
}