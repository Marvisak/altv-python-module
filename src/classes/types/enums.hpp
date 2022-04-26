#pragma once

enum class WeatherType : uint32_t {
    ExtraSunny,
    Clear,
    Clouds,
    Smog,
    Foggy,
    Overcast,
    Rain,
    Thunder,
    Clearing,
    Neutral,
    Snow,
    Blizzard,
    Snowlight,
    Xmas,
    Halloween,
};

enum class WeaponTint : uint32_t {
    Normal,
    Green,
    Gold,
    Pink,
    Army,
    LSPD,
    Orange,
    Platinum
};

enum class VehicleModType : uint8_t {
    Spoiler,
    FrontBumper,
    RearBumper,
    SideSkirt,
    Exhaust,
    Frame,
    Grille,
    Hood,
    Fender,
    RightFender,
    Roof,
    Engine,
    Brakes,
    Transmission,
    Horn,
    Suspension,
    Armor,
    Unk1,
    Turbo,
    Unk2,
    TireSmoke,
    Unk3,
    XenonLights,
    FrontWheels,
    BackWheels,
    Plateholder,
    VanityPlates,
    TrimDesign,
    Ornaments,
    Dashboard,
    Dial,
    DoorSpeaker,
    Seats,
    SteeringWheel,
    ColumnShifterLeavers,
    Plaques,
    Speakers,
    Trunk,
    Hydraulics,
    EngineBlock,
    AirFilter,
    Struts,
    ArchCover,
    Aerials,
    Trim,
    Tank,
    Windows,
    Unk4,
    Livery,
};

enum class WindowTint : uint8_t {
    DarkSmoke,
    Green,
    LightSmoke,
    Limo,
    Clear,
    PureBlack,
    Stock
};

enum class RadioStation : uint32_t {
    LosSantosRockRadio,
    NonStopPopFm,
    RadioLosSantos,
    ChannelX,
    WestCoastTalkRadio,
    RebelRadio,
    SoulwaxFm,
    EastLosFm,
    WestCoastClassics,
    BlaineCountyRadio,
    TheBlueArk,
    WorldWideFm,
    FlyloFm,
    TheLowdown,
    RadioMirrorPark,
    Space,
    VinewoodBoulevardRadio,
    SelfRadio,
    TheLab,
    RadioOff = 255,
};

enum class VehicleLockState : uint8_t {
    Nothing,
    Unlocked,
    Locked,
    LockoutPlayerOnly,
    LockPlayerInside,
    InitiallyLocked,
    ForceDoorsShut,
    LockedCanBeDamaged,
};

enum class VehicleDoor : uint8_t {
    DriverFront,
    PassengerFront,
    DriverRear,
    PassengerRear,
    Hood,
    Trunk,
};

enum class VehicleDoorState : uint8_t {
    Closed,
    OpenedLevel1,
    OpenedLevel2,
    OpenedLevel3,
    OpenedLevel4,
    OpenedLevel5,
    OpenedLevel6,
    OpenedLevel7,
    Unknown = 255,
};

enum class VehiclePart : uint8_t {
    FrontLeft,
    FrontRight,
    MiddleLeft,
    MiddleRight,
    RearLeft,
    RearRight,
};

enum class VehiclePartDamage : uint8_t {
    NotDamaged,
    DamagedLevel1,
    DamagedLevel2,
    DamagedLevel3,
};

enum class VehicleBumper : uint8_t {
    Front,
    Rear,
};

enum class VehicleBumperDamage : uint8_t {
    NotDamaged,
    Damaged,
    Nothing,
};

enum class NumberPlateStyle : uint32_t {
    BlueWhite,
    BlueWhite2,
    BlueWhite3,
    Yankton,
    YellowBlack,
    YellowBlue
};

enum class Event : uint16_t {
	ServerStarted = 1,

	PlayerConnect,
	PlayerBeforeConnect,
	PlayerDisconnect,

	ConnectionQueueAdd,
	ConnectionQueueRemove,

	ResourceStart,
	ResourceStop,
	ResourceError,

	SyncedMetaChange = 13,
	StreamSyncedMetaChange,
	GlobalMetaChange,
	GlobalSyncedMetaChange,
	LocalMetaChange,

	PlayerDamage,
	PlayerDeath,
	Fire,
	Explosion,
	StartProjectile,
	WeaponDamage,
	VehicleDestroy,
	VehicleDamage,

	ColshapeEvent = 27, // TODO Implement

	PlayerEnterVehicle,
	PlayerEnteringVehicle,
	PlayerLeftVehicle,
	PlayerChangeVehicleSeat,
	PlayerWeaponChange,
	PlayerRequestControl,

	VehicleAttach,
	VehicleDetach,
	NetOwnerChange,

	RemoveEntity,

	ConsoleCommand = 41,
};

enum class ExplosionType : int8_t {
	Grenade,
	GrenadeLauncher,
	StickyBomb,
	Molotov,
	Rocket,
	TankShell,
	HiOctane,
	Car,
	Plane,
	PetrolPump,
	Bike,
	DirSteam,
	DirFlame,
	DirWaterHydrant,
	DirGasCanister,
	Boat,
	ShipDestroy,
	Truck,
	Bullet,
	SmokeGrenadeLauncher,
	SmokeGrenade,
	BzGas,
	Flare,
	GasCanister,
	Extinguisher,
	ProgrammableAr,
	Train,
	Barrel,
	Propane,
	Blimp,
	DirFlameExplode,
	Tanker,
	PlaneRocket,
	VehicleBullet,
	GasTank,
	Firework,
	Snowball,
	ProxMine,
	ValkyrieCannon,
	Unknown = -1,
};

enum class BodyPart : int8_t {
	Pelvis,
	LeftHip,
	LeftLeg,
	LeftFoot,
	RightHip,
	RightLeg,
	RightFoot,
	LowerTorso,
	UpperTorso,
	Chest,
	UnderNeck,
	LeftShoulder,
	LeftUpperArm,
	LeftElbrow,
	LeftWrist,
	RightShoulder,
	RightUpperArm,
	RightElbrow,
	RightWrist,
	Neck,
	Head,
	Unknown = -1,
};

enum class VehicleType : uint8_t {
	Invalid,
	Ped,
	Automobile,
	Plane,
	Trailer,
	QuadBike,
	SubmarineCar,
	AmphibiousAutomobile,
	AmphibiousQuadBike,
	Heli,
	Blimp,
	AutoGyro,
	Bike,
	BMX,
	Boat,
	Train,
	Submarine,
	Object
};

