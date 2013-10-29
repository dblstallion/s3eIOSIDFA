#include "IwDebug.h"
#include "IwGx.h"
#include "s3eExt.h"
#include "s3eIOSIdentifiers.h"
#include "s3eOSReadString.h"
#include "s3ePointer.h"

// Example showing how to use the s3eIOSIdentifiers extension
int main()
{
    s3eDebugOutputString("Booting s3eIOSIdentifiers example");

    IwGxInit();
    IwGxSetColClear(0, 0, 0, 0xff);

    if (s3eIOSIdentifiersAvailable() != S3E_TRUE)
    {
        return 1;
    }

    while(!s3eDeviceCheckQuitRequest())
    {
        IwGxClear();

        const char *idfaString = "???";
        const char *idfvString = "???";

        IwGxPrintString(100, 100, "s3eIOSIDFA");
        IwGxPrintString(100, 300, s3eIOSIdentifiersIsIDFATrackingEnabled() ? "IDFA tracking ALLOWED" : "IDFA tracking NOT ALLOWED");
        IwGxPrintString(100, 400, "IDFA Value:");

        if (idfaString = s3eIOSIdentifiersGetIDFA())
        {
            IwGxPrintString(100, 500, idfaString);
        }

        IwGxPrintString(100, 600, "IDFV Value:");

        if (idfvString = s3eIOSIdentifiersGetIDFV())
        {
            IwGxPrintString(100, 700, idfvString);
        }

        IwGxFlush();
        IwGxSwapBuffers();
        s3eDeviceYield(0);
    }

    IwGxTerminate();
    return 0;
}