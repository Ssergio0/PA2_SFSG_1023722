#include <string>

class DataItem {
public:
    std::string originalKey;
    std::string hashedKey;
    std::string data;
    DataItem* next;
    DataItem* prev;

    DataItem(std::string origKey, std::string hashKey, std::string data);
};

