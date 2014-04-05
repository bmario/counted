/*
 * (c) 2013, 2014 Mario Bielert <mario.bielert@googlemail.com>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 */

#ifndef INCLUDE_COUNTED_COUNTED_ITERATOR_HPP
#define INCLUDE_COUNTED_COUNTED_ITERATOR_HPP

#include <iterator>

namespace detail {
template <typename Iterator>
class proxy {
public:
    
    typedef decltype(*Iterator()) value_type;
    typedef value_type& reference_type;
    
    proxy(std::size_t count, Iterator it) : m_count(count), it(it) {}
    
    std::size_t count() const
    {
        return m_count;
    }
    
    std::size_t index() const
    {
        return m_count;
    }
    
    reference_type value()
    {        
        return *it;
    }
    
private:
    std::size_t m_count;
    Iterator it;
};

template<typename Iterator>
class counted_iterator : public std::iterator<std::forward_iterator_tag, typename std::remove_reference<decltype(*Iterator())>::type>
{
    Iterator iter;
    std::size_t counter;

public:
    
    counted_iterator(Iterator iter) : iter(iter), counter(0) {}
    counted_iterator(Iterator iter, std::size_t counter) : iter(iter), counter(counter) {}

    proxy<Iterator> operator*()
    {
        return proxy<Iterator>(counter, iter);
    }

    //pre increment, e.g. ++iter
    counted_iterator& operator++()
    {
        ++iter;
        ++counter;

        return *this;
    }

    //post increment, e.g. iter++
    counted_iterator operator++(int)
    {
        counted_iterator tmp(iter, counter);
        ++iter;
        ++counter;

        return tmp;
    }

    bool operator!=(counted_iterator& other)
    {
        return iter != other.iter;
    }

    bool operator==(counted_iterator& other)
    {
        return iter == other.iter;
    }
};

} // namespace detail

#endif //INCLUDE_COUNTED_COUNTED_ITERATOR_HPP
