struct edge{        //存边
    int st;
    int ed;
    int value;  //边权
};
int father[10000];  //父亲数组
vector<edge> Edge;      
bool cmp(edge a,edge b)
{
    return a.value<b.value;
}
int find_father(int x) // 查找祖先并压缩路径
{
    return father[x]=x==father[x]?x:find_father(father[x]);
}
int Kruskal(int n)
{
    for(int i=1;i<=n;i++)   //初始化父亲数组
        father[i]=i;
    int ans = 0;    //最小生成树
    sort(Edge.begin(),Edge.end(),cmp);  //边权排序
    for(int i=0;i<Edge.size();i++)  //遍历所有边
    {
        if(find_father(Edge[i].st)!=find_father(Edge[i].ed))  //如果两个顶点不属于同一棵树
        {
            father[find_father(Edge[i].ed)]=find_father(Edge[i].st);        //合并两棵树
            ans+=Edge[i].value;
        }
    }
    int line=0; //判断还有几棵树
    for(int i=1;i<=n;i++)
        if(father[i]==i)
            line++;

    return line>1?-1:ans;       //联通则输出最小生成树权和否则输出-1
}
