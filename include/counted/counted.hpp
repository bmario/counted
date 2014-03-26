/*
 * (c) 2013 Mario Bielert <mario.bielert@googlemail.com>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 */

#ifndef INCLUDE_COUNTED_COUNTED_HPP
#define INCLUDE_COUNTED_COUNTED_HPP

#include <vector>
#include <type_traits>

#include <counted/counted_view.hpp>
#include <counted/counted_temporary.hpp>

template <typename Range, typename FuckYouGCC = typename std::enable_if<std::is_lvalue_reference<Range&&>::value>::type>
inline detail::counted_view<Range> counted(Range& r)
{
    return detail::counted_view<Range>(r);
}

template <typename Range>
inline detail::counted_view<const Range> counted(const Range& r)
{
    return detail::counted_view<const Range>(r);
}

template <typename Range, typename FuckYouGCC = typename std::enable_if<!std::is_lvalue_reference<Range&&>::value>::type >
inline detail::counted_temporary<Range> counted(Range&& r)
{
    return detail::counted_temporary<Range>(std::move(r));
}

template <typename Range, std::size_t count>
inline detail::counted_view<Range[count]> counted(Range (&r)[count])
{
    return detail::counted_view<Range[count]>(r);
}

template <typename T>
inline detail::counted_temporary<std::initializer_list<T>> counted(std::initializer_list<T>&& r)
{
    return detail::counted_temporary<std::initializer_list<T>>(std::move(r));
}


#endif //INCLUDE_COUNTED_COUNTED_HPP
