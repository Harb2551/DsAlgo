int splitString(string &str) 
{
    // Write your code here
    int zero=0,one=0;
    int n = str.length();
    for(auto i=0;i<n;i++){
        if(str[i]=='0')
            zero++;
        else
            one++;
    }
    if(zero!=one)
        return -1;
    zero = 0;
    one = 0;
    int ans = 0;
    for(auto i=0;i<n;i++){
        if(str[i]=='0')
            zero++;
        else
            one++;
        if(zero!=0 and zero==one){
            ans++;
            zero = 0;
            one = 0;
        }
    }
    return ans;
}