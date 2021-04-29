//  Author: fireLUFFYY, NITR

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/stack:200000000")

#include<bits/stdc++.h>

#define int unsigned long long
#define ull unsigned long long
#define vi vector<int>
#define vvl vector<vector<int>>
#define deql deque<int>
#define prquel priority_queue<int>
#define loop(i,n) for(int i=0;i<n;i++)
#define loopn(i,a,b) for(int i=a;i<=b;i++)
#define rloop(i,n) for(int i=n;i>0;i--)
#define sortv(a) sort(a.begin(),a.end())
#define sortvr(a) sort(a.rbegin(),a.rend())
#define verase(a) a.erase(unique(a.begin(),a.end()),a.end()) 
#define all(a) a.begin(),a.end()
#define dbg(x) cout<<#x<<" = "<<x<<"\n";
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second 
#define endl "\n"
#define inf 2e18
using namespace std;

int MOD=1000000007;
int mod=998244353;
const int N=200050;
const int nn=1000050;
int fact[N]; // array to store values of factorial
bool prime[nn];	//array to store precalculated primes till 10^6
bool pow2(int x){if(x&&(!(x&(x-1)))) return true; else return false;}
int gcd(int a,int b) { if(a == 0)return b;return gcd(b % a, a);}
int lcm(int a,int b){int val=max(a,b)/gcd(a,b);val*=min(a,b);return val;}
int multiply(int x, int y){return (x * 1ll * y) % MOD;}
int power(int x, int y){int z = 1;while(y){if(y & 1) z = multiply(z, x);x = multiply(x, x);y >>= 1;}return z;}
int modInverse(int x){return power(x, MOD - 2);}
int divide(int x, int y){return multiply(x, modInverse(y));}
void cal_factorial(){fact[0] = 1;for(int i = 1; i < N; i++)fact[i] = multiply(fact[i - 1], i);}// function to calculate factorial upto N
void cal_primes(){memset(prime,true,sizeof(prime)); loopn(i,2,sqrt(nn)){ if(prime[i]==true){ for(int j=i*i;j<=nn;j+=i){prime[j]=false;}}}}
int nCr(int n, int k){return divide(fact[n], multiply(fact[k], fact[n - k]));}
void FASTIO(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}


void solve(int t)
{
	int testcases=t;
	while(t--)
	{
		//cout<<"#"<<(testcases-t)<<" Test-Case: "<<endl;
		int n,k,ans=0,c;
		cin>>n>>k;
		string s,s2,ss="",mv="";
		cin>>s;
		vi p;
		loop(i,n)
		{
			c=0;
			if(i==0)
				ss=s;
			else
			{
				char c=ss[0];
				ss.erase(0,1);
				ss.push_back(c);
			}

			if(ss>mv)
			{
				p.clear();
				mv=ss;
				p.pb(i);
				c=1;
			}

			if(ss==mv)
				if(c==0)
					p.pb(i);
		}
		if(k<=p.size())
			ans=p[k-1];
		else
		{
			if(k%p.size()==0)
			{
				ans=(n*(k/p.size() - 1));
				ans+=p[p.size()-1];
			}
			else
			{
				ans=(n*(k/p.size()));
				ans+=p[k%p.size()-1];
			}
		}
		cout<<ans<<endl;
	}
}

main()
{
	auto start=chrono::system_clock::now();
	{
		#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
		#endif
		FASTIO();	
		int t=1;
		cin>>t;
		solve(t);
	}
	auto end=chrono::system_clock::now();
	chrono::duration<double> elapsed=end-start;
//	cout<<"Time taken: "<<elapsed.count()<<" sec";
	return 0;
}