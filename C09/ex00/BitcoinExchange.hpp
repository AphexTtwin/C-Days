#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>

class BitcoinExchange
{
private:
	std::map<std::string, double> _database;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();

	void loadDatabase();
	void processInputFile(const std::string &filename);

};

#endif