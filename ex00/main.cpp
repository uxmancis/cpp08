/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:49:24 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/22 15:56:27 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define RESET_COLOUR "\033[37m"

#include <vector> //std::vector Standard Vector (container)
#include <list> //std::list Standard Vector (container)
#include <iostream> //std::cout to print
#include "easyfind.hpp"

/* Associative containers (set, multiset, map, multimap) do NOT
*  have to be handled in this exercise :) */


/* Learning: 
*
*   operator[] does exist for vector, but doesn't exist for list. 
*
*   As a result, we'll need to use iterators to loop through all elements 
*   instead of indexing.
*/
template <typename T>
void putContainer(T container)
{
    typename T::iterator it = container.begin();
    
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

/* To test our program, we can modify either:
*
*   1) int number: The numbre we'll try to find in our containers
*   2) or the definition of our containers (Option 1-4)
*
*   Tests 1-4 will show result automatically :)
*/
int main(void)
{
    int number = 17; /* number we'll try to find in containers*/

    /* Option 1, std::vector: empty vector and PUSH BACK each value*/
    std::vector<int> myContainer1; //empty vector
    myContainer1.push_back(1); //Content of container
    myContainer1.push_back(5);
    myContainer1.push_back(17);

    /* Option 2, std::vector: Fixed size with default values: */
    std::vector<int> myContainer2(5); //5 elements, all initialized to 0 => myContainer2 = [0, 0, 0, 0, 0]

    /* Option 3, std::vector: Fixed size with custom initial value */
    std::vector<int> myContainer3(5, 42);

    /* Option 4, std::vector: Assign values later: */
    std::vector<int> myContainer4;
    myContainer4.assign(4, 99); // myContainer4 = [99, 99, 99, 99, 99]

    /* Option 5, std::list: Assign values later: */
    std::list<int>  myContainer5(2);
    myContainer5.assign(2, 103); // myContainer5 = [103, 103]
    
    std::cout << "\nNumber to be found in containers: " << CYAN << number << RESET_COLOUR << std::endl;
    
    /*Test 1: myContainer1 - Vector*/
    std::cout << "\n----- 📄 Test 1: myContainer1 -------------------------" << std::endl;
    putContainer(myContainer1);
    easyfind(myContainer1, number);
    std::cout << "\n" << std::endl;
    
    /*Test 2: myContainer2 - Vector*/
    std::cout << "----- 📄 Test 2: myContainer2 -------------------------" << std::endl;
    putContainer(myContainer2);
    easyfind(myContainer2, number);
    std::cout << "\n" << std::endl;

    /*Test 3: myContainer3 - Vector*/
    std::cout << "----- 📄 Test 3: myContainer3 -------------------------" << std::endl;
    putContainer(myContainer3);
    easyfind(myContainer3, number);
    std::cout << "\n" << std::endl;

    /*Test 4: myContainer4 - Vector*/
    std::cout << "----- 📄 Test 4: myContainer4 -------------------------" << std::endl;
    putContainer(myContainer4);
    easyfind(myContainer4, number);
    std::cout << "\n" << std::endl;

    /*Test 5: myContainer5 - List*/
    std::cout << "----- 📄 Test 5: myContainer5 -------------------------" << std::endl;
    putContainer(myContainer5);
    easyfind(myContainer5, number);
    std::cout << "\n" << std::endl;
}


/* About containers in STL (Standard Template Library):
*
*
*/