#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void sieve(int n){
    vector<bool> is_prime(n+1,true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i*i <= n; i++){
        if(is_prime[i]){
            for(int j = i*i; j <= n; j+=i){
                is_prime[j] = false;
            }
        }
    }

    for(int i = 2; i < n; i++){
        if(is_prime[i]){
            cout<<i<<" ";
        }
    }
}

void sieve(int l, int r){
    int is_prime[r-l+1];
    for(int i = 0; i < r-l+1; i++){
        is_prime[i] = 1;
    }

    for(int i = 2; i <= sqrt(r); i++){
        for(int j = max(i*i,(l+i-1)/i*i); j <= r; j+=i){
            is_prime[j-l] = 0;
        }
    }
    for(int i = max(l,2); i<=r;i++){
        if(is_prime[i-l]){
            cout<<i<<" ";
        }
    }
}

int main(){
    sieve(100);
    cout<<endl;
    sieve(100,1000);
    system("pause");
    return 0;
}