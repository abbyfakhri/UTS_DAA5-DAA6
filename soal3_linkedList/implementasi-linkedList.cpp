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
        char opt;
        
        list.displaylist();
        cout << "play by index (a) / music control (prev, next, loop, shuffle) (b): ";
        cin >> opt;

           if (opt == 'a'){
                playByIndex();
           } 
            else if(opt == 'b'){ 
                music_control();
            }


    }

    void playByIndex(){
        int opt;
        int n = list.listSize();
        list.displaylist();
        cout << "pilih lagu yang ingin diputar (by Index): " << endl;
        cin >> opt;
        
        if (opt >= 1 && opt <= n){
                cout << endl;
                cout << list.at(opt) <<" sedang dimainkan" << endl;
                cout << endl;

                return;

        }
        else{
            cout << endl;
            cout << "lagu tidak ditemukan, coba lagi" << endl;
            cout << endl;
            playMusic();
            return;
        }
    }

    void music_control(){

        int opt;
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
            music_control();
            
        }
        

        string opt2;
        
        
        
        while(opt >= 1 && opt <= n){

            cout << "music control ( prev, loop, next, shuffle, out )" << endl;
            cout << "input: "; cin >> opt2;
            cout << endl;

            // i should've make these as switch case

            if(opt2 == "prev"){

                cout << endl;
                cout << list.at(opt-1) <<" sedang dimainkan" << endl;
                cout << endl;
                opt--;
             }

            else if(opt2 == "next"){

                cout << endl;
                cout << list.at(opt+1) <<" sedang dimainkan" << endl;
                cout << endl;
                opt++;

            }

            else if(opt2 == "loop"){
                cout << endl;
                cout << list.at(opt) <<" sedang dalam loop" << endl;
                cout << endl;
            }

            else if(opt2 == "shuffle"){
                cout << endl;
                cout << list.at(randomValue(n)) <<" sedang dimaninkan" << endl;
                cout << endl;
            }
            else{
                    cout << endl;
                    cout << "out of music control" << endl;
                    cout << endl;
                    playMusic();
                    

                }

        }
        

        return;

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