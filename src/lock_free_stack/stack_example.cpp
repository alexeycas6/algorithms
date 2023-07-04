#include <chrono>
#include <iostream>
#include <thread>
#include "lock_free_stack.hpp"

using namespace std::chrono_literals;

int main() {
    lock_free_stack<int> stack;

    auto popper = std::thread([&stack]() {
        for (int i = 0; i < 10; i++) {
            stack.pop();
            std::this_thread::sleep_for(1s);
        }
    });
    auto pusher = std::thread([&stack]() {
        for (int i = 0; i < 10; i++) {
            stack.push(i);
            std::this_thread::sleep_for(2s);
        }
    });

    pusher.join();
    popper.join();

    std::cout << "stack size: " << stack.size() << std::endl;
    stack.print();

    return 0;
}