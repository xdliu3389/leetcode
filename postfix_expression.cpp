/*
        This program is used for pratice postfixexpression calculating.
        And it supports parenthesis, but it doesn't check if the input is legal.
        So you may get the undefine result if your expression input is illegal.
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <stdlib.h>

using namespace std;

//Print every element in exp;
//This function is for debugging
void printVec(vector<string> &exp)
{
    cout << "begin" << endl;
    int len = exp.size();
    for(int i=0; i<len; i++)
        cout << exp[i] << endl;
    cout << "end" << endl << endl;
}

//Convert a string type input to a vector<string>
//so that we can distinct operator and number easily
void inputToExpression(vector<string> &expression, string input)
{
    int len = input.size();
    string tmp = "";
    for(int i=0; i<len; i++) {
        if((input[i]>='0' && input[i]<='9') || input[i]=='.') {
            tmp += input[i];
        } else {
    	    if(tmp != "")
                expression.push_back(tmp);
            tmp = ""; tmp+=input[i];
            expression.push_back(tmp);
            tmp = "";
        }
    }
    if(tmp.size() > 0)
        expression.push_back(tmp);
}

//MiddleExpression to PostfixExpression
//	* / ( : push them to stack directly
//  + -   : pop stack untile the stack is zero or meet (
//  )     : pop stack untile meet (
//  else  : output to vector res
void middleToPost(vector<string> &expression)
{
    stack<string> opStack;
    vector<string> res;
    bool flag;
    int len = expression.size();
    for(int i=0; i<len; i++) {
        flag = true;
        if(expression[i]=="*" || expression[i]=="/" || expression[i]=="(") {
            opStack.push(expression[i]);
        } else if(expression[i]=="+" || expression[i]=="-") {
            while(flag) {
                if(opStack.size()==0 || opStack.top()=="(") {
                    flag=false;
                } else {
                    res.push_back(opStack.top());
                    opStack.pop();
                }
            }
            opStack.push(expression[i]);
        } else if(expression[i]==")") {
            while(flag) {
                if(opStack.top()=="(") {
                    opStack.pop();
                    flag = false;
                } else {
                    res.push_back(opStack.top());
                    opStack.pop();
                }
            }
        } else {
            res.push_back(expression[i]);
        }
    }
    while(opStack.size() != 0) {
        res.push_back(opStack.top());
        opStack.pop();
    }
    expression.clear();
    expression.swap(res);
}

//Calculate the result through PostfixExpression exp
//    operator : pop the top 2 value and do the operation with this operator
//    value    : push the value to valStack
//    result   : after loop the vector, the result will be stored in the top of valStack
//               Pay attention, we don't check the legacy of the input expression, so
//               here we believe the expression is legal in default
double calculateFromPosixexp(vector<string> &exp)
{
    stack<double> valStack;
    double v1, v2;
    for(int i=0; i<exp.size(); i++) {
        if(exp[i][0]>='*' && exp[i][0]<='/') {
            v2 = valStack.top();  valStack.pop();
            v1 = valStack.top();  valStack.pop();
            if(exp[i] == "+") 
                valStack.push(v1+v2);
            else if(exp[i] == "-")
                valStack.push(v1-v2);
            else if(exp[i] == "*")
                valStack.push(v1*v2);
            else
                valStack.push(v1/v2);
        } else {
            v1 = atof(exp[i].c_str());
            valStack.push(v1);
        }
    }
    return valStack.top();
}

int main()
{
    vector<string> expression;
    stack<string> opStack;
    string input;
    double res;
    cin >> input;
    inputToExpression(expression, input);
    //printVec(expression);
    middleToPost(expression);
    //printVec(expression);
    res = calculateFromPosixexp(expression);
    cout << res << endl;
    return 0;
}

