//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    struct comparitor_
    {
        bool operator()(Item min, Item max)
        {
    
            return (double)max.value / max.weight > (double)min.value / min.weight;
        }
    };
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int capacity, Item arr[], int n)
    {
        priority_queue<Item, vector<Item>, comparitor_> pq(arr, arr+n);
        
        double total_value = 0;
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            if (top.weight <= capacity)
            {
                total_value += top.value;
                capacity -= top.weight;
            }
            else
            {
                total_value += (double)top.value / top.weight * capacity;
                return total_value;
            }
        }
        return total_value;
    }
        
};