#include<iostream>
#include<bits/stdc++.h>
#define max 11;
using namespace std;

//open hash table

struct symtab{
    int data;   
    symtab *next;   //next ptr in same index
    int occuppied;  //boolean to determine whether the place is filled
};

symtab *arr[11],*tmp,*headref[11];       //defines arr of size 11(prime required)

int hashmod(int data){
    return data%11;
}

symtab* createnode(int data){
    symtab* ptr = new symtab;
    ptr->data = data;
    ptr->occuppied = 1;     //place occuppied
    ptr->next=NULL;
    return ptr;
}



void disphash(symtab *headref[]){
    for(int i=0;i<11;i++){
        symtab* ptr = headref[i];
        while(ptr!=NULL){
            cout<<ptr->data<<"\t";
            ptr=ptr->next;
        }
        cout<<"\n";
    }
}


int main(){
    int d[] = {1,2,3,7,9,5,14,11,12,22,25,46,57,34,10,8};
    int len = sizeof(d)/sizeof(d[0]);
    for(int i=0;i<len;i++){
        symtab* cur = arr[hashmod(d[i])];
        if(cur==NULL){
            arr[hashmod(d[i])]=createnode(d[i]);
            headref[hashmod(d[i])] = arr[hashmod(d[i])];
        }
        else{
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = createnode(d[i]);
        }

    }
    disphash(headref);
        
    
    cout<<"\n";
    return 0;
}
