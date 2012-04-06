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

#ifndef __BattleGroundSM_H
#define __BattleGroundSM_H

class BattleGround;

enum BG_SM_SPELLS
{
    BG_SM_CART_START_SPELL              = 111827,
    BG_SM_CART_1_PLAYER_IN_RANGE_SPELL  = 115904,
	BG_SM_CART_2_PLAYER_IN_RANGE_SPELL  = 116488,
	BG_SM_CART_3_PLAYER_IN_RANGE_SPELL  = 116490,
	BG_SM_CART_4_PLAYER_IN_RANGE_SPELL  = 116491,
	BG_SM_CART_5_PLAYER_IN_RANGE_SPELL  = 116492,
	BG_SM_CART_CONTROL_SPELL            = 115815,
};

enum BG_SM_NPC
{
    BG_SM_NPC_CART_A					= 39329,
	BG_SM_NPC_CART_H    				= 46485,
};

enum BG_SM_CHECKPOINTS
{
    BG_SM_CHECKPOINT_A1					= 5,
	BG_SM_CHECKPOINT_H1    				= 5,
	BG_SM_CHECKPOINT_A2					= 10,
	BG_SM_CHECKPOINT_H2    				= 10,
	BG_SM_CHECKPOINT_A3					= 20,
	BG_SM_CHECKPOINT_H3    				= 20,
	BG_SM_CHECKPOINT_A4					= 30,
	BG_SM_CHECKPOINT_H4    				= 30,
	BG_SM_CHECKPOINT_A5					= 40,
	BG_SM_CHECKPOINT_H5    				= 40,
	BG_SM_CHECKPOINT_HWIN				= 50,
	BG_SM_CHECKPOINT_AWIN  				= 50,
};

// id, x, y, z, o
const float BG_SM_H_WAYPOINTS[50][5] = {          //Waypoints for H Mine Cart
    {1, 1185.71f, 1185.24f, -56.36f, 2.56f},      // 1
    {2, 990.75f, 1008.18f, -42.60f, 2.43f},       // 2
    {3, 817.66f, 843.34f, -56.54f, 3.01f},        // 3
    {4, 807.46f, 1189.16f, 11.92f, 5.44f},        // 4
    {5, 1146.62f, 816.94f, -98.49f, 6.14f},       // 5
	//upto 50 waypoints for escorting travel
};

// id, x, y, z, o
const float BG_SM_A_WAYPOINTS[50][5] = {          //Waypoints for A Mine Cart
    {1, 1185.71f, 1185.24f, -56.36f, 2.56f},      // 1
    {2, 990.75f, 1008.18f, -42.60f, 2.43f},       // 2
    {3, 817.66f, 843.34f, -56.54f, 3.01f},        // 3
    {4, 807.46f, 1189.16f, 11.92f, 5.44f},        // 4
    {5, 1146.62f, 816.94f, -98.49f, 6.14f},       // 5
	//upto 50 waypoints for escorting travel
};

class BattleGroundSMScore : public BattleGroundScore
{
    public:
        BattleGroundSMScore() {};
        virtual ~BattleGroundSMScore() {};
};

class BattleGroundSM : public BattleGround
{
    friend class BattleGroundMgr;

    public:
        BattleGroundSM();
        ~BattleGroundSM();
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