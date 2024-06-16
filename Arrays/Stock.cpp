#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// No
int maxProfit(vector<int> ip)
{
    int diff = ip[1] - ip[0];
    int minVal = ip[0];

    for (int i = 1; i < ip.size(); i++)
    {
        if (ip[i] - minVal >= 0)
        {
            diff = max(diff, ip[i] - minVal);
            minVal = min(minVal, ip[i]);
        }
    }

    return diff;
}

int maxStockProfit(vector<int> ip, int start, int end)
{
    if (end <= start)
    {
        return 0;
    }

    int profit = 0;

    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (ip[j] > ip[i])
            {
                int curr = (ip[j] - ip[i]) + maxStockProfit(ip, start, i - 1) + maxStockProfit(ip, j + 1, end);
                profit = max(curr, profit);
            }
        }
    }

    return profit;
}

int optimizeFunc(vector<int> ar){
    int n = ar.size();

    int profit = 0;

    for (int i = 0; i < ar.size(); i++){
        if (ar[i] > ar[i - 1]){
            profit += (ar[i] - ar[i-1]);
        }
    }

    return profit;
}

int main()
{
    vector<int> prices = {1, 5, 3, 8, 12};
    int n = prices.size();
    // cout << maxStockProfit(prices, 0, n - 1);

    cout << optimizeFunc(prices);
    return 0;
}