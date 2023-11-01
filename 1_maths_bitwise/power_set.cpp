//https://practice.geeksforgeeks.org/problems/power-set4302/1

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int len = s.size(), i, n = pow(2, len);
		    vector<string> ans;
		    
		    for(int currSet=1;currSet<n;currSet++){
		        string currStr;
		        
		        for(i=0;i<len;i++){ 
		            if((currSet&(1<<i)) != 0)
		                currStr += s[i];
		        }
		        
		        ans.push_back(currStr);
		    }
		  
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};