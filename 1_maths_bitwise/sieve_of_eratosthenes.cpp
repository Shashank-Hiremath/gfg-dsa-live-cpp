//https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1

//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        vector<int> ans;
        // vector<bool> seive(n+1, 1);
        // for(int i=2;i*i<=n;i++){
        //     if(seive[i])
        //         for(int j=i*i;j<=n;j+=i)
        //             seive[j] = 0;
        // }
        
        // for(int i=2;i<=n;i++)
        //     if(seive[i] == 1)
        //         ans.push_back(i);
        
        bitset<10001> seive;
        seive.set();
        for(int i=2;i*i<=n;i++)
            if(seive.test(i))
                for(int j=i*i;j<=n;j+=i)
                    seive.reset(j);
        for(int i=2;i<=n;i++)
            if(seive.test(i))
                ans.push_back(i);

        return ans;
        
    }
};