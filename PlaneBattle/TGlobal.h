#pragma once
#include "TSingleton.h"
#include "TModelManager.h"
#include "TControler.h"
#include "TScene.h"

class CTGlobal : public CTSingleton<CTGlobal>
{
	friend class CTSingleton<CTGlobal>;
	CTGlobal(void);
public:
	~CTGlobal(void);

	/* 初始化 */
	bool initApplication();
	
	/* 获取模型管理 */
	CTModelManagerPtr getModelManager();

	/* 获取控制器 */
	CTControlerPtr getControler();

	/* 获取场景 */
	CTScenePtr getScene();

private:
	CTModelManagerPtr m_pModelManager; // 模型管理
	CTControlerPtr m_pControler; // 控制器
	CTScenePtr m_pScene; // 场景
};

