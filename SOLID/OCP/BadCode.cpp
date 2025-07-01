#include<bits/stdc++.h>
using namespace std;

class PaymentProcessor {
public:
    void processPayment(string paymentMethod, double amount) {
        if(paymentMethod == "CreditCard") {
            //business logic
            cout << "Making payment via Credit Card: " << amount << endl;
        } else if(paymentMethod == "DebitCard") {
            //business logic
            cout << "Making payment via Debit Card: " << amount << endl;            
        } else if(paymentMethod == "Paypal") {
            cout << "Making payment via Paypal: " << amount << endl;
        } else {
            cout << "Unsupported payment method " << paymentMethod << endl;
        }
    }
};

int main() 
{

}