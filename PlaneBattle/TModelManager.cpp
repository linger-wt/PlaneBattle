#include "TModelManager.h"

CTModelManager::CTModelManager(void)
{
}

CTModelManager::~CTModelManager(void)
{
}

CTEntityList CTModelManager::getEntityList()
{
	return m_entityList;
}

void CTModelManager::addEntity(CTEntityPtr entity)
{
	if (entity == nullptr)
	{
		return;
	}
	m_mutex.lock();
	auto res = std::find_if(m_entityList.begin(), m_entityList.end(), [entity](CTEntityPtr p){return p->getID() == entity->getID();});
	if (res == m_entityList.end())
	{
		m_entityList.push_back(entity);
	}
	m_mutex.unlock();
}

void CTModelManager::removeEntity(CTEntityPtr entity)
{
	if (entity == nullptr)
	{
		return;
	}
	m_mutex.lock();
	auto res = std::remove_if(m_entityList.begin(), m_entityList.end(), [entity](CTEntityPtr p){return entity->getID() == p->getID();});
	if (res != m_entityList.end())
	{
		m_entityList.erase(res);
	}
	m_mutex.unlock();
}

CTEntityPtr CTModelManager::getEntityByID(GUID id)
{
	CTEntityPtr entity = nullptr;
	
	m_mutex.lock();
	auto res = std::find_if(m_entityList.begin(), m_entityList.end(), [id](CTEntityPtr p){return p->getID() == id;});
	if (res != m_entityList.end())
	{
		entity = *res;
	}
	m_mutex.unlock();
	
	return entity;
}
