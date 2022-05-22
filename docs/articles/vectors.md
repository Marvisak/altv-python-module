# Vectors

In order to progress forward we need to learn about vectors

We have 2 types of vectors, Vector3 and Vector2

## Vector3

This is the vector you are probably going to use the most

You can create Vector3 like this: `alt.Vector3(0, 0, 0)` and replacing the 0 with your required number

You can perform most mathematical operations on vectors

```py
import alt

vector = alt.Vector3(10, 10, 10)
vector2 = alt.Vector3(20, 20, 20)

alt.log(vector + vector2)
alt.log(vector - vector2)
alt.log(vector * vector2)
alt.log(vector / vector2)
```

This code outputs:

```
Vector3(30.000000, 30.000000, 30.000000)
Vector3(-10.000000, -10.000000, -10.000000)
Vector3(200.000000, 200.000000, 200.000000)
Vector3(0.500000, 0.500000, 0.500000)
```

## Vector2

Vector2 is almost identical to Vector3, but you only get 2 numbers

You can create Vector2 like this `alt.Vector2(0, 0)`

You can also perform most mathematical operations

```py
import alt

vector = alt.Vector2(10, 10)
vector2 = alt.Vector2(20, 20)

alt.log(vector + vector2)
alt.log(vector - vector2)
alt.log(vector * vector2)
alt.log(vector / vector2)
```

This code outputs:

```
Vector2(30.000000, 30.000000)
Vector2(-10.000000, -10.000000)
Vector2(200.000000, 200.000000)
Vector2(0.500000, 0.500000)
```

---

Now you should know basic information about Vectors

Vectors have much more functions which you can find in API reference, this should be just a quick explanation of how do they work

Next we are going to learn about vehicles 
