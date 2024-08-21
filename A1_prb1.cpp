/*Implement a problem of number of zeroes.
Statement: Given an array of 1s and 0s which has all 1s first 
followed by all 0s? Find the number of 0s.
USE DIVIDE AND CONQUER TECHNIQU C*/
#include<iostream>
using namespace std;
int ctzero(int arr[],int n)
{
    int l=0;
    int h=n-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(arr[mid]==0)
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return n-l;
}
int main()
{
    int n;
    cout<<"enter number of element n"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the array element"<<endl;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int result=ctzero(arr,n);
    cout<<"number of zeroes in the array "<<result;
    return 0;
}