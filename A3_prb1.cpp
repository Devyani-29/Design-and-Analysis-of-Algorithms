/*Implement Coin Change problem. 
Statement Given an integer array of coins[ ] of size N representing 
different types of currency and an integer sum, The task is to find 
the number of ways to make sum by using different combinations 
from coins[].   
Note: Assume that you have an infinite supply of each type of 
coin.  
Input: sum = 4, coins[] = {1,2,3},                  Output: 4 
Input: sum = 10, coins[] = {2, 5, 3, 6}           Output: 5 */
#include<iostream>
using namespace std;
int count(int coins[],int n,int sum)
{
    int dp[n+1][sum+1];//initialize 2 dimentional array

// If sum is 0, then answer is true
for (int i=0;i<=n;i++)
{
    dp[i][0]=1;//Base condition
}
// If sum is not 0 and set is empty,
// then answer is false
for (int j=0;j<=sum;j++)
{
    dp[0][j]=0;//Base condition
}
  // Fill the table in bottom up manner
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=sum;j++)
    {
        dp[i][j]=dp[i-1][j];
        if (coins[i-1]<=j)
        {
            dp[i][j]+=dp[i][j-coins[i-1]];
        }
    }
}
return dp[n][sum];
}
//Driver Code
int main()
{
    int coins[20],n,sum;
    cout<<"enter the number of coins"<<endl;
    cin>>n;
    cout<<"Enter the coins value"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    cout<<"enter the sum"<<endl;
    cin>>sum;

    cout << "Number of ways to make the sum: " << count(coins, n, sum) << endl;
    return 0;

}