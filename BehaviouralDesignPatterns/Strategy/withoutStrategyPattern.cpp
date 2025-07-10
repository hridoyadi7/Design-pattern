#include<bits/stdc++.h>
using namespace std;

class PaymentService {
public:
    void processPayment(string paymentMethod) {
        if(paymentMethod == "CreditCard") {
            cout << "Making payment via credit card" << endl;
        } else if(paymentMethod == "DebitCard") {
            cout << "Making payment via debit card" << endl;
        } else if(paymentMethod == "UPI") {
            cout << "Making payment via UPI" << endl;
        } else {
            cout << "Unsupported payment method" << endl;
        }

    }
};

int main() 
{
    PaymentService paymentService;
    paymentService.processPayment("DebitCard");
    paymentService.processPayment("CreditCard");
    paymentService.processPayment("UPI");
    return 0;
}