/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:12:59 by angassin          #+#    #+#             */
/*   Updated: 2024/11/20 17:44:58 by angassin         ###   ########.fr       */
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
	std::sort(nbVector_.begin(), nbVector_.end());
}

void PmergeMe::sortDeque()
{
	std::sort(nbDeque_.begin(), nbDeque_.end());
}

