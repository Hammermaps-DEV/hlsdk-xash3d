/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/
#ifndef WEAPONS_H
#define WEAPONS_H

#include "effects.h"

class CBasePlayer;
extern int gmsgWeapPickup;

void DeactivateSatchels( CBasePlayer *pOwner );

// Contact Grenade / Timed grenade / Satchel Charge
class CGrenade : public CBaseMonster
{
public:
	void Spawn( void );

	typedef enum { SATCHEL_DETONATE = 0, SATCHEL_RELEASE } SATCHELCODE;

	static CGrenade *ShootTimed( entvars_t *pevOwner, Vector vecStart, Vector vecVelocity, float time );
	static CGrenade *ShootContact( entvars_t *pevOwner, Vector vecStart, Vector vecVelocity );
	static CGrenade *ShootSatchelCharge( entvars_t *pevOwner, Vector vecStart, Vector vecVelocity );
	static void UseSatchelCharges( entvars_t *pevOwner, SATCHELCODE code );

	void Explode( Vector vecSrc, Vector vecAim );
	void Explode( TraceResult *pTrace, int bitsDamageType );
	void EXPORT Smoke( void );

	void EXPORT BounceTouch( CBaseEntity *pOther );
	void EXPORT SlideTouch( CBaseEntity *pOther );
	void EXPORT ExplodeTouch( CBaseEntity *pOther );
	void EXPORT DangerSoundThink( void );
	void EXPORT PreDetonate( void );
	void EXPORT Detonate( void );
	void EXPORT DetonateUse( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	void EXPORT TumbleThink( void );

	virtual void BounceSound( void );
	virtual int	BloodColor( void ) { return DONT_BLEED; }
	virtual void Killed( entvars_t *pevAttacker, int iGib );

	BOOL m_fRegisteredSound;// whether or not this grenade has issued its DANGER sound to the world sound list yet.
};

// constant items
#define ITEM_HEALTHKIT		1
#define ITEM_ANTIDOTE		2
#define ITEM_SECURITY		3
#define ITEM_BATTERY		4

#define WEAPON_NONE				0
#define WEAPON_CROWBAR			1
#define	WEAPON_GLOCK			2
#define WEAPON_PYTHON			3
#define WEAPON_MP5				4
#define WEAPON_CHAINGUN			5
#define WEAPON_CROSSBOW			6
#define WEAPON_SHOTGUN			7
#define WEAPON_RPG				8
#define WEAPON_GAUSS			9
#define WEAPON_EGON				10
#define WEAPON_HORNETGUN		11
#define WEAPON_HANDGRENADE		12
#define WEAPON_TRIPMINE			13
#define	WEAPON_SATCHEL			14
#define	WEAPON_SNARK			15
#define WEAPON_DISPLACER		16
#define WEAPON_EAGLE			17
#define WEAPON_GRAPPLE			18
#define WEAPON_KNIFE			19
#define	WEAPON_M249			20
#define	WEAPON_PENGUIN			21
#define WEAPON_PIPEWRENCH		22
#define WEAPON_SHOCKRIFLE		23
#define WEAPON_SNIPERRIFLE		24
#define WEAPON_SPORELAUNCHER		25

#define WEAPON_ALLWEAPONS		(~(1<<WEAPON_SUIT))

#define WEAPON_SUIT				31	// ?????

#define MAX_WEAPONS			32

#define MAX_NORMAL_BATTERY	100

// weapon weight factors (for auto-switching)   (-1 = noswitch)
#define CROWBAR_WEIGHT		0
#define GLOCK_WEIGHT		10
#define PYTHON_WEIGHT		15
#define MP5_WEIGHT			15
#define SHOTGUN_WEIGHT		15
#define CROSSBOW_WEIGHT		10
#define RPG_WEIGHT			20
#define GAUSS_WEIGHT		20
#define EGON_WEIGHT			20
#define HORNETGUN_WEIGHT	10
#define HANDGRENADE_WEIGHT	5
#define SNARK_WEIGHT		5
#define SATCHEL_WEIGHT		-10
#define TRIPMINE_WEIGHT		-10
#define DISPLACER_WEIGHT		20
#define EAGLE_WEIGHT			15
#define GRAPPLE_WEIGHT			0
#define KNIFE_WEIGHT			0
#define M249_WEIGHT			15
#define PENGUIN_WEIGHT			5
#define PIPEWRENCH_WEIGHT		0
#define SHOCKRIFLE_WEIGHT		10
#define SNIPERRIFLE_WEIGHT		10
#define SPORELAUNCHER_WEIGHT		10

// weapon clip/carry ammo capacities
#define URANIUM_MAX_CARRY		100
#define	_9MM_MAX_CARRY			250
#define _357_MAX_CARRY			36
#define BUCKSHOT_MAX_CARRY		125
#define BOLT_MAX_CARRY			50
#define ROCKET_MAX_CARRY		5
#define HANDGRENADE_MAX_CARRY	10
#define SATCHEL_MAX_CARRY		5
#define TRIPMINE_MAX_CARRY		5
#define SNARK_MAX_CARRY			15
#define HORNET_MAX_CARRY		8
#define M203_GRENADE_MAX_CARRY	10
#define	_556_MAX_CARRY			200
#define _762_MAX_CARRY			15
#define PENGUIN_MAX_CARRY		9
#define SHOCK_MAX_CARRY			10
#define SPORE_MAX_CARRY			20

// the maximum amount of ammo each weapon's clip can hold
#define WEAPON_NOCLIP			-1

//#define CROWBAR_MAX_CLIP		WEAPON_NOCLIP
#define GLOCK_MAX_CLIP			17
#define PYTHON_MAX_CLIP			6
#define MP5_MAX_CLIP			50
#define MP5_DEFAULT_AMMO		25
#define SHOTGUN_MAX_CLIP		8
#define CROSSBOW_MAX_CLIP		5
#define RPG_MAX_CLIP			1
#define GAUSS_MAX_CLIP			WEAPON_NOCLIP
#define EGON_MAX_CLIP			WEAPON_NOCLIP
#define HORNETGUN_MAX_CLIP		WEAPON_NOCLIP
#define HANDGRENADE_MAX_CLIP	WEAPON_NOCLIP
#define SATCHEL_MAX_CLIP		WEAPON_NOCLIP
#define TRIPMINE_MAX_CLIP		WEAPON_NOCLIP
#define SNARK_MAX_CLIP			WEAPON_NOCLIP
#define EAGLE_MAX_CLIP			7
#define M249_MAX_CLIP			50
#define PENGUIN_MAX_CLIP		WEAPON_NOCLIP
#define SHOCKRIFLE_MAX_CLIP		10
#define SNIPERRIFLE_MAX_CLIP		5
#define SPORELAUNCHER_MAX_CLIP		5

// the default amount of ammo that comes with each gun when it spawns
#define GLOCK_DEFAULT_GIVE			17
#define PYTHON_DEFAULT_GIVE			6
#define MP5_DEFAULT_GIVE			25
#define MP5_DEFAULT_AMMO			25
#define MP5_M203_DEFAULT_GIVE		0
#define SHOTGUN_DEFAULT_GIVE		12
#define CROSSBOW_DEFAULT_GIVE		5
#define RPG_DEFAULT_GIVE			1
#define GAUSS_DEFAULT_GIVE			20
#define EGON_DEFAULT_GIVE			20
#define HANDGRENADE_DEFAULT_GIVE	5
#define SATCHEL_DEFAULT_GIVE		1
#define TRIPMINE_DEFAULT_GIVE		1
#define SNARK_DEFAULT_GIVE			5
#define HIVEHAND_DEFAULT_GIVE		8
#define EAGLE_DEFAULT_GIVE			7
#define M249_DEFAULT_GIVE			50
#define PENGUIN_DEFAULT_GIVE			3
#define SHOCKRIFLE_DEFAULT_GIVE			10
#define SNIPERRIFLE_DEFAULT_GIVE		5
#define SPORELAUNCHER_DEFAULT_GIVE		5

// The amount of ammo given to a player by an ammo item.
#define AMMO_URANIUMBOX_GIVE	20
#define AMMO_GLOCKCLIP_GIVE		GLOCK_MAX_CLIP
#define AMMO_357BOX_GIVE		PYTHON_MAX_CLIP
#define AMMO_MP5CLIP_GIVE		MP5_MAX_CLIP
#define AMMO_CHAINBOX_GIVE		200
#define AMMO_M203BOX_GIVE		2
#define AMMO_BUCKSHOTBOX_GIVE	12
#define AMMO_CROSSBOWCLIP_GIVE	CROSSBOW_MAX_CLIP
#define AMMO_RPGCLIP_GIVE		RPG_MAX_CLIP
#define AMMO_URANIUMBOX_GIVE	20
#define AMMO_SNARKBOX_GIVE		5
#define AMMO_556CLIP_GIVE		50
#define AMMO_762BOX_GIVE		5
#define AMMO_PENGUINBOX_GIVE		3
#define AMMO_SPORE_GIVE			1

// bullet types
typedef	enum
{
	BULLET_NONE = 0,
	BULLET_PLAYER_9MM, // glock
	BULLET_PLAYER_MP5, // mp5
	BULLET_PLAYER_357, // python
	BULLET_PLAYER_BUCKSHOT, // shotgun
	BULLET_PLAYER_CROWBAR, // crowbar swipe
	BULLET_PLAYER_556, // m249 
	BULLET_PLAYER_762, // sniperrifle
	BULLET_MONSTER_9MM,
	BULLET_MONSTER_MP5,
	BULLET_MONSTER_12MM,
	BULLET_MONSTER_357,
	BULLET_MONSTER_556, // m249 
	BULLET_MONSTER_762 // sniperrifle
} Bullet;

#define ITEM_FLAG_SELECTONEMPTY		1
#define ITEM_FLAG_NOAUTORELOAD		2
#define ITEM_FLAG_NOAUTOSWITCHEMPTY	4
#define ITEM_FLAG_LIMITINWORLD		8
#define ITEM_FLAG_EXHAUSTIBLE		16 // A player can totally exhaust their ammo supply and lose this weapon

#define WEAPON_IS_ONTARGET 0x40

typedef struct
{
	int		iSlot;
	int		iPosition;
	const char	*pszAmmo1;	// ammo 1 type
	int		iMaxAmmo1;		// max ammo 1
	const char	*pszAmmo2;	// ammo 2 type
	int		iMaxAmmo2;		// max ammo 2
	const char	*pszName;
	int		iMaxClip;
	int		iId;
	int		iFlags;
	int		iWeight;// this value used to determine this weapon's importance in autoselection.
} ItemInfo;

typedef struct
{
	const char *pszName;
	int iId;
} AmmoInfo;

// Items that the player has in their inventory that they can use
class CBasePlayerItem : public CBaseAnimating
{
public:
	virtual void SetObjectCollisionBox( void );

