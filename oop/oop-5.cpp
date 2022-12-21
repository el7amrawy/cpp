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
    int ContentQuality;

public:
    YouTubeChannel(string name, string ownerName)
    {
        Name = name;
        OwnerName = ownerName;
        SubsCount = 0;
        ContentQuality = 0;
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

    void CheckAnalytics()
    {
        if (ContentQuality < 5)
            cout << OwnerName << " has bad quality content.\n";
        else
            cout << OwnerName << " has good quality content.\n";
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
        ContentQuality++;
    }
};

class SingingYTChannel : public YouTubeChannel
{
public:
    SingingYTChannel(string name, string ownerName) : YouTubeChannel(name, ownerName)
    {
    }

    void Practice()
    {
        cout << OwnerName << " is practicing singing, learning new songs, ....\n";
        ContentQuality++;
    }
};
int main()
{
    CookingYTChannel c("Amy's kitchen", "Amy");
    SingingYTChannel s("Mark's band", "Marck");

    c.Practice();

    s.Practice();
    s.Practice();
    s.Practice();
    s.Practice();

    YouTubeChannel *yt1 = &c;
    YouTubeChannel *yt2 = &s;

    (*yt1).CheckAnalytics();
    yt2->CheckAnalytics();
    return 0;
}