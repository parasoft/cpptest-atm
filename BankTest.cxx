#include <gtest/gtest.h>

#include "Account.hxx"
#include "Bank.hxx"

// 
TEST(BankTest, TestGetAccount_getAccountValid) {
  Bank testBank;
  Account* newAccount = testBank.addAccount();
  newAccount->setPassword("passwd");

  Account* testAccountValid = testBank.getAccount(newAccount->getAccountNumber(), "passwd");

  EXPECT_EQ(testAccountValid, newAccount);
}

// 
TEST(BankTest, TestGetAccount_getAccountPasswordInvalid) {
  Bank testBank;
  Account* newAccount = testBank.addAccount();
  newAccount->setPassword("passwd");

  Account* testAccountValid = testBank.getAccount(newAccount->getAccountNumber(), "qwerty");

  EXPECT_EQ(testAccountValid, nullptr);
}

//
// TEST(BankTest, TestGetAccount_getAccountNumberInvalid) {
//   Bank testBank;
//   Account* newAccount = testBank.addAccount();
//   newAccount->setPassword("passwd");
//
//   Account* testAccountValid = testBank.getAccount(newAccount->getAccountNumber() + 1, "qwerty");
//
//   EXPECT_EQ(testAccountValid, nullptr);
// }
