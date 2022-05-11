from typing import Any, List, Dict, overload, TypedDict, Set, Callable, Sequence
from enum import Enum, auto

# enums
class WeatherType(Enum):
    ExtraSunny = auto()
    Clear = auto()
    Clouds = auto()
    Smog = auto()
    Foggy = auto()
    Overcast = auto()
    Rain = auto()
    Thunder = auto()
    Clearing = auto()
    Neutral = auto()
    Snow = auto()
    Blizzard = auto()
    Snowlight = auto()
    Xmas = auto()
    Halloween = auto()

class WeaponTint(Enum):
    Normal = auto()
    Green = auto()
    Gold = auto()
    Pink = auto()
    Army = auto()
    LSPD = auto()
    Orange = auto()
    Platinum = auto()


class VehicleModType(Enum):
    Spoiler = auto()
    FrontBumper = auto()
    RearBumper = auto()
    SideSkirt = auto()
    Exhaust = auto()
    Frame = auto()
    Grille = auto()
    Hood = auto()
    Fender = auto()
    RightFender = auto()
    Roof = auto()
    Engine = auto()
    Brakes = auto()
    Transmission = auto()
    Horn = auto()
    Suspension = auto()
    Armor = auto()
    Unk1 = auto()
    Turbo = auto()
    Unk2 = auto()
    TireSmoke = auto()
    Unk3 = auto()
    XenonLights = auto()
    FrontWheels = auto()
    BackWheels = auto()
    Plateholder = auto()
    VanityPlates = auto()
    TrimDesign = auto()
    Ornaments = auto()
    Dashboard = auto()
    Dial = auto()
    DoorSpeaker = auto()
    Seats = auto()
    SteeringWheel = auto()
    ColumnShifterLeavers = auto()
    Plaques = auto()
    Speakers = auto()
    Trunk = auto()
    Hydraulics = auto()
    EngineBlock = auto()
    AirFilter = auto()
    Struts = auto()
    ArchCover = auto()
    Aerials = auto()
    Trim = auto()
    Tank = auto()
    Windows = auto()
    Unk4 = auto()
    Livery = auto()


class WindowTint(Enum):
    DarkSmoke = auto()
    Green = auto()
    LightSmoke = auto()
    Limo = auto()
    Clear = auto()
    PureBlack = auto()
    Stock = auto()


class RadioStation(Enum):
    LosSantosRockRadio  = auto()
    NonStopPopFm  = auto()
    RadioLosSantos  = auto()
    ChannelX  = auto()
    WestCoastTalkRadio  = auto()
    RebelRadio  = auto()
    SoulwaxFm  = auto()
    EastLosFm  = auto()
    WestCoastClassics  = auto()
    BlaineCountyRadio  = auto()
    TheBlueArk  = auto()
    WorldWideFm  = auto()
    FlyloFm  = auto()
    TheLowdown  = auto()
    RadioMirrorPark  = auto()
    Space  = auto()
    VinewoodBoulevardRadio  = auto()
    SelfRadio  = auto()
    TheLab  = auto()
    RadioOff = 255


class VehicleLockState(Enum):
    Nothing = auto()
    Unlocked = auto()
    Locked = auto()
    LockoutPlayerOnly = auto()
    LockPlayerInside = auto()
    InitiallyLocked = auto()
    ForceDoorsShut = auto()
    LockedCanBeDamaged = auto()


class VehicleDoor(Enum):
    DriverFront = auto()
    PassengerFront = auto()
    DriverRear = auto()
    PassengerRear = auto()
    Hood = auto()
    Trunk = auto()


class VehicleDoorState(Enum):
    Closed = auto()
    OpenedLevel1 = auto()
    OpenedLevel2 = auto()
    OpenedLevel3 = auto()
    OpenedLevel4 = auto()
    OpenedLevel5 = auto()
    OpenedLevel6 = auto()
    OpenedLevel7 = auto()
    Unknown = 255


class VehiclePart(Enum):
    FrontLeft = auto()
    FrontRight = auto()
    MiddleLeft = auto()
    MiddleRight = auto()
    RearLeft = auto()
    RearRight = auto()


class VehiclePartDamage(Enum):
    NotDamaged = auto()
    DamagedLevel1 = auto()
    DamagedLevel2 = auto()
    DamagedLevel3 = auto()


class VehicleBumper(Enum):
    Front = auto()
    Rear = auto()

class VehicleBumperDamage(Enum):
    NotDamaged = auto()
    Damaged = auto()
    Nothing = auto()

class NumberPlateStyle(Enum):
    BlueWhite = auto()
    BlueWhite2 = auto()
    BlueWhite3 = auto()
    Yankton = auto()
    YellowBlack = auto()
    YellowBlue = auto()

class Event(Enum):
	ServerStarted = 1
	PlayerConnect = auto()
	PlayerBeforeConnect = auto()
	PlayerDisconnect = auto()
	ConnectionQueueAdd = auto()
	ConnectionQueueRemove = auto()
	ResourceStart = auto()
	ResourceStop = auto()
	ResourceError = auto()
	SyncedMetaChange = 13
	StreamSyncedMetaChange = auto()
	GlobalMetaChange = auto()
	GlobalSyncedMetaChange = auto()
	LocalMetaChange = auto()
	PlayerDamage = auto()
	PlayerDeath = auto()
	Fire = auto()
	Explosion = auto()
	StartProjectile = auto()
	WeaponDamage = auto()
	VehicleDestroy = auto()
	VehicleDamage = auto()
	ColShape = 27
	PlayerEnterVehicle = auto()
	PlayerEnteringVehicle = auto()
	PlayerLeftVehicle = auto()
	PlayerChangeVehicleSeat = auto()
	PlayerWeaponChange = auto()
	PlayerRequestControl = auto()
	VehicleAttach = auto()
	VehicleDetach = auto()
	NetOwnerChange = auto()
	RemoveEntity = auto()
	ConsoleCommand = 41

class ExplosionType(Enum):
	Grenade = 0
	GrenadeLauncher = auto()
	StickyBomb = auto()
	Molotov = auto()
	Rocket = auto()
	TankShell = auto()
	HiOctane = auto()
	Car = auto()
	Plane = auto()
	PetrolPump = auto()
	Bike = auto()
	DirSteam = auto()
	DirFlame = auto()
	DirWaterHydrant = auto()
	DirGasCanister = auto()
	Boat = auto()
	ShipDestroy = auto()
	Truck = auto()
	Bullet = auto()
	SmokeGrenadeLauncher = auto()
	SmokeGrenade = auto()
	BzGas = auto()
	Flare = auto()
	GasCanister = auto()
	Extinguisher = auto()
	ProgrammableAr = auto()
	Train = auto()
	Barrel = auto()
	Propane = auto()
	Blimp = auto()
	DirFlameExplode = auto()
	Tanker = auto()
	PlaneRocket = auto()
	VehicleBullet = auto()
	GasTank = auto()
	Firework = auto()
	Snowball = auto()
	ProxMine = auto()
	ValkyrieCannon = auto()
	Unknown = -1

class BodyPart(Enum):
	Pelvis = auto()
	LeftHip = auto()
	LeftLeg = auto()
	LeftFoot = auto()
	RightHip = auto()
	RightLeg = auto()
	RightFoot = auto()
	LowerTorso = auto()
	UpperTorso = auto()
	Chest = auto()
	UnderNeck = auto()
	LeftShoulder = auto()
	LeftUpperArm = auto()
	LeftElbrow = auto()
	LeftWrist = auto()
	RightShoulder = auto()
	RightUpperArm = auto()
	RightElbrow = auto()
	RightWrist = auto()
	Neck = auto()
	Head = auto()
	Unknown = -1


class VehicleType(Enum):
	Invalid = auto()
	Ped = auto()
	Automobile = auto()
	Plane = auto()
	Trailer = auto()
	QuadBike = auto()
	SubmarineCar = auto()
	AmphibiousAutomobile = auto()
	AmphibiousQuadBike = auto()
	Heli = auto()
	Blimp = auto()
	AutoGyro = auto()
	Bike = auto()
	BMX = auto()
	Boat = auto()
	Train = auto()
	Submarine = auto()
	Object = auto()


class ColShapeType(Enum):
	Sphere = auto()
	Cylinder = auto()
	Circle = auto()
	Cuboid = auto()
	Rect = auto()
	CheckpointCylinder = auto()
	Polygon = auto()


class BaseObjectType(Enum):
	Player = auto()
	Vehicle = auto()
	Blip = auto()
	WebView = auto()
	VoiceChannel = auto()
	ColShape = auto()
	Checkpoint = auto()
	WebSocketClient = auto()
	HttpClient = auto()
	Audio = auto()
	RmlElement = auto()
	RmlDocument = auto()
	LocalPlayer = auto()

class BlipColor(Enum):
	White = auto()
	Red = auto()
	Green = auto()
	Blue = auto()
	Yellow = 5
	LightRed = auto()
	Violet = auto()
	Pink = auto()
	LightOrange = auto()
	LightBrown = auto()
	LightGreen = auto()
	LightBlue = auto()
	LightPurple = auto()
	DarkPurple = auto()
	Cyan = auto()
	LightYellow = auto()
	Organe = auto()
	DarkPink = 19
	GraniteGreen = auto()
	DarkBrown = auto()
	LightGray = auto()
	LightPink = auto()
	LemonGreen = auto()
	ForestGreen = auto()
	ElectricBlue = auto()
	BrightPurple = auto()
	DarkYellow = auto()
	DarkCyan = 30
	Beige = 36
	DarkGray = 40
	PinkRed = auto()
	Gold = 46
	Orange = auto()
	BrilliantRose = auto()
	MediumPurple = 50
	Salmon = auto()
	DarkGreen = auto()
	BlizzardBlue = auto()
	OracleBlue = auto()
	Silver = auto()
	EastBay = 58
	YellowOrange = 60
	MulberryPink = auto()
	AltoGray = auto()
	JellyBeanBlue = auto()
	DarkOrange = auto()
	Mamba = auto()
	Default = auto()
	TransparentBlack = 72
	DeepRed = 76
	TransparentRed = 79
	TransparentBlue = 80
	Purple = 83

