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

    YouTubeChannel(string name, string ownerName)
    {
        Name = name;
        OwnerName = ownerName;
        SubsCount = 1;
    }

    void GetInfo()
    {
        cout << "Name: " << Name << endl;
        cout << "Owner: " << OwnerName << endl;
        cout << "List: " << endl;
        for (string s : PublishedVideoTitles)
        {
            cout << s << endl;
        }
    }
};

int main()
{
    YouTubeChannel y("aliTV", "ali");
    y.PublishedVideoTitles.push_back("1");
    y.PublishedVideoTitles.push_back("2");
    y.PublishedVideoTitles.push_back("3");
    y.GetInfo();
    return 0;
}