//
// Created by 易治行 on 2025/3/26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {

private:
    int id;
    string holder;
    int refund;

public:
    Account(int id, string holder, int refund=0): id(id), holder(holder), refund(refund){}

    int get_refund() {
        return this->refund;
    }

    int get_id () {
        return this->id;
    }


};


class ATM {
private:
    vector<Account*> accounts;

public:
    ATM(){}

    void open_account(string holder) {

    }

    Account* search_account(int id) {

        for (auto account : this->accounts) {
            if (account->get_id() == id)
                return account;
        }

        return nullptr;
    }

};