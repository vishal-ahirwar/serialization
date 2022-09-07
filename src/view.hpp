#ifndef __VIEW__
#define __VIEW__
#include<iomanip>
#include"record.hpp"
#include<vector>
#include<iostream>

void displayRecords(std::vector<Record>&records)
{
  std::cout<<"ID"<<std::setw(25)<<"FirstName"<<std::setw(25)<<"LastName"<<std::setw(25)<<"balance\n\n";
  for(const Record&record:records)
  {
    std::cout<<record.account<<std::setw(25)<<record.firstName<<std::setw(25)<<record.lastName<<std::setw(25)<<record.balance<<"\n";
  };
};
#endif//view.hpp
