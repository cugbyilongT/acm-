long long quick_mod(long long x,long long n,long long mod)   //快速幂
{
    long long ans=1 ;    //初始化为1
    while(n!=0)
    {
        if(n&1)     //取最低位，判断
        {
            ans = (ans*x)%mod;
        }
        x=(x*x)%mod;
        n>>=1;      //移位操作
    }
    return ans;
}
