# Intro

Let's start by breaking down the code we wrote previously

```py
import alt

alt.log("My First Python Resource Started!")
```

This is a very simple code, but it's great for explaining how does the module work

## Import alt module

```py hl_lines="1"
import alt

alt.log("My First Python Resource Started!")
```

The alt module is your way to communicate with alt:V API

It is embedded right into the module, so you don't have to install anything.

If you don't need alt:V API in your file you don't have to import it, but most of the thing module does are only usable through this import, so without it, you are going to write plain Python.

Your IDE won't show you any typehints for the alt module, if you want to have them, you can find info about them and much more at [General Recommendations](general-recommendations.md) chapter

## Log into the console

```py hl_lines="3"
import alt

alt.log("My First Python Resource Started!")
```

This line calls the log function

The log function behaves exactly like print function, it even has `sep` parameter which changes the way arguments passed to it are separated

The difference between this function and normal `#!python print()` is that this function uses alt:V API so the output looks different

```py
print("My First Python Resource Started!")
```

Outputs simply: `My First Python Resource Started!`

While our original code outputs: `[17:38:44] My First Python Resource Started!`

??? note
In the rest of articles when we will use this function, the timestamp is going to be removed

---

We have 3 kinds of log functions

- `alt.log()`
- `alt.log_error()`
- `alt.log_warning()`

Each of these functions works exactly the same, only the output looks differently.

---

You can pass any amount of arguments you want, all of them are going to be parsed to string and separated by space.

```py
import alt

alt.log("Hello", 50, [20, 30, 50])
```

This code outputs: `Hello 50 [20, 30, 50]`

If you want to edit the separator of the arguments you pass in, you should use the `sep` argument.

```py
import alt

alt.log("Hello", 50, [], sep=",")
```

This code outputs: `Hello,50,[20, 30, 50]`

---

You can also color the text you are outputting if you are using the `alt.log()` function

```py
import alt

alt.log("~r~This ~g~is ~b~colorful")
```

This code outputs: <code><span style="color: red">This</span> <span style="color: green">is</span> <span style="color: deepskyblue">colorful</span></code>

---

Now you should have basic understanding of how alt module works

You should also know everything about how log functions work and how can you use them in your code

In the next article we are going to learn about events and how to use them