/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:34:08 by angassin          #+#    #+#             */
/*   Updated: 2024/11/19 16:10:55 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP
# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <stdexcept>
# include <cstdlib> // atof
# include <ctime> // clock_t

class PmergeMe
{
	public:

		PmergeMe(int argc, char* argv[]);
		virtual ~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		void sortVector();
		void sortDeque();

		// The double is used to return the time taken to sort the container in decimal
		template <typename Container, typename SortFunction>
		double measureSortTime(Container& numbers, SortFunction sortFunction)
		{
			std::clock_t start = std::clock();
			// sortFunction(numbers);
			(this->*sortFunction)(numbers);
			std::clock_t end = std::clock();
			return static_cast<double>(end - start) / CLOCKS_PER_SEC;
		}

		template <typename Container>
		void	printContainer(Container& numbers)
		{
			for (typename Container::iterator it = numbers.begin(); it != numbers.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}

		template <typename Container>
		void	printResult(const Container& numbers, const std::string& containerName, double timeTaken)
		{
			std::cout << containerName << " sorted in " << timeTaken << " seconds" << " :" << std::endl;
			printContainer(numbers);
		}

	 private:

		std::vector<int> nbVector_;
		std::deque<int> nbDeque_;

		void parseInput(int argc, char* argv[]);

		template <typename Container>
		void	mergeInsertionSort(Container& numbers){}

};

#endif