#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s) {
        map <char,int> mp;
        int n = s.size();
        for(auto i=0;i<n;i++)
            mp[s[i]]++;
        priority_queue <pair<int,char>,vector<pair<int,char>>> pq;
        for(auto i=mp.begin();i!=mp.end();i++){
            pq.push({i->second,i->first});
            if(i->second>ceil(n/2.0))
                return "";
        }
        string s1;
        char last='$';
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            if(cur.second==last){
                auto temp = pq.top();
                s1.push_back(temp.second);
                pq.pop();
                if(temp.first-1>0){
                    pq.push({temp.first-1,temp.second});                    
                }
                last = temp.second;
                pq.push(cur);
            }
            else{
                s1.push_back(cur.second);        
                if(cur.first-1>0)
                    pq.push({cur.first-1,cur.second});
                last = cur.second;
            }
        }
        return s1;
    }

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    s = reorganizeString(s);
	    if(s=="")
	        cout << 0 << endl;
	    else
	        cout << 1 << endl;
	}
	return 0;
}








