/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:34:08 by angassin          #+#    #+#             */
/*   Updated: 2024/11/28 21:48:41 by angassin         ###   ########.fr       */
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
# include <algorithm> // swap

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

		void	parseInput(int argc, char* argv[]);
		
		// Ford-Johnson merge-insertion sort algorithm
		template <typename Container>
		void	mergeInsertionSort(Container& numbers)
		{
			if (numbers.size() <= 1)
				return;
			
			sortPairs(numbers);
			mergeSortPairs(numbers);
			
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
			using a temporary container to store the pairs sorted
			with a merge sort algorithm
		*/ 
		template <typename Container>
		void	mergeSortPairs(Container& numbers)
		{
			if (numbers.size() < 2)
				return;
			Container	temp(numbers.size());
			// mergeSort(numbers, temp, 0, numbers.size() - 1);
			mergeSort(numbers, temp, 0, (numbers.size() / 2) - 1);
		}
		
		/*
			Recursively divides the container in halves until the size is 1
			Then merges the halves in a sorted manner
		*/
		template <typename Container>
		void	mergeSort(Container& numbers, Container& temp, size_t left, size_t right)
		{
			if (left < right)
			{
				size_t	mid = (left + right) / 2;
				mergeSort(numbers, temp, left, mid);
				mergeSort(numbers, temp, mid + 1, right);
				mergeHalves(numbers, temp, left, mid + 1, right);
			}
		}

		/*
			Merges the two subarrays of pairs
			1. Merge the two subarrays while comparing the last number of the pairs
			2. Copy the remaining elements of the left subarray if any
			3. Copy the remaining elements of the right subarray if any
			4. Copy the merged elements back into the original container
		*/
		// template <typename Container>
		// void	mergeHalves(Container& numbers, Container& temp,
		// 	size_t	leftPos, size_t rightPos, size_t rightEnd)
		// {
		// 	size_t	leftEnd = rightPos - 1;
		// 	size_t	tempPos = leftPos;
		// 	size_t	nbElements = rightEnd - leftPos + 1;

		// 	while (leftPos <= leftEnd && rightPos <= rightEnd)
		// 	{
		// 		if (numbers[leftPos + 1] <= numbers[rightPos + 1])
		// 		{
		// 			temp[tempPos++] = numbers[leftPos++];
		// 			temp[tempPos++] = numbers[leftPos++];
		// 		}
		// 		else
		// 		{
		// 			temp[tempPos++] = numbers[rightPos++];
		// 			temp[tempPos++] = numbers[rightPos++];
		// 		}
		// 	}

		// 	while (leftPos <= leftEnd)
		// 	{
		// 		temp[tempPos++] = numbers[leftPos++];
		// 		temp[tempPos++] = numbers[leftPos++];
		// 	}

		// 	for (size_t i = 0; i < nbElements; ++i, --rightEnd)
		// 		numbers[rightEnd] = temp[rightEnd];
		// }
		// 		template <typename Container>
// void mergeHalves(Container& numbers, Container& temp, size_t left, size_t mid, size_t right)
// {
//     size_t leftPos = left * 2;
//     size_t rightPos = (mid + 1) * 2;
//     size_t tempPos = left * 2;
//     size_t leftEnd = (mid + 1) * 2;
//     size_t rightEnd = (right + 1) * 2;

//     while (leftPos < leftEnd && rightPos < rightEnd)
//     {
//         if (numbers[leftPos + 1] <= numbers[rightPos + 1])
//         {
//             temp[tempPos] = numbers[leftPos];
//             temp[tempPos + 1] = numbers[leftPos + 1];
//             leftPos += 2;
//         }
//         else
//         {
//             temp[tempPos] = numbers[rightPos];
//             temp[tempPos + 1] = numbers[rightPos + 1];
//             rightPos += 2;
//         }
//         tempPos += 2;
//     }

//     while (leftPos < leftEnd)
//     {
//         temp[tempPos] = numbers[leftPos];
//         temp[tempPos + 1] = numbers[leftPos + 1];
//         leftPos += 2;
//         tempPos += 2;
//     }
// 	while (rightPos < rightEnd)
//     {
//         temp[tempPos] = numbers[rightPos];
//         temp[tempPos + 1] = numbers[rightPos + 1];
//         rightPos += 2;
//         tempPos += 2;
//     }

//     for (size_t i = left * 2; i < rightEnd; i++)
//     {
//         numbers[i] = temp[i];
//     }
// }
	template <typename Container>
	void mergeHalves(Container& numbers, Container& temp, size_t left, size_t mid, size_t right)
	{
		size_t leftPos = left * 2;
		size_t rightPos = (mid + 1) * 2;
		size_t tempPos = left * 2;
		size_t leftEnd = (mid + 1) * 2;
		size_t rightEnd = (right + 1) * 2;

		// Merge the two subarrays while comparing the second element of each pair
		while (leftPos < leftEnd && rightPos < rightEnd)
		{
			if (numbers[leftPos + 1] <= numbers[rightPos + 1])
			{
				temp[tempPos++] = numbers[leftPos++];
				temp[tempPos++] = numbers[leftPos++];
			}
			else
			{
				temp[tempPos++] = numbers[rightPos++];
				temp[tempPos++] = numbers[rightPos++];
			}
		}

		// Copy the remaining elements of the left subarray if any
		while (leftPos < leftEnd)
		{
			temp[tempPos++] = numbers[leftPos++];
			temp[tempPos++] = numbers[leftPos++];
		}

		// Copy the remaining elements of the right subarray if any
		while (rightPos < rightEnd)
		{
			temp[tempPos++] = numbers[rightPos++];
			temp[tempPos++] = numbers[rightPos++];
		}

		// Copy the merged elements back into the original array
		for (size_t i = left * 2; i < rightEnd; ++i)
		{
			numbers[i] = temp[i];
		}
	}
// template <typename Container>
// void mergeHalves(Container& numbers, Container& temp, size_t left, size_t mid, size_t right)
// {
//     size_t leftPos = left * 2;
//     size_t rightPos = (mid + 1) * 2;
//     size_t tempPos = left * 2;
//     size_t leftEnd = (mid + 1) * 2;
//     size_t rightEnd = (right + 1) * 2;

//     // Merge the two subarrays while comparing the second element of each pair
//     while (leftPos < leftEnd && rightPos < rightEnd)
//     {
//         if (numbers[leftPos + 1] <= numbers[rightPos + 1])
//         {
//             temp[tempPos] = numbers[leftPos];
//             temp[tempPos + 1] = numbers[leftPos + 1];
//             leftPos += 2;
//         }
//         else
//         {
//             temp[tempPos] = numbers[rightPos];
//             temp[tempPos + 1] = numbers[rightPos + 1];
//             rightPos += 2;
//         }
//         tempPos += 2;
//     }

//     // Copy the remaining elements of the left subarray if any
//     while (leftPos < leftEnd)
//     {
//         temp[tempPos] = numbers[leftPos];
//         temp[tempPos + 1] = numbers[leftPos + 1];
//         leftPos += 2;
//         tempPos += 2;
//     }

//     // Copy the remaining elements of the right subarray if any
//     while (rightPos < rightEnd)
//     {
//         temp[tempPos] = numbers[rightPos];
//         temp[tempPos + 1] = numbers[rightPos + 1];
//         rightPos += 2;
//         tempPos += 2;
//     }

//     // Copy the merged elements back into the original array
//     for (size_t i = left * 2; i < rightEnd; ++i)
//     {
//         numbers[i] = temp[i];
//     }
// }
};
#endif