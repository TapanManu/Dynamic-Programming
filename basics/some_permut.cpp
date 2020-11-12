#include <iostream>
#include <bits/stdc++.h>

//program to print some of permutations

using namespace std;

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void disp(int arr[],int n){
    for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
    cout<<endl;
}


void permutation(int arr[],int n){
    if(n==1)    {cout<<arr[0]; return;}
    int p = 0;
    int i = 0;
    int count=0;
    int start = arr[p];
    do{
        i = (++i)%n;
        if(arr[p]!=arr[i]){
            swap(arr[i],arr[p]);
            disp(arr,n);
            count++;
        }
    }while(p!=i || arr[p]!=start);
    cout<<count;
}

int main(){
    int a[] = {1,2,3,4};
    int n = sizeof(a)/sizeof(a[0]);
    permutation(a,n);
    return 0;
}
