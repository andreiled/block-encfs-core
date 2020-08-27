/* 
 * File:   ObjectStorage.h
 *
 * Created on July 7, 2020, 11:56 PM
 */

#ifndef OBJECTSTORAGE_H
#define OBJECTSTORAGE_H

#include "../namespace.h"
#include <istream>

class block_encfs::core::storage::ObjectStorage {
public:
    ObjectStorage();
    ObjectStorage(const ObjectStorage& orig);
    virtual ~ObjectStorage();

    virtual void put(std::string key, std::istream data) = 0;
private:

};

#endif /* OBJECTSTORAGE_H */
