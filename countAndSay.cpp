#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
    vector<int> intVec;

    INSERT_ELEMENTS(intVec,1,9);

    vector<int>::iterator pos;
    pos = find(intVec.begin(),intVec.end(),5);

    if(pos != intVec.end())
        cout << "The value 5 exists,and its position is " <<
        distance(intVec.begin(),pos) + 1 << endl;
    else
        cout << "The value 4 not found!" << endl;

    pos = find(intVec.begin(),intVec.end(),12);

    if(pos != intVec.end())
        cout << "The value 12 exists,and its position is " <<
        distance(intVec.begin(),pos) + 1 << endl;
    else
        cout << "The value 12 not found!" << endl;
}
