#include <iostream>
#include <set>
#include <list>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    set<int> hej = {1, 2, 3, 4, 5};
    hej.insert(5);

    list<int> listan = {1, 2, 3, 4, 5};
    cout << listan.size() << endl;

    vector<int> vectorn = {1, 2, 3, 4, 5};
    vectorn.push_back(6);
    cout << vectorn.back() << endl;

    int array [5] = {1, 2, 3, 4, 5};
//    cout << array[9] << endl;

    map<string, int> mapen = {{"banana", 2}, {"orange", 3}};
    mapen["apple"] = 10;
    cout << mapen["apple"] << endl;
}
