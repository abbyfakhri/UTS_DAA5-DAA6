#include <iostream>
using namespace std;

struct dataMahasiswa{
    
    string nama;
    int nim;
};

void demoData(dataMahasiswa getData[],int n){
    
int nim[50] = {
		
                        211401069,
                        211401140,
                        211401023,
                        211401096,
                        211401093,
                        211401029,
                        211401044,
                        211401040,
                        211401014,
                        211401049,
                        211401017,
                        211401125,
                        211401034,
                        211401037,
                        211401111,
                        211401108,
                        211401054,
                        211401083,
                        211401013,
                        211401043,
                        211401080,
                        211401086,
                        211401131,
                        211401020,
                        211401060,
                        211401114,
                        211401066,
                        211401089,
                        211401003,
                        211401134,
                        211401099,
                        211401105,
                        211401012,
                        211401063,
                        211401009,
                        211401006,
                        211401128,
                        211401051,
                        211401057,
                        211401026,
                        211401077,
                        211401123,
                        211401143,
                        211401074,
                        211401121,
                        211401137,
                        211401102,
                        211401117};

string nama[50]={
                        "ABBY FAKHRI CHOIRY",
                        "ADDINA NABILAH SIREGAR",
                        "ADI SARPAN ALAHUT HARAHAP",
                        "AHMAD GHALIB ATHARIQ",
                        "ALFAN ZEQUES SITEPU",
                        "ANNISAH FITHRI",
                        "CHRISTIAN VIGO NATHANAEL PURBA",
                        "CHRISTOFFEL DANIEL Y. TAMBUNAN",
                        "DEA OKTAVIA",
                        "DIAN ATIKA SUKMA NASUTION",
                        "DINAH FARRAS ULFIAH SIREGAR",
                        "FANNY FAUJANNAH",
                        "FATIHANNISA LISTY ZULMI",
                        "FELIX",
                        "FIRMAN ADI PUTRA NASUTION",
                        "HIGEN PUTRA PERANGIN ANGIN",
                        "HUSEIN IBNU MAHMUD",
                        "ILHAM ABRAR",
                        "ISMAIL DARMAJI",
                        "JOHANES ALBERTO SIAHAAN",
                        "KEVIN BAGUS WARDHANA",
                        "LIDYA ALYA ZAHRA",
                        "LISTIA M P SIMANJUNTAK",
                        "M. HAFIZ ARIYANDI",
                        "MEYSHA SABRINA AZ-ZAHRA",
                        "MHD IQBAL FAHRIZA MANURUNG",
                        "MIRANDA CANTIKA SIAHAAN",
                        "MUHAMMAD ABDI HANNAN ZIDANE",
                        "MUHAMMAD RAFLY RITONGA",
                        "MUHAMMAD RAJA INAL LUBIS",
                        "MUHAMMAD RIZQULLAH HARAHAP",
                        "NAFTALY BARIL AKUDEA",
                        "NAYATA SANDRA CLAUDIA NASUTION",
                        "NICHOLAS HANSEN",
                        "NURHALIMAH",
                        "RAMADHANA HASRIANSYAH M",
                        "RIZKY ALPARIJI",
                        "RIZKY AZMI SWANDY",
                        "RONALDO DAMIANUS PARULIAN SILITONGA",
                        "SAHRU PUTRA WAJIH S",
                        "SATRIA NARDO DIONYSIUS",
                        "SOHMONO SODIP MANIK",
                        "STEVEN IMMANOEL",
                        "VIPI MONICA CHRISTINA MANALU",
                        "WAHYUDI",
                        "YOGI NOVIANA",
                        "YUSUF KALLA",
                        "ZEFANYA NICHOLAS SIBARANI"
                        };

for (int i = 0; i < n;i++){
    getData[i].nim = nim[i];
    getData[i].nama = nama[i];
   
    
}

}


void swapStruct(dataMahasiswa *a, dataMahasiswa *b){
    dataMahasiswa temp;

    temp = *a;
    *a = *b;
    *b = temp;


}



int divideArr(dataMahasiswa record[],int minIndex, int maxIndex){

    int pivot = record[maxIndex].nim;
    int i = minIndex - 1;

    for (int j = minIndex; j < maxIndex;j++){
        if(record[j].nim <= pivot){
            i++;

            swapStruct(&record[i],&record[j]);
           
        }
    }


    swapStruct(&record[i+1],&record[maxIndex]);

    return(i+1);


}



void quickSort(dataMahasiswa record[],int minIndex, int maxIndex){
    if(minIndex < maxIndex){

        int pivot = divideArr(record,minIndex,maxIndex);
        

        // left
        quickSort(record,minIndex,pivot-1);    


        // right
        quickSort(record,pivot+1,maxIndex);            
    }
}

void printRecord(dataMahasiswa record[],int n){
    for(int i=0; i<n; i++){
            cout <<i+1<<". | " <<record[i].nim << " | " << record[i].nama << endl;
            cout <<"----------------------------------------------" <<endl;
        }
}

int main(){

    cout << endl;
    
    dataMahasiswa komC[50];

    demoData(komC,48);

    cout << "DATA SEBELUM SORTING"<< endl;
    cout <<"----------------------------------------------" <<endl;
    printRecord(komC,48);

    quickSort(komC,0,47);
    
    cout <<endl;
    cout << "Tekan ENTER untuk menampilkan data setelah Sorting";
    cin.ignore();
    cout << endl;
    cout << "DATA SETELAH SORTING"<< endl;
    cout <<"----------------------------------------------" <<endl;

    printRecord(komC,48);

    
}