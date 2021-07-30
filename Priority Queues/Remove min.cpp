#include <cmath>
#include <algorithm>

class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;        // Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        int parentIndex = (childIndex - 1) / 2;
        while(parentIndex >= 0) {
            
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
        
    }
    
    int removeMin() {
        // Complete this function
         int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int pi=0;
        int lci=2*pi+1;
        int rci=2*pi+2;
        while(lci<pq.size()){
            if(lci==pq.size()-1){
                if(pi>lci){
                 swap(pq[pi],pq[lci]);
                    pi=lci;
            }
                break;
            }
            if(pq[pi]>pq[lci] && pq[pi]>pq[rci]){
                if(pq[lci]>pq[rci])
                {
                     swap(pq[pi],pq[rci]);
                    pi=rci;
                }
                else{
                     swap(pq[pi],pq[lci]);
                    pi=lci;
                }
            }
            else if(pq[pi]>pq[lci]){
                 swap(pq[pi],pq[lci]);
                    pi=lci;
            }
              else if(pq[pi]>pq[rci]){
                   swap(pq[pi],pq[rci]);
                    pi=rci;
            }
            else
                break;
            
            
                    lci=2*pi+1;
                     rci=2*pi+2;
            
        }
        return ans;
        
    }
    
    
};
