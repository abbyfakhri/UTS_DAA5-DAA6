#include <iostream>
#include <vector>
using namespace std;

struct produk{
    string nama;
    double harga;
};

void inputKeranjang(vector <produk>&list){
    produk temp;
    char opt = 'a';

    while(opt != 't'){
        cout << "masukkan nama produk: ";
        cin >> temp.nama;
        cout << "tekan t untuk mengakhiri program: ";
        cin >> opt;
    }

    cout << "input selesai"<< endl;

    

    
}

int main(){
    vector <produk> list;

    produk temp;

    for(auto i:list){

        cout << "masukkan nama: ";
        cin >> i.nama;
        cout << "masukkan harga: ";
        cin >> i.harga;

    }
}