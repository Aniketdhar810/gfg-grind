//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}

// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int findLength(Node* slowp,Node* fastp){
    int cnt=1;
    fastp=fastp->next;
    while(slowp!=fastp){
        cnt++;
        fastp=fastp->next;
    }
    return cnt;
}
int countNodesinLoop(struct Node *head)
{
    // Code here
    //stack method
    // Node* temp=head;
    // int cnt=1;
    // int value;
    // map<Node*,int> mp;

    // while(temp!=NULL){
    //     if(mp.find(temp)!=mp.end()){
    //         value=mp[temp];
    //         return cnt-value;
    //     }
    //     mp[temp]=cnt;
    //     cnt++;
    //     temp=temp->next;
    // }
    //tortoise and hare
    //when the the slow and fast meet we start counting
    Node* slowp=head;
    Node* fastp=head;
    while(fastp!=NULL && fastp->next!=NULL){
            slowp=slowp->next;
            fastp=fastp->next->next;
            if(slowp==fastp){
                return findLength(slowp,fastp);
            }
    }
    return 0;
}