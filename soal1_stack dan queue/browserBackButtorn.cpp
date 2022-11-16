#include <iostream>
#include <stack>
using namespace std;

int main(){
// browser back button

stack <string> data;

string input;

int n=5;

while (n>0){
    cout << "masukkan URL: ";
    cin >> input;
    data.push(input);
    n--;
}
char a;




do{
    cout << "would you like to go to the previous page? y/n ";
    cin >> a;
    if(a == 'y') {
        data.pop();
    cout << "now you're on the page of "<<data.top()<<endl;
    cout << endl;
    n--;
    }
    
}while(n='y');





}