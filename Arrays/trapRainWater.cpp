#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool sequentialCheck(vector<int> ip, int start, int end)
{
    if (start < end)
    {
        for (int i = start; i < end - 1; i++)
        {
            if (ip[i] > ip[i + 1])
            {
                return false;
            }
        }
    }
    else if (start > end)
    {
        for (int i = start - 1; i >= end; i--)
        {
            if (ip[i + 1] > ip[i])
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }

    return true;
}

int maxRainTrap(vector<int> ip)
{

    int p1 = 0;
    int p2 = ip.size() - 1;
    int maxArea = 0;
    int height = 0, base = 0;

    if (sequentialCheck(ip, 0, p2) || sequentialCheck(ip, p2, 0))
    {
        return -1;
    }

    while (p1 < p2)
    {
        height = min(ip[p1], ip[p2]);
        base = p2 - p1 - 1;
        int subTract = 0;
        maxArea = max(maxArea, (height * base));
        (height == ip[p1]) ? p1++ : p2--;
    }

    return maxArea;
}

// Here we assume that the bar stops utna volume
int maxRainTrapN(vector<int> ip)
{
    // If array is sorted ascending descending
    if (sequentialCheck(ip, 0, ip.size() - 1) || sequentialCheck(ip, ip.size() - 1, 0))
    {
        return -1;
    }   

    int leftMax = -1;
    int rightMax = 0;
    int res = 0;

    for (int i = 0; i < ip.size(); i++){
        leftMax = ip[0];
        for (int j = 0; j < i; j++){
            leftMax = max(leftMax, ip[i]);
        }
        rightMax = ip[i];
        for (int j = i + 1; j < ip.size(); j++){
            rightMax = max(rightMax, ip[j]);
        }

        res += (min(leftMax, rightMax) - ip[i]);
    
        cout << leftMax << " " << rightMax << " " << res << endl;
    }

    return res;
}

int maxRain(vector<int> ip){
    vector<int> left;
    vector<int> right;
    int n = ip.size();

    int maxLeft = ip[0];
    for (int i = 0; i < n; i++){
        left[i] = max(maxLeft, ip[i]);
    }

    int maxRight = ip[n - 1];

    for (int i = n - 2; i >= 0; i--){
        right[i] = max(maxRight, ip[i]);
    }


    int res = 0;

    for (int i = 0; i < n; i++){
        res = res + min(left[i], right[i]) - ip[i];
    }

    return res;
}

int main()
{
    vector<int> res = {3, 0, 1, 2, 5};
    cout << maxRain(res);
    return 0;
}