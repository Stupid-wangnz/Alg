#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
     * 输入的信息
     * @param:n 是一个整数，表示赛道有n段
     * @param:rangesL[] 是一个数组，表示n+1个机位，其中ranges[i]表示第i个摄像机能向左的移动范围
     * @param:rangesR[] 是一个数组，表示n+1个机位，其中ranges[i]表示第i个摄像机能向右的移动范围
     */
    int n;
    cin >> n;
    vector<int> rangesL(n+1);
    for (int i = 0; i < n+1; i++) {
        cin >> rangesL[i];
    }

    vector<int> rangesR(n+1);
    for (int i = 0; i < n+1; i++) {
        cin >> rangesR[i];
    }

    /*
     * 输出的信息
     * @param:ans 是一个整数，表示最少需要多少摄像机
     */
    int ans = 0;

    vector<int> prev(n+1,0);
    for(int i = 1; i < n+1; i++) {
        prev[i] = i;
    }
    for(int i= 1; i < n+1; i++) {
        int li=max(0,i-rangesL[i]);
        int ri=min(n,i+rangesR[i]);
        prev[ri]=min(prev[ri],li);
    }

    vector<int> dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=prev[i];j<i;j++){
            if(dp[j]!=-1){
                dp[i]=max(dp[i],dp[j]+1);
            }
            //dp[i]=min(dp[i],dp[j]+1);
        }
    }
    if(dp[n]==-1){
        cout<<-1<<endl;
    }else{
        cout<<dp[n]<<endl;
    }
    return 0;
}
