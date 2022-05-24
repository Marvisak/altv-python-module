# Events

Sometimes you want to execute code when something happens

This is why events exist, let's take a look at how they work

## Event's with no arguments

Let's start with events without any arguments as they are easier to understand, currently there is only one so let's take a look at it.

```py
import alt

@alt.event(alt.Event.ServerStarted)
def server_started() -> None:
    alt.log("Server Started!")
```

This code outputs `Server Started!` when the event is triggered, in this case the ServerStarted event which triggers when the server is started

Let's go through this code line by line

---

### Decorator
```py hl_lines="3"
import alt

@alt.event(alt.Event.ServerStarted)
def server_started() -> None:
    alt.log("Server Started!")
```

This decorator `alt.event()` decorator, is placed above a function which should get executed once the specified event is triggered

The first and only argument you pass to this function is an event you want to subscribe to. This has to be `alt.Event` enum, otherwise exception will be raised

---

### Function
```py hl_lines="4 5"
import alt

@alt.event(alt.Event.ServerStarted)
def server_started() -> None:
    alt.log("Server Started!")
```

This is the function you want to call once the event is triggered, the name can be anything you want

Because we are creating event with no arguments, there shouldn't be any arguments for this function

The body of the function can of course be anything you want, most of the time it's going to do something with the arguments passed to it

## Events with arguments

Most of the time you want to get some info from events, this is possible through arguments

```py
import alt

@alt.event(alt.Event.PlayerConnect)
def player_connect(player: alt.Player) -> None:
    alt.log(f"Player joined: {player.name}")
    player.model = "mp_m_freemode_01"
    player.spawn(0, 0, 0)
```

The only difference between these events and events without arguments, is that the function you create needs to have arguments

This is a PlayerConnect event which gets executed when player joins, our first argument is the player which connected

In this event we are logging into the console that player joined, spawning the player and setting its model

## Custom events

Sometimes you want to trigger events yourself, like for example when you want 2 resources communicate with each other or client to communicate with server

The communication can go as follows:

- Client -> Server
- Server -> Client
- Server -> Server

### Client -> Server

```js title="client.js"
import alt from "alt-client";

alt.emitServer("clientEvent", "This is message from client");
```

```py title="server.py"
import alt

@alt.client_event("clientEvent")
def client_event(player: alt.Player, msg: str) -> None:
    alt.log(f"Player {player.name} sent {msg}")
```

Client events work almost identically to normal events, you only need to replace the decorator `alt.event()` with `alt.client_event()` and instead of `alt.Event` enum, pass name of the event as string

When you receive event from client, you will get the player object as the first argument, this is the player which triggered the event

Rest of the arguments are the ones sent with the event, in this example it is the string `This is message from client`

### Server -> Client

```js title="client.js"
import alt from "alt-client";

alt.onServer("serverEvent", (msg) => {
    alt.log(msg);
});
```

```py title="server.py"
import alt

@alt.event(alt.Event.PlayerConnect)
def player_connect(player: alt.Player) -> None:
    # These 2 do the same thing
    player.emit("serverEvent", "This is a server event")
    alt.emit_client(player, "serverEvent", "This is a server event")

    # You can also pass list instead of single player
    alt.emit_client([player], "serverEvent", "This is a server event")

    # This will emit an event to all players
    alt.emit_all_clients("serverEvent", "This is a server event")
```

When we want to emit event from server to specific player, we need to have the player object

All the ways to emit a client event are showed in this code

The first two emit event to single player only, they both work completely the same way

The third one works the same way as the second one, apart from that you can pass list instead of single player, this can be useful when you need to emit event to multiple players

And the fourth and last one is the simplest, by calling the function you emit event to players

### Server -> Server

```py
import alt

@alt.custom_event("customEvent")
def custom_event(msg: str) -> None:
    alt.log(f"Message received {msg}")

alt.emit("customEvent", "This is a message from server")
```

Subscribing to events from server works the same way as with client events, only difference is that you use `alt.custom_event()` decorator

Emitting the event is also very similar to emitting client event, you just call `alt.emit()` function and pass the event name and the arguments

### Note about custom event arguments

Important thing to keep in mind, is that you can't pass everything as an event argument, the structures you sent have to be cross-language, so any custom object you might try to send as an argument won't work

Here is the list of types which you can send: `str`, `int`, `float`, `bool`, `NoneType`, `list`, `dict`, `function`, `bytes`, `bytearray`, `alt.Vector2`, `alt.Vector3`, `alt.RGBA`, `alt.BaseObject`

Functions can be only sent on the server, trying to send function to client or vice versa will fail

Keep in mind that if you send function, the return value and arguments of the function must be sendable in an event

## Cancelling Events

There are some events which you are able to cancel

Most of them are triggered by player doing something, and by cancelling them you disable it syncing to other players

```py
import alt

@alt.event(alt.Event.Explosion)
def explosion(player: alt.Player, *args) -> bool:
    alt.log(f"{player.name} caused an explosion")
    return False
```

This is the explosion event, which gets triggered once explosion is created

We can cancel events by returning `False`, you can cancel any event this way, but not every event will be changed once you cancel them

Also, here you can see that we used `*args` as an argument, this makes it so that you don't need to specify every single argument if you don't need them


The only event which works differently is `alt.Event.PlayerBeforeConnect`

In this event you can return `False` as with other events, but also a string, this will do the same thing as returning `False` but will also show a message

```py
import alt

banned_players = [
    "very_bad_player"
]

@alt.event(alt.Event.PlayerBeforeConnect)
def player_before_connect(connection_info: alt.ConnectionInfo) -> str | None:
    if connection_info.name in banned_players:
        return "You are banned"
```

---

You can see all of the available events inside [API Reference](api-reference/events.md)

Now you should know what events are and how to use them

In the next article we are going to learn about Tasks and Timers
