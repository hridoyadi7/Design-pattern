#include<bits/stdc++.h>
using namespace std;

class PaymentStrategy{
public:
    virtual void processPayment() = 0;
    virtual ~PaymentStrategy() {}
};

class CreditCardPayment : public PaymentStrategy {
public:
    void processPayment() override {
        cout << "Making payment via Credit Card" << endl;
    }
};

class DebitCardPayment : public PaymentStrategy {
public:
    void processPayment() override {
        cout << "Making payment via Debit Card" << endl;
    }
};

class PaymentService {
private:
    shared_ptr<PaymentStrategy> paymentStrategy;
public:
    void setPaymentStrategy(shared_ptr<PaymentStrategy> paymentStrategy) {
        this->paymentStrategy = paymentStrategy;
    }
    void pay() {
        paymentStrategy->processPayment();//Runtime polymorphism
    }
};

int main()
{
    PaymentService paymentService;
    shared_ptr<PaymentStrategy> creditCard = make_shared<CreditCardPayment>();
    paymentService.setPaymentStrategy(creditCard);
    paymentService.pay();
    shared_ptr<PaymentStrategy> debitCard = make_shared<DebitCardPayment>();
    paymentService.setPaymentStrategy(debitCard);
    paymentService.pay();
    return 0;
}