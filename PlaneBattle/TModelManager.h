#pragma once
#include "TEntity.h"
#include <QMutex>

class CTModelManager
{
public:
	CTModelManager(void);
	~CTModelManager(void);

	/* 获取实体列表 */
	CTEntityList getEntityList();

	/* 添加实体 */
	void addEntity(CTEntityPtr entity);

	/* 移除实体 */
	void removeEntity(CTEntityPtr entity);

	/* 根据ID查找实体 */
	CTEntityPtr getEntityByID(GUID id);

private:
	CTEntityList m_entityList; // 实体列表
	QMutex m_mutex; // 临界区
};

typedef std::shared_ptr<CTModelManager> CTModelManagerPtr;

