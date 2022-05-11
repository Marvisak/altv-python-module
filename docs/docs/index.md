# alt:V Python Module

<figure markdown>
  ![Logo](https://user-images.githubusercontent.com/40175773/162998616-a79410f7-5053-431d-afe8-c68b11a48c32.png)
  <figcaption>alt:V Python Module, fast and simple Python alt:V implementation</figcaption>
</figure>
---
alt:V Python Module adds server-side language support for Python

By installing Python Module you will be able to fully use alt:V server-side API from your Python code

This documentation only explains the Python module itself and assumes you are familiar with the alt:V, and it's API's already.

---

## Let's create your first alt:V Python resource

### Requirements

-   Already working alt:V server
-   Basic Python knowledge
-   Basic knowledge of command prompts
-   An IDE or any other code editor

### Installation

Installation of the Python Module is really easy

-   [Download](https://github.com/Marvisak/altv-python-module/releases/latest) the latest version of the module for your desired platform
-   Create `modules/python-module` folder in your alt:V server folder
-   Move all the files from the zip file you downloaded into the folder you created
-   Add into your `server.cfg` modules column "python-module"

```yaml
modules: ['python-module']
```

Now start the server, if you see this message in the console

```
Python module successfully loaded
```

Then Python module was installed successfully, and you are good to go

### Creating a resource

Creating a resource is identical to creating JavaScript resource

Let's start by creating required files of our resource

For this tutorial we are going to call our resource `python`

```
resources/python

resources/python/resource.cfg

resources/python/main.py
```

As Python is supported only on server-side we are going to create only server files, your gamemode would probably also have client files, but for the sake of this tutorial we are going to skip that

```yaml title="resource.cfg"
type: py
main: main.py
```

```py title="main.py"
import alt

alt.log("My First Python Resource Started!")
```

Now only thing left to do is add the resource into your `server.cfg`

```yaml
resources: ['python']
```

And now when you start your server you should see this message in the console

```
My First Python Resource Started!
```

Congratulations, you have just created your first alt:V Python Resource

## What's next

In the next few articles you are going to learn how the Python module works and how can you use it
After you read through this documentation you should have solid understanding of how the module works and how to use it.
