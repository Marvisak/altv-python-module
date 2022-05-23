from __future__ import annotations

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
    Nothing = auto()
    RadioOff = auto()
    MediaPlayer = auto()
    TheMusicLocker = auto()
    MotoMami = auto()
    BlueArk = auto()
    WorldWideFM = auto()
    FlyLoFM = auto()
    TheLowdown = auto()
    TheLab = auto()
    RadioMirrorPark = auto()
    KultFM = auto()
    Space = auto()
    VinewoodBoulevardRadio = auto()
    Blonded = auto()
    LosSantosUndergroundRadio = auto()
    iFruitRadio = auto()
    LosSantosRockRadio = auto()
    NonStopPopFM = auto()
    RadioLosSantos = auto()
    ChannelX = auto()
    WestCoastTalkRadio = auto()
    RebelRadio = auto()
    SoulwaxFM = auto()
    EastLosFM = auto()
    WestCoastClassics = auto()


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
    PropertyTakeover = auto()
    GangMexicansHighlight = auto()
    GangBikersHighlight = auto()
    TriathlonCycling = auto()
    TriathlonSwimming = auto()
    PropertyTakeoverBikers = auto()
    PropertyTakeoverCops = auto()
    PropertyTakeoverVagos = auto()
    Camera = auto()
    CentreRed = auto()
    HandcuffKeysBikers = auto()
    HandcuffKeysVagos = auto()
    HandcuffsClosedBikers = auto()
    HandcuffsClosedVagos = auto()
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
    # Constructor
    @overload
    def __init__(self, x: float, y: float) -> None:
        """
        Args:
                x:
                y:
        """

    @overload
    def __init__(self, vector_list: List[float]) -> None:
        """
        Args:
                vector_list:
        """

    @property
    def x(self) -> float:
        ...

    @x.setter
    def x(self, new_x: float) -> None:
        ...

    @property
    def y(self) -> float:
        ...

    @y.setter
    def y(self, new_y: float) -> None:
        ...

    zero: Vector2
    """(0, 0) vector"""
    one: Vector2
    """(1, 1) vector"""
    up: Vector2
    """(0, 1) vector"""
    down: Vector2
    """(0, -1) vector"""
    left: Vector2
    """(-1, 0) vector"""
    right: Vector2
    """(1, 0) vector"""
    positive_infinity: Vector2
    """(inf, inf) vector"""
    negative_infinity: Vector2
    """(-inf, -inf) vector"""

    # Methods
    def to_dict(self) -> IVector2:
        """Converts vector to IVector2 dict

        Returns:
                IVector2 dict
        """

    def to_list(self) -> List[float]:
        """Converts vector to list

        Returns:
                [x, y] list
        """

    def length(self) -> float:
        """Calculates length of the vector.

        Returns:
                Calculated length
        """

    def distance(self, vector: Vector2) -> float:
        """Calculates distance between two vectors.

        Args:
                vector:

        Returns:
                Calculated distance
        """

    def distance_squared(self, vector: Vector2) -> float:
        """Calculates squared distance between two vectors.

        Args:
                vector:

        Returns:
                Calculated squared distance.
        """

    def lerp(self, vector: Vector2, ratio: float) -> Vector2:
        """Interpolates vectors linearly.

        Args:
                vector:
                ratio:

        Returns:
                Interpolated vector
        """

    def to_degrees(self, vector: Vector2) -> Vector2:
        """Converts radians to degrees.

        Returns:
                Vector converted to degrees
        """

    def to_radians(self, vector: Vector2) -> Vector2:
        """Converts degrees to radians.

        Returns:
                Vector converted to radians
        """

    def is_in_range(self, vector: Vector2, range: float) -> bool:
        """Checks if distance between vectors is smaller or equal to range.

        Args:
                vector:
                range:

        Returns:
                True if distance is smaller or equal than range
        """

    @overload
    def __add__(self, other: Vector2) -> Vector2:
        ...

    @overload
    def __add__(self, num: float) -> Vector2:
        ...

    @overload
    def __add__(self, vector_list: List[float]) -> Vector2:
        ...

    @overload
    def __sub__(self, other: Vector2) -> Vector2:
        ...

    @overload
    def __sub__(self, num: float) -> Vector2:
        ...

    @overload
    def __sub__(self, vector_list: List[float]) -> Vector2:
        ...

    @overload
    def __mul__(self, other: Vector2) -> Vector2:
        ...

    @overload
    def __mul__(self, num: float) -> Vector2:
        ...

    @overload
    def __mul__(self, vector_list: List[float]) -> Vector2:
        ...

    @overload
    def __truediv__(self, other: Vector2) -> Vector2:
        ...

    @overload
    def __truediv__(self, num: float) -> Vector2:
        ...

    @overload
    def __truediv__(self, vector_list: List[float]) -> Vector2:
        ...

    def __neg__(self) -> Vector2:
        """Negates vector.

        Example:
                ```py
                vector = alt.Vector2(1, 1)
                alt.log(-vector) # Vector2(-1, -1)
                ```
        """

    def __eq__(self, other: object) -> bool:
        """Compares two vectors.

        Example:
                ```py
                vector = alt.Vector2(1, 1)
                vector2 = alt.Vector2(1, 1)
                alt.log(vector == vector2) # True
                ```
        """

    @overload
    def dot(self, vector: Vector2) -> Vector2:
        """Calculates dot product between two vectors.

        Args:
                vector:

        Returns:
                Dot product
        """

    @overload
    def dot(self, num: float) -> Vector2:
        """Calculates dot product between vector and a number.

        Args:
                num:

        Returns:
                Dot product
        """

    @overload
    def dot(self, vector_list: List[int]) -> Vector2:
        """Calculates dot product between two vectors.

        Args:
                vector_list:

        Returns:
                Dot product
        """

    def normalize(self) -> Vector2:
        """Normalizes vector.

        Returns:
                Normalized vector
        """

    def angle_to(self, vector: Vector2) -> float:
        """Calculates angle between two vectors (in radians).

        Args:
                vector:

        Returns:
                Calculated angle in radians
        """

    def angle_to_degrees(self, vector: Vector2) -> float:
        """Calculates angle between two vectors (in degrees).

        Args:
                vector:

        Returns:
                Calculated angle in degrees
        """


class IVector3(TypedDict):
    x: float
    y: float
    z: float


class Vector3:
    @property
    def x(self) -> float:
        ...

    @x.setter
    def x(self, new_x: float) -> None:
        ...

    @property
    def y(self) -> float:
        ...

    @y.setter
    def y(self, new_y: float) -> None:
        ...

    @property
    def z(self) -> float:
        ...

    @z.setter
    def z(self, new_z: float) -> None:
        ...

    zero: Vector3
    """(0, 0, 0) vector"""
    one: Vector3
    """(1, 1, 1) vector"""
    up: Vector3
    """(0, 0, 1) vector"""
    down: Vector3
    """(0, 0, -1) vector"""
    left: Vector3
    """(-1, 0, 0) vector"""
    right: Vector3
    """(1, 0, 0) vector"""
    back: Vector3
    """(0, -1, 0) vector"""
    forward: Vector3
    """(0, 1, 0) vector"""
    positive_infinity: Vector3
    """(inf, inf, inf) vector"""
    negative_infinity: Vector3
    """(-inf, -inf, -inf) vector"""

    # Constructor
    @overload
    def __init__(self, x: float, y: float, z: float) -> None:
        """
        Args:
                x:
                y:
                z:
        """

    @overload
    def __init__(self, vector_list: List[float]) -> None:
        """
        Args:
                vector_list:
        """

    # Methods
    def to_dict(self) -> IVector3:
        """Converts vector to IVector3 dict

        Returns:
                IVector3 dict
        """

    def to_list(self) -> List[int]:
        """Converts vector to list

        Returns:
                [x, y, z] list
        """

    def length(self) -> float:
        """Calculates length of the vector.

        Returns:
                Calculated length
        """

    def distance(self, vector: Vector3) -> float:
        """Calculates distance between two vectors.

        Args:
                vector:

        Returns:
                Calculated distance
        """

    def distance_squared(self, vector: Vector3) -> float:
        """Calculates squared distance between two vectors.

        Args:
                vector:

        Returns:
                Calculated squared distance.
        """

    def lerp(self, vector: Vector3, ratio: float) -> Vector3:
        """Interpolates vectors linearly.

        Args:
                vector:
                ratio:

        Returns:
                Interpolated vector
        """

    def to_degrees(self, vector: Vector3) -> Vector3:
        """Converts radians to degrees.

        Returns:
                Vector converted to degrees
        """

    def to_radians(self, vector: Vector3) -> Vector3:
        """Converts degrees to radians.

        Returns:
                Vector converted to radians
        """

    def is_in_range(self, vector: Vector3, range: float) -> bool:
        """Checks if distance between vectors is smaller or equal to range.

        Args:
                vector:
                range:

        Returns:
                True if distance is smaller or equal than range
        """

    @overload
    def __add__(self, other: Vector3) -> Vector3:
        ...

    @overload
    def __add__(self, num: float) -> Vector3:
        ...

    @overload
    def __add__(self, vector_list: List[float]) -> Vector3:
        ...

    @overload
    def __sub__(self, other: Vector3) -> Vector3:
        ...

    @overload
    def __sub__(self, num: float) -> Vector3:
        ...

    @overload
    def __sub__(self, vector_list: List[float]) -> Vector3:
        ...

    @overload
    def __mul__(self, other: Vector3) -> Vector3:
        ...

    @overload
    def __mul__(self, num: float) -> Vector3:
        ...

    @overload
    def __mul__(self, vector_list: List[float]) -> Vector3:
        ...

    @overload
    def __truediv__(self, other: Vector3) -> Vector3:
        ...

    @overload
    def __truediv__(self, num: float) -> Vector3:
        ...

    @overload
    def __truediv__(self, vector_list: List[float]) -> Vector3:
        ...

    def __neg__(self) -> Vector3:
        """Negates vector.

        Example:
                ```py
                vector = alt.Vector3(1, 1, 1)
                alt.log(-vector) # Vector3(-1, -1, -1)
                ```
        """

    def __eq__(self, other: object) -> bool:
        """Compares two vectors.

        Example:
                ```py
                vector = alt.Vector3(1, 1, 1)
                vector2 = alt.Vector3(1, 1, 1)
                alt.log(vector == vector2) # True
                ```
        """

    @overload
    def cross(self, vector: Vector3) -> Vector3:
        """Calculates cross product between two vectors.

        Args:
                vector:

        Returns:
                Calculated cross product
        """

    @overload
    def cross(self, num: int) -> Vector3:
        """Calculates cross product between vector and number.

        Args:
                num:

        Returns:
                Calculated cross product
        """

    @overload
    def cross(self, list: List[int]) -> Vector3:
        """Calculates cross product between two vectors.

        Args:
                list:

        Returns:
                Calculated cross product
        """

    @overload
    def dot(self, vector: Vector3) -> Vector3:
        """Calculates dot product between two vectors.

        Args:
                vector:

        Returns:
                Dot product
        """

    @overload
    def dot(self, num: int) -> Vector3:
        """Calculates dot product between vector and a number.

        Args:
                num:

        Returns:
                Dot product
        """

    @overload
    def dot(self, list: List[int]) -> Vector3:
        """Calculates dot product between two vectors.

        Args:
                list:

        Returns:
                Dot product
        """

    def normalize(self) -> Vector3:
        """Normalizes vector.

        Returns:
                Normalized vector
        """

    def angle_to(self, vector: Vector3) -> float:
        """Calculates angle between two vectors (in radians).

        Args:
                vector:

        Returns:
                Calculated angle in radians
        """

    def angle_to_degrees(self, vector: Vector3) -> float:
        """Calculates angle between two vectors (in degrees).

        Args:
                vector:

        Returns:
                Calculated angle in degrees
        """


