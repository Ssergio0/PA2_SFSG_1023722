#include "DataItem.h"

DataItem::DataItem(std::string key, std::string data)
	:keyPrimary(key), data(data), next(nullptr), prev(nullptr) {}
