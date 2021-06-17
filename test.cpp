#include<iostream>
#include<string>
#include <algorithm>
#include<vector>
#include<math.h>
using namespace std;

void radixSort(int arr[], int n){

    int arr1Sub[n];
    int arr2Sub[n];
    int nummax = arr[0];
    for(int i=1; i<n; i++){ // tim k scs lon nhat
        if(arr[i] > nummax)
            nummax = arr[i];
    }
    string numMax = to_string(nummax);
    int k = numMax.length();

    for(int i=0; i<n; i++){// tao mang phu = mang cu
            arr1Sub[i] = arr[i];
        }

    for(int j=0; j < k; j++){
        for(int i=0; i<n; i++){// tao mang phu = mang cu
            arr1Sub[i] = arr[i] / pow(10,j);
            arr2Sub[i] = arr[i];
        }
        vector <int> arrsub2[10];
        for(int i=0; i<n; i++){
            int x = arr1Sub[i]%10;
            arrsub2[x].push_back(arr2Sub[i]);
        }
        int Count = 0;
        for(int i=0; i<10; i++){
            reverse(arrsub2[i].begin(),arrsub2[i].end());
            while(arrsub2[i].empty()!= true){
                int a = arrsub2[i].back();
                arrsub2[i].pop_back();
                arr[Count] = a;
                arr1Sub[Count] = arr[Count];
                Count++;
            }
        }
    }
}

void selectionSort(int arr[], int n){

    for(int i = 0; i< n-1; i++){
        int curMin = i;
        for(int j = i +1; j<n ; j++){
            if(arr[j] < arr[curMin])
                curMin = j;
        }
        swap(arr[i], arr[curMin]);
    }
}
void bubbleSort(int arr[], int n){
    while(n > 0){
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
        }
        n--;
    }
}
void countSort(int arr[], int n){
    int arrCount[10000]={};
    for(int i=0; i<n; i++){
        arrCount[arr[i]]++;
    }

    int Count =0;
    for(int i=0; i<10000; i++){
        if(arrCount[i]!=0){
            arr[Count] = i;
            Count++;
        }

    }

}
int main(){
    int arr[] = {3211, 1, 10, 9680, 577, 9420, 7, 5622, 4793, 2030, 3138, 82, 2599, 743, 4127};
    int length = sizeof(arr)/ sizeof(arr[0]);
    //radixSort(arr,length);
    //selectionSort(arr, length);
    //bubbleSort(arr, length);
    countSort(arr, length);
    for(int i=0; i<length; i++){
        cout << arr[i]<< endl;
    }
    return 0;
}
