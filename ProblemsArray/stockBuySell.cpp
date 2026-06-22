#include <iostream>
using namespace std;

void maxProfit(vector<int> &nums) {
    int buyDay = -1;
    int sellDay = -1;
    
    pair<int, int> buy = {nums[0], 0};

    int profit = INT_MIN;

    int size = nums.size();

    for (int i = 0; i < size; i++) {
        // [7,2,1,0] 100-7; 93;
        // {8, 3}
        // Check if the buy value is > sell value.
            // buy > sell
            // buy = sell;

            // 7 > 3;
        if (buy.first > nums[i]) {
            buy.first = nums[i];
            buy.second = i;
        }

        // {1, 10};
        
        // Check if the buy value is < sell value.
            // Max(profit, sell - buy);
                // buyDay = index of buy
                // sellDay = current index
        if (buy.first < nums[i]) {

            int newProfit = nums[i] - buy.first; // 9-1; = 8 > in min;

            if (newProfit > profit) {
                buyDay = buy.second;
                sellDay = i;
                profit = newProfit;
            }
        } 
    }

    if (buyDay != -1 && sellDay != -1) {
        cout << "BUY: " << buyDay + 1  << " SELL: " << sellDay + 1 << endl;
    }
    else {cout << "NO PROFIT" << endl;}
    
}

int main() {
    vector<int> stock = {2, 4, 1};
    maxProfit(stock);
    return 0;
}