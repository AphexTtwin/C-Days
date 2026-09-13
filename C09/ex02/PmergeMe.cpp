#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    _vec = src._vec;
    _deq = src._deq;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        _vec = src._vec;
        _deq = src._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::parseInput(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        std::string arg(av[i]);

        for (size_t j = 0; j < arg.size(); j++)
        {
            if (!std::isdigit(arg[j]))
                throw std::runtime_error("Error: invalid number");
        }

        long lng = std::atol(arg.c_str());

        if (lng > 2147483647)
            throw std::runtime_error("Error: overflow");

        int num = std::atoi(arg.c_str());

        if (num < 0)
            throw std::runtime_error("Error: negative number");

        if (std::find(_vec.begin(), _vec.end(), num) != _vec.end())
            throw std::runtime_error("Error: duplicate number");

        _vec.push_back(num);
        _deq.push_back(num);
    }
}

std::vector<std::pair<int, int> > PmergeMe::createPairs(const std::vector<int> &vec)
{
    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
    return pairs;
}

void PmergeMe::sortPairs(std::vector<std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

std::vector<int> PmergeMe::ExtractWinners(std::vector<std::pair<int, int> > &pairs)
{
    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); i++)
        winners.push_back(pairs[i].first);
    return winners;
}

std::vector<int> PmergeMe::ExtractLosers(std::vector<std::pair<int, int> > &pairs)
{
    std::vector<int> losers;
    for (size_t i = 0; i < pairs.size(); i++)
        losers.push_back(pairs[i].second);
    return losers;
}

std::vector<std::pair<int, int> > PmergeMe::reorderPairs(const std::vector<int> &winners, const std::vector<std::pair<int, int> > &pairs)
{
    std::vector<std::pair<int, int> > orderd;

    for (size_t i = 0; i < winners.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (winners[i] == pairs[j].first)
            {
                orderd.push_back(pairs[j]);
                break;
            }
        }
    }
    return orderd;
}

std::vector<size_t> PmergeMe::generateJacobsthalOrder(size_t pendingSize)
{
    std::vector<size_t> order;
    if (pendingSize == 0)
        return order;

    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    if (pendingSize > 1)
        jacobsthal.push_back(1);
    if (pendingSize > 2)
        jacobsthal.push_back(1);

    for (size_t i = 3; jacobsthal.back() < pendingSize; ++i)
    {
        size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        jacobsthal.push_back(next);
    }

    std::vector<bool> used(pendingSize, false);

    for (size_t i = 1; i < jacobsthal.size(); ++i)
    {
        if (jacobsthal[i] < pendingSize && !used[jacobsthal[i]])
        {
            order.push_back(jacobsthal[i]);
            used[jacobsthal[i]] = true;
        }
    }

    for (size_t i = 0; i < pendingSize; ++i)
    {
        if (!used[i])
        {
            order.push_back(i);
            used[i] = true;
        }
    }
    return order;
}

std::vector<int> createMainAndPandind(std::vector<std::pair<int, int> > pairs, int flag)
{
    std::vector<int> mainchain;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (flag == 1)
            mainchain.push_back(pairs[i].first);
        else
            mainchain.push_back(pairs[i].second);
    }
    return mainchain;
}

void PmergeMe::insertPendingWithJacobsthal(std::vector<int>& mainChain, std::vector<int>& pending, std::vector<size_t>& links)
{
    std::vector<size_t> insertionOrder = generateJacobsthalOrder(pending.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        size_t idx = insertionOrder[i];

        size_t upperBound = links[idx];
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.begin() + upperBound + 1, pending[idx]);

        size_t insertPos = pos - mainChain.begin();
        mainChain.insert(pos, pending[idx]);

        for (size_t j = 0; j < links.size(); ++j)
        {
            if (links[j] >= insertPos)
            {
                links[j]++;
            }
        }
    }
}

std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return arr;
    int oddElement = -1337;
    bool hasOdd = false;
    std::vector<int> tempArr = arr;

    if (arr.size() % 2 != 0)
    {
        oddElement = arr.back();
        hasOdd = true;
        tempArr.pop_back();
    }

    std::vector<std::pair<int, int> > pairs = createPairs(tempArr);
    sortPairs(pairs);

    std::vector<int> winners = ExtractWinners(pairs);
    winners = fordJohnsonVector(winners);

    std::vector<std::pair<int, int> > orderedPairs;
    orderedPairs = reorderPairs(winners, pairs);

    std::vector<int> mainChain = createMainAndPandind(orderedPairs, 1);
    std::vector<int> pending = createMainAndPandind(orderedPairs, 2);

    std::vector<size_t> links;

    for (size_t i = 0; i < orderedPairs.size(); ++i)
    {
        int winner = orderedPairs[i].first;
        size_t pos = std::find(mainChain.begin(), mainChain.end(), winner) - mainChain.begin();
        links.push_back(pos);
    }

    insertPendingWithJacobsthal(mainChain, pending, links);
    arr = mainChain;

    if (hasOdd)
    {
        std::vector<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), oddElement);
        arr.insert(pos, oddElement);
    }

    return arr;
}

