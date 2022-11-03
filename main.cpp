#include "BankDatabase.h"

#include <iostream>

int main() {
  const char *db_filename{"accounts.db"};
  BankDatabase db{db_filename};

  db.AccountCreate(4003002, 1, "chenyuhang", "qweasd", 300);

  std::cout << "n accounts: " << db.AccountQuery() << std::endl;

  std::cout << "balance for 4003002: " << db.AccountBalance(4003002)
            << std::endl;

  std::cout << "deposit 300 for 4003002: " << std::endl;
  db.MoneyDeposit(4003002, 300);

  std::cout << "balance for 4003002: " << db.AccountBalance(4003002)
            << std::endl;

  std::cout << "withdraw 350 for 4003002: " << std::endl;
  db.MoneyWithdraw(4003002, 350);

  std::cout << "balance for 4003002: " << db.AccountBalance(4003002)
            << std::endl;

  std::cout << "quiting" << std::endl;
  db.Quit();

  //   BankDatabase db2{db_filename};
  //   std::cout << db.AccountQuery() << std::endl;
  return 0;
}