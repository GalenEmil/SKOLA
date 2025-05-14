#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> orderQueue;

    orderQueue.push_back("Margherita Pizza");
    orderQueue.push_back("Caesar Salad");
    orderQueue.push_back("Cheeseburger");

    while (!orderQueue.empty())
    {
        cout << "Filling order: " << orderQueue.front() << '\n';
        orderQueue.erase(orderQueue.begin());
    }
}
