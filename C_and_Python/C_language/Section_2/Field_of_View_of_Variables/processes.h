#ifndef PROCESSES_H
#define PROCESSES_H

#define MAX_PROCESSES 5
#define MAX_NAME_LENGTH 30

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH + 1];
} Process;

extern Process processes[MAX_PROCESSES];
extern int processescount;

int nextprocessid(void);
int createnewprocess(const char *name);
void stopprocess(int processid);

#endif 