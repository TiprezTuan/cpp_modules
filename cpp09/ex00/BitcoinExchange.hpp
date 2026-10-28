/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:20:23 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/28 20:01:32 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange
{
	public:
		// Special Member Functions
		BitcoinExchange(const std::string& bitcoinRates_path);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange(void);

		// Operator
		BitcoinExchange& operator=(const BitcoinExchange& other);

		// Member Functions
		void	displayBitcoinValues(const std::string& inputData_path)	const;

	private:
		// Special Member Functions
		BitcoinExchange(void);

		// Attributes
		std::map<std::string, double>	_bitcoinRates;
};

#endif /* BITCOIN_EXCHANGE_HPP */