	virtual int		Save( CSave &save );
	virtual int		Restore( CRestore &restore );

	static	TYPEDESCRIPTION m_SaveData[];

	virtual int AddToPlayer( CBasePlayer *pPlayer );	// return TRUE if the item you want the item added to the player inventory
	virtual int AddDuplicate( CBasePlayerItem *pItem ) { return FALSE; }	// return TRUE if you want your duplicate removed from world
	void EXPORT DestroyItem( void );
	void EXPORT DefaultTouch( CBaseEntity *pOther );	// default weapon touch
	void EXPORT FallThink ( void );// when an item is first spawned, this think is run to determine when the object has hit the ground.
	void EXPORT Materialize( void );// make a weapon visible and tangible
	void EXPORT AttemptToMaterialize( void );  // the weapon desires to become visible and tangible, if the game rules allow for it
	CBaseEntity* Respawn ( void );// copy a weapon
	void FallInit( void );
	void CheckRespawn( void );
	virtual int GetItemInfo(ItemInfo *p) { return 0; };	// returns 0 if struct not filled out
	virtual BOOL CanDeploy( void ) { return TRUE; };
	virtual BOOL Deploy( )								// returns is deploy was successful
		 { return TRUE; };

	virtual BOOL CanHolster( void ) { return TRUE; };// can this weapon be put away right now?
	virtual void Holster( int skiplocal = 0 );
	virtual void UpdateItemInfo( void ) { return; };

	virtual void ItemPreFrame( void )	{ return; }		// called each frame by the player PreThink
	virtual void ItemPostFrame( void ) { return; }		// called each frame by the player PostThink

	virtual void Drop( void );
	virtual void Kill( void );
	virtual void AttachToPlayer ( CBasePlayer *pPlayer );

	virtual int PrimaryAmmoIndex() { return -1; };
	virtual int SecondaryAmmoIndex() { return -1; };

	virtual int UpdateClientData( CBasePlayer *pPlayer ) { return 0; }

	virtual CBasePlayerItem *GetWeaponPtr( void ) { return NULL; };

	static ItemInfo ItemInfoArray[ MAX_WEAPONS ];
	static AmmoInfo AmmoInfoArray[ MAX_AMMO_SLOTS ];

	CBasePlayer	*m_pPlayer;
	CBasePlayerItem *m_pNext;
	int		m_iId;												// WEAPON_???

	virtual int iItemSlot( void ) { return 0; }			// return 0 to MAX_ITEMS_SLOTS, used in hud

	int			iItemPosition( void ) { return ItemInfoArray[ m_iId ].iPosition; }
	const char	*pszAmmo1( void )	{ return ItemInfoArray[ m_iId ].pszAmmo1; }
	int			iMaxAmmo1( void )	{ return ItemInfoArray[ m_iId ].iMaxAmmo1; }
	const char	*pszAmmo2( void )	{ return ItemInfoArray[ m_iId ].pszAmmo2; }
	int			iMaxAmmo2( void )	{ return ItemInfoArray[ m_iId ].iMaxAmmo2; }
	const char	*pszName( void )	{ return ItemInfoArray[ m_iId ].pszName; }
	int			iMaxClip( void )	{ return ItemInfoArray[ m_iId ].iMaxClip; }
	int			iWeight( void )		{ return ItemInfoArray[ m_iId ].iWeight; }
	int			iFlags( void )		{ return ItemInfoArray[ m_iId ].iFlags; }

	// int		m_iIdPrimary;										// Unique Id for primary ammo
	// int		m_iIdSecondary;										// Unique Id for secondary ammo
};

// inventory items that 
class CBasePlayerWeapon : public CBasePlayerItem
{
public:
	virtual int		Save( CSave &save );
	virtual int		Restore( CRestore &restore );

	static	TYPEDESCRIPTION m_SaveData[];

	// generic weapon versions of CBasePlayerItem calls
	virtual int AddToPlayer( CBasePlayer *pPlayer );
	virtual int AddDuplicate( CBasePlayerItem *pItem );

	virtual int ExtractAmmo( CBasePlayerWeapon *pWeapon ); //{ return TRUE; };			// Return TRUE if you can add ammo to yourself when picked up
	virtual int ExtractClipAmmo( CBasePlayerWeapon *pWeapon );// { return TRUE; };			// Return TRUE if you can add ammo to yourself when picked up

	virtual int AddWeapon( void ) { ExtractAmmo( this ); return TRUE; };	// Return TRUE if you want to add yourself to the player

	// generic "shared" ammo handlers
	BOOL AddPrimaryAmmo( int iCount, char *szName, int iMaxClip, int iMaxCarry );
	BOOL AddSecondaryAmmo( int iCount, char *szName, int iMaxCarry );

	virtual void UpdateItemInfo( void ) {};	// updates HUD state

	int m_iPlayEmptySound;
	int m_fFireOnEmpty;		// True when the gun is empty and the player is still holding down the
							// attack key(s)
	virtual BOOL PlayEmptySound( void );
	virtual void ResetEmptySound( void );

	virtual void SendWeaponAnim( int iAnim, int skiplocal = 1, int body = 0 );  // skiplocal is 1 if client is predicting weapon animations

	virtual BOOL CanDeploy( void );
	virtual BOOL IsUseable( void );
	BOOL DefaultDeploy( char *szViewModel, char *szWeaponModel, int iAnim, char *szAnimExt, int skiplocal = 0, int body = 0 );
	int DefaultReload( int iClipSize, int iAnim, float fDelay, int body = 0 );

	virtual void ItemPostFrame( void );	// called each frame by the player PostThink
	// called by CBasePlayerWeapons ItemPostFrame()
	virtual void PrimaryAttack( void ) { return; }				// do "+ATTACK"
	virtual void SecondaryAttack( void ) { return; }			// do "+ATTACK2"
	virtual void Reload( void ) { return; }						// do "+RELOAD"
	virtual void WeaponIdle( void ) { return; }					// called when no buttons pressed
	virtual int UpdateClientData( CBasePlayer *pPlayer );		// sends hud info to client dll, if things have changed
	virtual void RetireWeapon( void );
	virtual BOOL ShouldWeaponIdle( void ) {return FALSE; };
	virtual void Holster( int skiplocal = 0 );
	virtual BOOL UseDecrement( void ) { return FALSE; };

	int	PrimaryAmmoIndex(); 
	int	SecondaryAmmoIndex(); 

	void PrintState( void );

	virtual CBasePlayerItem *GetWeaponPtr( void ) { return (CBasePlayerItem *)this; };
	float GetNextAttackDelay( float delay );

