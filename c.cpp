#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define MAXX 100005;
#define ll long long int
#define ld long double
#define SIZE 1000001
#define MAX 1000000007
#define MOD 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.14159265358979323846
#define Q ll ; cin >> _; while(--)
#define endl "\n"
#define flush fflush(stdout);
#define fixedprec cout << fixed << setprecision(18);

bool prime[SIZE+1];
vector<ll> primesq;
ll nprime[SIZE+1];

void Sieve(){

    for(ll i=0;i<=SIZE;i++){
        prime[i] = true;
    }

    for(ll p=2;p*p<=SIZE;p++){
        if(prime[p]){
            for(ll i=p*p;i<=SIZE;i+=p){
                prime[i] = false;
            }
        }
    }

}

int main(){

    fast

    Sieve();
    ll naman[100000];
    for(int i = 0;i<10000000;i++)
    {
    	ll t;
        ll x;
    	ll a[100000];
    }
    for(int i = 0;i<10000000;i++)
    {
    	ll t;
    	ll a[100000];
    }
    ll i;
    for(i=2;i<=SIZE;i++){
        primesq.push_back(i*i);
    }
    nprime[0] = 0;
    nprime[1] = 0;
    for(i=2;i<=SIZE;i++){
        nprime[i] = nprime[i-1];
        if(prime[i]){
            nprime[i]++;
        }
    }

    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        if(n==1){
            cout << 1 << endl;
            continue;
        }
        else if(n==2){
            cout << 2 << endl;
            continue;
        }
        else if(n==3){
            cout << 3 << endl;
            continue;
        }
        ll l = 0;
        ll r = primesq.size();
        ll si = 0;
        while(l<=r){
            ll m = l+(r-l)/2;
            if(primesq[m]<=n){
                si = m;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        ll xi = sqrt(primesq[si]);
        int ans = nprime[n] - nprime[xi] + 1;
        cout << "ans = " << ans << endl;
    }

}
