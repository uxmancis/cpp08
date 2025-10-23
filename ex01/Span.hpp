/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:27:46 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/22 17:01:27 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include "utils.hpp"

/* Span is NOT a normal class, it's a template class.
*  When we want to instantiate (create object) from that class, 
*  we need to specify what type we want to use for T */

// template <typename Container>
class Span
{
    private:
        
        unsigned int     _N; /* Max number of integers the class can store */
        
    public:
        // std::vector<int> _container; /* Previous version only accepts std::vector */
        // Container _container;
        std::vector<int> _container;
        
        Span(unsigned int N_max); /* Constructor */
        Span(const Span &src2cpy); /* Copy Constructor */
        Span &operator=(const Span &src2cpy); /* Copy Assignment Operator */
        ~Span(); /* Destructor */
        
        /* Member functions: */
        // void addNumber(int nb); /* Adds a single number to the Span*/
        
        void addNumber(int number);

        template <typename InputIterator>
        void addNumber2(InputIterator end, InputIterator begin);
        
        int shortestSpan();
        int longestSpan();
        
};

#include "Span.tpp" //.hpp must include .tpp :)

#endif