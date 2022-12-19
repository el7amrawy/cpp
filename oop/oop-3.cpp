#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel
{
private:
    string Name;
    string OwnerName;
    int SubsCount;
    list<string> PublishedVideoTitles;

public:
    YouTubeChannel(string name, string ownerName)
    {
        Name = name;
        OwnerName = ownerName;
        SubsCount = 0;
    }

    void GetInfo()
    {
        cout << "Name: " << Name << endl;
        cout << "Owner: " << OwnerName << endl;
        cout << "Subs: " << SubsCount << endl;
        cout << "List: " << endl;
        for (string s : PublishedVideoTitles)
        {
            cout << s << endl;
        }
    }

    int Subscribe()
    {
        return ++SubsCount;
    }

    int Unsubscribe()
    {
        return SubsCount > 0 ? --SubsCount : SubsCount;
    }

    list<string> PublishVideo(string videoTitle)
    {
        PublishedVideoTitles.push_back(videoTitle);
        return PublishedVideoTitles;
    }
};

int main()
{
    YouTubeChannel y("aliTV", "ali");
    y.Subscribe();
    y.Subscribe();
    y.Unsubscribe();
    y.GetInfo();
    return 0;
}