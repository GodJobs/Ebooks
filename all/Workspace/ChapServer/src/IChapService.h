/*
 * IChapService.h
 *
 *  Created on: 2013-5-10
 *      Author: lizhi
 */

#ifndef ICHAPSERVICE_H_
#define ICHAPSERVICE_H_

#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <utils/Errors.h>

namespace android {

class IChapService: public android::IInterface {
public:
    DECLARE_META_INTERFACE(ChapService)
    ;
    virtual size_t getCount(size_t old) = 0;
};

class BnChapService: public BnInterface<IChapService> {
    virtual status_t onTransact(uint32_t code, const Parcel& data,
            Parcel* reply, uint32_t flags = 0);
};
}
#endif /* ICHAPSERVICE_H_ */
