#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache: public Cache{
   int size;
   public:
      LRUCache(int capacity, int size = 0){
          cp = capacity;
          this->size = size;
          head = NULL;
          tail = NULL;
      }
      void set(int k, int v){
         Node* temp;
         if(mp.find(k) != mp.end()){
            temp = mp[k];
            if(head == temp){
               return;
            } // Do nothing
            else if(tail == temp){
               temp->prev->next = temp->next;
               tail = temp->prev;
            }
            else{
               temp->prev->next = temp->next;
               temp->next->prev = temp->prev;
            }
            temp->next = head;
            head->prev = temp;
            head = temp;
         }
         else{
            temp = new Node(k,v);
            temp->next = head;
            if(head != NULL){
                head->prev = temp;
                head = temp;
            }
            else{
               tail = head = temp;
               ++size;
            }
            mp[k] = temp;
            if(size > cp){
               mp.erase(tail->key);
               tail = tail->prev;
               delete tail;
               --size;
            }           
         }
        /* temp = head;
        cout << endl << "Debug: "; 
        while(temp){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;*/
      }

      int get(int k){
         if(mp.find(k) != mp.end())
            return mp[k]->value;
         return -1;
      }
};
int main() {
   ifstream cin("input.txt");
   ofstream cout("output.txt");
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
