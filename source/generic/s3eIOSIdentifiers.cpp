/*
Generic implementation of the s3eIOSIdentifiers extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eIOSIdentifiers_internal.h"
s3eResult s3eIOSIdentifiersInit()
{
    //Add any generic initialisation code here
    return s3eIOSIdentifiersInit_platform();
}

void s3eIOSIdentifiersTerminate()
{
    //Add any generic termination code here
    s3eIOSIdentifiersTerminate_platform();
}

s3eBool s3eIOSIdentifiersIsIDFATrackingEnabled()
{
	return s3eIOSIdentifiersIsIDFATrackingEnabled_platform();
}

const char* s3eIOSIdentifiersGetIDFA()
{
	return s3eIOSIdentifiersGetIDFA_platform();
}

const char* s3eIOSIdentifiersGetIDFV()
{
	return s3eIOSIdentifiersGetIDFV_platform();
}
