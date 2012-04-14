-- ----------------------------
-- Table structure for `bpet_ability`
-- ----------------------------
DROP TABLE IF EXISTS `bpet_ability`;
CREATE TABLE `bpet_ability` (
  `AbilityID` int(11) unsigned NOT NULL DEFAULT '0',
  `Abilityspell` int(11) unsigned NOT NULL DEFAULT '0',
  `Abilitylvlreq` int(11) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`AbilityID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='BPet System';

-- ----------------------------
-- Records of bpet_ability
-- ----------------------------
INSERT INTO `bpet_ability` VALUES (0, 32703, 10); -- regen
INSERT INTO `bpet_ability` VALUES (1, 32703, 10); -- regen
INSERT INTO `bpet_ability` VALUES (2, 32703, 10); -- regen
INSERT INTO `bpet_ability` VALUES (3, 7160, 10); -- execute
INSERT INTO `bpet_ability` VALUES (4, 7160, 10); -- execute
INSERT INTO `bpet_ability` VALUES (5, 7160, 10); -- execute
INSERT INTO `bpet_ability` VALUES (6, 118442, 10); -- swiftness
INSERT INTO `bpet_ability` VALUES (7, 118442, 10); -- swiftness
INSERT INTO `bpet_ability` VALUES (8, 118442, 10); -- swiftness
INSERT INTO `bpet_ability` VALUES (9, 41410, 10); -- damned
INSERT INTO `bpet_ability` VALUES (10, 41410, 10); -- damned
INSERT INTO `bpet_ability` VALUES (11, 41410, 10); -- damned
INSERT INTO `bpet_ability` VALUES (12, 115997, 10); -- elusiveness
INSERT INTO `bpet_ability` VALUES (13, 115997, 10); -- elusiveness
INSERT INTO `bpet_ability` VALUES (14, 115997, 10); -- elusiveness
INSERT INTO `bpet_ability` VALUES (15, 33054, 10); -- spellshield
INSERT INTO `bpet_ability` VALUES (16, 33054, 10); -- spellshield
INSERT INTO `bpet_ability` VALUES (17, 33054, 10); -- spellshield
INSERT INTO `bpet_ability` VALUES (18, 2380, 10); -- wheather resistance
INSERT INTO `bpet_ability` VALUES (19, 2380, 10); -- wheather resistance
INSERT INTO `bpet_ability` VALUES (20, 2380, 10); -- wheather resistance
INSERT INTO `bpet_ability` VALUES (21, 60075, 10); -- enrage
INSERT INTO `bpet_ability` VALUES (22, 60075, 10); -- enrage
INSERT INTO `bpet_ability` VALUES (23, 60075, 10); -- enrage
INSERT INTO `bpet_ability` VALUES (24, 8361, 10); -- purity
INSERT INTO `bpet_ability` VALUES (25, 8361, 10); -- purity
INSERT INTO `bpet_ability` VALUES (26, 8361, 10); -- purity
INSERT INTO `bpet_ability` VALUES (27, 64668, 10); -- failsafe
INSERT INTO `bpet_ability` VALUES (28, 64668, 10); -- failsafe
INSERT INTO `bpet_ability` VALUES (29, 64668, 10); -- failsafe

-- ----------------------------
-- Table structure for `bpet_template`
-- ----------------------------
DROP TABLE IF EXISTS `bpet_template`;
CREATE TABLE `bpet_template` (
  `petID` int(11) unsigned NOT NULL DEFAULT '0',
  `speciesID` int(11) unsigned NOT NULL DEFAULT '0',
  `creatureID` int(11) unsigned DEFAULT '0',
  `name` varchar(100) DEFAULT 'BPet',
  `Ability0` int(11) unsigned NOT NULL DEFAULT '0', -- passive ability
  `Ability1` int(11) unsigned NOT NULL DEFAULT '0',
  `Ability2` int(11) unsigned NOT NULL DEFAULT '0',
  `Ability3` int(11) unsigned NOT NULL DEFAULT '0',
  `Ability4` int(11) unsigned NOT NULL DEFAULT '0',
  `Ability5` int(11) unsigned NOT NULL DEFAULT '0',
  `Ability6` int(11) unsigned NOT NULL DEFAULT '0',
  `Level` int(11) unsigned NOT NULL DEFAULT '1',
  `Health` int(11) unsigned NOT NULL DEFAULT '0',
  `Attack` int(11) unsigned NOT NULL DEFAULT '0',
  `Defense` int(11) unsigned NOT NULL DEFAULT '0',
  `Movement` int(11) unsigned NOT NULL DEFAULT '0',
  `Item` int(11) unsigned NOT NULL DEFAULT '0',
  `icon` varchar(100) DEFAULT 'BPet',
  `WeakVs1` int(11) unsigned NOT NULL DEFAULT '0',
  `WeakVs2` int(11) unsigned NOT NULL DEFAULT '0',
  `StrongVs1` int(11) unsigned NOT NULL DEFAULT '0',
  `StrongVs2` int(11) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`petID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='BPet System';

-- ----------------------------
-- Records of bpet_template
-- ----------------------------
INSERT INTO `bpet_template` VALUES (0, 0, 6293, 'HUMANOID', 0, 0, 1, 2, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (1, 1, 6293, 'DRAGON', 0, 3, 4, 5, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (2, 2, 4185, 'FLYING', 0, 6, 7, 8, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (3, 3, 36499, 'UNDEAD', 0, 9, 10, 11, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (4, 4, 27627, 'CRITTER', 0, 12, 13, 14, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (5, 5, 28482, 'MAGICAL', 0, 15, 16, 17, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (6, 6, 28482, 'ELEMENTAL', 0, 18, 19, 20, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (7, 7, 38065, 'BEAST', 0, 21, 22, 23, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (8, 8, 38065, 'AQUATIC', 0, 24, 25, 26, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);
INSERT INTO `bpet_template` VALUES (9, 9, 38065, 'MECHANICAL', 0, 27, 28, 29, 0, 0, 0, 1, 100, 50, 50, 5, 0, 'BPet', 0, 0, 0, 0);

/*
List of Battle Pets:

Beasts:

Albino Snake
Arctic Grizzly Cub
Baby Ape
Bananas
Beaver Yearling
Black Kingsnake
Blue Racer
Brown Snake
Cobra Hatchling
Crimson Snake
Darkmoon Monkey
Darting Hatchling
Deviate Hatchling
Dun Morogh Cub
Durotar Scorpion
Egbert
Fox Kit
Green Water Snake
Gundrak Hatchling
Hyjal Bear Cub
Keg Pony
Lashtail Hatchling
Leaping Hatchling
Mulgore Hatchling
Nightsaber Cub
Obsidian Hatchling
Otter Pup
Panda Cub
Panther Cub
Peanut
Pint-Sized Pink Pachyderm
Porcupette
Raccoon Kit
Ravager Hatchling
Ravasaur Hatchling
Razormaw Hatchling
Razzashi Hatchling
Ribbon Snake
Scarlet Snake
Scorpling
Venomhide Hatchling
Wind Rider Cub
Winter Reindeer
Winterspring Cub
Winterspring Cub
Worg Pup

Critters:

Armadillo Pup
Baby Blizzard Bear
Black Sheep
Black Tabby Cat
Bombay Cat
Brown Prairie Dog
Brown Rabbit
Calico Cat
Cockroach
Cornish Rex Cat
Darkmoon Cub
Elwynn Lamb
Feline Familiar
Giant Sewer Rat
Golden Pig
Kitty
Little Fawn
Lucky
Lucky
Manny
Mr. Chilly
Mr. Grubbs
Mr. Kitty
Mr. Wiggles
Nuts
Orange Tabby Cat
Pengu
Perky Pug
Plump Turkey
Sand Scarab
Scooter the Snail
Siamese Cat
Silver Pig
Silver Tabby Cat
Smolderweb Hatchling
Snowshoe Hare
Snowshoe Hare
Snowshoe Rabbit
Spring Rabbit
Stinker
Whiskers the Rat
White Kitten
White Tiger Cub
Wolpertinger

Dragonkin:

Azure Whelpling
Bronze Whelpling
Celestial Dragon
Crimson Whelpling
Crystalwing Stone Drake
Dark Whelpling
Emerald Whelpling
Essence of Competition
Faeling
Lil' Deathwing
Lil' Tarecgosa
Netherwhelp
Onyxian Whelpling
Proto-Drake Whelp
Soul of the Aspects
Spirit of Competition
Sprite Darter Hatchling
Tiny Green Dragon
Tiny Red Dragon

Elemental:

Ammen Vale Lashling
Core Hound Pup
Crimson Lasher
Dark Phoenix Hatchling
Elementium Geode
Frigid Frostling
Kirin Tor Familiar
Lil' Ragnaros
Lumpy
Pebble
Phoenix Hatchling
Rumbling Rockling
Searing Scorchling
Singing Sunflower
Sinister Squashling
Spirit of Summer
Swirling Stormling
Teldrassil Sproutling
Tiny Shale Spider
Tiny Snowman
Withers

Flying:

Ancona Chicken
Blood Parrot
Blue Dragonhawk Hatchling
Blue Mini Jouster
Blue Moth
Brilliant Kaliri
Bush Chicken
Cenarion Hatchling
Cockatiel
Cockatoo
Dragon Kite
Dragon Kite
Eagle Owl
Firefly
Gold Mini Jouster
Golden Dragonhawk Hatchling
Great Horned Owl
Green Wing Macaw
Gryphon Hatchling
Hawk Owl
Hippogryph Hatchling
Hungry Nether Ray
Hyacinth Macaw
Miniwing
Nether Ray Fry
Prairie Chicken
Pterrordax Hatchling
Red Dragonhawk Hatchling
Red Moth
Rustberg Gull
Senegal
Silver Dragonhawk Hatchling
Snowy Owl
Tickbird Hatchling
Tiny Flamefly
Tiny Sporebat
Tuskarr Kite
Westfall Chicken
White Moth
White Plymouth Rock
White Tickbird Hatchling
Yellow Moth

Humanoid:

Argent Gruntling
Argent Squire
Ar'lia
Blood Elf Orphan
Blue Baby Murloc
Curious Oracle Hatchling
Curious Wolvar Pup
Deathy
Draenei Orphan
Father Winter's Helper
Fathom-Stalker Azjentus
Greedy Kobold
Green Baby Murloc
Grunty
Guild Herald
Guild Herald
Guild Page
Guild Page
Gurky
Hardboiled Egg
Human Orphan
Lurky
Mini Tyrael
Moonkin Hatchling
Moonkin Hatchling
Murkablo
Murki
Murkimus the Gladiator
Murkimus the Gladiator
Murky
Oracle Orphan
Orcish Orphan
Pandaren Monk
Peddlefeet
Pink Baby Murloc
Poley
Purple Baby Murloc
Terky
Winter's Little Helper
Wolvar Orphan

Magical:

Crimson Serpent
Disgusting Oozeling
Elven Wisp
Enchanted Broom
Enchanted Lantern
Ethereal Soul-Trader
Festival Lantern
Fetish Shaman
Gregarious Grell
Jade Tiger
Legs
Lizzy
Lunar Lantern
Magic Lamp
Mana Wyrmling
Mini Diablo
Onyx Panther
PattyMack - WildBattlePet Test
Shimmering Wyrmling
Spectral Tiger Cub
Toxic Wasteling
Voodoo Figurine
Willy
Zeppit
Zergling
Zipao Tiger

Mechanical:

Alarming Clockbot
Blue Clockwork Rocket Bot
Clockwork Gnome
Clockwork Rocket Bot
Creepy Crate
Darkmoon Tonk
Darkmoon Zeppelin
Depleted War Golem
De-Weaponized Mechanical Companion
Krazzworks Zeppelin
Landro's Lil' XT
Landro's Lil' XT
Lifelike Toad
Lil' Smoky
Lil' XT
Mechanical Chicken
Mechanical Squirrel
Mechanopeep
Mini Thor
Personal World Destroyer
Pet Bombling
Rocket Chicken
Sen'jin Fetish
Tiny Harvester
Toy RC Mortar Tank
Tranquil Mechanical Yeti
Warbot
XS-001 Constructor Bot

Undead:

Corrupted Kitten
Coyote Spirit
Crawling Claw
Eye of the Legion
Fossilized Hatchling
Frosty
Ghostly Skull
Infested Bear Cub
Landro's Lichling
Lil' K.T.
Macabre Marionette
Scourge Haunt
Tirisfal Batling
Vampiric Batling

Uknown:

Admiral Taylor
Alliance Balloon
Alliance Balloon
Alliance Banner
Companion Combat Vehicle
Cosmetic Fire large
Cosmetic Smoke From Fire
Darkmoon Balloon
Darren's Test BattlePet 1
Darren's Test BattlePet 2
Darren's Test BattlePet 3
Darren's Test BattlePet 4
Darren's Test BattlePet 5
Darren's Test BattlePet 6
Darren's Test NPC
Darren's Test NPC 2
Fire Bunny
General Nazgrim
General Nazgrim
Gorrok
Green Balloon
Green Balloon
Guardian Cub
Hellscream's Vanguard
Horde Balloon
Horde Balloon
Horde Banner
Large Alliance Tent
Large Horde Tent
Large Panda Tent
Mishka
Mist
Mogu Defier
Mogu Door
Natasha
Orphan Spell Visual Invisible Holder
Player 1's Pet
Player 2's Pet
Player Clone (TEMP)
Player Clone (TEMP)
Reincarnated Skytalon
Rivett Clutchpop
Shademaster Kiryn
Small Alliance Tent
Small Horde Tent
Small Panda Tent
Sully The Pickle" McLeary"
Test Panda
Vladimir
Worgen Dust Bunny
Yellow Balloon
Yellow Balloon
Zandalari Fleshrender
Zandalari Fleshrender
Zandalari Fleshrender
Zandalari Priest
Zandalari Priest
Zandalari Priest
Zandalari Refugee
Zandalari Soulraiser
Zandalari Tomb-robber
Zandalari Underling
Zandalari Underling

Water:

Albino Snapjaw
Baby Shark
Bubbles
Chuck
Darkmoon Turtle
Dart Frog
Hawksbill Snapjaw
Island Frog
Jubling
Leatherback Snapjaw
Loggerhead Snapjaw
Magical Crawdad
Mojo
Muckbreath
Olive Snapjaw
Purple Puffer
Rainbow Trout
Sea Pony
Snarly
Speedy
Strand Crawler
Tiny Water Strider
Toothy
Tree Frog
Whirling Waveling
Wood Frog
*/