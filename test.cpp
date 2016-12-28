#include "Map.hpp"

#include <cassert>
int main(){
 
 {
 std::cout<<"**************************"<<std::endl<<std::endl;
 std::cout<<"Map<int,int> test"<<std::endl;
 std::cout<<"**************************"<<std::endl<<std::endl;

  cs540::Map<int,int> a; 
 std::pair <int,int> foo;
  foo=std::make_pair(1,207);
    a.insert(foo);
  foo=std::make_pair(200,290);
  a.insert(foo);
   foo=std::make_pair(-1,206);
  a.insert(foo);
    foo=std::make_pair(2010,20);
  a.insert(foo);  


std::cout<<"Map<int,int> --- > Test of at(), size(), operator[]"<<std::endl<<std::endl;
std::cout<<"Value at key 2010 is    "<<a.at(2010)<<std::endl<<std::endl;
std::cout<<"Size of Map is    "<<a.size()<<std::endl<<std::endl;
std::cout<<"Value at key 1 using []    "<<a[1]<<std::endl<<std::endl;



std::cout<<"Map<int,int> Iterator != & == operator test"<<std::endl<<std::endl;
auto it=a.begin(); auto it1=a.end();
it++; it1--;
assert(it!=it1);
it1--; it1--;
assert(it==it1);

std::cout<<"Map<int,int> ReverseIterator test"<<std::endl<<std::endl;
auto r=a.rend();
r--;
std::cout<<"reverser order end "<<r.pos->key<<"  "<<r.pos->value<<std::endl<<std::endl;
auto r1=a.rbegin();
std::cout<<"reverser order begin "<<r1.pos->key<<"  "<<r1.pos->value<<std::endl<<std::endl;

std::cout<<"Map<int,int> Reverse Iterator != & == operator test"<<std::endl<<std::endl;
assert(r!=r1);
r--;r--;
r1++;
assert(r==r1);

std::cout<<"Map<int,int> copy construction Passed"<<std::endl;
auto m_copy=a;
assert(a==m_copy);

std::cout<<"Map<int,int> before erasing element Iterator"<<std::endl;

for(auto it2=a.begin();it2!=a.end();it2++)
std::cout<<it2.pos->key<<"  "<<it2.pos->value<<std::endl<<std::endl;
std::cout<<"Map<int,int> find() and erase() test"<<std::endl<<std::endl;
 auto it3=a.find(2010);
 a.erase(it3);

std::cout<<"Map after erasing key"<<std::endl<<std::endl<<std::endl;
for(auto it2=a.begin();it2!=a.end();it2++)
std::cout<<it2.pos->key<<"  "<<it2.pos->value<<std::endl<<std::endl;

std::cout<<"Map<int,int> clear() test"<<std::endl<<std::endl;


a.clear();
}

{

std::cout<<"**************************"<<std::endl<<std::endl;
 std::cout<<"Map<double,int> test"<<std::endl;
 std::cout<<"**************************"<<std::endl<<std::endl;

   cs540::Map<double,int> a; 
 std::pair <int,int> foo;
  foo=std::make_pair(1.0,207);
    a.insert(foo);
  foo=std::make_pair(200.00,290);
  a.insert(foo);
   foo=std::make_pair(-1.000,206);
  a.insert(foo);
    foo=std::make_pair(2010.0,20);
  a.insert(foo);  


std::cout<<"Map<double,int> --- > Test of at(), size(), operator[]"<<std::endl<<std::endl;
std::cout<<"Value at key 2010 is    "<<a.at(2010.0)<<std::endl<<std::endl;
std::cout<<"Size of Map is    "<<a.size()<<std::endl<<std::endl;
std::cout<<"Value at key 1 using []    "<<a[1.0]<<std::endl<<std::endl;



std::cout<<"Map<double,int> Iterator != & == operator test"<<std::endl<<std::endl;
auto it=a.begin(); auto it1=a.end();
it++; it1--;
assert(it!=it1);
it1--; it1--;
assert(it==it1);

std::cout<<"Map<double,int> copy construction Passed"<<std::endl;
auto m_copy=a;
assert(a==m_copy);

std::cout<<"Map<double,int> before erasing element Iterator"<<std::endl;

for(auto it2=a.begin();it2!=a.end();it2++)
std::cout<<it2.pos->key<<"  "<<it2.pos->value<<std::endl<<std::endl;
std::cout<<"Map<double,int> find() and erase() test"<<std::endl<<std::endl;
 auto it3=a.find(2010);
 a.erase(it3);

std::cout<<"Map after erasing key"<<std::endl<<std::endl<<std::endl;
for(auto it2=a.begin();it2!=a.end();it2++)
std::cout<<it2.pos->key<<"  "<<it2.pos->value<<std::endl<<std::endl;

std::cout<<"Map<double,int> clear() test"<<std::endl<<std::endl;


a.clear();

}

}
