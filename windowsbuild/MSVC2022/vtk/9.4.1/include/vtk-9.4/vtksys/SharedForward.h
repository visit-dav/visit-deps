/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing#kwsys for details.  */
#ifndef vtksys_SharedForward_h
#  define vtksys_SharedForward_h

/*
  This header is used to create a forwarding executable sets up the
  shared library search path and replaces itself with a real
  executable.  This is useful when creating installations on UNIX with
  shared libraries that will run from any install directory.  Typical
  usage:

  #if defined(CMAKE_INTDIR)
  # define CONFIG_DIR_PRE CMAKE_INTDIR "/"
  # define CONFIG_DIR_POST "/" CMAKE_INTDIR
  #else
  # define CONFIG_DIR_PRE ""
  # define CONFIG_DIR_POST ""
  #endif
  #define vtksys_SHARED_FORWARD_DIR_BUILD "/path/to/foo-build/bin"
  #define vtksys_SHARED_FORWARD_PATH_BUILD "." CONFIG_DIR_POST
  #define vtksys_SHARED_FORWARD_PATH_INSTALL "../lib/foo-1.2"
  #define vtksys_SHARED_FORWARD_EXE_BUILD CONFIG_DIR_PRE "foo-real"
  #define vtksys_SHARED_FORWARD_EXE_INSTALL
  "../lib/foo-1.2/foo-real"
  #define vtksys_SHARED_FORWARD_OPTION_COMMAND "--command"
  #define vtksys_SHARED_FORWARD_OPTION_PRINT "--print"
  #define vtksys_SHARED_FORWARD_OPTION_LDD "--ldd"
  #if defined(CMAKE_INTDIR)
  # define vtksys_SHARED_FORWARD_CONFIG_NAME CMAKE_INTDIR
  #endif
  #include <vtksys/SharedForward.h>
  int main(int argc, char** argv)
  {
    return vtksys_shared_forward_to_real(argc, argv);
  }

  Specify search and executable paths relative to the forwarding
  executable location or as full paths.  Include no trailing slash.
  In the case of a multi-configuration build, when CMAKE_INTDIR is
  defined, the DIR_BUILD setting should point at the directory above
  the executable (the one containing the per-configuration
  subdirectory specified by CMAKE_INTDIR).  Then PATH_BUILD entries
  and EXE_BUILD should be specified relative to this location and use
  CMAKE_INTDIR as necessary.  In the above example imagine appending
  the PATH_BUILD or EXE_BUILD setting to the DIR_BUILD setting.  The
  result should form a valid path with per-configuration subdirectory.

  Additional paths may be specified in the PATH_BUILD and PATH_INSTALL
  variables by using comma-separated strings.    For example:

  #define vtksys_SHARED_FORWARD_PATH_BUILD \
          "." CONFIG_DIR_POST, "/path/to/bar-build" CONFIG_DIR_POST
  #define vtksys_SHARED_FORWARD_PATH_INSTALL \
          "../lib/foo-1.2", "../lib/bar-4.5"

  See the comments below for specific explanations of each macro.
*/

/* Disable -Wcast-qual warnings since they are too hard to fix in a
   cross-platform way.  */
#  if defined(__clang__) && defined(__has_warning)
#    if __has_warning("-Wcast-qual")
#      pragma clang diagnostic push
#      pragma clang diagnostic ignored "-Wcast-qual"
#    endif
#  endif

/* Full path to the directory in which this executable is built.  Do
   not include a trailing slash.  */
#  if !defined(vtksys_SHARED_FORWARD_DIR_BUILD)
#    error "Must define vtksys_SHARED_FORWARD_DIR_BUILD"
#  endif
#  if !defined(KWSYS_SHARED_FORWARD_DIR_BUILD)
#    define KWSYS_SHARED_FORWARD_DIR_BUILD                                    \
      vtksys_SHARED_FORWARD_DIR_BUILD
#  endif

/* Library search path for build tree.  */
#  if !defined(vtksys_SHARED_FORWARD_PATH_BUILD)
#    error "Must define vtksys_SHARED_FORWARD_PATH_BUILD"
#  endif
#  if !defined(KWSYS_SHARED_FORWARD_PATH_BUILD)
#    define KWSYS_SHARED_FORWARD_PATH_BUILD                                   \
      vtksys_SHARED_FORWARD_PATH_BUILD
