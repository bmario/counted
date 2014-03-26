/*
 * (c) 2013 Mario Bielert <mario.bielert@googlemail.com>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 */

#include <counted/counted.hpp>

#include <iostream>
#include <cassert>

int main()
{
    double vec2[] = {10,20,30,40,50,60,70,80,90};
    std::size_t i = 0;

    for(auto p : counted( {10,20,30,40,50,60,70,80,90}))
    {
        assert(i == p.count());
        std::cout << p.count() << ": " << p.value() << std::endl;
        assert(vec2[i] == p.value());

        i++;
    }

    assert(i == 9);

    return 0;
}
