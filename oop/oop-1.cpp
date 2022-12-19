#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel
{
public:
    string Name;
    string OwnerName;
    int SubsCount;
    list<string> PublishedVideoTitles;
};

int main()
{
    YouTubeChannel y;
    y.Name = "lmaoo";
    y.PublishedVideoTitles = {"1", "2", "3"};
    cout << "Name: " << y.Name;
    cout << "List: " << endl;
    for (string s : y.PublishedVideoTitles)
    {
        cout << s << endl;
    }
    return 0;
}