class FireInfo(TypedDict):
    pos: Vector3
    weapon: int


class RGBA:
    @property
    def r(self) -> int:
        """r component of RGBA"""

    @r.setter
    def r(self, new_r: float) -> None:
        ...

    @property
    def g(self) -> int:
        """g component of RGBA"""

    @g.setter
    def g(self, new_g: float) -> None:
        ...

    @property
    def b(self) -> int:
        """b component of RGBA"""

    @b.setter
    def b(self, new_b: float) -> None:
        ...

    @property
    def a(self) -> int:
        """a component of RGBA"""

    @a.setter
    def a(self, new_a: float) -> None:
        ...

    # Constructor
    def __init__(self, r: int, g: int, b: int, a: int = 255) -> None:
        """
        Args:
                r: An r component.
                g: An g component.
                b: An b component.
                a: An a component.

        Note:
                The RGBA values are alowed to range from 0 to 255.
        """

    def to_bgra(self) -> RGBA:
        """Converts RGBA to BGRA

        Returns:
                RGBA converted to BGRA
        """

    def to_argb(self) -> RGBA:
        """Converts RGBA to ARGB

        Returns:
                RGBA converted to ARGB
        """

    def to_list(self) -> List[int]:
        """Converts RGBA to list

        Returns:
                [r, g, b, a] list
        """


class BaseObject:
    # Properties
    @property
    def ref_count(self) -> int:
        """Returns the ref count of the entity.

        Raises:
                RuntimeError: If the server is not in debug mode
        """

    @property
    def valid(self) -> bool:
        """Object usability.

        Returns:
                False if object is no longer usable.
        """

    @property
    def type(self) -> BaseObjectType:
        """Type of the object."""

    # Methods
    def delete_meta(self, key: str) -> None:
        """Removes the specified key and the data connected to that specific key.

        Args:
                key: The key of the value to remove.
        """

    def get_meta(self, key: str) -> Any:
        """Gets a value using the specified key.

        Args:
                key: The key of the value to get.

        Returns:
                Dynamic value associated with the specified key or None if no data is present.
        """

    def set_meta(self, key: str, value: Any) -> None:
        """Stores the given value with the specified key.

        Args:
                key: The key of the value to store.
                value: The value to store.

        Note:
                The given value will be shared locally.
        """

    def has_meta(self, key: str) -> bool:
        """Determines whether contains the specified key.

        Args:
                key: The key of the value to locate.

        Returns:
                True when element associated with the specified key is stored.
        """

    def destroy(self) -> None:
        """Removes the object from the world."""


class WorldObject(BaseObject):
    # Properties
    @property
    def pos(self) -> Vector3:
        """Object position."""

    @pos.setter
    def pos(self, new_pos: Vector3) -> None:
        ...

    @property
    def dimension(self) -> int:
        """Object dimension

        Note:
                Check [https://docs.altv.mp/articles/dimensions.html](https://docs.altv.mp/articles/dimensions.html) to understand how it works.
        """

    @dimension.setter
    def dimension(self, new_dimension: int) -> None:
        ...


