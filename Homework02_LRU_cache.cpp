class LRUCache {
public:
    list<pair<int,int>> cache;
    unordered_map <int, list<pair<int,int>>::iterator> map;
    int size = 0;
    LRUCache(int capacity):size(capacity) {
        
    }
    //splice移动list的元素到另一个list某个位置
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        cache.splice(cache.begin(),cache,map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            cache.splice(cache.begin(),cache,map[key]);
            cache.begin()->second = value;
            return;
            //map[key] = list.begin();
        }
        if(cache.size() == size){
            int key = cache.back().first;
            cache.pop_back();
            map.erase(key);
                
        }
        
        cache.push_front({key,value});
        map[key] = cache.begin();
            
        
       
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */