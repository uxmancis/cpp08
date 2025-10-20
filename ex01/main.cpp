/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:32:42 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/20 16:26:46 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int randomNumber()
{
    return(std::rand() % 501);
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
    Span < std::vector<int> > sp((N)); 
    //Constructor is called --> As Span's a template class, type has to be specified when creating object.
    
    srand(time(0)); // seed the random generator once at the start
    
    /* ----------------------------- std:: VECTOR -------------------------------*/
    std::cout<<" ----------------------------- std:: VECTOR -------------------------------" << std::endl;
    /* std::vector initialization*/
    std::vector<int> randomNumbers(N); /* Create random container, this does NOT belong to our class */
    std::generate(randomNumbers.begin(), randomNumbers.end(), randomNumber); //Numbers are generated
    try
    {
        sp.addNumber(randomNumbers.begin(), randomNumbers.end()); //100% elements are added at once
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    /* Test 1: longestSpan*/
    std::cout << "\n📄 Test 1 - Vector: the longest distance between numbers in our container." << std::endl;
    int largest = sp.longestSpan();
    std::cout << CYAN "Longest Span: " << largest << RESET_COLOUR<< std::endl;

    /* Test 2: shortestSpan*/
    std::cout << "\n📄 Test 2 - Vector: the shortest distance between numbers in our container." << std::endl;
    int shortest = sp.shortestSpan();
    std::cout << CYAN "Shortest Span: " << shortest << RESET_COLOUR << std::endl;


    /* ----------------------------- std:: LIST -------------------------------*/
    std::cout <<"\n\n----------------------------- std:: LIST -------------------------------" << std::endl;
    /* Initialization */
    Span < std::list<int> > sp2((N)); 
    
    
    std::list<int> randomNumbers2(N);
    std::generate(randomNumbers2.begin(), randomNumbers2.end(), randomNumber); //Numbers are generated
    try
    {
        sp2.addNumber(randomNumbers2.begin(), randomNumbers2.end()); //100% elements are added at once
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "✅ Program continues safely!" << std::endl;
    
    /* Test 1: longestSpan*/
    std::cout << "\n\n📄 Test 3 - List: the longest distance between numbers in our container." << std::endl;
    largest = sp2.longestSpan();
    std::cout << CYAN "Longest Span: " << largest << RESET_COLOUR<< std::endl;

    /* Test 2: shortestSpan*/
    std::cout << "\n📄 Test 4 - List: the shortest distance between numbers in our container." << std::endl;
    shortest = sp2.shortestSpan();
    std::cout << CYAN "Shortest Span: " << shortest << RESET_COLOUR << std::endl;

    return (0);
}