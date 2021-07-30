#include <iostream>
using namespace std;


void inplaceHeapSort(int pq[], int n){
    // 1st step: Build the heap in input array
    // 0th ele is already in heap. we need to insert all elements from index 1 till end index into the heap, so start travelling from index 1.
    
    for(int i = 1; i < n; i++){
        // now ith index is added to heap
        // childIndex is the index of the ele added to the heap
        int childIndex = i;
        // bring added ele to correct position by comparing with parent
        while(childIndex >= 0){
            int parentIndex = (childIndex - 1) / 2;

            if(pq[childIndex] < pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }
    
    // the input array has now been converted into a heap
    
    // to get sorted array, we need to remove elemsts one by one from the heap
    // Remove elements

    int size = n; // size is the size of heap

    while(size > 1){
        // swap 1st and last element
        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size-1] = temp;
        
        // to remove ele from heap, reduce size of heap by 1.
        size--;
        
        // down-heapify 0th index ele. ie bring it to its correct position by swapping with its children
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndx = 2 * parentIndex + 2;
   
        while(leftChildIndex < size){
            // we need to swap parentIndex with minIndex - first find minIndex
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(rightChildIndx < size && pq[rightChildIndx] < pq[minIndex]) {
                minIndex = rightChildIndx;
            }
            if(minIndex == parentIndex) {
                break;
            }
            
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            
            // after swapping, our ele is placed at minIndex
            // so update the parentIndex to minIndex and keep comparing with new children
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndx = 2 * parentIndex + 2;
        }
    }


}





int main() {
    int input[] = {5, 1, 2, 0, 8};
    inplaceHeapSort(input, 5);
    for(int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;



}
