#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<bits/stdc++.h>

int main() {
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid < 0) { // Error occurred
        fprintf(stderr, "Fork failed");
        return 1;
    } else if (pid == 0) { // Child process
        printf("This is the child process, with PID: %d\n", getpid());
    } else { // Parent process
        printf("This is the parent process, with PID: %d\n", getpid());
        printf("Child process PID: %d\n", pid);
    }

    return 0;
}