//https://practice.geeksforgeeks.org/problems/union-find/1

//User function Template for C++

//User function Template for C++

class Solution
{
    public:
    int find(int a, int par[])
    {
        // cout<<a<<" =find\n";
        if(par[a] == a)
            return a;
        return par[a] = find(par[a], par);
    }
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int rank1[]) 
    {
        // cout<<"Union "<<a<<" "<<b<<"\n";
        int root_a = find(a, par);
        int root_b = find(b, par);
        
        if(rank1[root_a] < rank1[root_b])
            par[root_a] = root_b;
        else if(rank1[root_a] > rank1[root_b])
            par[root_b] = root_a;
        else{
            par[root_b] = root_a;
            rank1[root_a]++;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        // cout<<"isConnected "<<x<<" "<<y<<"\n";
        return find(x, par) == find(y, par);
    }
};