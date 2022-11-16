#include <iostream>
using namespace std;

class linkedList{
private:

struct node{
int nilai;
node *next;
};

node *head;

public:
linkedList(){
    head = NULL;
}
void insertBack(int newData){
    node *newNode=new node();
    newNode->nilai=newData;
    newNode->next=NULL;
    if (head==NULL){
        head= newNode;
    }
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp= temp->next;
           
        }
         temp->next=newNode;
    }
}

void insertFront(int newData){
    node *newNode=new node();
    newNode->nilai=newData;
    newNode->next=head;
    head=newNode;

}

void insertMiddle(int newData,int n){
    int flag=1;
    node *newNode=new node();
    newNode->nilai=newData;
    node *temp=head; node *temp2;
    if (n==1){
        insertFront(newData);
    }
    else{
        while(temp != NULL && (flag<n) ){
            flag++;
            temp2=temp;
            temp=temp->next;
        }
    }
    temp2->next=newNode;
    newNode->next=temp;
}

void erase(int n){
    int flag=1;
    node *temp=head; node *temp2;

      if(head==NULL){
        cout << "List Empty" << endl;
        return;
      }
      temp=head;
      if(n==1){
        head=head->next;
        free(temp);
        return;
      }
      else{
        while(temp != NULL && (flag<n)){
            flag++;
            temp2=temp;
            temp=temp->next;
        }
      }
      if(temp== NULL){
        cout << "position does not exist" << endl;
      }
      else{
        temp2->next=temp->next;
        free(temp);
      }
}

void display(){
node*temp=head;

if(temp!=NULL){
    cout << "the list contains: \n";

    while(temp!=NULL){
    cout << temp->nilai<<" ";
    temp=temp->next;
    }
    cout<<endl;
}

else{
    cout <<"the list is empty"<<endl;
}

}
void deleteList(){
    node *tempNode, *tempPtr;
    tempPtr=head;
    while(tempPtr){
        tempNode=tempPtr->next;
        free(tempPtr);
        tempPtr=tempNode;
    }
    head=NULL;
}
void isExist(int n){
    int flag=1;
    node *temp;
    temp=head;
    while(temp!=NULL){
        if((temp->nilai)==n){
            cout << "the value: "<<n<<" exist on the list at index "<<flag<<endl;
            return;
        }
        temp=temp->next;
        flag++;
        
    }
    cout << "the value: "<<n<<" does not exist on the list"<<endl;
}

void listSize(){
    int flag=0;
    node *temp;
    temp=head;
    if(head==NULL){
        cout << "the size of the list is "<<flag<<endl;
        return;
    }
    while(temp!=NULL){
        flag++;
        temp=temp->next; // traverse through the list
    }
    cout << "the size of the list is "<<flag<<endl;
}

};


int randomValue(int range){
	int a;
	
		a=(rand()%range)+1;
		return a;
	
	
}
void demo(){
linkedList myList,myList2;
myList.insertBack(5);
myList.insertBack(6);
myList.insertBack(7);
myList.insertFront(1);
myList.insertFront(8);
myList.insertMiddle(0,2);
myList.insertMiddle(100,3);
myList.erase(4);
//myList.deleteList();
myList.deleteList();
myList.display();
myList.listSize();

myList2.insertBack(1);
myList2.insertBack(2);
myList2.insertBack(3);
myList2.insertBack(4);
myList2.insertBack(5);
myList2.insertBack(5);
myList2.insertFront(12);
//myList2.erase(1);

//myList2.deleteList();
myList2.display();
myList2.isExist(4); 
myList2.listSize();
cout << endl;
}

int main(){

demo();
demo();

}