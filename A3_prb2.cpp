/*Implement Subset Sum Problem. 
Statement Given a set of non-negative integers and a value sum, 
the task is to check if there is a subset of the given set whose sum is 
equal to the given sum.  
Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9          Output: True 
Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30        Output: False*/
// A Dynamic Programming solution
// for subset sum problem
#include <iostream>
using namespace std;

// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..i-1] with sum
    // equal to j
    bool subset[n + 1][sum + 1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] =1;

    // If sum is not 0 and set is empty,
    // then answer is false
    for (int j = 1; j <= sum; j++)
        subset[0][j] = 0;

    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j]
                    = subset[i - 1][j]
                      || subset[i - 1][j - set[i - 1]];
        }
    }

    return subset[n][sum];
}

// Driver code
int main()
{
    int set[10],n,i,sum ;
    cout<<"Enter no of elements"<<endl;
    cin>>n;
    cout<<"Enter elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>set[i];
    }
    cout<<"Enter sum"<<endl;
    cin>>sum;
    if (isSubsetSum(set, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}