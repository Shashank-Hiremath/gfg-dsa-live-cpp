//https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1

#include <bits/stdc++.h>
#include <string>

using namespace std;

void possibleWords(int a[],int n);


int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	  possibleWords(a,N);
	   cout << endl;
	}
	
	return 0;
}// } Driver Code Ends
//Complete this function

void f(int a[], int N, string &s, string h[], int i)
{
    if(i==N)
        cout<<s<<" ";
    else
    for(int j = 0; h[a[i]][j]; j++)
    {
        s = s+h[a[i]][j];
        f(a, N, s, h, i+1);
        s = s.substr(0, s.size()-1);
    }
}

void possibleWords(int a[],int N)   //Too easy. Brute force
{
    //Your code here
    string h[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs",
    "tuv", "wxyz"}, s;
    f(a, N, s, h, 0);
}