	float m_flPumpTime;
	int		m_fInSpecialReload;									// Are we in the middle of a reload for the shotguns
	float	m_flNextPrimaryAttack;								// soonest time ItemPostFrame will call PrimaryAttack
	float	m_flNextSecondaryAttack;							// soonest time ItemPostFrame will call SecondaryAttack
	float	m_flTimeWeaponIdle;									// soonest time ItemPostFrame will call WeaponIdle
	int		m_iPrimaryAmmoType;									// "primary" ammo index into players m_rgAmmo[]
	int		m_iSecondaryAmmoType;								// "secondary" ammo index into players m_rgAmmo[]
	int		m_iClip;											// number of shots left in the primary weapon clip, -1 it not used
	int		m_iClientClip;										// the last version of m_iClip sent to hud dll
	int		m_iClientWeaponState;								// the last version of the weapon state sent to hud dll (is current weapon, is on target)
	int		m_fInReload;										// Are we in the middle of a reload;

	int		m_iDefaultAmmo;// how much ammo you get when you pick up this weapon as placed by a level designer.

	// hle time creep vars
	float m_flPrevPrimaryAttack;
	float m_flLastFireTime;
};

class CBasePlayerAmmo : public CBaseEntity
{
public:
	virtual void Spawn( void );
	void EXPORT DefaultTouch( CBaseEntity *pOther ); // default weapon touch
	virtual BOOL AddAmmo( CBaseEntity *pOther ) { return TRUE; };

	CBaseEntity* Respawn( void );
	void EXPORT Materialize( void );
};

extern DLL_GLOBAL	short	g_sModelIndexLaser;// holds the index for the laser beam
extern DLL_GLOBAL	const char *g_pModelNameLaser;

extern DLL_GLOBAL	short	g_sModelIndexLaserDot;// holds the index for the laser beam dot
extern DLL_GLOBAL	short	g_sModelIndexFireball;// holds the index for the fireball
extern DLL_GLOBAL	short	g_sModelIndexSmoke;// holds the index for the smoke cloud
extern DLL_GLOBAL	short	g_sModelIndexWExplosion;// holds the index for the underwater explosion
extern DLL_GLOBAL	short	g_sModelIndexBubbles;// holds the index for the bubbles model
extern DLL_GLOBAL	short	g_sModelIndexBloodDrop;// holds the sprite index for blood drops
extern DLL_GLOBAL	short	g_sModelIndexBloodSpray;// holds the sprite index for blood spray (bigger)

extern DLL_GLOBAL	short	g_sModelIndexSpore1;
extern DLL_GLOBAL	short	g_sModelIndexSpore2;
extern DLL_GLOBAL	short	g_sModelIndexSpore3;

extern DLL_GLOBAL  	short	g_sModelIndexBigSpit;
extern DLL_GLOBAL  	short	g_sModelIndexTinySpit;

extern void ClearMultiDamage(void);
extern void ApplyMultiDamage(entvars_t* pevInflictor, entvars_t* pevAttacker );
extern void AddMultiDamage( entvars_t *pevInflictor, CBaseEntity *pEntity, float flDamage, int bitsDamageType);

extern void DecalGunshot( TraceResult *pTrace, int iBulletType );
extern void SpawnBlood(Vector vecSpot, int bloodColor, float flDamage);
extern int DamageDecal( CBaseEntity *pEntity, int bitsDamageType );
extern void RadiusDamage( Vector vecSrc, entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, float flRadius, int iClassIgnore, int bitsDamageType );

typedef struct 
{
	CBaseEntity		*pEntity;
	float			amount;
	int				type;
} MULTIDAMAGE;

extern MULTIDAMAGE gMultiDamage;

#define LOUD_GUN_VOLUME			1000
#define NORMAL_GUN_VOLUME		600
#define QUIET_GUN_VOLUME		200

#define	BRIGHT_GUN_FLASH		512
#define NORMAL_GUN_FLASH		256
#define	DIM_GUN_FLASH			128

#define BIG_EXPLOSION_VOLUME	2048
#define NORMAL_EXPLOSION_VOLUME	1024
#define SMALL_EXPLOSION_VOLUME	512

#define	WEAPON_ACTIVITY_VOLUME	64

#define VECTOR_CONE_1DEGREES	Vector( 0.00873, 0.00873, 0.00873 )
#define VECTOR_CONE_2DEGREES	Vector( 0.01745, 0.01745, 0.01745 )
#define VECTOR_CONE_3DEGREES	Vector( 0.02618, 0.02618, 0.02618 )
#define VECTOR_CONE_4DEGREES	Vector( 0.03490, 0.03490, 0.03490 )
#define VECTOR_CONE_5DEGREES	Vector( 0.04362, 0.04362, 0.04362 )
#define VECTOR_CONE_6DEGREES	Vector( 0.05234, 0.05234, 0.05234 )
#define VECTOR_CONE_7DEGREES	Vector( 0.06105, 0.06105, 0.06105 )
#define VECTOR_CONE_8DEGREES	Vector( 0.06976, 0.06976, 0.06976 )
#define VECTOR_CONE_9DEGREES	Vector( 0.07846, 0.07846, 0.07846 )
#define VECTOR_CONE_10DEGREES	Vector( 0.08716, 0.08716, 0.08716 )
#define VECTOR_CONE_15DEGREES	Vector( 0.13053, 0.13053, 0.13053 )
#define VECTOR_CONE_20DEGREES	Vector( 0.17365, 0.17365, 0.17365 )

//=========================================================
// CWeaponBox - a single entity that can store weapons
// and ammo. 
//=========================================================
class CWeaponBox : public CBaseEntity
{
	void Precache( void );
	void Spawn( void );
	void Touch( CBaseEntity *pOther );
	void KeyValue( KeyValueData *pkvd );
	BOOL IsEmpty( void );
	int  GiveAmmo( int iCount, char *szName, int iMax, int *pIndex = NULL );
	void SetObjectCollisionBox( void );

public:
	void EXPORT Kill ( void );
	int		Save( CSave &save );
	int		Restore( CRestore &restore );
	static	TYPEDESCRIPTION m_SaveData[];

