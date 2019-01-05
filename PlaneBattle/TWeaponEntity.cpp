#include "TWeaponEntity.h"

CTWeaponEntity::CTWeaponEntity(DamageScale damageScale)
	: m_damageScale(damageScale)
{
}

CTWeaponEntity::~CTWeaponEntity(void)
{
}

double CTWeaponEntity::getDamageDegree()
{
	double damageDegree = 0.0;
	switch (m_damageScale)
	{
	case one_level:
		{
			damageDegree = 0.8;
		}
		break;
	case two_level:
		{
			damageDegree = 0.5;
		}
		break;
	case three_level:
		{
			damageDegree = 0.2;
		}
		break;
	}
	return damageDegree;
}
