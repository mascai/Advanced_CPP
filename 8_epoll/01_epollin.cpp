#include <iostream>
#include <unistd.h>
#include <sys/epoll.h>

#define MAX_EPOLL_EVENTS 8
#define MAX_INPUT_PIPES 4


int main() {
    int epollFd = -1;
    int eventsReady = 0;
    int inf[MAX_INPUT_PIPES][2];

    char message[] = "Hello";
    char receiveBuffer[4096];

    epoll_event einf[MAX_INPUT_PIPES];
    epoll_event eventQueue[MAX_EPOLL_EVENTS];

    epollFd = epoll_create1(0);
    if (epollFd == -1) {
        std::cout << "Can't create epoll" << std::endl;
    }
    
    // watching for EPOLLIN events
    for (int i = 0; i < MAX_INPUT_PIPES; ++i) {
        pipe(inf[i]);
        std::cout << "fd for " << inf[i][0] << " = " << inf[i][1] << std::endl;

        einf[i].events = EPOLLIN;
        einf[i].data.fd = inf[i][0];

        if (epoll_ctl(epollFd, EPOLL_CTL_ADD, inf[i][0], &einf[i]) == -1) {
            std::cout << "Can't add epoll" << std::endl;
        }

        if (i % 2) {
            write(inf[i][1], message, sizeof(message));
        }
    }

    while (true) {
        eventsReady = epoll_wait(epollFd, eventQueue, MAX_EPOLL_EVENTS, -1);
        for (int i = 0; i < eventsReady; ++i) {
            std::cout << "Got event " << eventQueue[i].events << " for fd=" << eventQueue[i].data.fd << std::endl;
            read(eventQueue[i].data.fd, receiveBuffer, sizeof(receiveBuffer));
        }
    }
}
