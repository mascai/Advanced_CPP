#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

void writer(const char *msg, int cnt, FILE *stream) {
    for (; cnt > 0; --cnt) {
        fprintf(stream, "%s\n", msg);
        fflush(stream);
        sleep(1);
    }
}

void reader(FILE *stream) {
    char buf[1024];
    while (!feof(stream) && !ferror(stream)
           && fgets(buf, sizeof(buf), stream) != NULL) {
        fputs(buf, stdout);
    }
}
int main() {
    int fd[2];
    pipe(fd);
    if (fork() == 0) {
        FILE *stream;
        close(fd[1]);
        stream = fdopen(fd[0], "r");
        reader(stream);
        close(fd[0]);
    } else {
        FILE *stream;
        close(fd[0]);
        string ch = "w";
        stream = fdopen(fd[1], "w");
        writer("Hello", 5, stream);
        close(fd[1]);
    }
    return 0;
}
