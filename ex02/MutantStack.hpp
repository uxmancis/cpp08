/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:22:51 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/17 18:26:32 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

class MutantStack
{
    public:
        /* Member functions */
        bool empty();
        size_t size();
        void top();
        void push();
        void emplace();
        void pop();
        void swap();

        /* Additional feature*/
        void iterators();
};

#endif