// DEQUE
std::deque<std::pair<int, int> > PmergeMe::createPairsDeque(const std::deque<int> &deq)
{
    std::deque<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
    }
    return pairs;
}

void PmergeMe::sortPairsDeque(std::deque<std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

std::deque<int> PmergeMe::ExtractWinnersDeque(std::deque<std::pair<int, int> > &pairs)
{
    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); i++)
        winners.push_back(pairs[i].first);
    return winners;
}

std::deque<int> PmergeMe::ExtractLosersDeque(std::deque<std::pair<int, int> > &pairs)
{
    std::deque<int> losers;
    for (size_t i = 0; i < pairs.size(); i++)
        losers.push_back(pairs[i].second);
    return losers;
}

std::deque<std::pair<int, int> > PmergeMe::reorderPairsDeque(const std::deque<int> &winners, const std::deque<std::pair<int, int> > &pairs)
{
    std::deque<std::pair<int, int> > orderd;

    for (size_t i = 0; i < winners.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (winners[i] == pairs[j].first)
            {
                orderd.push_back(pairs[j]);
                break;
            }
        }
    }
    return orderd;
}

std::deque<int> createMainAndPandindDeque(std::deque<std::pair<int, int> > pairs, int flag)
{
    std::deque<int> mainchain;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (flag == 1)
            mainchain.push_back(pairs[i].first);
        else
            mainchain.push_back(pairs[i].second);
    }
    return mainchain;
}

void PmergeMe::insertPendingWithJacobsthalDeque(std::deque<int>& mainChain, std::deque<int>& pending, std::deque<size_t>& links)
{
    std::vector<size_t> insertionOrder = generateJacobsthalOrder(pending.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        size_t idx = insertionOrder[i];

        size_t upperBound = links[idx];
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.begin() + upperBound + 1, pending[idx]);

        size_t insertPos = pos - mainChain.begin();
        mainChain.insert(pos, pending[idx]);

        for (size_t j = 0; j < links.size(); ++j)
        {
            if (links[j] >= insertPos)
            {
                links[j]++;
            }
        }
    }
}

std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int> &arr)
{
    if (arr.size() <= 1)
        return arr;
    int oddElement = -1337;
    bool hasOdd = false;
    std::deque<int> tempArr = arr;

    if (arr.size() % 2 != 0)
    {
        oddElement = arr.back();
        hasOdd = true;
        tempArr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs = createPairsDeque(tempArr);
    sortPairsDeque(pairs);

    std::deque<int> winners = ExtractWinnersDeque(pairs);
    winners = fordJohnsonDeque(winners);

    std::deque<std::pair<int, int> > orderedPairs;
    orderedPairs = reorderPairsDeque(winners, pairs);

    std::deque<int> mainChain = createMainAndPandindDeque(orderedPairs, 1);
    std::deque<int> pending = createMainAndPandindDeque(orderedPairs, 2);

    std::deque<size_t> links;

    for (size_t i = 0; i < orderedPairs.size(); ++i)
    {
        int winner = orderedPairs[i].first;
        size_t pos = std::find(mainChain.begin(), mainChain.end(), winner) - mainChain.begin();
        links.push_back(pos);
    }

    insertPendingWithJacobsthalDeque(mainChain, pending, links);
    arr = mainChain;

    if (hasOdd)
    {
        std::deque<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), oddElement);
        arr.insert(pos, oddElement);
    }

    return arr;
}

void PmergeMe::printBefore() const
{
    std::cout << "Before:  ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << "\n";
}

void PmergeMe::printAfter() const
{
    std::cout << "After:   ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << "\n";
}

void PmergeMe::process()
{
    printBefore();

    clock_t startVec = clock();
    std::vector<int> sortedVec = fordJohnsonVector(_vec);
    clock_t endVec = clock();
    double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

    clock_t startDeq = clock();
    std::deque<int> sortedDeq = fordJohnsonDeque(_deq);
    clock_t endDeq = clock();
    double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    _vec = sortedVec;
    _deq = sortedDeq;

    printAfter();

    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << deqTime << " us" << std::endl;
}