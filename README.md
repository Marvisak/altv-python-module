<p align="center">
    <img width="200" src="https://user-images.githubusercontent.com/40175773/162998616-a79410f7-5053-431d-afe8-c68b11a48c32.png" alt="Module Logo">
    <h1 align="center">alt:V Python Module</h1>
    <p align="center">Adds alt:V serverside language support for Python</p>
</p>

## State of the module
I started working on the module again (maybe), I am currently not happy with most of the code written and will have to rewrite it. I want to thank all the contributors which tried to keep the module alive, you've done a great job. 

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
