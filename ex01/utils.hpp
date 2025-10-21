/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:38:52 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/20 16:56:34 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RESET_COLOUR "\033[37m"
#define YELLOW "\e[0;33m"

#include <vector> //std::vector Standard Vector (container)
#include <list> //std::list Standard Vector (container)
#include <iostream> //std::cout to print
#include <algorithm> //std::min_element, std::find
#include <numeric> //adjacent_difference
#include <iomanip> //std::setw for adding space when printing


/* Learning: 
*
*   operator[] does exist for vector, but doesn't exist for list. 
*
*   As a result, we'll need to use iterators to loop through all elements 
*   instead of indexing.
*/
template <typename Container>
void putContainer(Container container)
{
    typename Container::iterator it = container.begin();
    
    std::cout << YELLOW "Container: [";
    while(it != container.end())
    {
        std::cout << *it;
        ++it;
        if (it != container.end())
            std::cout << ", ";
    }
    std::cout << "]" RESET_COLOUR << std::endl;
}

/* Generic for containers */
template <typename Container>
void sortContainer(Container &container)
{
    std::sort(container.begin(), container.end());
}

/* Specific for List type containers */
// template <typename T, typename Allocator>
// void sortContainer(std::list<T, Allocator> &c)
// {
    
// }

void sortContainer(std::list<int> container)
{
    container.sort();
}

#endif