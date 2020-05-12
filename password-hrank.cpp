#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

int n , m , passlength;
std::vector <string> v;
string s;
map <string , int > mp;
std::vector<int> len;

std::vector<string> ans;
map < string , int > ids;
map < pair <int, int > , bool > dp;
map <int , string > rev;
string res ;

bool f(int pos , int length , string res){
    if(pos > m) return false;
    if(pos == m) {
        if(length == m){
         ::res = res;
         return true;
        }return false;
    }
    if(length == m) return true;
    if(dp.find({pos , length}) != dp.end() ) return dp[{pos , length}];
    bool ok = false;
    for(int i = 0 ; i < n ; i++){
        if(pos + len[i] <= m){
            string ss = s.substr(pos , len[i]);
            if(mp.find(ss) != mp.end()){
                char c = (ids[ss] +  '0');
                ok |= f(pos + len[i] , length + len[i] , res + c);
            }
        }
    }
    dp[{pos , length}] = ok;
    return ok;
}

void init(){
    dp.clear();
    mp.clear();
    v.clear();
    len.clear();
    ans.clear();
    rev.clear();
    passlength = 0;
    res = "";
    ids.clear();
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int t; cin >> t;
   while(t--){
        init();
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            string x;
            cin >> x;
            v.push_back(x);
            mp[x] = 1;
            len.push_back(x.size());
            ids[x] = i;
            rev[i] = x;
        }
        cin >> s;
        m = s.size();
        if(f(0 , 0 , "")){
            cout << rev[res[0] - '0'];
            for(int i = 1 ; i < res.size() ; i++){
                cout << " " << rev[res[i] - '0'];
            }
        } else cout << "WRONG PASSWORD";
        cout << "\n";
    }
  return 0;
}
