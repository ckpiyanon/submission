/*
    dp component problem
    have 4 method
        1. create component dp(i, j) <- dp(i-1, j-1) * (j - (i > s) - (i > t))
        2. merge left dp(i, j) <- dp(i-1, j) * (j - (i > t))
        3. merge right dp(i, j) <- dp(i-1, j) * (j - (i > s))
        4. merge 2 component dp(i, j) <- dp(i-1, j+1) * j
    in case not start and end
        case L use 3, 4
        case R use 1, 2
        case B use 1, 2, 3, 4
    in case start
        case L, B use dp(i, j) <- dp(i-1, j)
        case R, B use dp(i, j) <- dp(i-1, j-1)
    in case end
        dp(i, j) <- dp(i-1, j) + dp(i-1, j-1)
*/
#include <bits/stdc++.h>
#define long long long
using namespace std;

const long M = 1e9+7;
const int N = 2e3+5;

int s, t;
long dp[N][N];
char arr[N];

long mic(int i, int j) {
    long& now = dp[i][j];
    if(now != -1) return now;
    now = 0;
    if(j != 0) {
        if(i == 1) {
            if((arr[i] != 'L' || t == i) && j == 1) now = 1;
        }else if(s == i) {
            if(arr[i] != 'L') now = (now + mic(i-1, j-1)) % M;
            if(arr[i] != 'R') now = (now + mic(i-1, j)) % M;
        } else if(t == i) {
            now = (now + mic(i-1, j) + mic(i-1, j-1)) % M;
        } else {
            if(arr[i] != 'L') now = (now + mic(i-1, j-1) * (j - (i > s ? 1 : 0) - (i > t ? 1 : 0))) % M;
            if(arr[i] != 'L') now = (now + mic(i-1, j) * (j - (i > t ? 1 : 0))) % M;
            if(arr[i] != 'R') now = (now + mic(i-1, j) * (j - (i > s ? 1 : 0))) % M;
            if(arr[i] != 'R') now = (now + mic(i-1, j+1) * j) % M;
        }
    }
    return now;
}    
int main() {
    memset(dp, -1, sizeof dp);
    scanf("%s", arr+1);
    scanf("%d %d", &s, &t);
    printf("%lld\n", mic(strlen(arr+1), 1));
}
    
