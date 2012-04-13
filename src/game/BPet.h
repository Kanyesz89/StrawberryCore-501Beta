/*
 * Copyright (C) 2010-2012 Strawberry-Pr0jcts <http://strawberry-pr0jcts.com/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef STRAWBERRYSERVER_PET_H
#define STRAWBERRYSERVER_PET_H

#include "Common.h"
#include "ObjectGuid.h"
#include "Creature.h"
#include "Unit.h"
/*
RANDOM battlepet events
PET_BATTLE_PVP_DUEL_REQUESTED
PET_BATTLE_PVP_DUEL
PET_BATTLE_MAX_HEALTH_CHANGED
PET_BATTLE_HEALTH_CHANGED
PET_BATTLE_PET_CHANGED
PET_BATTLE_AURA_APPLIED
PET_BATTLE_AURA_CANCELED
PET_BATTLE_AURA_CHANGED
PET_BATTLE_OPENING_START
PET_BATTLE_OPENING_DONE
PET_BATTLE_CLOSE
PET_BATTLE_FINAL_ROUND
PET_BATTLE_HEALTH_CHANGED
PET_BATTLE_TURN_STARTED
PET_BATTLE_PET_CHANGED
PET_BATTLE_ACTION_SELECTED
PET_BATTLE_PET_ROUND_PLAYBACK_COMPLETE
PET_BATTLE_PET_ROUND_RESULTS
PET_BATTLE_EVENT_ON_APPLY
PET_BATTLE_EVENT_ON_DAMAGE_TAKEN
PET_BATTLE_EVENT_ON_DAMAGE_DEALT
PET_BATTLE_EVENT_ON_HEAL_TAKEN
PET_BATTLE_EVENT_ON_HEAL_DEALT

battlepet Lang info
BATTLE_PET_FAVORITE = "Set Favorite";
BATTLE_PET_NAME_1 = "Humanoid";
BATTLE_PET_NAME_10 = "Mechanical";
BATTLE_PET_NAME_2 = "Dragonkin";
BATTLE_PET_NAME_3 = "Flying";
BATTLE_PET_NAME_4 = "Undead";
BATTLE_PET_NAME_5 = "Critter";
BATTLE_PET_NAME_6 = "Magic";
BATTLE_PET_NAME_7 = "Elemental";
BATTLE_PET_NAME_8 = "Beast";
BATTLE_PET_NAME_9 = "Aquatic";
BATTLE_PET_PUT_IN_CAGE = "Put In Cage";
BATTLE_PET_RELEASE = "Release";
BATTLE_PET_RENAME = "Rename";
BATTLE_PET_SUMMON = "Summon";
BATTLE_PET_UNFAVORITE = "Remove Favorite";
PET_BATTLE_ABILITIES_LABEL = "Abilities";
PET_BATTLE_AREA_EFFECT = "Area Effect:";
PET_BATTLE_CURRENT_HEALTH_FORMAT = "%d/%d";
PET_BATTLE_CURRENT_XP_FORMAT = "%d/%d";
PET_BATTLE_CURRENT_XP_FORMAT_VERBOSE = "XP: %d/%d";
PET_BATTLE_EFFECTIVENESS_VS = "Vs.";
PET_BATTLE_HEALTH_VERBOSE = "Health: %d/%d";
PET_BATTLE_PASS = "Pass";
PET_BATTLE_PVP_DUEL = "Pet-battle Duel";
PET_BATTLE_PVP_DUEL_REQUESTED = "%s has challenged you to a pet-battle.";
PET_BATTLE_RESISTANT_TO_LABEL = "Resistant To:";
PET_BATTLE_SELECT_AN_ACTION = "Select An Action";
PET_BATTLE_SELECT_A_PET = "Select a pet!";
PET_BATTLE_STATS_LABEL = "Stats";
PET_BATTLE_TURN_COOLDOWN = "%d Turn Cooldown";
PET_BATTLE_TURN_CURRENT_COOLDOWN = "Cooldown Remaining: %d |4Turn:Turns;";
PET_BATTLE_WAITING_FOR_OPPONENT = "Waiting For Opponent...";
PET_BATTLE_WEAK_TO_LABEL = "Weak To:";
TOOLTIP_WILDBATTLEPET_LEVEL = "Pet Level %s Wild Pet";
TOOLTIP_WILDBATTLEPET_LEVEL_CLASS = "Pet Level %s %s";

battlepet lang errors
ERR_PETBATTLE_CREATE_FAILED = "Failed to create pet-battle.";
ERR_PETBATTLE_DECLINED = "Pet-battle invitation declined.";
ERR_PETBATTLE_IN_BATTLE = "Pet-battle already in progress.";
ERR_PETBATTLE_NOT_A_TRAINER = "Must be a battle pet trainer to pet-battle.";
ERR_PETBATTLE_NOT_HERE = "Cannot pet-battle here.";
ERR_PETBATTLE_NOT_HERE_OBSTRUCTED = "Pet-battle area is obstructed.";
ERR_PETBATTLE_NOT_HERE_ON_TRANSPORT = "Cannot pet-battle on a transport.";
ERR_PETBATTLE_NOT_HERE_UNEVEN_GROUND = "Ground is too uneven to pet-battle.";
ERR_PETBATTLE_NOT_WHILE_DEAD = "Cannot pet-battle while dead.";
ERR_PETBATTLE_NOT_WHILE_FLYING = "Must be standing to pet-battle.";
ERR_PETBATTLE_NOT_WHILE_IN_COMBAT = "Cannot pet-battle while in combat.";
ERR_PETBATTLE_TARGET_INVALID = "Not a valid pet-battle target.";
ERR_PETBATTLE_TARGET_NOT_CAPTURABLE = "Creature is not a valid pet-battle target.";
ERR_PETBATTLE_TARGET_OUT_OF_RANGE = "Pet-battle target out of range.";

battlepet info
MAX_NUM_PET_BATTLE_ATTACK_MODIFIERS = 2;
MAX_BATTLE_PET_TEXT = "Pets: %d/500";
PET_BATTLE_STATE_ATTACK = 18;
PET_BATTLE_STATE_SPEED = 20;
PET_BATTLE_EVENT_ON_APPLY = 0;
PET_BATTLE_EVENT_ON_DAMAGE_TAKEN = 1;
PET_BATTLE_EVENT_ON_DAMAGE_DEALT = 2;
PET_BATTLE_EVENT_ON_HEAL_TAKEN = 3;
PET_BATTLE_EVENT_ON_HEAL_DEALT = 4;
PET_BATTLE_PAD_INDEX = 0;
PBDEBUG_TURN_TIME = 30;
PBDEBUG_ACTIVE_ALLY = 1;
PBDEBUG_ACTIVE_ENEMY = 2;

*/

#define BPETS_IN_BATTLE  3
#define BPET_ABILITIES  3

enum BPET_WEATHER_TEXTURES 
{
	BPET_WEATHER0                 = 53,                      // BurntEarth
	BPET_WEATHER1                 = 54,                      // ArcaneStorm
	BPET_WEATHER2                 = 55,                      // Moonlight
	BPET_WEATHER3                 = 56,                      // Darkness
	BPET_WEATHER4                 = 57,                      // Sandstorm
	BPET_WEATHER5                 = 58,                      // Blizzard
	BPET_WEATHER6                 = 59,                      // Mud
	BPET_WEATHER7                 = 60,                      // Rain
	BPET_WEATHER8                 = 61,                      // Sunlight
	BPET_WEATHER9                 = 62,                      // StaticField
	BPET_WEATHER10                = 63,                      // Windy
};

enum BPET_TYPE_PASSIVES
{
	BATTLE_PET_PASS_HU            = 238,                     // Humanoid - Recovery
    BATTLE_PET_PASS_DR            = 245,                     // Dragon - Execute
    BATTLE_PET_PASS_FL            = 239,                     // Flying - Swiftness
    BATTLE_PET_PASS_UN            = 242,                     // Undead - Damned
    BATTLE_PET_PASS_CR            = 236,                     // Critter - Elusive
    BATTLE_PET_PASS_MA            = 243,                     // Magical - Spellshield
    BATTLE_PET_PASS_EL            = 241,                     // Elemental - Weather Immune
    BATTLE_PET_PASS_BE            = 237,                     // Beast - Enrage
    BATTLE_PET_PASS_AQ            = 240,                     // Aquatic - Purity
	BATTLE_PET_PASS_ME            = 244,                     // Mechanical - Failsafe
};

enum BPET_BATTLE_EFFECTS
{
	BPET_INVALID                  = 00,
	BPET_ABILITY                  = 0,
	BPET_AURA_APPLY               = 1,
	BPET_AURA_REMOVE              = 2,
	BPET_AURA_TICK                = 3,
	BPET_AURA_PROC                = 4,
	BPET_PET_SWAP                 = 5,
	BPET_STATUS_CHANGE            = 6,
	BPET_PET_SET_STATE            = 7,
};

enum BPET_BATTLE_STATES
{
	BPET_INVALID                  = 00,
	BPET_CREATED                  = 0,
	BPET_WAITING                  = 1,
	BPET_IN_PROGRESS              = 2,
	BPET_WAITING_PLAYBACK         = 3,
	BPET_WAITING_PETS             = 4,
	BPET_FAILED                   = 5,
	BPET_FINAL_ROUND              = 6,
	BPET_FINISHED                 = 7,
};

enum BPET_RANGE_SPEED
{
    BPET_IDLE_RADIUS              = 1,
    BPET_RANGED_RADIUS            = 1,
    BPET_MELEE_RADIUS             = 1,
    BPET_FORWARD_SPEED            = 5,
    BPET_BACKWARD_SPEED           = 4,
};

enum BPET_TYPE
{
    BATTLE_PET_TYPE_HU            = 0,                       // Humanoid
    BATTLE_PET_TYPE_DR            = 1,                       // Dragon
    BATTLE_PET_TYPE_FL            = 2,                       // Flying
    BATTLE_PET_TYPE_UN            = 3,                       // Undead
    BATTLE_PET_TYPE_CR            = 4,                       // Critter
    BATTLE_PET_TYPE_MA            = 5,                       // Magical
    BATTLE_PET_TYPE_EL            = 6,                       // Elemental
    BATTLE_PET_TYPE_BE            = 7,                       // Beast
    BATTLE_PET_TYPE_AQ            = 8,                       // Aquatic
	BATTLE_PET_TYPE_ME            = 9,                       // Mechanical
    MAX_BPET_TYPE                 = 10
};

#define MAX_BPET_CARDS         4							 // AKA STABLES

// stored in character_bpet.slot
enum BPetSaveMode
{
    BPET_RELEASE                  = -1,                      // not saved in fact
    BPET_PUT_IN_CAGE              =  0,                      // in current slot (with player)
    BPET_FAVORITE                 =  1,
    BPET_UNFAVORITE               =  2,
    BPET_SAVE_NOT_IN_SLOT         =  100,
};

// There might be a lot more
enum BPetModeFlags
{
    BPET_MODE_UNKNOWN_0         = 0x0000001,
    BPET_MODE_UNKNOWN_2         = 0x0000100,
    BPET_MODE_DISABLE_ACTIONS   = 0x8000000,
};

enum BPetSpellState
{
    BPET_SPELL_UNCHANGED = 0,
    BPET_SPELL_CHANGED   = 1,
    BPET_SPELL_NEW       = 2,
    BPET_SPELL_REMOVED   = 3
};

enum BPetSpellType
{
    BPET_SPELL_NORMAL = 0,
    BPET_SPELL_FAMILY = 1,
};

struct BPetSpell
{
    uint8 active;                                           // use instead enum (not good use *uint8* limited enum in case when value in enum not possitive in *int8*)

    BPetSpellState state : 8;
    BPetSpellType type   : 8;
};

typedef UNORDERED_MAP<uint32, BPetSpell> BPetSpellMap;
typedef std::vector<uint32> AutoSpellList;

#define ACTIVE_SPELLS_MAX           4

#define BPET_FOLLOW_DIST  1.0f
#define BPET_FOLLOW_ANGLE (M_PI_F/2.0f)

class Player;

class BPet : public Creature
{
    public:
        explicit BPet(BPetType type = MAX_BPET_TYPE);
        virtual ~BPet();

        void AddToWorld();
        void RemoveFromWorld();

        BPetType getBPetType() const { return m_bpetType; }
        void setBPetType(BPetType type) { m_bpetType = type; }
        bool isControlled() const { return getBPetType()==SUMMON_PET}
        bool isTemporarySummoned() const { return m_duration > 0; }

		bool Create (uint32 guidlow, CreatureCreatePos& cPos, CreatureInfo const* cinfo, uint32 pet_number);
        bool CreateBaseAtCreature(Creature* creature);
        bool LoadBPetFromDB( Player* owner,uint32 bpetentry = 0,uint32 bpetnumber = 0, bool current = false );
        void SaveBPetToDB(PetSaveMode mode);
        void Unsummon(PetSaveMode mode, Unit* owner = NULL);
        static void DeleteFromDB(uint32 guidlow, bool separate_transaction = true);

        void SetDeathState(DeathState s);                   // overwrite virtual Creature::SetDeathState and Unit::SetDeathState
        void Update(uint32 update_diff, uint32 diff) override;  // overwrite virtual Creature::Update and Unit::Update

