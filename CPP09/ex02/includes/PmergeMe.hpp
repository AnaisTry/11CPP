/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:34:08 by angassin          #+#    #+#             */
/*   Updated: 2024/12/06 16:14:06 by angassin         ###   ########.fr       */
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
# include <algorithm> // swap, lower_bound

class PmergeMe
{
	public:

		PmergeMe();
		virtual ~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		std::vector<int>& getNbVector();
		std::deque<int>& getNbDeque();
		void sortVector(std::vector<int>& numbers);
		void sortDeque(std::deque<int>& numbers);

		template <typename Container>
		void parseInput(int argc, char* argv[], Container& container)
		{
			if (argc < 2)
				throw std::invalid_argument("Usage: ./PmergeMe [positive integers]");

			for (int i = 1; i < argc; ++i)
			{
				std::string	arg(argv[i]);
				if (arg.find(' ') != std::string::npos)
					throw std::invalid_argument("Invalid input: no spaces allowed");
					
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
		void	printContainer(Container& numbers) const
		{
			for (typename Container::iterator it = numbers.begin(); it != numbers.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}

		template <typename Container>
		void	printResult(const Container& numbers, const std::string& containerName, double time) const
		{
			std::cout << "Time to process a range of " << numbers.size() <<

				" element(s) with std::" << containerName << ": " << time << " ms" << std::endl;
		}

	 private:

		std::vector<int> nbVector_;
		std::deque<int> nbDeque_;

		std::vector<size_t> generateJacobstahl(size_t maxSize) const;

		
		// Ford-Johnson merge-insertion sort algorithm
		template <typename Container>
		void	mergeInsertionSort(Container& numbers)
		{
			Container	main;
			Container	pending;
			
			if (numbers.size() > 1)
			{
				sortPairs(numbers);
				mergeSortPairs(numbers);
				createChains(numbers, main, pending);
				insertionSort(main, pending);

				numbers.clear();
				numbers.insert(numbers.end(), main.begin(), main.end());
			}
		}

		// Sorts the pairs leaving the odd number if there is one
		template <typename Container>
		void	sortPairs(Container& numbers)
		{
			if (numbers.size() < 2)
				return;
			typename Container::iterator it = numbers.begin();
			while (it != numbers.end() && it + 1 != numbers.end())
			{
				if (*it > *(it + 1))
					std::swap(*it, *(it + 1));
				it += 2;
			}
		}

		/* 
			Merges the pairs based on the value of the last number of the pair,
			with a merge sort algorithm
		*/ 
		template <typename Container>
		void	mergeSortPairs(Container& numbers)
		{
			if (numbers.size() < 3)
				return;
			bool is_odd = numbers.size() % 2 == 1;
			mergeSort(numbers, numbers.begin(), numbers.end() - (is_odd));
		}
		
		/*
			Recursively divides the container in halves until the size is 1
			Then merges the halves in a sorted manner
		*/
		template <typename Container, typename Iterator>
		void	mergeSort(Container& numbers, Iterator begin, Iterator end)
		{
			size_t nb_items = distance(begin, end);
			if (nb_items > 3)
			{
				size_t	half = nb_items / 2;
				bool	is_odd = half % 2 == 1;
				Iterator	mid = next(begin, half + is_odd);
				mergeSort(numbers, begin, mid);
				mergeSort(numbers, mid, end);
				mergeHalves(numbers, begin, mid, end);
			}
		}

		/*
			Merges the two subarrays of pairs
			1. creates two subarrays from the original array
			2. Merge the two subarrays while comparing the last number of the pairs,
			cursor is used to place the sorted pairs in the container
			3. If there are any remaining pairs in the subarrays, they are added to the container 
		*/
		template <typename Container, typename Iterator>
		void mergeHalves(Container& numbers, Iterator begin, Iterator mid, Iterator end)
		{
			(void) numbers;
			Container leftHalf(begin, mid);
			Container rightHalf(mid, end);

			Iterator cursor = begin;
			Iterator leftIt = leftHalf.begin();
			Iterator rightIt = rightHalf.begin();

			while (leftIt != leftHalf.end() && rightIt != rightHalf.end())
			{
				if (*(leftIt + 1) < *(rightIt + 1))
				{
					*cursor = *leftIt;
					++leftIt;
					++cursor;
					*cursor = *leftIt;
					++leftIt;
				}
				else
				{
					*cursor = *rightIt;
					++rightIt;
					++cursor;
					*cursor = *rightIt;
					++rightIt;
				}
				++cursor;
			}

			while (leftIt != leftHalf.end())
			{
				*cursor = *leftIt;
				++leftIt;
				++cursor;
			}
			while (rightIt != rightHalf.end())
			{
				*cursor = *rightIt;
				++rightIt;
				++cursor;
			}
		}

		template <typename Container>
		void createChains(Container& numbers, Container& main, Container& pending)
		{
			typename Container::iterator it = numbers.begin();
			for (; it != numbers.end(); it++)
			{
				if (distance(numbers.begin(), it) % 2 == 1)
					main.push_back(*it);
				else
					pending.push_back(*it);
			}
		
		}

		/*
			Insert the pending numbers in the main container in a sorted manner
			1. Insert the first number of the pending container in the main container
				and move the iterator of the pending chain to the next number
			2. Generate the Jacobstahl sequence of the size of the pending container
			3. Loop over the Jacobstahl determining the number of items to insert in the main chain
			4. Loop over the pending chain to insert the numbers in the main chain
				with a bynary-search (lower_bound)
			5. Security loop in case there are remaining numbers in the pending chain

		*/
		template <typename Container>
		void insertionSort(Container& main, Container& pending)
		{
			if (pending.empty())
				return;

			main.insert(main.begin(), pending.front());

			typename Container::iterator itPend = pending.begin() + 1;
			size_t maxSize = pending.size();
			std::vector<size_t> jacobstahl = generateJacobstahl(maxSize);
			typename Container::iterator cursor;
			size_t insertedAmount = 1;

			for (size_t i = 1; i < jacobstahl.size(); ++i)
			{
				size_t jn = jacobstahl[i];
				size_t itemsToInsert = std::min(jn, maxSize - insertedAmount);
				typename Container::iterator itPendEnd = itPend;
        		std::advance(itPendEnd, itemsToInsert);
				
				while (itPend != itPendEnd)
				{
					cursor = std::lower_bound(main.begin(), main.end(), *itPend);
					main.insert(cursor, *itPend);
					++itPend;
					++insertedAmount;
				}
			}

			while (itPend != pending.end())
			{
				cursor = std::lower_bound(main.begin(), main.end(), *itPend);
				main.insert(cursor, *itPend);
				++itPend;
			}
		}

		template <typename Container> Container next(Container it, int steps)
		{
			std::advance(it, steps);
			return it;
		}

		template <typename Iterator>
		typename std::iterator_traits<Iterator>::difference_type distance(Iterator first, Iterator last)
		{
			typename std::iterator_traits<Iterator>::difference_type dist = 0;
			while (first != last)
			{
				++first;
				++dist;
			}
			return dist;
		}
};
#endif