class BlipSprite(Enum):
	Higher = auto()
	Lower = auto()
	PolicePed = auto()
	WantedRadius = auto()
	Area = auto()
	Centre = auto()
	North = auto()
	Waypoint = auto()
	Radius = auto()
	RadiusOutline = auto()
	WeaponHigher = auto()
	WeaponLower = auto()
	HigherAI = auto()
	LowerAI = auto()
	PoliceHeliSpin = auto()
	PolicePlaneMove = auto()
	MPCrew = 27
	MPFriendlies = auto()
	CableCar = 36
	Activities = auto()
	Raceflag = auto()
	Safehouse = 40
	Police = auto()
	PoliceChase = auto()
	PoliceHeli = auto()
	BombA = auto()
	Snitch = 47
	PlanningLocations = auto()
	CriminalCarsteal = 50
	CriminalDrugs = auto()
	CriminalHoldups = auto()
	CriminalPlayer = 54
	CopPatrol = 56
	CopPlayer = auto()
	CriminalWanted = auto()
	Heist = auto()
	PoliceStation = auto()
	Hospital = auto()
	AssassinsMark = auto()
	Elevator = auto()
	Helicopter = auto()
	RandomCharacter = 66
	SecurityVan = auto()
	TowTruck = auto()
	IllegalParking = 70
	Barber = auto()
	CarModShop = auto()
	ClothesStore = auto()
	Tattoo = 75
	ArmenianFamily = auto()
	LesterFamily = auto()
	MichaelFamily = auto()
	TrevorFamily = auto()
	JewelryHeist = auto()
	DragRaceFinish = 82
	Rampage = 84
	VinewoodTours = auto()
	LamarFamily = auto()
	FranklinFamily = 88
	ChineseStrand = auto()
	FlightSchool = auto()
	EyeSky = auto()
	AirHockey = auto()
	Bar = auto()
	BaseJump = auto()
	Basketball = auto()
	BiolabHeist = 96
	CabaretClub = 99
	CarWash = auto()
	ComedyClub = 102
	Darts = auto()
	DocksHeist = auto()
	FbiHeist = auto()
	FbiOfficersStrand = auto()
	FinaleBankHeist = auto()
	FinancierStrand = auto()
	Golf = auto()
	GunShop = auto()
	InternetCafe = auto()
	MichaelFamilyExile = auto()
	NiceHouseHeist = auto()
	RandomFemale = auto()
	RandomMale = auto()
	RuralBankHeist = 118
	ShootingRange = auto()
	SolomonStrand = auto()
	StripClub = auto()
	Tennis = auto()
	TrevorFamilyExile = auto()
	MichaelTrevorFamily = auto()
	Triathlon = 126
	OffRoadRacing = auto()
	GangCops = auto()
	GangMexicans = auto()
	GangBikers = auto()
	SnitchRed = 133
	CriminalCuffKeys = auto()
	Cinema = auto()
	MusicVenue = auto()
	PoliceStationBlue = auto()
	Airport = auto()
	CriminalSavedVehicle = auto()
	WeedStash = auto()
	Hunting = auto()
	Pool = auto()
	ObjectiveBlue = auto()
	ObjectiveGreen = auto()
	ObjectiveRed = auto()
	ObjectiveYellow = auto()
	ArmsDealing = auto()
	MPFriend = auto()
	CelebrityTheft = auto()
	WeaponAssaultRifle = auto()
	WeaponBat = auto()
	WeaponGrenade = auto()
	WeaponHealth = auto()
	WeaponKnife = auto()
	WeaponMolotov = auto()
	WeaponPistol = auto()
	WeaponRocket = auto()
	WeaponShotgun = auto()
	WeaponSmg = auto()
	WeaponSniper = auto()
	MPNoise = auto()
	PointOfInterest = auto()
	Passive = auto()
	UsingMenu = auto()
	GangCopsPartner = 171
	WeaponMinigun = 173
	WeaponArmour = 175
	PropertyTakeover  = auto()
	GangMexicansHighlight  = auto()
	GangBikersHighlight  = auto()
	TriathlonCycling  = auto()
	TriathlonSwimming  = auto()
	PropertyTakeoverBikers  = auto()
	PropertyTakeoverCops  = auto()
	PropertyTakeoverVagos  = auto()
	Camera  = auto()
	CentreRed  = auto()
	HandcuffKeysBikers  = auto()
	HandcuffKeysVagos  = auto()
	HandcuffsClosedBikers  = auto()
	HandcuffsClosedVagos  = auto()
	CameraBadger = 192
	CameraFacade = auto()
	CameraIfruit = auto()
	Yoga = 197
	Taxi = auto()
	Shrink = 205
	Epsilon = auto()
	FinancierStrandGrey = auto()
	TrevorFamilyGrey = auto()
	TrevorFamilyRed = auto()
	FranklinFamilyGrey = auto()
	FranklinFamilyBlue = auto()
	FranklinA = auto()
	FranklinB = auto()
	FranklinC = auto()
	GangVehicle = 225
	GangVehicleBikers = auto()
	GangVehicleCops = auto()
	GangVehicleVagos = auto()
	Gunca = auto()
	DrivingBikers = auto()
	DrivingCops = auto()
	DrivingVagos = auto()
	GangCopsHighlight = auto()
	ShieldBikers = auto()
	ShieldCops = 235
	ShieldVagos = auto()
	CustodyBikers = auto()
	CustodyVagos = auto()
	ArmsDealingAir = 251
	PlayerStateArrested = auto()
	PlayerStateCustody = auto()
	PlayerStateDriving = auto()
	PlayerStateKeyholder = auto()
	PlayerStatePartner = auto()
	Ztype = 262
	Stinger = auto()
	Packer = auto()
	Monroe = auto()
	Fairground = auto()
	Property = auto()
	GangHighlight = auto()
	Altruist = auto()
	AI = auto()
	OnMission = auto()
	CashPickup = auto()
	Chop = auto()
	Dead = auto()
	TerritoryLocked = auto()
	CashLost = auto()
	CashVagos = auto()
	CashCops = auto()
	Hooker = auto()
	Friend = auto()
	Mission2to4 = auto()
	Mission2to8 = auto()
	Mission2to12 = auto()
	Mission2to16 = auto()
	CustodyDropOff = auto()
	OnMissionCops = auto()
	OnMissionLost = auto()
	OnMissionVagos = auto()
	CriminalCarStealCops = auto()
	CriminalCarStealBikers = auto()
	CriminalCarStealVagos = auto()
	BandStrand = auto()
	SimeonFamily = auto()
	Mission1 = auto()
	Mission2 = auto()
	FriendDarts = auto()
	FriendComedyClub = auto()
	FriendCinema = auto()
	FriendTennis = auto()
	FriendStripClub = auto()
	FriendLiveMusic = auto()
	FriendGolf = auto()
	BountyHit = auto()
	UgcMission = auto()
	Horde = auto()
	CrateDrop = auto()
	PlaneDrop = auto()
	Sub = auto()
	Race = auto()
	Deathmatch = auto()
	ArmWrestling = auto()
	Mission1to2 = auto()
	ShootingRangeGunShop = auto()
	RaceAir = auto()
	RaceLand = auto()
	RaceSea = auto()
	Tow = auto()
	Garbage = auto()
	Drill = auto()
	Spikes = auto()
	Firetruck = auto()
	Minigun2 = auto()
	Bugstar = auto()
	Submarine = auto()
	Chinook = auto()
	GetawayCar = auto()
	MissionBikers1 = auto()
	MissionBikers1to2 = auto()
	MissionBikers2 = auto()
	MissionBikers2to4 = auto()
	MissionBikers2to8 = auto()
	MissionBikers2to12 = auto()
	MissionBikers2to16 = auto()
	MissionCops1 = auto()
	MissionCops1to2 = auto()
	MissionCops2 = auto()
	MissionCops2to4 = auto()
	MissionCops2to8 = auto()
	MissionCops2to12 = auto()
	MissionCops2to16 = auto()
	MissionVagos1 = auto()
	MissionVagos1to2 = auto()
	MissionVagos2 = auto()
	MissionVagos2to4 = auto()
	MissionVagos2to8 = auto()
	MissionVagos2to12 = auto()
	MissionVagos2to16 = auto()
	GangBike = auto()
	GasGrenade = auto()
	PropertyForSale = auto()
	GangAttackPackage = auto()
	MartinMadrazzo = auto()
	EnemyHeliSpin = auto()
	Boost = auto()
	Devin = auto()
	Dock = auto()
	Garage = auto()
	GolfFlag = auto()
	Hangar = auto()
	Helipad = auto()
	JerryCan = auto()
	Mask = auto()
	HeistPrep = auto()
	Incapacitated = auto()
	SpawnPointPickup = auto()
	Boilersuit = auto()
	Completed = auto()
	Rockets = auto()
	GarageForSale = auto()
	HelipadForSale = auto()
	DockForSale = auto()
	HangarForSale = auto()
	Placeholder6 = auto()
	Business = auto()
	BusinessForSale = auto()
	RaceBike = auto()
	Parachute = auto()
	TeamDeathmatch = auto()
	RaceFoot = auto()
	VehicleDeathmatch = auto()
	Barry = auto()
	Dom = auto()
	Maryann = auto()
	Cletus = auto()
	Josh = auto()
	Minute = auto()
	Omega = auto()
	Tonya = auto()
	Paparazzo = auto()
	Aim = auto()
	CrateDropBackground = auto()
	GreenAndNetPlayer1 = auto()
	GreenAndNetPlayer2 = auto()
	GreenAndNetPlayer3 = auto()
	GreenAndFriendly = auto()
	NetPlayer1AndNetPlayer2 = auto()
	NetPlayer1AndNetPlayer3 = auto()
	Creator = auto()
	CreatorDirection = auto()
	Abigail = auto()
	Blimp = auto()
	Repair = auto()
	Testosterone = auto()
	Dinghy = auto()
	Fanatic = auto()
	InfoIcon = 407
	CaptureTheFlag = auto()
	LastTeamStanding = auto()
	Boat = auto()
	CaptureTheFlagBase = auto()
	CaptureTheFlagOutline = 413
	CaptureTheFlagBaseNoBag = auto()
	WeaponJerrycan = auto()
	Rp = auto()
	LevelInside = auto()
	BountyHitInside = auto()
	CaptureTheUSAFlag = auto()
	CaptureTheUSAFlagOutline = auto()
	Tank = auto()
	PlayerHeli = auto()
	PlayerPlane = auto()
	PlayerJet = auto()
	CentreStroke = auto()
	PlayerGunCar = auto()
	PlayerBoat = auto()
	MPHeist = auto()
	Temp1 = auto()
	Temp2 = auto()
	Temp3 = auto()
	Temp4 = auto()
	Temp5 = auto()
	Temp6 = auto()
	RaceStunt = auto()
	HotProperty = auto()
	UrbanWarfareVersus = auto()
	KingOfTheCastle = auto()
	PlayerKing = auto()
	DeadDrop = auto()
	PennedIn = auto()
	Beast = auto()
	EdgePointer = auto()
	EdgeCrossTheLine = auto()
	MPLamar = auto()
	Bennys = auto()
	CornerNumber1 = auto()
	CornerNumber2 = auto()
	CornerNumber3 = auto()
	CornerNumber4 = auto()
	CornerNumber5 = auto()
	CornerNumber6 = auto()
	CornerNumber7 = auto()
	CornerNumber8 = auto()
	Yacht = auto()
	FindersKeepers = auto()
	AssaultPackage = auto()
	HuntTheBoss = auto()
	Sightseer = auto()
	TurretedLimo = auto()
	BellyOfTheBeast = auto()
	YachtLocation = auto()
	PickupBeast = auto()
	PickupZoned = auto()
	PickupRandom = auto()
	PickupSlowTime = auto()
	PickupSwap = auto()
	PickupThermal = auto()
	PickupWeed = auto()
	WeaponRailgun = auto()
	Seashark = auto()
	PickupHidden = auto()
	Warehouse = auto()
	WarehouseForSale = auto()
	Office = auto()
	OfficeForSale = auto()
	Truck = auto()
	Contraband = auto()
	Trailer = auto()
	VIP = auto()
	Cargobob = auto()
	AreaOutline = auto()
	PickupAccelerator = auto()
	PickupGhost = auto()
	PickupDetonator = auto()
	PickupBomb = auto()
	PickupArmoured = auto()
	Stunt = auto()
	WeaponLives = auto()
	StuntPremium = auto()
	Adversary = auto()
	BikerClubhouse = auto()
	BikerCagedIn = auto()
	BikerTurfWar = auto()
	BikerJoust = auto()
	ProductionWeed = auto()
	ProductionCrack = auto()
	ProductionFakeId = auto()
	ProductionMeth = auto()
	ProductionMoney = auto()
	Package = auto()
	Capture1 = auto()
	Capture2 = auto()
	Capture3 = auto()
	Capture4 = auto()
	Capture5 = auto()
	Capture6 = auto()
	Capture7 = auto()
	Capture8 = auto()
	Capture9 = auto()
	Capture10 = auto()
	Quad = auto()
	Bus = auto()
	DrugsPackage = auto()
	PickupJump = auto()
	Adversary4 = auto()
	Adversary8 = auto()
	Adversary10 = auto()
	Adversary12 = auto()
	Adversary16 = auto()
	Laptop = auto()
	PickupDeadline = auto()
	SportsCar = auto()
	WarehouseVehicle = auto()
	RegPapers = auto()
	PoliceStationDropoff = auto()
	Junkyard = auto()
	ExVech1 = auto()
	ExVech2 = auto()
	ExVech3 = auto()
	ExVech4 = auto()
	ExVech5 = auto()
	ExVech6 = auto()
	ExVech7 = auto()
	TargetA = auto()
	TargetB = auto()
	TargetC = auto()
	TargetD = auto()
	TargetE = auto()
	TargetF = auto()
	TargetG = auto()
	TargetH = auto()
	Juggernaut = auto()
	PickupRepair = auto()
	SteeringWheel = auto()
	Trophy = auto()
	PickupRocketBoost = auto()
	PickupHomingRocket = auto()
	PickupMachinegun = auto()
	PickupParachute = auto()
	PickupTime5 = auto()
	PickupTime10 = auto()
	PickupTime15 = auto()
	PickupTime20 = auto()
	PickupTime30 = auto()
	Supplies = auto()
	PropertyBunker = auto()
	GrWvm1 = auto()
	GrWvm2 = auto()
	GrWvm3 = auto()
	GrWvm4 = auto()
	GrWvm5 = auto()
	GrWvm6 = auto()
	GrCovertOps = auto()
	AdversaryBunker = auto()
	GrMocUpgrade = auto()
	GrWUpgrade = auto()
	SmCargo = auto()
	SmHangar = auto()
	TfCheckpoint = auto()
	RaceTf = auto()
	SmWp1 = auto()
	SmWp2 = auto()
	SmWp3 = auto()
	SmWp4 = auto()
	SmWp5 = auto()
	SmWp6 = auto()
	SmWp7 = auto()
	SmWp8 = auto()
	SmWp9 = auto()
	SmWp10 = auto()
	SmWp11 = auto()
	SmWp12 = auto()
	SmWp13 = auto()
	SmWp14 = auto()
	NhpBag = auto()
	NhpChest = auto()
	NhpOrbit = auto()
	NhpVeh1 = auto()
	NhpBase = auto()
	NhpOverlay = auto()
	NhpTurret = auto()
	NhpMgFirewall = auto()
	NhpMgNode = auto()
	NhpWp1 = auto()
	NhpWp2 = auto()
	NhpWp3 = auto()
	NhpWp4 = auto()
	NhpWp5 = auto()
	NhpWp6 = auto()
	NhpWp7 = auto()
	NhpWp8 = auto()
	NhpWp9 = auto()
	NhpCCTV = auto()
	NhpStarterpack = auto()
	NhpTurretConsole = auto()
	NhpMgMirRotate = auto()
	NhpMgMirStatic = auto()
	NhpMgProxy = auto()
	AcsrRaceTarget = auto()
	AcsrRaceHotring = auto()
	AcsrWp1 = auto()
	AcsrWp2 = auto()
	BatClubProperty = auto()
	BatCargo = auto()
	BatTruck = auto()
	BatHackJewel = auto()
	BatHackGold = auto()
	BatKeypad = auto()
	BatHackTarget = auto()
	PickupDtbHealth = auto()
	PickupDtbBlastIncrease = auto()
	PickupDtbBlastDecrease = auto()
	PickupDtbBombIncrease = auto()
	PickupDtbBombDecrease = auto()
	BatRivalClub = auto()
	BatDrone = auto()
	BatCashReg = auto()
	CCTV = auto()
	BatAssassinate = auto()
	BatPbus = auto()
	BatWp1 = auto()
	BatWp2 = auto()
	BatWp3 = auto()
	BatWp4 = auto()
	BatWp5 = auto()
	BatWp6 = auto()
	Blimp2 = auto()
	Oppressor2 = auto()
	BatWp7 = auto()
	ArenaSeries = auto()
	ArenaPremium = auto()
	ArenaWorkshop = auto()
	RaceWars = auto()
	ArenaTurret = auto()
	ArenaRCCar = auto()
	ArenaRCWorkshop = auto()
	ArenaTrapFire = auto()
	ArenaTrapFlip = auto()
	ArenaTrapSea = auto()
	ArenaTrapTurn = auto()
	ArenaTrapPit = auto()
	ArenaTrapMine = auto()
	ArenaTrapBomb = auto()
	ArenaTrapWall = auto()
	ArenaTrapBrd = auto()
	ArenaTrapSbrd = auto()
	ArenaBruiser = auto()
	ArenaBrutus = auto()
	ArenaCerberus = auto()
	ArenaDeathbike = auto()
	ArenaDominator = auto()
	ArenaImpaler = auto()
	ArenaImperator = auto()
	ArenaIssi = auto()
	ArenaSasquatch = auto()
	ArenaScarab = auto()
	ArenaSlamvan = auto()
	ArenaZ = auto()

