//============================================================================
// Name        : ChapServer.cpp
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

#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "ChapService.h"

#include <utils/Log.h>
using namespace android;

int main() {
    // prints ChapServer
    LOGI("ChapServer");
    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm = defaultServiceManager();
    ChapService::instantiate();
    LOGI("ProcessState proc =  %p", &proc);
    LOGI("IServiceManager sm =  %p", &sm);
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}
