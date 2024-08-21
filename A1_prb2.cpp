/*Implement a problem of move all zeroes to end of array.
Statement: Given an array of random numbers, Push all the zero’s 
of a given array to the end of the array. For example, if the given 
arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 
9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be 
same.
USE DIVIDE AND CONQUER TECHNIQUE*/

#include<iostream>
using namespace std;

int main()
{   //variale declaration
    int i, a[20], temp[20], k = 0, N;
    cout << "enter array size" << endl;
    cin >> N;

    int low = 0; //initially set low to 0
    int high = N - 1; //initially set high to n-1 where, n=size of array
    int mid = (low + high) / 2;

    cout << "enter array elements" << endl;//input from user
    for(i = 0; i < N; i++)
    {
        cin >> a[i];
    }

//searching non-zero element in first half of array & put it in temporary array
    for(i = 0; i <= mid; i++)
    {
        if(a[i] != 0)
        {
            temp[k] = a[i];
            k++;
        }
    }
    //searching non-zero element in second half of array & put it in temporary array
    for(i = mid + 1; i < N; i++)
    {
        if(a[i] != 0)
        {
            temp[k] = a[i];
            k++;
        }
    }
    //Remaining position in temporary filled with 0
    while(k < N)
    {
        temp[k++] = 0;
    }

    for(k = 0; k < N; k++)
    {
        cout << temp[k] << " "; // 
    }
    
    return 0;
}