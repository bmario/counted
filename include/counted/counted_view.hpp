/*
 * (c) 2013 Mario Bielert <mario.bielert@googlemail.com>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 */

#ifndef INCLUDE_COUNTED_COUNTED_VIEW_HPP
#define INCLUDE_COUNTED_COUNTED_VIEW_HPP
    
#include <counted/counted_iterator.hpp>
	
namespace detail {
    template <typename Range>
    class counted_view {
        const Range& r;

        typedef decltype(std::begin(r))  nested_iterator;
        typedef decltype(*std::begin(r)) nested_value_type;
    public:

        counted_view(const Range& r) : r(r) {}

        counted_iterator<nested_iterator> begin()
        {
  
            return counted_iterator<nested_iterator>(std::begin(r));
        }

        counted_iterator<nested_iterator> end()
        {
            return counted_iterator<nested_iterator>(std::end(r));
        }
    };
}

#endif //INCLUDE_COUNTED_COUNTED_VIEW_HPP