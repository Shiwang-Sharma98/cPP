#include<iostream>
#include<vector>
using namespace std;

class Node{  // user defined data type
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{  // user defined structure

public:

    Node* head;
    Node* tail;
    int size;

    LinkedList(){
        head = tail = NULL;
        size = 0;
    }

    void insertAtTail(int val){
        Node* temp = new Node(val);
        if(size==0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    
    void insertAtHead(int val){
        Node* temp = new Node(val);
        if(size==0) head = tail = temp;
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void InsertAtIndex(int idx,int val){
        if(idx==0) insertAtHead(val);
        else if (idx<0 || idx>size) cout<<"invalid idx";
        else if (idx==size) insertAtTail(val);
        else{
            Node* t = new Node(val);
            Node* temp = head;
            int n = 0;
            while(n<idx-1){
                temp = temp->next;
                n++;

            }
            t->next = temp->next;
            temp->next = t;
            size++;

        }
    }

    int getAtIndex(int idx){
        if(idx<0 || idx>=size){
            cout<<"invalid idx";
            return 0;
        }
        else if(idx==0) return head->val;
        else if(idx==size-1) return tail->val;
        else{
            Node* temp = head;
            for(int i = 0;i<idx;i++){
                temp = temp->next;
            }
            return temp->val;
        }
    }

    void deleteAtHead(){
        if(size==0){
            cout<<"list is empty!";
            return;
        }
        head = head->next;
        size--;
    }

    void deleteAtTail(){
        if(size==0){
            cout<<"list is empty!";
            return;
        }
        Node* temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
        size--;
    }

    void deleteAtIndex(int idx){
        if(size==0){
            cout<<"list is empty!";
            return;
        }
        else if(idx<0 || idx>=size){
            cout<<"invalid idx";
        }
        else if(idx==0) deleteAtHead();
        else if(idx==size-1) deleteAtTail();
        else{
            Node* temp = head;
            for(int i=1;i<idx-1;i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            size--;
        }
    }

    Node* merger_sorted_list(Node* a,Node* b){
        Node* c = new Node(100);
        Node* temp = c;
        while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
                temp->next = a;
                a = a->next;
                temp = temp->next;
            }
            else{
                temp->next = b;
                b = b->next;
                temp = temp->next;
            }
        }
        if(a==NULL){
            temp->next = b;
        }
        if(b==NULL){
            temp->next = a;
        }
        return c->next;

    }

    bool has_cycle(){
        Node* temp = head;
        Node *fast = temp;
        Node *slow = temp;
        // till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
			
			// At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
            if(fast == slow)
                return true;
        }
        
		// if traversal reaches to NULL this means no cycle.
        return false;
    }

    Node* removeNthFromEnd(int n) {
       Node* temp = head; 
       Node* slow = temp;
       Node* fast = temp;
      
       // traverse fast to n+1 steps
       for(int i=0;i<=n;i++){
           if(fast==NULL) return head->next;
           fast=fast->next;
       } 
       // move slow and fast at same pace
       while(fast!=NULL){
           slow=slow->next;
           fast=fast->next;
       }
       // now the slow pointer is exactly at the left of the node the we want to delete
       slow->next=slow->next->next;
       return head;
    }

    vector<Node*> splitListToParts(int k) {
        vector<Node*> ans;
        Node* temp = head;
        int n = 0;
        while(temp!=NULL){
            temp = temp->next;
            n++;
        }
        temp = head;
        int size = n/k; // size of one part
        int rem = n%k;
        while(temp!=NULL){
            Node* c = new Node(100);
            Node* tempc = c;
            int s = size;
            if(rem>0) s++;
            rem--;
            for(int i=1;i<=s;i++){
                tempc->next = temp;
                tempc = tempc->next;
                temp = temp->next;
            }
            tempc->next = NULL;
            k--;
            ans.push_back(c->next);
        }
        while(k!=0){
            ans.push_back(NULL);
            k--;
        }
        return ans;
    }     
};

int main(){
    
    LinkedList ll;
    ll.insertAtTail(10);
    ll.display();
    ll.insertAtHead(23);
    ll.insertAtHead(3);
    ll.insertAtHead(23);
    ll.insertAtHead(253);
    ll.insertAtHead(235);
    ll.insertAtHead(234);
    ll.insertAtHead(232);
    ll.display();
    return 0;
}