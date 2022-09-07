#ifndef __SERIALIZER__
#define __SERIALIZER__
#include <cereal/archives/json.hpp>
#include<cereal/types/vector.hpp>
#include"record.hpp"

template<typename Archive>
void serialize(Archive&archive,Record&record)
{
  archive(cereal::make_nvp("Account",Record::id),cereal::make_nvp("firstName",record.firstName),cereal::make_nvp("lastName",record.lastName),cereal::make_nvp("balance",record.balance));
};
#endif//serializer.hpp
