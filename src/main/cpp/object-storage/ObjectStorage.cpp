/* 
 * File:   ObjectStorage.cpp
 * 
 * Created on July 7, 2020, 11:56 PM
 */

#include <map>
#include <stdexcept>

#include "../../headers/object-storage/ObjectStorage.h"
#include "../../headers/object-storage/LocalFileSystemStorage.h"
#include "../../public/configuration/ObjectStorageConfiguration.h"

using std::map;
using std::string;
using std::out_of_range;

using block_encfs::core::configuration::ObjectStorageConfiguration;
using block_encfs::core::storage::ObjectStorage;
using block_encfs::core::storage::LocalFileSystemStorage;

ObjectStorage::ObjectStorage() {
}

ObjectStorage::ObjectStorage(const ObjectStorage& orig) {
}

ObjectStorage::~ObjectStorage() {
}

typedef ObjectStorage& (*STORAGE_FACTORY)(ObjectStorageConfiguration);
const map<string, STORAGE_FACTORY> STORAGE_IMPLEMENTATIONS = {
    {"local", (STORAGE_FACTORY) (&LocalFileSystemStorage::openStorage)}
    //    {"aws:s3", NULL}
};

ObjectStorage& block_encfs::core::storage::openStorage(ObjectStorageConfiguration configuration) {
    if (configuration.type.empty()) {
        throw "Object storage type is not specified";
    }

    STORAGE_FACTORY factory;
    try {
        factory = STORAGE_IMPLEMENTATIONS.at(configuration.type);
    } catch (out_of_range e) {
        throw "Storage type '" + configuration.type + "' is not known";
    }
    return (*factory)(configuration);
}
