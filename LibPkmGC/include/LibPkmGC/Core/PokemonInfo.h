#ifndef _LIBPKMGC_POKEMON_INFO_H
#define _LIBPKMGC_POKEMON_INFO_H

#include <LibPkmGC/Core/IntegerTypes.h>
namespace LibPkmGC{
enum GameIndex {
	NoGame = 0,
	FireRed = 1,
	LeafGreen = 2,

	Sapphire = 8,
	Ruby = 9,
	Emerald = 10,

	Colosseum_XD = 11
};
enum RegionIndex {
	NoRegion = 0, NTSC_J = 1, NTSC_U = 2, PAL = 3
};
enum LanguageIndex {
	NoLanguage = 0, Japanese = 1, English = 2, German = 3, French = 4, Italian = 5, Spanish = 6
};

struct LIBPKMGC_DECL VersionInfo {
	/* The following enum values come from Col/XD */

	GameIndex game;
	RegionIndex currentRegion;
	RegionIndex originalRegion;

	LanguageIndex language;

	void load(u8* data);
	void load(u8 lg, u8 gm); // GBA
	void save(u8* data);
	void save(u8& lg, u8& gm); // GBA

	bool isIncomplete(void) const;

};

const  VersionInfo emptyVersionInfo = { NoGame, NoRegion, NoRegion, NoLanguage };
  
enum ContestAchievementLevel {
	NoContestWon = 0,
	NormalContestWon = 1,
	SuperContestWon = 2,
	HyperContestWon = 3,
	MasterContestWon = 4
};


enum Gender{ Male = 0, Female = 1, Genderless = 2 };
enum EncounterType{
	Unencountered = 0,
	FatefulEncounter = 1,
	Gift = 0x50,
	NormalEncounter = 0xb8,
};

enum PokemonStorageUnit {
	NotStored = 0,
	StoredInParty = 1,
	StoredInPC = 2,
	StoredInPurifier = 3,
	StoredInDaycare = 4
};

struct LIBPKMGC_DECL PokemonStorageInfo {
	PokemonStorageUnit storageUnit;
	size_t index, subIndex;
};

const  PokemonStorageInfo emptyStorageInfo = { NotStored, 0, 0 };

enum PokemonSpeciesIndex{
	NoSpecies = 0,
	Bulbasaur = 0x01,
	Ivysaur = 0x02,
	Venusaur = 0x03,
	Charmander = 0x04,
	Charmeleon = 0x05,
	Charizard = 0x06,
	Squirtle = 0x07,
	Wartortle = 0x08,
	Blastoise = 0x09,
	Caterpie = 0x0A,
	Metapod = 0x0B,
	Butterfree = 0x0C,
	Weedle = 0x0D,
	Kakuna = 0x0E,
	Beedrill = 0x0F,
	Pidgey = 0x10,
	Pidgeotto = 0x11,
	Pidgeot = 0x12,
	Rattata = 0x13,
	Raticate = 0x14,
	Spearow = 0x15,
	Fearow = 0x16,
	Ekans = 0x17,
	Arbok = 0x18,
	Pikachu = 0x19,
	Raichu = 0x1A,
	Sandshrew = 0x1B,
	Sandslash = 0x1C,
	NidoranF = 0x1D,
	Nidorina = 0x1E,
	Nidoqueen = 0x1F,
	NidoranM = 0x20,
	Nidorino = 0x21,
	Nidoking = 0x22,
	Clefairy = 0x23,
	Clefable = 0x24,
	Vulpix = 0x25,
	Ninetales = 0x26,
	Jigglypuff = 0x27,
	Wigglytuff = 0x28,
	Zubat = 0x29,
	Golbat = 0x2A,
	Oddish = 0x2B,
	Gloom = 0x2C,
	Vileplume = 0x2D,
	Paras = 0x2E,
	Parasect = 0x2F,
	Venonat = 0x30,
	Venomoth = 0x31,
	Diglett = 0x32,
	Dugtrio = 0x33,
	Meowth = 0x34,
	Persian = 0x35,
	Psyduck = 0x36,
	Golduck = 0x37,
	Mankey = 0x38,
	Primeape = 0x39,
	Growlithe = 0x3A,
	Arcanine = 0x3B,
	Poliwag = 0x3C,
	Poliwhirl = 0x3D,
	Poliwrath = 0x3E,
	Abra = 0x3F,
	Kadabra = 0x40,
	Alakazam = 0x41,
	Machop = 0x42,
	Machoke = 0x43,
	Machamp = 0x44,
	Bellsprout = 0x45,
	Weepinbell = 0x46,
	Victreebel = 0x47,
	Tentacool = 0x48,
	Tentacruel = 0x49,
	Geodude = 0x4A,
	Graveler = 0x4B,
	Golem = 0x4C,
	Ponyta = 0x4D,
	Rapidash = 0x4E,
	Slowpoke = 0x4F,
	Slowbro = 0x50,
	Magnemite = 0x51,
	Magneton = 0x52,
	Farfetch_d = 0x53,
	Doduo = 0x54,
	Dodrio = 0x55,
	Seel = 0x56,
	Dewgong = 0x57,
	Grimer = 0x58,
	Muk = 0x59,
	Shellder = 0x5A,
	Cloyster = 0x5B,
	Gastly = 0x5C,
	Haunter = 0x5D,
	Gengar = 0x5E,
	Onix = 0x5F,
	Drowzee = 0x60,
	Hypno = 0x61,
	Krabby = 0x62,
	Kingler = 0x63,
	Voltorb = 0x64,
	Electrode = 0x65,
	Exeggcute = 0x66,
	Exeggutor = 0x67,
	Cubone = 0x68,
	Marowak = 0x69,
	Hitmonlee = 0x6A,
	Hitmonchan = 0x6B,
	Lickitung = 0x6C,
	Koffing = 0x6D,
	Weezing = 0x6E,
	Rhyhorn = 0x6F,
	Rhydon = 0x70,
	Chansey = 0x71,
	Tangela = 0x72,
	Kangaskhan = 0x73,
	Horsea = 0x74,
	Seadra = 0x75,
	Goldeen = 0x76,
	Seaking = 0x77,
	Staryu = 0x78,
	Starmie = 0x79,
	MrMime = 0x7A,
	Scyther = 0x7B,
	Jynx = 0x7C,
	Electabuzz = 0x7D,
	Magmar = 0x7E,
	Pinsir = 0x7F,
	Tauros = 0x80,
	Magikarp = 0x81,
	Gyarados = 0x82,
	Lapras = 0x83,
	Ditto = 0x84,
	Eevee = 0x85,
	Vaporeon = 0x86,
	Jolteon = 0x87,
	Flareon = 0x88,
	Porygon = 0x89,
	Omanyte = 0x8A,
	Omastar = 0x8B,
	Kabuto = 0x8C,
	Kabutops = 0x8D,
	Aerodactyl = 0x8E,
	Snorlax = 0x8F,
	Articuno = 0x90,
	Zapdos = 0x91,
	Moltres = 0x92,
	Dratini = 0x93,
	Dragonair = 0x94,
	Dragonite = 0x95,
	Mewtwo = 0x96,
	Mew = 0x97,

