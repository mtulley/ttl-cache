#include "ttlcache.h"

void TTLCache::insert(std::string key, int val, int lifespan) {
    CacheEntry entry{val, std::chrono::steady_clock::now(), std::chrono::seconds(lifespan)};
    map[key] = entry;
}

int TTLCache::get(std::string key) {
    CacheEntry entry = map.at(key);
    std::chrono::time_point<std::chrono::steady_clock> now = std::chrono::steady_clock::now();
    std::chrono::seconds age = std::chrono::duration_cast<std::chrono::seconds>(now - entry.timeOfInsertion);

    if (age > entry.lifespan) {
        map.erase(key);
        return 0;
    }

    return entry.val;
}

bool TTLCache::contains(std::string key) {
    return map.contains(key);
}

TTLCache::TTLCache() : map{} {}
