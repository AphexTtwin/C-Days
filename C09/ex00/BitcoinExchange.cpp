#include "BitcoinExchange.hpp"
#include <iomanip>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
    this->_database = src._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
    {
        this->_database = src._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

static std::pair<std::string, std::string> splitAndTrim(const std::string& line, char dl)
{
    std::string::size_type pos = line.find(dl);

    if (pos == std::string::npos)
        return std::make_pair("", "");

    std::string left = line.substr(0, pos);
    std::string right = line.substr(pos + 1);

    return std::make_pair(trim(left), trim(right));
}

static std::pair<std::string, double> splitKeyValue(std::string& line, char dl)
{
    std::string::size_type pos = line.find(dl);

    if (pos == std::string::npos)
        return std::make_pair("", 0.0);

    std::string key = line.substr(0, pos);
    std::string valuestr = line.substr(pos + 1);
    key = trim(key);
    valuestr = trim(valuestr);

    double value = std::strtod(valuestr.c_str(), NULL);
    return std::make_pair(key, value);
}

void BitcoinExchange::loadDatabase()
{
    std::string filename = "data.csv";
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::pair<std::string, double> p = splitKeyValue(line, ',');
        if (!p.first.empty())
            _database[p.first] = p.second;
    }
}

static bool isValidDate(const std::string& date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int    year = std::atoi(date.substr(0, 4).c_str());
    int    month = std::atoi(date.substr(5, 2).c_str());
    int    day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    int    daysInMonth[] = {
        31,28,31,30,31,30,
        31,31,30,31,30,31
    };

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

static bool isValidValue(const std::string& valueStr, double& value)
{
    std::stringstream    ss(valueStr);
    char    extra;

    if (!(ss >> value))
    {
        std::cerr << "Error: invalid value => " << valueStr << std::endl;
        return false;
    }

    if (ss >> extra)
    {
        std::cerr << "Error: invalid value => " << valueStr << std::endl;
        return false;
    }

    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

void BitcoinExchange::processInputFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        exit(1);
    }

    std::string line;
    if (!std::getline(file, line))
    {
        std::cout << "The file is completely empty!\n";
    }
	
    while (std::getline(file, line))
    {
        std::pair<std::string, std::string> parts = splitAndTrim(line, '|');



        std::string date = parts.first;
        std::string valueStr = parts.second;

        if (date.empty() && valueStr.empty())
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value;

        if (!isValidValue(valueStr, value))
            continue;

        std::map<std::string, double>::iterator it = _database.find(date);
        if (it == _database.end())
        {
            it = _database.lower_bound(date);
            if (it == _database.begin())
            {
                std::cout << "Error: no data available for date " << date << std::endl;
                continue;
            }
            --it;
        }

        double result = value * it->second;
        std::cout << date << " => " << std::setprecision(2) << value
                  << " = " << result << std::endl;
    }
}