class CheckpointType(Enum):
	CylinderSingleArrow = 0
	CylinderDoubleArrow = auto()
	CylinderTripleArrow = auto()
	CylinderCycleArrow = auto()
	CylinderCheckerboard = auto()
	CylinderWrench = auto()
	CylinderSingleArrow2 = auto()
	CylinderDoubleArrow2 = auto()
	CylinderTripleArrow2 = auto()
	CylinderCycleArrow2 = auto()
	CylinderCheckerboard2 = auto()
	CylinderWrench2 = auto()
	RingSingleArrow = auto()
	RingDoubleArrow = auto()
	RingTripleArrow = auto()
	RingCycleArrow = auto()
	RingCheckerboard = auto()
	SingleArrow = auto()
	DoubleArrow = auto()
	TripleArrow = auto()
	CycleArrow = auto()
	Checkerboard = auto()
	CylinderSingleArrow3 = auto()
	CylinderDoubleArrow3 = auto()
	CylinderTripleArrow3 = auto()
	CylinderCycleArrow3 = auto()
	CylinderCheckerboard3 = auto()
	CylinderSingleArrow4 = auto()
	CylinderDoubleArrow4 = auto()
	CylinderTripleArrow4 = auto()
	CylinderCycleArrow4 = auto()
	CylinderCheckerboard4 = auto()
	CylinderSingleArrow5 = auto()
	CylinderDoubleArrow5 = auto()
	CylinderTripleArrow5 = auto()
	CylinderCycleArrow5 = auto()
	CylinderCheckerboard5 = auto()
	RingPlaneUp = auto()
	RingPlaneLeft = auto()
	RingPlaneRight = auto()
	RingPlaneDown = auto()
	Empty = auto()
	Ring = auto()
	Empty2 = auto()
	Cylinder = auto()
	Cylinder1 = auto()
	Cylinder2 = auto()
	Cylinder3 = auto()
	Cylinder4 = auto()
	Cylinder5 = auto()
	Empty3 = auto()
	Empty4 = auto()
	Empty5 = auto()
	Empty6 = auto()
	RingDollar = auto()
	RingWolf = auto()
	RingQuestionMark = auto()
	RingPlane = auto()
	RingChopper = auto()
	RingBoat = auto()
	RingCar = auto()
	RingBike = auto()
	RingBicycle = auto()
	RingTruck = auto()
	RingParachute = auto()
	RingJetpack = auto()
	RingWhir = auto()

class IVector2(TypedDict):
	x: float
	y: float

class Vector2:
	@property
	def x(self) -> float: ...
	@x.setter
	def x(self, new_x: float) -> None: ...

	@property
	def y(self) -> float: ...
	@y.setter
	def y(self, new_y: float) -> None: ...

	zero: Vector2
	one: Vector2
	up: Vector2
	down: Vector2
	left: Vector2
	right: Vector2
	back: Vector2
	forward: Vector2
	positive_infinity: Vector2
	negative_infinity: Vector2

	# Constructor
	@overload
	def __init__(self, x: float, y: float) -> None: ...

	@overload
	def __init__(self, vector_list: List[float]) -> None: ...

	# Methods
	def to_dict(self) -> IVector2: ...
	def to_list(self) -> List[float]: ...
	def length(self) -> float: ...
	def distance(self) -> float: ...
	def to_degrees(self, vec: Vector2) -> Vector2: ...
	def to_radians(self, vec: Vector2) -> Vector2: ...
	def is_in_range(self, vec: Vector2, range: float) -> bool: ...

	@overload
	def __add__(self, other: Vector2) -> Vector2: ...
	@overload
	def __add__(self, num: float) -> Vector2: ...
	@overload
	def __add__(self, vector_list: List[float]) -> Vector2: ...

	@overload
	def __sub__(self, other: Vector2) -> Vector2: ...
	@overload
	def __sub__(self, num: float) -> Vector2: ...
	@overload
	def __sub__(self, vector_list: List[float]) -> Vector2: ...

	@overload
	def __mul__(self, other: Vector2) -> Vector2: ...
	@overload
	def __mul__(self, num: float) -> Vector2: ...
	@overload
	def __mul__(self, vector_list: List[float]) -> Vector2: ...

	@overload
	def __truediv__(self, other: Vector2) -> Vector2: ...
	@overload
	def __truediv__(self, num: float) -> Vector2: ...
	@overload
	def __truediv__(self, vector_list: List[float]) -> Vector2: ...

	def __neg__(self) -> Vector2: ...

	@overload
	def dot(self, vec: Vector2) -> Vector2: ...
	@overload
	def dot(self, num: int) -> Vector2: ...
	@overload
	def dot(self, list: List[int]) -> Vector2: ...

	def normalize(self) -> Vector2: ...
	def angle_to(self, vector: Vector2) -> float: ...
	def angle_to_degrees(self, vector: Vector2) -> float: ...

class IVector3(TypedDict):
	x: float
	y: float
	z: float

class Vector3:
	@property
	def x(self) -> float: ...
	@x.setter
	def x(self, new_x: float) -> None: ...

	@property
	def y(self) -> float: ...
	@y.setter
	def y(self, new_y: float) -> None: ...

	@property
	def z(self) -> float: ...
	@z.setter
	def z(self, new_z: float) -> None: ...

	zero: Vector3
	one: Vector3
	up: Vector3
	down: Vector3
	left: Vector3
	right: Vector3
	back: Vector3
	forward: Vector3
	positive_infinity: Vector3
	negative_infinity: Vector3

	# Constructor
	@overload
	def __init__(self, x: float, y: float, z: float) -> None: ...

	@overload
	def __init__(self, vector_list: List[float]) -> None: ...

	# Methods
	def to_dict(self) -> IVector3: ...
	def to_list(self) -> List[int]: ...
	def length(self) -> float: ...
	def distance(self) -> float: ...
	def to_degrees(self, vec: Vector3) -> Vector3: ...
	def to_radians(self, vec: Vector3) -> Vector3: ...
	def is_in_range(self, vec: Vector3, range: float) -> bool: ...

	@overload
	def __add__(self, other: Vector3) -> Vector3: ...
	@overload
	def __add__(self, num: float) -> Vector3: ...
	@overload
	def __add__(self, vector_list: List[float]) -> Vector3: ...

	@overload
	def __sub__(self, other: Vector3) -> Vector3: ...
	@overload
	def __sub__(self, num: float) -> Vector3: ...
	@overload
	def __sub__(self, vector_list: List[float]) -> Vector3: ...

	@overload
	def __mul__(self, other: Vector3) -> Vector3: ...
	@overload
	def __mul__(self, num: float) -> Vector3: ...
	@overload
	def __mul__(self, vector_list: List[float]) -> Vector3: ...

	@overload
	def __truediv__(self, other: Vector3) -> Vector3: ...
	@overload
	def __truediv__(self, num: float) -> Vector3: ...
	@overload
	def __truediv__(self, vector_list: List[float]) -> Vector3: ...

	def __neg__(self) -> Vector3: ...

	@overload
	def cross(self, vec: Vector3) -> Vector3: ...
	@overload
	def cross(self, num: int) -> Vector3: ...
	@overload
	def cross(self, list: List[int]) -> Vector3: ...

	@overload
	def dot(self, vec: Vector3) -> Vector3: ...
	@overload
	def dot(self, num: int) -> Vector3: ...
	@overload
	def dot(self, list: List[int]) -> Vector3: ...

	def normalize(self) -> Vector3: ...
	def angle_to(self, vector: Vector3) -> float: ...
	def angle_to_degrees(self, vector: Vector3) -> float: ...


