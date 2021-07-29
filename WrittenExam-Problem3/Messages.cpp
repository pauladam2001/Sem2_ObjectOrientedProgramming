//
// Created by paula on 6/22/2021.
//

#include "Messages.h"
#include <stdexcept>

Message::Message(string text): text{text} {

}

string Message::getMessage() {
    return this->text;
}



ShortMessage::ShortMessage(string text) : Message(text) {
    this->text = text;
    if (this->text.size() > 70)
        throw std::runtime_error("Text for short message is greater than 70 characters!");
}



NormalMessage::NormalMessage(string text) : Message(text) {
    this->text = text;
}



MessageWithAttachment::MessageWithAttachment(Message *message, string attachmentLocation):Message(message->getMessage() + attachmentLocation) {

}

MessageWithAttachment::~MessageWithAttachment() {
    delete this->message;
}