class Entity(WorldObject):
    # Properties
    all: Sequence[Entity]
    """List with all entities.
	
	Note:
		This creates a clone of the list everytime it is called. It is advised to call this once and store the result in a variable, before iterating over it.

	Example:
		```py
		entities = alt.Entity.all
		for entity in entities:
		    alt.log(entity.id)
		```
	"""

    @property
    def id(self) -> int:
        """Internal identificator of the entity which is identical on both sides."""

    @property
    def rot(self) -> Vector3:
        """Entity rotation.

        Note:
                Values are provided in radians.
        """

    @rot.setter
    def rot(self, new_rot: Vector3) -> None:
        ...

    @property
    def streamed(self) -> bool:
        """Whether the entity should be streamed for other entities."""

    @streamed.setter
    def streamed(self, state: bool) -> None:
        ...

    @property
    def visible(self) -> bool:
        """Whether the entity is visible."""

    @visible.setter
    def visible(self, state: bool) -> None:
        ...

    @property
    def collision(self) -> bool:
        ...

    @collision.setter
    def collision(self, state: bool) -> None:
        ...

    @property
    def frozen(self) -> bool:
        ...

    @frozen.setter
    def frozen(self, state: bool) -> None:
        ...

    @property
    def model(self) -> int:
        """Entity model hash.

        Note:
                Setter also accepts string as a value, but the getter will always return number
        """

    @model.setter
    def model(self, new_model: int | str) -> None:
        ...

    @property
    def net_owner(self) -> Player | None:
        """Network owner of the entity.

        Note:
                Network owner is responsible for syncing entity with the server. It changes when actual network owner passes the migration range, then the new one is determined based on distance from the entity (if entity is a vehicle, then the driver will take priority for becoming network owner). Disabling migration range will stop this process from happening until turned on again.
        """

    # Methods
    @staticmethod
    def get_by_id(id: int) -> Entity | None:
        """Retrieves the entity from the pool.

        Args:
                id: The id of the entity.

        Returns:
                Entity if it was found, otherwise None
        """

    def set_net_owner(self, player: Player, disable_migration: bool = False) -> None:
        """Changes network owner to the specified player.

        Args:
                player: The given player that will be set as new network owner.
                disable_migration: Pass True to disable migration, False to keep it enabled.

        Note:
                See [net_owner][alt.Entity.net_owner] to understand how network owner works.
                <p><b>
                Keep in mind that disabling migration can lead to unexpected behaviour when
                the network owner gets out of the streaming range.
                </b></p>
        """

    def reset_net_owner(self, disable_migration: bool = False) -> None:
        """Resets overwritten network owner.

        Args:
                disable_migration: Pass True to disable migration, False to keep it enabled.

        Note:
                See [net_owner][alt.Entity.net_owner] to understand how network owner works.
                <p><b>
                Keep in mind that disabling migration can lead to unexpected behaviour when
                the network owner gets out of the streaming range.
                </b></p>
        """

    def attach_to(
        self,
        entity: Entity,
        entity_bone_id: int,
        own_bone_id: int,
        pos: Vector3,
        rot: Vector3,
        enable_collisions: bool,
        no_fixed_rotation: bool,
    ) -> None:
        """Attaches this entity to another entity.

        Args:
                entity: Target entity.
                entity_bone_id: Target bone id.
                own_bone_id: Origin bone id.
                pos: Position offset.
                rot: Rotation.
                enable_collisions: If true the attached entity has a collision.
                no_fixed_rotation: If false the entity is attached with a fixed rotation (no bouncing). That means if the value in native was true, you have to use false in the serverside method.
        """

    def detach(self) -> None:
        """Detaches the entity if attached to another entity."""

    def get_synced_meta(self, key: str) -> Any:
        """Gets a value using the specified key.

        Args:
                key: The key of the value to get.

        Returns:
                Dynamic value associated with the specified key or None if no data is present.
        """

    def has_synced_meta(self, key: str) -> bool:
        """Determines whether contains the specified key.

        Args:
                key: The key of value to locate.

        Returns:
                True if the meta table contains any data at the specified key or False if not.
        """

    def set_synced_meta(self, key: str, value: Any) -> None:
        """Stores the given value with the specified key.

        Args:
                key: The key of the value to store.
                value: The value to store.

        Note:
                The given value will be shared with all clients.
        """

    def delete_synced_meta(self, key: str) -> None:
        """Removes the specified key and the data connected to that specific key.

        Args:
                key: The key of the value to remove.
        """

    def get_stream_synced_meta(self, key: str) -> Any:
        """Gets a value using the specified key.

        Args:
                key: The key of the value to get.

        Returns:
                Dynamic value associated with the specified key or None if no data is present.
        """

    def has_stream_synced_meta(self, key: str) -> bool:
        """Determines whether contains the specified key.

        Args:
                key: The key of value to locate.

        Returns:
                True if the meta table contains any data at the specified key or False if not.
        """

    def set_stream_synced_meta(self, key: str, value: Any) -> None:
        """Stores the given value with the specified key.

        Args:
                key: The key of the value to store.
                value: The value to store.

        Note:
                The given value will be shared with all clients in streaming range.
        """

    def delete_stream_synced_meta(self, key: str) -> None:
        """Removes the specified key and the data connected to that specific key.

        Args:
                key: The key of the value to remove.
        """


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
    """List with all players connected to the server.
	
	Note:
		This creates a clone of the list everytime it is called. It is advised to call this once and store the result in a variable, before iterating over it.

	Example:
		```py
		players = alt.Player.all
		for player in players:
		    alt.log(player.name)
		```
	"""

    @property
    def name(self) -> str:
        ...

    @property
    def ip(self) -> str:
        ...

    @property
    def connected(self) -> bool:
        ...

    @property
    def ping(self) -> int:
        ...

    @property
    def social_id(self) -> int:
        ...

    @property
    def hwid_hash(self) -> int:
        ...

    @property
    def hwid_ex_hash(self) -> int:
        ...

    @property
    def auth_token(self) -> str:
        ...

    @property
    def speed(self) -> int:
        ...

    @property
    def aim_pos(self) -> Vector3:
        """Position the player is currently aiming at.

        Note:
                Will return [zero][alt.Vector3.zero] if the player is aiming against a entity.
        """

    @property
    def head_rot(self) -> Vector3:
        ...

    @property
    def entity_aiming_at(self) -> Entity | None:
        ...

    @property
    def entity_aim_offset(self) -> Vector3:
        ...

    @property
    def invincible(self) -> bool:
        ...

    @invincible.setter
    def invincible(self, state: bool) -> None:
        ...

    @property
    def in_vehicle(self) -> bool:
        ...

    @property
    def vehicle(self) -> Vehicle | None:
        ...

    @property
    def seat(self) -> int:
        ...

    @property
    def health(self) -> int:
        ...

    @health.setter
    def health(self, new_health: int) -> None:
        ...

    @property
    def max_health(self) -> int:
        ...

    @max_health.setter
    def max_health(self, new_max_health: int) -> None:
        ...

    @property
    def armour(self) -> int:
        ...

    @armour.setter
    def armour(self, new_armour: int) -> None:
        ...

    @property
    def max_armour(self) -> int:
        ...

    @max_armour.setter
    def max_armour(self, new_max_armour: int) -> None:
        ...

    @property
    def current_weapon(self) -> int:
        ...

    @current_weapon.setter
    def current_weapon(self, new_current_weapon: int) -> None:
        ...

    @property
    def current_weapon_tint_index(self) -> WeaponTint:
        ...

    @property
    def current_weapon_tint_components(self) -> List[int]:
        ...

    @property
    def weapons(self) -> List[Weapon]:
        ...

    @property
    def dead(self) -> bool:
        ...

    @property
    def jumping(self) -> bool:
        ...

    @property
    def in_ragdoll(self) -> bool:
        ...

    @property
    def aiming(self) -> bool:
        ...

    @property
    def shooting(self) -> bool:
        ...

    @property
    def reloading(self) -> bool:
        ...

    @property
    def super_jump(self) -> bool:
        ...

    @property
    def crouching(self) -> bool:
        ...

    @property
    def stealthy(self) -> bool:
        ...

    @property
    def flashlight_active(self) -> bool:
        ...

    @property
    def head_blend_data(self) -> HeadBlendData:
        ...

    @property
    def hair_color(self) -> int:
        ...

    @property
    def hair_highlight_color(self) -> int:
        ...

    # Methods
    @staticmethod
    def get_by_id(id: int) -> Player | None:
        """Retrieves the player from the pool.

        Args:
                id: The id of the player.

        Returns:
                Player if it was found, otherwise None.
        """

    def emit(self, event_name: str, *args: Any) -> None:
        """Emits specified event to client.

        Args:
                event_name: Name of the event.
                *args: Rest parameters for emit to send.
        """

    def kick(self, reason: str = "Kicked") -> None:
        """Forcefully disconnects the player with a reason message.

        Args:
                reason: The reason that will display to the player on the disconnect screen.
        """

    def play_ambient_speech(
        self, speech_name: str, speech_param: str, speech_dict_hash: str
    ) -> None:
        """Plays ambient speech.

        Args:
                speech_name: Name of the speech.
                speech_param: Param of the speech.
                speech_dict_hash: Hash of the speech dict.

        Note:
                See [https://github.com/DurtyFree/gta-v-data-dumps/blob/master/speeches.json](https://github.com/DurtyFree/gta-v-data-dumps/blob/master/speeches.json) for a full list of speeches.
        """

    def set_date_time(
        self, day: int, month: int, year: int, hour: int, minute: int, second: int
    ) -> None:
        ...

    def set_weather(self, weather: WeatherType | int) -> None:
        ...

    def set_into_vehicle(self, vehicle: Vehicle, seat: int) -> None:
        """Set the player into a vehicle on specific seat."""

    def clear_blood_damage(self) -> None:
        """Removes the visible blood on the player body."""

    def give_weapon(self, weapon_hash: int, ammo: int, equip_now: bool) -> None:
        """Gives the specified weapon to the player.

        Args:
                weapon_hash: Hash of the weapon.
                ammo: Amount of ammo to spawn the weapon with. See note for more information
                equip_now: Should the weapon be equipped immediately.

        Note:
                Amount of given ammo is shared between all weapons with the same [ammo type](https://gist.github.com/root-cause/faf41f59f7a6d818b7db0b839bd147c1). For example pistols: `weapon_pistol` and `weapon_combatpistol` have same ammo pool.

                Some more notes about weapon ammo:

                - Zero ammo value doesnt remove ammo of that weapon.
                - Negative ammo value enables infinite ammo for this ammo type.
                - Amount of ammo will be added if player already have weapon with same ammo type.

        Example:
                ```py
                player.give_weapon(alt.hash("weapon_pistol"), 10, True) # sets amount ammo of type "AMMO_PISTOL" to 10
                player.give_weapon(alt.hash("weapon_combatpistol"), 10, True) # also 10 amount of ammo, as this has the same type of ammo
                player.give_weapon(alt.hash("weapon_pistol"), 10, True) # adds amount ammo of type "AMMO_PISTOL", so 20 pistol ammo in result
                ```
        """

    def remove_weapon(self, weapon_hash: int) -> None:
        """Removes the specified weapon from the player.

        Args:
                weapon_hash: Hash of the weapon.
        """

    def remove_all_weapons(self) -> None:
        """Removes every weapon from the player."""

    def set_weapon_tint_index(
        self, weapon_hash: int, tint_index: WeaponTint | int
    ) -> None:
        ...

    def add_weapon_component(self, weapon_hash: int, component: int) -> None:
        ...

    def remove_weapon_component(self, weapon_hash: int, component: int) -> None:
        """Removes the specified weapon component from the specified weapon.

        Args:
                weapon_hash: Hash of the weapon.
                component: Hash of the weapon component.
        """

    def set_head_overlay(self, overlay_id: int, index: int, opacity: float) -> bool:
        ...

    def remove_head_overlay(self, overlay_id: int) -> bool:
        ...

    def set_head_overlay_color(
        self,
        overlay_id: int,
        color_type: int,
        color_index: int,
        second_color_index: int,
    ) -> bool:
        ...

    def get_head_overlay(self, overlay_id: int) -> HeadOverlay:
        ...

    def set_face_feature(self, index: int, scale: float) -> bool:
        ...

    def get_face_feature_scale(self, index: int) -> float:
        ...

    def remove_face_feature(self, index: int) -> bool:
        ...

    def set_head_blend_palette_color(
        self, id: int, red: int, green: int, blue: int
    ) -> bool:
        ...

    def get_head_blend_palette_color(self, id: int) -> RGBA:
        ...

    def set_head_blend_data(
        self,
        shape_first_id: int,
        shape_second_id: int,
        shape_third_id: int,
        skin_first_id: int,
        skin_second_id: int,
        skin_third_id: int,
        shape_mix: float,
        skin_mix: float,
        third_mix: float,
    ) -> None:
        ...

    def set_eye_color(self, eye_color: int) -> bool:
        ...

    def get_eye_color(self) -> int:
        ...

    def get_clothes(self, component: int) -> Cloth:
        """Gets the specified clothing component.

        Args:
                component: Component id of the clothing.

        Returns:
                The currently equipped clothing component

        Example:
                ```py
                cloth = player.get_clothes(1) # Gets the currently equipped mask
                alt.log(cloth.drawable) # Logs the drawable of the currently equipped mask
                ```
        """

    def set_clothes(
        self, component: int, drawable: int, texture: int, palette: int = 0
    ) -> bool:
        """Sets the specified clothing component.

        Args:
                component: Component id of the clothing.
                drawable: Drawable id of the clothing.
                texture: Texture id of the clothing.
                palette: Palette of the clothing.

        Example:
                ```py
                player.set_clothes(1, 14, 0) # Sets the players mask to a blue hockey mask
                ```
        """

    def get_dlc_clothes(self, component: int) -> DlcCloth:
        """Gets the specified dlc clothing component.

        Args:
                component: Component id of the clothing.

        Returns:
                The currently equipped dlc clothing component

        Example:
                ```py
                cloth = player.get_dlc_clothes(1) # Gets the currently equipped mask
                alt.log(cloth.drawable) # Logs the drawable of the currently equipped mask
                ```
        """

    def set_dlc_clothes(
        self, dlc: int, component: int, drawable: int, texture: int, palette: int = 2
    ) -> bool:
        """Sets the specified dlc clothing component.

        Args:
                dlc: Dlc hash of the clothing
                component: Component id of the clothing.
                drawable: Drawable id of the clothing.
                texture: Texture id of the clothing.
                palette: Palette of the clothing.

        Example:
                ```py
                player.set_dlc_clothes(alt.hash("dlcname"), 1, 14, 0)
                ```
        """

    def get_prop(self, component: int) -> Prop:
        """Gets the specified prop component.

        Args:
                component: Component id of the prop.

        Returns:
                The prop component

        Example:
                ```py
                prop = player.get_prop(0) # Gets the hat prop of the player
                alt.log(prop.drawable) # Logs the drawable id of the current hat prop of the player
                ```
        """

    def set_prop(self, component: int, drawable: int, texture: int) -> bool:
        """Sets the specified prop component.

        Args:
                component: Component id of the prop.
                drawable: Drawable id of the prop.
                texture: Texture id of the prop.

        Example:
                ```py
                player.set_prop(0, 13, 0) # sets the players hat prop to a blue cowboy hat
                ```
        """

    def get_dlc_prop(self, component: int) -> DlcProp:
        """Gets the specified dlc prop component.

        Args:
                component: Component id of the prop.

        Returns:
                The dlc prop component

        Example:
                ```py
                prop = player.get_dlc_prop(0) # Gets the hat prop of the player
                alt.log(prop.drawable) # Logs the drawable id of the current hat prop of the player
                ```
        """

    def set_dlc_prop(
        self, dlc: int, component: int, drawable: int, texture: int
    ) -> bool:
        """Sets the specified dlc prop component.

        Args:
                dlc: Dlc hash of the prop
                component: Component id of the prop.
                drawable: Drawable id of the prop.
                texture: Texture id of the prop.

        Example:
                ```py
                player.set_dlc_prop(alt.hash("dlcname"), 0, 13, 0)
                ```
        """

    def clear_prop(self, component: int) -> None:
        """Removes a specified prop component.

        Args:
                component: Component id of the prop.

        Example:
                ```py
                player.clear_prop(0) # removes the player hat prop
                ```
        """

    def is_entity_in_streaming_range(self, entity: Entity | int) -> bool:
        """Checks whether the given entity is in the stream range of the player.

        Args:
                entity: Entity object or it's id

        Example:
                ```py
                if player.in_vehicle:
                    alt.log(player.is_entity_in_streaming_range(player.vehicle)) # This always logs True, because their own vehicle is always in stream range of the player
                ```
        """

    @overload
    def spawn(self, pos: Vector3, delay: int = 0) -> None:
        """Spawns the player in the world.

        Args:
                pos: The position where the player gets spawned.
                delay: The delay at which the player gets spawned after calling this function.

        Note:
                The player has to have a model set before being spawned.
        """

    @overload
    def spawn(self, x: float, y: float, z: float, delay: int = 0) -> None:
        """Spawns the player in the world.

        Args:
                x: The x position where the player gets spawned.
                y: The y position where the player gets spawned.
                z: The z position where the player gets spawned.
                delay: The delay at which the player gets spawned after calling this function.

        Note:
                The player has to have a model set before being spawned.
        """

    def despawn(self) -> None:
        ...

    def get_local_meta(self, key: str) -> Any:
        """Gets a value using the specified key.

        Args:
                key: The key of the value to get.

        Returns:
                Dynamic value associated with the specified key or undefined if no data is present.
        """

    def has_local_meta(self, key: str) -> bool:
        ...

    def set_local_meta(self, key: str, value: Any) -> None:
        """Stores the given value with the specified key.

        Args:
                key: The key of the value to store.
                value: The value to store.
        """

    def delete_local_meta(self, key: str) -> None:
        ...


