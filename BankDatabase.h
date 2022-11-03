#include "Account.h"
#include <vector>

class BankDatabase {
  /**
   * A database holding on to accounts
   */
private:
  std::vector<Account> accounts;
  std::string db_filename;

public:
  BankDatabase(const char *db_filename);

  void AccountCreate(int account_number, int account_id,
                     std::string account_holder_name,
                     std::string account_password, int balance);

  void AccountDelete(int account_number);

  int AccountQuery();

  int AccountBalance(int account_number);

  void MoneyDeposit(int account_number, int amount);

  void MoneyWithdraw(int account_number, int amount);

  void Quit();

  ~BankDatabase() {}
};