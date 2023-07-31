//https://practice.geeksforgeeks.org/problems/queue-using-stack/1

//User function Template for C++

class Queue {
    stack<int> aux, output;
public:

    void enqueue(int x) { //Enqueue operation made costly
        while(!output.empty()){
            aux.push(output.top());
            output.pop();
        }
        output.push(x);
        while(!aux.empty()){
            output.push(aux.top());
            aux.pop();
        }
    }

    int dequeue() {
        if(output.empty()){
            return -1;
        }
        int ret = output.top();
        output.pop();
        return ret;
    }
};


//User function Template for C++

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) { //Dequeue operation made costly
        input.push(x);
    }

    int dequeue() {
        if(!output.empty()){
            int ret = output.top();
            output.pop();
            return ret;
        }
        if(input.empty()){
            return -1;
        }
        
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        return dequeue();
    }
};