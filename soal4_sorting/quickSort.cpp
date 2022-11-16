#include <iostream>
using namespace std;

void swap(int *m, int *n){
    int temp = *m;
        *m = *n;
        *n =  temp;
}

void print(int arr[], int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] <<" ";
    }
}

int divideArr(int arr[], int minIndex, int maxIndex){

    int pivot = arr[maxIndex];
    int i = minIndex - 1;

    for (int j = minIndex; j < maxIndex;j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[maxIndex]);

    return(i+1);


}

void quickSort(int arr[],int minIndex, int maxIndex){
    if(minIndex < maxIndex){

        int pivot = divideArr(arr,minIndex,maxIndex);


        // left
        quickSort(arr,minIndex,pivot-1);    


        // right
        quickSort(arr,pivot+1,maxIndex);            
    }
}

int main(){



int arr[100] =  {87, 90,37,	31,	78,
                22,	16,	20,	45,	45,
                93,	10,	4,	57,	14,
                7,	41,	43,	15,	15,
                57,	46,	14,	24,	27,
                43,	62,	20,	9,	24,
                50,	46,	43,	11,	13,
                32,	83,	38,	49,	41,
                6,	10,	12,	72,	45,
                29,	33,	40,	1,	72,
                85,	93,	62,	28,	81,
                83,	74,	80,	50,	67,
                55,	20,	52,	55,	19,
                80,	98,	58,	52,	43,
                90,	83,	85,	60,	72,
                77,	71,	26,	83,	45,
                59,	8,	19,	24,	1,
                70,	52,	79,	41,	77,
                4,	61,	48,	33,	75,
                30,	35,	53,	35,	77};

    quickSort(arr,0,100);

    print(arr,100);

}