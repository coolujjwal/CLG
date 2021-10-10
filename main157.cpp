#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> routePiars(int d,vector<vector<int>> v1,vector<vector<int>> v2){
    int n=v1.size(),m=v2.size();
    vector<vector<int>> ans;
    vector<pair<int,int>>v3,v4;
    for(int i=0;i<(int)v1.size();i++)    v3.push_back({v1[i][1],v1[i][0]});
    for(int i=0;i<v2.size();i++)    v4.push_back({v2[i][1],v2[i][0]});
    sort(v3.begin(),v3.end());
    sort(v4.begin(),v4.end());
    vector<int> v5,v6;
    for(int i=0;i<v3.size();i++)    v5.push_back(v3[i].first);
    for(int i=0;i<v4.size();i++)    v6.push_back(v4[i].first);
    int mini=INT_MAX;
    for(int i=0;i<v5.size();i++){
        if(v5[i]>d)     break;
        auto it=lower_bound(v6.begin(),v6.end(),d-v5[i]);
        if(it==v6.end()){
            it--;
            int pos=it-v6.begin();
            mini=min(mini,d-(v5[i]+v6[pos]));

        }
        else{
            int pos=it-v6.begin();
            if(v6[pos]+v5[i]==d){
                mini=0;
                break;
            }
            else{
                if(it==v6.begin())  continue;
                pos--;
                mini=min(mini,d-(v5[i]+v6[pos]));
            }
        }
        
        
    }
    // cout<<mini<<endl;
    for(int i=0;i<v5.size();i++){
        if(v5[i]>d) break;
        auto it=lower_bound(v6.begin(),v6.end(),d-v5[i]);
        if(it==v6.end()){
            if(mini==0) continue;
            it--;
            int pos=it-v6.begin();
            if(d-v5[i]-v6[pos]==mini){
                while(pos>=0&&(d-v5[i]-v6[pos])==mini){
                    vector<int> tmp;
                    tmp.push_back(v3[i].second);tmp.push_back(v4[pos].second);
                    ans.push_back(tmp);
                    pos--;
                }
            }

        }
        else{
            int pos=it-v6.begin();
            if(d-v5[i]-v6[pos]==mini){
                while(pos<n&&(d-v5[i]-v6[pos])==mini){
                    vector<int> tmp;
                    tmp.push_back(v3[i].second);tmp.push_back(v4[pos].second);
                    ans.push_back(tmp);
                    pos++;
                }
            }
            else{
                if(it==v6.begin())  continue;
                pos--;
                while(pos>=0&&(d-v5[i]-v6[pos])==mini){
                    vector<int> tmp;
                    tmp.push_back(v3[i].second);tmp.push_back(v4[pos].second);
                    ans.push_back(tmp);
                    pos--;
                }
            }
        }
    }
    return ans;

}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> tmp;
        int x,y;
        cin>>x>>y;
        tmp.push_back(x);tmp.push_back(y);
        v.push_back(tmp);
    }
    cin>>n;
    vector<vector<int>> v2;
    for(int i=0;i<n;i++){
        vector<int> tmp;
        int x,y;
        cin>>x>>y;
        tmp.push_back(x);tmp.push_back(y);
        v2.push_back(tmp);
    }

    int z;
    cin>>z;
    vector<vector<int>> ans=routePiars(z,v,v2);
    for(int i=0;i<ans.size();i++)   cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
}
