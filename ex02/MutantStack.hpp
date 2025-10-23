/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:22:51 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/23 11:17:50 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef MUTANTSTACK_HPP
// #define MUTANTSTACK_HPP

// #include <stack>

// template <typename T>
// class MutantStack : public std::stack
// {
//     public:
//         // MutantStack(); /* Default Constructor */
//         // MutantStack(const MutantStack &src2cpy); /* Copy Constructor */
//         // MutantStack &operator=(const MutantStack &src2cpy); /* Copy Assignment Operator */
//         // ~MutantStack(); /* Destructor */
//         MutantStack(): std::stack<T>() {};
// 		MutantStack(const MutantStack& to_copy): std::stack<T>(static_cast<std::stack<T> > (to_copy)) {};
// 		MutantStack& operator=(const MutantStack& to_asign) {static_cast<std::stack<T> > (this) = static_cast<std::stack<T> > (to_asign);};
// 		~MutantStack() {};

//         /* Additional feature: Iterators*/
//         // iterator begin();
//         // iterator end();

//         typedef typename std::stack<T>::container_type::iterator iterator;
// 		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
// 		iterator begin() { return std::stack<T>::c.begin();}
// 		iterator end() { return std::stack<T>::c.end();}
// 		const_iterator begin() const { return std::stack<T>::c.begin();}
// 		const_iterator end() const { return std::stack<T>::c.end();}
// };

// #endif

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack> //std::stack container

/* std::stack is not a container itself, it's a container adapter. It's
*  actually buiñt on top of another container (std::deque<T> by default) + 
*  restricts access to behave like a stack (LIFO).
*
*  std::stack 
*/

template	<typename T>
class	MutantStack : public std::stack<T>
{
	public:

		/* When we use a template class, the full implementation must be in .hpp */
		
		/*OCF*/
		MutantStack(): std::stack<T>(){}; /* Default Constructor */
		MutantStack(const MutantStack	&src2cpy): std::stack<T> (src2cpy){}; /* Copy constructor */
		MutantStack& operator=(const MutantStack	&src2cpy)/* Copy assignment operator */
		{
			if (this != &src2cpy)
				std::stack<T>::operator=(src2cpy); //Calls std::stack's assignment operator
			return *this;
		}; 
		~MutantStack(){}; /* Destructor */

	public:
		/* About iterators: 
		*		#1 std --> standard Namespace in C++
		*			└── #2 ::stack<T> --> The base template Class, instanced with type T
		* 				└── #3 :: container_type --> an alias (typedef) inside class std::stack, typedef Container container_type
		*					 └── #4 ::iterator --> 
		*		Summary: 'iterator' named type, that exists in 'container_type' named type that uses stack<T>
		*
		*  About syntax: 
		*		typedef --> creates an alias (nickname) for a type
		*				E.g.: 
		*					typedefnsigned long long ULL;
		*					ULL age = 42;
		*						, instead of
		*					unsigned long long age = 42;
		*
		*				E.g.2:
		*					typedef (...) iterator; --> Example 
		*					typedef (real type) alias; --> Explanation
		*
		*		typename --> because of template, T, it must go before std::stack in this case
		*
		*		:: --> it's used to access a member, type or method that is defined inside another entity (namespace or class)
		*/
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		
		/* begin() and end() named methods return 'iterator' and 'const_iterator' types */
		iterator begin(){
			return std::stack<T>::c.begin();}
		iterator end(){
			return std::stack<T>::c.end();}
		const_iterator begin() const{
			return std::stack<T>::c.begin();}
		const_iterator end() const {
			return std::stack<T>::c.end();}
};

#endif