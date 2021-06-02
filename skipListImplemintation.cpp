#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>


using namespace std;
const int MAX_LEN = 50;



struct Node {
 public:
  
  int key;
  Node * up;
  Node * down;
  Node * next;
  Node * prev;
  

  //  Constructor
  Node( int  key) {
    this->key = key;
    this->next = nullptr;
    this->prev = nullptr;
    this->up = nullptr;
    this->down = nullptr;}
    
   void nodePrintData(); 
    
  };





class SkipList {
 public:
 
  vector<Node*> Heads;
  
  int Levels; 
  
  
  SkipList();

  
  void insert(int N);

  
  Node * insert_to_level(int N, int level, Node * down);  

  
  void printData();
  
  void findMinAndMax();

  
  Node * Search(int key);

  
  void Delete(int N);

  
  void Delete_Node(Node * N);

  

   
};

void Node :: nodePrintData(){
cout << this->key;
}

SkipList::SkipList() {
  // head 1 and tail 1 is in level 0 of the skip list  head --------> tail
  Node * Head1 = new Node ((int)-INFINITY);

  Node * Tail1 = new Node ((int)INFINITY);

  Head1->next = Tail1;

  Tail1->prev = Head1;

  Heads.push_back(Head1);
}



Node* SkipList::Search(int key) {
  Node* topleft;
  topleft = Heads[Heads.size() - 1]; // to get the top level left node 
  Node* p = new Node((int)INFINITY*-1);
  p = topleft;
  while (p != nullptr) {
    if (p->key == key) {
      break;
    } 
    else if (key > p->key && key < p->next->key) {
      p = p->down;
    }
    else if (key > p->key && key >= p->next->key) {
      p = p->next;
    } 
  }
  return p;
}


Node* SkipList::insert_to_level(int data, int level, Node* Down) {
  
  Node* newNode = new Node(data);
  newNode->down = Down;
  Node* p = new Node(0);
  p = Heads[level];

  while (p->next != nullptr && data > p->next->key) {
    p = p->next;
  }
  newNode->prev = p;
  newNode->next = p->next;
  p->next = newNode;
  newNode->next->prev = newNode;
  return newNode;
}

// Insert to skip list function

void SkipList::insert(int data) {
  int i = 0;
  Node* Down = insert_to_level(data, i, nullptr);  // Insert data to bottom level
  
  int CoinFlip = rand() % 2;
  while (CoinFlip == 0) {
    i++;
    if (Levels < i) {
      Levels += 1;
      Node* NewHead = new Node((int)-INFINITY);
      Node* NewTail = new Node((int)INFINITY);
      NewHead->next = NewTail;
      NewTail->prev = NewHead;
      Heads[i - 1]->up = NewHead;
      NewHead->down = Heads[i - 1];
      Heads.push_back(NewHead);
    }
    Node* newNode = insert_to_level(data, i, Down);
    Down->up = newNode;
    Down = newNode;
    CoinFlip = rand() % 2;
  }
  return;
}


void SkipList::Delete(int deleteNodeKey) {
  Node* p = Search(deleteNodeKey);
  while (p != nullptr) {
    Node* temp = p->down;
    Delete_Node(p);
    p = temp;
  }
}


void SkipList::Delete_Node(Node* deleteNode) {
  if (deleteNode->down != nullptr) 
     deleteNode->down->up = nullptr;
  if (deleteNode->up != nullptr) 
    deleteNode->up->down = nullptr;
  Node* Next = deleteNode->next;
  Node* Prev = deleteNode->prev;
  Prev->next = Next;
  delete (deleteNode);
  Next->prev = Prev;
}



void SkipList::printData() {
  
    Node* pt = new Node((int)-INFINITY);
    pt = Heads[0];
    pt = pt -> next;
    cout<<"[";
    while (pt->next != nullptr) {
      
      pt->nodePrintData() ;
      pt = pt->next;
      if (pt->next!=nullptr)
      cout<<",";
      
    }
    
    cout <<"]"<< endl;
  
}






void SkipList::findMinAndMax() {
    int min , max;
    min = max =0;
    Node* pt = new Node((int)-INFINITY);
    pt = Heads[0];
    pt = pt -> next;
    min = pt->key;
    
    while (pt->next != nullptr) {
      
      //max is worst case it takes longest time
      max = pt->key;
      pt = pt->next;
      
      
    }
    cout <<"["<<max<<"]"<<endl;
     cout <<"["<<min<<"]"<<endl;
    
    
  
}





void insert (SkipList *mySL){
int key;
char tmp;
cin >> tmp ;
cin >> key;
mySL->insert(key);
cin >>tmp;

}


void deleteI (SkipList *mySL){
int key;
char tmp;
cin >> tmp ;
cin >> key;
mySL->Delete(key);
cin >>tmp;

}

void search (SkipList *mySL){
int key;
char tmp;
cin >> tmp ;
cin >> key;

Node * pt = mySL->Search(key);
if (pt == nullptr){
cout << "[No]"  <<endl ;
}
else
cout << "[Yes]"  <<endl ;



cin >>tmp;

}


int main() {
    int inputNumber , opNumber ;
    cin >> inputNumber ;
    cin>> opNumber ; 
    char tmp ; 
    char opKind;
    SkipList *mySL = new SkipList();
    
    
    for (int i = 0 ; i <inputNumber;i++){
     cin >> tmp; 
     cin >> opKind;
     
     insert(mySL);
     
    }
    
    for (int i = 0; i< (opNumber-inputNumber) ; i++){
    cin >> tmp; 
    cin >> opKind;
    if (opKind == 's'){
    search(mySL);
    }
    else if (opKind == 'd'){
    deleteI(mySL);
    }
    
    }
    mySL->findMinAndMax();
    mySL->printData();
   
    
    
    return 0;
}
