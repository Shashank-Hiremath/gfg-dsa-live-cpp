//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void heapify(ll heap[], ll heap_size, ll i)
{
    ll smallest = i, left = 2*i+1, right = 2*i+2;
    if(left < heap_size && heap[left] < heap[smallest])
        smallest = left;
    if(right < heap_size && heap[right] < heap[smallest])
        smallest = right;
    if(i != smallest)
    {
        swap(heap[i], heap[smallest]);
        heapify(heap, heap_size, smallest);
    }
}
ll extract_min(ll heap[], ll &heap_size)
{
    swap(heap[0], heap[heap_size-1]);
    heap_size--;
    heapify(heap, heap_size, 0);
    return heap[heap_size];
}
void insert_heap(ll heap[], ll &heap_size, ll val)
{
    heap_size++;
    int i = heap_size-1, parent = (i-1)/2;
    heap[i] = val;
    while(i && heap[parent] > heap[i])
    {
        swap(heap[parent], heap[i]);
        i = parent;
        parent = (i-1)/2;
    }
}
ll minCost(ll arr[], ll n) {
    ll heap_size = n, heap[heap_size], i, ans = 0, first, second;
    for(i=0;i<n;i++)
        heap[i] = arr[i];
    for(i=heap_size/2-1;i>=0;i--)
        heapify(heap, heap_size, i);
    while(heap_size>1)
    {
        first = extract_min(heap, heap_size);
        second = extract_min(heap, heap_size);
        ans += first + second;
        insert_heap(heap, heap_size, first+second);
    }
    return ans;
}