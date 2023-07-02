//https://practice.geeksforgeeks.org/problems/reverse-a-stack/1

class Solution{
public:
    void pushToBottom(stack<int> &st, int x){
        if (st.size() == 0) {
            st.push(x);
        }
        else {
            int a = st.top();
            st.pop();
            pushToBottom(st, x);
            st.push(a);
        }
    }
    void Reverse(stack<int> &st){
        if(st.size()==0){
            return ;
        }
        int top = st.top();
        st.pop();
        Reverse(st);
        pushToBottom(st, top);
    }
};