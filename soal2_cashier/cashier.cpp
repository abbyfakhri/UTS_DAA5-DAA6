#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;



class cashier{

    private:

    struct produk{
        string namaItem;
        double hargaItem;
        int jumlahItem;
    };

    vector <produk> listInventory;
    vector <produk> listKeranjang;

    void display(vector <produk> &list,string nama){
        if(nama == "keranjang"){
            cout << endl;
                cout << "Daftar item pada Keranjang"<<endl;
                cout << endl;
            }
        else if(nama == "inventory"){
            cout << endl;
                cout << "Daftar item pada Inventory"<<endl;
                cout << endl;
            }
        else{
                cout << "INVALID FUNCTION ARGUMENT"<<endl;
            }

        if(list.size() == 0){
            cout << "ITEM KOSONG"<< endl;
        }
        for(produk i: list){
            cout <<"nama item: " <<i.namaItem << endl;
            cout <<"harga/item: "<< i.hargaItem << endl;
            cout << "jumlah item: "<<i.jumlahItem << endl;
            cout << "total harga item: "<<i.jumlahItem*i.hargaItem << endl;
            cout << endl;
        }

        backtoMenu();

    }



void totalHarga(vector <produk> &list){
    
    double sum = 0;
    for(produk i:list){
            sum = sum + (i.jumlahItem*i.hargaItem);
        }
    
    cout << "Total Harga = "<<sum << endl;
    backtoMenu();
    
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

    backtoMenu();
    
}

bool isExist(produk *temp,vector <produk> &listInventory){
    int res = 0;
    for(produk i:listInventory){
        res = temp -> namaItem.compare(i.namaItem);
        if(res == 0){
            temp -> hargaItem = i.hargaItem;
            return true;
        }
    }

    return false;

}

void inputKeranjang(vector <produk>&list,vector <produk> &listInventory){
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
    
    backtoMenu();
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

void backtoMenu(){
    cout << endl;
    cout << "Tekan enter untuk kembali ke menu ";
    cin.ignore();
    cin.ignore();

    menu();
}

void deleteItem(vector <produk> &listKeranjang){
    string itemName;
    cout << "masukkan nama item yang ingin dihapus: ";
    //getline(cin,itemName);

    cin >> itemName;

    //int pos = listKeranjang.begin();
    int pos = 0;
    for(produk i: listKeranjang){
        if (itemName.compare(i.namaItem)==0){
            listKeranjang.erase(listKeranjang.begin()+pos);
            cout << "Produk "<<i.namaItem <<" Berhasil Dihapus"<< endl;
            
        }

        pos++;
    }

    cout << "Produk "<<itemName << "Tidak Ditemukan" << endl;
    
    backtoMenu();
    
    
}

public:

void menu(){
    int opt = 0;
    cout << endl;
    cout << "Pilih 4 untuk DEMO Program"<< endl;
    cout << endl;
    cout << "1. Masukkan Daftar Belanja"<<endl;
    cout << "2. Hitung Total Belanja"<<endl;
    cout << "3. Masukkan Produk Baru ke dalam Inventory"<<endl;
    cout << "4. Demo Program"<< endl;
    cout << "5. Tampilkan Isi Keranjang" << endl;
    cout << "6. Tampilkan Isi Inventory" << endl;
    cout << "7. Kembali ke menu" << endl;
    cout << "8. Akhiri Program"<< endl;
    cout << "9. Hapus item" << endl;
    
    cout <<endl;
    cout << "Pilih Menu: ";
    cin >> opt;
    cout << opt << endl;

    // add switch case for menu later

    switch (opt)
    {
    case 1:
        inputKeranjang(listKeranjang,listInventory);
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
        display(listKeranjang,"keranjang");
    case 6:
        display(listInventory,"inventory");
    case 7:
        backtoMenu();
        break;
    case 8:
        cout << "program selesai"<<endl;
        exit(10);
        break;
    case 9:
        deleteItem(listInventory);
        break;
    default:
        cout << "Input Invalid" << endl;
        backtoMenu();
        break;
    }
    
}

void demo(vector <produk> &listInventory, vector <produk> &listKeranjang){
    cout << endl;
    dummyInventoryData(listInventory);
    display(listInventory,"inventory");
    inputKeranjang(listKeranjang,listInventory);
    display(listKeranjang,"keranjang");
    totalHarga(listKeranjang);

    backtoMenu();
    

}


};


int main(){
    
    cashier counter1;
    counter1.menu();

}