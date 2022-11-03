#include <fstream>
#include <iostream>
#include <string>

class Account {
private:
public:
  int account_number; // primary key
  int account_id;
  std::string account_holder_name;
  std::string account_password;
  int balance;

  Account(int account_number, int account_id, std::string account_holder_name,
          std::string account_password, int balance)
      : account_number{account_number}, account_id{account_id},
        account_holder_name{account_holder_name},
        account_password{account_password}, balance{balance} {
    // member initialization, see
    // https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
    std::cout << "Account created:" << *this << std::endl;
  }

  friend std::ofstream &operator<<(std::ofstream &fs, const Account &acc);
  friend std::ostream &operator<<(std::ostream &out, const Account &acc);
  void deposit(int amount);
  void withdraw(int amount);

  ~Account() {}
};