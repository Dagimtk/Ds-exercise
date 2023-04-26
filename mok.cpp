#include<iostream>

using namespace;
/*void binary(int arr[],int sixe){
 int mid,top,bottom,found;
 mid=sixe/2;

 for(i=0;i<=sixe;i++)
 {
     if(found==mid){
        return i;
     }
     else if()
 }
}*/
void SimpleSort(int arr[])
{
for(int i=0; i<=n-2;i++)
for(int j=i+1; j<=n-1; j++)
if(arr[i] > arr[j])
{
int temp;
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
int main(){
    /*int mid,top,bottom;
    int arr[];
*/int arr[]={3,6,2,8,7};

SimpleSort(arr[]);

    return 0;
}
