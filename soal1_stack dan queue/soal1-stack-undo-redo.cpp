#include <iostream>
#include <stack>
using namespace std;

void input(stack <string> &data, int *n){

    string temp;
    char opt = 'm';
    while (opt != 't'){
        cout << "masukkan URL: ";
        cin >> temp;
        data.push(temp);
        *n++;

        cout << "Masukkan (t) Untuk Mengakhiri Input: "<< endl; 
        cout << "Masukkan Sembarang Untuk Melanjutkan Input: " << endl;
        cin >> opt;
    }

}

void undo_redo(stack <string> &data1, int *n){

string opt;
string temp;
stack <string> data2;

int rem = *n;

cout << endl;
while(rem > 1){
    cout << "ingin melakukan UNDO atau REDO? input -> (undo/redo) : ";
    
    cin >> opt;
    if(opt == "undo") {
        temp = data1.top();
        data2.push(temp);
        data1.pop();

        cout << "Anda sekarang berada di halaman: "<<data1.top()<< endl;
        cout << endl;
        rem--; 
    }
    else if(opt == "redo"){

        temp = data2.top();
        data1.push(temp);
        data2.pop();
        cout << "Anda sekarang berada di halaman: "<<data1.top()<< endl;
        cout << endl;
        rem++;

    }
}

}

void dummyData(stack <string> &data,int *dataSize){

    string arr[] = {"google.com","kiyowoaf.com","auh-ah-pengen-beli-trek.com","facebook.com","anjay.id","DAAbismillah-A.amin","pujituhan-Yesus.id"};
    int n = sizeof(arr)/sizeof(arr[0]);
    *dataSize = n;
    for(int i=0; i<n; i++){
        data.push(arr[i]);
    }

}


int main(){

cout << endl;
cout << "Program Undo - Redo" << endl;

stack <string> history;

int n = 0;

// input(data1,&n);   to input your own data

dummyData(history,&n);


undo_redo(history,&n);

}
