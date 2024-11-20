/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:52:19 by angassin          #+#    #+#             */
/*   Updated: 2024/11/20 20:03:30 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char* argv[])
{
	try
	{
		PmergeMe	pmergeMe;

		double	vectorParsingTime = pmergeMe.measureParseTime(argc, argv,
			pmergeMe.getNbVector(), &PmergeMe::parseInput<std::vector<int> >);
		
		double dequeParsingTime = pmergeMe.measureParseTime(argc, argv,
			pmergeMe.getNbDeque(), &PmergeMe::parseInput<std::deque<int> >);

		std::cout << "Before: ";
		pmergeMe.printContainer(pmergeMe.getNbVector());

		double vectorTime = pmergeMe.measureSortTime(pmergeMe.getNbVector(),
			&PmergeMe::sortVector);
		double dequeTime = pmergeMe.measureSortTime(pmergeMe.getNbDeque(),
			&PmergeMe::sortDeque);

		std::cout << "After: ";
		pmergeMe.printContainer(pmergeMe.getNbVector());

		pmergeMe.printResult(pmergeMe.getNbVector(), "vector", vectorParsingTime + vectorTime);
		pmergeMe.printResult(pmergeMe.getNbDeque(), "deque", dequeParsingTime + dequeTime);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}