#include<sys/system_properties.h>

#include "apilevel.h"
#include "common.h"

#define SDK_LEVEL_KEY  "ro.build.version.sdk"

static int preferable_sdk_verion = -1;

int get_most_preferrable_level()
{
	// If we had one, return it.
	if(preferable_sdk_verion > 0) {
		return preferable_sdk_verion;
	}
	char value[PROP_VALUE_MAX] = {0};
	int length = __system_property_get(SDK_LEVEL_KEY, value);
	int version  = 0;
	L("Get %s returns %s", SDK_LEVEL_KEY, value);
	if(length > 0) {
		version = atoi(value);
	}

	int i =ARR_LEN(compiled_sdks) -1;
	for(; i > 0 ; i--) {
		if(compiled_sdks[i] <= version) {
			preferable_sdk_verion = compiled_sdks[i];
			break;
		}
	}
	return preferable_sdk_verion;
}
