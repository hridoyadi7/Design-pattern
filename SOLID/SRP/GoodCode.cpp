#include<bits/stdc++.h>
using namespace std;

class InvoiceRepository{
    void saveToDatabase() {
        cout << "Saving Invoice in Database" << endl;
    }
};

class EmailService{
    void sendEmailNotification() {
        cout << "Sending email notification for invoice" << endl;
    }
};

class Invoice{
private:
    double amount;
public:
    Invoice(double amount) {
        this->amount = amount;
    }
    void generateInvoice() {
        cout << "Invoice generated and printed for amount " << amount << endl;
    }
};