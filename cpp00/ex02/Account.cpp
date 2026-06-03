/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:06:50 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/03 18:07:46 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include "Account.hpp"

/************************************/
/*			Static Variables		*/
/************************************/
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/************************************/
/*		Special Member Functions	*/
/************************************/
Account::Account(void)
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
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_amount >= withdrawal)
	{
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
	
		_nbWithdrawals++;
		int	p_amount = _amount;
		_amount -= withdrawal;
		std::cout	<< "index:" << _accountIndex
					<< ";p_amount:" << p_amount
					<< ";withdrawal:" << withdrawal
					<< ";amount:" << _amount
					<< ";nb_withdrawals:" << _nbWithdrawals
					<< std::endl;
		return (true);
	}
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:refused"
				<< std::endl;
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
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}