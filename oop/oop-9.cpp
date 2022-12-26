#include <iostream>
using namespace std;

// class YouTubeChannel
// {
//     string Name;
//     int SubscribersCount;

// public:
//     YouTubeChannel(string name, int subscribersCount)
//     {
//         Name = name;
//         SubscribersCount = subscribersCount;
//     }
// };
class EquilatreraTriangle
{
private:
    float a;
    float circumference;
    float area;

public:
    void setA(float length)
    {
        a = length;
        circumference = a * 3;
        area = (1.73 * a * a) / 4;
    }
    // friend void printResults(EquilatreraTriangle);
    friend class Homework;
};

// void printResults(EquilatreraTriangle eq)
// {
//     cout << "circumference: " << eq.circumference << endl;
//     cout << "area: " << eq.area << endl;
// }
class Homework
{
public:
    void printResults(EquilatreraTriangle eq)
    {
        cout << "circumference: " << eq.circumference << endl;
        cout << "area: " << eq.area << endl;
    }
};

int main()
{
    EquilatreraTriangle eq;
    eq.setA(5);
    (new Homework)->printResults(eq);
    return 0;
}