class RGBA:
	r: int
	g: int
	b: int
	a: int

	# Constructor
	def __init__(self, r: int, g: int, b: int, a: int) -> None: ...

	def to_bgra(self) -> RGBA: ...
	def to_argb(self) -> RGBA: ...


class BaseObject:
	# Properties
	@property
	def ref_count(self) -> int: ...

	@property
	def valid(self) -> bool: ...

	@property
	def type(self) -> BaseObjectType: ...

	# Methods
	def delete_meta(self, key: str) -> None: ...
	def get_meta(self, key: str) -> Any: ...
	def set_meta(self, key: str, value: Any) -> None: ...
	def has_meta(self, key: str) -> bool: ...
	def destroy(self) -> None: ...


class WorldObject(BaseObject):
	# Properties
	@property
	def pos(self) -> Vector3: ...
	@pos.setter
	def pos(self, new_pos: Vector3) -> None: ...

	@property
	def dimension(self) -> int: ...
	@dimension.setter
	def dimension(self, new_dimension: int) -> None: ...


class Entity(WorldObject):
	# Properties
	all: Sequence[Entity]

	@property
	def id(self) -> int: ...

	@property
	def rot(self) -> Vector3: ...
	@rot.setter
	def rot(self, new_rot: Vector3) -> None: ...

	@property
	def streamed(self) -> bool: ...
	@streamed.setter
	def streamed(self, state: bool) -> None: ...

	@property
	def visible(self) -> bool: ...
	@visible.setter
	def visible(self, state: bool) -> None: ...

	@property
	def collision(self) -> bool: ...
	@collision.setter
	def collision(self, state: bool) -> None: ...

	@property
	def frozen(self) -> bool: ...
	@frozen.setter
	def frozen(self, state: bool) -> None: ...

	@property
	def model(self) -> int: ...
	@model.setter
	def model(self, new_model: int | str) -> None: ...

	@property
	def net_owner(self) -> Player | None: ...

	# Methods
	@staticmethod
	def get_by_id(id: int) -> Entity | None: ...

	def set_net_owner(self, player: Player, disable_migration: bool = False) -> None: ...
	def reset_net_owner(self, disable_migration: bool = False) -> None: ...

	def attach_to(self, entity: Entity, bone: int) -> None: ...
	def detach(self) -> None: ...

	def get_synced_meta(self, key: str) -> Any: ...
	def has_synced_meta(self, key: str) -> bool: ...
	def set_synced_meta(self, key: str, value: Any) -> None: ...
	def delete_synced_meta(self, key: str) -> None: ...

	def get_stream_synced_meta(self, key: str) -> Any: ...
	def has_stream_synced_meta(self, key: str) -> bool: ...
	def set_stream_synced_meta(self, key: str, value: Any) -> None: ...
	def delete_stream_synced_meta(self, key: str) -> None: ...

class Weapon(TypedDict):
	hash: int
	tint_index: int
	components: Set[int]

class HeadOverlay(TypedDict):
	index: int
	opacity: float
	color_type: int
	color_index: int
	second_color_index: int

class HeadBlendData(TypedDict):
	shape_first_id: int
	shape_second_id: int
	shape_third_id: int
	skin_first_id: int
	skin_second_id: int
	skin_third_id: int
	shape_mix: float
	skin_mix: float
	third_mix: float

class Cloth(TypedDict):
	drawable: int
	texture: int
	palette: int

class DlcCloth(TypedDict):
	dlc: int
	drawable: int
	texture: int
	palette: int

class Prop(TypedDict):
	drawable: int
	texture: int

class DlcProp(TypedDict):
	dlc: int
	drawable: int
	texture: int

class Player(Entity):
	# Properties
	all: Sequence[Player]

	@property
	def name(self) -> str: ...

	@property
	def ip(self) -> str: ...

	@property
	def connected(self) -> bool: ...

	@property
	def ping(self) -> int: ...

	@property
	def social_id(self) -> int: ...

	@property
	def hwid_hash(self) -> int: ...

	@property
	def hwid_ex_hash(self) -> int: ...

	@property
	def auth_token(self) -> str: ...

	@property
	def speed(self) -> int: ...

	@property
	def aim_pos(self) -> Vector3: ...

	@property
	def head_rot(self) -> Vector3: ...

	@property
	def entity_aiming_at(self) -> Entity | None: ...

	@property
	def entity_aim_offset(self) -> Vector3: ...

	@property
	def invincible(self) -> bool: ...
	@invincible.setter
	def invincible(self, state: bool) -> None: ...

	@property
	def in_vehicle(self) -> bool: ...

	@property
	def vehicle(self) -> Vehicle | None: ...

	@property
	def seat(self) -> int: ...

	@property
	def health(self) -> int: ...
	@health.setter
	def health(self, new_health: int) -> None: ...

	@property
	def max_health(self) -> int: ...
	@max_health.setter
	def max_health(self, new_max_health: int) -> None: ...

	@property
	def armour(self) -> int: ...
	@armour.setter
	def armour(self, new_armour: int) -> None: ...

	@property
	def max_armour(self) -> int: ...
	@max_armour.setter
	def max_armour(self, new_max_armour: int) -> None: ...

	@property
	def current_weapon(self) -> int: ...
	@current_weapon.setter
	def current_weapon(self, new_current_weapon: int) -> None: ...

	@property
	def current_weapon_tint_index(self) -> WeaponTint: ...

	@property
	def current_weapon_tint_components(self) -> List[int]: ...

	@property
	def weapons(self) -> List[Weapon]: ...

	@property
	def dead(self) -> bool: ...

	@property
	def jumping(self) -> bool: ...

	@property
	def in_ragdoll(self) -> bool: ...

	@property
	def aiming(self) -> bool: ...

	@property
	def shooting(self) -> bool: ...

	@property
	def reloading(self) -> bool: ...

	@property
	def super_jump(self) -> bool: ...

	@property
	def crouching(self) -> bool: ...

	@property
	def stealthy(self) -> bool: ...

	@property
	def flashlight_active(self) -> bool: ...

	@property
	def head_blend_data(self) -> HeadBlendData: ...

	@property
	def eye_color(self) -> int: ...

	@property
	def hair_color(self) -> int: ...

	@property
	def hair_highlight_color(self) -> int: ...

	# Methods
	@staticmethod
	def get_by_id(id: int) -> Player | None: ...

	def emit(self, event_name: str, *args: Any) -> None: ...
	def kick(self, reason: str = "Kicked") -> None: ...
	def play_ambient_speech(self, speech_name: str, speech_param: str, speech_dict_hash: str) -> None: ...

	def set_date_time(self, day: int, month: int, year: int, hour: int, minute: int, second: int) -> None: ...
	def set_weather(self, weather: WeatherType | int) -> None: ...

	def set_into_vehicle(self, vehicle: Vehicle, seat: int) -> None: ...
	def clear_blood_damage(self) -> None: ...

	def give_weapon(self, weapon_hash: int, ammo: int, equip_now: bool) -> None: ...
	def remove_weapon(self, weapon_hash: int) -> None: ...
	def remove_all_weapons(self) -> None: ...
	def set_weapon_tint_index(self, weapon_hash: int, tint_index: WeaponTint | int) -> None: ...
	def add_weapon_component(self, weapon_hash: int, component: int) -> None: ...
	def remove_weapon_component(self, weapon_hash: int, component: int) -> None: ...

	def set_head_overlay(self, overlay_id: int, index: int, opacity: float) -> bool: ...
	def remove_head_overlay(self, overlay_id: int) -> bool: ...
	def set_head_overlay_color(self, overlay_id: int, color_type: int, color_index: int, second_color_index: int) -> bool: ...
	def get_head_overlay(self, overlay_id: int) -> HeadOverlay: ...
	def set_face_feature(self, index: int, scale: float) -> bool: ...
	def get_face_feature_scale(self, index: int) -> float: ...
	def remove_face_feature(self, index: int) -> bool: ...
	def set_head_blend_palette_color(self, id: int, red: int, green: int, blue: int) -> bool: ...
	def get_head_blend_palette_color(self, id: int) -> RGBA: ...
	def set_head_blend_data(self, shape_first_id: int, shape_second_id: int, shape_third_id: int, skin_first_id: int, skin_second_id: int, skin_third_id: int, shape_mix: float, skin_mix: float, third_mix: float) -> None: ...

	def get_clothes(self, component: int) -> Cloth: ...
	def set_clothes(self, component: int, drawable: int, texture: int, palette: int = 0) -> bool: ...
	def get_dlc_clothes(self, component: int) -> DlcCloth: ...
	def set_dlc_clothes(self, dlc: int, component: int, drawable: int, texture: int, palette = 2) -> bool: ...
	def get_prop(self, component: int) -> Prop: ...
	def set_prop(self, component: int, drawable: int, texture: int) -> bool: ...
	def get_dlc_prop(self, component: int) -> DlcProp: ...
	def set_dlc_prop(self, dlc: int, component: int, drawable: int, texture: int) -> bool: ...
	def clear_props(self, component: int) -> None: ...

	def is_entity_in_streaming_range(self, entity: Entity | int) -> bool: ...

	@overload
	def spawn(self, pos: Vector3, delay: int = 0) -> None: ...
	@overload
	def spawn(self, x: float, y: float, z: float, delay: int = 0) -> None: ...
	def despawn(self) -> None: ...

	def get_local_meta(self, key: str) -> Any: ...
	def has_local_meta(self, key: str) -> bool: ...
	def set_local_meta(self, key: str, value: Any) -> None: ...
	def delete_local_meta(self, key: str) -> None: ...


