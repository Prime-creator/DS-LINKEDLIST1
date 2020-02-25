#include <iostream>
#include <stack>
#include<string.h>
#include<vector>
#include <algorithm>

using namespace std;

class stacks{
    vector<int> v;
public:
    void Push(int num){
        v.push_back(num);
    }
    void pop(int num){
        v.pop_back();
    }
    int top(){
        return v[v.size()-1];
    }
    bool isEmpty(){
        return v.size()==0;
    }
};

class node{
public:

    int data;
    node *next;
    node(int d){
        data = d;
        next = NULL;
    }
};

class Stack{
    node *head;
    int count;
public:

    Stack(){
        head = NULL;
        int count = 0;
    }
    void push(int d){
        if(head == NULL){
            head = new node(d);
            count++;
        }
        else{
            node *temp = new node(d);
            temp->next = head;
            head = temp;
            count++;
        }
    }
    void pop(){
        if(head == NULL){
            return;
        }
        node *n = head;
        head = head->next;
        delete n;
        count--;
    }

};

void push_elem(stack<int> &s,int topElem){
    if(s.empty()){
        s.push(topElem);
        return;
    }
    int topElemo = s.top();
    s.pop();
    push_elem(s,topElem);
    s.push(topElemo);
}
void ReverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int topElem = s.top();
    s.pop();
    ReverseStack(s);
    push_elem(s,topElem);
}

/*class Queue{
    int count;
    int f, r, n;
    int *a;
public:
    Queue(int s = 4){
        f = 0;
        n = s;
        r = n-1;
        a = new int[n];
        count = 0;
    }

    void push(int d){
        if(count == n){
            cout<<"OverFlow"<<endl;
            return;
        }
        else{
            r = (r+1)%n;
            a[r] = d;
            count++;
        }
    }
    void pop(){
        if(count == 0){
            cout<<"UnderFlow"<<endl;
        }
        f=(f+1)%n;
        count--;
    }
    bool empty(){
		return count==0;
	}

	int front(){
		return a[f];
	}
};
*/

class Queue{
    node *f;
    node *r;
    int count;
public:
    Queue(){
        f = r = NULL;
        count = 0;
    }
    void push(int d){
        if(f == NULL){
            f = r = new node(d);
            count++;
        }
        else{
            node *n = new node(d);
            r->next = n;
            r = n;
            count++;
        }
    }
    void pop(){
        if(f == NULL){
            return;
        }
        else if(f->next == NULL){
            delete f;
            f = r = NULL;
            count--;
        }
        else{
            node *temp = f;
            f = f->next;
            delete temp;
            count--;
        }
    }
    int front(){
		return f->data;
	}

	bool empty(){
		return f==NULL; // count==0
	}
};


void nextLargest(){
    int test;
    cin>>test;
    while(test--){
            int len;
            cin>>len;
            int a[len];
            for(int i = 0; i < len; i++){
                cin>>a[i];
            }
        stack <int> st;
        st.push(a[0]);
        for(int i = 1; i < len;i++){
            while(!st.empty() && st.top() < a[i]){
                cout<<a[i]<<" ";
                st.pop();
            }
        st.push(a[i]);
        }
        while(!st.empty()){
            cout<<"-1";
            st.pop();
        }
        cout<<endl;
        }
}

bool isbalanced(string str){
    stack<char> st;
    int n = str.size();
    for(int i = 0; i < n ; i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            st.push(str[i]);
           }
    }
    if(st.empty())
        return false;
    char x;
    for(int i = 0; i < n ; i++){
        switch(str[i]){
        case ')':
            //cout<<"hello i am )";
            x = st.top();
            st.pop();
            if(x == '{' || x == '[')
                return false;
            break;

        case '}':
            //cout<<"hello }";
            x = st.top();
            st.pop();
            if(x == '(' || x == '{')
                return false;
            break;

        case ']':
            x = st.top();
            //cout<<"hello ]";
            st.pop();
            if(x == '(' || x == '{')
                return false;
            break;
        }
    }
    return true;
}
void lower_boundStl(){
    int a[] = {50,10,40,30,20};
    sort(a,a+sizeof(a)/sizeof(a[0]));
    cout<<"elem"<<endl;
    vector<int> v(a,a+ sizeof(a)/sizeof(a[0])) ;
    for(int i = 0 ; i != v.size(); i++){
        cout<<v[i]<<endl;
    }
    vector<int>::iterator low1, low2;
    low1 = lower_bound(v.begin(), v.end(), 29);
    cout<<"result"<<endl;
    cout<<(low1 - v.begin());}

bool IsPresent(int *a, int n,int temp){

}
int main()
{

}
