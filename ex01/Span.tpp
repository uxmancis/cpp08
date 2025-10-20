/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:34:22 by uxmancis          #+#    #+#             */
/*   Updated: 2025/10/20 16:51:22 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Custom constructor */
template <typename T> //When a class is template, this must appear above the methods.
Span<T>::Span(unsigned int N_max): _N(N_max)
{
    std::cout << "container was created with size " CYAN << N_max << RESET_COLOUR << std::endl;
    (void)_N;
}

/* addNumber
*
*   _container.size(): How many numbers are already stored
*   _N: Maximum number of elements that can be store in container.
*
*   _container.insert: Adds new elements to a vector. It can be used in 
*                      several ways. Our way: to insert a range of elements.
*           .insert(position, firstIterator, lastIterator).
*/
// void Span::addNumber(int nb)
template <typename T>
template <typename InputIterator>
void Span<T>::addNumber(InputIterator begin, InputIterator end)
{   
    /* #1 nb_elements: Get the total number of elements to add in the container */
    size_t nb_elements = std::distance(begin, end);
    
    /* #2 freeSpace: How many slots are left*/
    size_t freeSpace = _N - _container.size();
    std::cout << "nb_elements = " << nb_elements << ", freeSpace = " << freeSpace << std::endl;

    if (nb_elements > freeSpace)
        throw std::runtime_error("Not enough space in Span");

    /* #3 Insert: adds new elements to a vector. */
    _container.insert(_container.end(), begin, end);
    
    /* Visualize Values in container */
    putContainer(_container);
}

/* shortestSpan
*   #1 Creates a copy from original container
*   #2 Sorts the integers ascending from container
*   #3 Sets initial difference and checks whether if there is any shorter difference
*
*   container.begin() and .end() are 2 iterators that define a range [begin, end]
*       > begin(): points to the 1st element to add.
*       > end(): points past N, doesn't refer to a real elemet.
*
*  We canNOT use indexes with list containers. Then, we'll use iterator++ so iterate
*  and access to container's content. This way, we make this function work with any
*  kind of container, no matter whether if they have or do not have index access.
*  Solution: we'll use iterators only.
*
*  Also, sort isn't universal. So, we create an implementation ourselves.
*
*/
template <typename Container>
int Span<Container>::shortestSpan()
{
    /* #1 Create copy from original container*/
    Container sorted = _container;
    
    /* #2 Sorts the integers ascending from container */
    sortContainer(sorted); // 👈 automatically calls correct version!:)
    
    sorted.sort();
    
    typename T::const_iterator prev = sorted.begin();
    typename T::const_iterator it = prev;
    ++it;

    int minDiff = std::abs(*it - *prev);

    for (; it != sorted.end(); ++it, ++prev)
    {
        int diff = std::abs(*it - *prev);
        if (diff < minDiff)
            minDiff = diff;
    }

    return minDiff;
    
    
    
    
    
    /////////////////////Previous version:
    // std::sort(sorted.begin(), sorted.end());
    // // std::cout << "SORTED: ";
    // putContainer(sorted);
    
    // int minDiff = std::abs(sorted[1] - sorted[0]); //Initial difference
    // // std::cout << "Initial " GREEN "minDiff = " RESET_COLOUR << minDiff << std::endl;
    // size_t i = 0;
    // int number1 = sorted[i];
    // // std::cout << "number1 = " << number1 << std::endl;
    // int number2= sorted[i+1];
    // int diff = std::abs(sorted[i+1] - sorted[i]);
    // // std::cout << CYAN "diff = " RESET_COLOUR << diff << std::endl;
    // for (i = 1; i < sorted.size() - 1; ++i)
    // {
    //     diff = std::abs(sorted[i+1] - sorted[i]);
    //     // std::cout << "      RECALCULATE - "CYAN "diff = " RESET_COLOUR << diff << std::endl;
    //     if (diff < minDiff)
    //     {
    //         // std::cout << YELLOW << "i = " << i << ", again :)" RESET_COLOUR  <<  std::endl;
    //         minDiff = diff;
    //         number1 = sorted[i];
    //         number2 = sorted[i+1];
    //         // std::cout << "number1 = " << number1 << std::endl;
    //         // std::cout << "number2 = " << number2 << std::endl;
    //         // std::cout << GREEN "minDiff = " RESET_COLOUR << minDiff << std::endl;
    //         // std::cout << CYAN "diff = " RESET_COLOUR << diff << std::endl;
    //         // std::cout << "---------------------" << std::endl;
    //     } 
    // }
    // std::cout << "  > shortestSpan, number1 = " << number1 << std::endl;
    // std::cout << "  > shortestSpan, number2 = " << number2 << std::endl;
    // // std::cout << "shortestSpan, minDiff = " << minDiff << std::endl;
    // // std::cout << "shortestSpan, diff = " << diff << std::endl;
    
    // return(minDiff);
}

/* std::min_element and std::max_element both return an iterator (similar to a pointer) to
*  smallest and largest elements. That's why we use '*' to dereference it and get the 
*  actual number. */
template <typename T>
int Span<T>::longestSpan()
{
    int nb_smallest = *std::min_element(_container.begin(), _container.end());
    int nb_largest = *std::max_element(_container.begin(), _container.end());
    int substraction = nb_largest - nb_smallest;

    // std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    std::cout << std::setw(10) << "  > shortest number: " << nb_smallest << std::endl;
    std::cout << std::setw(10) << "  > largest number: " << nb_largest << std::endl;
    return(substraction);
}