class Neon(TypedDict):
	left: bool
	right: bool
	front: bool
	back: bool

class Vehicle(Entity):
	@overload
	def __init__(self, model: str | int, x: float, y: float, z: float, rx: float, ry: float, rz: float) -> None: ...
	@overload
	def __init__(self, model: str | int, pos: Vector3, rot: Vector3) -> None: ...

	# Properties
	all: Sequence[Vehicle]

	@property
	def modkit(self) -> int: ...
	@modkit.setter
	def modkit(self, id: int) -> None: ...

	@property
	def primary_color(self) -> int: ...
	@primary_color.setter
	def primary_color(self, color: int) -> None: ...

	@property
	def primary_color_rgb(self) -> RGBA: ...
	@primary_color_rgb.setter
	def primary_color_rgb(self, color: RGBA) -> None: ...

	@property
	def secondary_color(self) -> int: ...
	@secondary_color.setter
	def secondary_color(self, color: int) -> None: ...

	@property
	def secondary_color_rgb(self) -> RGBA: ...
	@secondary_color_rgb.setter
	def secondary_color_rgb(self, color: RGBA) -> None: ...

	@property
	def pearl_color(self) -> int: ...
	@pearl_color.setter
	def pearl_color(self, color: int) -> None: ...

	@property
	def wheel_color(self) -> int: ...
	@wheel_color.setter
	def wheel_color(self, color: int) -> None: ...

	@property
	def interior_color(self) -> int: ...
	@interior_color.setter
	def interior_color(self, color: int) -> None: ...

	@property
	def dashboard_color(self) -> int: ...
	@dashboard_color.setter
	def dashboard_color(self, color: int) -> None: ...

	@property
	def tire_smoke_color(self) -> RGBA: ...
	@tire_smoke_color.setter
	def tire_smoke_color(self, color: RGBA) -> None: ...

	@property
	def custom_tires(self) -> bool: ...
	@custom_tires.setter
	def custom_tires(self, state: bool) -> None: ...

	@property
	def darkness(self) -> int: ...
	@darkness.setter
	def darkness(self, value: int) -> None: ...

	@property
	def number_plate_index(self) -> NumberPlateStyle: ...
	@number_plate_index.setter
	def number_plate_index(self, index: NumberPlateStyle | int) -> None: ...

	@property
	def number_plate_text(self) -> str: ...
	@number_plate_text.setter
	def number_plate_text(self, text: str) -> None: ...

	@property
	def window_tint(self) -> WindowTint: ...
	@window_tint.setter
	def window_tint(self, tint: WindowTint | int) -> None: ...

	@property
	def dirt_level(self) -> int: ...
	@dirt_level.setter
	def dirt_level(self, level: int) -> None: ...

	@property
	def neon(self) -> Neon: ...
	@neon.setter
	def neon(self, new_neon: Neon) -> None: ...

	@property
	def neon_color(self) -> RGBA: ...
	@neon_color.setter
	def neon_color(self, color: RGBA) -> None: ...

	@property
	def livery(self) -> int: ...
	@livery.setter
	def livery(self, new_livery: int) -> None: ...

	@property
	def roof_livery(self) -> int: ...
	@roof_livery.setter
	def roof_livery(self, new_roof_livery: int) -> None: ...

	@property
	def game_state_base64(self) -> str: ...
	@game_state_base64.setter
	def game_state_base64(self, base64: str) -> None: ...

	@property
	def appearance_data_base64(self) -> str: ...
	@appearance_data_base64.setter
	def appearance_data_base64(self, base64: str) -> None: ...

	@property
	def health_data_base64(self) -> str: ...
	@health_data_base64.setter
	def health_data_base64(self, base64: str) -> None: ...

	@property
	def damage_data_base64(self) -> str: ...
	@damage_data_base64.setter
	def damage_data_base64(self, base64: str) -> None: ...

	@property
	def script_data_base64(self) -> str: ...
	@script_data_base64.setter
	def script_data_base64(self, base64: str) -> None: ...

	@property
	def engine_on(self) -> bool: ...
	@engine_on.setter
	def engine_on(self, state: bool) -> None: ...

	@property
	def headlight_color(self) -> int: ...
	@headlight_color.setter
	def headlight_color(self, color: int) -> None: ...

	@property
	def active_radio_station(self) -> RadioStation: ...
	@active_radio_station.setter
	def active_radio_station(self, station: RadioStation | int) -> None: ...

	@property
	def siren_active(self) -> bool: ...
	@siren_active.setter
	def siren_active(self, state: bool) -> None: ...

	@property
	def lock_state(self) -> VehicleLockState: ...
	@lock_state.setter
	def lock_state(self, state: VehicleLockState | int) -> None: ...

	@property
	def roof_state(self) -> int: ...
	@roof_state.setter
	def roof_state(self, state: int) -> None: ...

	@property
	def lights_multiplier(self) -> float: ...
	@lights_multiplier.setter
	def lights_multiplier(self, multiplier: int) -> None: ...

	@property
	def engine_health(self) -> int: ...
	@engine_health.setter
	def engine_health(self, health: int) -> None: ...

	@property
	def petrol_tank_health(self) -> int: ...
	@petrol_tank_health.setter
	def petrol_tank_health(self, health: int) -> None: ...

	@property
	def body_health(self) -> int: ...
	@body_health.setter
	def body_health(self, health: int) -> None: ...

	@property
	def body_additional_health(self) -> int: ...
	@body_additional_health.setter
	def body_additional_health(self, health: int) -> None: ...

	@property
	def manual_engine_control(self) -> bool: ...
	@manual_engine_control.setter
	def manual_engine_control(self, state: bool) -> None: ...

	@property
	def drift_mode_enabled(self) -> bool: ...
	@drift_mode_enabled.setter
	def drift_mode_enabled(self, state: bool) -> None: ...

	@property
	def is_mission_train(self) -> bool: ...
	@is_mission_train.setter
	def is_mission_train(self, state: bool) -> None: ...

	@property
	def is_train_engine(self) -> bool: ...
	@is_train_engine.setter
	def is_train_engine(self, is_engine: bool) -> None: ...

	@property
	def train_track_id(self) -> int: ...
	@train_track_id.setter
	def train_track_id(self, track_id: int) -> None: ...

	@property
	def train_engine_id(self) -> Vehicle | None: ...
	@train_engine_id.setter
	def train_engine_id(self, vehicle: Vehicle) -> None: ...

	@property
	def train_config_index(self) -> int: ...
	@train_config_index.setter
	def train_config_index(self, config_index: int) -> None: ...

	@property
	def train_distance_from_engine(self) -> float: ...
	@train_distance_from_engine.setter
	def train_distance_from_engine(self, distance_from_engine: float) -> None: ...

	@property
	def is_train_caboose(self) -> bool: ...
	@is_train_caboose.setter
	def is_train_caboose(self, is_caboose: bool) -> None: ...

	@property
	def train_direction(self) -> bool: ...
	@train_direction.setter
	def train_direction(self, direction: bool) -> None: ...

	@property
	def train_passenger_carriages(self) -> bool: ...
	@train_passenger_carriages.setter
	def train_passenger_carriages(self, has_passenger_carriages: bool) -> None: ...

	@property
	def train_render_derailed(self) -> bool: ...
	@train_render_derailed.setter
	def train_render_derailed(self, render_derailed: bool) -> None: ...

	@property
	def train_force_doors_open(self) -> bool: ...
	@train_force_doors_open.setter
	def train_force_doors_open(self, force_doors_open: bool) -> None: ...

	@property
	def train_cruise_speed(self) -> float: ...
	@train_cruise_speed.setter
	def train_cruise_speed(self, cruise_speed: float) -> None: ...

	@property
	def train_carriage_config_index(self) -> int: ...
	@train_carriage_config_index.setter
	def train_carriage_config_index(self, carriage_config_index: int) -> None: ...

	@property
	def train_linked_to_backward_id(self) -> Vehicle | None: ...
	@train_linked_to_backward_id.setter
	def train_linked_to_backward_id(self, vehicle: Vehicle) -> None: ...

	@property
	def train_linked_to_forward_id(self) -> Vehicle | None: ...
	@train_linked_to_forward_id.setter
	def train_linked_to_forward_id(self, vehicle: Vehicle) -> None: ...

	@property
	def train_unk1(self) -> bool: ...
	@train_unk1.setter
	def train_unk1(self, unk1: bool) -> None: ...

	@property
	def train_unk2(self) -> bool: ...
	@train_unk2.setter
	def train_unk2(self, unk2: bool) -> None: ...

	@property
	def train_unk3(self) -> bool: ...
	@train_unk3.setter
	def train_unk3(self, unk3: bool) -> None: ...

	@property
	def boat_anchor_active(self) -> bool: ...
	@boat_anchor_active.setter
	def boat_anchor_active(self, state: bool) -> None: ...

	@property
	def driver(self) -> Player: ...

	@property
	def destroyed(self) -> bool: ...

	@property
	def modkits_count(self) -> int: ...

	@property
	def is_primary_color_rgb(self) -> bool: ...

	@property
	def is_secondary_color_rgb(self) -> bool: ...

	@property
	def is_tire_smoke_color_custom(self) -> bool: ...

	@property
	def wheel_type(self) -> int: ...

	@property
	def front_wheel(self) -> int: ...

	@property
	def rear_wheel(self) -> int: ...

	@property
	def neon_active(self) -> bool: ...

	@property
	def handbrake_active(self) -> bool: ...

	@property
	def daylight_on(self) -> bool: ...

	@property
	def nightlight_on(self) -> bool: ...

	@property
	def flamethrower_active(self) -> bool: ...

	@property
	def wheels_count(self) -> int: ...

	@property
	def repairs_count(self) -> int: ...

	@property
	def has_armored_windows(self) -> bool: ...

	@property
	def velocity(self) -> Vector3: ...

	@property
	def attached(self) -> Vehicle: ...

	@property
	def attached_to(self) -> Vehicle: ...

	# Methods
	@staticmethod
	def get_by_id(id: int) -> Vehicle | None: ...

	def get_mod(self, mod_type: int) -> int: ...
	def set_mod(self, mod_type: int, mod_id: int) -> bool: ...
	def get_mods_count(self, mod_type: int) -> int: ...
	def get_extra(self, extra_id: int) -> bool: ...
	def set_extra(self, extra_id: int, state: bool) -> None: ...
	def get_door_state(self, door_id: int) -> VehicleDoorState: ...
	def set_door_state(self, door_id: int, state: VehicleDoorState | int) -> None: ...
	def is_window_opened(self, window_id: int) -> bool: ...
	def set_window_opened(self, window_id: int, state: bool) -> None: ...
	def is_wheel_burst(self, wheel_id: int) -> bool: ...
	def does_wheel_has_tire(self, wheel_id: int) -> bool: ...
	def is_wheel_detached(self, wheel_id: int) -> bool: ...
	def is_wheel_on_fire(self, wheel_id: int) -> bool: ...
	def get_wheel_health(self, wheel_id: int) -> float: ...
	def get_part_damage_level(self, part_id: VehiclePart | int) -> VehiclePartDamage: ...
	def get_part_bullet_holes(self, part_id: VehiclePart | int) -> int: ...
	def is_light_damaged(self, light_id: int) -> bool: ...
	def is_window_damaged(self, window_id: int) -> bool: ...
	def is_special_light_damaged(self, special_light_id: int) -> bool: ...
	def get_armored_window_health(self, window_id: int) -> float: ...
	def get_armored_window_shoot_count(self, window_id: int) -> int: ...
	def get_bumper_damage_level(self, bumper_id: VehicleBumper | int) -> VehicleBumperDamage: ...
	def repair(self) -> None: ...
	def set_wheels(self, type: int, variation: int) -> None: ...
	def set_rear_wheels(self, variation: int) -> None: ...
	def set_wheel_burst(self, wheel_id: int, state: bool) -> None: ...
	def set_wheel_has_tire(self, wheel_id: int, state: bool) -> None: ...
	def set_wheel_detached(self, wheel_id: int, state: bool) -> None: ...
	def set_wheel_on_fire(self, wheel_id: int, state: bool) -> None: ...
	def set_wheel_fixed(self, wheel_id: int) -> None: ...
	def set_part_damage_level(self, part_id: VehiclePart | int, damage: VehiclePartDamage | int) -> None: ...
	def set_part_bullet_holes(self, part_id: VehiclePart | int, count: int) -> None: ...
	def set_light_damaged(self, light_id: int, is_damaged: bool) -> None: ...
	def set_window_damaged(self, window_id: int, is_damaged: bool) -> None: ...
	def set_special_light_damaged(self, special_light_id: int, is_damaged: bool) -> None: ...
	def set_armored_window_health(self, window_id: int, health: float) -> None: ...
	def set_armored_window_shoot_count(self, window_id: int, count: int) -> None: ...
	def set_bumper_damage_level(self, bumper_id: VehicleBumper | int, level: VehicleBumperDamage | int) -> None: ...
	def set_search_light_to(self, entity: Entity, state: bool) -> None: ...


