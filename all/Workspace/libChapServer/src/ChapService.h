/*
 * ChapService.h
 *
 *  Created on: 2013-5-13
 *      Author: lizhi
 */

#ifndef CHAPSERVICE_H_
#define CHAPSERVICE_H_

#include "IChapService.h"
namespace android {
class ChapService: public android::BnChapService {
public:
    ChapService();
    static void instantiate();
    virtual ~ChapService();
};
}
#endif /* CHAPSERVICE_H_ */
