/*
 * (c) 2013 Mario Bielert <mario.bielert@googlemail.com>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 */

#ifndef INCLUDE_COUNTED_COUNTED_ITERATOR_HPP
#define INCLUDE_COUNTED_COUNTED_ITERATOR_HPP

namespace detail {
template <typename Value>
class proxy {
public:
    proxy(std::size_t count, const Value& v) : m_count(count), v(v) {}

    std::size_t count() const
    {
        return m_count;
    }

    const Value& value() const
    {
        return v;
    }

private:
    std::size_t m_count;
    const Value& v;
};

template<typename Iterator>
class counted_iterator
{
    Iterator iter;
    std::size_t counter;

public:
    typedef decltype(*iter) value_type;

    counted_iterator(Iterator iter) : iter(iter), counter(0) {}
    counted_iterator(Iterator iter, std::size_t counter) : iter(iter), counter(counter) {}

    proxy<value_type> operator*()
    {
        return proxy<value_type>(counter, *iter);
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