class Neon(TypedDict):
    left: bool
    right: bool
    front: bool
    back: bool


class Vehicle(Entity):
    @overload
    def __init__(
        self,
        model: str | int,
        x: float,
        y: float,
        z: float,
        rx: float,
        ry: float,
        rz: float,
    ) -> None:
        ...

    @overload
    def __init__(self, model: str | int, pos: Vector3, rot: Vector3) -> None:
        ...

    # Properties
    all: Sequence[Vehicle]
    """List with all vehicles.
	
	Note:
		This creates a clone of the list everytime it is called. It is advised to call this once and store the result in a variable, before iterating over it.

	Example:
		```py
		vehicles = alt.Vehicle.all
		for vehicle in vehicles:
		    alt.log(vehicles.model)
		```
	"""

    @property
    def modkit(self) -> int:
        """Gets or sets the current mod kit of a vehicle."""

    @modkit.setter
    def modkit(self, id: int) -> None:
        ...

    @property
    def primary_color(self) -> int:
        """Gets or sets the current primary color of a vehicle."""

    @primary_color.setter
    def primary_color(self, color: int) -> None:
        ...

    @property
    def primary_color_rgb(self) -> RGBA:
        """Gets or sets the custom primary color as a RGBA type.

        Example:
                ```py
                vehicle = alt.Vehicle("elegy", 0, 0, 0, 0, 0, 0)
                vehicle.primary_color_rgb = alt.RGBA(255, 0, 0)
                alt.log("Vehicle primary color RGB was set to red")
                ```
        """

    @primary_color_rgb.setter
    def primary_color_rgb(self, color: RGBA) -> None:
        ...

    @property
    def secondary_color(self) -> int:
        """Gets or sets the current secondary color."""

    @secondary_color.setter
    def secondary_color(self, color: int) -> None:
        ...

    @property
    def secondary_color_rgb(self) -> RGBA:
        """Gets or sets the custom secondary color as a RGBA type.

        Example:
                ```py
                vehicle = alt.Vehicle("elegy", 0, 0, 0, 0, 0, 0)
                vehicle.secondary_color_rgb = alt.RGBA(255, 0, 0)
                alt.log("Vehicle secondary color RGB was set to red")
                ```
        """

    @secondary_color_rgb.setter
    def secondary_color_rgb(self, color: RGBA) -> None:
        ...

    @property
    def pearl_color(self) -> int:
        """Gets or sets the pearl color of a vehicle."""

    @pearl_color.setter
    def pearl_color(self, color: int) -> None:
        ...

    @property
    def wheel_color(self) -> int:
        """Gets or sets the wheel color."""

    @wheel_color.setter
    def wheel_color(self, color: int) -> None:
        ...

    @property
    def interior_color(self) -> int:
        """Gets or sets the interior color of a vehicle."""

    @interior_color.setter
    def interior_color(self, color: int) -> None:
        ...

    @property
    def dashboard_color(self) -> int:
        """Gets or sets the dashboard color of the vehicle. Dash board colors range from 0 to 159.

        Example:
                ```py
                vehicle = alt.Vehicle("elegy", 0, 0, 0, 0, 0, 0)
                vehicle.dashboard_color = 139
                ```
        """

    @dashboard_color.setter
    def dashboard_color(self, color: int) -> None:
        ...

    @property
    def tire_smoke_color(self) -> RGBA:
        """Gets or sets the color of the tire smoke."""

    @tire_smoke_color.setter
    def tire_smoke_color(self, color: RGBA) -> None:
        ...

    @property
    def custom_tires(self) -> bool:
        """Gets or sets if the vehicle instance has custom tires."""

    @custom_tires.setter
    def custom_tires(self, state: bool) -> None:
        ...

    @property
    def darkness(self) -> int:
        """Applies some decoration effects to the vehicle (e.g.: It makes the hydra looking rusty or applies snow to the front bumper of policeold1). Does not work on every vehicle model.

        Example:
                ```py
                vehicle = alt.Vehicle('elegy', 0, 0, 0, 0, 0, 0)
                vehicle.darkness = 500;
                ```
        """

    @darkness.setter
    def darkness(self, value: int) -> None:
        ...

    @property
    def number_plate_index(self) -> NumberPlateStyle:
        """Gets or sets the current number plate style."""

    @number_plate_index.setter
    def number_plate_index(self, index: NumberPlateStyle | int) -> None:
        ...

    @property
    def number_plate_text(self) -> str:
        """Gets or sets the current text displayed on the number plate."""

    @number_plate_text.setter
    def number_plate_text(self, text: str) -> None:
        ...

    @property
    def window_tint(self) -> WindowTint:
        """Gets or sets the window tint of a vehicle."""

    @window_tint.setter
    def window_tint(self, tint: WindowTint | int) -> None:
        ...

    @property
    def dirt_level(self) -> int:
        """Gets or sets the dirt level of the vehicle."""

    @dirt_level.setter
    def dirt_level(self, level: int) -> None:
        ...

    @property
    def neon(self) -> Neon:
        """Enables or disables a neon light on a specific position."""

    @neon.setter
    def neon(self, new_neon: Neon) -> None:
        ...

    @property
    def neon_color(self) -> RGBA:
        """Gets or sets the color of the neon lights."""

    @neon_color.setter
    def neon_color(self, color: RGBA) -> None:
        ...

    @property
    def livery(self) -> int:
        """Gets or sets the livery of a vehicle."""

    @livery.setter
    def livery(self, new_livery: int) -> None:
        ...

    @property
    def roof_livery(self) -> int:
        """Gets or sets the roof livery of a vehicle."""

    @roof_livery.setter
    def roof_livery(self, new_roof_livery: int) -> None:
        ...

    @property
    def game_state_base64(self) -> str:
        """Gets or sets the game state data of a vehicle as a base64 string.

        Returns:
                A base64 string of the game state data.

        Note:
                Base64 methods are deprecated.
        """

    @game_state_base64.setter
    def game_state_base64(self, base64: str) -> None:
        ...

    @property
    def appearance_data_base64(self) -> str:
        """Gets or sets the appearance of a vehicle as a base64 string.

        Returns:
                A base64 string.

        Note:
                Base64 methods are deprecated.
        """

    @appearance_data_base64.setter
    def appearance_data_base64(self, base64: str) -> None:
        ...

    @property
    def health_data_base64(self) -> str:
        """Gets or sets the health data of a vehicle as a base64 string.

        Returns:
                A base64 string of the health data.

        Note:
                Base64 methods are deprecated.
        """

    @health_data_base64.setter
    def health_data_base64(self, base64: str) -> None:
        ...

    @property
    def damage_data_base64(self) -> str:
        """Gets or sets the damage status of a vehicle as a base64 string.

        Returns:
                A base64 string of the damage status.

        Note:
                Base64 methods are deprecated.
        """

    @damage_data_base64.setter
    def damage_data_base64(self, base64: str) -> None:
        ...

    @property
    def script_data_base64(self) -> str:
        """Gets or sets the script data of a vehicle as a base64 string.

        Returns:
                A base64 string of the script data.

        Note:
                Base64 methods are deprecated.
        """

    @script_data_base64.setter
    def script_data_base64(self, base64: str) -> None:
        ...

    @property
    def engine_on(self) -> bool:
        """Gets or sets the engine state of the vehicle. The functionality of the vehicle engine can be triggered on either client-side or server-side. If you want to trigger the engine on client-side use native.setVehicleEngineOn.

        Example:
                ```py
                vehicle = alt.Vehicle('elegy', 0, 0, 0, 0, 0, 0)
                vehicle.engine_on = True;
                ```
        """

    @engine_on.setter
    def engine_on(self, state: bool) -> None:
        ...

    @property
    def headlight_color(self) -> int:
        """Gets or sets the headlight color of a vehicle."""

    @headlight_color.setter
    def headlight_color(self, color: int) -> None:
        ...

    @property
    def active_radio_station(self) -> RadioStation:
        """Gets or sets the active radio station.

        Example:
                ```py
                vehicle = alt.Vehicle.all[0]
                station = vehicle.active_radio_station
                alt.log(f"Current station: {station}")

                vehicle.active_radio_station = alt.RadioStation.RadioOff
                alt.log("Vehicle radio station was turned off.")
                ```
        """

    @active_radio_station.setter
    def active_radio_station(self, station: RadioStation | int) -> None:
        ...

    @property
    def siren_active(self) -> bool:
        """Gets or sets the siren state of a vehicle."""

    @siren_active.setter
    def siren_active(self, state: bool) -> None:
        ...

    @property
    def lock_state(self) -> VehicleLockState:
        """Gets or sets the lock state of a vehicle."""

    @lock_state.setter
    def lock_state(self, state: VehicleLockState | int) -> None:
        ...

    @property
    def roof_state(self) -> int:
        """Gets or sets the roof state of a vehicle (closed or open)."""

    @roof_state.setter
    def roof_state(self, state: int) -> None:
        ...

    @property
    def lights_multiplier(self) -> float:
        """Gets or sets the lights intensity and distance of a vehicle."""

    @lights_multiplier.setter
    def lights_multiplier(self, multiplier: int) -> None:
        ...

    @property
    def engine_health(self) -> int:
        """
        Gets or sets the current engine health.

        Default maximum engine health is 1000.
        The `vehicle.repair()` function should be used to repair a vehicle if the engine health is less than or equal to zero.

        This example demonstrates that when you drive through a ColShape it will repair the vehicle.

        Example:
                ```py
                colshape = alt.ColShape.circle(-1295.9208984375, 86.0835189819336, 2)

                colshape.set_meta("repairVehicles", True)

                @alt.event(alt.Event.ColShape)
                def colshape_func(colshape: alt.ColShape, entity: alt.Entity, enter: bool):
                    if not isinstance(entity, alt.Vehicle) or not enter or not colshape.get_meta("repairVehicles"):
                            return

                    if entity.destroyed:
                            entity.repair()
                            alt.log("Repaired Destroyed Vehicle")
                            return

                    entity.engine_health = 1000
                    alt.log("Repaired Vehicle")
                ```
        """

    @engine_health.setter
    def engine_health(self, health: int) -> None:
        ...

    @property
    def petrol_tank_health(self) -> int:
        """Gets or sets the current health amount of the petrol tank."""

    @petrol_tank_health.setter
    def petrol_tank_health(self, health: int) -> None:
        ...

    @property
    def body_health(self) -> int:
        """Gets or sets the body health."""

    @body_health.setter
    def body_health(self, health: int) -> None:
        ...

    @property
    def body_additional_health(self) -> int:
        """Gets or sets the additional body health."""

    @body_additional_health.setter
    def body_additional_health(self, health: int) -> None:
        ...

    @property
    def manual_engine_control(self) -> bool:
        """Enables or disables the manual engine control."""

    @manual_engine_control.setter
    def manual_engine_control(self, state: bool) -> None:
        ...

    @property
    def drift_mode_enabled(self) -> bool:
        """Gets or sets the drift mode state of the vehicle."""

    @drift_mode_enabled.setter
    def drift_mode_enabled(self, state: bool) -> None:
        ...

    @property
    def is_mission_train(self) -> bool:
        """Gets or sets if the created train is a mission train."""

    @is_mission_train.setter
    def is_mission_train(self, state: bool) -> None:
        ...

    @property
    def is_train_engine(self) -> bool:
        """Gets or sets if the train is the engine of the train."""

    @is_train_engine.setter
    def is_train_engine(self, is_engine: bool) -> None:
        ...

    @property
    def train_track_id(self) -> int:
        """Gets or sets the track id of the train."""

    @train_track_id.setter
    def train_track_id(self, track_id: int) -> None:
        ...

    @property
    def train_engine_id(self) -> Vehicle | None:
        """Gets or sets the engine of the train."""

    @train_engine_id.setter
    def train_engine_id(self, vehicle: Vehicle | None) -> None:
        ...

    @property
    def train_config_index(self) -> int:
        """Gets or sets the trains config index.

        Note:
                You can find a list of all possible config indices in the trains.xml. Valid indices are between 1 and 25.
        """

    @train_config_index.setter
    def train_config_index(self, config_index: int) -> None:
        ...

    @property
    def train_distance_from_engine(self) -> float:
        """Gets or sets the distance of the trains to the engine."""

    @train_distance_from_engine.setter
    def train_distance_from_engine(self, distance_from_engine: float) -> None:
        ...

    @property
    def is_train_caboose(self) -> bool:
        """Gets or sets if the train is a caboose."""

    @is_train_caboose.setter
    def is_train_caboose(self, is_caboose: bool) -> None:
        ...

    @property
    def train_direction(self) -> bool:
        """Gets or sets the direction of the train."""

    @train_direction.setter
    def train_direction(self, direction: bool) -> None:
        ...

    @property
    def train_passenger_carriages(self) -> bool:
        """Gets or sets if the train is a passenger carriage."""

    @train_passenger_carriages.setter
    def train_passenger_carriages(self, has_passenger_carriages: bool) -> None:
        ...

    @property
    def train_render_derailed(self) -> bool:
        """Gets or sets if the trains is rendered derailed."""

    @train_render_derailed.setter
    def train_render_derailed(self, render_derailed: bool) -> None:
        ...

    @property
    def train_force_doors_open(self) -> bool:
        """Gets or sets if the doors of the trains should be forced open."""

    @train_force_doors_open.setter
    def train_force_doors_open(self, force_doors_open: bool) -> None:
        ...

    @property
    def train_cruise_speed(self) -> float:
        """Gets or sets the cruise speed of the train."""

    @train_cruise_speed.setter
    def train_cruise_speed(self, cruise_speed: float) -> None:
        ...

    @property
    def train_carriage_config_index(self) -> int:
        """Gets or sets the config index of the train's carriage."""

    @train_carriage_config_index.setter
    def train_carriage_config_index(self, carriage_config_index: int) -> None:
        ...

    @property
    def train_linked_to_backward_id(self) -> Vehicle | None:
        """Gets or sets another train that is linked to the back of the train. Returns null if there is no linked train."""

    @train_linked_to_backward_id.setter
    def train_linked_to_backward_id(self, vehicle: Vehicle) -> None:
        ...

    @property
    def train_linked_to_forward_id(self) -> Vehicle | None:
        """Gets or sets another train that is linked to the back of the train. Returns null if there is no linked train in front."""

    @train_linked_to_forward_id.setter
    def train_linked_to_forward_id(self, vehicle: Vehicle) -> None:
        ...

    @property
    def train_unk1(self) -> bool:
        ...

    @train_unk1.setter
    def train_unk1(self, unk1: bool) -> None:
        ...

    @property
    def train_unk2(self) -> bool:
        ...

    @train_unk2.setter
    def train_unk2(self, unk2: bool) -> None:
        ...

    @property
    def train_unk3(self) -> bool:
        ...

    @train_unk3.setter
    def train_unk3(self, unk3: bool) -> None:
        ...

    @property
    def boat_anchor_active(self) -> bool:
        """Gets or sets the status of the boat anchor."""

    @boat_anchor_active.setter
    def boat_anchor_active(self, state: bool) -> None:
        ...

    @property
    def driver(self) -> Player | None:
        """Gets the current driver of the vehicle. It returns null, if there is no driver.

        Example:
                ```py
                vehicle = alt.Vehicle("elegy", 0, 0, 0, 0, 0, 0)
                driver = vehicle.driver
                if driver:
                    alt.log(f"There is currently a player driving this car {driver.name}")
                ```
        """

    @property
    def destroyed(self) -> bool:
        """Gets if a vehicle is destroyed. Destroyed is set to True when specific game activities cause the engine to stop. Explosions, being underwater, crashing too much, etc.

        Example:
                ```py
                vehicle = alt.Vehicle("elegy", 0, 0, 0, 0, 0, 0)
                if vehicle.destroyed:
                    alt.log("The elegy has been destroyed.")
                ```
        """

    @property
    def modkits_count(self) -> int:
        """Gets the maximum amount of vehicle mod kits available."""

    @property
    def is_primary_color_rgb(self) -> bool:
        ...

    @property
    def is_secondary_color_rgb(self) -> bool:
        ...

    @property
    def is_tire_smoke_color_custom(self) -> bool:
        ...

    @property
    def wheel_type(self) -> int:
        """Gets the wheel type."""

    @property
    def front_wheels(self) -> int:
        """Gets the type of the front wheels."""

    @property
    def rear_wheels(self) -> int:
        """Gets the type of the rear wheels."""

    @property
    def neon_active(self) -> bool:
        ...

    @property
    def handbrake_active(self) -> bool:
        """Gets if the handbrake of a car is active."""

    @property
    def daylight_on(self) -> bool:
        """Gets the current state of the daylights.

        Example:
                ```py
                vehicle = alt.Vehicle("elegy", 0, 0, 0, 0, 0, 0)
                if vehicle.daylight_on:
                    alt.log("Vehicle daylights are on")
                else:
                    alt.log("Vehicle daylights are off")
                ```
        """

    @property
    def nightlight_on(self) -> bool:
        """Gets the current state of the nightlights."""

    @property
    def flamethrower_active(self) -> bool:
        """Gets if a flamethrower of a vehicle is active on vehicle models like `cerberus`."""

    @property
    def wheels_count(self) -> int:
        """Gets the amount of wheels of a vehicle."""

    @property
    def repairs_count(self) -> int:
        """Gets how often a vehicle got repaired."""

    @property
    def has_armored_windows(self) -> bool:
        """Gets if the car has armored windows."""

    @property
    def velocity(self) -> Vector3:
        """Gets the velocity vector of a vehicle."""

    @property
    def attached(self) -> Vehicle | None:
        """Gets a vehicle that is attached to the vehicle instance."""

    @property
    def attached_to(self) -> Vehicle | None:
        """Gets a vehicle where the vehicle is attached to."""

    # Methods
    @staticmethod
    def get_by_id(id: int) -> Vehicle | None:
        """Retrieves the vehicle from the pool.

        Args:
                id: The id of the vehicle.

        Returns:
                Vehicle if it was found, otherwise None.
        """

    def get_mod(self, mod_type: VehicleModType | int) -> int:
        """Returns the mod value for a specific mod type.

        Args:
                mod_type: The id of the mod type.

        Returns:
                The value of the mod type.
        """

    def set_mod(self, mod_type: VehicleModType | int, mod_id: int) -> bool:
        """Applies a specific mod of a given mod type.

        Args:
                mod_type: The type of the mod.
                mod_id: The id of the mod.
        """

    def get_mods_count(self, mod_type: VehicleModType | int) -> int:
        """Returns the amount of possible mod values for a specific mod type.

        Args:
                mod_type: The id of the mod type.

        Returns:
                The amount of possible mod values of a mod type.
        """

    def get_extra(self, extra_id: int) -> bool:
        """Returns the state of a specific extra of a vehicle.

        Args:
                extra_id: The id of the extra.

        Returns:
                True when the extra is enabled, otherwise False

        Note:
                Extras are not available on every vehicle model.
        """

    def set_extra(self, extra_id: int, state: bool) -> None:
        """Sets the state of an extra of a vehicle.

        Args:
                extra_id: The id of the extra.
                state: The state of the extra.

        Note:
                Setting extras on vehicle does not work for every vehicle model. For example you can change the light bar of a police car with this method.
        """

    def get_door_state(self, door_id: int) -> VehicleDoorState:
        """Returns the state of a specific door.

        Args:
                door_id: The id of the door.

        Returns:
                The state of the door.
        """

    def set_door_state(self, door_id: int, state: VehicleDoorState | int) -> None:
        """Sets the state of a specific door

        Args:
                door_id: The id of the door.
                state: The state of the door.
        """

    def is_window_opened(self, window_id: int) -> bool:
        """Returns if a specific window is open.

        Args:
                window_id: The id of the window.

        Returns:
                True if the window is opened, otherwise False.
        """

    def set_window_opened(self, window_id: int, state: bool) -> None:
        """Sets if a specific window is open.

        Args:
                window_id: The id of the window.
                state: True to open the window, otherwise False.
        """

    def is_wheel_burst(self, wheel_id: int) -> bool:
        """Returns if a specific wheel is burst.

        Args:
                wheel_id: The id of the wheel.

        Returns:
                True if the wheel is burst, otherwise False.
        """

    def does_wheel_has_tire(self, wheel_id: int) -> bool:
        """Returns if a specific wheel has a tire.

        Args:
                wheel_id: The specific wheel based on the id

        Returns:
                True when the wheel has a tire, otherwise False.
        """

    def is_wheel_detached(self, wheel_id: int) -> bool:
        """Returns if a specific wheel is detached.

        Args:
                wheel_id: The id of the wheel.

        Returns:
                True if the wheel is detached, otherwise False.
        """

    def is_wheel_on_fire(self, wheel_id: int) -> bool:
        """Returns if a specific wheel is on fire.

        Args:
                wheel_id: The id of the wheel.

        Returns:
                True if the wheel is on fire, otherwise False.
        """

    def get_wheel_health(self, wheel_id: int) -> float:
        """Returns the health of a specific wheel.

        Args:
                wheel_id: The id of the wheel.

        Returns:
                The amount of health of a specific wheel.
        """

    def get_part_damage_level(self, part_id: VehiclePart | int) -> VehiclePartDamage:
        """Returns the damage level of a vehicle part.

        Args:
                part_id: The id of a vehicle part.

        Returns:
                The damage level of a vehicle part.
        """

    def get_part_bullet_holes(self, part_id: VehiclePart | int) -> int:
        """Returns the amount of bullet holes of a vehicle part.

        Args:
                part_id: The id of a vehicle part.

        Returns:
                The amount of bullet holes of a vehicle part.
        """

    def is_light_damaged(self, light_id: int) -> bool:
        """Returns if a specific light is damaged.

        Args:
                light_id: The id of the light.

        Returns:
                True if the light is damaged, otherwise False.
        """

    def is_window_damaged(self, window_id: int) -> bool:
        """Returns if a specific window is damaged.

        Args:
                window_id: The id of the window.

        Returns:
                True if the window is damaged, otherwise False.
        """

    def is_special_light_damaged(self, special_light_id: int) -> bool:
        """Returns if a specific special light is damaged.

        Args:
                special_light_id: The id of the special light.

        Returns:
                True if the special light is damaged, otherwise False.
        """

    def get_armored_window_health(self, window_id: int) -> float:
        """Returns the health of a specific armored window.

        Args:
                window_id: The window id.

        Returns:
                The amount of health.
        """

    def get_armored_window_shoot_count(self, window_id: int) -> int:
        """Returns the amount of shoots that a specific armoured window received.

        Args:
                window_id: The window id.

        Returns:
                The amount of shoots that a window received.
        """

    def get_bumper_damage_level(
        self, bumper_id: VehicleBumper | int
    ) -> VehicleBumperDamage:
        """Returns the damage level of a specific bumper.

        Args:
                bumper_id: The id of a bumper.

        Returns:
                The damage level of a bumper.
        """

    def repair(self) -> None:
        """Repairs the vehicle."""

    def set_wheels(self, wheel_type: int, wheel_id: int) -> None:
        """Applies a wheel style based on the type and variation.

        Args:
                wheel_type: The type of the wheel.
                wheel_id: The variation id of the wheel.
        """

    def set_rear_wheels(self, wheel_id: int) -> None:
        """Sets type of the rear wheels.

        Args:
                wheel_id: The id of the rear wheel type.
        """

    def set_wheel_burst(self, wheel_id: int, state: bool) -> None:
        """Sets if a specific wheel is burst.

        Args:
                wheel_id: The id of the wheel.
                state: True to burst the wheel, otherwise False.
        """

    def set_wheel_has_tire(self, wheel_id: int, state: bool) -> None:
        """Sets if a specific wheel has a tire.

        Args:
                wheel_id: The id of the wheel.
                state: True to apply a tire to a wheel, otherwise False.
        """

    def set_wheel_health(self, wheel_id: int, health: int) -> None:
        """Sets the health of a specific wheel.

        Args:
                wheel_id: The id of the wheel.
                health: The health of the wheel.
        """

    def set_wheel_detached(self, wheel_id: int, state: bool) -> None:
        """Sets a wheel either detached or attached.

        Args:
                wheel_id: The id of the wheel.
                state: True to detach the wheel, otherwise False.
        """

    def set_wheel_on_fire(self, wheel_id: int, state: bool) -> None:
        """Sets a wheel either on fire or not.

        Args:
                wheel_id: The id of the wheel.
                state: True to set the wheel on fire, otherwise False.
        """

    def set_wheel_fixed(self, wheel_id: int) -> None:
        """Repairs a specific wheel.

        Args:
                wheel_id: The id of the wheel.
        """

    def set_part_damage_level(
        self, part_id: VehiclePart | int, damage: VehiclePartDamage | int
    ) -> None:
        """Sets the damage level of a vehicle part.

        Args:
                part_id: The id of the part.
                damage: The damage level.
        """

    def set_part_bullet_holes(self, part_id: VehiclePart | int, count: int) -> None:
        """Applies bullet holes to a specific vehicle part.

        Args:
                part_id: The id of the part.
                count: The amount of bullet holes.
        """

    def set_light_damaged(self, light_id: int, is_damaged: bool) -> None:
        """Sets a specific light of the vehicle either damaged or not.

        Args:
                light_id: The id of the light.
                is_damaged: True to damage the specific light, otherwise False.
        """

    def set_window_damaged(self, window_id: int, is_damaged: bool) -> None:
        """Sets if a specific window is damaged.

        Args:
                window_id: The id of the window.
                is_damaged: True to damage the specific window, otherwise False.
        """

    def set_special_light_damaged(
        self, special_light_id: int, is_damaged: bool
    ) -> None:
        """Sets if a special light is damaged.

        Args:
                special_light_id: The id of the special light.
                is_damaged: True to damage the specific special light, otherwise False.
        """

    def set_armored_window_health(self, window_id: int, health: float) -> None:
        """Sets the health of a specific armored window.

        Args:
                window_id: The id of the window.
                health: The amount of health.
        """

    def set_armored_window_shoot_count(self, window_id: int, count: int) -> None:
        """Sets the shoot count of a specific armoured window.

        Args:
                window_id: The id of the window.
                count: The amount of shoots.
        """

    def set_bumper_damage_level(
        self, bumper_id: VehicleBumper | int, level: VehicleBumperDamage | int
    ) -> None:
        """Sets the damage level of a specific bumper.

        Args:
                bumper_id: The id of the bumper.
                level: The damage level.
        """

    def set_search_light_to(self, entity: Entity, state: bool) -> None:
        """Activates the searchlight and follows the target.

        Note:
                Entity parameter isn't working for now and this can only be used for helicopter searchlights.
        """


