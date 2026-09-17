#include <SystemConfiguration/SystemConfiguration.h>
#include <CoreFoundation/CFRuntime.h>
#include <stdarg.h>
#include <pthread.h>
#include <string.h>

#define STUB() printf("STUB %s\n", __func__)

const CFStringRef kSCDynamicStoreUseSessionKeys = CFSTR("UseSessionKeys");

struct __SCDynamicStore {
	CFRuntimeBase _base;
	CFArrayRef keys;
	CFArrayRef patterns;
};

static CFTypeID __kSCDynamicStoreTypeID = _kCFRuntimeNotATypeID;

static void
__SCDynamicStoreDeallocate(CFTypeRef cf)
{
	struct __SCDynamicStore *store = (struct __SCDynamicStore *)cf;
	if (store->keys) {
		CFRelease(store->keys);
		store->keys = NULL;
	}
	if (store->patterns) {
		CFRelease(store->patterns);
		store->patterns = NULL;
	}
}

static const CFRuntimeClass __SCDynamicStoreClass = {
	0,
	"SCDynamicStore",
	NULL,
	NULL,
	__SCDynamicStoreDeallocate,
	NULL,
	NULL,
	NULL,
	NULL
};

static void
__SCDynamicStoreInitialize(void)
{
	__kSCDynamicStoreTypeID = _CFRuntimeRegisterClass(&__SCDynamicStoreClass);
}

CFTypeID
SCDynamicStoreGetTypeID(void)
{
	static pthread_once_t once = PTHREAD_ONCE_INIT;
	pthread_once(&once, __SCDynamicStoreInitialize);
	return __kSCDynamicStoreTypeID;
}

static SCDynamicStoreRef
__SCDynamicStoreCreateInstance(CFAllocatorRef allocator)
{
	struct __SCDynamicStore *store;
	CFTypeID typeID = SCDynamicStoreGetTypeID();
	if (typeID == _kCFRuntimeNotATypeID) {
		return NULL;
	}
	store = (struct __SCDynamicStore *)_CFRuntimeCreateInstance(allocator, typeID,
	    sizeof(struct __SCDynamicStore) - sizeof(CFRuntimeBase), NULL);
	return (SCDynamicStoreRef)store;
}

static void
__SCDynamicStoreRLSPerform(void *info)
{
	(void)info;
}

CFTypeID SCNetworkConnectionGetTypeID(void)
{
    STUB();
	return 0;
}

Boolean SCNetworkConnectionScheduleWithRunLoop(SCNetworkConnectionRef ref, CFRunLoopRef rl, CFStringRef rlMode)
{
    STUB();
	return 0;
}

Boolean SCNetworkConnectionUnscheduleFromRunLoop(SCNetworkConnectionRef ref, CFRunLoopRef rl, CFStringRef rlMode)
{
    STUB();
	return 0;
}

Boolean SCNetworkConnectionStop(SCNetworkConnectionRef ref, Boolean force)
{
    STUB();
	return 0;
}

Boolean SCNetworkConnectionStart(SCNetworkConnectionRef ref, CFDictionaryRef userOptions, Boolean linger)
{
    STUB();
	return 0;
}

Boolean
SCNetworkConnectionCopyUserPreferences		(
						CFDictionaryRef				  __nullable	selectionOptions,
						CFStringRef		__nonnull	* __nullable	serviceID,
						CFDictionaryRef		__nonnull	* __nullable	userOptions
						)			__OSX_AVAILABLE_STARTING(__MAC_10_3,__IPHONE_NA) {
    STUB();
	return 0;
}

SCNetworkConnectionRef SCNetworkConnectionCreateWithServiceID(CFAllocatorRef allocator, CFStringRef serviceID, SCNetworkConnectionCallBack cb, SCNetworkConnectionContext* ctxt)
{
    STUB();
	return NULL;
}

struct __SCNetworkReachability {
	CFRuntimeBase _base;
};

static CFTypeID __kSCNetworkReachabilityTypeID = _kCFRuntimeNotATypeID;

