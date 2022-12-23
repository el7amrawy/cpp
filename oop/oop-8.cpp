#include <iostream>
#include <list>

using namespace std;

struct YoutubeChannel
{
    string Name;
    unsigned int SubsCount;

    YoutubeChannel(string name, unsigned int subsCount)
    {
        Name = name;
        SubsCount = subsCount;
    }
    bool operator==(const YoutubeChannel &yt) const
    {
        return this->Name == yt.Name;
    }
};

struct MyCollection
{
    list<YoutubeChannel> MyChannels;

    void operator+=(YoutubeChannel yt)
    {
        (*this).MyChannels.push_back(yt);
    }

    void operator-=(YoutubeChannel yt)
    {
        this->MyChannels.remove(yt);
    }
};

ostream &operator<<(ostream &COUT, YoutubeChannel *yt)
{
    COUT << "Name: " << (*yt).Name << endl;
    COUT << "Subs: " << yt->SubsCount << endl;
    return COUT;
}

ostream &operator<<(ostream &COUT, MyCollection &myCollection)
{
    for (YoutubeChannel ytChannel : myCollection.MyChannels)
        COUT << &ytChannel << endl;
    return COUT;
}

int main()
{
    YoutubeChannel *yt1 = new YoutubeChannel("Teddy's channel", 20);
    YoutubeChannel yt2("lmaoo TV", 90);
    MyCollection co;
    // cout << yt1;
    // operator<<(cout, &yt2);
    co += *yt1;
    co += yt2;
    co -= *yt1;
    cout << co;
    return 0;
}
