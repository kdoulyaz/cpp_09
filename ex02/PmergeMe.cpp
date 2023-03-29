/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:06:31 by kdoulyaz          #+#    #+#             */
/*   Updated: 2023/03/18 21:06:35 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av){

    std::deque<int> inputDeque;
    std::list<int> inputList;

    srand(time(NULL));
    for (int i = 1; i < ac; ++i)
    {
        int value = atoi(av[i]);
        if (value <= 0)
        {
            std::cerr << RED "Error: Invalid input value \"" << av[i] << "\". Only positive integers are allowed." NONE << std::endl;
			exit(1);
        }
        inputDeque.push_back(value);
        inputList.push_back(value);
    }
    std::cout << GREEN "Before: " NONE;
    display(inputDeque);

    clock_t start1 = clock();
    mergeInsertSortDeque(inputDeque);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

    clock_t start2 = clock();
    mergeInsertSortList(inputList);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

    std::cout << GREEN "After: " NONE;
    display(inputDeque);
    std::cout << YELLOW "Time to process a range of " CYANE << inputDeque.size() << YELLOW << " elements with std::deque container: " GREEN << time1 << " us" << std::endl;
    std::cout << YELLOW "Time to process a range of " CYANE << inputList.size() << YELLOW " elements with std::list container: " GREEN << time2 << " us" << std::endl;
}

PmergeMe::~PmergeMe(){
}

template <typename T>
void PmergeMe::display(const T& container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
    // Base case
    if (arr.size() <= 1) {
        return;
    }
    
    // Divide the deque into two halves
    int mid = arr.size() / 2;
    std::deque<int> left(arr.begin(), arr.begin() + mid);
    std::deque<int> right(arr.begin() + mid, arr.end());
    
    // Recursively sort the two halves
    mergeInsertSortDeque(left);
    mergeInsertSortDeque(right);
    
    // Merge the sorted halves
    std::deque<int>::iterator it1 = left.begin();
    std::deque<int>::iterator it2 = right.begin();
    std::deque<int> merged;
    while (it1 != left.end() && it2 != right.end()) {
        if (*it1 <= *it2) {
            merged.push_back(*it1);
            ++it1;
        } else {
            merged.push_back(*it2);
            ++it2;
        }
    }
    merged.insert(merged.end(), it1, left.end()); 
    merged.insert(merged.end(), it2, right.end());
    
    // Insertion sort the merged deque
    for (std::deque<int>::iterator it = merged.begin() + 1; it != merged.end(); ++it) {
        int temp = *it;
        std::deque<int>::iterator it2 = it;
        while (it2 != merged.begin() && *(it2-1) > temp) {
            *it2 = *(it2-1);
            --it2;
        }
        *it2 = temp;
    }
    
    // Copy the sorted elements back into the original deque
    std::copy(merged.begin(), merged.end(), arr.begin());
}

void PmergeMe::mergeInsertSortList(std::list<int>& arr)
{
    // Base case
    if (arr.size() <= 1) {
        return;
    }
    
    // Divide the list into two halves
    int mid = arr.size() / 2;
    std::list<int> left, right;
    std::list<int>::iterator it = arr.begin();
    for (int i = 0; i < mid; ++i) {
        left.push_back(*it);
        ++it;
    }
    while (it != arr.end()) {
        right.push_back(*it);
        ++it;
    }
    
    // Recursively sort the two halves
    mergeInsertSortList(left);
    mergeInsertSortList(right);
    
    // Merge the sorted halves
    std::list<int>::iterator it1 = left.begin();
    std::list<int>::iterator it2 = right.begin();
    std::list<int> merged;
    while (it1 != left.end() && it2 != right.end()) {
        if (*it1 <= *it2) {
            merged.push_back(*it1);
            ++it1;
        } else {
            merged.push_back(*it2);
            ++it2;
        }
    }
    merged.insert(merged.end(), it1, left.end());
    merged.insert(merged.end(), it2, right.end());
    
   // Insertion sort the merged list
for (std::list<int>::iterator it = std::next(merged.begin()); it != merged.end(); ++it) {
    int temp = *it;
    std::list<int>::iterator it2 = it;
    while (it2 != merged.begin() && *(std::prev(it2)) > temp) {
        *(std::next(it2)) = *(std::prev(it2));
        --it2;
    }
    *(std::next(it2)) = temp;
}
    // Copy the sorted elements back into the original list
    arr = merged;
}