class VoiceChannel(BaseObject):
	# Constructor
	def __init__(self, spatial: bool, max_distance: float) -> None: ...

	# Properties
	@property
	def player_count(self) -> int: ...

	@property
	def players(self) -> List[Player]: ...

	@property
	def max_distance(self) -> float: ...

	@property
	def spatial(self) -> bool: ...

	def add_player(self, player: Player) -> None: ...
	def has_player(self, player: Player) -> bool: ...
	def is_player_muted(self, player: Player) -> bool: ...
	def mute_player(self, player: Player) -> None: ...
	def remove_player(self, player: Player) -> None: ...
	def unmute_player(self, player: Player) -> None: ...

class Blip(WorldObject):
	all: Sequence[Blip]

	@property
	def alpha(self) -> int: ...
	@alpha.setter
	def alpha(self, new_alpha: int) -> None: ...

	@property
	def as_mission_creator(self) -> bool: ...
	@as_mission_creator.setter
	def as_mission_creator(self, val: bool) -> None: ...

	@property
	def attached_to(self) -> Entity: ...
	@attached_to.setter
	def attached_to(self, entity: Entity) -> None: ...

	@property
	def bright(self) -> bool: ...
	@bright.setter
	def bright(self, new_bright: bool) -> None: ...

	@property
	def category(self) -> int: ...
	@category.setter
	def category(self, val: int) -> None: ...

	@property
	def color(self) -> BlipColor: ...
	@color.setter
	def color(self, new_color: BlipColor | int) -> None: ...

	@property
	def crew_indicator_visible(self) -> bool: ...
	@crew_indicator_visible.setter
	def crew_indicator_visible(self, val: bool) -> None: ...

	@property
	def display(self) -> int: ...
	@display.setter
	def display(self, new_display: int) -> None: ...

	@property
	def flash_interval(self) -> int: ...
	@flash_interval.setter
	def flash_interval(self, interval: int) -> None: ...

	@property
	def flash_timer(self) -> int: ...
	@flash_timer.setter
	def flash_timer(self, timer: int) -> None: ...

	@property
	def flashes(self) -> bool: ...
	@flashes.setter
	def flashes(self, state: bool) -> None: ...

	@property
	def flashes_alternate(self) -> bool: ...
	@flashes_alternate.setter
	def flashes_alternate(self, state: bool) -> None: ...

	@property
	def friend_indicator_visible(self) -> bool: ...
	@friend_indicator_visible.setter
	def friend_indicator_visible(self, state: bool) -> None: ...

	@property
	def gxt_name(self) -> str: ...
	@gxt_name.setter
	def gxt_name(self, name: str) -> None: ...

	@property
	def heading(self) -> float: ...
	@heading.setter
	def heading(self, rot: float) -> None: ...

	@property
	def heading_indicator_visible(self) -> bool: ...
	@heading_indicator_visible.setter
	def heading_indicator_visible(self, state: bool) -> None: ...

	@property
	def high_detail(self) -> bool: ...
	@high_detail.setter
	def high_detail(self, state: bool) -> None: ...

	@property
	def name(self) -> str: ...
	@name.setter
	def name(self, new_name: str) -> None: ...

	@property
	def number(self) -> int: ...
	@number.setter
	def number(self, new_number: int) -> None: ...

	@property
	def outline_indicator_visible(self) -> bool: ...
	@outline_indicator_visible.setter
	def outline_indicator_visible(self, state: bool) -> None: ...

	@property
	def priority(self) -> int: ...
	@priority.setter
	def priority(self, state: int) -> None: ...

	@property
	def pulse(self) -> bool: ...
	@pulse.setter
	def pulse(self, state: bool) -> None: ...

	@property
	def route(self) -> bool: ...
	@route.setter
	def route(self, state: bool) -> None: ...

	@property
	def route_color(self) -> RGBA: ...
	@route_color.setter
	def route_color(self, state: RGBA) -> None: ...

	@property
	def scale(self) -> float: ...
	@scale.setter
	def scale(self, new_scale: float) -> None: ...

	@property
	def secondary_color(self) -> RGBA: ...
	@secondary_color.setter
	def secondary_color(self, new_scale: RGBA) -> None: ...

	@property
	def short_range(self) -> bool: ...
	@short_range.setter
	def short_range(self, state: bool) -> None: ...

	@property
	def show_cone(self) -> bool: ...
	@show_cone.setter
	def show_cone(self, state: bool) -> None: ...

	@property
	def shrinked(self) -> bool: ...
	@shrinked.setter
	def shrinked(self, state: bool) -> None: ...

	@property
	def size(self) -> Vector2: ...
	@size.setter
	def size(self, new_size: Vector2) -> None: ...

	@property
	def sprite(self) -> BlipSprite: ...
	@sprite.setter
	def sprite(self, new_sprite: BlipSprite) -> None: ...

	@property
	def tick_visible(self) -> bool: ...
	@tick_visible.setter
	def tick_visible(self, state: bool) -> None: ...

	@staticmethod
	@overload
	def area(x: float, y: float, z: float, width: float, height: float) -> Blip: ...

	@staticmethod
	@overload
	def area(pos: Vector3, width: float, height: float) -> Blip: ...

	@staticmethod
	@overload
	def point(x: float, y: float, z: float) -> Blip: ...

	@staticmethod
	@overload
	def point(pos: Vector3) -> Blip: ...

	@staticmethod
	@overload
	def point(entity: Entity) -> Blip: ...

	@staticmethod
	@overload
	def radius(x: float, y: float, z: float, radius: float) -> Blip: ...

	@staticmethod
	@overload
	def radius(pos: Vector3, radius: float) -> Blip: ...

	def fade(self, opacity: int, duration: int) -> None: ...

