#include "DataRecord.h"
#include <sstream>
#include <iomanip>

DataRecord::DataRecord(const std::string& key, const std::vector<std::string>& fields)
    : primaryKey(key), dataFields(fields) {
    generateHashKey();
}

std::string DataRecord::getPrimaryKey()const {
    return primaryKey;
}

std::string DataRecord::getHashKey()const {
    return hashKey;
}

void DataRecord::generateHashKey() {

}

const std::vector<std::string>& DataRecord::getDataFields()const {
    return dataFields;
}