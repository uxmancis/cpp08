/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:33:38 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/17 17:17:46 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* Custom constructor */
Span::Span(unsigned int N_max): _N(N_max)
{
    std::cout << "container was created with size " CYAN << N_max << RESET_COLOUR << std::endl;
    (void)_N;
}

/* addNumber
*
*   _container.size(): How many numbers are already stored
*   _N: Maximum number of elements that can be store in container.
*
*   _container.insert: Adds new elements to a vector. It can be used in 
*                      several ways. Our way: to insert a range of elements.
*           .insert(position, firstIterator, lastIterator).
*/
// void Span::addNumber(int nb)
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{ 
    // _container.push_back(nb);
    // std::cout << YELLOW << "\n" << nb << RESET_COLOUR " has been assigned to container" << std::endl;
    
    // std::vector<int>::iterator begin = _container.begin();
    // std::vector<int>::iterator end = _container.end();
    
    /* #1 nb_elements: Get the total number of elements to add in the container */
    size_t nb_elements = std::distance(begin, end);
    // std::cout << "nb_elements: " << nb_elements << std::endl;
    // std::cout << "size: " << _container.size() << std::endl;
    // std::cout << "N = " << _N << std::endl;

    /* #2 freeSpace: How many slots are left*/
    size_t freeSpace = _N - _container.size();

    if (nb_elements > freeSpace)
        throw std::runtime_error("Not enough space in Span");

    //Insert: adds new elements to a vector. It can be used in 
    _container.insert(_container.end(), begin, end);

    // _N - _container.size()
    

    
    /* Visualize Values in container */
    std::cout << "Container = [";
    for (std::vector<int>::iterator it = _container.begin(); it != _container.end(); ++it)
        std::cout << *it << ", ";
    std::cout << "]" << std::endl;
}

/* shortestSpan
*   #1 Creates a copy from original container
*   #2 Sorts the integers ascending from container
*   #3 Sets initial difference and checks whether if there is any shorter difference
*
*   container.begin() and .end() are 2 iterators that define a range [begin, end]
*       > begin(): points to the 1st element to add.
*       > end(): points past N, doesn't refer to a real elemet.
*
*/
int Span::shortestSpan()
{
    std::vector<int> sorted = _container; /* Creates a copy from original container */
    std::sort(sorted.begin(), sorted.end()); /* Sorts the integers ascending from container */
    
    /* Visualize Values in container */
    // std::cout << "\nContainer = [";
    // for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it)
    //     std::cout << *it << ", ";
    // std::cout << "]" << std::endl;
    /* Visualize Values in container */
    // std::cout << "Sorted = [";
    // for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
    //     std::cout << *it << ", ";
    // std::cout << "]" << std::endl;
    

    int minDiff = std::abs(sorted[1] - sorted[0]); //Initial difference
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int diff = std::abs(sorted[i+1] - sorted[i]);
        if (diff < minDiff)
            diff = minDiff;
    }
    
    return(minDiff);
}

/* std::min_element and std::max_element both return an iterator (similar to a pointer) to
*  smallest and largest elements. That's why we use '*' to dereference it and get the 
*  actual number. */
int Span::longestSpan()
{
    int nb_smallest = *std::min_element(_container.begin(), _container.end());
    int nb_largest = *std::max_element(_container.begin(), _container.end());
    int substraction = nb_largest - nb_smallest;

    // std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    std::cout << std::setw(10) << "> shortest number: " << nb_smallest << std::endl;
    std::cout << std::setw(10) << "> largest number: " << nb_largest << std::endl;
    return(substraction);
}