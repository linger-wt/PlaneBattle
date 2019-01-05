#pragma once
#include "TEntity.h"

/* 武器实体 */
class CTWeaponEntity : public CTEntity
{
	/* 毁伤规模 */
	enum DamageScale
	{
		one_level=0, // 一级伤害（最大）
		two_level, // 二级伤害
		three_level, // 三级伤害（最小）
	};

public:
	CTWeaponEntity(DamageScale damageScale);
	~CTWeaponEntity(void);

	/* 获取武器毁伤程度 
	   根据不同的毁伤规模获取到的毁伤程度也不同
	   一级毁伤规模：0.8
	   二级毁伤规模：0.5
	   三级毁伤规模：0.2*/
	double getDamageDegree();

private:
	DamageScale m_damageScale;
};

