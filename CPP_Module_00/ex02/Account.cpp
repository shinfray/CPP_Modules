/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:22:54 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/05 18:12:15by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <ctime>

#include <iostream>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
    : _accountIndex(getNbAccounts()), _amount(initial_deposit),
      _nbDeposits(0), _nbWithdrawals(0)
{
    ++_nbAccounts;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "created";
    std::cout << std::endl;
}

Account::~Account()
{
    --_nbAccounts;
    _totalAmount -= checkAmount();
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "closed";
    std::cout << std::endl;
}

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals();
    std::cout << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    const int   p_amount(checkAmount());
    _amount += deposit;
    ++_nbDeposits;
    _totalAmount += deposit;
    ++_totalNbDeposits;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << p_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "nb_deposits:" << _nbDeposits;
    std::cout << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    const int   p_amount = checkAmount();
    const bool  withdrawal_decision = (p_amount >= withdrawal);

    if (withdrawal_decision == true) {
        _amount -= withdrawal;
        ++_nbWithdrawals;
        _totalAmount -= withdrawal;
        ++_totalNbWithdrawals;
    }
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << p_amount << ";";
    if (withdrawal_decision == false) {
        std::cout << "withdrawal:refused";
    } else {
        std::cout << "withdrawal:" << withdrawal << ";";
        std::cout << "amount:" << checkAmount() << ";";
        std::cout << "nb_withdrawals:" << _nbWithdrawals;
    }
    std::cout << std::endl;
    return withdrawal_decision;
}

int Account::checkAmount() const
{
    return _amount;
}

void    Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
}

void    Account::_displayTimestamp()
{
    const std::time_t   time_since_epoch(std::time(NULL));
    const std::tm*      now(std::localtime(&time_since_epoch));
    char                formated_time[18] = "";

    std::strftime(formated_time, 18, "[%Y%m%d_%H%M%S]", now);
    std::cout << formated_time << " ";
}
