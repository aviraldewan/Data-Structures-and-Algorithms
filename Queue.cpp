#include<iostream>
#include<climits>
using namespace std;

#define n INT_MAX

class queue
{
     int* arr;
     int front, back; 
public:
     queue()
     {
          arr = new int[n];
          front = -1;
          back = -1;
     }
     void push(int x)
     {
          if (back == n-1)
          {
               cout << "queue overflow\n";
               return;
          }
          back++;
          arr[back] = x;
          if (front == -1)
               front++;
     }
     void pop()
     {
          if (front == -1 || front > back)
          {
               cout << "no elements in queue\n";
               return;
          }
          front++;
     }
     int peek()
     {
          if (front == -1 || front > back)
          {
               cout << "no elements in queue\n";
               return -1;
          }
          return arr[front];
     }
     bool empty()
     {
          if (front == -1 || front > back)
               return true;
          return false;
     }
};

int main()
{
     queue s;
     cout << s.empty() << endl;
     s.push(1);
     s.push(3);
     cout << s.peek() << endl;
     s.pop();
     cout << s.peek() << endl;
     cout << s.empty() << endl;
     s.pop();

}
