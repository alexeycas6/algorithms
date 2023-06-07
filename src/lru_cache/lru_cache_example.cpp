#include <string>

#include "lru_cache.hpp"

int main() {

    lru_cache<int, std::string> cache(5);
    cache.put(1, std::string("1"));
    cache.put(2, std::string("2"));
    cache.put(3, std::string("3"));
    cache.put(4, std::string("4"));
    cache.put(5, std::string("5"));
    cache.print(); // (5, 5) (4, 4) (3, 3) (2, 2) (1, 1)

    auto res = cache.get(2);
    cache.print(); // (2, 2) (5, 5) (4, 4) (3, 3) (1, 1)

    cache.put(6, "6");
    cache.print(); // (6, 6) (2, 2) (5, 5) (4, 4) (3, 3)

    cache.put(5, "7");
    cache.print(); // (5, 7) (6, 6) (2, 2) (4, 4) (3, 3)

    return 0;
}