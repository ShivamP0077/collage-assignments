#include <iostream>
using namespace std;

int count = 0;

int tower_hanoi(int n, char a, char b, char c)
{
  if (n == 1)
  {
    cout << " move 1st disk " << a << " to " << c << endl;
    count++;
    return 0;
  }
  tower_hanoi(n - 1, a, c, b);
  cout << " move " << n << " th disk " << a << " to "<<c<<endl; count++;
      tower_hanoi(n - 1, b, a, c);
}

int main(void)
{
  int n;
  cout << "Enter a number of disk : ";
  cin >> n;
  tower_hanoi(n, 's', 'h', 'd');
  cout << "count : " << count;
}