        uint8 GetBPetAutoSpellSize() const { return m_autospells.size(); }
        uint32 GetBPetAutoSpellOnPos(uint8 pos) const
        {
            if (pos >= m_autospells.size())
                return 0;
            else
                return m_autospells[pos];
        }

        void RegenerateAll(uint32 update_diff);             // overwrite Creature::RegenerateAll
        void GiveBPetLevel(uint32 level);
        void SynchronizeLevelWithOwner();
        bool InitStatsForLevel(uint32 level, Unit* owner = NULL);
        void SetDuration(int32 dur) { m_duration = dur; }

        int32 GetBonusDamage() { return m_bonusdamage; }
        void SetBonusDamage(int32 damage) { m_bonusdamage = damage; }

        bool UpdateStats(Stats stat);
        bool UpdateAllStats();
        void UpdateResistances(uint32 school);
        void UpdateArmor();
        void UpdateMaxHealth();
        void UpdateMaxPower(Powers power);
        void UpdateAttackPowerAndDamage(bool ranged = false);
        void UpdateDamagePhysical(WeaponAttackType attType);

        bool CanTakeMoreActiveSpells(uint32 SpellIconID);
        void ToggleAutocast(uint32 spellid, bool apply);

        void ApplyModeFlags(BPetModeFlags mode, bool apply);
        BPetModeFlags GetModeFlags() const { return m_bpetModeFlags; }

        bool HasSpell(uint32 spell) const;

        void LearnPetPassives();
        void CastBPetAuras(bool current);
        void CastBPetAura(BPetAura const* aura);

        void _LoadSpellCooldowns();
        void _SaveSpellCooldowns();
        void _LoadAuras(uint32 timediff);
        void _SaveAuras();
        void _LoadSpells();
        void _SaveSpells();

        bool addSpell(uint32 spell_id,ActiveStates active = ACT_DECIDE, PetSpellState state = PETSPELL_NEW, PetSpellType type = PETSPELL_NORMAL);
        bool learnSpell(uint32 spell_id);
        void learnSpellHighRank(uint32 spellid);
        void InitLevelupSpellsForLevel();
        bool unlearnSpell(uint32 spell_id, bool learn_prev, bool clear_ab = true);
        bool removeSpell(uint32 spell_id, bool learn_prev, bool clear_ab = true);
        void CleanupActionBar();

        BPetSpellMap     m_spells;
        AutoSpellList   m_autospells;

        void InitBPetCreateSpells();

        bool resetTalents(bool no_cost = false);
        static void resetTalentsForAllPetsOf(Player* owner, Pet* online_pet = NULL);
        uint32 resetTalentsCost() const;
        void InitTalentForLevel();

        uint8 GetMaxTalentPointsForLevel(uint32 level);
        uint8 GetFreeTalentPoints() { return GetByteValue(UNIT_FIELD_BYTES_1, 1); }
        void SetFreeTalentPoints(uint8 points) { SetByteValue(UNIT_FIELD_BYTES_1, 1, points); }
        void UpdateFreeTalentPoints(bool resetIfNeed = true);

        uint32  m_resetTalentsCost;
        time_t  m_resetTalentsTime;
        uint32  m_usedTalentCount;

        const uint64& GetAuraUpdateMask() const { return m_auraUpdateMask; }
        void SetAuraUpdateMask(uint8 slot) { m_auraUpdateMask |= (uint64(1) << slot); }
        void ResetAuraUpdateMask() { m_auraUpdateMask = 0; }

        // overwrite Creature function for name localization back to WorldObject version without localization
        const char* GetNameForLocaleIdx(int32 locale_idx) const { return WorldObject::GetNameForLocaleIdx(locale_idx); }

        bool    m_removed;                                  // prevent overwrite bpet state in DB at next Pet::Update if pet already removed(saved)
    protected:
        PetType m_bpetType;
        int32   m_duration;                                 // time until unsummon (used mostly for summoned guardians and not used for controlled pets)
        int32   m_bonusdamage;
        uint64  m_auraUpdateMask;
        bool    m_loading;

    private:
        BPetModeFlags m_bpetModeFlags;

        void SaveToDB(uint32, uint8, uint32)                // overwrited of Creature::SaveToDB     - don't must be called
        {
            STRAWBERRY_ASSERT(false);
        }
        void DeleteFromDB()                                 // overwrited of Creature::DeleteFromDB - don't must be called
        {
            STRAWBERRY_ASSERT(false);
        }
};
#endif
