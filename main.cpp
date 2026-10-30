#include <iostream>
#include <chrono>
#include <thread>

#include "ttlcache.h"

int main () {
    TTLCache cache{};
    
    cache.insert("0.0.0.0", 1);

    std::this_thread::sleep_for(std::chrono::seconds(11));

    std::cout << cache.get("0.0.0.0") << std::endl;
}

std::chrono::time_point<std::chrono::steady_clock> getTime() {
    return std::chrono::steady_clock::now();
}
