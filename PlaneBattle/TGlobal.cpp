#include "TGlobal.h"

CTGlobal::CTGlobal(void)
{
}

CTGlobal::~CTGlobal(void)
{
}

bool CTGlobal::initApplication()
{
	/* 创建模型管理 */
	m_pModelManager = std::make_shared<CTModelManager>();

	/* 创建场景 */
	m_pScene = std::make_shared<CTScene>();

	/* 创建控制器 */
	m_pControler = std::make_shared<CTControler>();

	return true;
}

CTModelManagerPtr CTGlobal::getModelManager()
{
	return m_pModelManager;	
}

CTControlerPtr CTGlobal::getControler()
{
	return m_pControler;
}

CTScenePtr CTGlobal::getScene()
{
	return m_pScene;
}
