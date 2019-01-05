#pragma once

/* 데절친경 */
template<class T>
class  CTSingleton
{
	static T * s_instance;

public:
	static T * instance();
	static void freeInstance();
};

template<class T>
T * CTSingleton<T>::s_instance=NULL;

template<class T>
T * CTSingleton<T>::instance()
{
	if(s_instance == 0)
	{
		s_instance=new T();
	}

	return s_instance;
}

template<class T>
void CTSingleton<T>::freeInstance()
{
	if(s_instance)
	{	
		delete s_instance;
		s_instance=NULL;
	}
}
