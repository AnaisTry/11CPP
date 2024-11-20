/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:12:59 by angassin          #+#    #+#             */
/*   Updated: 2024/11/20 18:16:27 by angassin         ###   ########.fr       */
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

const std::vector<int>& PmergeMe::getNbVector() const
{
	return nbVector_;
}

const std::deque<int>& PmergeMe::getNbDeque() const
{
	return nbDeque_;
}

void PmergeMe::sortVector()
{
	mergeInsertionSort(nbVector_);
}

void PmergeMe::sortDeque()
{
	std::mergeInsertionSort(nbDeque_);
}
