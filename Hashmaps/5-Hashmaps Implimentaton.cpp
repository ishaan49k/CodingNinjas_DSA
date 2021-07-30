#include <string>
using namespace std;

template <typename V>
class MapNode {
    public:
        string key;
        V value;
        MapNode* next;

        MapNode(string key, V value){
            this->key = key;
            this->value = value;
            next = NULL;
        }

        ~MapNode(){
            // before deleting current node, delete the next node
            // to delete the entire LL, call delete on the head of LL
            delete next;
        }
};

template <typename V>
class ourmap{
    MapNode<V>** buckets;
    int count;  // how many LL heads does bucket array store
    int numBuckets;  // total no. of buckest in bucket array. this is useful for compression fucntion

    public:
    ourmap() {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        // remove garbage values from all buckets of bucket array
        for (int i = 0; i < numBuckets; i++) {
            buckets[i] = NULL;
        }
    }

    ~ourmap(){
        // before deleting array, delete all the LL in all its buckets
    // first delete LL cuz if we delete array first, we wont have the heads of LL
        for (int i = 0; i < numBuckets; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }

    int size(){
        return count;
    }

        

    private:
    // this is hash fucntion which takes in string and outputs a bucket index
    int getBucketIndex(string key){
        // Step 1: find hashcode
        int hashCode = 0;
        
        
        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--) {
            hashCode += key[i] * currentCoeff;
            // to ensure hashcode dosent become too large
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBuckets; // to enusre currentCoff dosent become become too large
        }
        
        // Step 2: compression function we use is %
        return hashCode % numBuckets;
    }
    
    
    void rehash(){
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>* [2*numBuckets];
        // make all buckets of new array NULL
        for(int i=0; i < 2*numBuckets; i++){
            buckets[i] = NULL;
        }
        
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0; // there is no data in our map right now cuz buckets is empty
        
// travel temp - travel each LL stored in buckets of temp and add the elements to buckets
        for(int i=0; i< oldBucketCount; i++){
            MapNode<V>* head = temp[i];
            while(head != NULL){
                string key = head->key;
                V value = head->value;
                insert(key, value); // inser will be called on buckets array
                head = head->next;
            }
        }
        
        // delete temp array after all its data has been copied to buckets
        for(int i=0; i < oldBucketCount; i++){
            MapNode<V>* head = temp[i];
            delete head;
        }
        
        delete [] temp;
    }

    
    public:

    double getLoadFactor(){
        return (1.0*count)/numBuckets;
    }
    
    void insert(string key, V value) {
        int bucketIndex = getBucketIndex(key);
// if at the bucketIndex, input key already exists, we just have to update the value assosicated with it. if it is a new key, then make a node and attach this node at the starting of LL of that bucketIndex.
        MapNode<V>* head = buckets[bucketIndex]; // head is head of LL at BucketIndex

// run a loop to iterate over LL at bucketIndex. if we find a node with key same as the input key, we just update value associated with existing key and return.
        while (head != NULL){
            if (head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        
        // if we reach here, it means the entered key is a new key.
        // create a new ode and add it to starting of LL
        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        
        // check if we have to do rehashing
        double loadFactor = (1.0)*count/numBuckets;
        if(loadFactor > 0.7){
            rehash();
        }
    }

    
// delete the node which contains input key.
// to delete a node, we need to link its previous node with its next
// we also have to manually delete the node cuz it is dynamic
    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        while(head != NULL){
// if we find the node
            if(head->key == key){
// ie the key to be deleted is the first node of LL. here be careful cuz right now prev = NULL. so we dont want to acess prev->next
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                }else {
                    prev->next = head->next;
                }
                
// before deleting node, store its value to be returned.
// make sure its next = NULL cuz otherwise if we call delete on it, it will delete all nodes in front of it also.
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        
// if we dont find the key, return 0
        return 0;
    }

    
    V getValue(string key){     //input string and return its value
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while (head != NULL) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        
// return 0 as default if we dint find the key in LL
        return 0;
    }


};
