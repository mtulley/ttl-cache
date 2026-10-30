#ifndef TTL_CACHE_H
#define TTL_CACHE_H

#include <string>
#include <unordered_map>
#include <chrono>

class TTLCache {
private:
    struct CacheEntry {
        int val {};
        std::chrono::time_point<std::chrono::steady_clock> timeOfInsertion {};
        std::chrono::seconds lifespan {};
    };

    std::unordered_map<std::string, CacheEntry> map;

public:
    void insert(std::string key, int val, int lifespan = 10);

    int get(std::string key);

    bool contains(std::string key);

    TTLCache();
};

#endif
