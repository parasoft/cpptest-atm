#include "Account.hxx"

double Account::deposit(double amount)
{
    myBalance += amount;
    return (getBalance());
}


double Account::debit(double amount)
{
    myBalance -= amount;
    return (getBalance());
}
void foo(int accountNumber, string password)
{
}
void bar(int accountNumber, string password)
{
}
void goo(int accountNumber, string password)
{
}