class VoiceChannel(BaseObject):
    # Constructor
    def __init__(self, spatial: bool, max_distance: float) -> None:
        """Creates a new voice channel.

        Args:
                spatial: Whether the voice channel should be 3D (e.g. talking in person) or 1D (e.g. talking over a telephone).
                max_distance: The max distance at which you can hear each other.

        Note:
                This throws an error when the voice chat is not activated on serverside.
        """

    # Properties
    @property
    def player_count(self) -> int:
        ...

    @property
    def players(self) -> List[Player]:
        ...

    @property
    def max_distance(self) -> float:
        ...

    @property
    def spatial(self) -> bool:
        ...

    def add_player(self, player: Player) -> None:
        ...

    def has_player(self, player: Player) -> bool:
        ...

    def is_player_muted(self, player: Player) -> bool:
        ...

    def mute_player(self, player: Player) -> None:
        ...

    def remove_player(self, player: Player) -> None:
        ...

    def unmute_player(self, player: Player) -> None:
        ...


class Blip(WorldObject):
    all: Sequence[Blip]
    """List with all blips.
	
	Note:
		This creates a clone of the list everytime it is called. It is advised to call this once and store the result in a variable, before iterating over it.

	Example:
		```py
		blips = alt.Blip.all
		for blip in blips:
		    alt.log(blip.name)
		```
	"""

    @property
    def alpha(self) -> int:
        ...

    @alpha.setter
    def alpha(self, new_alpha: int) -> None:
        ...

    @property
    def as_mission_creator(self) -> bool:
        ...

    @as_mission_creator.setter
    def as_mission_creator(self, val: bool) -> None:
        ...

    @property
    def attached_to(self) -> Entity:
        ...

    @attached_to.setter
    def attached_to(self, entity: Entity) -> None:
        ...

    @property
    def bright(self) -> bool:
        ...

    @bright.setter
    def bright(self, new_bright: bool) -> None:
        ...

    @property
    def category(self) -> int:
        ...

    @category.setter
    def category(self, val: int) -> None:
        ...

    @property
    def color(self) -> BlipColor:
        ...

    @color.setter
    def color(self, new_color: BlipColor | int) -> None:
        ...

    @property
    def crew_indicator_visible(self) -> bool:
        ...

    @crew_indicator_visible.setter
    def crew_indicator_visible(self, val: bool) -> None:
        ...

    @property
    def display(self) -> int:
        ...

    @display.setter
    def display(self, new_display: int) -> None:
        ...

    @property
    def flash_interval(self) -> int:
        ...

    @flash_interval.setter
    def flash_interval(self, interval: int) -> None:
        ...

    @property
    def flash_timer(self) -> int:
        ...

    @flash_timer.setter
    def flash_timer(self, timer: int) -> None:
        ...

    @property
    def flashes(self) -> bool:
        ...

    @flashes.setter
    def flashes(self, state: bool) -> None:
        ...

    @property
    def flashes_alternate(self) -> bool:
        ...

    @flashes_alternate.setter
    def flashes_alternate(self, state: bool) -> None:
        ...

    @property
    def friend_indicator_visible(self) -> bool:
        ...

    @friend_indicator_visible.setter
    def friend_indicator_visible(self, state: bool) -> None:
        ...

    @property
    def gxt_name(self) -> str:
        ...

    @gxt_name.setter
    def gxt_name(self, name: str) -> None:
        ...

    @property
    def heading(self) -> float:
        ...

    @heading.setter
    def heading(self, rot: float) -> None:
        ...

    @property
    def heading_indicator_visible(self) -> bool:
        ...

    @heading_indicator_visible.setter
    def heading_indicator_visible(self, state: bool) -> None:
        ...

    @property
    def high_detail(self) -> bool:
        ...

    @high_detail.setter
    def high_detail(self, state: bool) -> None:
        ...

    @property
    def name(self) -> str:
        ...

    @name.setter
    def name(self, new_name: str) -> None:
        ...

    @property
    def number(self) -> int:
        ...

    @number.setter
    def number(self, new_number: int) -> None:
        ...

    @property
    def outline_indicator_visible(self) -> bool:
        ...

    @outline_indicator_visible.setter
    def outline_indicator_visible(self, state: bool) -> None:
        ...

    @property
    def priority(self) -> int:
        ...

    @priority.setter
    def priority(self, state: int) -> None:
        ...

    @property
    def pulse(self) -> bool:
        ...

    @pulse.setter
    def pulse(self, state: bool) -> None:
        ...

    @property
    def route(self) -> bool:
        ...

    @route.setter
    def route(self, state: bool) -> None:
        ...

    @property
    def route_color(self) -> RGBA:
        ...

    @route_color.setter
    def route_color(self, state: RGBA) -> None:
        ...

    @property
    def scale(self) -> float:
        ...

    @scale.setter
    def scale(self, new_scale: float) -> None:
        ...

    @property
    def secondary_color(self) -> RGBA:
        ...

    @secondary_color.setter
    def secondary_color(self, new_scale: RGBA) -> None:
        ...

    @property
    def short_range(self) -> bool:
        ...

    @short_range.setter
    def short_range(self, state: bool) -> None:
        ...

    @property
    def show_cone(self) -> bool:
        ...

    @show_cone.setter
    def show_cone(self, state: bool) -> None:
        ...

    @property
    def shrinked(self) -> bool:
        ...

    @shrinked.setter
    def shrinked(self, state: bool) -> None:
        ...

    @property
    def size(self) -> Vector2:
        """
        Note:
                Doesn't properly work for areablips currently.
        """

    @size.setter
    def size(self, new_size: Vector2) -> None:
        ...

    @property
    def sprite(self) -> BlipSprite:
        ...

    @sprite.setter
    def sprite(self, new_sprite: BlipSprite) -> None:
        ...

    @property
    def tick_visible(self) -> bool:
        ...

    @tick_visible.setter
    def tick_visible(self, state: bool) -> None:
        ...

    @staticmethod
    @overload
    def area(x: float, y: float, z: float, width: float, height: float) -> Blip:
        ...

    @staticmethod
    @overload
    def area(pos: Vector3, width: float, height: float) -> Blip:
        ...

    @staticmethod
    @overload
    def point(x: float, y: float, z: float) -> Blip:
        ...

    @staticmethod
    @overload
    def point(pos: Vector3) -> Blip:
        ...

    @staticmethod
    @overload
    def point(entity: Entity) -> Blip:
        ...

    @staticmethod
    @overload
    def radius(x: float, y: float, z: float, radius: float) -> Blip:
        ...

    @staticmethod
    @overload
    def radius(pos: Vector3, radius: float) -> Blip:
        ...

    def fade(self, opacity: int, duration: int) -> None:
        ...


