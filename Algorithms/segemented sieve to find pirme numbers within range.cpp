//SMOP is smallest multiple of primeno.

#include <bits/stdc++.h>
using namespace std;

void sieve(int n, vector<int> &primeNos) // for 1st segment in range of 2 to sqrt(n)
{ // O(n)
    vector<bool> list (n,true);
    for(int i=2;i*i<n;i++)
    {
        if(list[i]==true)
        {
            for(int j=i*i ; j<n; j=j+i)
            {
                list[j] = false;
            }
        }
    }
     for(int i=2;i<n;i++)
    {
        if(list[i]==true)
        {
            cout<<i<<" ";
            primeNos.push_back(i);
        }
    }
}

void segmentedSieve(int n) // O(sqrt(n))
{
    // segments are of size sqrt(n);
    int range = floor(sqrt(n));
    vector<int> primeNos; 
    primeNos.reserve(range);
    sieve(range,primeNos);
    // 1st segment is processed ==> all prime numbers between 2 to sqrt(n) in primeNos

    int low = range + 1; // lower bound of 2nd segment
    int high = 2*range;  // upper bound of 2nd segment

    while(low<n)
    {
        cout<<"\nRange("<<low<<","<<high<<") : ";
        bool isPrime[range+1]; // numbers in the segment : index => 0 to range
        memset(isPrime,true,range+1);
        for(int i=0;i<primeNos.size();i++)
        {
            int SMOP = (low/primeNos[i])*primeNos[i];
            if(SMOP<low)
            {
                SMOP = SMOP + primeNos[i];
            }
            for(int j=SMOP ; j<high ; j = j + primeNos[i]) // moving across the segment
            {
                isPrime[j-low] = false;
            }
        }
        for(int i=low;i<high;i++)
        {
            if(isPrime[i-low]==true)
            {
                cout<<i<<" ";
            }
        }
        low = low + range;
        high = high + range;
    }
}

int main()
{
	int n =100;
    segmentedSieve(n);
}