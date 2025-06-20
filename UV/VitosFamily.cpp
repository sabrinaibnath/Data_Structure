#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void Merge(vector<int> &arr, int low, int mid, int high){
    int h = low, i = 0, j = mid + 1; 

    vector<int> b(high - low + 1); 

    while((h <= mid) && (j <= high)){
        if(arr[h] <= arr[j]){
            b[i] = arr[h];
            h++;  
        }
        else{
            b[i] = arr[j]; 
            j++;  
        }
        i++; 
    }
 
    if(h > mid){
        for(int k = j; k <= high; k++){
            b[i] = arr[k];
            i++;
        }
    }

    else{
        for(int k = h; k <= mid; k++){
            b[i] = arr[k];
            i++;
        }
    }
    
    
    for(int k = low, x = 0; k <= high; k++, x++){
        arr[k] = b[x];
    }
}


void MergeSort(vector<int> &arr, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;  
        MergeSort(arr, low, mid);  
        MergeSort(arr, mid + 1, high);  
        Merge(arr, low, mid, high); 
    }
}

int main(){
    
    ios::sync_with_stdio(false); // Improves input speed
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n) ;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        MergeSort(arr, 0, n - 1);
        
        int median = 0;
        if(n % 2 != 0){
            median = arr[n/2];
        }
        else{
            median = (arr[n/2] + arr[(n/2) - 1]) / 2;
        }
        
        int tot_dis = 0;

        for (int i = 0; i < n; i++) {
           tot_dis += abs(arr[i] - median);
        }
        
        cout << tot_dis << endl;

    }
    
    return 0;
}