#  endif

/* Library search path for install tree.  */
#  if !defined(vtksys_SHARED_FORWARD_PATH_INSTALL)
#    error "Must define vtksys_SHARED_FORWARD_PATH_INSTALL"
#  endif
#  if !defined(KWSYS_SHARED_FORWARD_PATH_INSTALL)
#    define KWSYS_SHARED_FORWARD_PATH_INSTALL                                 \
      vtksys_SHARED_FORWARD_PATH_INSTALL
#  endif

/* The real executable to which to forward in the build tree.  */
#  if !defined(vtksys_SHARED_FORWARD_EXE_BUILD)
#    error "Must define vtksys_SHARED_FORWARD_EXE_BUILD"
#  endif
#  if !defined(KWSYS_SHARED_FORWARD_EXE_BUILD)
#    define KWSYS_SHARED_FORWARD_EXE_BUILD                                    \
      vtksys_SHARED_FORWARD_EXE_BUILD
#  endif

/* The real executable to which to forward in the install tree.  */
#  if !defined(vtksys_SHARED_FORWARD_EXE_INSTALL)
#    error "Must define vtksys_SHARED_FORWARD_EXE_INSTALL"
#  endif
#  if !defined(KWSYS_SHARED_FORWARD_EXE_INSTALL)
#    define KWSYS_SHARED_FORWARD_EXE_INSTALL                                  \
      vtksys_SHARED_FORWARD_EXE_INSTALL
#  endif

/* The configuration name with which this executable was built (Debug/Release).
 */
#  if defined(vtksys_SHARED_FORWARD_CONFIG_NAME)
#    define KWSYS_SHARED_FORWARD_CONFIG_NAME                                  \
      vtksys_SHARED_FORWARD_CONFIG_NAME
#  else
#    undef KWSYS_SHARED_FORWARD_CONFIG_NAME
#  endif

/* Create command line option to replace executable.  */
#  if defined(vtksys_SHARED_FORWARD_OPTION_COMMAND)
#    if !defined(KWSYS_SHARED_FORWARD_OPTION_COMMAND)
#      define KWSYS_SHARED_FORWARD_OPTION_COMMAND                             \
        vtksys_SHARED_FORWARD_OPTION_COMMAND
#    endif
#  else
#    undef KWSYS_SHARED_FORWARD_OPTION_COMMAND
#  endif

/* Create command line option to print environment setting and exit.  */
#  if defined(vtksys_SHARED_FORWARD_OPTION_PRINT)
#    if !defined(KWSYS_SHARED_FORWARD_OPTION_PRINT)
#      define KWSYS_SHARED_FORWARD_OPTION_PRINT                               \
        vtksys_SHARED_FORWARD_OPTION_PRINT
#    endif
#  else
#    undef KWSYS_SHARED_FORWARD_OPTION_PRINT
#  endif

/* Create command line option to run ldd or equivalent.  */
#  if defined(vtksys_SHARED_FORWARD_OPTION_LDD)
#    if !defined(KWSYS_SHARED_FORWARD_OPTION_LDD)
#      define KWSYS_SHARED_FORWARD_OPTION_LDD                                 \
        vtksys_SHARED_FORWARD_OPTION_LDD
#    endif
#  else
#    undef KWSYS_SHARED_FORWARD_OPTION_LDD
#  endif

/* Include needed system headers.  */

#  include <errno.h>
#  include <limits.h>
#  include <stddef.h> /* size_t */
#  include <stdio.h>
#  include <stdlib.h>
#  include <string.h>

#  if defined(_WIN32) && !defined(__CYGWIN__)
#    include <windows.h>

#    include <io.h>
#    include <process.h>
#    define KWSYS_SHARED_FORWARD_ESCAPE_ARGV /* re-escape argv for execvp */
#  else
#    include <sys/stat.h>
#    include <unistd.h>
#  endif

/* Configuration for this platform.  */

