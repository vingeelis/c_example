#define _GNU_SOURCE
#include <sched.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define IS_OK(ret_v, msg) \
    {                     \
        if (ret_v == -1)  \
        {                 \
            perror(msg);  \
            exit(-1);     \
        }                 \
    }

// child stack size = 1M
#define STACK_SIZE (1024 * 1024)
static char child_stack[STACK_SIZE];

// child process
static int child_func()
{
    // replaces  the current process image with a new process image.
    // execlp("bash", "bash", (char *)NULL);

    execlp("ipcs", "ipcs", "-q", NULL);

    // the code here will never be executed
    // char *const bash_args[] = {"/bin/bash", NULL};
    // execv(bash_args[0], bash_args);

    return 0;
}

int ipc_enable()
{

    // flags with CLONE_NEWIPC
    int container_pid = clone(child_func, child_stack + STACK_SIZE, CLONE_NEWUTS | CLONE_NEWIPC | SIGCHLD, NULL);

    // parent wait children
    waitpid(container_pid, NULL, 0);

    return 0;
}

int ipc_disable()
{

    // flags without CLONE_NEWIPC
    int container_pid = clone(child_func, child_stack + STACK_SIZE, CLONE_NEWUTS | SIGCHLD, NULL);

    // parent wait children
    waitpid(container_pid, NULL, 0);
    return 0;
}

int main()
{
    // Create a message queue.
    system("ipcmk -Q");

    // Write information about active message queues.
    printf("\n-------------------- in parent --------------------\n");
    system("ipcs -q | tail +2");
    printf("\n-------------------- in parent --------------------\n");

    printf("\n-------------------- ipc enable --------------------\n");
    ipc_enable();
    printf("\n-------------------- ipc enable --------------------\n");

    printf("\n-------------------- ipc disable --------------------\n");
    ipc_disable();
    printf("\n-------------------- ipc disable --------------------\n");

    // remove all message queue.
    system("ipcs -q | tail +4 | awk '{print $2}' | xargs -I{} ipcrm -q {}");
}