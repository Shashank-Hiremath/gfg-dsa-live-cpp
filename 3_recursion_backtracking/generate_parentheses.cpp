//https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
void f(vector<string> &res, string curr, int open, int close)
{
    if(open+close == 0)
        res.push_back(curr);
    if(open)
        f(res, curr+"(", open-1, close);
    if(close && close>open)
        f(res, curr+")", open, close-1);
}
vector<string> AllParenthesis(int n) 
{
    vector<string> res;
    f(res, "", n, n);
    return res;
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> result = AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
}