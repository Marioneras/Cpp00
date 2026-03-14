/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthou <mberthou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 20:19:30 by mberthou          #+#    #+#             */
/*   Updated: 2026/03/14 23:48:31 by mberthou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() :
	_accountIndex(_nbAccounts),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)

{
	_nbAccounts++;
	_totalAmount += _amount;
	
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount << ";created" << std::endl;
}

Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)

{
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts() {
	return (_nbAccounts);
}

int	Account::getTotalAmount() {
	return (_totalAmount);
}

int	Account::getNbDeposits() {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals() {
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp() {
	const std::time_t now = std::time(0);
	static char buf[64];

	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", std::localtime(&now));
	std::cout	<< "[" << buf << "]";
}

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout	<< " accounts:" << _nbAccounts
				<< ";total:" << _totalNbDeposits
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_totalNbDeposits++;
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";p_amount:" << _amount - deposit
				<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_totalNbWithdrawals++;
	_nbWithdrawals++;

	if (_amount <= withdrawal) {
		_displayTimestamp();
		std::cerr	<< " index:" << _accountIndex
					<< ";p_amount:" << _amount + withdrawal
					<< ";withdrawal:refused"
					<< std::endl;
		return false;
	}
	_amount -= withdrawal;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";p_amount:" << _amount + withdrawal
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawal:" << _nbWithdrawals
				<< std::endl;
	return true;
}

int		Account::checkAmount() const {
	return (_amount);
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}
