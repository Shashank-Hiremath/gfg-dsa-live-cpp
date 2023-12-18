//https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return if the paranthesis are balanced or not
bool ispar(string x)
{
    stack<char> s;
    for(auto c: x)
        if(s.empty() || !(s.top()=='(' && c==')' || 
                          s.top()=='{' && c=='}' || 
                          s.top()=='[' && c==']'))
            s.push(c);
        else
            s.pop();
    return s.empty();
}


// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends