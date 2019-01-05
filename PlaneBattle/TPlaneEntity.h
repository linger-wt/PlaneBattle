#pragma once
#include "TEntity.h"
#include <QString>

/* 飞机实体 */
class CTPlaneEntity : public CTEntity
{
public:
	CTPlaneEntity(void);
	~CTPlaneEntity(void);

	/* 实体生命值 */
	int getHealth();
	void setHealth(int health);

	/* 是否损毁(生命值是否为0) */
	bool isDestory();

private:
	int m_health; // 实体生命值
};

