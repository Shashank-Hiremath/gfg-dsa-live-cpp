//https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size(), zeros=0, twos=n-1, i=0;
        while(i<=twos){
            if(a[i] == 2){
                swap(a[i], a[twos]);
                twos--;
            }else if(a[i] == 0){
                swap(a[i], a[zeros]);
                zeros++;
                i++;
            }else if(a[i] == 1){
                i++;
            }
        }
    }
};