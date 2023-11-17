
#include "DataItem.h"

DataItem::DataItem(std::string origKey, std::string hashKey, std::string data)
    : originalKey(origKey), hashedKey(hashKey), data(data), next(nullptr), prev(nullptr) {}
