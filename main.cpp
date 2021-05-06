#include<iostream>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000000000000
#define ff first
#define ss second
#define f(i,a,b) for(ll i=a;i<b;i++)
#define it(b)  for(auto &it:b)
#define NUM  1000000007
#define ff first
#define ss second
#define mp make_pair
#define pb(x) push_back(x)
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
class dsu
{
    ll *parent;
    ll *size;
public:
    ll distinct;
    dsu(){}
    dsu(int n):distinct(n)
    {
        parent=new ll [n+1];
        size=new ll [n+1];
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    ll find_parent(int i)
    {
        if(parent[parent[i]]!=parent[i])
            parent[i]=find_parent(parent[i]);
        return parent[i];
    }
    bool find(int a,int b)
    {
        if(find_parent(a)==find_parent(b))
        {
            return true;
        }
        return false;
    }
    void uni(int a,int b)
    {
        ll parent_a=find_parent(a),parent_b=find_parent(b);
        if(parent_a==parent_b)
            return;
        if(size[parent_a]>=size[parent_b])
        {
            distinct--;
            size[parent_a]+=size[parent_b];
            parent[parent_b]=parent_a;
        }
        else
        {
            distinct--;
            size[parent_b]+=size[parent_a];
            parent[parent_a]=parent_b;
        }
    }
    ll siz(int a)
    {
        return size[find_parent(a)];
    }
    ~dsu()
    {
        delete []size;delete []parent;
    }
};
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2)%NUM;
    if (b % 2)
        return (((res * res)%NUM)* a)%NUM;
    else
        return (res * res)%NUM;
}
struct prep
{
    vll fact;
    vll inv;
    ll m;
    prep(){}
    explicit prep(int n):m(NUM)
    {
        ll mod=NUM;
        int num=n;
        fact.resize(n+31);
        inv.resize(n+31);
        fact[0]=1;
        inv[0]=1;
        for(int i=1;i<=num+30;i++)
        {
            fact[i]=(fact[i-1]*i)%mod;
            inv[i]=binpow(fact[i],mod-2)%NUM;
        }
    }
    ll ncr(ll n , ll r)
    {
        if(r>n||r<0)
        {
            return 0;
        }
        ll p = ((fact[n]*inv[r])%m);
        p=(p*(inv[n-r])%m);
        return p;
    }
    ll fac(ll num)
    {
        return fact[num];
    }
};
bool isPrime(long long n) {
    if (n == 1)return false;
    if (n == 2)return true;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0)return false;
    return true;
}
inline ll min(ll a,ll b)
{
    if(a>b)return b;return a;
}
inline ll max(ll a, ll b)
{
    if(a>b)
        return a;
    return b;
}
inline ll dif(long long a,long long b)
{
    if(a>b)
        return a-b;
    return b-a;
}
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    long long k=gcd(a,b);
    return (a*b)/k;
}
void read(ll*arr,int n)
{
    for(int i=0;i<n;i++)cin>>arr[i];
}
vector<long long >prime;
void sieveOferatosthenes(long long  MAX)
{
    bool pri[MAX + 1];memset(pri, true, sizeof(pri));pri[1] = false;
    for (long long  p = 2; p * p <= MAX; p++) {
        if (pri[p]) {
            for (long long  i = p * p; i <= MAX; i += p)
                pri[i] = false;
        }
    }
    for(long long  i=1;i<=MAX;i++) {
        if (pri[i]) {
            prime.push_back(i);
        }
    }
}
void solve()
{
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << showpoint;
    cout << setprecision(6);
    int t;t=1;
    //cin>>t;
    // WE WILL WIN.
    while(t--)
    {
        solve();
    }
}