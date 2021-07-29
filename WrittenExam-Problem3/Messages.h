//
// Created by paula on 6/22/2021.
//

#ifndef PROBLEM3_MESSAGES_H
#define PROBLEM3_MESSAGES_H

#include <string>

using namespace std;


class Message {
private:
    string text;

public:
    Message() = default;

    Message(string text);

    string getMessage();

    ~Message() = default;
};


class ShortMessage : public Message {
private:
    string text;
public:
    ShortMessage(string text);

    ~ShortMessage() = default;
};


class NormalMessage : public Message {
private:
    string text;

public:
    NormalMessage(string text);

    ~NormalMessage() = default;
};


class MessageWithAttachment : public Message {
private:
    Message* message;
    string attachmentLocation;

public:
    MessageWithAttachment(Message* message, string attachmentLocation);

    ~MessageWithAttachment();
};


#endif //PROBLEM3_MESSAGES_H
