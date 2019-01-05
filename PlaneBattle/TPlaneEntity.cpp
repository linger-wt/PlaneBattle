#include "TPlaneEntity.h"

CTPlaneEntity::CTPlaneEntity(void)
{

}

CTPlaneEntity::~CTPlaneEntity(void)
{

}

int CTPlaneEntity::getHealth()
{
	return m_health;
}

void CTPlaneEntity::setHealth(int health)
{
	m_health = health;
}

bool CTPlaneEntity::isDestory()
{
	return m_health <= 0;
}
