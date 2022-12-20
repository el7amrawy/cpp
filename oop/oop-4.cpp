#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel
{
private:
    string Name;
    int SubsCount;
    list<string> PublishedVideoTitles;

protected:
    string OwnerName;

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
        cout << "Videos: " << endl;
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

class CookingYTChannel : public YouTubeChannel
{
public:
    CookingYTChannel(string name, string ownerName) : YouTubeChannel(name, ownerName)
    {
    }
    void Practice()
    {
        cout << OwnerName << " is practicing cooking, learning new recipes, ....\n";
    }
};
int main()
{
    CookingYTChannel c("alica cooking", "alica");
    CookingYTChannel c2("adam's kitchen", "adam");
    YouTubeChannel y("lmaoo channel", "lmaoo");
    c.Subscribe();
    c.PublishVideo("cook an apple");
    c.GetInfo();
    y.GetInfo();
    c.Practice();
    c2.Practice();
    return 0;
}