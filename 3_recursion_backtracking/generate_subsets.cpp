//https://practice.geeksforgeeks.org/batch/gcl-63/track/DSASP-Recursion/video/MjMzMQ%3D%3D

#include <iostream>
using namespace std;


void printSub(string str, string curr, int index)
{
	if(index == str.length())
	{
		cout<<curr<<" ";
		return;
	}

	printSub(str, curr, index + 1);
	printSub(str, curr+str[index], index + 1);
}
	
int main() {
	
	string str = "ABC";
    	
    printSub(str, "", 0);
	
	return 0;
}