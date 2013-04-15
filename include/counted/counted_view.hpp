/*
 * (c) 2013 Mario Bielert <mario.bielert@googlemail.com>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 */

#ifndef INCLUDE_COUNTED_COUNTED_VIEW_HPP
#define INCLUDE_COUNTED_COUNTED_VIEW_HPP
    
namespace detail {
    template <typename Value>
    class proxy {
    public:
        proxy(std::size_t count, const Value& v) : m_count(count), v(v) {}
        
        std::size_t count() const
        {
            return m_count;
        }
        
        std::size_t first() const
        {
            return count();
        }
        
        const Value& value() const
        {
            return v;
        }
        
        const Value& second() const
        {
            return value();
        }
        
    private:
        std::size_t m_count;
        const Value& v;
    };

    template <typename Range>
    class counted_view {
        const Range& r;

        typedef decltype(std::begin(r))  nested_iterator;
        typedef decltype(*std::begin(r)) nested_value_type;
    public:

        counted_view(const Range& r) : r(r) {}

        class iterator
        {
        public:
            iterator(nested_iterator iter) : iter(iter), counter(0) {}
            iterator(nested_iterator iter, std::size_t counter) : iter(iter), counter(counter) {}

            proxy<nested_value_type> operator*()
            {
                return proxy<nested_value_type>(counter, *iter);
            }

            //pre increment, e.g. ++iter
            iterator& operator++()
            {
                ++iter;
                ++counter;

                return *this;
            }
    
            //post increment, e.g. iter++
            iterator operator++(int)
            {
                iterator tmp(iter, counter);
                ++iter;
                ++counter;

                return tmp;
            }

            bool operator!=(iterator& other)
            {
                return iter != other.iter;
            }
  
            bool operator==(iterator& other)
            {
                return iter == other.iter;
            }
        private:
            nested_iterator iter;
            std::size_t counter;
        };

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

#endif //INCLUDE_COUNTED_COUNTED_VIEW_HPP