	BOOL HasWeapon( CBasePlayerItem *pCheckItem );
	BOOL PackWeapon( CBasePlayerItem *pWeapon );
	BOOL PackAmmo( int iszName, int iCount );

	CBasePlayerItem	*m_rgpPlayerItems[MAX_ITEM_TYPES];// one slot for each 

	int m_rgiszAmmo[MAX_AMMO_SLOTS];// ammo names
	int	m_rgAmmo[MAX_AMMO_SLOTS];// ammo quantities

	int m_cAmmoTypes;// how many ammo types packed into this box (if packed by a level designer)
};

#ifdef CLIENT_DLL
bool bIsMultiplayer ( void );
void LoadVModel ( char *szViewModel, CBasePlayer *m_pPlayer );
#endif

class CGlock : public CBasePlayerWeapon
{
public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 2; }
	int GetItemInfo(ItemInfo *p);

	void PrimaryAttack( void );
	void SecondaryAttack( void );
	void GlockFire( float flSpread, float flCycleTime, BOOL fUseAutoAim );
	BOOL Deploy( void );
	void Reload( void );
	void WeaponIdle( void );

	virtual BOOL UseDecrement( void )
	{ 
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

private:
	int m_iShell;

	unsigned short m_usFireGlock1;
	unsigned short m_usFireGlock2;
};

class CCrowbar : public CBasePlayerWeapon
{
public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 1; }
	void EXPORT SwingAgain( void );
	void EXPORT Smack( void );
	int GetItemInfo(ItemInfo *p);

	void PrimaryAttack( void );
	int Swing( int fFirst );
	BOOL Deploy( void );
	void Holster( int skiplocal = 0 );
	int m_iSwing;
	TraceResult m_trHit;

	virtual BOOL UseDecrement( void )
	{ 
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}
private:
	unsigned short m_usCrowbar;
};

class CPython : public CBasePlayerWeapon
{
public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 2; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer( CBasePlayer *pPlayer );
	void PrimaryAttack( void );
	void SecondaryAttack( void );
	BOOL Deploy( void );
	void Holster( int skiplocal = 0 );
	void Reload( void );
	void WeaponIdle( void );
	float m_flSoundDelay;

	BOOL m_fInZoom;// don't save this. 

	virtual BOOL UseDecrement( void )
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

private:
	unsigned short m_usFirePython;
};

class CMP5 : public CBasePlayerWeapon
{
public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 3; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer( CBasePlayer *pPlayer );

	void PrimaryAttack( void );
	void SecondaryAttack( void );
	int SecondaryAmmoIndex( void );
	BOOL Deploy( void );
	void Reload( void );
	void WeaponIdle( void );
	float m_flNextAnimTime;
	int m_iShell;

	virtual BOOL UseDecrement( void )
	{ 
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

private:
	unsigned short m_usMP5;
	unsigned short m_usMP52;
};

class CCrossbow : public CBasePlayerWeapon
{
public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( ) { return 3; }
	int GetItemInfo(ItemInfo *p);

	void FireBolt( void );
	void FireSniperBolt( void );
	void PrimaryAttack( void );
	void SecondaryAttack( void );
	int AddToPlayer( CBasePlayer *pPlayer );
	BOOL Deploy( );
	void Holster( int skiplocal = 0 );
	void Reload( void );
	void WeaponIdle( void );

	int m_fInZoom; // don't save this

	virtual BOOL UseDecrement( void )
	{ 
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

private:
	unsigned short m_usCrossbow;
	unsigned short m_usCrossbow2;
};

class CShotgun : public CBasePlayerWeapon
{
public:
#ifndef CLIENT_DLL
	int		Save( CSave &save );
	int		Restore( CRestore &restore );
	static	TYPEDESCRIPTION m_SaveData[];
#endif
	void Spawn( void );
	void Precache( void );
	int iItemSlot( ) { return 3; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer( CBasePlayer *pPlayer );

	void PrimaryAttack( void );
	void SecondaryAttack( void );
	BOOL Deploy( );
	void Reload( void );
	void WeaponIdle( void );
	int m_fInReload;
	float m_flNextReload;
	int m_iShell;

	virtual BOOL UseDecrement( void )
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

private:
	unsigned short m_usDoubleFire;
	unsigned short m_usSingleFire;
};

class CLaserSpot : public CBaseEntity
{
	void Spawn( void );
	void Precache( void );

	int	ObjectCaps( void ) { return FCAP_DONT_SAVE; }

public:
	void Suspend( float flSuspendTime );
	void EXPORT Revive( void );