	Chikorita = 0x98,
	Bayleef = 0x99,
	Meganium = 0x9A,
	Cyndaquil = 0x9B,
	Quilava = 0x9C,
	Typhlosion = 0x9D,
	Totodile = 0x9E,
	Croconaw = 0x9F,
	Feraligatr = 0xA0,
	Sentret = 0xA1,
	Furret = 0xA2,
	Hoothoot = 0xA3,
	Noctowl = 0xA4,
	Ledyba = 0xA5,
	Ledian = 0xA6,
	Spinarak = 0xA7,
	Ariados = 0xA8,
	Crobat = 0xA9,
	Chinchou = 0xAA,
	Lanturn = 0xAB,
	Pichu = 0xAC,
	Cleffa = 0xAD,
	Igglybuff = 0xAE,
	Togepi = 0xAF,
	Togetic = 0xB0,
	Natu = 0xB1,
	Xatu = 0xB2,
	Mareep = 0xB3,
	Flaaffy = 0xB4,
	Ampharos = 0xB5,
	Bellossom = 0xB6,
	Marill = 0xB7,
	Azumarill = 0xB8,
	Sudowoodo = 0xB9,
	Politoed = 0xBA,
	Hoppip = 0xBB,
	Skiploom = 0xBC,
	Jumpluff = 0xBD,
	Aipom = 0xBE,
	Sunkern = 0xBF,
	Sunflora = 0xC0,
	Yanma = 0xC1,
	Wooper = 0xC2,
	Quagsire = 0xC3,
	Espeon = 0xC4,
	Umbreon = 0xC5,
	Murkrow = 0xC6,
	Slowking = 0xC7,
	Misdreavus = 0xC8,
	Unown = 0xC9,
	Wobbuffet = 0xCA,
	Girafarig = 0xCB,
	Pineco = 0xCC,
	Forretress = 0xCD,
	Dunsparce = 0xCE,
	Gligar = 0xCF,
	Steelix = 0xD0,
	Snubbull = 0xD1,
	Granbull = 0xD2,
	Qwilfish = 0xD3,
	Scizor = 0xD4,
	Shuckle = 0xD5,
	Heracross = 0xD6,
	Sneasel = 0xD7,
	Teddiursa = 0xD8,
	Ursaring = 0xD9,
	Slugma = 0xDA,
	Magcargo = 0xDB,
	Swinub = 0xDC,
	Piloswine = 0xDD,
	Corsola = 0xDE,
	Remoraid = 0xDF,
	Octillery = 0xE0,
	Delibird = 0xE1,
	Mantine = 0xE2,
	Skarmory = 0xE3,
	Houndour = 0xE4,
	Houndoom = 0xE5,
	Kingdra = 0xE6,
	Phanpy = 0xE7,
	Donphan = 0xE8,
	Porygon2 = 0xE9,
	Stantler = 0xEA,
	Smeargle = 0xEB,
	Tyrogue = 0xEC,
	Hitmontop = 0xED,
	Smoochum = 0xEE,
	Elekid = 0xEF,
	Magby = 0xF0,
	Miltank = 0xF1,
	Blissey = 0xF2,
	Raikou = 0xF3,
	Entei = 0xF4,
	Suicune = 0xF5,
	Larvitar = 0xF6,
	Pupitar = 0xF7,
	Tyranitar = 0xF8,
	Lugia = 0xF9,
	HoOh = 0xFA,
	Celebi = 0xFB,

	Treecko = 0x115,
	Grovyle = 0x116,
	Sceptile = 0x117,
	Torchic = 0x118,
	Combusken = 0x119,
	Blaziken = 0x11A,
	Mudkip = 0x11B,
	Marshtomp = 0x11C,
	Swampert = 0x11D,
	Poochyena = 0x11E,
	Mightyena = 0x11F,
	Zigzagoon = 0x120,
	Linoone = 0x121, 
	Wurmple = 0x122,
	Silcoon = 0x123,
	Beautifly = 0x124,
	Cascoon = 0x125,
	Dustox = 0x126,
	Lotad = 0x127,
	Lombre = 0x128,
	Ludicolo = 0x129,
	Seedot = 0x12A,
	Nuzleaf = 0x12B,
	Shiftry = 0x12C,
	Nincada = 0x12D,
	Ninjask = 0x12E,
	Shedinja = 0x12F,
	Taillow = 0x130,
	Swellow = 0x131,
	Shroomish = 0x132,
	Breloom = 0x133,
	Spinda = 0x134,
	Wingull = 0x135,
	Pelipper = 0x136,
	Surskit = 0x137,
	Masquerain = 0x138,
	Wailmer = 0x139,
	Wailord = 0x13A,
	Skitty = 0x13B,
	Delcatty = 0x13C,
	Kecleon = 0x13D,
	Baltoy = 0x13E,
	Claydol = 0x13F,
	Nosepass = 0x140,
	Torkoal = 0x141,
	Sableye = 0x142,
	Barboach = 0x143,
	Whiscash = 0x144,
	Luvdisc = 0x145,
	Corphish = 0x146,
	Crawdaunt = 0x147,
	Feebas = 0x148,
	Milotic = 0x149,
	Carvanha = 0x14A,
	Sharpedo = 0x14B,
	Trapinch = 0x14C,
	Vibrava = 0x14D,
	Flygon = 0x14E,
	Makuhita = 0x14F,
	Hariyama = 0x150,
	Electrike = 0x151,
	Manectric = 0x152,
	Numel = 0x153,
	Camerupt = 0x154,
	Spheal = 0x155,
	Sealeo = 0x156,
	Walrein = 0x157,
	Cacnea = 0x158,
	Cacturne = 0x159,
	Snorunt = 0x15A,
	Glalie = 0x15B,
	Lunatone = 0x15C,
	Solrock = 0x15D,
	Azurill = 0x15E,
	Spoink = 0x15F,
	Grumpig = 0x160,
	Plusle = 0x161,
	Minun = 0x162,
	Mawile = 0x163,
	Meditite = 0x164,
	Medicham = 0x165,
	Swablu = 0x166,
	Altaria = 0x167,
	Wynaut = 0x168,
	Duskull = 0x169,
	Dusclops = 0x16A,
	Roselia = 0x16B,
	Slakoth = 0x16C,
	Vigoroth = 0x16D,
	Slaking = 0x16E,
	Gulpin = 0x16F,
	Swalot = 0x170,
	Tropius = 0x171,
	Whismur = 0x172,
	Loudred = 0x173,
	Exploud = 0x174,
	Clamperl = 0x175,
	Huntail = 0x176,
	Gorebyss = 0x177,
	Absol = 0x178,
	Shuppet = 0x179,
	Banette = 0x17A,
	Seviper = 0x17B,
	Zangoose = 0x17C,
	Relicanth = 0x17D,
	Aron = 0x17E,
	Lairon = 0x17F,
	Aggron = 0x180,
	Castform = 0x181,
	Volbeat = 0x182,
	Illumise = 0x183,
	Lileep = 0x184,
	Cradily = 0x185,
	Anorith = 0x186,
	Armaldo = 0x187,
	Ralts = 0x188, 
	Kirlia = 0x189,
	Gardevoir = 0x18A,
	Bagon = 0x18B,
	Shelgon = 0x18C,
	Salamence = 0x18D,
	Beldum = 0x18E,
	Metang = 0x18F,
	Metagross = 0x190,
	Regirock = 0x191,
	Regice = 0x192,
	Registeel = 0x193,
	Kyogre = 0x194, 
	Groudon = 0x195, 
	Rayquaza = 0x196, 
	Latias = 0x197, 
	Latios = 0x198, 
	Jirachi = 0x199, 
	Deoxys = 0x19A, 
	Chimecho = 0x19B,

