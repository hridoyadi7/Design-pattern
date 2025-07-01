#include<bits/stdc++.h>
using namespace std;

// class CreditCard{
// private:
//     string cardNo;
//     string userName;
// public:
//     CreditCard(string cardNo, string name) {
//         this->cardNo = cardNo;
//         this->userName = name;
//     }
//     string getCardNo() {
//         return this->cardNo;
//     }
//     string getUserName() {
//         return this->userName;
//     }
// };

// class Card{
// private:
//     string cardNo;
//     string userName;
// public:
//     Card(string cardNo, string name) {
//         this->cardNo = cardNo;
//         this->userName = name;
//     }
//     string getCardNo() {
//         return this->cardNo;
//     }
//     string getUserName() {
//         return this->userName;
//     }

//     void pay() {
//         //we don't know how to implement this
//     }
// };

// class Card{
// private:
//     string cardNo;
//     string userName;
// public:
//     Card(string cardNo, string name) {
//         this->cardNo = cardNo;
//         this->userName = name;
//     }
//     string getCardNo() {
//         return this->cardNo;
//     }
//     string getUserName() {
//         return this->userName;
//     }

//     virtual void pay() = 0;//pure virtual function and make this class abstract
// };

class PaymentMethod{
public:
    virtual void pay() = 0;//pure virtual function and make this class abstract
    // Always include a virtual destructor in interfaces
    virtual ~PaymentMethod() {}
};


class Card : public PaymentMethod{
// private:
protected:
    string cardNo;
    string userName;
public:
    Card(string cardNo, string name) {
        this->cardNo = cardNo;
        this->userName = name;
    }
    string getCardNo() {
        return this->cardNo;
    }
    string getUserName() {
        return this->userName;
    }
};

class CreditCard: public Card{
public:
    CreditCard(string cardNo, string name) : Card(cardNo, name) {
        //same as calling super() in Java
    }
    void pay() {
        cout << "Making payment via Credit Card with cardNo:" << cardNo << endl;
    }
};

class DebitCard: public Card{
public:
    DebitCard(string cardNo, string name) : Card(cardNo, name) {
        //same as calling super() in Java
    }
    void pay() {
        cout << "Making payment via Debit Card." << endl;
    }
};

class UPI: public PaymentMethod{
private:
    string upiId;
public:
    UPI(string upiId) {
        this->upiId = upiId;
    }
    void pay() {
        cout << "Making payment via UPI with upiId:" << upiId << endl;
    }  
};

class Wallet: public PaymentMethod{
private:
    string walletId;
public:
    Wallet(string wId) {
        this->walletId = wId;
    }
    void pay() {
        cout << "Making payment via wallet with walletId:" << walletId << endl;
    }
};

class PaymentService{
private:
    unordered_map<string, shared_ptr<PaymentMethod>> paymentMethods;
public:
    PaymentService() {

    }
    void addPaymentMethod(string name, shared_ptr<PaymentMethod> pm) {
        paymentMethods[name] = pm;
    }

    void makePayment(string name) {
        if (paymentMethods.count(name)) {
            paymentMethods[name]->pay();  // Correct: call via smart pointer
        }
    }
};

int main(){
    PaymentService ps;
    ps.addPaymentMethod("SouravDebit", make_shared<DebitCard>("1234", "Sourav Adhikari"));
    ps.addPaymentMethod("SouravCredit", make_shared<CreditCard>("5678", "Sourav Adhikari"));
    ps.addPaymentMethod("SouravUPI", make_shared<UPI>("SouravUPI123"));
    ps.addPaymentMethod("SouravWallet", make_shared<Wallet>("SouravWallet456"));
    ps.makePayment("SouravUPI");
    ps.makePayment("SouravDebit");
    ps.makePayment("SouravCredit");
    ps.makePayment("SouravWallet");
    return 0;
}