class ColShape(WorldObject):
    @staticmethod
    @overload
    def circle(x: float, y: float, radius: float) -> ColShape:
        ...

    @staticmethod
    @overload
    def circle(pos: Vector2, radius: float) -> ColShape:
        ...

    @staticmethod
    @overload
    def cylinder(
        x: float, y: float, z: float, radius: float, height: float
    ) -> ColShape:
        ...

    @staticmethod
    @overload
    def cylinder(pos: Vector3, radius: float, height: float) -> ColShape:
        ...

    @staticmethod
    @overload
    def sphere(x: float, y: float, z: float, radius: float) -> ColShape:
        ...

    @staticmethod
    @overload
    def sphere(pos: Vector3, radius: float) -> ColShape:
        ...

    @staticmethod
    @overload
    def cube(
        x1: float, y1: float, z1: float, x2: float, y2: float, z2: float
    ) -> ColShape:
        ...

    @staticmethod
    @overload
    def cube(pos1: Vector3, pos2: Vector3) -> ColShape:
        ...

    @staticmethod
    @overload
    def rectangle(x1: float, y1: float, x2: float, y2: float) -> ColShape:
        ...

    @staticmethod
    @overload
    def rectangle(pos1: Vector3, pos2: Vector3) -> ColShape:
        ...

    @staticmethod
    def polygon(min_z: float, max_z: float, points: List[Vector2]) -> ColShape:
        ...

    @property
    def colshape_type(self) -> ColShapeType:
        ...

    @property
    def players_only(self) -> bool:
        """Whether this colshape should only trigger its enter/leave events for players or all entities."""

    @players_only.setter
    def players_only(self, state: bool) -> None:
        ...

    def is_entity_in(self, entity: Entity) -> bool:
        ...

    def is_point_in(self, pos: Vector3) -> bool:
        ...


