#include<iostream>
#include<sys/time.h>
using namespace std;

long double fac_iteration(int n)
{
    long double ans = 1;
    for(int i = 1; i<n; i++)
    {
        ans *= i;
    }
    return ans;
}

long double fac_recersion(int n)
{
    if(n == 1)
     return 1;

    return fac_recersion(n-1)*n;
}


int main(void)
{
    int num = 50;

    timeval t1,t2;

     cout<<"----------------------------------------Iteration----------------------------------"<<endl;
    
    gettimeofday(&t1,NULL);
    fac_iteration(num);
    gettimeofday(&t2,NULL);

    cout<<"time in sec......."<<endl;
    cout<<"start: "<<t1.tv_sec<<" End: "<<t2.tv_sec<<endl;
    cout<<"Diffrencr in sec: "<<t2.tv_sec - t1.tv_sec<<endl;

    cout<<"time in microsec......."<<endl;
    cout<<"start: "<<t1.tv_usec<<" End: "<<t2.tv_usec<<endl;
    cout<<"Diffrencr in microsec : "<<t2.tv_usec - t1.tv_usec<<endl;
 

    
    gettimeofday(&t1,NULL);
    fac_recersion(num);
    gettimeofday(&t2,NULL);

    cout<<"-----------------------------------------recrction---------------------------------"<<endl;
    
    cout<<"time in sec......."<<endl;
    cout<<"start: "<<t1.tv_sec<<" End: "<<t2.tv_sec<<endl;
    cout<<"Diffrencr in sec: "<<t2.tv_sec - t1.tv_sec<<endl;
  
 
    cout<<"time in microsec......."<<endl;
    cout<<"start: "<<t1.tv_usec<<" End: "<<t2.tv_usec<<endl;
    cout<<"Diffrencr in microsec : "<<t2.tv_usec - t1.tv_usec<<endl;

}
  