/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:18:01 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/20 12:38:44 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Vector: It is a container similar to an array, but that can change size when 
*           needed.     
*/
#include <vector> //std::vector Standard Vector (container)
#include <iostream> //std::cout to print
#include <algorithm> //std::find

//.tpp should NEVER include .hpp file (easyfind.hpp in this case)

/* 1st time using iterators! :)*/
template <typename T>
int easyfind (T container, int number)
{
    /* Previous version, only works with std::vector<int>, and 
    *  that breaks with the whole idea of making easyfind a template. */
    // std::vector<int>::iterator it = std::find(container.begin(), container.end(), number);
    
    /* This way it accepts any kind of container :)*/
    typename T::iterator it = std::find(container.begin(), container.end(), number);
    if (it == container.end())
    {
        std::cerr << "❌: " CYAN << number << RESET_COLOUR " number was NOT found in container" << std::endl;
        return (-1); 
    }
    std::cout << "✅: " CYAN << number << RESET_COLOUR " number WAS found in container, yay! :) " <<  std::endl;
    return(0);
}