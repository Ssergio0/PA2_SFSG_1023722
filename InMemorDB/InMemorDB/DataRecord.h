#pragma once

#include<vector>
#include<string>

class DataRecord
{
private:
	std::string primaryKey;
	std::string hashKey;
	std::vector<std::string> dataFields;

public:
	DataRecord(const std::string& key, const std::vector<std::string>& fields);
	DataRecord(const DataRecord& other) = delete; // Prevenir copias
	DataRecord& operator=(const DataRecord& other) = delete; // Prevenir asignaciones
	std::string getPrimaryKey()const;
	std::string getHashKey() const;
	void generateHashKey();
	const std::vector<std::string>& getDataFields() const;
};

