#!C:\A_Visit\ForRegression\visit-deps\windowsbuild\MSVC2017\python\3.7.7\python.exe
# EASY-INSTALL-ENTRY-SCRIPT: 'Cython==0.29.17','console_scripts','cygdb'
__requires__ = 'Cython==0.29.17'
import re
import sys
from pkg_resources import load_entry_point

if __name__ == '__main__':
    sys.argv[0] = re.sub(r'(-script\.pyw?|\.exe)?$', '', sys.argv[0])
    sys.exit(
        load_entry_point('Cython==0.29.17', 'console_scripts', 'cygdb')()
    )
