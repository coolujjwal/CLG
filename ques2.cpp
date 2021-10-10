#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define pll pair<ll,ll>
#define pint pair<int,int>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define MAX 100005
#define mod 998244353
#define endl '\n'
#define mp make_pair
#define INF INT_MAX
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ff first
#define ss second
#define ps(x,y) fixed<<setprecision(y)<<x
#define setbits(x) __builtin_popcountll(x)            //counts no of ones in binary representation
#define w(t)     int t; cin>>t; while(t--)
#define pi 3.141592653589793238
#define sortt(v)  sort(v.begin(),v.end())
#define rev(v)   reverse(v.begin(),v.end())
#define lb(v,x) std::lower_bound(v.begin(),v.end(),x)
#define ub(v,x) std::upper_bound(v.begin(),v.end(),x)
#define fix fixed<<setprecision(15)
//prime greater than 1e6 1000003

using namespace std;


unordered_map<string,int> siz,vis,insiz[4];
unordered_map<string,string> par;
int n,m,a,b,f,s,t;

string parent(string x){
	if(x==par[x])	return x;
	return par[x]=parent(par[x]);
}

void union1(string s1,string t1){
	string p=parent(s1);
	string q=parent(t1);
	if(p==q)	return;
	if(siz[q]+siz[p]>b)	return;
	if(insiz[1][q]+insiz[1][p]>f)	return;
	if(insiz[2][q]+insiz[2][p]>s)	return;
	if(insiz[3][q]+insiz[3][p]>t)	return;
	par[p]=q;
	siz[q]+=siz[p];
	siz[p]=0;
	for(int i=1;i<4;i++){
		insiz[i][q]+=insiz[i][p];
		insiz[i][p]=0;
	}
}

bool my_compare(string a, string b)
{
    // Check if a string is present as
    // prefix in another string, then
    // compare the size of the string
    // and return the larger size
    if (a.compare(0, b.size(), b) == 0
        || b.compare(0, a.size(), a) == 0)
 
        return a.size() > b.size();
 
    // Else return lexicographically
    // smallest string
    else
        return a < b;
}

int main(){
	fast;
	int casee=1;
	
	
	cin>>n>>m>>a>>b>>f>>s>>t;
	string st;int dept;
	vector<string> st3;
	forn(i,n){
		cin>>st>>dept;
		st3.push_back(st);
		par[st]=st;
		siz[st]=1;
		if(dept==1){
			insiz[2][st]=insiz[3][st]=0;
		}
		else if(dept==2){
			insiz[1][st]=insiz[3][st]=0;
		}
		else{
			insiz[2][st]=insiz[1][st]=0;
		}
		insiz[dept][st]=1;

	}
	while(m--){
		string st1,st2;
		cin>>st1>>st2;
		union1(st1,st2);
	}
	int maxi=-1;
	for(auto it=siz.begin();it!=siz.end();it++)		maxi=max(maxi,it->ss);
	// cout<<maxi<<endl;
	if(maxi<a)	cout<<"no groups";
	else{
		// vector<string> ans;
		sort(st3.begin(),st3.end(),my_compare);
		forn(i,st3.size()){
			string parentt=parent(st3[i]);
			if(siz[parentt]==maxi)	cout<<st3[i]<<endl;
		}
	}

}	
