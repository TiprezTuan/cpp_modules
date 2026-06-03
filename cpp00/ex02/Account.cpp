/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:06:50 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/03 17:03:23 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include "Account.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
Account::Account()
{
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += _amount;

	std::cout	<< "[";
	_displayTimestamp();
	std::cout	<< "] ";
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created"
				<< std::endl;

} 

Account::~Account(void)
{
	std::cout	<< "[";
	_displayTimestamp();
	std::cout	<< "] ";
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed"
				<< std::endl;
	_nbAccounts--;
}

/************************************/
/*			Getters / Setters		*/
/************************************/
int	Account::getNbAccounts(void)	{return _nbAccounts;}
int	Account::getTotalAmount(void)	{return _totalAmount;}
int Account::getNbDeposits(void)	{return _totalNbDeposits;}
int	Account::getNbWithdrawals(void)	{return _totalNbWithdrawals;}

/************************************/
/*				Methodes			*/
/************************************/
void	Account::_displayTimestamp(void) 
{
	std::cout << std::time(NULL);
}

void	Account::displayAccountsInfos(void)
{
	std::cout	<< "[";
	_displayTimestamp();
	std::cout	<< "] ";
	std::cout	<< "accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_totalNbDeposits++;
	_totalAmount += deposit;
	
	_nbDeposits++;
	int	p_amount = _amount;
	_amount += deposit;

	std::cout	<< "[";
	_displayTimestamp();
	std::cout	<< "] ";
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:1"
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_amount >= withdrawal)
	{
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
	
		_nbWithdrawals++;
		_amount += withdrawal;
		return (true);
	}
	return (false);
}

int	Account::checkAmount(void) const {return _amount;}

void	Account::displayStatus(void) const
{
	std::cout	<< "[";
	_displayTimestamp();
	std::cout	<< "] ";
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawal:" << _nbWithdrawals
				<< std::endl;
}