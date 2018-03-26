const int maxn=1e7;
int prime[maxn];    //存储素数
bool is_prime[maxn];    //存储是否为素数
int get_prime(int n)
{
    int prime_num=0;    //素数个数
    for(int i=0; i<=n; i++)
        is_prime[i]=1;      //初始化
    is_prime[0]=is_prime[1]=0;
    for(int i=2; i<=n; i++)     //筛素数
        if(is_prime[i]==1)
        {
            prime[prime_num++]=i;
            for(int j=i; j<=n; j+=i)
                is_prime[j]=0;
        }
    return prime_num;   //返回素数个数
}
