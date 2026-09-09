/*Leetcode ps-460. LFU Cache
Design and implement a data structure for a Least Frequently Used (LFU) cache.
Implement the LFUCache class:
LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.*/




/* Approach - Frequency-Grouped Doubly Linked List with Hash Map / LFU Cache Architecture (Time: O(log K) due to map, Space: O(Capacity))
 * Basically, we completely annihilate the O(N) brute-force frequency scan by aggressively grouping nodes into frequency buckets, maintaining recency order via doubly linked lists to resolve frequency ties with absolute precision!
 * * Observation: 
 * - The absolute core of this architecture is the Frequency-Bucket Partition! You brilliantly decoupled the cache into two tiers: an `unordered_map` for instant O(1) key lookups, and a frequency-indexed structure (`std::map<int, std::list>`) where each frequency bucket holds a doubly linked list of nodes. When an item is accessed, it gracefully steps up to the next frequency bucket, and ties are naturally broken by the linked list's LRU order!
 * - (The Fatal `std::vector` Allocation Trap): Your architectural logic is razor-sharp, but your data structure payload introduces silent hardware bloat! Storing a `vector<int>` inside every node of a `std::list` (`list<vector<int>>`) forces the compiler to manage dynamic vector buffers and metadata overhead for every single cache entry, causing heap fragmentation and cache-line thrashing! You can completely eliminate this by defining a lightweight, flat custom struct `struct Node { int key, val, freq; };` directly inside the list.
 * - (The `std::map` Frequency Log-Time Bottleneck): Deploying `std::map<int, list<...>> freq;` means your frequency table is backed by a Red-Black tree. Every time you access a frequency bucket, update `minFreq`, or check `freq.begin()`, you incur an $O(\log \text{distinct frequencies})$ penalty. To achieve true, pristine O(1) time complexity across *every single operation*, you can replace the `std::map` with a raw `unordered_map<int, list<Node>>` coupled with a simple scalar `minFreq` tracker!
 * * How it runs:
 * First, the cache constructor intercepts the maximum capacity and initializes our tracking registers.
 * When `get(key)` is invoked, we probe the lookup map. If the key is absent, we instantly return `-1`. If present, we extract its data, invoke `makeMostFrequentlyUsed` to slice it out of its current frequency bucket, push it into the incremented frequency list, and return its value.
 * When `put(key, value)` is invoked, if the key exists, we update its value and elevate its frequency. If it's a new key and we have spare capacity, we drop it straight into the frequency 1 bucket.
 * The exact millisecond the cache breaches capacity during an insertion, the eviction engine triggers! We instantly grab the least frequency list from the front, pop the oldest victim sitting at `.back()`, purge it from the lookup map, and seamlessly insert the new element at raw silicon speed!
 */



class LFUCache {
private:
    int cap;
    int size;
    unordered_map<int, list<vector<int>>::iterator> mp; //key -> address of list of vector{key, value, freq}
    map<int, list<vector<int>>> freq; //freq -> list of vector{key, value, freq}
    
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    void makeMostFrequentlyUsed(int key) {
        auto &vec = *(mp[key]);
        
        int value = vec[1];
        
        int f     = vec[2];
        
        freq[f].erase(mp[key]);
        
        if(freq[f].empty())
            freq.erase(f);
        
        f++;
        
        freq[f].push_front(vector<int>({key, value, f}));
        
        mp[key] = freq[f].begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        auto &vec = (*(mp[key]));
        
        int value = vec[1];
        
        makeMostFrequentlyUsed(key);
        
        return value;
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        
        if(mp.find(key) != mp.end()) {
            auto &vec = (*(mp[key]));
            vec[1] = value;
            makeMostFrequentlyUsed(key);
        }
        else if(size < cap) {
            size++;
            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        }
        else { //Time to remove LFU or LRU if tie
            
            auto &kaun_sa_list = freq.begin()->second;
            
            int key_delete = (kaun_sa_list.back())[0]; //ordered_map ensures that the begin() will be th eleast frequency
            
            kaun_sa_list.pop_back();
            
            if(kaun_sa_list.empty())
                freq.erase(freq.begin()->first);
            
            freq[1].push_front(vector<int>({key, value, 1}));
            
            mp.erase(key_delete);
            mp[key] = freq[1].begin();
        }
    }
};
