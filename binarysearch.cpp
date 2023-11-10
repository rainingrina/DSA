#include<iostream>
using namespace std;

int binarySearch(int even[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    
    while(start<=end){
        if(even[mid]==key){
        return mid;
    }
    else if(key>even[mid]){
        start=mid+1;
    }
    else{
        end=mid-1;
    }
    mid=start+(end-start)/2;
    }
    return -1;
}
int main(){
    int even[6]={11,22,36,58,67,89};
    int index=binarySearch(even,6,36);
    cout<<index<<endl;
    return 0;
}