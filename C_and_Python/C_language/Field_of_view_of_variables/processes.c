#include "processes.h"
#include <stdio.h>

Process processes[MAX_PROCESSES];
int processescount = 0;

static int uniqueid = 1;

int nextprocessid(void) {
    if (uniqueid <= 0)
        return 0;

    return uniqueid++;
}

int createnewprocess(const char *name) {
    if (processescount >= MAX_PROCESSES)
        return 0;

    int id = nextprocessid();
    if (id == 0)
        return 0;

    Process newprocess = {id, ""};
    snprintf(newprocess.name, MAX_NAME_LENGTH + 1, "%s", name);

    processes[processescount++] = newprocess;

    return id;
}

void stopprocess(int processid) {
    for (int i = 0; i < processescount; ++i) {
        if (processes[i].id == processid) {
            for (int j = i; j < processescount - 1; ++j) {
                processes[j] = processes[j + 1];
            }
            processescount--;
            return;
        }
    }
}