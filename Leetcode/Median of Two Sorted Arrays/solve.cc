#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) 
    {
        int *C = new int[m+n+5];
        int i=0, j=0, p=0;
        for(/*pass*/;i<m && j<n;/*pass*/)
        {
            if(A[i]<B[j]) C[p++] = A[i++];
            else C[p++] = B[j++];
        }
        while(i<m) C[p++] = A[i++];
        while(j<n) C[p++] = B[j++];

        if((m+n)%2==0) return (C[(m+n-1)/2] + C[(m+n)/2])/2.;
        else return C[(m+n-1)/2];
    }
};

int main()
{
    Solution S;
    int A[] = {1,1,3,3};
    int B[] = {1,1,3,3};
    print(S.findMedianSortedArrays(A,4, B, 4));
    return 0;
}
