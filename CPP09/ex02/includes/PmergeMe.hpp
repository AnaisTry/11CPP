/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:34:08 by angassin          #+#    #+#             */
/*   Updated: 2024/11/20 18:46:47 by angassin         ###   ########.fr       */
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

		PmergeMe();
		virtual ~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		const std::vector<int>& getNbVector() const;
		const std::deque<int>& getNbDeque() const;
		void sortVector();
		void sortDeque();

		template <typename Container>
		void parseInput(int argc, char* argv[], Container& container)
		{
			if (argc != 2)
				throw std::invalid_argument("Usage: ./PmergeMe [positive integers]");

			for (int i = 1; i < argc; ++i)
			{
				int	num;
				std::istringstream	iss(argv[i]);
				iss >> num;
				if(iss.fail() || num <= 0)
					throw std::invalid_argument("Invalid input: positive integers required");
				
				container.push_back(num);
			}
		}

		template <typename Container, typename ParseFunction>
		double measureParseTime(int argc, char* argv[], Container& container, ParseFunction parseFunction)
		{
			std::clock_t start = std::clock();
			(this->*parseFunction)(argc, argv, container);
			std::clock_t end = std::clock();
			return 1000.0 * (end - start) / CLOCKS_PER_SEC;
		}

		// The double is used to return the time taken to sort the container in decimal
		template <typename Container, typename SortFunction>
		double measureSortTime(Container& numbers, SortFunction sortFunction)
		{
			std::clock_t start = std::clock();
			// sortFunction(numbers);
			(this->*sortFunction)(numbers);
			std::clock_t end = std::clock();
			return 1000.0 * (end - start) / CLOCKS_PER_SEC;
		}

		template <typename Container>
		void	printContainer(Container& numbers)
		{
			for (typename Container::iterator it = numbers.begin(); it != numbers.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}

		template <typename Container>
		void	printResult(const Container& numbers, const std::string& containerName, double time) const
		{
			std::cout << "Time to process a range of " << numbers.size() <<
				"elements with std::" << containerName << ": " << time << " ms" << std::endl;
		}

	 private:

		std::vector<int> nbVector_;
		std::deque<int> nbDeque_;

		void parseInput(int argc, char* argv[]);

		template <typename Container>
		void	mergeInsertionSort(Container& numbers){}

};

#endif