//https://practice.geeksforgeeks.org/problems/prime-factors5052/1



class Solution{
	public:
	vector<int>AllPrimeFactors(int n) {
	    vector<int> ans;
	    for(int i=2;i*i<=n;i++)
	        if(n%i == 0){
	            ans.push_back(i);
	            while(n%i == 0)
	                n /= i;
	        }
	    if(n != 1)
	        ans.push_back(n);
	    return ans;
	}
};