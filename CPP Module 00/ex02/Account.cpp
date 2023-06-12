#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account ( int initial_deposit)
{
	_accountIndex = _nbAccounts;
	++_nbAccounts;
	_amount = initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:"
	<< _amount << ";created" << std::endl;
}
void Account::displayAccountsInfos()
{
	// std::cout << "index:" << _accountIndex << ';' << "amount:"
	// << _amount << ';' << "deposits:" << Account::getTotalAmount() << std::endl;
}

bool Account::makeWithdrawal(int)
{
	return(1);
}

int	getNbDeposits( void )
{
	int nb;
	for (i = 0; i < 8; i++)
		nb = 
	return
}
Account::~Account()
{
	std::cout << "index:" << _accountIndex << ";amount:"
	<< _amount << ";closed" << std::endl;
}
void Account::makeDeposit(int dep)
{
	std::cout << "index:" << _accountIndex << ";p_amount:"
	<< _amount << ";deposit:" << dep << ";amount:" << _amount + dep
	<< ";nb_deposits:" << getNbDeposits() << std::endl;
	_amount += dep;
}
void Account::displayStatus() const{}