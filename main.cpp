#include <iostream>
#define NO_OF_CHARS 256
using namespace std;
//LINKED LIST QUESTIONS:

class node{
public:
    int data;
    node *next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

void InsertAtBeg(node *&head, node *&tail, int data){
    if(head == NULL){
        node *n = new node(data);
        head = tail = n;
    }
    else{
        node *n = new node(data);
        n->next = head;
        head = n;
    }
}

void InsertAtEnd(node *&head, node *&tail, int data){
    if(head == NULL){
        node *n = new node(data);
        tail = head = n;
    }
    else{
        node *n = new node(data);
        tail->next = n;
        tail = n;
    }
}

int length(node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

void InsertAtMid(node* &head,node* &tail,int data,int pos){
    if(pos == 0){
        InsertAtBeg(head, tail, data);
        return;
    }
    else if(pos >= length(head)){
        InsertAtEnd(head, tail, data);
        return;
    }
    else{
        node *temp = head;
        int jump = 1;
        while(jump <= pos-1){
            temp = temp->next;
            jump++;
        }
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

void Print(node* head){
	while(head!=NULL){
		cout<<head->data<<"-->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}

node *searcher(node *head, int key){
    while(head != NULL){
        if(head->data == key){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

node *recSearcher(node *head, int key){
    if(head == NULL){
        return NULL;
    }
    if(head->data == key){
        return head;
    }
    return (recSearcher(head->next, key));
}

void deleteatbeg(node *&head , node *&tail){
    if(head == NULL){
        return;
    }
    else if(head->next == NULL){
        delete head;
    }
    else{
        node *n = head;
        head = head->next;
        delete n;
    }
}
/*
void deleteatend(node *&head , node *&tail){
            if(head == NULL){
                return ;
            }
            else if(head->next == NULL){
                delete head ;
                head = tail = NULL;
            }
            else{
                node *temp = head;
                while(temp->next != tail){
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                temp->next = NULL;
            }
}

void deleteatmid(node *&head, node *&tail ,int pos){
        if(pos == 0){
            deleteatbeg(head , tail);
        }
        else if(pos >= length(head)){
            return;
        }
        else{
            node *temp = head;
            int jump = 1;
            while(jump <= pos-1){
                temp = temp->next;
                jump++;
            }
            node*n = temp->next;
            temp->next = n->next;
            delete n;
        }
}

int mid(node *head){
    if(head == NULL || head->next){
        return head->data;
    }
    node *slow = head;
    node *fast = head->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow->data;
}

node *Rev_linkedList(node *head){
    if(head == NULL && head->next == NULL){
                return NULL;
    }
    node *temp = head;
    while(temp != NULL){
        temp = temp->next;
    }
    temp = head;
    node *prev = NULL;
    node *current = head;
    node *n;
    while(current != NULL){
        n = current;
        current = current->next;
        n->next = prev;
        prev = n;
    }
    head = prev;
    return head;
}

void rev(node *head, int k){
    node *current = head;
    node *n;
    node *prev = NULL;
    int count = 0;
    while(count <k && current != NULL){
        next = current;
        current = current->next;
        n->next = prev;
        prev = n;
    }
    head = prev;
    if(n->next != NULL){
        return rev(head->next, k);
    }
    return head;
}

int DetectLoop(node *head){
    if(head == NULL){
        return 0;
    }
    if(head->next == NULL){
        return 1;
    }
    node *slow = head;
    node *fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            return 1;
        }
    }
    return 0;
}

void DetectAndRemove(node *head){
    if(head == NULL || head->next == NULL){
        return;
    }
    node *fast = head;
    node *slow = head;
    slow = slow->next;
    fast = fast->next->next;

    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast == slow){
        slow = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast = fast->next;
}

node *Merge(node *h1, node *h2){
    if(h1 == NULL && h2 != NULL){
        return h2;
    }
    if(h1 != NULL && h2 == NULL){
        return h1;
    }
    node *p;
    if(h1->data < h2->data){
        p = h1;
        p->next = Merge(h1->next, h2);
    }
    else{
        p = h2;
        p->next = Merge(h1,h2->next);
    }
    return p;
}

node *Merge_sort(node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *m = mid(head);
    node *a = head;
    node *b = m->next;
    a = Merge_sort(a);
    b = Merge_sort(b);
    node *nayaHead = Merge(a,b);
    return nayaHead;
}

node *mid(node *head){
    if(head==NULL || head->next==NULL){
		return head;
	}
	node *slow = head;
	node *fast = head->next;
	while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
	}
	return slow;
}

*/

/*node *seg(node *head){
    node *temp = head;
    int count[3] = {0,0,0};
    while(temp != NULL){
        count[temp->data] += 1;
        temp = temp->next;
    }
    temp = head;
    int i = 0;
    while(temp != NULL){
        if(count[i] == 0){
            i++;
        }
        else{
            temp->data = i;
            --count[i];
            temp = temp->next;
        }
    }

}
*/

/*
bool anagram(char *inp1, char *inp2, int n1, int n2){
    int count[NO_OF_CHARS] = {0};
    if(n1 != n2){
        return false;
    }
    for(int i = 0; i < n1; i++){
        count[inp1[i]]++;
        count[inp2[i]]--;
    }
    for(int i = 0; i < NO_OF_CHARS; i++){
        if(count[i]){return false;}
    }
    return true;
}
*/

int main()
{   int count[3] = {0,0,0};
    char a[] = {'a','b','c','a','c','b','b','c','a','a'};
    for(int  i = 0; i < sizeof(a); i++){
        count[a[i]]++;
    }
    for(int i = 0 ; i< 3;i++){
        cout<<count[i]<<endl;
    }
    return 0;
}
