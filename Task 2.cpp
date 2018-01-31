#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
 
 
 
int diff (int a, int b) {
 
 
    return abs(a-b);
}
 
int solution( vector<int> &A)  {
 
    int themax=0;
    for (int k=0;k<A.size()-1;k++)  {
 
        int first_half_max=0;
        int second_half_max=0;
        if (k==0 && A[0]<0) first_half_max=A[k];
        else {
            for (int i = 0; i<k+1;i++) {
            if (A[i]>first_half_max) first_half_max = A[i];
        }
 
        }
 
        if (k==A.size()-2 && A[k+1] <0) second_half_max=A[k+1];
        else {
        for (int j = k+1; j<A.size();j++) {
 
 
                if (A[j]>second_half_max) second_half_max = A[j];
        }
        }
 
 
            if (diff(first_half_max,second_half_max) > themax) themax = diff(first_half_max,second_half_max);
 
    }
    return themax;
 
}
 
 
 
int main()
{
    vector <int> A(3);
    A[0] = 1;
    A[1] = 3;
    A[2] = -3;
    cout<<solution(A)<<endl;
 
    return 0;
}