class Checkpoint(ColShape):
    @overload
    def __init__(
        self,
        type: int | CheckpointType,
        x: float,
        y: float,
        z: float,
        radius: float,
        height: float,
        r: int,
        g: int,
        b: int,
        a: int,
    ) -> None:
        ...

    @overload
    def __init__(
        self,
        type: int | CheckpointType,
        pos: Vector3,
        radius: float,
        height: float,
        color: RGBA,
    ) -> None:
        ...

    @property
    def checkpoint_type(self) -> CheckpointType:
        ...

    @property
    def height(self) -> float:
        ...

    @property
    def radius(self) -> float:
        ...

    @property
    def color(self) -> RGBA:
        ...


class ConnectionInfo:
    @property
    def name(self) -> str:
        ...

    @property
    def social_id(self) -> int:
        ...

    @property
    def hwid_hash(self) -> int:
        ...

    @property
    def hwid_ex_hash(self) -> int:
        ...

    @property
    def auth_token(self) -> str:
        ...

    @property
    def is_debug(self) -> bool:
        ...

    @property
    def branch(self) -> str:
        ...

    @property
    def build(self) -> int:
        ...

    @property
    def cdn_url(self) -> str:
        ...

    @property
    def password_hash(self) -> int:
        ...

    @property
    def ip(self) -> str:
        ...

    @property
    def discord_user_id(self) -> str:
        ...

    @property
    def accepted(self) -> bool:
        ...

    def accept(self) -> None:
        """
        Note:
                This method works only when accessed from ConnectionQueue.
        """

    def decline(self, reason: str) -> None:
        """
        Note:
                This method works only when accessed from ConnectionQueue.
        """


