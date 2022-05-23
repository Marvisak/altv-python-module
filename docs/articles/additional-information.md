# Additional Information

This article will be about some additional information you might need

## Installing 3rd party packages | Using venv

You'll probably want to use some 3rd party package in your code.

For compatibility reasons python module doesn't allow you to use your global environment, so you need to create virtual environment

There are 2 ways how to use it with the module

### The easy way

The easy way is the way you would normally create virtual environment

There are many ways how to achieve this but for the sake of this tutorial I am going to use the standard python way

```
$ python -m venv env
```

Execute this command in your server root folder, and it should create an environment in a folder called env.

Now just enter it, this example is for windows

```
$ env\Scripts\activate
```

Now just start the server, and it should load the virtual environment into the path

If it doesn't which will probably happen if you are using Windows, use the second way

### The annoying way

I am going to expect that you have created your virtual environment in the previous step

Here you will need to find your site-packages folder

On Windows this is: `env\Lib\site-packages`

Now open your `server.cfg` and enter this field:
```
python-venv: env\Lib\site-packages
```
Of course replace the path with your own one, this path has to be relative to the server root folder.

Now start your server, and you can now import any third party packages you install into the virtual environment

### Problems

There might be a bit of a problem, as the module should always be running the newest version of Python, it's APIs might not be compatible with the APIs of the Python you have installed on your system. 

This might create a problem with packages written in C as effectively you are installing packages for a wrong version of Python, so if you find any problems. The only way how to fix them is probably installing the newest version of Python on your system.

If any package doesn't work even with the newest version of Python create issue on GitHub.

## Autocompletion and stubs

If you want autocompletion for your code, you need to download our stubs

You can either install it into your global environment (not recommended) or into your virtual environment you created in the previous step (recommended)

```
$ pip install altv-stubs
```

This should install stubs of the module and your IDE should automatically detect that the stubs were installed and add autocompletion

## Async

Currently, there is no implementation of Python async in the module, meaning that any code which requires the `await` keyword won't work

I (the module developer) am not experienced enough with asynchronous Python to be able to implement it

If you have the necessary knowledge on how to use Python async and can help implement it, contact me on discord `Marvis#5422`

## MyPy

This is just a little recommendation from me.

You've probably heard of TypeScript, the static JavaScript, what if I told you there is something similar like that for Python

It's called MyPy and because unlike JavaScript Python already has typehints and other required stuff for static code it's a CLI application instead of whole other language

You can find all the information about MyPy [on their website](https://mypy.readthedocs.io/en/stable/)

You will need the stubs installed in order for MyPy to check your code

All the code in this documentation should be compatible with MyPy
