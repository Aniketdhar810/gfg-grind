//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head){
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL){
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;   
        } 
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* temp=reverse(head);
        Node* duplicate=temp;
        int sum=1;
        while(temp!=NULL){
            sum+=temp->data;
            temp->data=sum%10;
            sum=sum/10;
            if (temp->next == NULL && sum > 0) {
                // If we are at the end of the list and there's still a carry, add a new node
                temp->next = new Node(sum);
                sum = 0; // Reset carry since we've handled it
            }
            temp=temp->next;
        }
        duplicate=reverse(duplicate);
        return duplicate;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends