from . import *


def ServerStarted() -> None:
    ...


def PlayerConnect(player: Player) -> None:
    ...


def PlayerBeforeConnect(connection_info: ConnectionInfo) -> str | bool | None:
    ...


def PlayerDisconnect(player: Player, reason: str) -> None:
    ...


def ConnectionQueueAdd(connection_info: ConnectionInfo) -> None:
    ...


def ConnectionQueueRemove(connection_info: ConnectionInfo) -> None:
    ...


def ResourceStart(resource_name: str) -> None:
    ...


def ResourceStop(resource_name: str) -> None:
    ...


def ResourceError(resource_name: str) -> None:
    ...


def SyncedMetaChange(entity: Entity, key: str, value: str, old_value: str) -> None:
    ...


def StreamSyncedMetaChange(
    entity: Entity, key: str, value: str, old_value: str
) -> None:
    ...


def GlobalMetaChange(key: str, value: str, old_value: str) -> None:
    ...


def GlobalSyncedMetaChange(key: str, value: str, old_value: str) -> None:
    ...


def LocalMetaChange(player: Player, key: str, value: str, old_value: str) -> None:
    ...


def PlayerDamage(
    victim: Player,
    attacker: Entity,
    health_damage: int,
    armour_damage: int,
    weapon_hash: int,
) -> None:
    ...


def PlayerDeath(victim: Player, killer: Entity, weapon_hash: int) -> None:
    ...


def Fire(player: Player, fires: FireInfo) -> bool | None:
    ...


def Explosion(
    source: Player, type: ExplosionType, pos: Vector3, fx: int, target: Entity
) -> bool | None:
    ...


def StartProjectile(
    player: Player, pos: Vector3, dir: Vector3, ammo_hash: int, weapon_hash: int
) -> bool | None:
    ...


def WeaponDamage(
    source: Player,
    target: Entity,
    weapon_hash: int,
    damage: int,
    offset: Vector3,
    body_part: BodyPart,
) -> bool | None:
    ...


def VehicleDestroy(vehicle: Vehicle) -> None:
    ...


def VehicleDamage(
    vehicle: Vehicle,
    attacker: Entity,
    body_health_damage: int,
    additional_body_health_damage: int,
    engine_health_damage: int,
    petrol_tank_damage: int,
    weapon: int,
) -> None:
    ...


def ColShape(colshape: ColShape, entity: Entity, state: bool) -> None:
    ...


def PlayerEnterVehicle(player: Player, vehicle: Vehicle, seat: int) -> None:
    ...


def PlayerEnteringVehicle(player: Player, vehicle: Vehicle, seat: int) -> None:
    ...


def PlayerLeftVehicle(player: Player, vehicle: Vehicle, seat: int) -> None:
    ...


def PlayerChangeVehicleSeat(
    player: Player, vehicle: Vehicle, old_seat: int, seat: int
) -> None:
    ...


def PlayerWeaponChange(player: Player, old_weapon: int, weapon: int) -> bool | None:
    ...


def PlayerRequestControl(player: Player, target: Entity) -> bool | None:
    ...


def VehicleAttach(vehicle: Vehicle, attached_vehicle: Vehicle) -> None:
    ...


def VehicleDetach(vehicle: Vehicle, detached_vehicle: Vehicle) -> None:
    ...


def NetOwnerChange(entity: Entity, owner: Player, old_owner: Player) -> None:
    ...


def RemoveEntity(object: Entity) -> None:
    ...


def ConsoleCommand(name: str, args: List[str]) -> None:
    ...


def PlayerAnimationChange(
    player: Player,
    old_anim_dict: int,
    new_anim_dict: int,
    old_anim_name: int,
    new_anim_name: int,
) -> None:
    ...
