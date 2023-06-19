#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account ( int initial_deposit)
{
	_displayTimestamp();
	_nbDeposits = _totalNbDeposits;
	_nbWithdrawals = _totalNbWithdrawals;
	_accountIndex = _nbAccounts;
	++_nbAccounts;
	_amount = initial_deposit;
	_totalAmount += _amount;
	std::cout << "index:" << _accountIndex << ";amount:"
	<< _amount << ";created" << std::endl;
}

int	Account::getNbWithdrawals()
{
	return(_totalNbWithdrawals);
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:"; 
	if (withdrawal > _amount)	
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount - withdrawal
	<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return(1);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:"
	<< getTotalAmount() << ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
	<< _amount << ";closed" << std::endl;
}
void Account::makeDeposit(int dep)
{
	_displayTimestamp();
	_totalNbDeposits++;
	_nbDeposits++;
	_totalAmount += dep;
	std::cout << "index:" << _accountIndex << ";p_amount:"
	<< _amount << ";deposit:" << dep << ";amount:" << _amount + dep
	<< ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += dep;
}
void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
	<< _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t seconds = time(NULL);
	tm*	time = std::localtime(&seconds);
	std::cout << '[' << time->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << time->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << time->tm_mday << '_';
	std::cout << std::setw(2) << std::setfill('0') << time->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << time->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << time->tm_sec << "] ";
}