#!C:\A_Visit\ForRegression\visit-deps\windowsbuild\MSVC2017\python\3.7.7\python.exe
# EASY-INSTALL-ENTRY-SCRIPT: 'setuptools==44.0.0','console_scripts','easy_install-3.7'
__requires__ = 'setuptools==44.0.0'
import re
import sys
from pkg_resources import load_entry_point

if __name__ == '__main__':
    sys.argv[0] = re.sub(r'(-script\.pyw?|\.exe)?$', '', sys.argv[0])
    sys.exit(
        load_entry_point('setuptools==44.0.0', 'console_scripts', 'easy_install-3.7')()
    )
