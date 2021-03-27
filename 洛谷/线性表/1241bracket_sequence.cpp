//
// Created by 木子又欠 on 2020/9/20.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[105]; // 标记  0:未被匹配过  1：已被匹配

int main()
{
    int i,j;
    string s;
    cin >> s;
    for (i=0; i<s.length(); i++) {
        if (s[i] == ')') { // 找到了右括号
            for (j=i-1; j>=0; j--) {
                if (s[j] == '(' and a[j] == 0) { // 找到了没被匹配过的左括号且匹配成功
                    a[i] = a[j] = 1;
                    break;
                }
                else if (s[j] == '[' and a[j] == 0) break; // 找到了左括号但匹配失败
            }
            // 找不到左括号，不做任何操作
        }
            // 下面同理
        else if (s[i] == ']') {
            for (j=i-1; j>=0; j--) {
                if (s[j] == '[' and a[j] == 0) {
                    a[i] = a[j] = 1;
                    break;
                }
                else if (s[j] == '(' and a[j] == 0) break;
            }
        }
    }
    for (i=0; i<s.length(); i++) {
        if (a[i] == 0) { // 没有匹配则成对输出
            if (s[i] == '(' or s[i] == ')') cout << "()";
            else cout << "[]";
        }
        else cout << s[i]; // 匹配成功则直接输出
    }
    return 0;
}


//****************using the algorithm of stack***********************//
#include<cstdio>
#include<cstring>
int  q[101],top;
//array q is the stack,
//q[i] means No.i element in stack relate to the c[i];
//top is the size of the stack;
char c[101],b[101];
//c is the orignal string;
//b[i] is the added  element to match c[i];
int main()
{
    int i,l;
    scanf("%s",c);
    l=strlen(c);
    for (i=0;i<l;i++)
    {
        if (c[i]=='(') {q[++top]=i; b[i]=')';}
        if (c[i]=='[') {q[++top]=i; b[i]=']';}
        if (c[i]==')'||c[i]==']')
            if (!top||b[q[top]]!=c[i])  //fail to match
                if (c[i]==')') b[i]='('; else b[i]='[';
            else b[q[top--]]=' ';//successfully matched
    }
    for (i=0;i<l;i++)
    {
        if (b[i]=='('||b[i]=='[') printf("%c",b[i]);
        printf("%c",c[i]);
        if (b[i]==')'||b[i]==']') printf("%c",b[i]);
    }
    return 0;
}