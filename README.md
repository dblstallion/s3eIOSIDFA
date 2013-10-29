s3eIOSIdentifiers
=================

A Marmalade extension to acess the advertisingIdentifier and identifierForVendor (a.k.a. the IDFA and IDFV, respectively) from iOS.

## Usage

1. Clone this whole folder into your project (or add it as a submodule)
2. Add "s3eIOSIdentifiers" to the subprojects section of your MKB file
3. Add `#include "s3eIOSIdentifiers.h"` to the source files where it will be used
4. Refer to the file `s3eIOSIdentifiers.h` for more information on the supplied functionality

##### Checking if tracking is enabled
```cpp
if (s3eIOSIdentifiersAvailable())
{
	return s3eIOSIdentifiersIsIDFATrackingEnabled();
}
```

##### Getting the IDFA
```cpp
if (s3eIOSIdentifiersAvailable())
{
	return s3eIOSIdentifiersGetIDFA();
}
```

##### Getting the IDFV
```cpp
if (s3eIOSIdentifiersAvailable())
{
	return s3eIOSIdentifiersGetIDFV();
}
```

## Notes

* You're still allowed to use the IDFA for certain cases even if the user has disabled tracking
* Refer to the [ASIdentifierManager][1] and [UIDevice][2] class reference pages for more information

[1]: https://developer.apple.com/library/ios/documentation/AdSupport/Reference/ASIdentifierManager_Ref/ASIdentifierManager.html#//apple_ref/occ/instp/ASIdentifierManager/advertisingIdentifier
[2]: https://developer.apple.com/library/ios/documentation/UIKit/Reference/UIDevice_Class/Reference/UIDevice.html#//apple_ref/occ/instp/UIDevice/identifierForVendor
