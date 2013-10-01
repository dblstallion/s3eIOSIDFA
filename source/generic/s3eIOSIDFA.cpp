/*
Generic implementation of the s3eIOSIDFA extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eIOSIDFA_internal.h"
s3eResult s3eIOSIDFAInit()
{
    //Add any generic initialisation code here
    return s3eIOSIDFAInit_platform();
}

void s3eIOSIDFATerminate()
{
    //Add any generic termination code here
    s3eIOSIDFATerminate_platform();
}

s3eBool s3eIOSIDFAIsTrackingEnabled()
{
	return s3eIOSIDFAIsTrackingEnabled_platform();
}

const char* s3eIOSIDFAGetIDFA()
{
	return s3eIOSIDFAGetIDFA_platform();
}
