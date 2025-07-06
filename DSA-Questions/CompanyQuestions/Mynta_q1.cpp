#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to calculate 2^Y without precision issues
long long powerOfTwo(int Y) {
    long long result = 1;
    for (int i = 0; i < Y; ++i) {
        result *= 2;
    }
    return result;
}

int maxNetWorth(int N, int X, int Y, vector<int>& propertyPrices) {
    // Sort properties by their current prices
    sort(propertyPrices.begin(), propertyPrices.end());

    int moneyLeft = X;
    long long totalNetWorth = 0;

    // Calculate 2^Y once
    long long multiplier = powerOfTwo(Y);

    for (int price : propertyPrices) {
        if (moneyLeft >= price) {
            // Buy the property
            moneyLeft -= price;
            // Add its worth after Y years to the total net worth
            totalNetWorth += (long long)price * multiplier;
        } else {
            break;  // No more properties can be bought
        }
    }

    return totalNetWorth;
}

int main() {
    // Example 1
    int input1 = 4; 
    int input2 = 46; 
    int input3 = 20;
    vector<int> input4 = {7, 15, 11, 17};
    cout << maxNetWorth(input1, input2, input3, input4) << endl;  // Output: 29360128

    // Example 2
    input1 = 6; 
    input2 = 44; 
    input3 = 20;
    input4 = {5, 3, 6, 1, 2, 4};
    cout << maxNetWorth(input1, input2, input3, input4) << endl;  // Output: 16777216

    return 0;
}