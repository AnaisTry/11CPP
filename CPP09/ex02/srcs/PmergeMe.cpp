/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:12:59 by angassin          #+#    #+#             */
/*   Updated: 2024/11/20 22:35:48 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		nbVector_ = other.nbVector_;
		nbDeque_ = other.nbDeque_;
	}
	return *this;
}

std::vector<int>& PmergeMe::getNbVector()
{
	return nbVector_;
}

std::deque<int>& PmergeMe::getNbDeque()
{
	return nbDeque_;
}

void PmergeMe::sortVector(std::vector<int>& numbers)
{
	mergeInsertionSort(numbers);
}

void PmergeMe::sortDeque(std::deque<int>& numbers)
{
	mergeInsertionSort(numbers);
}
