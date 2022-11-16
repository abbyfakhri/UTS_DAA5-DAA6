#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

struct produk{
    string namaItem;
    double hargaItem;
    int jumlahItem;
};

void display(vector <produk> &list,string nama){
    if(nama == "keranjang"){
        cout << "Daftar item pada Keranjang"<<endl;
    }
    else if(nama == "inventory"){
        cout << "Daftar item pada Inventory"<<endl;
    }
    else{
        cout << "INVALID FUNCTION ARGUMENT"<<endl;
    }
    for(produk i: list){
        cout <<"nama item: " <<i.namaItem << endl;
        cout <<"harga/item: "<< i.hargaItem << endl;
        cout << "jumlah item: "<<i.jumlahItem << endl;
        cout << "total harga item: "<<i.jumlahItem*i.hargaItem << endl;
        cout << endl;
    }
}



void totalHarga(vector <produk> &list){
    
    double sum = 0;
    for(produk i:list){
        sum = sum + (i.jumlahItem*i.hargaItem);
    }
    
    cout << "Total Harga = "<<sum << endl;
    
}

void inputInventory(vector <produk>&list){
    produk temp;
    char opt = 'x';

    while(opt != 'b'){
        cout << "masukkan nama produk: ";
        cin >> temp.namaItem;
        cout << "masukkan harga produk: ";
        cin >> temp.hargaItem;
        cout << "masukkan jumlah produk: ";
        cin >> temp.jumlahItem;

        list.push_back(temp);
        cout << "lanjut input (a): "<< endl;
        cout << "berhenti input (b): "<< endl;

        cin >> opt;

    }

    cout << "input selesai"<< endl;

    cout << endl;
    
}

bool isExist(produk *temp,vector <produk> listInventory){
    for(produk i:listInventory){
        if(temp -> namaItem == i.namaItem ){
            temp -> hargaItem = i.hargaItem;
            return true;
        }
    }

    return false;
}

void inputKeranjang(vector <produk>&list,vector <produk> listInventory){
    produk temp;
    char opt = 'x';

    while(opt != 'b'){
        cout << "masukkan nama produk: ";
        cin >> temp.namaItem;
        cout << "masukkan jumlah item: ";
        cin >> temp.jumlahItem;
        cout << endl;

        if(isExist(&temp,listInventory) == true){
            list.push_back(temp);
            cout << "produk "<<temp.namaItem<<" BERHASIL dimasukkan ke dalam keranjang"<< endl;
        }
        else{
            cout << "produk "<<temp.namaItem<<" TIDAK ditemukan di inventory"<<endl;
        }
        cout << endl;
        
        cout << "lanjut input (a): "<< endl;
        cout << "berhenti input (b): "<< endl;

        cin >> opt;
    }

    cout << endl;
    cout << "input selesai"<< endl;
    

    cout << endl;
    
}

void dummyInventoryData(vector <produk>&list){
    produk temp;
    temp.namaItem = "kondom";
    temp.hargaItem = 100;
    temp.jumlahItem = 3;
    list.push_back(temp);

    temp.namaItem = "buku";
    temp.hargaItem = 200;
    temp.jumlahItem = 4;
    list.push_back(temp);

    temp.namaItem = "rokok";
    temp.hargaItem = 300;
    temp.jumlahItem = 5;
    list.push_back(temp);
}

void dummyKeranjangData(vector <produk> &list){
    produk temp;
    temp.namaItem = "kondom";
    temp.hargaItem = 100;
    temp.jumlahItem = 2;
    list.push_back(temp);

    temp.namaItem = "buku";
    temp.hargaItem = 200;
    temp.jumlahItem = 1;
    list.push_back(temp);

    temp.namaItem = "rokok";
    temp.hargaItem = 300;
    temp.jumlahItem = 3;
    list.push_back(temp);
}



void demo(vector <produk> &listInventory, vector <produk> &listKeranjang){
    
    dummyInventoryData(listInventory);
    //dummyKeranjangData(listKeranjang);
    
    display(listInventory,"inventory");
    inputKeranjang(listKeranjang,listInventory);
    display(listKeranjang,"keranjang");
    totalHarga(listKeranjang);

}

void menu(vector <produk> &listInventory, vector <produk> &listKeranjang){
    int opt = 0;
    cout << "Pilih 6 untuk DEMO Program"<< endl;
    cout << endl;
    cout << "1. Masukkan Daftar Belanja"<<endl;
    cout << "2. Hitung Total Belanja"<<endl;
    cout << "3. Masukkan Produk Baru ke dalam Inventory"<<endl;
    cout << "4. Demo Program"<< endl;
    cout << "5. Kembali ke menu" << endl;
    cout << "6. Akhiri Program"<< endl;
    

    cout << "Pilih Menu: ";
    cin >> opt;

    // add switch case for menu later

    switch (opt)
    {
    case 1:
        inputKeranjang(listInventory,listKeranjang);
        break;
    case 2:
        totalHarga(listKeranjang);
        break;
    case 3:
        inputInventory(listInventory);
        break;
    case 4:
        demo(listInventory,listKeranjang);
        break;
    case 5:
        menu(listInventory,listKeranjang);
        break;
    case 6:
        cout << "program selesai"<<endl;
        exit(10);
        break;

    default:
        cout << "Input Invalid" << endl;
        break;
    }
    
}


int main(){
    // main variables
    vector <produk> listInventory;
    vector <produk> listKeranjang;

    menu(listInventory,listKeranjang);

}