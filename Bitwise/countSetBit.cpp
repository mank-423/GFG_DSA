#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countSetBit(int x){

    int n = x;

    int count = 0;
    while (n != 0){
        count += (n & 1);

        n = n >> 1;
    }

    return count;
}

// Brian kerning algorithm
// O (set bits)
int setBitsAlgo(int n){
    int res = 0;

    while (n > 0){
        n = n & (n - 1);
        res+=1;
    }

    return res;
}

// Look up method
int tbl[256];

void initialize(){
    tbl[0] = 0;
    for (int i = 0; i < 256; i++)
        tbl[i] = tbl[i & (i - 1)] + 1; //Brian kerning
}

int lookUpSetBits(int n){
    // Intializing first
    initialize();

    // 32 bits
    // So every number is 8 bits no
    // i.e = [00...0] [00...0] [0...0] [00001101] = 13 (every 8 bit)
    // Doing right shift by 8 bits to check with every group if set bits is present
    // Last one is only 24 right shift because after that only 8 bits will remain
    return tbl[n & 255] + tbl[(n >> 8) & 255] + tbl[(n >> 16) & 255] + tbl[(n >> 24)];
}

int main()
{
    cout << lookUpSetBits(4);
    return 0;
}