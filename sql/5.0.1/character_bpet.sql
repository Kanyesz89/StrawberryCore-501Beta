-- ----------------------------
-- Table structure for `character_bpet`
-- ----------------------------
DROP TABLE IF EXISTS `character_bpet`;
CREATE TABLE `character_bpet` (
  `guID` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
  `petID` int(11) unsigned NOT NULL DEFAULT '0',
  `ownerID` int(11) unsigned NOT NULL DEFAULT '0',
  `curAbility1` int(11) unsigned NOT NULL DEFAULT '0',
  `curAbility2` int(11) unsigned NOT NULL DEFAULT '0',
  `curAbility3` int(11) unsigned NOT NULL DEFAULT '0',
  `curName` varchar(100) DEFAULT 'BPet',
  `curlevel` int(11) unsigned NOT NULL DEFAULT '1',
  `curxp` int(11) unsigned NOT NULL DEFAULT '0',
  `curhealth` int(11) unsigned NOT NULL DEFAULT '1',
  `card` tinyint(3) unsigned NOT NULL DEFAULT '0', -- aka slot
  `favourite` int(11) unsigned NOT NULL DEFAULT '0',
  `wins` int(11) unsigned NOT NULL DEFAULT '0',
  `loss` int(11) unsigned NOT NULL DEFAULT '0',
  `draw` int(11) unsigned NOT NULL DEFAULT '0',
  `rank` int(11) unsigned NOT NULL DEFAULT '0';  
  PRIMARY KEY (`petid`),
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Battle Pet System';

-- ----------------------------
-- Records of character_bpet
-- ----------------------------

-- ----------------------------
-- Table structure for `world_bpet_ability`
-- ----------------------------
DROP TABLE IF EXISTS `world_bpet_ability`;
CREATE TABLE `world_bpet_ability` (
  `abilityID` int(11) unsigned NOT NULL DEFAULT '0',
  `abilityslot` int(11) unsigned NOT NULL DEFAULT '0',
  `abilityspell` int(11) unsigned NOT NULL DEFAULT '0',
  `abilitycooldown` int(11) unsigned NOT NULL DEFAULT '0';
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='BPet System';

-- ----------------------------
-- Records of world_bpet_ability
-- ----------------------------
INSERT INTO `world_bpet_ability` VALUES (0, 0, 32703, 0); --regen
INSERT INTO `world_bpet_ability` VALUES (1, 1, 32703, 0); --regen
INSERT INTO `world_bpet_ability` VALUES (2, 2, 32703, 0); --regen
INSERT INTO `world_bpet_ability` VALUES (3, 0, 7160, 0); --execute
INSERT INTO `world_bpet_ability` VALUES (4, 1, 7160, 0); --execute
INSERT INTO `world_bpet_ability` VALUES (5, 2, 7160, 0); --execute
INSERT INTO `world_bpet_ability` VALUES (6, 0, 118442, 0); --swiftness
INSERT INTO `world_bpet_ability` VALUES (7, 1, 118442, 0); --swiftness
INSERT INTO `world_bpet_ability` VALUES (8, 2, 118442, 0); --swiftness
INSERT INTO `world_bpet_ability` VALUES (9, 0, 41410, 0); --damned
INSERT INTO `world_bpet_ability` VALUES (10, 1, 41410, 0); --damned
INSERT INTO `world_bpet_ability` VALUES (11, 2, 41410, 0); --damned
INSERT INTO `world_bpet_ability` VALUES (12, 0, 115997, 0); --elusiveness
INSERT INTO `world_bpet_ability` VALUES (13, 1, 115997, 0); --elusiveness
INSERT INTO `world_bpet_ability` VALUES (14, 2, 115997, 0); --elusiveness
INSERT INTO `world_bpet_ability` VALUES (15, 0, 33054, 0); --spellshield
INSERT INTO `world_bpet_ability` VALUES (16, 1, 33054, 0); --spellshield
INSERT INTO `world_bpet_ability` VALUES (17, 2, 33054, 0); --spellshield
INSERT INTO `world_bpet_ability` VALUES (18, 0, 2380, 0); --wheather resistance
INSERT INTO `world_bpet_ability` VALUES (19, 1, 2380, 0); --wheather resistance
INSERT INTO `world_bpet_ability` VALUES (20, 2, 2380, 0); --wheather resistance
INSERT INTO `world_bpet_ability` VALUES (21, 0, 60075, 0); --enrage
INSERT INTO `world_bpet_ability` VALUES (22, 1, 60075, 0); --enrage
INSERT INTO `world_bpet_ability` VALUES (23, 2, 60075, 0); --enrage
INSERT INTO `world_bpet_ability` VALUES (24, 0, 8361, 0); --purity
INSERT INTO `world_bpet_ability` VALUES (25, 1, 8361, 0); --purity
INSERT INTO `world_bpet_ability` VALUES (26, 2, 8361, 0); --purity
INSERT INTO `world_bpet_ability` VALUES (27, 0, 64668, 0); --failsafe
INSERT INTO `world_bpet_ability` VALUES (28, 1, 64668, 0); --failsafe
INSERT INTO `world_bpet_ability` VALUES (29, 2, 64668, 0); --failsafe

-- ----------------------------
-- Table structure for `world_bpet_template`
-- ----------------------------
DROP TABLE IF EXISTS `world_bpet_template`;
CREATE TABLE `world_bpet_template` (
  `petID` int(11) unsigned NOT NULL DEFAULT '0',
  `speciesID` int(11) unsigned NOT NULL DEFAULT '0',
  `modelid` int(11) unsigned DEFAULT '0',
  `defname` varchar(100) DEFAULT 'BPet',
  `defAbility1` int(11) unsigned NOT NULL DEFAULT '0',
  `defAbility2` int(11) unsigned NOT NULL DEFAULT '0',
  `defAbility3` int(11) unsigned NOT NULL DEFAULT '0',
  `maxLevel` int(11) unsigned NOT NULL DEFAULT '1',
  `maxXp` int(11) unsigned NOT NULL DEFAULT '0',
  `maxHealth` int(11) unsigned NOT NULL DEFAULT '0';
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='BPet System';

-- ----------------------------
-- Records of world_bpet_template
-- ----------------------------
INSERT INTO `world_bpet_template` VALUES (0, 0, 6293, 'HUMANOID', 0, 1, 2, 20, 100, 100);
INSERT INTO `world_bpet_template` VALUES (1, 1, 6293, 'DRAGON', 3, 4, 5, 20, 100, 100);
INSERT INTO `world_bpet_template` VALUES (2, 2, 4185, 'FLYING', 6, 7, 8, 20, 100, 100);
INSERT INTO `world_bpet_template` VALUES (3, 3, 36499, 'UNDEAD', 9, 10, 11, 20, 100, 100);
INSERT INTO `world_bpet_template` VALUES (4, 4, 27627, 'CRITTER', 12, 13, 14, 20, 100, 100);
INSERT INTO `world_bpet_template` VALUES (5, 5, 28482, 'MAGICAL', 15, 16, 17, 20, 100, 100);
INSERT INTO `world_bpet_template` VALUES (6, 6, 28482, 'ELEMENTAL', 18, 19, 20, 20, 100, 100);
INSERT INTO `world_bpet_template` VALUES (7, 7, 38065, 'BEAST', 21, 22, 23, 20, 100, 100);
INSERT INTO `world_bpet_template` VALUES (8, 8, 38065, 'AQUATIC', 24, 25, 26, 20, 100, 100);
INSERT INTO `world_bpet_template` VALUES (9, 9, 38065, 'MECHANICAL', 27, 28, 29, 20, 100, 100);