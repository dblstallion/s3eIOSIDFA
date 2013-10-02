s3eIOSIDFA
==========

A Marmalade extension to acess the advertising identifier (a.k.a. the IDFA) from iOS.

## Usage

1. Clone this whole folder into your project (or add it as a submodule)
2. Add "s3eIOSIDFA" to the subprojects section of your MKB file
3. Add `#include "s3eIOSIDFA.h"` to the source files where it will be used
4. Refer to the file `s3eIOSIDFA.h` for more information on the supplied functionality

##### Checking if tracking is enabled
```cpp
if (s3eIOSIDFAAvailable())
{
	return s3eIOSIDFAIsTrackingEnabled();
}
```

##### Getting the IDFA
```cpp
if (s3eIOSIDFAAvailable())
{
	return s3eIOSIDFAGetIDFA();
}
```

## Notes

* You're still allowed to use the IDFA for certain cases even if the user has disabled tracking
* Refer to the [ASIdentifierManager class reference][1] for more information

[1]: https://developer.apple.com/library/ios/documentation/AdSupport/Reference/ASIdentifierManager_Ref/ASIdentifierManager.html#//apple_ref/occ/instp/ASIdentifierManager/advertisingIdentifier
