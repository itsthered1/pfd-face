AR = 'arm-none-eabi-ar'
ARFLAGS = 'rcs'
AS = 'arm-none-eabi-gcc'
BINDIR = '/usr/local/bin'
BLOCK_MESSAGE_KEYS = []
BUILD_DIR = 'basalt'
BUILD_TYPE = 'app'
BUNDLE_BIN_DIR = 'basalt'
BUNDLE_NAME = 'pfd-face.pbw'
CC = ['arm-none-eabi-gcc']
CCLNK_SRC_F = []
CCLNK_TGT_F = ['-o']
CC_NAME = 'gcc'
CC_SRC_F = []
CC_TGT_F = ['-c', '-o']
CC_VERSION = ('4', '7', '2')
CFLAGS = ['-std=c99', '-mcpu=cortex-m3', '-mthumb', '-ffunction-sections', '-fdata-sections', '-g', '-fPIE', '-Os', '-D_TIME_H_', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter', '-Wno-error=unused-function', '-Wno-error=unused-variable']
CFLAGS_MACBUNDLE = ['-fPIC']
CFLAGS_cshlib = ['-fPIC']
CPPPATH_ST = '-I%s'
DEFINES = ['RELEASE', 'PBL_PLATFORM_BASALT', 'PBL_COLOR', 'PBL_RECT', 'PBL_MICROPHONE', 'PBL_SMARTSTRAP', 'PBL_HEALTH', 'PBL_COMPASS', 'PBL_SMARTSTRAP_POWER', 'PBL_DISPLAY_WIDTH=144', 'PBL_DISPLAY_HEIGHT=168', 'PBL_SDK_3']
DEFINES_ST = '-D%s'
DEST_BINFMT = 'elf'
DEST_CPU = 'arm'
DEST_OS = 'linux'
INCLUDES = ['basalt']
LD = 'arm-none-eabi-ld'
LIBDIR = '/usr/local/lib'
LIBPATH_ST = '-L%s'
LIB_DIR = 'node_modules'
LIB_JSON = []
LIB_ST = '-l%s'
LINKFLAGS = ['-mcpu=cortex-m3', '-mthumb', '-Wl,--gc-sections', '-Wl,--warn-common', '-fPIE', '-Os']
LINKFLAGS_MACBUNDLE = ['-bundle', '-undefined', 'dynamic_lookup']
LINKFLAGS_cshlib = ['-shared']
LINKFLAGS_cstlib = ['-Wl,-Bstatic']
LINK_CC = ['arm-none-eabi-gcc']
MESSAGE_KEYS = {u'WIND_DIRECTION': 10003, u'CONDITIONS': 10002, u'TEMPERATURE': 10000, u'HUMIDITY': 10001}
MESSAGE_KEYS_DEFINITION = '/mnt/c/Users/Claudio/Desktop/pfd-face/build/src/message_keys.auto.c'
MESSAGE_KEYS_HEADER = '/mnt/c/Users/Claudio/Desktop/pfd-face/build/include/message_keys.auto.h'
MESSAGE_KEYS_JSON = '/mnt/c/Users/Claudio/Desktop/pfd-face/build/js/message_keys.json'
NODE_PATH = '/home/claudio/.pebble-sdk/SDKs/current/node_modules'
PEBBLE_SDK_COMMON = '/home/claudio/.pebble-sdk/SDKs/current/sdk-core/pebble/common'
PEBBLE_SDK_PLATFORM = '/home/claudio/.pebble-sdk/SDKs/current/sdk-core/pebble/basalt'
PEBBLE_SDK_ROOT = '/home/claudio/.pebble-sdk/SDKs/current/sdk-core/pebble'
PLATFORM = {'TAGS': ['basalt', 'color', 'rect', 'mic', 'strap', 'strappower', 'compass', 'health', '144w', '168h'], 'MAX_FONT_GLYPH_SIZE': 256, 'ADDITIONAL_TEXT_LINES_FOR_PEBBLE_H': [], 'MAX_APP_BINARY_SIZE': 65536, 'MAX_RESOURCES_SIZE': 1048576, 'MAX_APP_MEMORY_SIZE': 65536, 'MAX_WORKER_MEMORY_SIZE': 10240, 'NAME': 'basalt', 'BUNDLE_BIN_DIR': 'basalt', 'BUILD_DIR': 'basalt', 'MAX_RESOURCES_SIZE_APPSTORE': 262144, 'DEFINES': ['PBL_PLATFORM_BASALT', 'PBL_COLOR', 'PBL_RECT', 'PBL_MICROPHONE', 'PBL_SMARTSTRAP', 'PBL_HEALTH', 'PBL_COMPASS', 'PBL_SMARTSTRAP_POWER', 'PBL_DISPLAY_WIDTH=144', 'PBL_DISPLAY_HEIGHT=168']}
PLATFORM_NAME = 'basalt'
PREFIX = '/usr/local'
PROJECT_INFO = {'appKeys': {u'WIND_DIRECTION': 10003, u'CONDITIONS': 10002, u'TEMPERATURE': 10000, u'HUMIDITY': 10001}, u'watchapp': {u'watchface': True}, u'displayName': u'pfd-face', u'uuid': u'144b7a85-d8a5-4cb3-9329-c4401b89a4bd', u'messageKeys': {u'WIND_DIRECTION': 10003, u'CONDITIONS': 10002, u'TEMPERATURE': 10000, u'HUMIDITY': 10001}, 'companyName': u'MakeAwesomeHappen', u'enableMultiJS': True, u'sdkVersion': u'3', u'capabilities': [u'location'], 'versionLabel': u'1.0', u'targetPlatforms': [u'aplite', u'basalt', u'diorite'], 'longName': u'pfd-face', 'shortName': u'pfd-face', u'resources': {u'media': [{u'type': u'bitmap', u'name': u'IMAGE_BACKGROUND', u'file': u'images/background.png'}, {u'type': u'bitmap', u'name': u'IMAGE_WIND_DIRECTION', u'file': u'images/wind_direction.png'}]}, 'name': u'pfd-face'}
REQUESTED_PLATFORMS = [u'aplite', u'basalt', u'diorite']
RESOURCES_JSON = [{u'type': u'bitmap', u'name': u'IMAGE_BACKGROUND', u'file': u'images/background.png'}, {u'type': u'bitmap', u'name': u'IMAGE_WIND_DIRECTION', u'file': u'images/wind_direction.png'}]
RPATH_ST = '-Wl,-rpath,%s'
SANDBOX = False
SDK_VERSION_MAJOR = 5
SDK_VERSION_MINOR = 86
SHLIB_MARKER = None
SIZE = 'arm-none-eabi-size'
SONAME_ST = '-Wl,-h,%s'
STLIBPATH_ST = '-L%s'
STLIB_MARKER = None
STLIB_ST = '-l%s'
SUPPORTED_PLATFORMS = ['aplite', 'basalt', 'chalk', 'diorite', 'emery']
TARGET_PLATFORMS = ['diorite', 'basalt', 'aplite']
TIMESTAMP = 1658955626
USE_GROUPS = True
VERBOSE = 0
WEBPACK = '/home/claudio/.pebble-sdk/SDKs/current/node_modules/.bin/webpack'
cprogram_PATTERN = '%s'
cshlib_PATTERN = 'lib%s.so'
cstlib_PATTERN = 'lib%s.a'
macbundle_PATTERN = '%s.bundle'
