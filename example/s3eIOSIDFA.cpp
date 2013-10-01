#include "IwDebug.h"
#include "IwGx.h"
#include "s3eExt.h"
#include "s3eIOSIDFA.h"
#include "s3eOSReadString.h"
#include "s3ePointer.h"

// Example showing how to use the s3eIOSIDFA extension
int main()
{
    s3eDebugOutputString("Booting s3eIOSIDFA example");

    IwGxInit();
    IwGxSetColClear(0, 0, 0, 0xff);

    if (s3eIOSIDFAAvailable() != S3E_TRUE)
    {
        return 1;
    }

    while(!s3eDeviceCheckQuitRequest())
    {
        IwGxClear();

        const char *idfaString = "???";

        IwGxPrintString(100, 100, "s3eIOSIDFA");
        IwGxPrintString(100, 300, s3eIOSIDFAIsTrackingEnabled() ? "IDFA IS AVAILABLE" : "IDFA NOT AVAILABLE");
        IwGxPrintString(100, 500, "IDFA Value:");

        if (idfaString = s3eIOSIDFAGetIDFA())
        {
            IwGxPrintString(100, 600, idfaString);
        }

        IwGxFlush();
        IwGxSwapBuffers();
        s3eDeviceYield(0);
    }

    IwGxTerminate();
    return 0;
}