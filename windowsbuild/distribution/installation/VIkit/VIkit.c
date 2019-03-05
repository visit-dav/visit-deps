/*****************************************************************************
*
* Copyright (c) 2000 - 2009, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-400124
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <direct.h>
#include <exdll\exdll.h>
#include <vector>
#include <string>
#include <shlobj.h>
using std::vector;
using std::string;
typedef vector<int> intVector;
typedef vector<intVector> intIntVector;

/* For VisIt 1.9.0 and above:
 * Assumes NSIS is installed in C:\Program Files\NSIS and that the "exdll"
 * directory is available in NSIS's Contrib directory.  If not, the MSVC
 * project file will need to be modified.  
 * Open the solution file and build the Release version
 */

/* For VisIt versions below 1.9.0:
 * Copy the VIkit directory to the Contrib directory where NSIS was installed
 * (typically C:\Program Files\NSIS\Contrib) and build the VIkit project to
 * create the VIkit DLL. Be sure to build in Release mode. 
 *
 * Once VIkit.dll is built, copy it into NSIS's Plugins directory
 * (typically C:\Program Files\NSIS\Plugins).
 */

/* Uncomment these definitions if you need to debug the functions.
#define DEBUG_ReplaceStringInFileEx
#define DEBUG_VisItPath
#define DEBUG_FindVisItInPath
#define DEBUG_RemoveAllVisItInPath
*/


/******************************************************************************
 *
 * Purpose: Finds the users' home directory.
 *
 * Programmer: Kathleen Bonnell 
 * Date:       November 6, 2008
 *
 * Modifications:
 *   Kathleen Bonnell, Fri Nov 7 15:48:57 PST 2008
 *   GetUserProfileDirectory requires user name, so use SHGetFolderPath 
 *   instead.
 *
 *****************************************************************************/
string
GetUserHomeDir()
{
    char *profPath = new char[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, profPath)))
        return string(profPath);
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_PROFILE, NULL, SHGFP_TYPE_CURRENT, profPath)))
        return string(profPath);
    return string("C:\\");
}

/******************************************************************************
 *
 * Purpose: Replaces a string in a file and resaves the file.
 *
 * Programmer: Brad Whitlock
 * Date:       Thu Mar 16 11:43:23 PDT 2006
 *
 * Modifications:
 *   Kathleen Bonnell, Wed Oct 8 18:18:33 PDT 2008
 *   Removed reference to 'VisItDev' in the location of the log file.
 *
 *   Kathleen Bonnell, Fri Nov 7 15:50:12 PST 2008
 *   Retrieve users' home dir for location of log file.
 *
 *****************************************************************************/

static void
ReplaceStringInFileEx(const char *filename, const char *S, const char *R)
{
    FILE *src = NULL;
#ifdef DEBUG_ReplaceStringInFileEx
    string logFile = GetUserHomeDir() + "\\ReplaceStringInFileEx.log"; 
    FILE *log = fopen(logFile.c_str(), "wt");
    fprintf(log, "ReplaceStringInFileEx(\"%s\", \"%s\", \"%s\")\n", filename, S, R);
#endif
    src = fopen(filename, "rt");
    if(src != NULL)
    {
        FILE *dest = NULL;
        int count = 0;
        char buffer[1024];
        char destfile[1024];
        int LS = strlen(S);
        int LR = (R != NULL) ? strlen(R) : 0;

#ifdef DEBUG_ReplaceStringInFileEx
        fprintf(log, "We were able to open %s\n", filename);
#endif

        _snprintf(destfile, 1024, "%s.tmp", filename);
        dest = fopen(destfile, "wt");
        if(dest == NULL)
        {
#ifdef DEBUG_ReplaceStringInFileEx
            fprintf(log, "We were not able to open %s\n", destfile);
            fclose(log);
#endif
            fclose(src);
            return;
        }

        while(1)
        {
            buffer[count] = fgetc(src);

            if(feof(src))
                break;

            if(count+1 == LS)
            {
                /* Our string has reached the size of the string that
                 * looking for. If it matches, write the replacement
                 * string. Otherwise, write the string in the buffer.
                 */
                if(strncmp(buffer, S, LS) == 0)
                {
                    if(R != NULL && LR >= 1)
                        fwrite(R, LR, 1, dest);
                }
                else
                    fwrite(buffer, LS, 1, dest);
                count = 0;
            }
            else if(buffer[count] != S[count])
            {
                /* Our string cannot match the string in the buffer
                 * so write out the buffer.
                 */
                fwrite(buffer, count+1, 1, dest);
                count = 0;
            }
            else
            {
                /* keep going. */
                ++count;
            }
        }

        fclose(src);
        fclose(dest);
#ifdef DEBUG_ReplaceStringInFileEx
        fprintf(log, "Closed src and dest\n");
#endif

        /* Try renaming the files. */
        if(remove(filename) == 0)
        {
            rename(destfile, filename);
#ifdef DEBUG_ReplaceStringInFileEx
            fprintf(log, "Renamed %s to %s\n", filename, destfile);
#endif
        }
#ifdef DEBUG_ReplaceStringInFileEx
        else
        {
            fprintf(log, "Could not remove %s\n", filename);
        }
#endif
    }
#ifdef DEBUG_ReplaceStringInFileEx
    else
    {
        fprintf(log, "Could not open %s\n", filename);
    }

    fclose(log);
#endif
}

/******************************************************************************
 *
 * Purpose: Retrieves the registry key for the 'Environment' subkey of 
 *          HKEY_LOCAL_MACHINE.
 *
 *          The subkey path to 'Environment' is: HKEY_LOCAL_MACHINE\System\
 *          CurrentControlSet\Control\SessionManager\Environemnt
 *
 * Arguments:
 *     hkey     A place to store the retrieved registry key.
 *     sam      Which access & and security permissions to use in retrieval.
 *     log      A file handle for logging errors.
 *
 * Returns:
 *   1 upon successful retrieval of key, 0 otherwise.
 *
 * Post conditions:
 *   On success, the designated registry subkey is open, and must be
 *   closed by caller.
 *
 * Programmer: Kathleen Bonnell 
 * Creation:   June 4, 2008 
 *
 * Modifications:
 *
 *****************************************************************************/

static int
GetEnvKeyLM(HKEY *hkey, REGSAM sam, FILE *log)
{
    int readSuccess = 0;
    HKEY hsubkey1, hsubkey2, hsubkey3, hsubkey4;
   
    readSuccess = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM", 0, 
                               KEY_QUERY_VALUE, &hsubkey1);
    if (readSuccess != ERROR_SUCCESS)
    {
        return 0;
    }

    readSuccess = RegOpenKeyEx(hsubkey1, "CurrentControlSet", 0, 
                               KEY_QUERY_VALUE, &hsubkey2);
    if (readSuccess != ERROR_SUCCESS)
    {
        RegCloseKey(hsubkey1);
        if (log != 0)
            fprintf(log, "could not open CurrentControlSet on HKLM\n");
        return 0;
    }

    readSuccess = RegOpenKeyEx(hsubkey2, "Control", 0, 
                               KEY_QUERY_VALUE, &hsubkey3);
    if (readSuccess != ERROR_SUCCESS)
    {
        RegCloseKey(hsubkey2);
        RegCloseKey(hsubkey1);
        if (log != 0)
            fprintf(log, "could not open Control on HKLM\n");
        return 0;
    }

    readSuccess = RegOpenKeyEx(hsubkey3, "Session Manager", 0, 
                               KEY_QUERY_VALUE, &hsubkey4);
    if (readSuccess != ERROR_SUCCESS)
    {
        RegCloseKey(hsubkey2);
        RegCloseKey(hsubkey3);
        RegCloseKey(hsubkey1);
        if (log != 0)
            fprintf(log, "could not open Session Manager on HKLM\n");
        return 0;
    }

    readSuccess = RegOpenKeyEx(hsubkey4, "Environment", 0, 
                               sam, hkey);
    if (readSuccess != ERROR_SUCCESS)
    {
        RegCloseKey(hsubkey4);
        RegCloseKey(hsubkey3);
        RegCloseKey(hsubkey2);
        RegCloseKey(hsubkey1);
        if (log != 0)
            fprintf(log, "could not open Environment on HKLM\n");
        return 0;
    }
    RegCloseKey(hsubkey4);
    RegCloseKey(hsubkey3);
    RegCloseKey(hsubkey2);
    RegCloseKey(hsubkey1);
    return 1;
}

/******************************************************************************
 *
 * Purpose: Retrieves the registry key for the 'Environment' subkey of 
 *          HKEY_CURRENT_USER
 *
 *          The subkey path to 'Environment' is: HKEY_CURRENT_USER\Environment
 *          
 * Arguments:
 *     hkey     A place to store the retrieved registry key.
 *     sam      Which access & and security permissions to use in retrieval.
 *     log      A file handle for logging errors.
 *
 * Returns:
 *   1 upon successful retrieval of key, 0 otherwise.
 *
 * Post conditions:
 *   On success, the designated registry subkey is open, and must be
 *   closed by caller.
 *
 * Programmer: Kathleen Bonnell 
 * Creation:   June 4, 2008 
 *
 * Modifications:
 *
 *****************************************************************************/

static int
GetEnvKeyCU(HKEY *hkey, REGSAM sam, FILE *log)
{
    if (RegOpenKeyEx(HKEY_CURRENT_USER, "Environment", 0, sam,
                     hkey) != ERROR_SUCCESS)
    {
        if (log != 0)
            fprintf(log, "could not open Environment on HKCU\n");
        return 0;
    }
    return 1;
}

/******************************************************************************
 *
 * Purpose: A wrapper for methods that retrieve 'Environment' subkey from
 *          a particular predfined Registry Key .
 *          HKLM = HKEY_LOCAL_MACHINE
 *          HKCU = HKEY_CURRENT_USER
 *
 * Arguments:
 *     hkey     A place to store the retrieved registry key.
 *     sam      Which access & and security permissions to use in retrieval.
 *     log      A file handle for logging errors.
 *
 * Returns:
 *   1 upon successful retrieval of key, 0 otherwise.
 *
 * Post conditions:
 *   On success, the designated registry subkey is open, and must be
 *   closed by caller.
 *
 * Programmer: Kathleen Bonnell 
 * Creation:   June 4, 2008 
 *
 * Modifications:
 *
 *****************************************************************************/

static int
GetEnvKey(const char *regType, HKEY *hkey, REGSAM sam, FILE *log)
{
    if (strcmp(regType, "HKLM") == 0)
        return GetEnvKeyLM(hkey, sam, log);
    else if (strcmp(regType, "HKCU") == 0)
        return GetEnvKeyCU(hkey, sam, log);
    else 
        return 0;
}

/******************************************************************************
 *
 * Purpose: Reads a value from the Environment registry key.
 *
 * Arguments:
 *     regType  The predefined registry key type.
 *     valName  The name of the value to be read.
 *     val      A place to store the value.
 *     keyType  A place to store the key's type.
 *     log      A file handle for logging errors.
 *
 * Returns:
 *   1 upon successful retrieval of key value, 0 otherwise.
 *
 * Programmer: Kathleen Bonnell 
 * Creation:   June 4, 2008 
 *
 * Modifications:
 *
 *****************************************************************************/

static int
ReadEnvKeyVal(const char *regType, const char *valName, char**val, 
              DWORD *keyType, FILE *log)
{
    int readSuccess = 0;
    HKEY hkey;
    DWORD strSize = 0;
    const BYTE *dummy = NULL;


    readSuccess = GetEnvKey(regType, &hkey, KEY_QUERY_VALUE, log);

    if (!readSuccess)
    {
        if (log != 0)
            fprintf(log, "Could not open EnvKey in %s\n", regType);
        return 0;
    }

    readSuccess = RegQueryValueEx(hkey, valName, NULL, keyType, NULL, 
                                  &strSize);
    if (readSuccess != ERROR_SUCCESS)
    {
        RegCloseKey(hkey);
        /* try to create the value */
        readSuccess = GetEnvKey(regType, &hkey, KEY_SET_VALUE, log);
        if (!readSuccess)
        {
            if (log != 0)
                fprintf(log, "Could not open EnvKey for writing in %s\n", 
                              regType);
            return 0;
        }
        strSize = 1;
        *keyType = REG_EXPAND_SZ;
        readSuccess = RegSetValueEx(hkey, valName, 0, REG_EXPAND_SZ, dummy, 0);
        *val = NULL;
        if (readSuccess != ERROR_SUCCESS)
        {
            RegCloseKey(hkey);
            if (log != 0)
                fprintf(log, "Could not retrieve or set value %s in %s\n",
                        valName, regType);
            return 0;
        }
    }
    else
    {
        *val = (char*)malloc(strSize);
        readSuccess = RegQueryValueEx(hkey, valName, NULL, keyType, 
                                      (LPBYTE)*val, &strSize);
    }
    RegCloseKey(hkey);
    return 1;
}

/******************************************************************************
 *
 * Purpose: Prepends a value on to the PATH environment variable string.
 *
 * Arguments:
 *     regType  The predefined registry key type.
 *     addVal   The value to be prepended.
 *     val      A place to store the current value.
 *     newval   A place to store the new value.
 *     log      A file handle for logging errors.
 *
 * Returns:
 *   1 upon successful prepending to PATH, 0 otherwise.
 *
 * Post conditions:
 *   Upon success, val and newval will have been malloc'd.  Caller is
 *   responsible for free'ing.
 *
 * Programmer: Kathleen Bonnell 
 * Creation:   June 4, 2008 
 *
 * Modifications:
 *
 *****************************************************************************/

static int
PrependPath(const char *regType, const char *addVal, char**currentPath, 
            char**newPath,
            FILE *log)
{
    int readSuccess = 0;
    HKEY hkey;
    DWORD keyType, strSize = 0;

    if (log != 0)
        fprintf(log, "Attempting to add this to PATH:  %s\n", addVal);

    readSuccess = ReadEnvKeyVal(regType, "PATH", currentPath, &keyType, log);
   
    if (!readSuccess)
    {
        if (log != 0)
            fprintf(log, "could not read PATH on %s\n", regType);
        return 0;
    }
    if (*currentPath != NULL)
    {
        /* first lets see if the value we are adding is already present */
        char *ptr = strstr(*currentPath, addVal);
        if (ptr != NULL)
        {
            if (log != 0)
              fprintf(log, "%s already exists in PATH: %s\n", 
                      addVal, *currentPath); 
            return 1;
        }
        strSize = strlen(*currentPath) + 1;
    }
    else 
    {
        strSize = 0;
    }

    readSuccess = GetEnvKey(regType, &hkey, KEY_SET_VALUE, log);
    if (!readSuccess)
    {
        if (log != 0)
            fprintf(log, "Could not open Environment on %s for Setting\n", 
                    regType);
        return 0;
    }
    
    *newPath = (char*)malloc(strSize+1 + strlen(addVal));
    strcpy(*newPath, addVal);
    if (strSize > 1)
    {
        strcat(*newPath, ";");
        strcat(*newPath, *currentPath); 
    }
    readSuccess = RegSetValueEx(hkey, "PATH", 0, REG_EXPAND_SZ, 
                                (LPBYTE)*newPath, 
                                (strlen(*newPath)+1) * sizeof(TCHAR));
    RegCloseKey(hkey);
    if (readSuccess != ERROR_SUCCESS)
    {
        if (log != 0)
            fprintf(log, "Could not set value for PATH in %s\n", regType);
        return 0;
    }

    return 1;
}

/******************************************************************************
 *
 * Purpose: Removes a value from the PATH environment variable string.
 *
 * Arguments:
 *     regType  The predefined registry key type.
 *     remVal   The value to be prepended.
 *     val      A place to store the current value.
 *     newval   A place to store the new value.
 *     log      A file handle for logging errors.
 *
 * Returns:
 *   1 upon successful prepending to PATH, 0 otherwise.
 *
 * Post conditions:
 *   Upon success, val and newval will have been malloc'd.  Caller is
 *   responsible for free'ing.
 *
 * Programmer: Kathleen Bonnell 
 * Creation:   June 4, 2008 
 *
 * Modifications:
 *
 *****************************************************************************/

static int
RemoveFromPath(const char *regType, const char *remVal,
               char **val, char**newval, FILE *log)
{
    char *token, *start, *path;
    int good = 0;
    HKEY hkey;
    DWORD keyType, strSize = 0;

    good = ReadEnvKeyVal(regType, "PATH", val, &keyType, log); 
    if (!good)
    {
        return 0;
    }
    if (*val != NULL)
    {
        strSize = strlen(*val) + 1;
    }
    else 
    {
        strSize = 0;
    }
    good = GetEnvKey(regType, &hkey, KEY_SET_VALUE, log);
    if (!good)
    {
        return 0;
    }

    *newval = (char*)malloc(strSize+1);
    *newval[0] = '\0';
    start = path = *newval;
    token = strtok(*val, ";");
    while(token != NULL)
    {
        if (strcmp(token, remVal) != 0)
        {
            int len = strlen(token);
            if (path == start)
            {
                sprintf(path, "%s", token);
                path += len;
            }
            else
            {
                sprintf(path, ";%s", token);
                path += (len + 1);
            }
        }
        /* Get next token: */
        token = strtok(NULL, ";");
    }

    good = RegSetValueEx(hkey, "PATH", 0L, keyType, (LPBYTE)*newval, 
                                strlen(*newval) +1);
    RegCloseKey(hkey);
    if (good != ERROR_SUCCESS)
    {
        return 0;
    }
    return 1;
}

static int
RemoveAllVisItsFromPath(const char *regType, char **val, char **newval, 
                        FILE *log)
{
    char *token, *start, *path;
    int good = 0;
    HKEY hkey;
    DWORD keyType, strSize = 0;

    good = ReadEnvKeyVal(regType, "PATH", val, &keyType, log); 
    if (!good)
    {
        return 0;
    }
    if (*val != NULL)
    {
        strSize = strlen(*val) + 1;
    }
    else 
    {
        strSize = 0;
    }
    good = GetEnvKey(regType, &hkey, KEY_SET_VALUE, log);
    if (!good)
    {
        return 0;
    }

    *newval = (char*)malloc(strSize+1);
    *newval[0] = '\0';
    start = path = *newval;
    token = strtok(*val, ";");
    while(token != NULL)
    {
        if (strstr(token, "VisIt ") == NULL)
        {
            int len = strlen(token);
            if (path == start)
            {
                sprintf(path, "%s", token);
                path += len;
            }
            else
            {
                sprintf(path, ";%s", token);
                path += (len + 1);
            }
        }
        /* Get next token: */
        token = strtok(NULL, ";");
    }

    good = RegSetValueEx(hkey, "PATH", 0L, keyType, (LPBYTE)*newval, 
                                strlen(*newval) +1);
    RegCloseKey(hkey);
    if (good != ERROR_SUCCESS)
    {
        return 0;
    }
    return 1;
}


/*** end Kat's Additions ***/

/******************************************************************************
 ******************************************************************************
 ***
 *** NSIS EXTENSION FUNCTIONS
 ***
 ******************************************************************************
 *****************************************************************************/


/******************************************************************************
 *
 * Purpose: This function is a custom extension for the NSIS installer that
 *          allows it to easily format the install directory, stored in
 *          $INST_DIR, to a Java preference that we can use to poke VisIt's
 *          installation directory into the registry so Java can find it.
 *
 * Programmer: Brad Whitlock
 * Date:       Mon Jun 6 16:55:54 PST 2005
 *
 * Input Arguments:
 *
 * Input / Output Arguments:
 *
 * Output Arguments:
 *
 * Modifications:
 *
 *****************************************************************************/
extern "C"
{

void __declspec(dllexport) GetInstallPathFormattedForJava(
    HWND hwndParent, int string_size, 
    char *variables, stack_t **stacktop)
{
    char *path = 0, newpath[1024];
    int i, pos = 0, len = 0;

    EXDLL_INIT();

    if(!g_stacktop)
        return;

    path = getuservariable(INST_INSTDIR);

    newpath[0] = '\0';
    len = strlen(path);
    memset(newpath, 0, 1024);

    for(i = 0; i < len && pos < 1024; ++i)
    {
        char c = path[i];
        if(c == '\\')
        {
            newpath[pos++] = '/';
            c = '/';
        }
        else if(c >= 'A' && c <= 'Z')
            newpath[pos++] = '/';
        newpath[pos++] = c;
    }

    pushstring(newpath);
}


/******************************************************************************
 *
 * Purpose: This function is a custom extension for the NSIS installer that
 *          allows it to replace a string in a file.
 *
 * Programmer: Brad Whitlock
 * Date:       Thu Mar 16 10:52:54 PDT 2005
 *
 * Precondition:
 *   The strings containing the filename, string to replace, and replacement
 *   string on the top of the stack.
 *
 * Postcondition:
 *   The arguments used to call this function are popped from the stack.
 *
 * Modifications:
 *
 *****************************************************************************/

void __declspec(dllexport) ReplaceStringInFile(
    HWND hwndParent, int string_size, 
    char *variables, stack_t **stacktop)
{
    char *path_file = NULL;
    char *installdir = NULL;
    char filename[1024];
    char stringtoreplace[1024];
    char replacementstring[1024];
    FILE *src = NULL;
    FILE *dest = NULL;
    int linstalldir;
    EXDLL_INIT();

    if(!g_stacktop)
        return;

    /* Replacement string. */
    popstring(replacementstring);
    /* String to replace. */
    popstring(stringtoreplace);
    /* Filename. */
    popstring(filename);

    /* Destination directory. */
    installdir = getuservariable(INST_INSTDIR);

    linstalldir = strlen(installdir);
    if(installdir[linstalldir-1] == '\\')
    {
        path_file = (char *)malloc(linstalldir + strlen(filename) + 1+6);
        sprintf(path_file, "%s\\hosts\\%s", installdir, filename);
    }
    else
    {
        path_file = (char *)malloc(linstalldir + strlen(filename) + 1 + 1+6);
        sprintf(path_file, "%s\\hosts\\%s", installdir, filename);
    }

    /* Replace the string in the specified file. */
    if(stringtoreplace != NULL && strlen(stringtoreplace) > 0)
        ReplaceStringInFileEx(path_file, stringtoreplace, replacementstring);
    
    free(path_file);
}

void __declspec(dllexport) ReplaceStringInFiles(
    HWND hwndParent, int string_size, 
    char *variables, stack_t **stacktop)
{
    char *path_file = NULL;
    char *installdir = NULL;
    char filespath[1024];
    char search[1024];
    char filename[1024];
    char stringtoreplace[1024];
    char replacementstring[1024];
    FILE *src = NULL;
    FILE *dest = NULL;
    int linstalldir;
#ifdef DEBUG_ReplaceStringInFileEx
    string logFile = GetUserHomeDir() + "\\ReplaceStringInFiles.log"; 
    FILE *log = fopen(logFile.c_str(), "wt");
#endif
    WIN32_FIND_DATA fd;
    HANDLE dirHandle = INVALID_HANDLE_VALUE;

    EXDLL_INIT();

    if(!g_stacktop)
        return;

    /* Replacement string. */
    popstring(replacementstring);
    /* String to replace. */
    popstring(stringtoreplace);
    /* Filename. */
    popstring(filespath);
#ifdef DEBUG_ReplaceStringInFileEx
fprintf(log, "replacementstring is %s\n", replacementstring);
fprintf(log, "stringtoreplace   is %s\n", stringtoreplace);
fprintf(log, "filespath         is %s\n", filespath);
#endif

    if(stringtoreplace != NULL && strlen(stringtoreplace) > 0)
    {
      /* Destination directory. */
      installdir = getuservariable(INST_INSTDIR);
      sprintf(filename, "%s\\%s", installdir, filespath);
      sprintf(search, "%s\\*.xml", filename);
      linstalldir = strlen(search);
#ifdef DEBUG_ReplaceStringInFileEx
fprintf(log, "installdir        is %s\n", installdir);
fprintf(log, "search            is %s\n", search);
#endif

      /* find all files in dest dir */
      dirHandle = FindFirstFile(search, &fd);
      if (dirHandle != INVALID_HANDLE_VALUE)
      {
        do
        {
          path_file = (char *)malloc(linstalldir + strlen(fd.cFileName) +1+1);
          sprintf(path_file, "\"%s\\%s\"", filename, fd.cFileName);
#ifdef DEBUG_ReplaceStringInFileEx
fprintf(log, "fd.cFileName       is %s\n", fd.cFileName);
fprintf(log, "path_file          is %s\n", path_file);
#endif 
          ReplaceStringInFileEx(path_file, stringtoreplace, replacementstring);
          free(path_file);

        } while(FindNextFile(dirHandle, &fd));
        FindClose(dirHandle);
      }
    }

    /* Replace the string in the specified file. */
    
}


/******************************************************************************
 *
 * Purpose: This function is a custom extension for the NSIS installer that
 *          prepends the VisIt install path to the system PATH variable.
 *
 * Programmer: Kathleen Bonnell 
 * Date:       Tue Jun 3 10:42:32 PDT 2008 
 *
 * Precondition:
 *   The strings containing the visitpath on the top of the stack.
 *
 * Postcondition:
 *   The arguments used to call this function are popped from the stack.
 *
 * Modifications:
 *
 *****************************************************************************/

void __declspec(dllexport) AddVisItToPath(
    HWND hwndParent, int string_size, 
    char *variables, stack_t **stacktop)
{
    char visitpath[1024];
    char allusers[1024];
    char *pathenv = 0, *newpathenv = 0;
    int success;
    FILE *log = NULL;
#ifdef DEBUG_VisItPath
    char logLocation[1024];
    char *token;
    int len = 0;
#endif

    EXDLL_INIT();

    if(!g_stacktop)
        return;

    popstring(allusers);
    popstring(visitpath);

#ifdef DEBUG_VisItPath
    token = strstr(visitpath, "VisIt");
    len = strlen(visitpath) - strlen(token);
    strncpy(logLocation, visitpath, len);
    logLocation[len] = '\0';
    sprintf(logLocation, "%s\\VIkit_AddVisItToPath.txt", logLocation);
    log = fopen(logLocation, "wt");
#endif
    
    if (strcmp(allusers, "all") == 0)
    {
        success = PrependPath("HKLM", "%VISITLOC%", &pathenv, 
                                &newpathenv, log);
    }
    else 
    {
        success = PrependPath("HKCU", "%VISITLOC%", &pathenv, 
                                &newpathenv, log);
    }
    if (pathenv != 0)
        free(pathenv);
    if (newpathenv != 0)
        free(newpathenv);
    if (success)
        pushstring("true");
    else
        pushstring("false");

#ifdef DEBUG_VisItPath
    fclose(log);
#endif

}

/******************************************************************************
 *
 * Purpose: This function is a custom extension for the NSIS installer that
 *          remove the VisIt install path from the system PATH variable.
 *
 * Programmer: Kathleen Bonnell 
 * Date:       June 4, 2008 
 *
 * Precondition:
 *   The strings containing the visitpath and whether the install is for 
 *   "all" users or "current" on the top of the stack.
 *
 * Postcondition:
 *   The arguments used to call this function are popped from the stack.
 *
 * Modifications:
 *
 *****************************************************************************/

void __declspec(dllexport) RemoveVisItFromPath(
    HWND hwndParent, int string_size, 
    char *variables, stack_t **stacktop)
{
    char visitpath[1024];
    char allusers[1024];
    char *pathenv = 0, *newpathenv = 0;
    int success;
    FILE *log = NULL;
#ifdef DEBUG_VisItPath
    char logLocation[1024];
    char *token = 0;
    int len = 0;
#endif

    EXDLL_INIT();

    if(!g_stacktop)
        return;

    popstring(allusers);
    popstring(visitpath);

#ifdef DEBUG_VisItPath
    token = strstr(visitpath, "VisIt");
    len = strlen(visitpath) - strlen(token);
    strncpy(logLocation, visitpath, len);
    logLocation[len] = '\0';
    sprintf(logLocation, "%s\\VIkit_RemoveVisItFromPath.txt", logLocation);
    log = fopen(logLocation, "wt");
#endif
    
    if (strcmp(allusers, "all") == 0)
    {
        success = RemoveFromPath("HKLM", "%VISITLOC%", &pathenv, 
                                &newpathenv, log);
    }
    else 
    {
        success = RemoveFromPath("HKCU", "%VISITLOC%", &pathenv, 
                                &newpathenv, log);
    }
    if (pathenv != 0)
        free(pathenv);
    if (newpathenv != 0)
        free(newpathenv);
    if (success)
        pushstring("true");
    else
        pushstring("false");

#ifdef DEBUG_VisItPath
    fclose(log);
#endif

}

/******************************************************************************
 *
 * Purpose: This function is a custom extension for the NSIS installer that
 *          searches the PATH environment variable for 'VisIt' and returns all 
 *          strings that match.
 *
 * Programmer: Kathleen Bonnell 
 * Date:       October 27, 2010 
 *
 * Precondition:
 *   Top of stack: A string indicating whether the install is for "all" users 
 *   or "current".
 *   Top of stack-1: Path to VisIt's install location (for debug logging).
 *
 * Postcondition:
 *   The arguments used to call this function are popped from the stack.
 *
 *   One value is returned on the stack.
 *      If 'VisIt' was not found in PATH, the value is an empty string.
 *
 *      If 'VisIt' was found in PATH, a string containing a message box prompt 
 *      is the top value of the stack.
 *
 * Modifications:
 *
 *****************************************************************************/

void __declspec(dllexport) FindVisItInPath(
    HWND hwndParent, int string_size, 
    char *variables, stack_t **stacktop)
{
    char visitpath[1024];
    char allusers[1024];
    char *pathenv = 0;
    FILE *log = NULL;
    int good = 0;
    DWORD keyType;
#ifdef DEBUG_FindVisItInPath
    char logLocation[1024];
    char *token = 0;
    int len = 0;
#endif

    EXDLL_INIT();

    if(!g_stacktop)
        return;

    popstring(allusers);
    popstring(visitpath);

#ifdef DEBUG_FindVisItInPath
    token = strstr(visitpath, "VisIt");
    len = strlen(visitpath) - strlen(token);
    strncpy(logLocation, visitpath, len);
    logLocation[len] = '\0';
    sprintf(logLocation, "%s\\VIkit_FindVisItInPath.txt", logLocation);
    log = fopen(logLocation, "wt");
#endif
    
    if (strcmp(allusers, "all") == 0)
    {
        good = ReadEnvKeyVal("HKLM", "PATH", &pathenv, &keyType, log); 
    }
    else 
    {
        good = ReadEnvKeyVal("HKCU", "PATH", &pathenv, &keyType, log); 
    }

    if (!good)
    {
        pushstring(""); 
    }
    else if (pathenv == NULL)
    {
        pushstring(""); 
    }
    else
    {
        char *pp = pathenv;
        char *visit = strstr(pp, "VisIt ");
        char versions[1024];
        char tmp[1024];
        int v[3];
        good = 0;
        while (visit != NULL)
        {
            if (sscanf(visit+6, "%d.%d.%d", &v[0], &v[1], &v[2]) == 3)
            {
               good = 1;
               _snprintf(tmp, 1024, "%d.%d.%d ; ", v[0], v[1], v[2]);
               if (log != NULL)
                    fprintf(log, "\tadding version: %s\n", tmp);
               strncat(versions, tmp, strlen(tmp));
            }
            pp = visit+6;
            visit = strstr(pp, "VisIt ");
        }
        if (good)
        {
            char msg[1024];
            _snprintf(msg, 1024, "These versions of VisIt were found in the "
                      "PATH: %s. Would you like them removed from the PATH?",
                      versions);
            pushstring(msg);
        }  
        else 
        {
            pushstring("");
        }  
    }

    if (pathenv != 0)
        free(pathenv);

#ifdef DEBUG_FindVisItInPath
    fclose(log);
#endif

}

/******************************************************************************
 *
 * Purpose: This function is a custom extension for the NSIS installer that
 *          searches the PATH environment variable for 'VisIt' and returns all 
 *          strings that match.
 *
 * Programmer: Kathleen Bonnell 
 * Date:       October 27, 2010 
 *
 * Precondition:
 *   Top of stack: A string indicating whether the install is for "all" users 
 *   or "current".
 *   Top of stack-1: Path to VisIt's install location (for debug logging).
 *
 * Postcondition:
 *   The arguments used to call this function are popped from the stack.
 *
 * Modifications:
 *
 *****************************************************************************/

void __declspec(dllexport) RemoveAllVisItInPath(
    HWND hwndParent, int string_size, 
    char *variables, stack_t **stacktop)
{
    char visitpath[1024];
    char allusers[1024];
    char *pathenv = 0, *newpathenv = 0;
    FILE *log = NULL;
    int good = 0;
#ifdef DEBUG_RemoveAllVisItInPath
    char logLocation[1024];
    char *token = 0;
    int len = 0;
#endif

    EXDLL_INIT();

    if(!g_stacktop)
        return;

    popstring(allusers);
    popstring(visitpath);

#ifdef DEBUG_RemoveAllVisItInPath
    token = strstr(visitpath, "VisIt");
    len = strlen(visitpath) - strlen(token);
    strncpy(logLocation, visitpath, len);
    logLocation[len] = '\0';
    sprintf(logLocation, "%s\\VIkit_FindVisItInPath.txt", logLocation);
    log = fopen(logLocation, "wt");
#endif
    
    if (strcmp(allusers, "all") == 0)
    {
        good = RemoveAllVisItsFromPath("HKLM", &pathenv, &newpathenv, log); 
    }
    else 
    {
        good = RemoveAllVisItsFromPath("HKCU", &pathenv, &newpathenv, log); 
    }

    if (pathenv != 0)
        free(pathenv);
    if (newpathenv != 0)
        free(newpathenv);

#ifdef DEBUG_RemoveAllVisItInPath
    fclose(log);
#endif

}

BOOL WINAPI DllMain(HANDLE hInst, ULONG ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}

} /* extern "C" */
