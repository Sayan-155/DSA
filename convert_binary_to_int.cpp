#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int data)
        {
            this->val = data;
            this->next = NULL;
        }
        ~Node()
        {
            cout<<"Destroyed";
        }
};

Node* push_back(Node* head , int val)
{
    if(!head) return new Node(val);
    else
    {
        Node* last = head;
        while(last->next)
            last = last->next;
        
        last->next = new Node(val); 
        return head;
    }
}

Node* make_list(vector<int> arr)
{
    Node* head = new Node(arr[0]);
    for(int i=1; i<arr.size() ; i++)
    {
        head = push_back(head , arr[i]);
    }
    return head;
}

void print_list(Node* head)
{
    if(!head) cout<<"List not exists";
    while(head)
    {
        cout<<head->val<<"->";
        head = head -> next;
    }
    cout<<endl;
}


vector<int> num_to_arr(int num)
{
    vector<int> arr;
    while (num)
    {
        int n = num%10;
        arr.push_back(n);
        num /= 10;
    }
    return arr;
}

void print_arr(vector<int> arr)
{
    for(int i=0 ; i<arr.size() ; i++)
        cout<<arr[i];

    cout<<endl;
}

int bin_list_to_nm(Node* head)
{
    int num = 0;
    int power = 0;
    while(head)
    {
        num += head->val * pow(2 , power);
        power += 1;
        head=head->next;
    }

    return num;
}

int main()
{
    int bin_num = 1000;
    vector<int> arr = num_to_arr(bin_num);
    Node* head;

    head= make_list(arr);
    int num = bin_list_to_nm(head);
    cout<<num;

    return 0;
}