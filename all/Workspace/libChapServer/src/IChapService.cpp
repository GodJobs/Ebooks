/*
 * ChapService.cpp
 *
 *  Created on: 2013-5-10
 *      Author: lizhi
 */

#define LOG_TAG "IChapService"

#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <utils/Errors.h>
#include <utils/Log.h>
#include "IChapService.h"

namespace android {

enum {
    GET_COUNT = IBinder::FIRST_CALL_TRANSACTION
}
;

class DeathNotifier: public IBinder::DeathRecipient {
public:
    virtual void binderDied(const wp<IBinder>& who) {
        LOGI("binderDied who %p",who);
    }
};

class BpChapService: public BpInterface<IChapService> {
public:
    BpChapService(const sp<IBinder>& impl) :
            BpInterface<IChapService>(impl) {
        asBinder()->linkToDeath(new DeathNotifier);
    }
    virtual size_t getCount(size_t old) {
        LOGI("getCount old = %d", old);
        Parcel data, reply;
        data.writeInterfaceToken(IChapService::getInterfaceDescriptor());
        data.writeInt32(old);
        remote()->transact(GET_COUNT, data, &reply);
        size_t err = reply.errorCheck();
        if (NO_ERROR == err) {
            return reply.readInt32();
        }
        return -1;
    }
};

IMPLEMENT_META_INTERFACE(ChapService, "android.ccdt.ChapService");

status_t BnChapService::onTransact(uint32_t code, const Parcel& data,
        Parcel* reply, uint32_t flags) {
    switch (code) {
    case GET_COUNT: {
        CHECK_INTERFACE(IChapService, data, reply);
        size_t old = data.readInt32();
        reply->writeInt32(getCount(old));
    }
        break;
    default:
        break;
    }
    return NO_ERROR;
}

size_t BnChapService::getCount(size_t old) {
    LOGI("getCount old = %d", old);
    return ++old;
}
}

