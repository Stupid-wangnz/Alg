#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class edge{
public:
    int s;
    int t;

    int weight;

    edge(){
        s=-1;
        t=-1;
        weight=0;
    }
    edge(int s,int t,int weight){
        this->s=s;
        this->t=t;
        this->weight=weight;
    }
};


//求解无向图最小生成树
int main() {
    int V,E;
    cin>>V>>E;

    /*vector<edge> E_list;
    vector<int>N_Recorder;
    for (int i = 0; i < E; ++i) {
        int e_s,e_t,e_weight;
        cin>>e_s>>e_t>>e_weight;
        E_list.push_back(edge(e_s,e_t,e_weight));
    }

    for(int i=0;i<V+1;i++)
        N_Recorder.push_back(i);

    sort(E_list.begin(),E_list.end(),[&](const edge a,const edge b)->bool {return a.weight<b.weight;});
    //kruskal
    int sum_weight=0;
    for(int i=0;i<E;i++){
        //if 两个node所属集合相等，不需要添加这条边
        int a=N_Recorder[E_list[i].s];//s所属的集合
        int b=N_Recorder[E_list[i].t];//t所属的集合
        if(a==b)
            continue;

        //把b集合全部归入a集合
        for(int j=1;j<V+1;j++){
            if(N_Recorder[j]==b)
                N_Recorder[j]=a;
        }
        sum_weight+=E_list[i].weight;
    }
    cout<<sum_weight;*/


    //prim
    //初始化二维数组维护边信息，-1表示没有边
    int**edges=new int *[V+1];
    for(int i=0;i<=V;i++)
        edges[i]=new int [V+1];

    for(int i=0;i<=V;i++)
        for(int j=0;j<=V;j++)
            edges[i][j]=-1;

    for(int i=0;i<E;i++){
        int e_s,e_t,e_weight;
        cin>>e_s>>e_t>>e_weight;
        edges[e_s][e_t]=edges[e_t][e_s]=e_weight;
    }
    //用一个map组维护能连接上结点的最小距离
    //node1 在开始阶段就在树内了
    vector<int>dis_node(V+1,-1);
    dis_node[1]=0;
    for(int i=1;i<=V;i++){
        if(edges[1][i]!=-1){
            dis_node[i]=edges[1][i];
        }
    }
    int sum=0;
    //从node1开始
    for(int i=0;i<V-1;i++){
        //找到目前最小距离的node
        int s_dis=INT32_MAX,s_it=0;
        for(int j=1;j<=V;j++){
            if(dis_node[j]<=0)
                continue;
            if(dis_node[j]<s_dis){
                s_dis=dis_node[j];
                s_it=j;
            }
        }
        dis_node[s_it]=0;
        sum+=s_dis;
        for(int j=1;j<=V;j++){
            if(edges[s_it][j]!=-1){
                if(dis_node[j]==-1)
                    dis_node[j]=edges[s_it][j];
                else
                    dis_node[j]=min(dis_node[j],edges[s_it][j]);
            }
        }
    }
    cout<<sum;
    return 0;
}
