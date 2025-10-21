/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxuemancisidorlaskurain <uxuemancisidor    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:22:51 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/21 12:32:55 by uxuemancisi      ###   ########.fr       */
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

#ifndef MutantStack_HPP
# define MutantStack_HPP

#include <stack> //std::stack container

template	<typename T>
class	MutantStack : public std::stack<T>
{
	public:
		/*OCF*/
		MutantStack(): std::stack<T>() {};
		MutantStack(const MutantStack& to_copy): std::stack<T>(static_cast<std::stack<T> > (to_copy)) {};
		MutantStack& operator=(const MutantStack& to_asign) {static_cast<std::stack<T> > (this) = static_cast<std::stack<T> > (to_asign);};
		~MutantStack() {};

	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		iterator begin() { return std::stack<T>::c.begin();}
		iterator end() { return std::stack<T>::c.end();}
		const_iterator begin() const { return std::stack<T>::c.begin();}
		const_iterator end() const { return std::stack<T>::c.end();}
};

#endif