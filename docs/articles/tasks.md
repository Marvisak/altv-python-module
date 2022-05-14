# Tasks and Timers

Sometimes you want to call functions in loop or after certain amount of time

You can't use tools provided by Python because they will freeze your whole code execution

Thankfully Python module provides you with tools which can help you solve this problem

## Tasks

Tasks or as some call it intervals call your code every X milliseconds

```py
import alt

@alt.task(seconds=1)
def task():
    alt.log("I am called every second!")
```

After you run this code you should see something like this:
```
[XX:XX:01] I am called every second!
[XX:XX:02] I am called every second!
[XX:XX:03] I am called every second!
[XX:XX:04] I am called every second!
```

As you can see tasks are very similar to events, we are also using decorator

The decorator `alt.task()` has 4 keyword arguments: `milliseconds`, `seconds`, `minutes`, `hours`, all of them are floats

All the arguments you enter will get converted into milliseconds

If you don't enter any arguments the function will get executed every server tick

You can also combine the arguments to create something like this

```py
import alt

@alt.task(minutes=1, seconds=30)
def task():
    alt.log("I am called every minute and a half!")
```

Which outputs this:
```
[XX:01:30] I am called every minute and a half!
[XX:03:00] I am called every minute and a half!
[XX:04:30] I am called every minute and a half!
[XX:06:00] I am called every minute and a half!
```

The function you used the decorator on will then get 4 new functions

- `func.stop()` Stops the task from executing
- `func.start()` Starts the task if it was stopped previously
- `func.is_running()` Returns `True` if the interval is running, otherwise `False`
- `func.set_interval()` Changes the interval, takes the exact same arguments as the `alt.task()` decorator

So you can create something like this:

```py
import alt

@alt.task()
def task():
    alt.log("I am called only once!")
    task.stop()
```

Which outputs:
```
I am called only once!
```

??? note
    You should never do something like this, if you need a code which should execute only once, use timers which are explained below


## Timers

Timers call your code after X milliseconds, the difference between tasks and timers is that timers call your function only once

```py
import alt

def timer():
    alt.log("I am called after one second!")

timer_number = alt.timer(timer, 1000)
```

Which outputs:
```
[XX:XX:01] I am called after one second!
```

The `alt.timer()` function takes 2 arguments, the first one is the function you want to add to the timer, and the second one is the amount of milliseconds after which the function should get called

---

Now you should know everything about Tasks and Timers

Next we are going to learn about vectors
