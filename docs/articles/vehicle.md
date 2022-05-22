# Vehicle

If you want to drive a vehicle you need to create it first. You can create them from serverside, and they will be completely synced.


```py
import alt

vehicle = alt.Vehicle("elegy", 10, 10, 10, 0, 0, 0) # Creates vehicle with the model elegy on 10,10,10 with 0,0,0 rotation
vehicle2 = alt.Vehicle(alt.hash("panto"), alt.Vector3(40, 40, 40), alt.Vector3(20, 20, 20)) # Creates vehicle with model panto on 40,40,40 with 20,20,20 rotation
```

Vehicles have a lot of properties and methods you can use to edit them

```py
vehicle.primary_color_rgb = alt.RGBA(255, 0, 0) # Makes the spawned vehicle red
```

You can see all the methods and properties you can use on vehicle in our stubs or inside the [API Reference](api-reference/api.md)