/* The path separator for this platform.  */
#  if defined(_WIN32) && !defined(__CYGWIN__)
#    define KWSYS_SHARED_FORWARD_PATH_SEP ';'
#    define KWSYS_SHARED_FORWARD_PATH_SLASH '\\'
#  else
#    define KWSYS_SHARED_FORWARD_PATH_SEP ':'
#    define KWSYS_SHARED_FORWARD_PATH_SLASH '/'
#  endif
static const char kwsys_shared_forward_path_sep[2] = {
  KWSYS_SHARED_FORWARD_PATH_SEP, 0
};
static const char kwsys_shared_forward_path_slash[2] = {
  KWSYS_SHARED_FORWARD_PATH_SLASH, 0
};

/* The maximum length of a file name.  */
#  if defined(PATH_MAX)
#    define KWSYS_SHARED_FORWARD_MAXPATH PATH_MAX
#  elif defined(MAXPATHLEN)
#    define KWSYS_SHARED_FORWARD_MAXPATH MAXPATHLEN
#  else
#    define KWSYS_SHARED_FORWARD_MAXPATH 16384
#  endif

/* Select the environment variable holding the shared library runtime
   search path for this platform and build configuration.  Also select
   ldd command equivalent.  */

/* Linux */
#  if defined(__linux)
#    define KWSYS_SHARED_FORWARD_LDD "ldd"
#    define KWSYS_SHARED_FORWARD_LDD_N 1
#    define KWSYS_SHARED_FORWARD_LDPATH "LD_LIBRARY_PATH"

/* FreeBSD */
#  elif defined(__FreeBSD__)
#    define KWSYS_SHARED_FORWARD_LDD "ldd"
#    define KWSYS_SHARED_FORWARD_LDD_N 1
#    define KWSYS_SHARED_FORWARD_LDPATH "LD_LIBRARY_PATH"

/* OpenBSD */
#  elif defined(__OpenBSD__)
#    define KWSYS_SHARED_FORWARD_LDD "ldd"
#    define KWSYS_SHARED_FORWARD_LDD_N 1
#    define KWSYS_SHARED_FORWARD_LDPATH "LD_LIBRARY_PATH"

/* OS X */
#  elif defined(__APPLE__)
#    define KWSYS_SHARED_FORWARD_LDD "otool", "-L"
#    define KWSYS_SHARED_FORWARD_LDD_N 2
#    define KWSYS_SHARED_FORWARD_LDPATH "DYLD_LIBRARY_PATH"

/* AIX */
#  elif defined(_AIX)
#    define KWSYS_SHARED_FORWARD_LDD "dump", "-H"
#    define KWSYS_SHARED_FORWARD_LDD_N 2
#    define KWSYS_SHARED_FORWARD_LDPATH "LIBPATH"

/* SUN */
#  elif defined(__sun)
#    define KWSYS_SHARED_FORWARD_LDD "ldd"
#    define KWSYS_SHARED_FORWARD_LDD_N 1
#    include <sys/isa_defs.h>
#    if defined(_ILP32)
#      define KWSYS_SHARED_FORWARD_LDPATH "LD_LIBRARY_PATH"
#    elif defined(_LP64)
#      define KWSYS_SHARED_FORWARD_LDPATH "LD_LIBRARY_PATH_64"
#    endif

/* HP-UX */
#  elif defined(__hpux)
#    define KWSYS_SHARED_FORWARD_LDD "chatr"
#    define KWSYS_SHARED_FORWARD_LDD_N 1
#    if defined(__LP64__)
#      define KWSYS_SHARED_FORWARD_LDPATH "LD_LIBRARY_PATH"
#    else
#      define KWSYS_SHARED_FORWARD_LDPATH "SHLIB_PATH"
#    endif

/* SGI MIPS */
#  elif defined(__sgi) && defined(_MIPS_SIM)
#    define KWSYS_SHARED_FORWARD_LDD "ldd"
#    define KWSYS_SHARED_FORWARD_LDD_N 1
#    if _MIPS_SIM == _ABIO32
#      define KWSYS_SHARED_FORWARD_LDPATH "LD_LIBRARY_PATH"
#    elif _MIPS_SIM == _ABIN32
#      define KWSYS_SHARED_FORWARD_LDPATH "LD_LIBRARYN32_PATH"
#    elif _MIPS_SIM == _ABI64
#      define KWSYS_SHARED_FORWARD_LDPATH "LD_LIBRARY64_PATH"
#    endif

/* Cygwin */
#  elif defined(__CYGWIN__)
#    define KWSYS_SHARED_FORWARD_LDD                                          \
      "cygcheck" /* TODO: cygwin 1.7 has ldd                                  \
                  */
