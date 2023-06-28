#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>

class QueueFullException{
    public:
    std::string name = "QueueFullException"; 
    std::string what(){
        return "Excessão: " + this->name;
    }
};

class QueueEmptyException{
    public:
    std::string name = "QueueEmptyException";
    std::string what(){
        return "Excessão: " + this->name;
    }
};

class ItemNotFoundException{
    public:
    std::string name = "ItemNotFoundException"; 
    std::string what(){
        return "Excessão: " + this->name;
    }
};

class AlreadyExecuted{
    public:
    std::string name = "AlreadyExecuted"; 
    std::string what(){
        return "Excessão: " + this->name;
    }
};

#endif
