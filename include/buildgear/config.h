/* Buildgear static configuration */
#define VERSION                  "0.3 alpha"

#define ROOT_DIR                 ".buildgear"
#define BUILD_FILES_DIR          "buildfiles"
#define BUILD_FILES_HOST_DIR     BUILD_FILES_DIR "/host"
#define BUILD_FILES_TARGET_DIR   BUILD_FILES_DIR "/target"
#define BUILD_DIR                "build"
#define SOURCE_DIR               BUILD_DIR  "/source"
#define WORK_DIR                 BUILD_DIR  "/work"
#define PACKAGE_DIR              BUILD_DIR  "/package"


#define GLOBAL_CONFIG_FILE       "~/.buildgearconfig"
#define LOCAL_CONFIG_FILE        ROOT_DIR "/config"
#define BUILD_FILE               "Buildfile"

#define KEY_NAME                 "name"
#define KEY_VERSION              "version"
#define KEY_RELEASE              "release"
#define KEY_SOURCE               "source"
#define KEY_DEPENDS              "depends"

#define CONFIG_KEY_DEFAULT_NAME_PREFIX       "default_name_prefix"
#define CONFIG_KEY_BUILD_PARALLEL_LEVEL      "build_parallel_level"
#define CONFIG_KEY_DOWNLOAD_PARALLEL_LEVEL   "download_parallel_level"
#define CONFIG_KEY_SOURCE_DIR                "source_dir"
#define CONFIG_KEY_SOURCE_MIRROR             "source_mirror"
#define CONFIG_KEY_PACKAGE_COMPRESSION_LEVEL "package_compression_level"
#define CONFIG_KEY_IGNORE_CHECKSUM           "ignore_checksum"
#define CONFIG_KEY_IGNORE_FOOTPRINT          "ignore_footprint"

#define HOST                     0
#define TARGET                   1

#define TERMINFO_CIVIS           "\033[?25l"
#define TERMINFO_CNORM           "\033[?25h"

#define BUILD_SCRIPT             "/home/mgl/projects/buildgear/git/buildgear/buildgear.sh"