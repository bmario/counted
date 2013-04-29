/*
 * (c) 2013 Mario Bielert <mario.bielert@googlemail.com>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 */

#ifndef INCLUDE_COUNTED_COUNTED_TEMPORARY_HPP
#define INCLUDE_COUNTED_COUNTED_TEMPORARY_HPP

#include <counted/counted_iterator.hpp>
	
namespace detail {

    template <typename Range>
    class counted_temporary {
        Range r;

        typedef decltype(std::begin(r))  nested_iterator;
        typedef decltype(*std::begin(r)) nested_value_type;
		typedef counted_iterator<nested_iterator> iterator;
    public:

        counted_temporary(Range&& r) : r(r) {}


        iterator begin()
        {
  
            return iterator(std::begin(r));
        }

        iterator end()
        {
            return iterator(std::end(r));
        }
    };
}

#endif //INCLUDE_COUNTED_COUNTED_TEMPORARY_HPP