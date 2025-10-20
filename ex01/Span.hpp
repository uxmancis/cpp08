/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:27:46 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/20 16:24:08 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include "utils.hpp"

/* Span is NOT a normal class, it's a template class.
*  When we want to instantiate (create object) from that class, 
*  we need to specify what type we want to use for T */

template <typename T> class Span
{
    private:
        
        unsigned int     _N; /* Max number of integers the class can store */
        
    public:
        // std::vector<int> _container; /* Previous version only accepts std::vector */
        T _container;
        
        Span(unsigned int N_max); /* Constructor */
        
        /* Member functions: */
        // void addNumber(int nb); /* Adds a single number to the Span*/
        template <typename InputIterator>
        void addNumber(InputIterator end, InputIterator begin);
        int shortestSpan();
        int longestSpan();
        
};

#include "Span.tpp" //.hpp must include .tpp :)

#endif