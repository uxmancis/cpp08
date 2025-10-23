/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:18:09 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/23 10:56:37 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
/* std::stack container is not iterable*/

/* main required in subject: using std::stack methods*/
int main()
{
    MutantStack<int> mstack;
    mstack.push(5); //inserts element at the top
    mstack.push(17);
    std::cout << mstack.top() << std::endl; //accesses to the top element, shows 17
    mstack.pop(); //removes the top element
    std::cout << mstack.size() << std::endl; //shows 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

// #include <list>

// /* main required in subject: methods and iterators are adapted for lists*/
// int main()
// {
//     std::list<int> mstack;
//     mstack.push_back(5); //'push' in our MutantStack (inherites from std::stack)
//     mstack.push_back(17);
//     std::cout << mstack.back() << std::endl; //'top' in our MutantStack (inherites from std::stack)
//     mstack.pop_back(); //'pop' in our MutantStack (inherites from std::stack)
//     std::cout << mstack.size() << std::endl;
//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     //[...]
//     mstack.push_back(0);

//     /* std::list already has iterators */
//     std::list<int>::iterator it = mstack.begin();
//     std::list<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//     std::cout << *it << std::endl;
//     ++it;
//     }
//     std::list<int> s(mstack);
//     return 0;
// }

#include <stack>
#define CYAN "\033[36m"
#define RESET_COLOUR "\033[37m"
#define YELLOW "\033[33m"

// template <typename T>
void putStack(std::stack<int> stack)
{
    std::cout << "[";
    while (!stack.empty())
    {
        std::cout << stack.top() << ", "; //prints
        stack.pop(); //removes
    }
    std::cout << "]" << std::endl;
}

/* My tests */
// int main(void)
// {
//     /*********** ORIGINAL METHODS IN STACKS - Compare Stack (Original) vs. our Mutant Stack ***********/
//     std::cout << "\n************************* Show " CYAN "ORIGINAL" RESET_COLOUR" Member functions *************************" << std::endl;
//     /* Test 1: .empty() */
//     std::cout << "📄 Test 1: " CYAN << ".empty()" RESET_COLOUR << std::endl;
//     std::stack<int> stack;
    
//     if (stack.empty())
//         std::cout << "1) Stack is empty" << std::endl;
//     else 
//         std::cout << "1) Stack is NOT empty" << std::endl;
  
//     MutantStack<int> my_mstack;
//     if (my_mstack.empty())
//         std::cout << "2) our Mutant Stack is empty" << std::endl;
//     else 
//         std::cout << "2) our Mutant Stack is NOT empty" << std::endl;
//     std::cout << "✅ Test 1 - COMPLETED Successfully" << std::endl;

//     /* Test 2: .size() */
//     std::cout << "\n\n📄 Test 2: " CYAN << ".size()" RESET_COLOUR << std::endl;
//     std::cout << "1) Stack's size is " << stack.size() << std::endl;
//     std::cout << "2) our Mutant Stack's size is " << my_mstack.size() << std::endl;
//     std::cout << "✅ Test 2 - COMPLETED Successfully" << std::endl;

//     /* Test 3: .push(): insert elements into our stack, into TOP of stack */
//     std::cout << "\n\n📄 Test 3: " CYAN << ".push()" RESET_COLOUR ", " CYAN ".top()" RESET_COLOUR ", and " CYAN ".pop() " RESET_COLOUR << std::endl;
//     stack.push(60);
//     stack.push(60);
//     stack.push(60);
//     stack.push(60);
//     std::cout << "1) Original stack: ";
//     putStack(stack);

//     my_mstack.push(7);
//     my_mstack.push(7);
//     my_mstack.push(7);
//     std::cout << "2) our Mutant Stack: ";
//     putStack(my_mstack);
//     std::cout << "✅ Test 3 - COMPLETED Successfully" << std::endl;

//     /* Test 4: .swap() */
//     // std::cout << "\n\n📄 Test 4: " CYAN << ".swap()" RESET_COLOUR << std::endl;
//     // std::cout << "First swap: " << std::endl;
//     // stack.swap(my_mstack);
//     // std::cout << "1) Original stack: ";
//     // putStack(stack);
//     // std::cout << "2) our Mutant Stack: ";
//     // putStack(my_mstack);

//     // std::cout << "\nSecond swap: " << std::endl;
//     // my_mstack.swap(stack);
//     // std::cout << "1) Original stack: ";
//     // putStack(stack);
//     // std::cout << "2) our Mutant Stack: ";
//     // putStack(my_mstack);
//     // std::cout << "✅ Test 4 - COMPLETED Successfully" << std::endl;
    
    
//     /*********** SHOW ADDITIONAL METHODS FOR STACKS -  ***********/
//     std::cout << "\n\n************************* Show " YELLOW "ADDITIONAL" RESET_COLOUR " Member functions: ITERATORS *************************" << std::endl;
//     std::cout << "📄 Test 5: " YELLOW ".begin() " RESET_COLOUR " and " YELLOW ".end()" RESET_COLOUR << std::endl;
//     MutantStack<int>::iterator it = my_mstack.begin();
//     MutantStack<int>::iterator ite = my_mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//     std::cout << *it << std::endl;
//     ++it;
//     }
//     std::cout << "✅ Test 5 - COMPLETED Successfully" << std::endl;
//     return (0);
// }

// /* Stack's member functions: 
// *       empty() --> Test whether container is empty
// *       size() --> Return size
// *       top() --> Access (print) next element on top of stack
// *       push() --> Inserts a new element
// *       pop() --> Removes top element
// *       swap() --> Exchanges 100% elements from stacks
// *
// *  Additional member functions: begin() and end() that return iterators
// */