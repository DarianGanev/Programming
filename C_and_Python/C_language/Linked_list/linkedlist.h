#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef unsigned int uint;

typedef enum {
    NEW,
    STARTED,
    COMPLETED
} TaskState;

typedef struct {
    char *name;
    uint priority;
    TaskState state;
} Task;

struct ListNode {
    Task *task;
    struct ListNode *next;
};

typedef struct {
    struct ListNode *head;
    uint size;
} LinkedList;

LinkedList init();

void pushTask(LinkedList *list, char *name, uint priority);
void setTaskState(LinkedList *list, uint priority, TaskState state);
void deleteTask(LinkedList *list, uint priority);
void printTasks(LinkedList *list);

#endif