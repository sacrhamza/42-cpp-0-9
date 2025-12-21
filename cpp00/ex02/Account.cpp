#include "Account.hpp"
#include <iostream>

int Account::getNbAccounts(void)
{
  return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
  return (_totalAmount);
}

int Account::getNbDeposits(void)
{
  return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
  return (_totalNbWithdrawals);
}

int Account::checkAmount(void) const
{
  return (_amount);
}

void	Account::displayStatus(void) const
{
  std::cout << "index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";deposits:" << _nbDeposits;
  std::cout << ";withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::displayAccountsInfos(void)
{
  std::cout << "accounts:" << _nbAccounts;
  std::cout << ";total:" << _totalAmount;
  std::cout << ";deposits:" << _totalNbDeposits;
  std::cout << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

void	Account::makeDeposit(int deposit)
{
  std::cout << "index:" << _accountIndex;
  std::cout << ";p_amount:" << _amount;

  _amount += deposit;
  _nbDeposits++;

  _totalAmount += deposit;
  _totalNbDeposits++;

  std::cout << ";deposit:" << deposit;
  std::cout << ";amount:" << _amount;
  std::cout << ";nb_deposits:" << _nbDeposits << "\n";
}


bool	Account::makeWithdrawal(int withdrawal)
{
  std::cout << "index:" << _accountIndex;
  std::cout << ";p_amount:" << _amount;
  std::cout << ";withdrawal:";
  // public
  if (_amount < withdrawal)
  {
    std::cout << "refused\n";
    return (false);
  }
  _amount -= withdrawal;
  _nbWithdrawals++;

  //private
  _totalNbWithdrawals++;
  _totalAmount -= withdrawal;

  std::cout << withdrawal; 
  std::cout << ";amount:" << _amount;
  std::cout << ";nb_withdrawals:" << _nbWithdrawals << "\n";
  return (true);
}

Account::Account(int initial_deposit)
{
  // vars
  _amount = initial_deposit;
  _nbDeposits = 1;

  // class variables
  _nbAccounts++;
  _totalAmount += _amount;

  _accountIndex = _nbAccounts - 1;
  _nbDeposits = 0;
  std::cout << "index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";created" << "\n";
}


Account::Account()
{
  _accountIndex++;
}

Account::~Account()
{
  std::cout << "index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";closed" << "\n";
// index:0;amount:47;closed
}


void	_displayTimestamp( void )
{
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
