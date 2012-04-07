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

#ifndef __BattleGroundTK_H
#define __BattleGroundTK_H

class BattleGround;

enum BG_TK_SPELLS
{
    BG_TK_PICKUP_POWERBALL_SPELL        = 112839,
	BG_TK_DROP_POWERBALL_SPELL          = 112839,
	BG_TK_HOLDING_POWERBALL_SPELL       = 112839,
};

enum BG_TK_NPC
{
    BG_SM_NPC_POWERBALL					= 29265,
};

class BattleGroundTKScore : public BattleGroundScore
{
    public:
        BattleGroundTKScore() {};
        virtual ~BattleGroundTKScore() {};
};

class BattleGroundTK : public BattleGround
{
    friend class BattleGroundMgr;

    public:
        BattleGroundTK();
        ~BattleGroundTK();
        void Update(uint32 diff);

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player *plr);
        virtual void StartingEventCloseDoors();
        virtual void StartingEventOpenDoors();

        void RemovePlayer(Player *plr, ObjectGuid guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        //bool SetupBattleGround();

        /* Scorekeeping */
        void UpdatePlayerScore(Player *Source, uint32 type, uint32 value);

    private:
};
#endif