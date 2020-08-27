/* 
 * File:   LocalFileSystemStorage.cpp
 * 
 * Created on July 8, 2020, 2:05 AM
 */

#include <istream>

#include "../../headers/object-storage/LocalFileSystemStorage.h"
#include "../../public/configuration/ObjectStorageConfiguration.h"

using std::string;
using std::istream;

using block_encfs::core::configuration::ObjectStorageConfiguration;
using block_encfs::core::storage::LocalFileSystemStorage;

LocalFileSystemStorage::LocalFileSystemStorage() {
}

LocalFileSystemStorage::LocalFileSystemStorage(const LocalFileSystemStorage& orig) {
}

LocalFileSystemStorage::~LocalFileSystemStorage() {
}

LocalFileSystemStorage& LocalFileSystemStorage::openStorage(ObjectStorageConfiguration configuration) {
    return *(new LocalFileSystemStorage());
}

void LocalFileSystemStorage::put(string key, istream data) {

}
