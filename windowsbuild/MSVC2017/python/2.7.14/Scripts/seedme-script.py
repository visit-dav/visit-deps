#!C:\A_VisIt\2.13RC\windowsbuild\MSVC2017\python\2.7.14\python.exe
# EASY-INSTALL-ENTRY-SCRIPT: 'seedme==1.2.4','console_scripts','seedme'
__requires__ = 'seedme==1.2.4'
import re
import sys
from pkg_resources import load_entry_point

if __name__ == '__main__':
    sys.argv[0] = re.sub(r'(-script\.pyw?|\.exe)?$', '', sys.argv[0])
    sys.exit(
        load_entry_point('seedme==1.2.4', 'console_scripts', 'seedme')()
    )
