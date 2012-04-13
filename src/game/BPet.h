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

enum BPetType
{
    BATTLE_PET_HU            = 0,                        // Humanoid
    BATTLE_PET_DR            = 1,                        // Dragonkin
    BATTLE_PET_FL            = 2,                        // Flying
    BATTLE_PET_UN            = 3,                        // Undead
    BATTLE_PET_CR            = 4,                        // Critter
    BATTLE_PET_MA            = 5,                        // Magic
    BATTLE_PET_EL            = 6,                        // Elemental
    BATTLE_PET_BE            = 7,                        // Beast
    BATTLE_PET_AQ            = 8,                        // Aquatic
	BATTLE_PET_ME            = 9,                        // Mechanical
    MAX_BPET_TYPE            = 10
};

#define MAX_BPET_STABLES         4

// stored in character_bpet.slot
enum BPetSaveMode
{
    BPET_RELEASE                = -1,                        // not saved in fact
    BPET_PUT_IN_CAGE            =  0,                        // in current slot (with player)
    BPET_FAVORITE               =  1,
    BPET_UNFAVORITE             =  2,
    BPET_SAVE_NOT_IN_SLOT       =  100,
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
    BPETSPELL_UNCHANGED = 0,
    BPETSPELL_CHANGED   = 1,
    BPETSPELL_NEW       = 2,
    BPETSPELL_REMOVED   = 3
};

enum BPetSpellType
{
    BPETSPELL_NORMAL = 0,
    BPETSPELL_FAMILY = 1,
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
