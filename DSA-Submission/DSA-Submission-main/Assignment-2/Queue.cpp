class Queue
{
  int front, rear;
  vector<int> arr;

public:
  Queue()
  {
    front = 0;
    rear = 0;
    arr.resize(100001);
  }
  void enqueue(int e)
  {
    if (rear == 0)
    {
      rear = 1;
      front = 1;
    }
    arr[rear] = e;
    rear++;
  }
  int dequeue()
  {
    if (front != rear)
    {
      int n = arr[front];
      front++;
      return n;
    }
    else
      return -1;
  }
};