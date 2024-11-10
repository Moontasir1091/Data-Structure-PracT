/* Bast case TC :- O(n) : list already sorted
    Average:- O(n^2) randomly ordered
    Worst: O(n^2) list reverse ordered */

#include<bits/stdc++.h>
using namespace std;
void insertionSORT(int arr[], int n){
for(int i=1;i<n;++i){
    int temp = arr[i];
    int j = i-1;

    while(j>=0 && arr[j]>temp){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
}
cout << "SORTED ARRAY:- ";
for(int i=0;i<n;++i){
    cout << arr[i] << " ";

}
cout << endl;
}

int main(){
    int n; cin >> n;
    int arr[n+100];
cout << "UNSORTED ARRAY:- ";
for(int i=0;i<n;++i){
   cin >> arr[i];
}
insertionSORT(arr,n);

}







