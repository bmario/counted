/*
 * (c) 2013 Mario Bielert <mario.bielert@googlemail.com>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 */

#ifndef INCLUDE_COUNTED_COUNTED_HPP
#define INCLUDE_COUNTED_COUNTED_HPP

#include <vector>

#include <counted/counted_view.hpp>

template <typename Range> 
inline detail::counted_view<Range> counted(Range& r)
{
  return detail::counted_view<Range>(r);
}

#endif //INCLUDE_COUNTED_COUNTED_HPP