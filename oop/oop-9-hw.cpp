#include <iostream>
#include <list>

using namespace std;

class YoutubeChannel
{
    string Name;
    unsigned int SubsCount;

public:
    bool operator==(const YoutubeChannel &yt) const
    {
        return this->Name == yt.Name;
    }
    YoutubeChannel(string name, unsigned int subsCount)
    {
        Name = name;
        SubsCount = subsCount;
    }
    friend ostream &operator<<(ostream &, YoutubeChannel &);
};

class MyCollection
{
    list<YoutubeChannel> MyChannels;

public:
    void operator+=(YoutubeChannel yt)
    {
        (*this).MyChannels.push_back(yt);
    }

    void operator-=(YoutubeChannel yt)
    {
        this->MyChannels.remove(yt);
    }
    friend ostream &operator<<(ostream &, MyCollection &);
};

ostream &operator<<(ostream &COUT, YoutubeChannel &yt)
{
    COUT << "Name: " << yt.Name << endl;
    COUT << "Subs: " << yt.SubsCount << endl;
    return COUT;
}

ostream &operator<<(ostream &COUT, MyCollection &myCollection)
{
    for (YoutubeChannel ytChannel : myCollection.MyChannels)
        COUT << ytChannel << endl;
    return COUT;
}

int main()
{
    YoutubeChannel yt1("Teddy's channel", 20);
    YoutubeChannel yt2("lmaoo TV", 90);
    MyCollection co;

    co += yt1;
    co += yt2;
    // co -= yt1;
    cout << co;
    return 0;
}
