/*Leetcode ps-146. LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.*/


/* Approach - Doubly Linked List with Hash Map / O(1) LRU Cache Architecture (Time: O(log N) due to map, Space: O(Capacity))
 * Basically, we couple a doubly linked list with a lookup map to maintain strict chronological recency order, achieving lightning-fast node relocation the instant an element is accessed or inserted!
 * * Observation: 
 * - The absolute core of this architecture is the O(1) Node Relocation Pattern! By storing `std::list::iterator` directly inside the lookup table, you can slice a node out of the middle of the linked list and shove it straight to the front in constant time, completely bypassing any need for a linear search.
 * - (The `std::map` Red-Black Tree Bottleneck - Fatal Flaw): Your architectural intuition for an LRU cache is textbook, but your container choice introduces a massive performance tax! You deployed `std::map` instead of `std::unordered_map`. Because `std::map` is implemented as a Red-Black tree, every single `get` and `put` lookup incurs an $O(\log N)$ penalty instead of true $O(1)$ hashing! For tight performance bounds, you MUST replace `std::map` with `std::unordered_map` to enforce strict O(1) time complexity.
 * - (The Mutable Capacity Counter Trap): Decrementing and incrementing your capacity variable `n` on the fly works, but relying on a drifting counter instead of directly checking `mp.size() >= capacity` introduces subtle fragility. If a state invariant slips, your capacity tracking desynchronizes. Always query the container's native size or compare against a constant `capacity` limit.
 * * How it runs:
 * First, the cache constructor intercepts the maximum capacity and initializes our tracking variables.
 * When `get(key)` is invoked, we probe the lookup table. If the key is absent, we instantly return `-1`. If present, we fire our recency function (`makerecused`), slicing the node from its current position in the linked list and moving it to the front, then returning its value.
 * When `put(key, value)` is invoked, if the key already exists, we update its value and bring it to the front. If it's a new key, we push it to the front of the list and register it in the map. 
 * If the capacity breaches the limit, we ruthlessly evict the least recently used victim sitting at `dll.back()`, purging it from both the map and the list to maintain absolute size equilibrium at raw silicon speed!
 */



class LRUCache {
public:
    list<int> dll; //key
    map<int,pair<list<int> :: iterator,int>> mp; //stores add and value of a certain key
    int n ;
    LRUCache(int capacity) {
        n = capacity;
    }

    void makerecused(int key){
        dll.erase(mp[key].first);//remove from current index
        dll.push_front(key);//bring the key at begining of map
        mp[key].first = dll.begin();//store the address of node in map
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1; // element is not present in cache

        //element is present -> mark it recently used by bringing it to front
        makerecused(key);

        return mp[key].second;


    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){//present in map
            //mark it as most recently used by bringing it at begining of list
            mp[key].second = value;
            makerecused(key);
        }else{ // not present
            dll.push_front(key);
            mp[key] = {dll.begin(),value};
            n--;

            if(n < 0){//need to remove most recently used
               int key_del = dll.back();
               mp.erase(key_del);

               dll.pop_back();
               n++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