class ColShape(WorldObject):
	@staticmethod
	@overload
	def circle(x: float, y: float, radius: float) -> ColShape: ...

	@staticmethod
	@overload
	def circle(pos: Vector2, radius: float) -> ColShape: ...

	@staticmethod
	@overload
	def cylinder(x: float, y: float, z: float, radius: float, height: float) -> ColShape: ...

	@staticmethod
	@overload
	def cylinder(pos: Vector3, radius: float, height: float) -> ColShape: ...

	@staticmethod
	@overload
	def sphere(x: float, y: float, z: float, radius: float) -> ColShape: ...

	@staticmethod
	@overload
	def sphere(pos: Vector3, radius: float) -> ColShape: ...

	@staticmethod
	@overload
	def cube(x1: float, y1: float, z1: float, x2: float, y2: float, z2: float) -> ColShape: ...

	@staticmethod
	@overload
	def cube(pos1: Vector3, pos2: Vector3) -> ColShape: ...

	@staticmethod
	@overload
	def rectangle(x1: float, y1: float, x2: float, y2: float) -> ColShape: ...

	@staticmethod
	@overload
	def rectangle(pos1: Vector3, pos2: Vector3) -> ColShape: ...

	@staticmethod
	def polygon(min_z: float, max_z: float, points: List[Vector2]) -> ColShape: ...

	@property
	def colshape_type(self) -> ColShapeType: ...

	@property
	def players_only(self) -> bool: ...
	@players_only.setter
	def players_only(self, state: bool) -> None: ...

	def is_entity_in(self, entity: Entity) -> bool: ...
	@overload
	def is_point_in(self, x: float, y: float, z: float) -> bool: ...
	@overload
	def is_point_in(self, pos: Vector3): ...

class Checkpoint(ColShape):
	@overload
	def __init__(self, type: int | CheckpointType, x: float, y: float, z: float, radius: float, height: float, r: int, g: int, b: int, a: int) -> None: ...
	@overload
	def __init__(self, type: int | CheckpointType, pos: Vector3, radius: float, height: float, color: RGBA) -> None: ...

	@property
	def checkpoint_type(self) -> CheckpointType: ...
	@property
	def height(self) -> float: ...
	@property
	def radius(self) -> float: ...
	@property
	def color(self) -> RGBA: ...



class ConnectionInfo:
	@property
	def name(self) -> str: ...

	@property
	def social_id(self) -> int: ...

	@property
	def hwid_hash(self) -> int: ...

	@property
	def hwid_ex_hash(self) -> int: ...

	@property
	def auth_token(self) -> str: ...

	@property
	def is_debug(self) -> bool: ...

	@property
	def branch(self) -> str: ...

	@property
	def build(self) -> int: ...

	@property
	def cdn_url(self) -> str: ...

	@property
	def password_hash(self) -> int: ...

	@property
	def ip(self) -> str: ...

	@property
	def discord_user_id(self) -> str: ...

	@property
	def accepted(self) -> bool: ...

	def accept(self) -> None: ...
	def decline(self, reason: str) -> None: ...


class Resource:
	all: Sequence[Resource]
	current: Resource

	@property
	def is_started(self) -> bool: ...

	@property
	def type(self) -> str: ...

	@property
	def name(self) -> str: ...

	@property
	def main(self) -> str: ...

	@property
	def path(self) -> str: ...

	@property
	def exports(self) -> Dict[str, Callable]: ...

	@property
	def dependencies(self) -> List[str]: ...

	@property
	def dependants(self) -> List[str]: ...

	@property
	def required_permissions(self) -> List[int]: ...

	@property
	def optional_permissions(self) -> List[int]: ...

	@staticmethod
	def get_by_name(resource_name: str) -> Resource: ...

class VehicleModelInfo:
	@property
	def title(self) -> str: ...

	@property
	def wheels_count(self) -> int: ...

	@property
	def has_armored_windows(self) -> bool: ...

	@property
	def primary_color(self) -> int: ...

	@property
	def secondary_color(self) -> int: ...

	@property
	def pearl_color(self) -> int: ...

	@property
	def wheels_color(self) -> int: ...

	@property
	def interior_color(self) -> int: ...

	@property
	def dashboard_color(self) -> int: ...

	@property
	def has_auto_attach_trailer(self) -> bool: ...

	@property
	def type(self) -> VehicleType: ...

	@property
	def available_modkits(self) -> List[bool]: ...

	def has_extra(self, extra_id: int): ...
	def has_default_extra(self, extra_id: int): ...

# alt attributes
branch: str
debug: bool
default_dimension: int
global_dimension: int
root_dir: str
sdk_version: int
version: str

# alt methods
def hash(value: str) -> int: ...
def get_net_time() -> int: ...
def get_server_config() -> Dict[str, Any]: ...
def get_vehicle_model_info_by_hash(vehicle_hash: int) -> VehicleModelInfo: ...
def hash_server_password(password: str) -> int: ...
def set_password(password: str) -> None: ...
def stop_server() -> None: ...
def string_to_sha256(value: str) -> str: ...
def export(name: str, object: Any) -> None: ...
def restart_resource(resource_name: str) -> None: ...
def start_resource(resource_name: str) -> None: ...
def stop_resource(resource_name: str) -> None: ...

def delete_meta(self, key: str) -> None: ...
def get_meta(self, key: str) -> Any: ...
def set_meta(self, key: str, value: Any) -> None: ...
def has_meta(self, key: str) -> bool: ...

def get_synced_meta(self, key: str) -> Any: ...
def has_synced_meta(self, key: str) -> bool: ...
def set_synced_meta(self, key: str, value: Any) -> None: ...
def delete_synced_meta(self, key: str) -> None: ...

def timer(func: Callable, milliseconds: float) -> int: ...
def clear_timer(timer_id: int) -> None: ...

def log(*args: Any, sep = " ") -> None: ...
def log_error(*args: Any, sep = " ") -> None: ...
def log_warning(*args: Any, sep = " ") -> None: ...

def emit(event_name: str, *args: Any) -> None: ...
def emit_client(player: Player | List[Player], event_name: str, *args: Any) -> None: ...
def emit_all_clients(event_name: str, *args: Any) -> None: ...

# decorators
def event(event: Event) -> Callable: ...
def custom_event(event: str) -> Callable: ...
def client_event(event: str) -> Callable: ...
def task(*, milliseconds: float = 0, seconds: float = 0, minutes: float = 0, hours: float = 0) -> Callable: ...
