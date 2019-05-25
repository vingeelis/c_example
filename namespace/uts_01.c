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
static int child_func(void *hostname)
{
    // set hostname
    sethostname(hostname, strlen(hostname));

    // replaces  the current process image with a new process image.
    execlp("bash", "bash", (char *)NULL);

    // the code here will never be executed
    char *const bash_args[] = {"/bin/bash", NULL};
    execv(bash_args[0], bash_args);

    return 0;
}

int main(int argc, char *argv[])
{
    pid_t child_pid;

    if (argc < 2)
    {
        printf("Usage: %s <child-hostname>\n", argv[0]);
        return -1;
    }

    // child_func: When the child process is created with clone(), it commences execution by calling the function pointed to by the argument fn.
    // child_stack + STACK_SIZE: Stacks grow downward on  all  proces‐sors that run Linux (except the HP PA processors), so child_stack usually points to the topmost address of the memory space set up for the child stack.
    // SIGCHLD | CLONE_NEWUTS: flags may also be bitwise-ORed with zero or more of the following constants, in order to specify what is shared between the calling process and the child process.
    // argv[1]: The arg argument is passed as the argument of the function: child_func
    child_pid = clone(child_func, child_stack + STACK_SIZE, SIGCHLD | CLONE_NEWUTS, argv[1]);

    IS_OK(child_pid, "clone");

    // parent wait for child
    waitpid(child_pid, NULL, 0);

    // parent finish
    return 0;
}