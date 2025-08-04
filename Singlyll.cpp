#include <iostream>
#include <vector>

using namespace std;

class Node {

    public:
    //instanciate
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
//constractor data and its nxt address
        data = data1;
        next = next1;
    }

    Node(int data1){
//INITIALIZE node of one data(if te list as one elt)
        data= data1;
        next = nullptr;
    }
};


Node* convertArr2LL(vector<int> &arr){

    Node* head = new Node(arr[0]);
    //create head od ll to first elt of array 

    Node* moverHead = head; 

    for(int i =1 ; i< arr.size(); i++){

        Node* tempNode = new Node(arr[i]);

        moverHead -> next = tempNode;

        moverHead = tempNode;

    }
     return head;
}


Node* insertHead(Node* head, int value){

    Node* newNode = new Node(value);

    newNode -> next = head;

    head = newNode;

    return head;
}

Node* insertTail(Node* head, int value){

    Node* moverHead = head;

    while(moverHead -> next != NULL){

        moverHead = moverHead -> next;

    }

    Node* newNode = new Node(value);

    moverHead -> next = newNode;


    return head;


}


Node* insertKthNode(Node* head, int value, int k){
    Node* moverHead = head;
    int count  = 0;
    while(moverHead){
        count++;
        if(count == k - 1){
            Node* temp = moverHead -> next;

            Node* newNode = new Node(value);

            moverHead ->next = newNode;

            newNode -> next = temp;}
            moverHead = moverHead ->next;
    }
    return head;}
Node* removeHead(Node* head ){
    if(head ==NULL||head ->next==NULL){
        return NULL;
    }
    Node* temp=head ;
    head=head->next;
    delete temp;
    return head ;
}

Node* removeTail(Node* head ){
    if(head ==NULL||head ->next==NULL){
        return NULL;
    }
    Node*temp=head;
    Node* mover=temp->next;

    while (mover->next!=NULL)
    {
        temp=temp->next;
        mover=mover->next;
       
    }
    temp->next=NULL;
    delete mover;
    return temp;
    }

void print(Node* head){

    Node* moverHead = head;

    while(moverHead != NULL){

        cout<< moverHead -> data << " -> ";

        moverHead = moverHead -> next;

    }
    cout<<"NULL";
    cout<< '\n';
}
int main() {
    vector<int> arr;
    int n, val;

    // Read the number of elements in the list
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    // Read the elements of the list
    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        arr.push_back(val);
    }

     Node* head = convertArr2LL(arr);
    cout << "Original Linked List: ";
    print(head);

    // Insert at head (0) and print
    Node* head2 = insertHead(head, 0);
    cout << "After inserting 0 at head: ";
    print(head2);

    // Insert at tail (6) and print
    Node* head3 = insertTail(head2, 6);
    cout << "After inserting 6 at tail: ";
    print(head3);

    // Insert at k-th position (9 at position 3) and print
    Node* head4 = insertKthNode(head3, 9, 3);
    cout << "After inserting 9 at position 3: ";
    print(head4);

    // Remove head and print
    Node* head5 = removeHead(head4);
    cout << "After removing head: ";
    print(head5);

    // Remove tail and print
    Node* head6 = removeTail(head5);
    cout << "After removing tail: ";
    print(head6);

    return 0;
}