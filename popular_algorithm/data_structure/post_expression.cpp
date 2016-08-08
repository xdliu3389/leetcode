#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <stdlib.h>

using namespace std;
 
class calculate {
public:
    //输出vector, 用于调试
    void printV() {
        for(int i=0; i<numqueue.size(); i++)
            cout << numqueue[i] << " ";
        cout << endl;
    }
 
    //构造函数. 依次调用类里的方法并最终得到结果
    calculate(string _in):in(_in) {
        len = in.size();
        adjustStringStyle();
        //cout << in << endl;
        mid2post();
        //printV();
        int res = calFromPost();
    }
 
    //将表达式里的字符{ [ } ]换成( ( ) )方便后面的处理
    void adjustStringStyle() {
        for(int i=0; i<len; i++) {
            if(in[i]=='{')
                in[i] = '(';
            else if(in[i]=='}')
                in[i] = ')';
            else if(in[i]=='[')
                in[i] = '(';
            else if(in[i]==']')
                in[i] = ')';
        }
    }
 
    //中缀转后缀.
    //这里唯一需要注意的是遇到负数如何处理.　我的处理方法:
    //　1.如果遇到-,那么判断它是否是第一个字符,　如果是第一个字符那么就表明接下来的数是负数
    //　2.如果不是第一个字符, 那么就判断前面的是不是(,　这里只考虑负数
    void mid2post() {
        string tmp = "";
        for(int i=0; i<len; i++) {
            if(in[i]>='0' && in[i]<='9')
                tmp += in[i];
            else {
                if((in[i]=='-' && i==0) || (in[i]=='-' && (in[i-1]=='(' || in[i-1]=='+' || in[i-1]=='-' || in[i-1]=='/')))
                    tmp += in[i];
                else {
                    if(tmp != "") {
                        numqueue.push_back(atoi(tmp.c_str()));
                        tmp = "";
                    }
                    if(in[i]=='+' || in[i]=='-') {
                        while(!num.empty() && num.top()!='(') {
                            numqueue.push_back(num.top());
                            num.pop();
                        }
                        num.push(in[i]);
                    } else if(in[i]=='*' || in[i]=='/') {
                        while(!num.empty() && (num.top()=='*'||num.top()=='/')) {
                            numqueue.push_back(num.top());
                            num.pop();
                        }
                        num.push(in[i]);
                    } else if(in[i]=='(') {
                        num.push(in[i]);
                    } else {
                        while(num.top()!='(') {
                            numqueue.push_back(num.top());
                            num.pop();
                        }
                        num.pop();
                    }
                }
            }
        }
        if(tmp != "")
            numqueue.push_back(atoi(tmp.c_str()));
        while(!num.empty()) {
            numqueue.push_back(num.top());
            num.pop();
        }
    }
 
    int calFromPost() {
        int res;
        int n1, n2;
        for(int i=0; i<numqueue.size(); i++) {
            if(numqueue[i]=='+') {
                n1 = num.top();
                num.pop();
                n2 = num.top();
                num.pop();
                num.push(n1+n2);
            } else if(numqueue[i]=='-') {
                n1 = num.top();
                num.pop();
                n2 = num.top();
                num.pop();
                num.push(n2-n1);
            } else if(numqueue[i]=='*') {
                n1 = num.top();
                num.pop();
                n2 = num.top();
                num.pop();
                num.push(n1*n2);
            } else if(numqueue[i]=='/') {
                n1 = num.top();
                num.pop();
                n2 = num.top();
                num.pop();
                num.push(n2/n1);
            } else {
                num.push(numqueue[i]);
            }
        }
        cout << num.top();
        return num.top();
    }
 
private:
    stack<int> num;
    vector<int> numqueue;
    string in;
    int len;
};
 
int main()
{
    string s;
    while(getline(cin, s))
        calculate c(s);
    return 0;
}
