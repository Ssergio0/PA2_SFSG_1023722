#include <string>
#include<vector>

class FileManager {
private:
    std::string primaryKey;
    std::vector<std::string>datos;
    std::string nextKey;

public:
    FileManager(const std::string& linea);
    std::string getPrimaryKey() const;
    std::string getNextKey()const;

    void showData()const;
    bool searchSequentialValue(const std::string& valor)const;
};
