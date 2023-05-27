//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
     struct Node*temp = head;
     
     if(temp->next == NULL)return temp;
     vector<int>arr;
     
     while(temp != NULL){
         arr.push_back(temp->data);
         
         temp = temp->next;
     }
     int s = 0;
     int e =arr.size()-1;
     temp = head;
     while(s<e){
         int start = arr[s];
         int end = arr[e];
         arr[s] = end -start;
         arr[e] = start;
         s++;
         e--;
     }
     int i = 0;
     while(temp != NULL){
         temp->data = arr[i];
         i++;
         temp = temp->next;
     }
     return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends