/*Implement a problem of minimum work to be done per day to CO2
finish given tasks within D days problem.
Statement: Given an array task[] of size N denoting amount of 
work to be done for each task, the problem is to find the minimum 
amount of work to be done on each day so that all the tasks can be 
completed in at most D days. Note: On one day work can be done 
for only one task.
Input: task[] = [3, 4, 7, 15], D = 10 Output: 4
Input: task[] = [30, 20, 22, 4, 21], D = 6 Output: 22
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to check if all tasks can be completed by 'per_day' amount of work per day
bool valid(int per_day, const vector<int>& task, int d, int n) {
    int cur_day = 0;
    for (int i = 0; i < n; i++) {
        // Calculate the number of days required for task[i] with the given 'per_day'
        cur_day += (task[i] + per_day - 1) / per_day;

        // If the total days exceeds 'd', return false
        if (cur_day > d) {
            return false;
        }
    }
    return true;
}

// Function to find minimum work to be done each day
int minTask(const vector<int>& task, int d, int n) {
    int low = 1;
    int high = *max_element(task.begin(), task.end());

    // Variable to store the result
    int per_day_task = high;

    // Binary search for the minimum 'per_day'
    while (low <= high) {
        int mid = (low + high) / 2;

        if (valid(mid, task, d, n)) {
            per_day_task = mid;  // Found a valid solution, try for a smaller per_day
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return per_day_task;
}

int main() {
    // Input from user
    int n, d;
    cout << "Enter number of tasks: ";
    cin >> n;
    vector<int> task(n);
    cout << "Enter the task values: ";
    for (int i = 0; i < n; i++) {
        cin >> task[i];
    }
    cout << "Enter number of days: ";
    cin >> d;

    // Output the result
    cout << "Minimum amount of work to be done each day: " << minTask(task, d, n) << endl;

    return 0;
}