	static CLaserSpot *CreateSpot( void );
};

class CRpg : public CBasePlayerWeapon
{
public:
#ifndef CLIENT_DLL
	int		Save( CSave &save );
	int		Restore( CRestore &restore );
	static	TYPEDESCRIPTION m_SaveData[];
#endif
	void Spawn( void );
	void Precache( void );
	void Reload( void );
	int iItemSlot( void ) { return 4; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer( CBasePlayer *pPlayer );

	BOOL Deploy( void );
	BOOL CanHolster( void );
	void Holster( int skiplocal = 0 );

	void PrimaryAttack( void );
	void SecondaryAttack( void );
	void WeaponIdle( void );

	void UpdateSpot( void );
	BOOL ShouldWeaponIdle( void ) { return TRUE; };

	CLaserSpot *m_pSpot;
	int m_fSpotActive;
	int m_cActiveRockets;// how many missiles in flight from this launcher right now?

	virtual BOOL UseDecrement( void )
	{ 
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

private:
	unsigned short m_usRpg;
};

class CRpgRocket : public CGrenade
{
public:
	int		Save( CSave &save );
	int		Restore( CRestore &restore );
	static	TYPEDESCRIPTION m_SaveData[];
	void Spawn( void );
	void Precache( void );
	void EXPORT FollowThink( void );
	void EXPORT IgniteThink( void );
	void EXPORT RocketTouch( CBaseEntity *pOther );
	static CRpgRocket *CreateRpgRocket( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CRpg *pLauncher );

	int m_iTrail;
	float m_flIgniteTime;
	CRpg *m_pLauncher;// pointer back to the launcher that fired me. 
};

class CGauss : public CBasePlayerWeapon
{
public:
#ifndef CLIENT_DLL
	int		Save( CSave &save );
	int		Restore( CRestore &restore );
	static	TYPEDESCRIPTION m_SaveData[];
#endif
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 4; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer( CBasePlayer *pPlayer );

	BOOL Deploy( void );
	void Holster( int skiplocal = 0  );

	void PrimaryAttack( void );
	void SecondaryAttack( void );
	void WeaponIdle( void );

	void StartFire( void );
	void Fire( Vector vecOrigSrc, Vector vecDirShooting, float flDamage );
	float GetFullChargeTime( void );
	int m_iBalls;
	int m_iGlow;
	int m_iBeam;
	int m_iSoundState; // don't save this

	// was this weapon just fired primary or secondary?
	// we need to know so we can pick the right set of effects. 
	BOOL m_fPrimaryFire;

	virtual BOOL UseDecrement( void )
	{ 
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

private:
	unsigned short m_usGaussFire;
	unsigned short m_usGaussSpin;
};

class CEgon : public CBasePlayerWeapon
{
public:
#ifndef CLIENT_DLL
	int		Save( CSave &save );
	int		Restore( CRestore &restore );
	static	TYPEDESCRIPTION m_SaveData[];
#endif
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 4; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer( CBasePlayer *pPlayer );

	BOOL Deploy( void );
	void Holster( int skiplocal = 0 );

	void UpdateEffect( const Vector &startPoint, const Vector &endPoint, float timeBlend );

	void CreateEffect ( void );
	void DestroyEffect ( void );

	void EndAttack( void );
	void Attack( void );
	void PrimaryAttack( void );
	void WeaponIdle( void );

	float m_flAmmoUseTime;// since we use < 1 point of ammo per update, we subtract ammo on a timer.

	float GetPulseInterval( void );
	float GetDischargeInterval( void );

	void Fire( const Vector &vecOrigSrc, const Vector &vecDir );

	BOOL HasAmmo( void );

	void UseAmmo( int count );

	enum EGON_FIREMODE { FIRE_NARROW, FIRE_WIDE};

	CBeam				*m_pBeam;
	CBeam				*m_pNoise;
	CSprite				*m_pSprite;

	virtual BOOL UseDecrement( void )
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

	unsigned short m_usEgonStop;

private:
	float				m_shootTime;
	EGON_FIREMODE		m_fireMode;
	float				m_shakeTime;
	BOOL				m_deployed;

	unsigned short m_usEgonFire;
};

class CHgun : public CBasePlayerWeapon
{
public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 4; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer( CBasePlayer *pPlayer );

	void PrimaryAttack( void );
	void SecondaryAttack( void );
	BOOL Deploy( void );
	BOOL IsUseable( void );
	void Holster( int skiplocal = 0 );
	void Reload( void );
	void WeaponIdle( void );
	float m_flNextAnimTime;

	float m_flRechargeTime;

	int m_iFirePhase;// don't save me.

	virtual BOOL UseDecrement( void )
	{ 
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}
private:
	unsigned short m_usHornetFire;
};

class CHandGrenade : public CBasePlayerWeapon
{
public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 5; }
	int GetItemInfo(ItemInfo *p);

	void PrimaryAttack( void );
	BOOL Deploy( void );
	BOOL CanHolster( void );
	void Holster( int skiplocal = 0 );
	void WeaponIdle( void );

	virtual BOOL UseDecrement( void )
	{ 
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}
};

class CSatchel : public CBasePlayerWeapon
{
public:
#ifndef CLIENT_DLL
	int		Save( CSave &save );
	int		Restore( CRestore &restore );
	static	TYPEDESCRIPTION m_SaveData[];
#endif
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 5; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer( CBasePlayer *pPlayer );
	void PrimaryAttack( void );
	void SecondaryAttack( void );
	int AddDuplicate( CBasePlayerItem *pOriginal );
	BOOL CanDeploy( void );
	BOOL Deploy( void );
	BOOL IsUseable( void );

	void Holster( int skiplocal = 0 );
	void WeaponIdle( void );
	void Throw( void );

	virtual BOOL UseDecrement( void )
	{ 
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}
};

class CTripmine : public CBasePlayerWeapon
{
public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 5; }
	int GetItemInfo(ItemInfo *p);
	void SetObjectCollisionBox( void )
	{
		//!!!BUGBUG - fix the model!
		pev->absmin = pev->origin + Vector(-16, -16, -5);
		pev->absmax = pev->origin + Vector(16, 16, 28); 
	}

	void PrimaryAttack( void );
	BOOL Deploy( void );
	void Holster( int skiplocal = 0 );
	void WeaponIdle( void );

	virtual BOOL UseDecrement( void )
	{ 
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

private:
	unsigned short m_usTripFire;
};

class CSqueak : public CBasePlayerWeapon
{
public:
	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 5; }
	int GetItemInfo(ItemInfo *p);

	void PrimaryAttack( void );
	void SecondaryAttack( void );
	BOOL Deploy( void );
	void Holster( int skiplocal = 0 );
	void WeaponIdle( void );
	int m_fJustThrown;

	virtual BOOL UseDecrement( void )
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

private:
	unsigned short m_usSnarkFire;
};

//
//
//
class CDisplacer : public CBasePlayerWeapon
{
public:

#ifndef CLIENT_DLL
	int		Save(CSave &save);
	int		Restore(CRestore &restore);
	static	TYPEDESCRIPTION m_SaveData[];
#endif
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 5; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer(CBasePlayer *pPlayer);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	BOOL Deploy(void);
	void Holster(int skiplocal = 0);
	void WeaponIdle(void); 

	BOOL PlayEmptySound(void);//

