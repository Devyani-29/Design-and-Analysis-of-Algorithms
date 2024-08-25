/*Implement a problem of maximize Profit by trading stocks 
based on given rate per day.
Statement: Given an array arr[] of N positive integers which 
denotes the cost of selling and buying a stock on each of 
the N days. The task is to find the maximum profit that can be 
earned by buying a stock on or selling all previously bought stocks 
on a particular day.
Input: arr[] = {2, 3, 5} Output: 5
Input: arr[] = {8, 5, 1} Output: 0*/
#include <iostream>
using namespace std;

// Function to find the maximum profit
int maximumProfit( int prices[], int n) {
    int profit = 0;
    int currentDay = n - 1; // Start from the last day

    // Loop through the days from the end to the beginning
    while (currentDay > 0) {
        int prevday = currentDay - 1;

        // Traverse backwards and accumulate profit
        while (prevday >= 0 && (prices[currentDay] > prices[prevday])) {
            profit += (prices[currentDay] - prices[prevday]); // Add the profit
            prevday--; // Move to the previous day
        }

        // Move the current day pointer to the next possible day
        currentDay = prevday;
    }

    return profit;
}

// Main driver code
int main() {
    int N;

    // Ask user for the number of days
    cout << "Enter number of days: ";
    cin >> N;

    // Validate the number of days
    if (N <= 0) {
        cout << "Number of days must be positive." << endl;
        return 1; // Exit with an error code
    }

    int prices[N];

    // Ask user to input stock prices
    cout << "Enter stock prices: ";
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }
    cout << "Maximum profit is " << maximumProfit(prices, N) << endl;

    return 0;
}
