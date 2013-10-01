/*
 * iphone-specific implementation of the s3eIOSIDFA extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eIOSIDFA_internal.h"

#import <AdSupport/ASIdentifierManager.h>

static NSString *idfaString = nil;

s3eResult s3eIOSIDFAInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void s3eIOSIDFATerminate_platform()
{
    // Add any platform-specific termination code here
    
    if (idfaString != nil)
    {
        [idfaString release];
        idfaString = nil;
    }
}

s3eBool s3eIOSIDFAIsTrackingEnabled_platform()
{
    ASIdentifierManager *adManager = [ASIdentifierManager sharedManager];

    if (adManager.advertisingTrackingEnabled)
    {
        return S3E_TRUE;
    }
    
    return S3E_FALSE;
}

const char *s3eIOSIDFAGetIDFA_platform()
{
    if (idfaString == nil)
    {
        ASIdentifierManager *adManager = [ASIdentifierManager sharedManager];
        idfaString = [adManager.advertisingIdentifier UUIDString];
        [idfaString retain];
    }

    return [idfaString UTF8String];
}
