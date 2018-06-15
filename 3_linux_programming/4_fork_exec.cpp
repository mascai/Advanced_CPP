/*
    Выполнить ls -l в дочернем процессе
*/
#include <iostream>
#include <bits/stdc++.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int spawn(char *prog_name, char **arg_list) {
    pid_t child_pid = fork();
    if (child_pid != 0) {
        return 0;
    } else {
        execvp(prog_name, arg_list);
        fprintf(stderr, "ann error occured");
        abort();
    }
}

int main() {
    char *arg_list[] = {
            "ls",
            "-l",
            NULL
    };
    spawn("ls", arg_list);
}

