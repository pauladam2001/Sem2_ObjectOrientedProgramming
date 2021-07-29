#include <iostream>
#include "Contacts.h"
#include "Messages.h"

using namespace std;


int main() {
    Contact* contact1;
    contact1 = new Person("John");
    Contact* contact2;
    contact2 = new Person("Alice");

    Contact* group1;
    group1 = new Group("University friends");
    group1->addContact(contact1);
    group1->addContact(contact2);

    Contact* contact3;
    contact3 = new Person("Lilian");
    Contact* contact4;
    contact4 = new Person("Michael");
    group1->addContact(contact3);
    group1->addContact(contact4);

    Contact* group2;
    group2 = new Group("Parents");
    Contact* contact5;
    contact5 = new Person("Mother");
    Contact* contact6;
    contact6 = new Person("Father");
    group2->addContact(contact5);
    group2->addContact(contact6);

    Contact* contact7;
    contact7 = new Person("Charles");

    Message* message1;
    message1 = new ShortMessage("I arrived safely");

    group2->sendMessage(message1);

    Message* message2;
    message2 = new NormalMessage("I invite you to my birthday party");

    Message* message3;
    message3 = new MessageWithAttachment(message2, " in Medias, Sibiu county");

    contact7->sendMessage(message3);

    group1->sendMessage(message3);


    delete contact1;
    delete contact2;
    delete contact3;
    delete contact4;
    delete contact5;
    delete contact6;
    delete group1;
    delete group2;
    delete message1;
    delete message2;
    delete message3;

    return 0;
}
