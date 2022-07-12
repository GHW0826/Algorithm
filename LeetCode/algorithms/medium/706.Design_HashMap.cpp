class MyHashMap {
public:
    unordered_map<int, int> table_;
    MyHashMap() {
    }
    
    void put(int key, int value) {
        table_[key] = value;
    }
    
    int get(int key) {
        if (table_.find(key) != table_.end())
            return table_[key];
        return -1;
    }
    
    void remove(int key) {
        table_.erase(key);
    }
};
