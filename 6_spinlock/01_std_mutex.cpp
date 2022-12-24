
#include <iostream>
#include <thread>
#include <mutex>


std::mutex m;
int i = 0;

void locked_increment() {
    m.lock();
    std::cout << "Print value " << i << "\n";
    i++;
    m.unlock();
}


int main() {

    std::thread thread1(locked_increment);
    std::thread thread2(locked_increment);
    std::thread thread3(locked_increment);

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
