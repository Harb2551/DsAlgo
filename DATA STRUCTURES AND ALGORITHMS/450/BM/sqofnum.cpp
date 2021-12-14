int calculateSquare(int num)
{
    //    Write your code here.
    int ans=0;
    for(auto i=31;i>=0;i--){
        if(num&(1LL<<i)){
            for(auto j=31;j>=0;j--){
                if(num&(1LL<<j)){
                    ans += (1LL<<i)<<j;
                }
            }
        }
    }
    return ans;
}