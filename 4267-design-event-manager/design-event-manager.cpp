class EventManager {
public:
    set<pair<int,int>> active;
    unordered_map<int,int>mp;
    EventManager(vector<vector<int>>& events) {
        
       for(int i=0;i<events.size();i++) {
        int id=events[i][0], priority= events[i][1];
           mp[id]=priority;
           active.insert({-priority,id});
       }   
        
    }
    
    void updatePriority(int eventId, int newPriority) {
        int oldpriority=mp[eventId];
        active.erase({-oldpriority,eventId});
        mp[eventId]=newPriority;
        active.insert({-newPriority,eventId});

    }
    
    int pollHighest() {
        if(mp.empty()) return -1;
        int max=active.begin()->first; 
        int ans=active.begin()->second;
        mp.erase(ans);
        active.erase({max,ans});
        return ans;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */