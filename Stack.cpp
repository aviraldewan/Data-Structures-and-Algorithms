#include<iostream>
#include<climits>
using namespace std;

#define n INT_MAX

class stack
{
     int* arr;
     int Top;
public:
     stack()
     {
          arr = new int[n];
          Top = -1;
     }
     void push(int element)
     {
          if (Top == n-1)
          {
               cout << "stack overflow\n";
               return;
          }
          Top++;
          arr[Top] = element;
     }
     void pop()
     {
          if (Top == -1)
          {
               cout << "no element to pop\n";
               return;
          }
          Top--;
     }
     void top()
     {
          if (Top == -1)
          {
               cout << "no element in stack\n";
               return;
          }
          cout << arr[Top] << endl;
     }
     bool empty()
     {
          if (Top == -1)
               return true;
          return false;
     }
};

int main()
{
     stack s;
     cout << s.empty() << endl;
     s.push(1);
     s.push(3);
     s.push(2);
     s.top();
     s.pop();
     s.top();
     s.pop();
     s.top();
     cout << s.empty() << endl;
     s.pop();
}