	virtual BOOL UseDecrement(void)
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

	int		m_iFireState;
	int		m_iFireMode;
	int		m_iBeam;
	CBeam *m_pBeam;
	CBaseEntity* m_hTargetEarth;
	CBaseEntity* m_hTargetXen;

	BOOL HasAmmo(void);
	void UseAmmo(int count);
	BOOL CanFireDisplacer() const;
	BOOL CanFireDisplacer2() const;

	enum DISPLACER_FIRESTATE { FIRESTATE_NONE = 0, FIRESTATE_SPINUP, FIRESTATE_FIRE };
	enum DISPLACER_FIREMODE { FIREMODE_NONE = 0, FIREMODE_FORWARD, FIREMODE_BACKWARD };

private:
	void ClearSpin( void );
	void SpinUp(int iFireMode);
	void Fire( BOOL fIsPrimary );
	void Teleport( void );
	void Displace( void );
	void CreateEffects( void );

private:
	unsigned short m_usDisplacer;
};

class CEagleLaser : public CBaseEntity
{
	void Spawn( void );
	void Precache( void );

	int	ObjectCaps( void ) { return FCAP_DONT_SAVE; }

public:
	void Suspend( float flSuspendTime );
	void EXPORT Revive( void );

	static CEagleLaser *CreateSpotDeagle( void );
};

class CEagle : public CBasePlayerWeapon
{
public:

#ifndef CLIENT_DLL
	int		Save( CSave &save );
	int		Restore( CRestore &restore );
	static	TYPEDESCRIPTION m_SaveData[];
#endif

	void Spawn( void );
	void Precache( void );
	int iItemSlot( void ) { return 2; }
	int GetItemInfo(ItemInfo *p);

	void PrimaryAttack( void );
	void SecondaryAttack( void );
	BOOL Deploy( void );
	void Holster( int skiplocal = 0 );
	void Reload( void );
	void WeaponIdle( void );

	void UpdateSpot( void );
	CEagleLaser *m_pEagleLaser;
	int m_fEagleLaserActive;
	virtual BOOL UseDecrement( void )
	{ 
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

private:
	int m_iShell;
	

	unsigned short m_usEagle;
};


class CGrappleTonguetip;

class CGrapple : public CBasePlayerWeapon
{
public:

#ifndef CLIENT_DLL
	int		Save(CSave &save);
	int		Restore(CRestore &restore);
	static	TYPEDESCRIPTION m_SaveData[];
#endif

	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 1; }
	int GetItemInfo(ItemInfo *p);

	void PrimaryAttack(void);
	BOOL Deploy(void);
	void Holster(int skiplocal = 0);
	void WeaponIdle(void);
	void ItemPostFrame(void);

	virtual BOOL ShouldWeaponIdle(void) { return TRUE; }

	virtual BOOL UseDecrement(void)
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

	void Fire(void);
	void FireWait(void);
	void FireReach(void);
	void FireTravel(void);
	void FireRelease(void);

	void Fire2(void);

	void OnTongueTipHitSurface( const Vector& vecTarget );
	void OnTongueTipHitEntity( CBaseEntity* pEntity );

	void StartPull( void );
	void StopPull( void );
	void Pull( void );

	BOOL IsTongueColliding( const Vector& vecShootOrigin, const Vector& vecTipPos );
	void CheckFireEligibility( void );
	BOOL CheckTargetProximity( void );

	void CreateTongueTip( void );
	void DestroyTongueTip( void );
	void UpdateTongueTip( void );

	void CreateBeam( CBaseEntity* pTongueTip );
	void DestroyBeam( void );
	void UpdateBeam( void );

	void StartPullSound( void );
	void UpdatePullSound( void );
	void ResetPullSound( void );

	BOOL CanAttack(float attack_time, float curtime, BOOL isPredicted);

	enum GRAPPLE_FIRESTATE 
	{ 
		FIRESTATE_NONE = 0, 
		FIRESTATE_FIRE,
		FIRESTATE_FIRE2,
		FIRESTATE_WAIT, 
		FIRESTATE_REACH, 
		FIRESTATE_TRAVEL, 
		FIRESTATE_RELEASE,
	};

	int		m_iFirestate;
	int		m_iHitFlags;
	BOOL	m_fTipHit;
	CGrappleTonguetip* m_pTongueTip;
	CBeam*	m_pBeam;
	float	m_flNextPullSoundTime;
	BOOL	m_fPlayPullSound;
private:
};


class CKnife : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 1; }
	void EXPORT SwingAgain(void);
	void EXPORT Smack(void);
	int GetItemInfo(ItemInfo *p);

	void PrimaryAttack(void);
	int Swing(int fFirst);
	BOOL Deploy(void);
	void Holster(int skiplocal = 0);
	int m_iSwing;
	TraceResult m_trHit;

	virtual BOOL UseDecrement(void)
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}
private:
	unsigned short m_usKnife;
};


class CM249 : public CBasePlayerWeapon
{
public:

#ifndef CLIENT_DLL
	int		Save(CSave &save);
	int		Restore(CRestore &restore);
	static	TYPEDESCRIPTION m_SaveData[];
#endif

	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 6; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer(CBasePlayer *pPlayer);

	void PrimaryAttack(void);
	BOOL Deploy(void);
	void Reload(void);
	void WeaponIdle(void);
	virtual BOOL ShouldWeaponIdle(void) { return TRUE; }
	float m_flNextAnimTime;
	int m_iShell;

	virtual BOOL UseDecrement(void)
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

	void ReloadStart( void );
	void ReloadInsert( void );

	enum M249_RELOAD_STATE { RELOAD_STATE_NONE = 0, RELOAD_STATE_OPEN, RELOAD_STATE_FILL };

	int m_iReloadState;

private:
	unsigned short m_usM249;
};

class CPenguin : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 5; }
	int GetItemInfo(ItemInfo *p);

	void PrimaryAttack(void);
	void SecondaryAttack(void);
	BOOL Deploy(void);
	void Holster(int skiplocal = 0);
	void WeaponIdle(void);
	int m_fJustThrown;

	virtual BOOL UseDecrement(void)
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

