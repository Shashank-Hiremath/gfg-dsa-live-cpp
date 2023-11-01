//https://practice.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1

//User function Template for C++
class Solution
{
	public:
    int gcd(int A, int B) 
	{ 
	    if(A == 0)
	        return B;
	    return gcd(B%A, A);
	    
	   // return __gcd(A, B);
	} 
};