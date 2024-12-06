/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:12:59 by angassin          #+#    #+#             */
/*   Updated: 2024/12/06 14:22:43 by angassin         ###   ########.fr       */
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

std::vector<size_t> PmergeMe::generateJacobstahl(size_t maxSize) const
{
	std::vector<size_t> jacobstahl;
	jacobstahl.push_back(0);
	jacobstahl.push_back(1);
	size_t i = 2;
	while (jacobstahl.back() < maxSize)
	{
		jacobstahl.push_back(jacobstahl[i - 1] * 2 + 1);
		++i;
	}
	return jacobstahl;
}