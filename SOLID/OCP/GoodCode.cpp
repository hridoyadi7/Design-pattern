#include<bits/stdc++.h>
using namespace std;

class PaymentMethod{
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCard: public PaymentMethod{
public:
    void pay(double amount) {
        cout << "Making payment via Credit Card: " << amount << endl;
    }
};

class DebitCard: public PaymentMethod{
public:
    void pay(double amount) {
        cout << "Making payment via Debit Card: " << amount << endl;
    }
};

class Paypal: public PaymentMethod{
public:
    void pay(double amount) {
        cout << "Making payment via Paypal: " << amount << endl;
    }
};

class UPI:public PaymentMethod{
public:
    void pay(double amount) {
        cout << "Making payment via UPI: " << amount << endl;
    }
};

class PaymentProcessor{
public:
    void processPayment(shared_ptr<PaymentMethod> paymentMethod, double amount) {
        paymentMethod->pay(amount);//Example of runtime polymorphism: whatever object is passed will call its pay()
    }   
};

int main() 
{
    shared_ptr<PaymentMethod> paypal = make_shared<Paypal>();
    PaymentProcessor paymentProcessor;
    paymentProcessor.processPayment(paypal, 10);
    shared_ptr<PaymentMethod> debitCard = make_shared<DebitCard>();
    paymentProcessor.processPayment(debitCard, 100);
    shared_ptr<PaymentMethod> upi = make_shared<UPI>();
    paymentProcessor.processPayment(upi, 1000);
    return 0;
}