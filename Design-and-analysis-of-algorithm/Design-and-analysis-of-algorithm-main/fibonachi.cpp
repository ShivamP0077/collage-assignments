#include<iostream>
#include<sys/time.h>
#include<cmath> 
using namespace std;

long double fib_iteration(int n)
{
    long double fib1 = 0;
    long double fib2 = 1;
    for(int i = 2; i <= n; i++)
    {
        long double temp = fib1 + fib2;
        fib1 = fib2;
        fib2 = temp;
    }
    return fib2;
}

long double fib_recursion(int n)
{
    if(n == 0 || n == 1);
        return n;

    return fib_recursion(n-1) + fib_recursion(n-2);
}

long double fib_using_equation(int n)
{
     return (pow(((1 + sqrt(5)) / 2), n - 1) - pow(((1 - sqrt(5)) / 2), n - 1)) / sqrt(5);
}

int main(void)
{
    int num = 80;

    timeval t1, t2;

    cout << "----------------------------------------Iteration----------------------------------" << endl;

    gettimeofday(&t1, NULL);
    fib_iteration(num);
    gettimeofday(&t2, NULL);

    cout << "time in sec......." << endl;
    cout << "start: " << t1.tv_sec << " End: " << t2.tv_sec << endl;
    cout << "Difference in sec: " << t2.tv_sec - t1.tv_sec << endl;

    cout << "time in microsec......." << endl;
    cout << "start: " << t1.tv_usec << " End: " << t2.tv_usec << endl;
    cout << "Difference in microsec : " << t2.tv_usec - t1.tv_usec << endl;

     cout << "-----------------------------------------Fibonacci using equation-------------------" << endl;

    gettimeofday(&t1, NULL);
    fib_using_equation(num);
    gettimeofday(&t2, NULL);

    cout << "time in sec......." << endl;
    cout << "start: " << t1.tv_sec << " End: " << t2.tv_sec << endl;
    cout << "Difference in sec: " << t2.tv_sec - t1.tv_sec << endl;

    cout << "time in microsec......." << endl;
    cout << "start: " << t1.tv_usec << " End: " << t2.tv_usec << endl;
    cout << "Difference in microsec : " << t2.tv_usec - t1.tv_usec << endl;


    cout << "-----------------------------------------Recursion---------------------------------" << endl;

    gettimeofday(&t1, NULL);
    long double ans = fib_recursion(num);
    gettimeofday(&t2, NULL);

    cout << "time in sec......." << endl;
    cout << "start: " << t1.tv_sec << " End: " << t2.tv_sec << endl;
    cout << "Difference in sec: " << t2.tv_sec - t1.tv_sec << endl;

    cout << "time in microsec......." << endl;
    cout << "start: " << t1.tv_usec << " End: " << t2.tv_usec << endl;
    cout << "Difference in microsec : " << t2.tv_usec - t1.tv_usec << endl;

    return 0;
}
