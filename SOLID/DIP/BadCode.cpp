#include<bits/stdc++.h>
using namespace std;

class EmailService {
public:
    void sendEmail(string message) {
        cout << "Sending Email:" << message << endl;
    }
};

class SMSService {
public:
    void sendSMS(string message) {
        cout << "Sending SMS:" << message << endl;
    }
};

class NotificationService {
private:
    EmailService emailService;
    SMSService smsService;
public:
    NotificationService() {
        this->emailService = EmailService();
        this->smsService = SMSService();
    }
    void notifyByEmail(string message) {
        emailService.sendEmail(message);
    }
    void notifyBySMS(string message) {
        smsService.sendSMS(message);
    }
};