private:
	unsigned short m_usPenguinFire;
};

class CPipeWrench : public CBasePlayerWeapon
{
public:
#ifndef CLIENT_DLL
	int		Save(CSave &save);
	int		Restore(CRestore &restore);
	static	TYPEDESCRIPTION m_SaveData[];
#endif


	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 1; }
	void EXPORT SwingAgain(void);
	void EXPORT Smack(void);
	int GetItemInfo(ItemInfo *p);

	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void ItemPostFrame(void);
	virtual BOOL ShouldWeaponIdle(void) { return FALSE; };
	int Swing(int fFirst, BOOL fIsPrimary);
	BOOL Deploy(void);
	void Holster(int skiplocal = 0);
	int m_iSwing;
	TraceResult m_trHit;

	virtual BOOL UseDecrement(void)
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}
private:

	unsigned short m_usPWrench;

	void EXPORT WindUp(void);
	void EXPORT WindLoop(void);
	void EXPORT SwingAgain2(void);
	BOOL CanAttack(float attack_time, float curtime, BOOL isPredicted);

	enum PWRENCH_FIRESTATE { FIRESTATE_NONE = 0, FIRESTATE_WINDUP, FIRESTATE_WINDLOOP, FIRESTATE_BIGHIT };
	int m_iFirestate;
	float m_flHoldStartTime;
};

class CShockBeam : public CBaseEntity
{
public:
	void Spawn( void );
	void Precache( void );
	int  Classify ( void );
	void EXPORT ShockTouch( CBaseEntity *pOther );
	static CShockBeam *Shoot(entvars_t *pevOwner, Vector vecStart, Vector vecVelocity);
	void EXPORT FadeShock( void );
	void EXPORT ExplodeThink( void );
	void EXPORT BlastOn( void );
	void EXPORT BlastOff( void );
	void Glow( void );
	void GetAttachment ( int iAttachment, Vector &origin, Vector &angles );

	CBeam *m_pBeam;
	CBeam *m_pNoise;
	CSprite *m_pSprite;

	int m_iFadeCount;
	int m_iTrail;

	Vector m_vecForward;

	CBaseEntity *pShockedEnt;
};


class CShockrifle : public CHgun
{
public:

#ifndef CLIENT_DLL
	int		Save(CSave &save);
	int		Restore(CRestore &restore);
	static	TYPEDESCRIPTION m_SaveData[];
#endif

	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 7; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer(CBasePlayer *pPlayer);

	void PrimaryAttack(void);
	void SecondaryAttack(void);
	BOOL Deploy(void);
	void Holster(int skiplocal = 0);
	void Reload(void);
	void WeaponIdle(void);
	void ItemPostFrame(void);;

	int m_fShouldUpdateEffects;
	int m_flBeamLifeTime;

	void UpdateEffects();
	
	virtual BOOL UseDecrement(void)
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}
private:
	unsigned short m_usShockFire;
};

class CSniperrifle : public CBasePlayerWeapon
{
public:

#ifndef CLIENT_DLL
	int		Save(CSave &save);
	int		Restore(CRestore &restore);
	static	TYPEDESCRIPTION m_SaveData[];
#endif

	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 6; }
	int GetItemInfo(ItemInfo *p);
	int AddToPlayer(CBasePlayer *pPlayer);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	BOOL Deploy(void);
	void Holster(int skiplocal = 0);
	void Reload(void);
	void WeaponIdle(void);
	//void ItemPostFrame(void);

	BOOL ShouldWeaponIdle(void) { return TRUE; };

	BOOL m_fInZoom;// don't save this. 

	virtual BOOL UseDecrement(void)
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}

	BOOL m_fNeedAjustBolt;
	int	 m_iBoltState;

	enum SNIPER_BOLTSTATE { BOLTSTATE_FINE = 0, BOLTSTATE_ADJUST, BOLTSTATE_ADJUSTING, };

private:
	unsigned short m_usSniper;
};
#define MAX_PORTAL_BEAMS 5

class CPortal : public CBaseEntity
{
public:
	void Spawn(void);

	static void Shoot(entvars_t *pevOwner, Vector vecStart, Vector vecVelocity);
	static void Shoot2(entvars_t *pevOwner, Vector vecStart, Vector vecAngles,Vector vecVelocity);

	static void SelfCreate(entvars_t *pevOwner, Vector vecStart);

	void Touch(CBaseEntity *pOther);
	void EXPORT Animate(void);
	void EXPORT ExplodeThink( void );
	void Circle( void );


	virtual int		Save(CSave &save);
	virtual int		Restore(CRestore &restore);
	static	TYPEDESCRIPTION m_SaveData[];

	int  m_maxFrame;
	CBeam* m_pBeam[MAX_PORTAL_BEAMS];

	void CreateBeams();
	void ClearBeams();
	void UpdateBeams();
	CBaseEntity *pRemoveEnt;
};

class CSporelauncher : public CShotgun
{
public:

#ifndef CLIENT_DLL
	int		Save(CSave &save);
	int		Restore(CRestore &restore);
	static	TYPEDESCRIPTION m_SaveData[];
#endif

	void Spawn( void );
	void Precache( void );
	int iItemSlot() { return 7; }
	int GetItemInfo( ItemInfo *p );
	int AddToPlayer( CBasePlayer *pPlayer );

	void PrimaryAttack( void );
	void SecondaryAttack( void );
	BOOL Deploy();
	void Reload( void );
	void WeaponIdle( void );

	virtual BOOL UseDecrement( void )
	{
#if defined( CLIENT_WEAPONS )
		return TRUE;
#else
		return FALSE;
#endif
	}
	int m_iSquidSpitSprite;
private:
	unsigned short m_usSporeFire;
};
#endif // WEAPONS_H
