# ColShapes

ColShapes are collision zones which can detect entities entering them/leaving them

There are 6 types of colShapes:
    - Circle
    - Cylinder
    - Sphere
    - Cube
    - Rectangle
    - Polygon
    - Checkpoint

All of them work differently, we are going to take a look at Circle and later at Checkpoint

```py
import alt

test_colshape = alt.ColShape.circle(0, 0, 20)

@alt.event(alt.Event.ColShape)
def colshape_event(colshape: alt.ColShape, entity: alt.Entity, state: bool) -> None:
    if colshape != test_colshape: # If it isn't our ColShape we can return
        return

    if isinstance(entity, alt.Player):
        if state: # Entered colshape
            alt.log(f"Player {entity.name} just entered colshape.")
        else:
            alt.log(f"Player {entity.name} just leaved colshape.")
```

This code will output text when player enters and leaves colshape.

## Checkpoints

Checkpoints are little different from ColShapes. The biggest change is that the player can see the ColShape.

```py
import alt

checkpoint = alt.Checkpoint(alt.CheckpointType.Ring, 0, 0, 70, 2, 2, 255, 0, 0, 255)

@alt.event(alt.Event.ColShape)
def colshape_event(colshape: alt.ColShape, entity: alt.Entity, state: bool) -> None:
    if colshape != checkpoint: # If it isn't our Checkpoint we can return
        return

    if isinstance(entity, alt.Player):
        if state: # Entered checkpoint
            alt.log(f"Player {entity.name} just entered checkpoint.")
        else:
            alt.log(f"Player {entity.name} just leaved checkpoint.")
```


