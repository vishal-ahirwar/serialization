#ifndef __RECORDS__
#define __RECORDS__
#include<iostream>
enum class INPUT:char{SERIALISE='r',DESERIALIZE='w'};
struct Record
{
  inline static size_t id;
  size_t account{id};
  std::string firstName;
  std::string lastName;
  double balance{};
  Record(){++id;};
};
#endif//record.hpp