#    define KWSYS_SHARED_FORWARD_LDD_N 1
#    define KWSYS_SHARED_FORWARD_LDPATH "PATH"

/* Windows */
#  elif defined(_WIN32)
#    define KWSYS_SHARED_FORWARD_LDPATH "PATH"

/* Guess on this unknown system.  */
#  else
#    define KWSYS_SHARED_FORWARD_LDD "ldd"
#    define KWSYS_SHARED_FORWARD_LDD_N 1
#    define KWSYS_SHARED_FORWARD_LDPATH "LD_LIBRARY_PATH"
#  endif

#  ifdef KWSYS_SHARED_FORWARD_ESCAPE_ARGV
typedef struct kwsys_sf_arg_info_s
{
  const char* arg;
  int size;
  int quote;
} kwsys_sf_arg_info;

static kwsys_sf_arg_info kwsys_sf_get_arg_info(const char* in)
{
  /* Initialize information.  */
  kwsys_sf_arg_info info;

  /* String iterator.  */
  const char* c;

  /* Keep track of how many backslashes have been encountered in a row.  */
  int windows_backslashes = 0;

  /* Start with the length of the original argument, plus one for
     either a terminating null or a separating space.  */
  info.arg = in;
  info.size = (int)strlen(in) + 1;
  info.quote = 0;

  /* Scan the string for characters that require escaping or quoting.  */
  for (c = in; *c; ++c) {
    /* Check whether this character needs quotes.  */
    if (strchr(" \t?'#&<>|^", *c)) {
      info.quote = 1;
    }

    /* On Windows only backslashes and double-quotes need escaping.  */
    if (*c == '\\') {
      /* Found a backslash.  It may need to be escaped later.  */
      ++windows_backslashes;
    } else if (*c == '"') {
      /* Found a double-quote.  We need to escape it and all
         immediately preceding backslashes.  */
      info.size += windows_backslashes + 1;
      windows_backslashes = 0;
    } else {
      /* Found another character.  This eliminates the possibility
         that any immediately preceding backslashes will be
         escaped.  */
      windows_backslashes = 0;
    }
  }

  /* Check whether the argument needs surrounding quotes.  */
  if (info.quote) {
    /* Surrounding quotes are needed.  Allocate space for them.  */
    info.size += 2;

    /* We must escape all ending backslashes when quoting on windows.  */
    info.size += windows_backslashes;
  }

  return info;
}

static char* kwsys_sf_get_arg(kwsys_sf_arg_info info, char* out)
{
  /* String iterator.  */
  const char* c;

  /* Keep track of how many backslashes have been encountered in a row.  */
  int windows_backslashes = 0;

  /* Whether the argument must be quoted.  */
  if (info.quote) {
    /* Add the opening quote for this argument.  */
    *out++ = '"';
  }

  /* Scan the string for characters that require escaping or quoting.  */
  for (c = info.arg; *c; ++c) {
    /* On Windows only backslashes and double-quotes need escaping.  */
    if (*c == '\\') {
      /* Found a backslash.  It may need to be escaped later.  */
      ++windows_backslashes;
    } else if (*c == '"') {
      /* Found a double-quote.  Escape all immediately preceding
         backslashes.  */
      while (windows_backslashes > 0) {
        --windows_backslashes;
        *out++ = '\\';
      }

      /* Add the backslash to escape the double-quote.  */
      *out++ = '\\';
    } else {
      /* We encountered a normal character.  This eliminates any
         escaping needed for preceding backslashes.  */
      windows_backslashes = 0;
    }

    /* Store this character.  */
    *out++ = *c;
  }

  if (info.quote) {
    /* Add enough backslashes to escape any trailing ones.  */
    while (windows_backslashes > 0) {
      --windows_backslashes;
      *out++ = '\\';
    }

    /* Add the closing quote for this argument.  */
    *out++ = '"';
  }

  /* Store a terminating null without incrementing.  */
  *out = 0;

  return out;
}
#  endif

