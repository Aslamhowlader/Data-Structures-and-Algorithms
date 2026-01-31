#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    v.push_back(12);
    v.push_back(23);
    v.push_back(100);
    v.push_back(230);
    v.push_back(120);
    v.push_back(250);
    v.push_back(143);
    v.push_back(232);


    cout << v.front() << endl;
    cout << v.back() << endl;


    cout << v.size() << endl;


    if(v.empty()) cout << "Empty" << endl;
    else cout << "Not Empty" << endl;


    v.pop_back();
    v.pop_back();
    v.pop_back();


    for(int i = 0; i < 8; i++){
        cout << v[i] << " ";
    }
}
