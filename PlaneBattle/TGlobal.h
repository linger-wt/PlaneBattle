#pragma once
#include <TSingleton.h>
#include "TModelManager.h"
#include "TControler.h"

class CTGlobal : public CTSingleton<CTGlobal>
{
	friend class CTSingleton<CTGlobal>;
	CTGlobal(void);
public:
	~CTGlobal(void);

	/* 初始化 */
	bool init();
	
	/* 获取模型管理 */
	CTModelManagerPtr getModelManager();

	/* 获取控制器 */
	CTControlerPtr getControler();

private:
	CTModelManagerPtr m_modelManager; // 模型管理
	CTControlerPtr m_controler; // 控制器
};

