#include "TGlobal.h"

CTGlobal::CTGlobal(void)
{
}

CTGlobal::~CTGlobal(void)
{
}

bool CTGlobal::init()
{
	/* 创建模型管理 */
	m_modelManager = std::make_shared<CTModelManager>();

	/* 创建控制器 */
	m_controler = std::make_shared<CTControler>();
	m_controler->init(); // 控制器初始化

	return true;
}

CTModelManagerPtr CTGlobal::getModelManager()
{
	return m_modelManager;	
}

CTControlerPtr CTGlobal::getControler()
{
	return m_controler;
}
