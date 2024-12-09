#include <bits/stdc++.h>
#include <stack>
using namespace std;

string s;
stack<int> q;

int main(){
    int a = 0;
    int b = 0;
    cin >> s;
    for(int i = 0;i < s.length();i++){
        if(s[i] == '@') break;
        else if(s[i] == '.'){
            q.push(a);
            a = 0;
            b = 0;
        }else if(s[i] <= '9' && s[i] >= '0'){
            a = b * 10 + s[i] - '0';
            b = a;
        }
        else{
            if(s[i] == '-'){
                int t = q.top();
                q.pop();
                int m = q.top();
                q.pop();
                q.push(m - t);
            }
            if(s[i] == '+'){
                int t = q.top();
                q.pop();
                int m = q.top();
                q.pop();
                q.push(m + t);
            }
            if(s[i] == '/'){
                int t = q.top();
                q.pop();
                int m = q.top();
                q.pop();
                q.push(m / t);
            }
            if(s[i] == '*'){
                int t = q.top();
                q.pop();
                int m = q.top();
                q.pop();
                q.push(m * t);
            }
        }
    }
    cout << q.top() << endl;
    return 0;
}