//============================================================================
// Name        : ChapClient.cpp
// Author      : ChapLee
// Version     :
// Copyright   : CCDT
// Description : Hello World in C++, Ansi-style
//============================================================================
//#include "STLInclude.h"

#define LOG_TAG "ChapServer"

#include <sys/types.h>
#include <unistd.h>
#include <grp.h>

#include <binder/IServiceManager.h>
#include "IChapService.h"
#include "ChapService.h"

#include <utils/Log.h>

int main() {
    using namespace android;
    // prints ChapServer
    LOGI("ChapClient");
    sp<IServiceManager> sm = defaultServiceManager();
    LOGI("IServiceManager sm =  %p", &sm);
    sp<IBinder> service = sm->getService(String16("cn.ccdt.ChapService"));
    sp<IChapService> cService = interface_cast<IChapService>(service);
    size_t count = cService->getCount(12);
    LOGI("ChapClient count  = %d", count);
    return 0;
}
