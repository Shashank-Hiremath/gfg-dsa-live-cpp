//https://practice.geeksforgeeks.org/problems/reverse-a-string/1


//User function Template for C++

// string reverseWord(string str){
//   int n = str.size();
//   string ans;
//   for(int i=0;i<n;i++){
//       ans = ans + str[n-1-i];
//   }
//   return ans;
// }

string reverseWord(string str){
  int n = str.size(), i;
  for(i=0;i<n/2;i++){
    //   swap(str[i], str[n-1-i]);
    char temp = str[i];
    str[i] = str[n-1-i];
    str[n-1-i] = temp;
  }
  return str;
}
