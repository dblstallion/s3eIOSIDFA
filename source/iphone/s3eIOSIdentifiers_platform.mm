/*
 * iphone-specific implementation of the s3eIOSIdentifiers extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eIOSIdentifiers_internal.h"

#import <AdSupport/ASIdentifierManager.h>
#import <UIKit/UIKit.h>

static NSString *idfaString = nil;
static NSString *idfvString = nil;

s3eResult s3eIOSIdentifiersInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void s3eIOSIdentifiersTerminate_platform()
{
    // Add any platform-specific termination code here
    
    if (idfaString != nil)
    {
        [idfaString release];
        idfaString = nil;
    }
    
    if (idfvString != nil)
    {
        [idfvString release];
        idfvString = nil;
    }
}

s3eBool s3eIOSIdentifiersIsIDFATrackingEnabled_platform()
{
    ASIdentifierManager *adManager = [ASIdentifierManager sharedManager];
    
    if (adManager.advertisingTrackingEnabled)
    {
        return S3E_TRUE;
    }
    
    return S3E_FALSE;
}

const char* s3eIOSIdentifiersGetIDFA_platform()
{
    if (idfaString == nil)
    {
        ASIdentifierManager *adManager = [ASIdentifierManager sharedManager];
        idfaString = [adManager.advertisingIdentifier UUIDString];
        [idfaString retain];
    }
    
    return [idfaString UTF8String];
}

const char* s3eIOSIdentifiersGetIDFV_platform()
{
    if (idfvString == nil)
    {
        idfvString = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
        [idfvString retain];
    }
    
    return [idfvString UTF8String];
}
