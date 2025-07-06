#include<bits/stdc++.h>
using namespace std;

class NotificationChannel {
public:
    virtual void send(string message) = 0;
    virtual ~NotificationChannel() {}
};

class EmailService : public NotificationChannel {
public:
    void send(string message) override {
        cout << "Sending Email: " << message << endl;
    }
};

class SMSService : public NotificationChannel {
public:
    void send(string message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

class NotificationService {
private:
    shared_ptr<NotificationChannel> notificationChannel;
public:
    NotificationService(shared_ptr<NotificationChannel> channel) {
        this->notificationChannel = channel;
    }
    void notify(string message) {
        notificationChannel->send(message);
    }
};

int main() {
    shared_ptr<NotificationChannel> emailNotification = make_shared<EmailService>();
    shared_ptr<NotificationChannel> smsNotification = make_shared<SMSService>();

    NotificationService emailNotificationService(emailNotification);
    emailNotificationService.notify("You order has been shipped!");

    NotificationService smsNotificationService(smsNotification);
    smsNotificationService.notify("OTP code: 123456");
    return 0;
}