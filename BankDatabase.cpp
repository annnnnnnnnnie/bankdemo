#include "BankDatabase.h"

#include <algorithm>
#include <fstream>
#include <iostream>

BankDatabase::BankDatabase(const char *db_filename) {
  this->db_filename = db_filename;

  std::ifstream fs{db_filename};

  if (!fs) {
    std::cerr << "database file " << db_filename
              << "could not be opened for reading!\n";
    return;
  }

  while (fs) {
    int account_number; // primary key
    int account_id;
    std::string account_holder_name;
    std::string account_password;
    int balance;
    fs >> account_number >> account_id >> account_holder_name >>
        account_password >> balance;

    // load accoutns from database
    AccountCreate(account_number, account_id, account_holder_name,
                  account_password, balance);
  }

  return;
}

void BankDatabase::AccountCreate(int account_number, int account_id,
                                 std::string account_holder_name,
                                 std::string account_password, int balance) {
  std::cout << "Creating account " << account_number << " " << account_id << " "
            << account_holder_name << " " << account_password << " " << balance
            << std::endl;
  this->accounts.emplace_back(account_number, account_id, account_holder_name,
                              account_password, balance);
}

void BankDatabase::AccountDelete(int account_number) {
  auto acc = std::find_if(this->accounts.cbegin(), this->accounts.cend(),
                          [account_number](auto &account) {
                            return account.account_number == account_number;
                          });
  this->accounts.erase(acc);
}

int BankDatabase::AccountQuery() {
  /**
   * Returns how many accounts are there
   */
  return this->accounts.size();
}

int BankDatabase::AccountBalance(int account_number) {
  auto acc = std::find_if(this->accounts.cbegin(), this->accounts.cend(),
                          [account_number](auto &account) {
                            return account.account_number == account_number;
                          });
  return acc->balance;
}

void BankDatabase::MoneyDeposit(int account_number, int amount) {
  auto acc = std::find_if(this->accounts.begin(), this->accounts.end(),
                          [account_number](auto &account) {
                            return account.account_number == account_number;
                          });
  acc->deposit(amount);
}

void BankDatabase::MoneyWithdraw(int account_number, int amount) {
  auto acc = std::find_if(this->accounts.begin(), this->accounts.end(),
                          [account_number](auto &account) {
                            return account.account_number == account_number;
                          });
  acc->withdraw(amount);
}

void BankDatabase::Quit() {
  /**
   * Write back to database
   */
  std::ofstream fs{this->db_filename};

  std::for_each(this->accounts.cbegin(), this->accounts.cend(),
                [&fs](const auto account) {
                  fs << account;
                  std::cout << "saving.." << std::endl;
                  std::cout << account;
                });
}