#include <iostream>
#include "linkedList.h"
using namespace std;





class musicPlayer{

    public:

    linkedList list;

    

    void showPlaylist(){
        list.displaylist();
    }


    void playMusic(){   // no out from this function feature yet
        int opt = 0;
        int n = list.listSize();
        list.displaylist();

        cout << "pilih lagu yang ingin diputar (by Index): " << endl;
        cin >> opt;
        
        if (opt >= 1 && opt <= n){
                cout << endl;
                cout << list.at(opt) <<" sedang dimainkan" << endl;
                cout << endl;
        }
        else{
            cout << endl;
            cout << "lagu tidak ditemukan, coba lagi" << endl;
            cout << endl;
            playMusic();
            return;
        }
   
    }



    void loopTest(){
        while (true){
            playMusic();
        }
    }




    
};

void insert_demo_data(linkedList &list){


    string laguBatak[] = {"Tarpaima - Osen Hutasoit","Dongan Martua - Cendana Trio","Poda - Vicky Sianipar","Rap - Style Voice","Mardua Holong - Omega Trio"};

    int n = sizeof(laguBatak)/sizeof(laguBatak[0]);

    for (int i=0; i<n; i++){
        list.insertBack(laguBatak[i]);
    }

}


void insert_demo_data_2(linkedList &list){


    string laguBatak[] = {"Rich Flex - Drake","Major Distribution - Drake","Spin Bout U - Drake"};

    int n = sizeof(laguBatak)/sizeof(laguBatak[0]);

    for (int i=0; i<n; i++){
        list.insertBack(laguBatak[i]);
    }

}



void driver(){

    musicPlayer playlist1;
    musicPlayer playlist2;

    insert_demo_data(playlist1.list);
    insert_demo_data_2(playlist1.list);

    playlist2.showPlaylist();

    playlist1.loopTest();

    

    
    
}


/*


features
1. next 
2. previous
3. loop 
4. shuffle  



*/



int main(){

    
driver();
    



}