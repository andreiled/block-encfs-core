/* 
 * File:   namespace.h
 *
 * Created on July 7, 2020, 11:53 PM
 */

#ifndef NAMESPACE_PRIVATE_H
#define NAMESPACE_PRIVATE_H

#include "../public/namespace.h"

namespace block_encfs {
    namespace core {
        namespace storage {
            class ObjectStorage;
            class LocalFileSystemStorage;
            ObjectStorage& openStorage(block_encfs::core::configuration::ObjectStorageConfiguration configuration);
        }
    }
}

#endif /* NAMESPACE_H */
