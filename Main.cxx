#include <iostream>

#include "ATM.hxx"
#include "BaseDisplay.hxx"
#include "Bank.hxx"
#include "Account.hxx"

int main()
{
    Bank * psBank = new Bank();
    BaseDisplay * psDisplay = new BaseDisplay();
    ATM * psATM = new ATM(psBank, psDisplay);

    Account * psAccount = psBank->addAccount();
    psAccount->setPassword("qwerty");

    psATM->viewAccount(psAccount->getAccountNumber(), psAccount->getPassword());
    psATM->fillUserRequest(ATM::REQUEST_BALANCE, 0);
    psATM->fillUserRequest(ATM::REQUEST_DEPOSIT, 100);
    psATM->fillUserRequest(ATM::REQUEST_WITHDRAW, 70);

    delete psATM;
    delete psDisplay;
    delete psBank;

    return 0;
}