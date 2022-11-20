#include <iostream>
using namespace std;


class linkedList{

private:

struct node{
    string nilai;
    node *next;
    node *prev;
};

public:

node *head = NULL;

void insertBack(string newData){
    node *newNode = new node();
    newNode->nilai=newData;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
    }
    else{
        node *temp=head;
        while(temp->next != NULL){
            temp = temp->next;
           
        }

         temp->next=newNode;
    }
}

void insertFront(string newData){
    node *newNode=new node();
    newNode->nilai=newData;
    newNode->next=head;
    head=newNode;

}

void insertMiddle(string newValue, int n){
    int flag=1;
    node *newNode = new node();
    newNode ->nilai = newValue;
    node *tempBefore;
    node *tempAfter = head;

    if (n == 1){

        insertFront(newValue);

         
    }

    else{
        while (tempAfter != NULL && flag < n ){
            flag++;
            tempBefore = tempAfter;     //this set the tempBefore variable to the same position as the tempAfter before in the next line we traverse the tempAfter one step more
            tempAfter = tempAfter -> next;
        }

        tempBefore -> next = newNode;   // set the tempBefore pointer to point to the newNode
        newNode -> next = tempAfter;    // set the newNode pointer to point to the tempAfter its position
    }

}

void insertMiddle_2(string newValue, int n){
    int flag=1;
    node *newNode = new node();
    newNode ->nilai = newValue;
    node *tempBefore;
    node *tempAfter = head;

    if (n == 1){

        insertFront(newValue);

         
    }

    else{
        while (tempAfter != NULL && flag < n ){
            flag++;
            tempBefore = tempAfter;         //this set the tempBefore variable to the same position as the tempAfter before in the next line we traverse the tempAfter one step more
            tempAfter = tempAfter -> next;
        }

        tempBefore -> next = newNode;   // set the tempBefore pointer to point to the newNode
        newNode -> next = tempAfter;    // set the newNode pointer to point to the tempAfter its position

    
    }


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

void displaylist(){
node*temp=head;
int i = 0;

if(temp!=NULL){
    
    while(temp!=NULL){
    i++;
    cout << i <<". "<<temp->nilai<<" ";
    temp=temp->next;
    cout << endl;
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
void isExist(string n){
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

int listSize(){
    int flag=0;
    node *temp;
    temp=head;
    if(head==NULL){
        return 0;
    }
    while(temp!=NULL){
        flag++;
        temp=temp->next; // traverse through the list
    }
    return flag;
}

string at(int n){
    node*temp = head;
    int i = 1;

    if(temp!=NULL){
        
        while(temp != NULL && i <= n-1){
        i++;
        temp=temp->next;
        cout << endl;
        }
        return temp -> nilai;
        cout<<endl;
    }

    return "(not found)";
}




};


int randomValue(int range){
	int a;
	
		a=(rand()%range)+1;
		return a;
	
	
}



