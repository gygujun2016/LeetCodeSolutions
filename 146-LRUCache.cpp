/*
    Design and implement a data structure for Least Recently Used (LRU) cache. 
    It should support the following operations: get and put.

    get(key) - Get the value (will always be positive) of the key if the key 
    exists in the cache, otherwise return -1.
    put(key, value) - Set or insert the value if the key is not already present. 
    When the cache reached its capacity, it should invalidate the least recently 
    used item before inserting a new item.

    Follow up:
    Could you do both operations in O(1) time complexity?

    Example:

    LRUCache cache = new LRUCache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4

    设计 LRU Cache
    随机访问key O(1) -> hashtable
    删除LRU Cache中最后访问的key O(1) -> list
    加入/改变一个key到LRU的最前面 O(1) -> list
*/
#include <LeetCodeUtil.h>
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    int get(int key) {
        // 1. Key 不在 LRU Cache 中的情况， 返回 -1
        auto it = m_.find(key);
        if (it == m_.end()) return -1;
        // 2. Key 在 LRU Cache 这个的情况， 返回 Value， 并将该节点移动到 list 头部
        cache_.splice(cache_.begin(), cache_, it->second); // 把 it->second结点移动到cache_.beign()位置
        return it->second->second;
    }
    void put(int key, int value) {
        auto it = m_.find(key); 
        if (it != m_.end()) { // 1. Key 在LRU Cache 中的情况，更新 value，并移动该节点到list头部
            it->second->second = value;
            cache_.splice(cache_.begin(), cache_, it->second); // 把 it->second结点移动到cache_.beign()位置
            return;
        }
        // 2. Key 不在 LRU Cache中，则考虑是否超过容量
        if (m_.size() == capacity_) {
            const auto& node = cache_.back();
            m_.erase(node.first); // 删除最后一个结点
            cache_.pop_back(); // 删除最后一个结点
        }
        // 添加一个节点到LRU Cache中
        cache_.emplace_front(key, value);
        m_[key] = cache_.begin();
    }
private:
    int capacity_; // LRU Cache 的容量
    list<pair<int, int>> cache_; // list的结点就是一个(key, value);
    unordered_map<int, list<pair<int, int>>::iterator> m_; // 通过key来找到对应的list的结点
};
int main(int argc, char const *argv[]) {
    LRUCache* cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cache->get(1);       // returns 1
    cache->put(3, 3);    // evicts key 2
    cache->get(2);       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    cache->get(1);       // returns -1 (not found)
    cache->get(3);       // returns 3
    cache->get(4);       // returns 4
    return 0;
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */