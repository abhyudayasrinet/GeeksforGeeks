#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

//question: https://www.geeksforgeeks.org/maximum-sum-iarri-among-rotations-given-array/


int main()
{
    int length;
    cin>>length;
    vector <int> a(length);
    for(int i=0;i<length;i++)
        cin>>a[i];

    int sum = 0,array_sum=0;
    for(int i=0;i<length;i++)
    {
        sum += i*a[i];
        array_sum += a[i];
    }
    int max = sum;
    // cout<<max<<endl;
    for(int i=1;i<length;i++) 
    {
        sum = sum + length*a[i-1] - array_sum;
        // cout<<sum<<endl;
        if(sum > max)
            max = sum;
    }
    cout<<"MAX: "<<max<<endl;
    return 0;
}