/* Function to convert a logical or relative path to a physical full path.  */
static int kwsys_shared_forward_realpath(const char* in_path, char* out_path)
{
#  if defined(_WIN32) && !defined(__CYGWIN__)
  /* Implementation for Windows.  */
  DWORD n =
    GetFullPathNameA(in_path, KWSYS_SHARED_FORWARD_MAXPATH, out_path, 0);
  return n > 0 && n <= KWSYS_SHARED_FORWARD_MAXPATH;
#  else
  /* Implementation for UNIX.  */
  return realpath(in_path, out_path) != 0;
#  endif
}

static int kwsys_shared_forward_samepath(const char* file1, const char* file2)
{
#  if defined(_WIN32)
  int result = 0;
  HANDLE h1 = CreateFileA(file1, GENERIC_READ, FILE_SHARE_READ, NULL,
                          OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
  HANDLE h2 = CreateFileA(file2, GENERIC_READ, FILE_SHARE_READ, NULL,
                          OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
  if (h1 != INVALID_HANDLE_VALUE && h2 != INVALID_HANDLE_VALUE) {
    BY_HANDLE_FILE_INFORMATION fi1;
    BY_HANDLE_FILE_INFORMATION fi2;
    GetFileInformationByHandle(h1, &fi1);
    GetFileInformationByHandle(h2, &fi2);
    result = (fi1.dwVolumeSerialNumber == fi2.dwVolumeSerialNumber &&
              fi1.nFileIndexHigh == fi2.nFileIndexHigh &&
              fi1.nFileIndexLow == fi2.nFileIndexLow);
  }
  CloseHandle(h1);
  CloseHandle(h2);
  return result;
#  else
  struct stat fs1, fs2;
  return (stat(file1, &fs1) == 0 && stat(file2, &fs2) == 0 &&
          memcmp(&fs2.st_dev, &fs1.st_dev, sizeof(fs1.st_dev)) == 0 &&
          memcmp(&fs2.st_ino, &fs1.st_ino, sizeof(fs1.st_ino)) == 0 &&
          fs2.st_size == fs1.st_size);
#  endif
}

/* Function to report a system error message.  */
static void kwsys_shared_forward_strerror(char* message)
{
#  if defined(_WIN32) && !defined(__CYGWIN__)
  /* Implementation for Windows.  */
  DWORD original = GetLastError();
  DWORD length =
    FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                   0, original, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                   message, KWSYS_SHARED_FORWARD_MAXPATH, 0);
  if (length < 1 || length > KWSYS_SHARED_FORWARD_MAXPATH) {
    /* FormatMessage failed.  Use a default message.  */
    snprintf(message, KWSYS_SHARED_FORWARD_MAXPATH,
             "Error 0x%lX (FormatMessage failed with error 0x%lX)", original,
             GetLastError());
  }
#  else
  /* Implementation for UNIX.  */
  strcpy(message, strerror(errno));
#  endif
}

/* Functions to execute a child process.  */
static void kwsys_shared_forward_execvp(const char* cmd,
                                        char const* const* argv)
{
#  ifdef KWSYS_SHARED_FORWARD_ESCAPE_ARGV
  /* Count the number of arguments.  */
  int argc = 0;
  {
    char const* const* argvc;
    for (argvc = argv; *argvc; ++argvc, ++argc) {
    }
  }

  /* Create the escaped arguments.  */
  {
    char** nargv = (char**)malloc((argc + 1) * sizeof(char*));
    int i;
    for (i = 0; i < argc; ++i) {
      kwsys_sf_arg_info info = kwsys_sf_get_arg_info(argv[i]);
      nargv[i] = (char*)malloc(info.size);
      kwsys_sf_get_arg(info, nargv[i]);
    }
    nargv[argc] = 0;

    /* Replace the command line to be used.  */
    argv = (char const* const*)nargv;
  }
#  endif

/* Invoke the child process.  */
#  if defined(_MSC_VER)
  _execvp(cmd, argv);
#  elif defined(__MINGW32__) && !defined(__MINGW64__)
  execvp(cmd, argv);
#  else
  execvp(cmd, (char* const*)argv);
#  endif
}

/* Function to get the directory containing the given file or directory.  */
static void kwsys_shared_forward_dirname(const char* begin, char* result)
{
  /* Find the location of the last slash.  */
  int last_slash_index = -1;
  const char* end = begin + strlen(begin);
  for (; begin <= end && last_slash_index < 0; --end) {
    if (*end == '/' || *end == '\\') {
      last_slash_index = (int)(end - begin);
    }
  }

  /* Handle each case of the index of the last slash.  */
  if (last_slash_index < 0) {
    /* No slashes.  */
    strcpy(result, ".");
  } else if (last_slash_index == 0) {
    /* Only one leading slash.  */
    strcpy(result, kwsys_shared_forward_path_slash);
  }
#  if defined(_WIN32)
  else if (last_slash_index == 2 && begin[1] == ':') {
    /* Only one leading drive letter and slash.  */
    strncpy(result, begin, (size_t)last_slash_index);
    result[last_slash_index] = KWSYS_SHARED_FORWARD_PATH_SLASH;
    result[last_slash_index + 1] = 0;
  }
#  endif
  else {
    /* A non-leading slash.  */
    strncpy(result, begin, (size_t)last_slash_index);
    result[last_slash_index] = 0;
  }
}

/* Function to check if a file exists and is executable.  */
static int kwsys_shared_forward_is_executable(const char* f)
{
#  if defined(_MSC_VER)
#    define KWSYS_SHARED_FORWARD_ACCESS _access
#  else
#    define KWSYS_SHARED_FORWARD_ACCESS access
#  endif
#  if defined(X_OK)
#    define KWSYS_SHARED_FORWARD_ACCESS_OK X_OK
#  else
#    define KWSYS_SHARED_FORWARD_ACCESS_OK 04
#  endif
  if (KWSYS_SHARED_FORWARD_ACCESS(f, KWSYS_SHARED_FORWARD_ACCESS_OK) == 0) {
    return 1;
  } else {
    return 0;
  }
}

/* Function to locate the executable currently running.  */
static int kwsys_shared_forward_self_path(const char* argv0, char* result)
{
  /* Check whether argv0 has a slash.  */
  int has_slash = 0;
  const char* p = argv0;
  for (; *p && !has_slash; ++p) {
    if (*p == '/' || *p == '\\') {
      has_slash = 1;
    }
  }

  if (has_slash) {
    /* There is a slash.  Use the dirname of the given location.  */
    kwsys_shared_forward_dirname(argv0, result);
    return 1;
  } else {
    /* There is no slash.  Search the PATH for the executable.  */
    const char* path = getenv("PATH");
    const char* begin = path;
    const char* end = begin + (begin ? strlen(begin) : 0);
    const char* first = begin;
    while (first != end) {
      /* Store the end of this path entry.  */
      const char* last;

      /* Skip all path separators.  */
      for (; *first && *first == KWSYS_SHARED_FORWARD_PATH_SEP; ++first)
        ;

      /* Find the next separator.  */
      for (last = first; *last && *last != KWSYS_SHARED_FORWARD_PATH_SEP;
           ++last)
        ;

      /* If we got a non-empty directory, look for the executable there.  */
      if (first < last) {
        /* Determine the length without trailing slash.  */
        size_t length = (size_t)(last - first);
        if (*(last - 1) == '/' || *(last - 1) == '\\') {
          --length;
        }

        /* Construct the name of the executable in this location.  */
        strncpy(result, first, length);
        result[length] = KWSYS_SHARED_FORWARD_PATH_SLASH;
        strcpy(result + (length) + 1, argv0);

        /* Check if it exists and is executable.  */
        if (kwsys_shared_forward_is_executable(result)) {
          /* Found it.  */
          result[length] = 0;
          return 1;
        }
      }

      /* Move to the next directory in the path.  */
      first = last;
    }
  }

  /* We could not find the executable.  */
  return 0;
}

/* Function to convert a specified path to a full path.  If it is not
   already full, it is taken relative to the self path.  */
static int kwsys_shared_forward_fullpath(const char* self_path,
                                         const char* in_path, char* result,
                                         const char* desc)
{
  /* Check the specified path type.  */
  if (in_path[0] == '/') {
    /* Already a full path.  */
    strcpy(result, in_path);
  }
#  if defined(_WIN32)
  else if (in_path[0] && in_path[1] == ':') {
    /* Already a full path.  */
    strcpy(result, in_path);
  }
#  endif
  else {
    /* Relative to self path.  */
    char temp_path[KWSYS_SHARED_FORWARD_MAXPATH];
    strcpy(temp_path, self_path);
    strcat(temp_path, kwsys_shared_forward_path_slash);
    strcat(temp_path, in_path);
    if (!kwsys_shared_forward_realpath(temp_path, result)) {
      if (desc) {
        char msgbuf[KWSYS_SHARED_FORWARD_MAXPATH];
        kwsys_shared_forward_strerror(msgbuf);
        fprintf(stderr, "Error converting %s \"%s\" to real path: %s\n", desc,
                temp_path, msgbuf);
      }
      return 0;
    }
  }
  return 1;
}

/* Function to compute the library search path and executable name
   based on the self path.  */
static int kwsys_shared_forward_get_settings(const char* self_path,
                                             char* ldpath, char* exe)
{
  /* Possible search paths.  */
  static const char* search_path_build[] = { KWSYS_SHARED_FORWARD_PATH_BUILD,
                                             0 };
  static const char* search_path_install[] = {
    KWSYS_SHARED_FORWARD_PATH_INSTALL, 0
  };

  /* Chosen paths.  */
  const char** search_path;
  const char* exe_path;

/* Get the real name of the build and self paths.  */
#  if defined(KWSYS_SHARED_FORWARD_CONFIG_NAME)
  char build_path[] =
    KWSYS_SHARED_FORWARD_DIR_BUILD "/" KWSYS_SHARED_FORWARD_CONFIG_NAME;
  char self_path_logical[KWSYS_SHARED_FORWARD_MAXPATH];
#  else
  char build_path[] = KWSYS_SHARED_FORWARD_DIR_BUILD;
  const char* self_path_logical = self_path;
#  endif
  char build_path_real[KWSYS_SHARED_FORWARD_MAXPATH];
  char self_path_real[KWSYS_SHARED_FORWARD_MAXPATH];
  if (!kwsys_shared_forward_realpath(self_path, self_path_real)) {
    char msgbuf[KWSYS_SHARED_FORWARD_MAXPATH];
    kwsys_shared_forward_strerror(msgbuf);
    fprintf(stderr, "Error converting self path \"%s\" to real path: %s\n",
            self_path, msgbuf);
    return 0;
  }

  /* Check whether we are running in the build tree or an install tree.  */
  if (kwsys_shared_forward_realpath(build_path, build_path_real) &&
      kwsys_shared_forward_samepath(self_path_real, build_path_real)) {
    /* Running in build tree.  Use the build path and exe.  */
    search_path = search_path_build;
#  if defined(_WIN32)
    exe_path = KWSYS_SHARED_FORWARD_EXE_BUILD ".exe";
#  else
    exe_path = KWSYS_SHARED_FORWARD_EXE_BUILD;
#  endif

#  if defined(KWSYS_SHARED_FORWARD_CONFIG_NAME)
    /* Remove the configuration directory from self_path.  */
    kwsys_shared_forward_dirname(self_path, self_path_logical);
#  endif
  } else {
    /* Running in install tree.  Use the install path and exe.  */
    search_path = search_path_install;
#  if defined(_WIN32)
    exe_path = KWSYS_SHARED_FORWARD_EXE_INSTALL ".exe";
#  else
    exe_path = KWSYS_SHARED_FORWARD_EXE_INSTALL;
#  endif

#  if defined(KWSYS_SHARED_FORWARD_CONFIG_NAME)
    /* Use the original self path directory.  */
    strcpy(self_path_logical, self_path);
#  endif
  }

  /* Construct the runtime search path.  */
  {
    const char** dir;
    for (dir = search_path; *dir; ++dir) {
      /* Add separator between path components.  */
      if (dir != search_path) {
        strcat(ldpath, kwsys_shared_forward_path_sep);
      }

      /* Add this path component.  */
      if (!kwsys_shared_forward_fullpath(self_path_logical, *dir,
                                         ldpath + strlen(ldpath),
                                         "runtime path entry")) {
        return 0;
      }
    }
  }

  /* Construct the executable location.  */
  if (!kwsys_shared_forward_fullpath(self_path_logical, exe_path, exe,
                                     "executable file")) {
    return 0;
  }
  return 1;
}

/* Function to print why execution of a command line failed.  */
static void kwsys_shared_forward_print_failure(char const* const* argv)
{
  char msg[KWSYS_SHARED_FORWARD_MAXPATH];
  char const* const* arg = argv;
  kwsys_shared_forward_strerror(msg);
  fprintf(stderr, "Error running");
  for (; *arg; ++arg) {
    fprintf(stderr, " \"%s\"", *arg);
  }
  fprintf(stderr, ": %s\n", msg);
}

/* Static storage space to store the updated environment variable.  */
static char kwsys_shared_forward_ldpath[65535] =
  KWSYS_SHARED_FORWARD_LDPATH "=";

/* Main driver function to be called from main.  */
static int vtksys_shared_forward_to_real(int argc, char** argv_in)
{
  char const** argv = (char const**)argv_in;
  /* Get the directory containing this executable.  */
  char self_path[KWSYS_SHARED_FORWARD_MAXPATH];
  if (kwsys_shared_forward_self_path(argv[0], self_path)) {
    /* Found this executable.  Use it to get the library directory.  */
    char exe[KWSYS_SHARED_FORWARD_MAXPATH];
    if (kwsys_shared_forward_get_settings(self_path,
                                          kwsys_shared_forward_ldpath, exe)) {
      /* Append the old runtime search path.  */
      const char* old_ldpath = getenv(KWSYS_SHARED_FORWARD_LDPATH);
      if (old_ldpath) {
        strcat(kwsys_shared_forward_ldpath, kwsys_shared_forward_path_sep);
        strcat(kwsys_shared_forward_ldpath, old_ldpath);
      }

      /* Store the environment variable.  */
      putenv(kwsys_shared_forward_ldpath);

#  if defined(KWSYS_SHARED_FORWARD_OPTION_COMMAND)
      /* Look for the command line replacement option.  */
      if (argc > 1 &&
          strcmp(argv[1], KWSYS_SHARED_FORWARD_OPTION_COMMAND) == 0) {
        if (argc > 2) {
          /* Use the command line given.  */
          strcpy(exe, argv[2]);
          argv += 2;
          argc -= 2;
        } else {
          /* The option was not given an executable.  */
          fprintf(stderr,
                  "Option " KWSYS_SHARED_FORWARD_OPTION_COMMAND
                  " must be followed by a command line.\n");
          return 1;
        }
      }
#  endif

#  if defined(KWSYS_SHARED_FORWARD_OPTION_PRINT)
      /* Look for the print command line option.  */
      if (argc > 1 &&
          strcmp(argv[1], KWSYS_SHARED_FORWARD_OPTION_PRINT) == 0) {
        fprintf(stdout, "%s\n", kwsys_shared_forward_ldpath);
        fprintf(stdout, "%s\n", exe);
        return 0;
      }
#  endif

#  if defined(KWSYS_SHARED_FORWARD_OPTION_LDD)
      /* Look for the ldd command line option.  */
      if (argc > 1 && strcmp(argv[1], KWSYS_SHARED_FORWARD_OPTION_LDD) == 0) {
#    if defined(KWSYS_SHARED_FORWARD_LDD)
        /* Use the named ldd-like executable and arguments.  */
        char const* ldd_argv[] = { KWSYS_SHARED_FORWARD_LDD, 0, 0 };
        ldd_argv[KWSYS_SHARED_FORWARD_LDD_N] = exe;
        kwsys_shared_forward_execvp(ldd_argv[0], ldd_argv);

        /* Report why execution failed.  */
        kwsys_shared_forward_print_failure(ldd_argv);
        return 1;
#    else
        /* We have no ldd-like executable available on this platform.  */
        fprintf(stderr, "No ldd-like tool is known to this executable.\n");
        return 1;
#    endif
      }
#  endif

      /* Replace this process with the real executable.  */
      argv[0] = exe;
      kwsys_shared_forward_execvp(argv[0], argv);

      /* Report why execution failed.  */
      kwsys_shared_forward_print_failure(argv);
    } else {
      /* Could not convert self path to the library directory.  */
    }
  } else {
    /* Could not find this executable.  */
    fprintf(stderr, "Error locating executable \"%s\".\n", argv[0]);
  }

  /* Avoid unused argument warning.  */
  (void)argc;

  /* Exit with failure.  */
  return 1;
}

/* Restore warning stack.  */
#  if defined(__clang__) && defined(__has_warning)
#    if __has_warning("-Wcast-qual")
#      pragma clang diagnostic pop
#    endif
#  endif

#else
#  error "vtksys/SharedForward.h should be included only once."
#endif
