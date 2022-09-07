#ifndef __INIT__
#define __INIT__
#include"record.hpp"
#include"view.hpp"
#include"serializer.hpp"
#include"input.hpp"
#include<fstream>
void init()
{
  INPUT input{INPUT::SERIALISE};//record.hpp
  std::vector<Record>records{};//record.hpp
  UserInput(input);//input.hpp
  switch(input)
  {
    case INPUT::SERIALISE:
    {
      auto write=[](std::vector<Record>&records)->void
      {
        getInput(records);//input.hpp
        displayRecords(records);//view.hpp

      if(std::ofstream archive{"records.json"})
      {
        cereal::JSONOutputArchive ouput(archive);//serializer.hpp
        ouput(cereal::make_nvp("records",records));
      };
    };

    write(records);
      break;
    };
    case INPUT::DESERIALIZE:
    {
      auto read=[](std::vector<Record>&records)->void
      {
        if(std::ifstream archive{"records.json"})
        {
          cereal::JSONInputArchive input(archive);//serializer.hpp
          input(records);
          displayRecords(records);//view.hpp
        }else
        {
          std::cout<<"[error] failed to find records file!\n";
        };
      };
      read(records);
      break;
    };
  };
};
#endif//init.hpp
