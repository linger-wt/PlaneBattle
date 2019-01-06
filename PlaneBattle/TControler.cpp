#include "TControler.h"
#include "TEntity.h"
#include "TGlobal.h"

CTControler::CTControler(void)
{
}

CTControler::~CTControler(void)
{
}

void CTControler::init()
{
	CTModelManagerPtr pModelManager = CTGlobal::instance()->getModelManager();
	CTScenePtr pScene = CTGlobal::instance()->getScene();
	if (pModelManager == nullptr || pScene == nullptr)
	{
		return;
	}

	// 创建红方实体（红方实体属于操作方，只有一个）
	CTEntityPtr entity = std::make_shared<CTEntity>();
	entity->setCamp(CTEntity::Red); // 设置实体阵营
	entity->setPos(QPointF(0, 0)); // 设置实体位置
	pModelManager->addEntity(entity); // 将实体加入到模型管理中
	pScene->addItemToScene(entity); // 将红方实体加入到场景中
}
