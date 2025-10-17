/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:49:24 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/17 12:25:52 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Vector: It is a container similar to an array, but that can change size when 
*           needed.     
*/
#include <vector> //std::vector Standard Vector (container)
#include <iostream> //std::cout to print
#include <algorithm> //std::find

#define CYAN "\033[36m"
#define RESET_COLOUR "\033[37m"

template <typename T>
int easyfind (T container, int number)
{
    std::vector<int>::iterator it = std::find(container.begin(), container.end(), number);
    if (it == container.end())
    {
        std::cerr << "❌: " CYAN << number << RESET_COLOUR " number was NOT found in container" << std::endl;
        return (-1); 
    }
    std::cout << "✅: " CYAN << number << RESET_COLOUR " number WAS found in container, yay! :) " <<  std::endl;
    return(0);
}

int main(void)
{
    int number = 99;

    /* Option 1: empty vector and PUSH BACK each value*/
    std::vector<int> myContainer1; //empty vector
    myContainer1.push_back(1); //Content of container
    myContainer1.push_back(5);
    myContainer1.push_back(3);

    /* Option 2: Fixed size with default values: */
    std::vector<int> myContainer2(5); //5 elements, all initialized to 0 => myContainer2 = [0, 0, 0, 0, 0]

    /* Option 3: Fixed size with custom initial value */
    std::vector<int> myContainer3(5, 42);

    /* Option 4: Assign values later: */
    std::vector<int> myContainer4;
    myContainer4.assign(4, 99); // myContainer4 = [99, 99, 99, 99, 99]
    
    /*Test 1: myContainer1*/
    std::cout << "Test 1: myContainer1 -------------------------" << std::endl;
    easyfind(myContainer1, number);
    std::cout << "\n" << std::endl;
    
    /*Test 2: myContainer2*/
    std::cout << "Test 2: myContainer2 -------------------------" << std::endl;
    easyfind(myContainer2, number);
    std::cout << "\n" << std::endl;

    /*Test 3: myContainer3*/
    std::cout << "Test 3: myContainer3 -------------------------" << std::endl;
    easyfind(myContainer3, number);
    std::cout << "\n" << std::endl;

    /*Test 4: myContainer4*/
    std::cout << "Test 4: myContainer4 -------------------------" << std::endl;
    easyfind(myContainer4, number);
    std::cout << "\n" << std::endl;
}


/* About containers in STL (Standard Template Library):
*
*
*/