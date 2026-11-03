/* Comet compatibility stubs. Return real CF objects so callers never message a null class. */
#import <CoreFoundation/CoreFoundation.h>

__attribute__((visibility("default"), used))
const char *SCErrorString(int status)
{
	(void)status;
	return "failed";
}

__attribute__((visibility("default"), used))
CFStringRef SCDynamicStoreKeyCreateProxies(CFAllocatorRef allocator)
{
	(void)allocator;
	return CFStringCreateWithCString(NULL, "State:/Network/Global/Proxies", kCFStringEncodingUTF8);
}

__attribute__((visibility("default"), used))
CFArrayRef SCNetworkInterfaceCopyAll(void)
{
	return CFArrayCreate(NULL, NULL, 0, &kCFTypeArrayCallBacks);
}

__attribute__((visibility("default"), used))
CFStringRef SCNetworkInterfaceGetBSDName(const void *interface)
{
	(void)interface;
	return CFStringCreateWithCString(NULL, "en0", kCFStringEncodingUTF8);
}

__attribute__((visibility("default"), used))
CFStringRef SCNetworkInterfaceGetHardwareAddressString(const void *interface)
{
	(void)interface;
	return CFStringCreateWithCString(NULL, "00:00:00:00:00:00", kCFStringEncodingUTF8);
}