class Resource:
    all: Sequence[Resource]
    current: Resource

    @property
    def is_started(self) -> bool:
        ...

    @property
    def type(self) -> str:
        ...

    @property
    def name(self) -> str:
        ...

    @property
    def main(self) -> str:
        ...

    @property
    def path(self) -> str:
        ...

    @property
    def exports(self) -> Dict[str, Callable]:
        ...

    @property
    def dependencies(self) -> List[str]:
        ...

    @property
    def dependants(self) -> List[str]:
        ...

    @property
    def required_permissions(self) -> List[int]:
        ...

    @property
    def optional_permissions(self) -> List[int]:
        ...

    @staticmethod
    def get_by_name(resource_name: str) -> Resource:
        ...


class VehicleModelInfo:
    @property
    def title(self) -> str:
        ...

    @property
    def wheels_count(self) -> int:
        ...

    @property
    def has_armored_windows(self) -> bool:
        ...

    @property
    def primary_color(self) -> int:
        ...

    @property
    def secondary_color(self) -> int:
        ...

    @property
    def pearl_color(self) -> int:
        ...

    @property
    def wheels_color(self) -> int:
        ...

    @property
    def interior_color(self) -> int:
        ...

    @property
    def dashboard_color(self) -> int:
        ...

    @property
    def has_auto_attach_trailer(self) -> bool:
        ...

    @property
    def type(self) -> VehicleType:
        ...

    @property
    def available_modkits(self) -> List[bool]:
        ...

    def has_extra(self, extra_id: int):
        ...

    def has_default_extra(self, extra_id: int):
        ...


# alt attributes
branch: str
"""Represents the current branch."""
debug: bool
"""Returns if the resource is in debug mode."""
default_dimension: int
global_dimension: int
root_dir: str
"""The root directory of the server."""
sdk_version: int
"""Represents the current SDK version."""
version: str
"""Represents the current version.

Note:
	It's a slighty modified semantic versioning specification, which can be matched using this regular expression pattern `^(0|[1-9]\d*)\.(0|[1-9]\d*)(?:-((?:0|[1-9]\d*|\d*[a-zA-Z-][0-9a-zA-Z-]*)(?:\.(?:0|[1-9]\d*|\d*[a-zA-Z-][0-9a-zA-Z-]*))*))$`
"""


# alt methods
def hash(value: str) -> int:
    """Creates a hash using Jenkins one-at-a-time algorithm.

    Args:
            value: A string from which hash will be created.
    """


def get_net_time() -> int:
    """Gets the amount of milliseconds since the server was started."""


def get_server_config() -> Dict[str, Any]:
    ...


def get_vehicle_model_info_by_hash(vehicle_hash: int) -> VehicleModelInfo:
    ...


def hash_server_password(password: str) -> int:
    """Hash string with alt:V algortihm.

    Args:
            password: The string you want to hash
    """


def set_password(password: str) -> None:
    """Change the server password at runtime.

    Args:
            password: The new password.
    """


def stop_server() -> None:
    ...


def string_to_sha256(value: str) -> str:
    ...


def export(name: str, object: Any) -> None:
    """Exports a value to other resources

    Args:
            name: The name of the export
            object: The exported object
    """


def restart_resource(resource_name: str) -> None:
    """Restarts the specified resource.

    Args:
            resource_name: Name of the resource.
    """


def start_resource(resource_name: str) -> None:
    """Starts the specified resource.

    Args:
            resource_name: Name of the resource.
    """


def stop_resource(resource_name: str) -> None:
    """Stops the specified resource.

    Args:
            resource_name: Name of the resource.
    """


def delete_meta(key: str) -> None:
    """Removes the specified key and the data connected to that specific key.

    Args:
            key: The key of the value to remove.
    """


def get_meta(key: str) -> Any:
    """Gets a value using the specified key.

    Args:
            key: The key of the value to get.

    Returns:
            Dynamic value associated with the specified key or undefined if no data is present.
    """


def set_meta(key: str, value: Any) -> None:
    """Stores the given value with the specified key.

    Args:
            key: The key of the value to store.
            value: The value to store.
    """


def has_meta(key: str) -> bool:
    """Determines whether contains the specified key.

    Args:
            key: The key of the value to locate.

    Returns:
            True when element associated with the specified key is stored.
    """


def get_synced_meta(key: str) -> Any:
    """Gets a value using the specified key.

    Args:
            key: The key of the value to get.

    Returns:
            Dynamic value associated with the specified key or undefined if no data is present.
    """


def has_synced_meta(key: str) -> bool:
    """Determines whether contains the specified key.

    Args:
            key: The key of the value to locate.

    Returns:
            True when element associated with the specified key is stored.
    """


def set_synced_meta(key: str, value: Any) -> None:
    """Stores the given value with the specified key.

    Args:
            key: The key of the value to store.
            value: The value to store.
    """


def delete_synced_meta(key: str) -> None:
    """Removes the specified key and the data connected to that specific key.

    Args:
            key: The key of the value to remove.
    """


def timer(func: Callable, milliseconds: float) -> int:
    """
    Schedules execution of handler once after the expiration of interval.

    Args:
            func: Function that should be scheduled for execution.
            milliseconds: The time, in milliseconds, before execution of specified function.

    Returns:
            A number representing the id value of the timer that is set. Use this value with the [clear_timer][alt.clear_timer] function to cancel the timer.
    """


def clear_timer(timer_id: int) -> None:
    """Clears a timer set with the [timer][alt.timer] function.

    Args:
            timer_id: The id of a timer.
    """


def log(*args: Any, sep: str = " ") -> None:
    """Logs the specified arguments to the console.

    Args:
            *args: Arguments logged to the console.
            sep: Separator used for separating arguments.
    """


def log_error(*args: Any, sep: str = " ") -> None:
    """Logs the specified arguments as an error to the console.

    Args:
            *args: Arguments logged to the console.
            sep: Separator used for separating arguments.
    """


def log_warning(*args: Any, sep: str = " ") -> None:
    """Logs the specified arguments as a warning to the console.

    Args:
            *args: Arguments logged to the console.
            sep: Separator used for separating arguments.
    """


def emit(event_name: str, *args: Any) -> None:
    """Emits specified event across resources.

    Args:
            event_name: Name of the event.
            *args: Rest parameters for emit to send.
    """


def emit_client(player: Player | List[Player], event_name: str, *args: Any) -> None:
    """Emits specified event to specific client.

    Args:
            player: Event is sent to specific player.
            event_name: Name of the event.
            *args: Rest parameters for emit to send.
    """


def emit_all_clients(event_name: str, *args: Any) -> None:
    """Emits specified event to all clients.

    Args:
            event_name: Name of the event.
            *args: Rest parameters for emit to send.
    """


# decorators
def event(event: Event) -> Callable:
    """A decorator that subscribes to a server event with a listener

    Args:
            event: The subscribed event.
    """


def custom_event(event: str) -> Callable:
    """A decorator that subscribes to a custom event with a listener

    Args:
            event: Name of the event.
    """


def client_event(event: str) -> Callable:
    """A decorator that subscribes to a client event with a listener

    Args:
            event: Name of the event.
    """


def task(
    *, milliseconds: float = 0, seconds: float = 0, minutes: float = 0, hours: float = 0
) -> Callable:
    """A decorator which creates a task executed every X milliseconds

    Args:
            milliseconds: Time in milliseconds.
            seconds: Time in seconds.
            minutes: Time in minutes.
            hours: Time in hours.
    """
