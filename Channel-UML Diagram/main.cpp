#include <iostream>
#include "telephone/Telephone.h"
#include "channel/Channel.h"

using namespace std;


int main() {
    Channel* channel1;
    Channel* channel2;
    Channel* channel3;
    channel1 = new Telephone{};
    channel2 = new Fax{};
    channel3 = new SMS{};

    Contact contact(channel1, channel2, channel3);
    contact.sendAlarm("Wake up!");

    delete channel1;
    delete channel2;
    delete channel3;

    return 0;
}
