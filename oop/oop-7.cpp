#include <iostream>

using namespace std;

class Smartphone
{
public:
    virtual void TakeSelfie() = 0;
    virtual void MakeCall() = 0;
};

class Android : public Smartphone
{
public:
    void TakeSelfie()
    {
        cout << "Android took a selfie.\n";
    }
    void MakeCall()
    {
        cout << "Android is calling....\n";
    }
};

class IPhone : public Smartphone
{
public:
    void TakeSelfie()
    {
        cout << "IPhone took a selfie.\n";
    }
    void MakeCall()
    {
        cout << "IPhone is calling....\n";
    }
};

int main()
{
    Smartphone *s1 = new Android();
    Smartphone *s2 = new IPhone();

    s1->TakeSelfie();
    (*s2).MakeCall();
    return 0;
}