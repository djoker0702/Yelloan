#include <iostream>
#include <bits/stdc++.h>
using namespace std;



vector<int> defactor (int x) {

    vector<int> result;
    stack<int> temp; //we need to get the digits in a LIFO
    if (!x) result.push_back(x); //handle the 0 value
    while (x) {
        temp.push(x%10);
        x/=10;
    }
    while (!temp.empty()) {
        result.push_back(temp.top());
        temp.pop();
    }
    return result;
}

int solution (int A, int B) {

    vector<int> sA,sB;
    sA = defactor(A);
    sB = defactor(B);
    int ia=0,ib=0;
    while (ia < sA.size() & ib < sB.size()) {
            if (sA[ia] == sB[ib]) { //compare A and B digits element by element
                ia++;
                ib++;
            } else if (sA[ia] != sB[ib]  ) {
                if (ia==0) {ib++;} // we should always increment B to avoid infinite loop, but in a way that does n't affect the result
                ia=0;
            }
            if (ia==sA.size()) return ib-sA.size(); // A is in B : return
    }

    return -1;
}

int main()
{
    int A,B;
    cin>>A>>B;
    cout<< solution(A,B) <<endl;
    return 0;
}
