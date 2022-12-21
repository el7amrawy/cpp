#include <iostream>
using namespace std;

class Instrument
{
public:
    virtual void MakeSound() = 0;
};

class Accordion : public Instrument
{
public:
    void MakeSound()
    {
        cout << "Accordion playing.. . \n";
    }
};

class Piano : public Instrument
{
public:
    void MakeSound()
    {
        cout << "Piano playing.. .\n";
    }
};

int main()
{
    Instrument *a = new Accordion();
    Instrument *p = new Piano();
    Instrument *q = new Piano();

    Instrument *instruments[] = {a, p, q};
    for (int i = 0; i < sizeof(instruments) / sizeof(Instrument); i++)
        instruments[i]->MakeSound();
    return 0;
}