#ifndef WPN_mp5k_H
#define WPN_mp5k_H
#ifdef _WIN32
#pragma once
#endif

//mp5k
#define mp5k_MAX_SPEED		190
#define mp5k_DAMAGE		32
#define mp5k_DAMAGE_SIL		33
#define mp5k_RANGE_MODIFER      0.97
#define mp5k_RANGE_MODIFER_SIL  0.95
#define mp5k_RELOAD_TIME	3.05

class Cmp5k : public CBasePlayerWeapon
{
public:
	void Spawn() override;
	void Precache() override;
	int GetItemInfo(ItemInfo *p) override;
	BOOL Deploy() override;
	float GetMaxSpeed() override { return SMG_SPEED; }
	int iItemSlot() override { return PRIMARY_WEAPON_SLOT; }
	void PrimaryAttack() override;
void QuickDeploy() override;

void QuickReload() override;
	void SecondaryAttack() override;
	void Reload() override;
void unsilreload();
void silreload();
	void WeaponIdle() override;
	BOOL UseDecrement() override {
#ifdef CLIENT_WEAPONS
		return TRUE;
#else
		return FALSE;
#endif
	}
	KnockbackData GetKnockBackData() override { return { 350.0f, 250.0f, 300.0f, 100.0f, 0.6f }; }

public:
	void mp5kFire(float flSpread, float flCycleTime, BOOL fUseAutoAim);

	int m_iShell;
	int iShellOn;

private:
	unsigned short m_usFiremp5k;
};

#endif
