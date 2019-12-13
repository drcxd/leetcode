class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // if found
        if (cache.find(key) != cache.end()) {
            // change the position of the key in the list to the front
            lru.erase(cache[key].second);
            lru.push_front(key);
            cache[key].second = lru.begin(); // update cache
            return cache[key].first; // return the value
        }
        return -1;
    }

    void put(int key, int value) {
        // if key already exist
        if (cache.find(key) != cache.end()) {
            // change the position of the key to the front of the list
            lru.erase(cache[key].second);
            lru.push_front(key);
            // update cache
            cache[key].second = lru.begin();
            cache[key].first = value;
            return;
        }
        // if the list is full, remove the last element
        if (cache.size() == capacity) {
            cache.erase(lru.back());
            lru.pop_back();
        }
        // put the new element at the front of the list
        lru.push_front(key);
        cache.insert({key, {value, lru.begin()}});
    }

private:

    int capacity;

    list<int/*key*/> lru;

    unordered_map<int/*key*/, pair<int/*value*/, list<int>::iterator/*position*/> > cache;
};