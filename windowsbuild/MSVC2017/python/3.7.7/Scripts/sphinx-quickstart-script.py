#!C:\A_Visit\ForRegression\visit-deps\windowsbuild\MSVC2017\python\3.7.7\python.exe
# EASY-INSTALL-ENTRY-SCRIPT: 'sphinx==2.2.1','console_scripts','sphinx-quickstart'
__requires__ = 'sphinx==2.2.1'
import re
import sys
from pkg_resources import load_entry_point

if __name__ == '__main__':
    sys.argv[0] = re.sub(r'(-script\.pyw?|\.exe)?$', '', sys.argv[0])
    sys.exit(
        load_entry_point('sphinx==2.2.1', 'console_scripts', 'sphinx-quickstart')()
    )
