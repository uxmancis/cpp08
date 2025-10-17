/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:27:46 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/17 17:10:57 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#define CYAN "\033[36m"
#define RESET_COLOUR "\033[37m"
#define YELLOW "\e[0;33m"

#include <vector> //std::vector Standard Vector (container)
#include <iostream> //std::cout to print
#include <algorithm> //std::min_element, std::find
#include <numeric> //adjacent_difference
#include <iomanip> //std::setw for adding space when printing

class Span
{
    private:
        
        unsigned int     _N; /* Max number of integers the class can store */
        
    public:
        std::vector<int> _container;
        
        Span(unsigned int N_max); /* Constructor */
        
        /* Member functions: */
        // void addNumber(int nb); /* Adds a single number to the Span*/
        void addNumber(std::vector<int>::iterator end, std::vector<int>::iterator begin);
        int shortestSpan();
        int longestSpan();
        
};

#endif