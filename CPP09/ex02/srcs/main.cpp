/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:52:19 by angassin          #+#    #+#             */
/*   Updated: 2024/11/20 17:50:42 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char* argv[])
{
	try
	{
		PmergeMe	pmergeMe;
		std::cout << "Before: " << std::endl;
		pmergeMe.printContainer(pmergeMe.getNbVector());
		
		double vectorTime = pmergeMe.measureSortTime(pmergeMe.getNbVector(), &PmergeMe::sortVector);
		double dequeTime = pmergeMe.measureSortTime(pmergeMe.getNbDeque(), &PmergeMe::sortDeque);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}