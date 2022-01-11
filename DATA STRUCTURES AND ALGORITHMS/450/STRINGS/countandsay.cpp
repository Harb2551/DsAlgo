class Solution {
public:
    string countAndSay(int n) {
        string a,b;
        a = "1";
        for(auto i=2;i<=n;i++){
            int m = a.length();
            int j = 0;
            b = "";
            while(j<m){
                char temp = a[j];
                int count = 0;
                while(temp==a[j]){
                    j++;
                    count++;
                }
                b += to_string(count);
                b += temp;
            }
            a = b;
        }
        return a;
    }
};