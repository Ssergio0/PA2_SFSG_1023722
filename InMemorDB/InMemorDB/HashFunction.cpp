#include "HashFunction.h"

unsigned long HashFunction::hash(const std::string& key) {
	unsigned long hash = 5381;
	for (char c : key)
		hash = ((hash << 5) + hash) + c;
	return hash;
}