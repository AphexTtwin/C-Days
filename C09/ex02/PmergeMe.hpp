#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <stdexcept>

class PmergeMe
{
private:

    std::vector<int> _vec;
    std::deque<int>  _deq;

    std::vector<std::pair<int, int> > createPairs(const std::vector<int> &vec);
    void sortPairs(std::vector<std::pair<int, int> > &pairs);
    std::vector<int> ExtractWinners(std::vector<std::pair<int, int> > &pairs);
    std::vector<int> ExtractLosers(std::vector<std::pair<int, int> > &pairs);
    std::vector<std::pair<int, int> > reorderPairs(const std::vector<int> &winners, const std::vector<std::pair<int, int> > &pairs);
    std::vector<int> fordJohnsonVector(std::vector<int> &arr);
    void insertPendingWithJacobsthal(std::vector<int>& mainChain, std::vector<int>& pending, std::vector<size_t>& links);

    std::deque<std::pair<int, int> > createPairsDeque(const std::deque<int> &deq);
    void sortPairsDeque(std::deque<std::pair<int, int> > &pairs);
    std::deque<int> ExtractWinnersDeque(std::deque<std::pair<int, int> > &pairs);
    std::deque<int> ExtractLosersDeque(std::deque<std::pair<int, int> > &pairs);
    std::deque<std::pair<int, int> > reorderPairsDeque(const std::deque<int> &winners, const std::deque<std::pair<int, int> > &pairs);
    std::deque<int> fordJohnsonDeque(std::deque<int> &arr);
    void insertPendingWithJacobsthalDeque(std::deque<int>& mainChain, std::deque<int>& pending, std::deque<size_t>& links);

    std::vector<size_t> generateJacobsthalOrder(size_t pendingSize);

public:

    PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);
    ~PmergeMe();

    void parseInput(char **av);
    void process();
    void printBefore() const;
    void printAfter() const;
};

#endif