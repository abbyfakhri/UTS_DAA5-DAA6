#include <iostream>
#include <chrono>
#include <thread>
#include <queue>
using namespace std;

void ambil_nomor_antrian(queue <int> &antrian, int *nomorAntrian){
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    int temp = *nomorAntrian;
    cout << "Tekan Enter Untuk Mengambil Nomor Antrian: ";
    //cin.ignore();
    cout << endl;
    antrian.push(temp);
    cout << endl;
    cout << "Nomor Antrian Anda Adalah: A-"<<antrian.back()<< endl;
    cout << "Silahkan Menunggu Giliran...." << endl;

    sleep_for(seconds(3));
    
}

void current_queue_demo_data(queue <int> &antrian){

    for(int i = 100; i <= 120;i++){
        antrian.push(i);
    }
}



int main(){

    cout << endl;

    queue <int> nomorAntrian;
    

    int n = 100;

    current_queue_demo_data(nomorAntrian);
    int temp = nomorAntrian.back();

    while(n > 0){
        n--;
        
        ambil_nomor_antrian(nomorAntrian,&temp);
        cout << endl;
        cout << "Pelanggan Dengan Nomor Antrian A-"<< nomorAntrian.front() <<" Segera Menuju Counter"<< endl;
        cout << endl;
        nomorAntrian.pop();
        temp++;
        


    }


}


