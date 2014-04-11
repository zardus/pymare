from distutils.core import setup
from distutils.extension import Extension
setup(name='example',
    version='1.0',
    ext_modules=[Extension('example', ['example.c', 'example_pystructs.c', 'example_enums.c'])],
    )
