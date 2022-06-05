#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Len;
int N;

vector<pair<int,int>> preConditioning(vector<int>&Locations,vector<vector<int>>&Move,vector<int>&Range){

    vector<pair<int,int>>Region;
    for(int i=0;i<N;i++){
        int l=max(0,Locations[i]-Move[i][0]-Range[i]);
        int r=min(Len,Locations[i]+Move[i][1]+Range[i]);
        pair<int,int>P(l,r);
        if(Range[i]==0){
            continue;
        }
        Region.push_back(P);
    }
    N=Region.size();
    return Region;
}

int OPT1(vector<pair<int,int>>&Region){
    vector<int>dp(Len+1,INT_MAX-1);
    dp[0]=0;
    for(int i=1;i<=Len;i++){
        for(auto r:Region){
            if(r.first<i&&r.second>=i)
                dp[i]=min(dp[i],dp[r.first]+1);
        }
    }
    return dp[Len]==INT_MAX-1?-1:dp[Len];
}

int OPT2(vector<pair<int,int>>&Region){
    sort(Region.begin(),Region.end(),[](const auto&t1,const auto&t2){return t1.first<t2.first;});
    vector<int>dp(Len+1,INT_MAX-1);
    dp[0]=0;
    for(int i=0;i<Region.size();i++){
        int st=Region[i].first;
        int ed=Region[i].second;
        for(int k=st;k<=ed;k++){
            dp[k]=min(dp[k],dp[st]+1);
        }
    }

    return dp[Len]==INT_MAX-1?-1:dp[Len];
}

int Greedy(vector<pair<int,int>>&Region){
    sort(Region.begin(),Region.end(),[](const auto&t1,const auto&t2){return t1.first<t2.first||(t1.first==t2.first&&t1.second>t2.second);});
    int i=0,ans=0,st=0,ed=0;
    while(i<Region.size()&&st<Len){
        if(Region[i].first<=st){
            ed=st;
            while(i<Region.size()&&Region[i].first<=ed){
                st=max(st,Region[i].second);
                i++;
            }
            ans++;
        }
        else
            break;
    }
    return st>=Len?ans:-1;
}

int main() {
    /*
     * 输入的信息
     * @param:Len,赛道的长度
     * @param:N,摄像机的数量
     * @param:Move[]
     * @param:range[],表示i号摄像机的摄影幅度
     * @param:Locations[]
     */

    //第一组测试用例，答案为3，有最优解
    Len=10;
    N=6;

    vector<int>Locations({1,5,9,6,3,7});
    vector<vector<int>>Move({{0,0},{0,0},{0,0},{3,1},{1,1},{1,1}});
    vector<int>Range({1,1,1,2,1,1});


    //第二组测试用例，答案为-1，没有最优解
    /*Len=5;
    N=2;

    vector<int>Locations({1,2});
    vector<vector<int>>Move({{0,1},{1,1}});
    vector<int>Range({1,0});*/


    vector<pair<int,int>>Region= preConditioning(Locations,Move,Range);
    cout<<"result of dynamic programming1:minNum="<<OPT1(Region)<<endl;
    cout<<"result of dynamic programming2:minNum="<<OPT2(Region)<<endl;
    cout<<"result of Greedy Algorithm:minNum="<<Greedy(Region)<<endl;


    return 0;
}
