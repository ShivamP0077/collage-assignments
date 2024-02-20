#include <iostream>
using namespace std;
const int MAX = 100;

class Queue
{
private:
  int queue[MAX];
  int f = -1, r = -1;
  int counter = 0;

public:
  bool isFull()
  {
    return counter == MAX;
  }
  bool isEmpty()
  {
    return counter == 0;
  }
  void push(int n)
  {
    if (r == -1)
    {
      r = 0;
      f = 0;
    }
    else if (!isFull())
    {
      if (r == MAX - 1)
      {
        r = 0;
      }
      else
      {
        r++;
      }
    }
    else if (isFull())
    {
      cout << "Queue is full!" << endl;
      return;
    }

    queue[r] = n;
    counter++;
  }
  void pop()
  {
    if (!isEmpty())
    {
      cout << queue[f] << endl;
      if (f == MAX - 1)
      {
        f = 0;
      }
      else
      {
        f++;
      }

      counter--;
    }
    else
    {
      cout << "Queue is empty!" << endl;
    }
  }
};
int main()
{
  Queue myQueue;
  myQueue.push(1);
  myQueue.push(2);
  myQueue.push(3);
  myQueue.pop();
  myQueue.pop();
  myQueue.pop();

  return 0;
}