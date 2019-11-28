class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            lru.erase(cache[key].second);
            lru.push_front(key);
            cache[key].second = lru.begin();
            return cache[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            lru.erase(cache[key].second);
            lru.push_front(key);
            cache[key].second = lru.begin();
            cache[key].first = value;
            return;
        }
        if (cache.size() == capacity) {
            cache.erase(lru.back());
            lru.pop_back();
        }
        lru.push_front(key);
        cache.insert({key, {value, lru.begin()}});
    }

private:

    int capacity;

    list<int> lru;

    unordered_map<int, pair<int, list<int>::iterator> > cache;
};