# altv-python-module
alt:V Multiplayer Python Module

This is a module which will make you able to write alt:V scripts in Python. The module is in a complete beginning, and it will take a long time to get it to a usable level

## How to install
1) Download and Install Python 3.9.6 from [Python](https://python.org) 
2) Download the newest version from [Releases](https://github.com/Marvisak/altv-python-module/releases)
3) Open the zip file
4) Drag & Drop the folder from the zip into your server's modules folder
5) Open your server's server.cfg and add the module:
```
modules: [ python-module ]
```

## Troubleshooting

**Problem**: When starting the server with module installed I get this error:

```
Failed to load "python-module.dll"
Win32 error: 126 (7e) | The Specified Module Could Not Be Found.
```

or

```
Fatal Python error: init_fs_encoding: failed to get the Python codec of the filesystem encoding
Python runtime state: core initialized
ModuleNotFoundError: No module named 'encodings'
```

**Solution**: You don't have Python or correct version of Python installed, head to the [Python website](https://python.org) and download the latest version
# I really appreciate any contribution