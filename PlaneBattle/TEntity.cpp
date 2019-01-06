#include "TEntity.h"

CTEntity::CTEntity(void)
{
	::CoCreateGuid(&m_id);
	m_size = QSize(80,80); // 给实体定一个初始大小
}

CTEntity::~CTEntity(void)
{
}

GUID CTEntity::getID()
{
	return m_id;
}

QPointF CTEntity::getPos()
{
	return m_pos;
}

void CTEntity::setPos(QPointF point)
{
	m_pos = point;
}

QSize CTEntity::getSize()
{
	return m_size;
}

void CTEntity::setSize(QSize size)
{
	m_size = size;
}

CTEntity::Camp CTEntity::getCamp()
{
	return m_camp;
}

void CTEntity::setCamp(Camp camp)
{
	m_camp = camp;
}

QString CTEntity::getIconPath()
{
	return m_iconPath;
}

void CTEntity::setIconPath(QString iconPath)
{
	m_iconPath = iconPath;
}
