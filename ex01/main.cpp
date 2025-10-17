/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:32:42 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/17 17:25:05 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int randomNumber()
{
    return(std::rand() % 101);
}

/* #1 As an evaluator, 🥊choose your figher in main by defining N.
*           N represents the number of elements(integers) 
*           our container will have.
*
*  Explanation of exercise:
*  #2 randomNumber() generates integers in range [0-100] both inclusive.
*  #3 addNumber() adds these integers into object's _container.
*  
*  📄 Finally, 2 tests show what do longestSpan() and shortestSpan() do.
*  
 */
int main(void)
{
    unsigned int N = 10; /* 🥊 Choose your figher :)*/
    
    /* Initialization */
    Span sp(N); //Constructor is called
    
    srand(time(0)); // seed the random generator once at the start
    
    std::vector<int> randomNumbers(N);
    std::generate(randomNumbers.begin(), randomNumbers.end(), randomNumber); //Numbers are generated
    sp.addNumber(randomNumbers.begin(), randomNumbers.end()); //100% elements are added at once
    
    /* Test 1: longestSpan*/
    std::cout << "\n📄 Test 1: the longest distance between numbers in our container." << std::endl;
    int largest = sp.longestSpan();
    std::cout << "Longest Span: " << largest << std::endl;

    /* Test 2: shortestSpan*/
    std::cout << "\n📄 Test 2: the shortest distance between numbers in our container." << std::endl;
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;

    return (0);
}