/*
 * ChapService.cpp
 *
 *  Created on: 2013-5-13
 *      Author: lizhi
 */
#define LOG_TAG "ChapService"

#include <binder/IServiceManager.h>
#include "ChapService.h"
#include <utils/Log.h>

namespace android {
ChapService::ChapService() {

}

ChapService::~ChapService() {
}

void ChapService::instantiate() {
    LOGI("ChapService::instantiate");
    defaultServiceManager()->addService(String16("cn.ccdt.ChapService"),
            new ChapService);
}

}
