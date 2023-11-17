#include "LinkedList.h"
#include <string>

class FileManager {
public:
    static int readFile(const std::string& filename, LinkedList& list);
};


