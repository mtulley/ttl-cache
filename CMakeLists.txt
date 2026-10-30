cmake_minimum_required(VERSION 3.20)

project(ttl_cache LANGUAGES CXX)

add_executable(ttl-cache
    main.cpp
    ttlcache.cpp
)

target_compile_features(ttl-cache PRIVATE cxx_std_20)
