//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        // Add code here
        // int cnt0=0,cnt2=0,cnt1=0;
        // Node* temp=head;
        // while(temp!=NULL){
        //     if(temp->data==0) cnt0++;
            
        //     else if(temp->data==1)cnt1++;
            
        //     else if (temp->data==2) cnt2++;
            
        //     temp=temp->next;
        // }
        // temp=head;
        // for(int i=0;i<cnt0;i++){
        //         temp->data=0;
        //         temp=temp->next;
        //     }
        // for(int i=0;i<cnt1;i++){
        //         temp->data=1;
        //         temp=temp->next;
        //     }
        // for(int i=0;i<cnt2;i++){
        //         temp->data=2;
        //         temp=temp->next;
        // }
        
        //BY CHANGING LINKS
        Node* zerohead=new Node(-1);
        Node* onehead=new Node(-1);
        Node* twohead=new Node(-1);
        
        Node* ll0=zerohead;
        Node* ll1=onehead;
        Node* ll2=twohead;
        
        
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==0){
                ll0->next=temp;
                ll0=temp;
            }
            else if(temp->data==1){
                ll1->next=temp;
                ll1=temp;
            }
            else{
                ll2->next=temp;
                ll2=temp;
            }
            temp=temp->next;
        }
        ll0->next=(onehead->next)? (onehead->next):(twohead->next);
        ll1->next=twohead->next;
        ll2->next=NULL;
        Node* newHead=zerohead->next;
        delete(zerohead);
        delete(onehead);
        delete(twohead);
        return newHead;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends