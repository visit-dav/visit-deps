Windows Build Notes for libccmio-2.6.1

ccmio-2.6.1-projects.zip contains projects for 
MSVC7 (.Net 2003), MSVC8 (2005), MSVC9 (2008),
MSVC 2010 and a copy of this readme.


Get libccmio-2.6.1.tar.gz from VisIt's third_party libs.
Extract it to the location on your computer where you
wish to build the third-party libs. (eg. "C:\")
This will create
C:\libccmio-2.6.1

Extract the ccmio projects to the root directory for libccmio:
C:\libccmio-2.6.1
to create
C:\libccmio-2.6.1\windows

cd to  (open the folder for)
C:\libccmio-2.6.1\windows

There will be five directories, 'adf', 'ccmio' 'vc7', 'vc8',
and 'vc9' and 'vc10'.  ('adf' and 'ccmio' contains modified 
headers and source necessary for building dlls on Windows).  

run copy_ccmio.bat

Open the folder for the compiler you wish to use, and 
open the corresponding solution file.

For use with VisIt, select the Release configuration 
and build.  Choose the X64 platform for 64bit (available
with vc8 and above).
