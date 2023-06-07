#include <iostream>
#include <list>
#include <unordered_map>

template <class Key, class Value> class lru_cache {
    int m_capacity { 0 };
    std::unordered_map<Key, std::pair<Value, typename std::list<Key>::iterator>>
        m_storage; // storage: key -> {value, iterator for key in list}
    std::list<Key> m_list; // list of keys in the right order

    void use(const Key& key) noexcept {
        // key in cache
        if (m_storage.find(key) != m_storage.end()) {
            // delete old position
            m_list.erase(m_storage[key].second);
        } else // key not in cache
        {
            // if cache is full
            if (m_list.size() >= m_capacity) {
                // pop last element
                m_storage.erase(m_list.back());
                m_list.pop_back();
            }
        }
        // add to begin
        m_list.push_front(key);
        m_storage[key].second = m_list.begin();
    }

public:
    lru_cache(int capacity) { m_capacity = capacity; }

    Value& get(const Key& key) {
        if (m_storage.find(key) != m_storage.end()) {
            use(key);
            return m_storage[key].first;
        } else
            throw std::range_error { "No such element in the cache" };
    }

    void put(const Key& key, const Value& value) noexcept {
        use(key);
        m_storage[key].first = value;
    }

    void print() noexcept {
        for (const auto& elem : m_list)
            std::cout << "(" << elem << ", " << m_storage[elem].first << ") ";
        std::cout << std::endl;
    }
};