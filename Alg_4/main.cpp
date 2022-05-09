#include <iostream>
#include<cmath>
using namespace std;
/*
 * 字符串比较
 * 动态规划实现序列比较
 * 空间O(2*m)
 */
string s1, s2;
int k;

//递归实现，时间超限
int OPT(int i,int j) {
    if(i==0)
        return j*k;
    if(j==0)
        return i*k;

    int a1=abs(s1[i-1]-s2[j-1])+OPT(i-1,j-1);
    int a2=k+OPT(i-1,j);
    int a3=k+OPT(i,j-1);

    return min(a1,min(a2,a3));

}
int main() {

    cin >> s1 >> s2;

    //k是空格与字符的距离
    cin >> k;

    //int n = s1.size();
    int m = s1.size();
    int n = s2.size();

    int A[m+1][2];
    for(int i=0;i<=m;i++) {
        A[i][0]=i*k;
    }
    for(int j=1;j<=n;j++) {
        A[0][1]=j*k;
        for(int i=1;i<=m;i++) {
            int a1=abs(s1[i-1]-s2[j-1])+A[i-1][0];
            int a2=k+A[i-1][1];
            int a3=k+A[i][0];
            A[i][1]=min(a1,min(a2,a3));
        }
        for(int i=0;i<=m;i++) {
            A[i][0]=A[i][1];
        }
    }
    cout << A[m][0] << endl;
}