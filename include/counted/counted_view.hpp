/*
 * (c) 2013, 2014 Mario Bielert <mario.bielert@googlemail.com>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 */

#ifndef INCLUDE_COUNTED_COUNTED_VIEW_HPP
#define INCLUDE_COUNTED_COUNTED_VIEW_HPP
    
#include <counted/counted_iterator.hpp>
	
namespace detail {
    template <typename Iterator>
    class counted_view {
        Iterator begin_;
        Iterator end_;
    public:

        counted_view(Iterator begin, Iterator end) : begin_(begin), end_(end) {}

        counted_iterator<Iterator> begin()
        {
  
            return counted_iterator<Iterator>(begin_);
        }

        counted_iterator<Iterator> end()
        {
            return counted_iterator<Iterator>(end_);
        }
    };
}

#endif //INCLUDE_COUNTED_COUNTED_VIEW_HPP