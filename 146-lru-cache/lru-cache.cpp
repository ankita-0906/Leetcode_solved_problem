class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    void makerecent(int key){
        auto address=mp[key].first;
        int val=mp[key].second;
        dll.erase(address);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        makerecent(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {

        
        if(mp.find(key)!=mp.end()){
            mp[key].second=value;
              makerecent(key);
        }
        else{
            if (mp.size() == n){
           // delete from linkedlist and map
           mp.erase(dll.back());
          dll.pop_back();
        
        }
            dll.push_front(key);
            mp[key].first=dll.begin();
             mp[key].second=value;
           
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */