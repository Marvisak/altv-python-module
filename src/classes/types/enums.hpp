#pragma once

#include <cstdint>

enum class WeatherType : uint32_t
{
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

enum class WeaponTint : uint32_t
{
	Normal,
	Green,
	Gold,
	Pink,
	Army,
	LSPD,
	Orange,
	Platinum
};

enum class VehicleModType : uint8_t
{
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

enum class WindowTint : uint8_t
{
	DarkSmoke,
	Green,
	LightSmoke,
	Limo,
	Clear,
	PureBlack,
	Stock
};

enum class RadioStation : uint32_t
{
	Nothing,
	RadioOff,
	MediaPlayer,
	TheMusicLocker,
	MotoMami,
	BlueArk,
	WorldWideFM,
	FlyLoFM,
	TheLowdown,
	TheLab,
	RadioMirrorPark,
	KultFM,
	Space,
	VinewoodBoulevardRadio,
	Blonded,
	LosSantosUndergroundRadio,
	iFruitRadio,
	LosSantosRockRadio,
	NonStopPopFM,
	RadioLosSantos,
	ChannelX,
	WestCoastTalkRadio,
	RebelRadio,
	SoulwaxFM,
	EastLosFM,
	WestCoastClassics
};

enum class VehicleLockState : uint8_t
{
	Nothing,
	Unlocked,
	Locked,
	LockoutPlayerOnly,
	LockPlayerInside,
	InitiallyLocked,
	ForceDoorsShut,
	LockedCanBeDamaged,
};

enum class VehicleDoor : uint8_t
{
	DriverFront,
	PassengerFront,
	DriverRear,
	PassengerRear,
	Hood,
	Trunk,
};

enum class VehicleDoorState : uint8_t
{
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

enum class VehiclePart : uint8_t
{
	FrontLeft,
	FrontRight,
	MiddleLeft,
	MiddleRight,
	RearLeft,
	RearRight,
};

enum class VehiclePartDamage : uint8_t
{
	NotDamaged,
	DamagedLevel1,
	DamagedLevel2,
	DamagedLevel3,
};

enum class VehicleBumper : uint8_t
{
	Front,
	Rear,
};

enum class VehicleBumperDamage : uint8_t
{
	NotDamaged,
	Damaged,
	Nothing,
};

enum class NumberPlateStyle : uint32_t
{
	BlueWhite,
	BlueWhite2,
	BlueWhite3,
	Yankton,
	YellowBlack,
	YellowBlue
};

enum class Event : uint16_t
{
	ServerStarted = 1,

	PlayerConnect,
	PlayerBeforeConnect,
	PlayerDisconnect,
	PlayerConnectDenied,

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

	ColShape = 27,

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

	PlayerAnimationChange,
	PlayerInteriorChange
};

enum class ExplosionType : int8_t
{
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

enum class BodyPart : int8_t
{
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

enum class VehicleType : uint8_t
{
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

enum class ColShapeType : uint8_t
{
	Sphere,
	Cylinder,
	Circle,
	Cuboid,
	Rect,
	CheckpointCylinder,
	Polygon
};

enum class BaseObjectType : uint8_t
{
	Player,
	Vehicle,
	Blip,
	WebView,
	VoiceChannel,
	ColShape,
	Checkpoint,
	WebSocketClient,
	HttpClient,
	Audio,
	RmlElement,
	RmlDocument,
	LocalPlayer
};

enum class BlipColor : int
{
	White,
	Red,
	Green,
	Blue,
	Yellow = 5,
	LightRed,
	Violet,
	Pink,
	LightOrange,
	LightBrown,
	LightGreen,
	LightBlue,
	LightPurple,
	DarkPurple,
	Cyan,
	LightYellow,
	Organe,
	DarkPink = 19,
	GraniteGreen,
	DarkBrown,
	LightGray,
	LightPink,
	LemonGreen,
	ForestGreen,
	ElectricBlue,
	BrightPurple,
	DarkYellow,
	DarkCyan = 30,
	Beige = 36,
	DarkGray = 40,
	PinkRed,
	Gold = 46,
	Orange,
	BrilliantRose,
	MediumPurple = 50,
	Salmon,
	DarkGreen,
	BlizzardBlue,
	OracleBlue,
	Silver,
	EastBay = 58,
	YellowOrange = 60,
	MulberryPink,
	AltoGray,
	JellyBeanBlue,
	DarkOrange,
	Mamba,
	Default,
	TransparentBlack = 72,
	DeepRed = 76,
	TransparentRed = 79,
	TransparentBlue = 80,
	Purple = 83,
};

enum class BlipSprite : int
{
	Higher,
	Lower,
	PolicePed,
	WantedRadius,
	Area,
	Centre,
	North,
	Waypoint,
	Radius,
	RadiusOutline,
	WeaponHigher,
	WeaponLower,
	HigherAI,
	LowerAI,
	PoliceHeliSpin,
	PolicePlaneMove,
	MPCrew = 27,
	MPFriendlies,
	CableCar = 36,
	Activities,
	Raceflag,
	Safehouse = 40,
	Police,
	PoliceChase,
	PoliceHeli,
	BombA,
	Snitch = 47,
	PlanningLocations,
	CriminalCarsteal = 50,
	CriminalDrugs,
	CriminalHoldups,
	CriminalPlayer = 54,
	CopPatrol = 56,
	CopPlayer,
	CriminalWanted,
	Heist,
	PoliceStation,
	Hospital,
	AssassinsMark,
	Elevator,
	Helicopter,
	RandomCharacter = 66,
	SecurityVan,
	TowTruck,
	IllegalParking = 70,
	Barber,
	CarModShop,
	ClothesStore,
	Tattoo = 75,
	ArmenianFamily,
	LesterFamily,
	MichaelFamily,
	TrevorFamily,
	JewelryHeist,
	DragRaceFinish = 82,
	Rampage = 84,
	VinewoodTours,
	LamarFamily,
	FranklinFamily = 88,
	ChineseStrand,
	FlightSchool,
	EyeSky,
	AirHockey,
	Bar,
	BaseJump,
	Basketball,
	BiolabHeist = 96,
	CabaretClub = 99,
	CarWash,
	ComedyClub = 102,
	Darts,
	DocksHeist,
	FbiHeist,
	FbiOfficersStrand,
	FinaleBankHeist,
	FinancierStrand,
	Golf,
	GunShop,
	InternetCafe,
	MichaelFamilyExile,
	NiceHouseHeist,
	RandomFemale,
	RandomMale,
	RuralBankHeist = 118,
	ShootingRange,
	SolomonStrand,
	StripClub,
	Tennis,
	TrevorFamilyExile,
	MichaelTrevorFamily,
	Triathlon = 126,
	OffRoadRacing,
	GangCops,
	GangMexicans,
	GangBikers,
	SnitchRed = 133,
	CriminalCuffKeys,
	Cinema,
	MusicVenue,
	PoliceStationBlue,
	Airport,
	CriminalSavedVehicle,
	WeedStash,
	Hunting,
	Pool,
	ObjectiveBlue,
	ObjectiveGreen,
	ObjectiveRed,
	ObjectiveYellow,
	ArmsDealing,
	MPFriend,
	CelebrityTheft,
	WeaponAssaultRifle,
	WeaponBat,
	WeaponGrenade,
	WeaponHealth,
	WeaponKnife,
	WeaponMolotov,
	WeaponPistol,
	WeaponRocket,
	WeaponShotgun,
	WeaponSmg,
	WeaponSniper,
	MPNoise,
	PointOfInterest,
	Passive,
	UsingMenu,
	GangCopsPartner = 171,
	WeaponMinigun = 173,
	WeaponArmour = 175,
	PropertyTakeover,
	GangMexicansHighlight,
	GangBikersHighlight,
	TriathlonCycling,
	TriathlonSwimming,
	PropertyTakeoverBikers,
	PropertyTakeoverCops,
	PropertyTakeoverVagos,
	Camera,
	CentreRed,
	HandcuffKeysBikers,
	HandcuffKeysVagos,
	HandcuffsClosedBikers,
	HandcuffsClosedVagos,
	CameraBadger = 192,
	CameraFacade,
	CameraIfruit,
	Yoga = 197,
	Taxi,
	Shrink = 205,
	Epsilon,
	FinancierStrandGrey,
	TrevorFamilyGrey,
	TrevorFamilyRed,
	FranklinFamilyGrey,
	FranklinFamilyBlue,
	FranklinA,
	FranklinB,
	FranklinC,
	GangVehicle = 225,
	GangVehicleBikers,
	GangVehicleCops,
	GangVehicleVagos,
	Guncar,
	DrivingBikers,
	DrivingCops,
	DrivingVagos,
	GangCopsHighlight,
	ShieldBikers,
	ShieldCops = 235,
	ShieldVagos,
	CustodyBikers,
	CustodyVagos,
	ArmsDealingAir = 251,
	PlayerStateArrested,
	PlayerStateCustody,
	PlayerStateDriving,
	PlayerStateKeyholder,
	PlayerStatePartner,
	Ztype = 262,
	Stinger,
	Packer,
	Monroe,
	Fairground,
	Property,
	GangHighlight,
	Altruist,
	AI,
	OnMission,
	CashPickup,
	Chop,
	Dead,
	TerritoryLocked,
	CashLost,
	CashVagos,
	CashCops,
	Hooker,
	Friend,
	Mission2to4,
	Mission2to8,
	Mission2to12,
	Mission2to16,
	CustodyDropOff,
	OnMissionCops,
	OnMissionLost,
	OnMissionVagos,
	CriminalCarStealCops,
	CriminalCarStealBikers,
	CriminalCarStealVagos,
	BandStrand,
	SimeonFamily,
	Mission1,
	Mission2,
	FriendDarts,
	FriendComedyClub,
	FriendCinema,
	FriendTennis,
	FriendStripClub,
	FriendLiveMusic,
	FriendGolf,
	BountyHit,
	UgcMission,
	Horde,
	CrateDrop,
	PlaneDrop,
	Sub,
	Race,
	Deathmatch,
	ArmWrestling,
	Mission1to2,
	ShootingRangeGunShop,
	RaceAir,
	RaceLand,
	RaceSea,
	Tow,
	Garbage,
	Drill,
	Spikes,
	Firetruck,
	Minigun2,
	Bugstar,
	Submarine,
	Chinook,
	GetawayCar,
	MissionBikers1,
	MissionBikers1to2,
	MissionBikers2,
	MissionBikers2to4,
	MissionBikers2to8,
	MissionBikers2to12,
	MissionBikers2to16,
	MissionCops1,
	MissionCops1to2,
	MissionCops2,
	MissionCops2to4,
	MissionCops2to8,
	MissionCops2to12,
	MissionCops2to16,
	MissionVagos1,
	MissionVagos1to2,
	MissionVagos2,
	MissionVagos2to4,
	MissionVagos2to8,
	MissionVagos2to12,
	MissionVagos2to16,
	GangBike,
	GasGrenade,
	PropertyForSale,
	GangAttackPackage,
	MartinMadrazzo,
	EnemyHeliSpin,
	Boost,
	Devin,
	Dock,
	Garage,
	GolfFlag,
	Hangar,
	Helipad,
	JerryCan,
	Mask,
	HeistPrep,
	Incapacitated,
	SpawnPointPickup,
	Boilersuit,
	Completed,
	Rockets,
	GarageForSale,
	HelipadForSale,
	DockForSale,
	HangarForSale,
	Placeholder6,
	Business,
	BusinessForSale,
	RaceBike,
	Parachute,
	TeamDeathmatch,
	RaceFoot,
	VehicleDeathmatch,
	Barry,
	Dom,
	Maryann,
	Cletus,
	Josh,
	Minute,
	Omega,
	Tonya,
	Paparazzo,
	Aim,
	CrateDropBackground,
	GreenAndNetPlayer1,
	GreenAndNetPlayer2,
	GreenAndNetPlayer3,
	GreenAndFriendly,
	NetPlayer1AndNetPlayer2,
	NetPlayer1AndNetPlayer3,
	Creator,
	CreatorDirection,
	Abigail,
	Blimp,
	Repair,
	Testosterone,
	Dinghy,
	Fanatic,
	InfoIcon = 407,
	CaptureTheFlag,
	LastTeamStanding,
	Boat,
	CaptureTheFlagBase,
	CaptureTheFlagOutline = 413,
	CaptureTheFlagBaseNoBag,
	WeaponJerrycan,
	Rp,
	LevelInside,
	BountyHitInside,
	CaptureTheUSAFlag,
	CaptureTheUSAFlagOutline,
	Tank,
	PlayerHeli,
	PlayerPlane,
	PlayerJet,
	CentreStroke,
	PlayerGunCar,
	PlayerBoat,
	MPHeist,
	Temp1,
	Temp2,
	Temp3,
	Temp4,
	Temp5,
	Temp6,
	RaceStunt,
	HotProperty,
	UrbanWarfareVersus,
	KingOfTheCastle,
	PlayerKing,
	DeadDrop,
	PennedIn,
	Beast,
	EdgePointer,
	EdgeCrossTheLine,
	MPLamar,
	Bennys,
	CornerNumber1,
	CornerNumber2,
	CornerNumber3,
	CornerNumber4,
	CornerNumber5,
	CornerNumber6,
	CornerNumber7,
	CornerNumber8,
	Yacht,
	FindersKeepers,
	AssaultPackage,
	HuntTheBoss,
	Sightseer,
	TurretedLimo,
	BellyOfTheBeast,
	YachtLocation,
	PickupBeast,
	PickupZoned,
	PickupRandom,
	PickupSlowTime,
	PickupSwap,
	PickupThermal,
	PickupWeed,
	WeaponRailgun,
	Seashark,
	PickupHidden,
	Warehouse,
	WarehouseForSale,
	Office,
	OfficeForSale,
	Truck,
	Contraband,
	Trailer,
	VIP,
	Cargobob,
	AreaOutline,
	PickupAccelerator,
	PickupGhost,
	PickupDetonator,
	PickupBomb,
	PickupArmoured,
	Stunt,
	WeaponLives,
	StuntPremium,
	Adversary,
	BikerClubhouse,
	BikerCagedIn,
	BikerTurfWar,
	BikerJoust,
	ProductionWeed,
	ProductionCrack,
	ProductionFakeId,
	ProductionMeth,
	ProductionMoney,
	Package,
	Capture1,
	Capture2,
	Capture3,
	Capture4,
	Capture5,
	Capture6,
	Capture7,
	Capture8,
	Capture9,
	Capture10,
	Quad,
	Bus,
	DrugsPackage,
	PickupJump,
	Adversary4,
	Adversary8,
	Adversary10,
	Adversary12,
	Adversary16,
	Laptop,
	PickupDeadline,
	SportsCar,
	WarehouseVehicle,
	RegPapers,
	PoliceStationDropoff,
	Junkyard,
	ExVech1,
	ExVech2,
	ExVech3,
	ExVech4,
	ExVech5,
	ExVech6,
	ExVech7,
	TargetA,
	TargetB,
	TargetC,
	TargetD,
	TargetE,
	TargetF,
	TargetG,
	TargetH,
	Juggernaut,
	PickupRepair,
	SteeringWheel,
	Trophy,
	PickupRocketBoost,
	PickupHomingRocket,
	PickupMachinegun,
	PickupParachute,
	PickupTime5,
	PickupTime10,
	PickupTime15,
	PickupTime20,
	PickupTime30,
	Supplies,
	PropertyBunker,
	GrWvm1,
	GrWvm2,
	GrWvm3,
	GrWvm4,
	GrWvm5,
	GrWvm6,
	GrCovertOps,
	AdversaryBunker,
	GrMocUpgrade,
	GrWUpgrade,
	SmCargo,
	SmHangar,
	TfCheckpoint,
	RaceTf,
	SmWp1,
	SmWp2,
	SmWp3,
	SmWp4,
	SmWp5,
	SmWp6,
	SmWp7,
	SmWp8,
	SmWp9,
	SmWp10,
	SmWp11,
	SmWp12,
	SmWp13,
	SmWp14,
	NhpBag,
	NhpChest,
	NhpOrbit,
	NhpVeh1,
	NhpBase,
	NhpOverlay,
	NhpTurret,
	NhpMgFirewall,
	NhpMgNode,
	NhpWp1,
	NhpWp2,
	NhpWp3,
	NhpWp4,
	NhpWp5,
	NhpWp6,
	NhpWp7,
	NhpWp8,
	NhpWp9,
	NhpCCTV,
	NhpStarterpack,
	NhpTurretConsole,
	NhpMgMirRotate,
	NhpMgMirStatic,
	NhpMgProxy,
	AcsrRaceTarget,
	AcsrRaceHotring,
	AcsrWp1,
	AcsrWp2,
	BatClubProperty,
	BatCargo,
	BatTruck,
	BatHackJewel,
	BatHackGold,
	BatKeypad,
	BatHackTarget,
	PickupDtbHealth,
	PickupDtbBlastIncrease,
	PickupDtbBlastDecrease,
	PickupDtbBombIncrease,
	PickupDtbBombDecrease,
	BatRivalClub,
	BatDrone,
	BatCashReg,
	CCTV,
	BatAssassinate,
	BatPbus,
	BatWp1,
	BatWp2,
	BatWp3,
	BatWp4,
	BatWp5,
	BatWp6,
	Blimp2,
	Oppressor2,
	BatWp7,
	ArenaSeries,
	ArenaPremium,
	ArenaWorkshop,
	RaceWars,
	ArenaTurret,
	ArenaRCCar,
	ArenaRCWorkshop,
	ArenaTrapFire,
	ArenaTrapFlip,
	ArenaTrapSea,
	ArenaTrapTurn,
	ArenaTrapPit,
	ArenaTrapMine,
	ArenaTrapBomb,
	ArenaTrapWall,
	ArenaTrapBrd,
	ArenaTrapSbrd,
	ArenaBruiser,
	ArenaBrutus,
	ArenaCerberus,
	ArenaDeathbike,
	ArenaDominator,
	ArenaImpaler,
	ArenaImperator,
	ArenaIssi,
	ArenaSasquatch,
	ArenaScarab,
	ArenaSlamvan,
	ArenaZr,
};

enum class CheckpointType : uint8_t
{
	CylinderSingleArrow,
	CylinderDoubleArrow,
	CylinderTripleArrow,
	CylinderCycleArrow,
	CylinderCheckerboard,
	CylinderWrench,
	CylinderSingleArrow2,
	CylinderDoubleArrow2,
	CylinderTripleArrow2,
	CylinderCycleArrow2,
	CylinderCheckerboard2,
	CylinderWrench2,
	RingSingleArrow,
	RingDoubleArrow,
	RingTripleArrow,
	RingCycleArrow,
	RingCheckerboard,
	SingleArrow,
	DoubleArrow,
	TripleArrow,
	CycleArrow,
	Checkerboard,
	CylinderSingleArrow3,
	CylinderDoubleArrow3,
	CylinderTripleArrow3,
	CylinderCycleArrow3,
	CylinderCheckerboard3,
	CylinderSingleArrow4,
	CylinderDoubleArrow4,
	CylinderTripleArrow4,
	CylinderCycleArrow4,
	CylinderCheckerboard4,
	CylinderSingleArrow5,
	CylinderDoubleArrow5,
	CylinderTripleArrow5,
	CylinderCycleArrow5,
	CylinderCheckerboard5,
	RingPlaneUp,
	RingPlaneLeft,
	RingPlaneRight,
	RingPlaneDown,
	Empty,
	Ring,
	Empty2,
	Cylinder,
	Cylinder1,
	Cylinder2,
	Cylinder3,
	Cylinder4,
	Cylinder5,
	Empty3,
	Empty4,
	Empty5,
	Empty6,
	RingDollar,
	RingWolf,
	RingQuestionMark,
	RingPlane,
	RingChopper,
	RingBoat,
	RingCar,
	RingBike,
	RingBicycle,
	RingTruck,
	RingParachute,
	RingJetpack,
	RingWhirl,
};

enum class ConnectDeniedReason : uint8_t {
	WrongVersion,
	WrongBranch,
	DebugNotAllowed,
	WrongPassword,
	WrongCdnUrl
};
