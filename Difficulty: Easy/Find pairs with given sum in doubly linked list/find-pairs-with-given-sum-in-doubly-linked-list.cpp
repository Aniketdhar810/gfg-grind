//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        //N2 time complex
        // vector<pair<int,int>> arr;
        // Node* temp1=head;
        // while(temp1!=NULL){
        //     Node* temp2=temp1->next;
        //     while(temp2!=NULL){
        //         if((temp1->data+temp2->data)==target){
        //             arr.push_back(make_pair(temp1->data, temp2->data));
        //         }
        //         temp2=temp2->next;
        //     }
        //     temp1=temp1->next;
        // }
        // return arr;
        //two pointer approach
        vector<pair<int,int>>arr;
        Node* left=head;
        Node* right=head;
        while(right->next!=NULL){
            right=right->next;
        }
        while (left != NULL && right != NULL && left != right && left->prev != right)
        {
            int sum = left->data + right->data;
            if (sum == target)
            {
                arr.push_back(make_pair(left->data, right->data));
                left = left->next;
                right = right->prev;
            }
            else if (sum < target)
            {
                left = left->next;
            }
            else
            {
                right = right->prev;
            }
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends