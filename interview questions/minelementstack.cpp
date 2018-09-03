//https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1


#include <iostream>
#include <stack>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};

/*returns min element from stack*/
int _stack :: getMin()
{
    if(s.empty())
        return -1;
   return minEle;
}
/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.empty())
        return -1;
    int val = s.top(),tmp;
    s.pop();
    if(val < minEle)
    {
        tmp = minEle;
        minEle = 2*minEle - val;
        return tmp;
    }
    return val;
}
/*push element x into the stack*/
void _stack::push(int x)
{
    if(s.empty())
    {
        s.push(x);
        minEle = x;
        return;
    }
    int tmp;
    if(x < minEle)
    {
        tmp = x;
        x = 2*x - minEle;
        minEle = tmp;
    }
    s.push(x);
    // cout<<x<<" "<<minEle<<endl;
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){
       int qt;
       cin>>qt;
       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }
}