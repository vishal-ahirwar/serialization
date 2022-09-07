#ifndef __INPUT__
#define __INPUT__
#include<iostream>
#include<algorithm>
#include"record.hpp"

void getInput(std::vector<Record>&record)
{
  while(true)
  {

    Record rec{};
    std::cout<<"firstName : ";
    std::getline(std::cin,rec.firstName);
    std::cout<<"lastName  : ";
    std::getline(std::cin,rec.lastName);
    std::cout<<"balance   : ";
    std::cin>>rec.balance;
    record.push_back(rec);
    std::cout<<"Would you like to add More data [y/N] ";
    char input{};
    std::cin>>input;
    if(tolower(input)=='n')break;
    std::cin.clear();
    std::cin.ignore();
  };
};



void UserInput(INPUT&in)
{
  std::cout<<"Choose your option [read/write] ";
  std::string option{};
  std::getline(std::cin,option);
  std::transform(std::begin(option),std::end(option),std::begin(option),[](auto c){return tolower(c);});
  if((option)=="write")
  {
    in=INPUT::SERIALISE;
  }else if((option)=="read")
  {
    in=INPUT::DESERIALIZE;
  }else
  {
    std::cout<<"[error] : Invalid Input!\n";
    exit(1);
  }
};
#endif//input.hpp