	Bonsly = 0x19D,
	Munchlax = 0x19E // Munchlax is not a valid Pokémon in this game (0 base stats total), unlike Bonsly
};

enum PokemonNatureIndex{
	Hardy = 0,
	Lonely = 1,
	Brave = 2,
	Adamant = 3,
	Naughty = 4,
	Bold = 5,
	Docile = 6,
	Relaxed = 7,
	Impish = 8,
	Lax = 9,
	Timid = 10,
	Hasty = 11,
	Serious = 12,
	Jolly = 13,
	Naive = 14,
	Modest = 15,
	Mild = 16,
	Quiet = 17,
	Bashful = 18,
	Rash = 19,
	Calm = 20,
	Gentle = 21,
	Sassy = 22,
	Careful = 23,
	Quirky = 24
};



enum PokemonMoveIndex{
	NoMove = 0,
	Pound = 1,
	KarateChop = 2,
	DoubleSlap = 3,
	CometPunch = 4,
	MegaPunch = 5,
	PayDay = 6,
	FirePunch = 7,
	IcePunch = 8,
	ThunderPunch = 9,
	Scratch = 10,
	ViceGrip = 11,
	Guillotine = 12,
	RazorWind = 13,
	SwordsDance = 14,
	Cut = 15,
	Gust = 16,
	WingAttack = 17,
	Whirlwind = 18,
	Fly = 19,
	Bind = 20,
	Slam = 21,
	VineWhip = 22,
	Stomp = 23,
	DoubleKick = 24,
	MegaKick = 25,
	JumpKick = 26,
	RollingKick = 27,
	SandAttack = 28,
	Headbutt = 29,
	HornAttack = 30,
	FuryAttack = 31,
	HornDrill = 32,
	Tackle = 33,
	BodySlam = 34,
	Wrap = 35,
	TakeDown = 36,
	Thrash = 37,
	DoubleEdge = 38,
	TailWhip = 39,
	PoisonSting = 40,
	Twineedle = 41,
	PinMissile = 42,
	Leer = 43,
	Bite = 44,
	Growl = 45,
	Roar = 46,
	Sing = 47,
	Supersonic = 48,
	SonicBoom = 49,
	Disable = 50,
	Acid = 51,
	Ember = 52,
	Flamethrower = 53,
	Mist = 54,
	WaterGun = 55,
	HydroPump = 56,
	Surf = 57,
	IceBeam = 58,
	Blizzard = 59,
	Psybeam = 60,
	BubbleBeam = 61,
	AuroraBeam = 62,
	HyperBeam = 63,
	Peck = 64,
	DrillPeck = 65,
	Submission = 66,
	LowKick = 67,
	Counter = 68,
	SeismicToss = 69,
	Strength = 70,
	Absorb = 71,
	MegaDrain = 72,
	LeechSeed = 73,
	Growth = 74,
	RazorLeaf = 75,
	SolarBeam = 76,
	PoisonPowder = 77,
	StunSpore = 78,
	SleepPowder = 79,
	PetalDance = 80,
	StringShot = 81,
	DragonRage = 82,
	FireSpin = 83,
	ThunderShock = 84,
	Thunderbolt = 85,
	ThunderWave = 86,
	Thunder = 87,
	RockThrow = 88,
	Earthquake = 89,
	Fissure = 90,
	Dig = 91,
	Toxic = 92,
	Confusion = 93,
	Psychic = 94,
	Hypnosis = 95,
	Meditate = 96,
	Agility = 97,
	QuickAttack = 98,
	Rage = 99,
	Teleport = 100,
	NightShade = 101,
	Mimic = 102,
	Screech = 103,
	DoubleTeam = 104,
	Recover = 105,
	Harden = 106,
	Minimize = 107,
	Smokescreen = 108,
	ConfuseRay = 109,
	Withdraw = 110,
	DefenseCurl = 111,
	Barrier = 112,
	LightScreen = 113,
	Haze = 114,
	Reflect = 115,
	FocusEnergy = 116,
	Bide = 117,
	Metronome = 118,
	MirrorMove = 119,
	SelfDestruct = 120,
	EggBomb = 121,
	Lick = 122,
	Smog = 123,
	Sludge = 124,
	BoneClub = 125,
	FireBlast = 126,
	Waterfall = 127,
	Clamp = 128,
	Swift = 129,
	SkullBash = 130,
	SpikeCannon = 131,
	Constrict = 132,
	Amnesia = 133,
	Kinesis = 134,
	SoftBoiled = 135,
	HighJumpKick = 136,
	Glare = 137,
	DreamEater = 138,
	PoisonGas = 139,
	Barrage = 140,
	LeechLife = 141,
	LovelyKiss = 142,
	SkyAttack = 143,
	Transform = 144,
	Bubble = 145,
	DizzyPunch = 146,
	Spore = 147,
	Flash = 148,
	Psywave = 149,
	Splash = 150,
	AcidArmor = 151,
	Crabhammer = 152,
	Explosion = 153,
	FurySwipes = 154,
	Bonemerang = 155,
	Rest = 156,
	RockSlide = 157,
	HyperFang = 158,
	Sharpen = 159,
	Conversion = 160,
	TriAttack = 161,
	SuperFang = 162,
	Slash = 163,
	Substitute = 164,
	Struggle = 165,
	Sketch = 166,
	TripleKick = 167,
	Thief = 168,
	SpiderWeb = 169,
	MindReader = 170,
	Nightmare = 171,
	FlameWheel = 172,
	Snore = 173,
	Curse = 174,
	Flail = 175,
	Conversion2 = 176,
	Aeroblast = 177,
	CottonSpore = 178,
	Reversal = 179,
	Spite = 180,
	PowderSnow = 181,
	Protect = 182,
	MachPunch = 183,
	ScaryFace = 184,
	FeintAttack = 185,
	SweetKiss = 186,
	BellyDrum = 187,
	SludgeBomb = 188,
	MudSlap = 189,
	Octazooka = 190,
	Spikes = 191,
	ZapCannon = 192,
	Foresight = 193,
	DestinyBond = 194,
	PerishSong = 195,
	IcyWind = 196,
	Detect = 197,
	BoneRush = 198,
	LockOn = 199,
	Outrage = 200,
	Sandstorm = 201,
	GigaDrain = 202,
	Endure = 203,
	Charm = 204,
	Rollout = 205,
	FalseSwipe = 206,
	Swagger = 207,
	MilkDrink = 208,
	Spark = 209,
	FuryCutter = 210,
	SteelWing = 211,
	MeanLook = 212,
	Attract = 213,
	SleepTalk = 214,
	HealBell = 215,
	Return = 216,
	Present = 217,
	Frustration = 218,
	Safeguard = 219,
	PainSplit = 220,
	SacredFire = 221,
	Magnitude = 222,
	DynamicPunch = 223,
	Megahorn = 224,
	DragonBreath = 225,
	BatonPass = 226,
	Encore = 227,
	Pursuit = 228,
	RapidSpin = 229,
	SweetScent = 230,
	IronTail = 231,
	MetalClaw = 232,
	VitalThrow = 233,
	MorningSun = 234,
	Synthesis = 235,
	Moonlight = 236,
	HiddenPower = 237,
	CrossChop = 238,
	Twister = 239,
	RainDance = 240,
	SunnyDay = 241,
	Crunch = 242,
	MirrorCoat = 243,
	PsychUp = 244,
	ExtremeSpeed = 245,
	AncientPower = 246,
	ShadowBall = 247,
	FutureSight = 248,
	RockSmash = 249,
	Whirlpool = 250,
	BeatUp = 251,
	FakeOut = 252,
	Uproar = 253,
	Stockpile = 254,
	SpitUp = 255,
	Swallow = 256,
	HeatWave = 257,
	Hail = 258,
	Torment = 259,
	Flatter = 260,
	WillOWisp = 261,
	Memento = 262,
	Facade = 263,
	FocusPunch = 264,
	SmellingSalts = 265,
	FollowMe = 266,
	NaturePower = 267,
	Charge = 268,
	Taunt = 269,
	HelpingHand = 270,
	Trick = 271,
	RolePlay = 272,
	Wish = 273,
	Assist = 274,
	Ingrain = 275,
	Superpower = 276,
	MagicCoat = 277,
	Recycle = 278,
	Revenge = 279,
	BrickBreak = 280,
	Yawn = 281,
	KnockOff = 282,
	Endeavor = 283,
	Eruption = 284,
	SkillSwap = 285,
	Imprison = 286,
	Refresh = 287,
	Grudge = 288,
	Snatch = 289,
	SecretPower = 290,
	Dive = 291,
	ArmThrust = 292,
	Camouflage = 293,
	TailGlow = 294,
	LusterPurge = 295,
	MistBall = 296,
	FeatherDance = 297,
	TeeterDance = 298,
	BlazeKick = 299,
	MudSport = 300,
	IceBall = 301,
	NeedleArm = 302,
	SlackOff = 303,
	HyperVoice = 304,
	PoisonFang = 305,
	CrushClaw = 306,
	BlastBurn = 307,
	HydroCannon = 308,
	MeteorMash = 309,
	Astonish = 310,
	WeatherBall = 311,
	Aromatherapy = 312,
	FakeTears = 313,
	AirCutter = 314,
	Overheat = 315,
	OdorSleuth = 316,
	RockTomb = 317,
	SilverWind = 318,
	MetalSound = 319,
	GrassWhistle = 320,
	Tickle = 321,
	CosmicPower = 322,
	WaterSpout = 323,
	SignalBeam = 324,
	ShadowPunch = 325,
	Extrasensory = 326,
	SkyUppercut = 327,
	SandTomb = 328,
	SheerCold = 329,
	MuddyWater = 330,
	BulletSeed = 331,
	AerialAce = 332,
	IcicleSpear = 333,
	IronDefense = 334,
	Block = 335,
	Howl = 336,
	DragonClaw = 337,
	FrenzyPlant = 338,
	BulkUp = 339,
	Bounce = 340,
	MudShot = 341,
	PoisonTail = 342,
	Covet = 343,
	VoltTackle = 344,
	MagicalLeaf = 345,
	WaterSport = 346,
	CalmMind = 347,
	LeafBlade = 348,
	DragonDance = 349,
	RockBlast = 350,
	ShockWave = 351,
	WaterPulse = 352,
	DoomDesire = 353,
	PsychoBoost = 354
};

enum PokemonSpeciesExpGrowthType {
	MediumFast = 0,
	Erratic = 1,
	Fluctuating = 2,
	MediumSlow = 3,
	Fast = 4,
	Slow = 5,
};

enum PokemonNatureAffinity {
	Beneficial = 0, Neutral = 1, Detrimental = 2
};

enum PokemonAbilityIndex {
	NoAbility = 0,
	Stench = 1,
	Drizzle = 2,
	SpeedBoost = 3,
	BattleArmor = 4,
	Sturdy = 5,
	Damp = 6,
	Limber = 7,
	SandVeil = 8,
	Static = 9,
	VoltAbsorb = 10,
	WaterAbsorb = 11,
	Oblivious = 12,
	CloudNine = 13,
	Compoundeyes = 14,
	Insomnia = 15,
	ColorChange = 16,
	Immunity = 17,
	FlashFire = 18,
	ShieldDust = 19,
	OwnTempo = 20,
	SuctionCups = 21,
	Intimidate = 22,
	ShadowTag = 23,
	RoughSkin = 24,
	WonderGuard = 25,
	Levitate = 26,
	EffectSpore = 27,
	Synchronize = 28,
	ClearBody = 29,
	NaturalCure = 30,
	Lightningrod = 31,
	SereneGrace = 32,
	SwiftSwim = 33,
	Chlorophyll = 34,
	Illuminate = 35,
	Trace = 36,
	HugePower = 37,
	PoisonPoint = 38,
	InnerFocus = 39,
	MagmaArmor = 40,
	WaterVeil = 41,
	MagnetPull = 42,
	Soundproof = 43,
	RainDish = 44,
	SandStream = 45,
	Pressure = 46,
	ThickFat = 47,
	EarlyBird = 48,
	FlameBody = 49,
	RunAway = 50,
	KeenEye = 51,
	HyperCutter = 52,
	Pickup = 53,
	Truant = 54,
	Hustle = 55,
	CuteCharm = 56,
	Plus = 57,
	Minus = 58,
	Forecast = 59,
	StickyHold = 60,
	ShedSkin = 61,
	Guts = 62,
	MarvelScale = 63,
	LiquidOoze = 64,
	Overgrow = 65,
	Blaze = 66,
	Torrent = 67,
	Swarm = 68,
	RockHead = 69,
	Drought = 70,
	ArenaTrap = 71,
	VitalSpirit = 72,
	WhiteSmoke = 73,
	PurePower = 74,
	ShellArmor = 75,
	Cacophony = 76,
	AirLock = 77,
};

enum PokemonSpeciesGenderRatio {
	MaleOnly = 0,
	M7F1 = 31,
	M1F3 = 63,
	M1F1 = 127,
	M3F1 = 191,
	M1F7 = 223,
	FemaleOnly = 254,
	GenderlessOnly = 255, // 'Only' to avoid a name clash with enum Gender
};

enum PokemonStatus {
	NoStatus = 0, Poisoned = 3, BadlyPoisoned = 4, Paralyzed = 5, Burnt = 6, Frozen = 7, Asleep = 8
};

LIBPKMGC_DECL u16 pokemonStatusToBitField(PokemonStatus status, s8 turnsOfBadPoison = 0, s8 turnsOfSleepRemaining = 0);
LIBPKMGC_DECL PokemonStatus pokemonStatusFromBitField(u16 status, s8* turnsOfBadPoison = NULL, s8* turnsOfSleepRemaining = NULL);

struct LIBPKMGC_DECL PokemonSpeciesData {
	bool isValid;
	PokemonSpeciesExpGrowthType expGrowthType;
	PokemonSpeciesGenderRatio genderRatio;
	u16 baseHappinness;
	PokemonAbilityIndex possibleAbilities[2];
	u16 baseStats[6];
	u16 EVYield[6];
};

LIBPKMGC_DECL const u32* getSpeciesExpTable(PokemonSpeciesIndex index);
LIBPKMGC_DECL PokemonSpeciesData getSpeciesData(PokemonSpeciesIndex index);
LIBPKMGC_DECL PokemonNatureAffinity getNatureStatAffinity(PokemonNatureIndex nature, size_t stat);
LIBPKMGC_DECL u8 getBaseMoveMaxPPs(PokemonMoveIndex move);

LIBPKMGC_DECL u16 getPokedexIndexOf(PokemonSpeciesIndex speciesIndex);
LIBPKMGC_DECL PokemonSpeciesIndex getSpeciesIndexOf(u16 pokedexIndex);

struct LIBPKMGC_DECL PokemonMove {
	PokemonMoveIndex move;
	u8 currentPPs;
	u8 nbPPUpsUsed;

	void load(u8* data);

	void save(u8* data);

	u8 calculateMaxPP(void) const;

};

struct LIBPKMGC_DECL PokemonMarkings {
	bool circle, square, triangle, heart;
	void load(u8 m);
	u8 save(void) const;
};

}

#endif