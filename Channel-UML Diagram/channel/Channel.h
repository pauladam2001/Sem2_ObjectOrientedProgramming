//
// Created by paula on 6/18/2021.
//

#ifndef CHANNEL_UML_DIAGRAM_WRITTEN_CHANNEL_H
#define CHANNEL_UML_DIAGRAM_WRITTEN_CHANNEL_H

#include <string>

using namespace std;


class Channel {
public:
    virtual void send(string message) = 0;

    virtual ~Channel() = default;
};


class Failover : public Channel {
private:
    Channel* channel1;
    Channel* channel2;
public:
    void send(string message) override {
        try {
            this->channel1->send(message);
        }
        catch (runtime_error& e) {
            try {
                this->channel2->send(message);
            }
            catch (runtime_error& e) {
                cout << "Both channels busy!";
            }
        }
    }
};


class Contact {
private:
    Channel* channel1;
    Channel* channel2;
    Channel* channel3;

public:
    Contact(Channel* channel1, Channel* channel2, Channel* channel3): channel1{channel1}, channel2{channel2}, channel3{channel3} {

    }

    void sendAlarm(string message) {
        int sem = 0;
        while (sem != 2) {
            try {
                this->channel1->send(message);
            }
            catch (runtime_error& e) {
                cout << e.what() << "\n";
                try {
                    this->channel2->send(message);
                }
                catch (runtime_error& e) {
                    cout << e.what() << "\n";
                    this->channel3->send(message);
                }
            }
            sem++;
            try {
                this->channel2->send(message);
            }
            catch (runtime_error& e) {
                cout << e.what() << "\n";
                this->channel3->send(message);
            }
            sem++;
            this->channel3->send(message);
        }
    }
};


#endif //CHANNEL_UML_DIAGRAM_WRITTEN_CHANNEL_H
