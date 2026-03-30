class LFUCache {
public:
int  n;

unordered_map<int,list<vector<int>>::iterator>mp;  // key->address
 map<int, list<vector<int>>> freq; //counter->{key,value,counter}
 
    LFUCache(int capacity) {
        n=capacity ;
    }
    void  makeFrequentUsed(int key){
        auto &vec = *mp[key]; 
         int value=vec[1]; int counter =vec[2];

         freq[counter].erase(mp[key]);

         if(freq[counter].empty())
           freq.erase(counter);

         freq[counter+1].push_front({key,value,counter+1});
         mp[key]=freq[counter+1].begin();
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
       auto &vec = *mp[key]; 
        int value=vec[1];
        makeFrequentUsed(key);
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            auto &vec=*mp[key];
            vec[1]=value;
          makeFrequentUsed(key);
        }
        else{
            if(mp.size()==n){
                auto &it=freq.begin()->second;
                
                auto keyy=(it.back())[0]; 
                it.pop_back();
                if(it.empty()) freq.erase(freq.begin());
                mp.erase(keyy);

            }
            freq[1].push_front({key,value,1});
            mp[key]=freq[1].begin();

        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */