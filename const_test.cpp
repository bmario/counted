/*
 * (c) 2013 Mario Bielert <mario.bielert@googlemail.com>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.
 */

#include <iostream>
#include <cassert>
#include <vector>

#include <counted/counted.hpp>

int main()
{
  std::vector<double> vec = {10,20,30,40,50,60,70,80,90};
  
  const std::vector<double>& vec2 = vec;
  
  std::size_t i = 0;
  
   for(auto p : counted(vec2))
  {
    assert(i == p.count());
    std::cout << p.count() << ": " << p.value() << std::endl;
    assert(vec[i] == p.value());
    
    i++;
  }
  
  assert(i == 9);
  
  return 0;
}