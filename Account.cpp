#include "Account.h"

std::ofstream &operator<<(std::ofstream &ofs, const Account &acc) {
  ofs << acc.account_number << " " << acc.account_id << " "
      << acc.account_holder_name << " " << acc.account_password << " "
      << acc.balance << " " << std::endl;
  return ofs;
}

std::ostream &operator<<(std::ostream &out, const Account &acc) {
  out << acc.account_number << " " << acc.account_id << " "
      << acc.account_holder_name << " " << acc.account_password << " "
      << acc.balance << " " << std::endl;
  return out;
}

void Account::deposit(int amount) {
  /**
   * Assume always succeed
   */
  this->balance += amount;
}

void Account::withdraw(int amount) {
  /**
   * Assume always succeed
   */
  this->balance -= amount;
}