static const CFRuntimeClass __SCNetworkReachabilityClass = {
	0,
	"SCNetworkReachability",
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

static void
__SCNetworkReachabilityInitialize(void)
{
	__kSCNetworkReachabilityTypeID = _CFRuntimeRegisterClass(&__SCNetworkReachabilityClass);
}

CFTypeID SCNetworkReachabilityGetTypeID(void)
{
	static pthread_once_t once = PTHREAD_ONCE_INIT;
	pthread_once(&once, __SCNetworkReachabilityInitialize);
	return __kSCNetworkReachabilityTypeID;
}

static SCNetworkReachabilityRef
__SCNetworkReachabilityCreate(CFAllocatorRef allocator)
{
	CFTypeID typeID = SCNetworkReachabilityGetTypeID();
	if (typeID == _kCFRuntimeNotATypeID) {
		return NULL;
	}
	return (SCNetworkReachabilityRef)_CFRuntimeCreateInstance(allocator, typeID, 0, NULL);
}

Boolean SCNetworkReachabilityScheduleWithRunLoop(SCNetworkReachabilityRef ref, CFRunLoopRef rl, CFStringRef rlMode)
{
	(void)ref;
	(void)rl;
	(void)rlMode;
	return TRUE;
}

Boolean SCNetworkReachabilityUnscheduleFromRunLoop(SCNetworkReachabilityRef ref, CFRunLoopRef rl, CFStringRef rlMode)
{
	(void)ref;
	(void)rl;
	(void)rlMode;
	return TRUE;
}

Boolean SCNetworkReachabilitySetCallback(SCNetworkReachabilityRef target, SCNetworkReachabilityCallBack cb, SCNetworkReachabilityContext* ctxt)
{
	(void)target;
	(void)cb;
	(void)ctxt;
	return TRUE;
}

Boolean SCNetworkReachabilityGetFlags(SCNetworkReachabilityRef target, SCNetworkReachabilityFlags* flags)
{
	(void)target;
	if (flags) {
		*flags = kSCNetworkReachabilityFlagsReachable;
	}
	return TRUE;
}

SCNetworkReachabilityRef SCNetworkReachabilityCreateWithName(CFAllocatorRef allocator, const char* nodeName)
{
	(void)nodeName;
	return __SCNetworkReachabilityCreate(allocator);
}

SCNetworkReachabilityRef SCNetworkReachabilityCreateWithAddressPair(CFAllocatorRef allocator, const struct sockaddr* localAddress, const struct sockaddr* remoteAddress)
{
	(void)localAddress;
	(void)remoteAddress;
	return __SCNetworkReachabilityCreate(allocator);
}

SCNetworkReachabilityRef SCNetworkReachabilityCreateWithAddress(CFAllocatorRef allocator, const struct sockaddr* remoteAddress)
{
	(void)remoteAddress;
	return __SCNetworkReachabilityCreate(allocator);
}

CFStringRef
SCDynamicStoreKeyCreate(CFAllocatorRef allocator, CFStringRef fmt, ...)
{
	va_list args;
	CFStringRef result;

	va_start(args, fmt);
	result = CFStringCreateWithFormatAndArguments(allocator, NULL, fmt, args);
	va_end(args);
	return result;
}

CFStringRef
SCDynamicStoreKeyCreateNetworkGlobalEntity(CFAllocatorRef allocator, CFStringRef domain, CFStringRef entity)
{
	return CFStringCreateWithFormat(allocator, NULL, CFSTR("%@/%@/%@/%@"),
	    domain, kSCCompNetwork, kSCCompGlobal, entity);
}

CFStringRef
SCDynamicStoreKeyCreateNetworkInterfaceEntity(CFAllocatorRef allocator, CFStringRef domain, CFStringRef ifname, CFStringRef entity)
{
	if (entity == NULL) {
		return CFStringCreateWithFormat(allocator, NULL, CFSTR("%@/%@/%@/%@"),
		    domain, kSCCompNetwork, kSCCompInterface, ifname);
	}
	return CFStringCreateWithFormat(allocator, NULL, CFSTR("%@/%@/%@/%@/%@"),
	    domain, kSCCompNetwork, kSCCompInterface, ifname, entity);
}

CFStringRef
SCDynamicStoreKeyCreateComputerName(CFAllocatorRef allocator)
{
	return SCDynamicStoreKeyCreate(allocator, CFSTR("%@/%@"),
	    kSCDynamicStoreDomainSetup, kSCCompSystem);
}

CFStringRef
SCDynamicStoreKeyCreateHostNames(CFAllocatorRef allocator)
{
	return SCDynamicStoreKeyCreate(allocator, CFSTR("%@/%@/%@"),
	    kSCDynamicStoreDomainSetup, kSCCompNetwork, kSCCompHostNames);
}

CFStringRef
SCDynamicStoreKeyCreateProxies(CFAllocatorRef allocator)
{
	return SCDynamicStoreKeyCreateNetworkGlobalEntity(allocator,
	    kSCDynamicStoreDomainState, kSCEntNetProxies);
}

CFPropertyListRef
SCDynamicStoreCopyValue(SCDynamicStoreRef store, CFStringRef key)
{
	CFStringRef expected;
	Boolean match;

	(void)store;
	if (key == NULL) {
		return NULL;
	}

	expected = SCDynamicStoreKeyCreateNetworkGlobalEntity(NULL,
	    kSCDynamicStoreDomainState, kSCEntNetIPv4);
	match = (expected != NULL) && CFEqual(key, expected);
	if (expected) {
		CFRelease(expected);
	}
	if (!match) {
		return NULL;
	}

	{
		CFStringRef addr = CFSTR("127.0.0.1");
		CFArrayRef addrs = CFArrayCreate(NULL, (const void **)&addr, 1, &kCFTypeArrayCallBacks);
		CFStringRef dictKey = kSCPropNetIPv4Addresses;
		CFDictionaryRef dict = CFDictionaryCreate(NULL,
		    (const void **)&dictKey, (const void **)&addrs, 1,
		    &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
		if (addrs) {
			CFRelease(addrs);
		}
		return dict;
	}
}

SCDynamicStoreRef
SCDynamicStoreCreate(CFAllocatorRef allocator, CFStringRef name, SCDynamicStoreCallBack callout, SCDynamicStoreContext *context)
{
	(void)name;
	(void)callout;
	(void)context;
	return __SCDynamicStoreCreateInstance(allocator);
}

SCDynamicStoreRef __nullable
SCDynamicStoreCreateWithOptions(CFAllocatorRef __nullable allocator, CFStringRef name, CFDictionaryRef __nullable storeOptions, SCDynamicStoreCallBack __nullable callout, SCDynamicStoreContext* __nullable context)
{
	(void)storeOptions;
	return SCDynamicStoreCreate(allocator, name, callout, context);
}

CFRunLoopSourceRef
SCDynamicStoreCreateRunLoopSource(CFAllocatorRef allocator, SCDynamicStoreRef store, CFIndex order)
{
	CFRunLoopSourceContext ctx;

	if (store == NULL) {
		return NULL;
	}

	memset(&ctx, 0, sizeof(ctx));
	ctx.version = 0;
	ctx.perform = __SCDynamicStoreRLSPerform;
	return CFRunLoopSourceCreate(allocator, order, &ctx);
}

Boolean
SCDynamicStoreSetDispatchQueue(SCDynamicStoreRef store, dispatch_queue_t queue)
{
	(void)store;
	(void)queue;
	return TRUE;
}

Boolean
SCDynamicStoreSetNotificationKeys(SCDynamicStoreRef store, CFArrayRef __nullable keys, CFArrayRef __nullable patterns)
{
	struct __SCDynamicStore *storePrivate = (struct __SCDynamicStore *)store;

	if (storePrivate == NULL) {
		return FALSE;
	}

	if (storePrivate->keys) {
		CFRelease(storePrivate->keys);
		storePrivate->keys = NULL;
	}
	if (storePrivate->patterns) {
		CFRelease(storePrivate->patterns);
		storePrivate->patterns = NULL;
	}
	if (keys) {
		storePrivate->keys = CFArrayCreateCopy(NULL, keys);
	}
	if (patterns) {
		storePrivate->patterns = CFArrayCreateCopy(NULL, patterns);
	}
	return TRUE;
}

Boolean SCPreferencesSetComputerName(SCPreferencesRef	prefs, CFStringRef __nullable	name, CFStringEncoding	nameEncoding) {
	STUB();
	return FALSE;
};

Boolean SCPreferencesSetLocalHostName(SCPreferencesRef	prefs, CFStringRef __nullable	name) {
	STUB();
	return FALSE;
};

const char *SCErrorString(int status)
{
	(void)status;
	return "SCError";
}

CFArrayRef SCNetworkInterfaceCopyAll(void)
{
	STUB();
	return NULL;
}

CFStringRef __nullable
SCNetworkInterfaceGetBSDName(SCNetworkInterfaceRef interface)
{
	(void)interface;
	return NULL;
}

CFStringRef __nullable
SCNetworkInterfaceGetHardwareAddressString(SCNetworkInterfaceRef interface)
{
	(void)interface;
	return NULL;
}
