/*
gcc -o ans 1.c -lpthread

*/

#include <pthread.h>    
#include <stdio.h>
#include <stdlib.h>

void *Thread(void *string) {
        int i;
        for (i=0; i<10; i++)
                printf("%s\n", (char *)string);
        pthread_exit(NULL);
}

int main() {
        char *e_str = "Hello!";
        char *f_str = "Bonjour !";
 
        pthread_t e_th;
        pthread_t f_th;
 
        int rc;
 
        rc = pthread_create(&e_th, NULL, Thread, (void *)e_str);
        if (rc)
                exit(-1);
        rc = pthread_create(&f_th, NULL, Thread, (void *)f_str);
        if (rc)
                exit(-1);
        pthread_exit(NULL);
}

/*
g++ -o ans 1.cpp -lpthread
--запись 'x' и 'o' в произвольном порядке


#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

void *foo(void* unused) {
    while (true) {
        fputc('x', stderr);
    }
}

int main() {
    pthread_t thread_id;
    // создание потока, который выполняюет ф-цию foo
    pthread_create(&thread_id, NULL, &foo, NULL);
    while (true) {
        fputc('o', stderr);
    }
    return 0;
}

*/
