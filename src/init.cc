#ifndef __INIT__
#define __INIT__
#include"record.hpp"
#include"view.hpp"
#include"serializer.hpp"
#include"input.hpp"
#include<fstream>
void init()
{
  INPUT input{INPUT::SERIALISE};
  std::vector<Record>records{};
  UserInput(input);
  switch(input)
  {
    case INPUT::SERIALISE:
    {
      auto write=[](std::vector<Record>&records)->void
      {
        getInput(records);
        displayRecords(records);

      if(std::ofstream archive{"records.json"})
      {
        cereal::JSONOutputArchive ouput(archive);
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
          cereal::JSONInputArchive input(archive);
          input(records);
          displayRecords(records);
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
