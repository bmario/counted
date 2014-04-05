/*
 * (c) 2013, 2014 Mario Bielert <mario.bielert@googlemail.com>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 */

#ifndef INCLUDE_COUNTED_COUNTED_HPP
#define INCLUDE_COUNTED_COUNTED_HPP

#include <counted/counted_view.hpp>
#include <counted/counted_temporary.hpp>

#include <type_traits>
#include <vector>
#include <initializer_list>

template <typename Container, typename enabled = typename std::enable_if<std::is_lvalue_reference<Container&&>::value && std::is_const<Container>::value>::type>
auto counted(Container&& c) -> detail::counted_view<decltype(c.cbegin())>
{
    return detail::counted_view<decltype(c.cbegin())>(c.cbegin(), c.cend());
}

template <typename Container, typename enabled = typename std::enable_if<(std::is_lvalue_reference<Container&&>::value && !std::is_const<Container>::value) || std::is_array<Container>::value>::type>
auto counted(Container&& c) -> detail::counted_view<decltype(std::begin(c))>
{
    return detail::counted_view<decltype(std::begin(c))>(std::begin(c), std::end(c));
}

template <typename Container, typename enabled = typename std::enable_if<std::is_rvalue_reference<Container&&>::value>::type>
detail::counted_temporary<Container> counted(Container&& c)
{
    return detail::counted_temporary<Container>(std::move(c));
}

template <typename T>
detail::counted_temporary<std::vector<T>> counted(std::initializer_list<T>&& l)
{
    return detail::counted_temporary<std::vector<T>>(std::vector<T>(std::move(l)));
}

#endif //INCLUDE_COUNTED_COUNTED_HPP
