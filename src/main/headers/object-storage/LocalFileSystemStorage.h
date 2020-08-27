/* 
 * File:   LocalFileSystemStorage.h
 *
 * Created on July 8, 2020, 2:05 AM
 */

#ifndef LOCALFILESYSTEMSTORAGE_H
#define LOCALFILESYSTEMSTORAGE_H

#include "../namespace.h"
#include "ObjectStorage.h"

class block_encfs::core::storage::LocalFileSystemStorage : public block_encfs::core::storage::ObjectStorage {
public:
    LocalFileSystemStorage();
    LocalFileSystemStorage(const LocalFileSystemStorage& orig);
    virtual ~LocalFileSystemStorage();

    virtual void put(std::string key, std::istream data);

    static LocalFileSystemStorage& openStorage(block_encfs::core::configuration::ObjectStorageConfiguration configuration);
private:

};

#endif /* LOCALFILESYSTEMSTORAGE_H */

