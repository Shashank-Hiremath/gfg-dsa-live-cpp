//https://practice.geeksforgeeks.org/problems/lru-cache/1



#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends




// design the class:

class LRUCache
{
private:
public:
    int k;
    list<pair<int, int>> dl;
    unordered_map<int, list<pair<int, int>>::iterator> um;
    LRUCache(int cap)
    {
        k = cap;
        dl.clear();
        um.clear();
    }
    
    int get(int key)
    {
        if(um.find(key) != um.end())
        {
            int val = um[key]->second;
            dl.erase(um[key]);
            um.erase(key);
            dl.push_front({key, val});
            um[key] = dl.begin();
            return val;
        }
        return -1;
    }
    
    void set(int key, int value)
    {
        if(um.find(key) != um.end())
        {
            dl.erase(um[key]);
            um.erase(key);
            dl.push_front({key, value});
            um[key] = dl.begin();
        }
        else
        {
            if(dl.size() == k)
            {
                um.erase(dl.back().first);
                dl.pop_back();
            }
            dl.push_front({key, value});
            um[key] = dl.begin();
        }
        // dl.push_front({key, value});
        // um[key] = dl.begin();
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends