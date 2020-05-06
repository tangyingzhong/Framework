///************************************************************************
/// <copyrigth>2018-2019 Corporation.All Rights Reserved</copyrigth>
/// <author>tangyingzhong</author>
/// <contact>tangyz114987@outlook.com</contact>
/// <version>v1.0.0</version>
/// <describe>
/// It duty for loading AppFramework's context
///</describe>
/// <date>2019/11/6</date>
///***********************************************************************
#ifndef APPFRAMEWORK_H
#define APPFRAMEWORK_H

#include "Common/IApplicationContext.h"
#include "../../../Common/PluginLoader/Include/PluginLoader.h"

class AppFramework
{
public:
	typedef Mutex* Lock;
	typedef PluginLoader<IApplicationContext> Loader;

public:
	// Get the AppFramework instance
	static AppFramework* GetInstance();

	// Destory the app instance
	static None DestoryInstance();

private:
	// Construct the AppFramework
	AppFramework();

	// Destruct the AppFramework
	~AppFramework();

	// Forbid the AppFramework's copy
	AppFramework(const AppFramework& other){	}

	// Forbid the AppFramework's assignment
	AppFramework& operator=(const AppFramework& other){	}

public:
	// Get global AppFramework context
	IApplicationContext* GetGlobalContext();

private:
	// Initialize the AppFramework
	None Initialize();

	// Destory the AppFramework
	None Destory();

	// Create app context
	None CreateAppContext();

private:
	// Get the AppContext
	inline IApplicationContext* GetAppContext() const
	{
		return m_pAppContext;
	}

	// Set the AppContext
	inline None SetAppContext(IApplicationContext* pAppContext)
	{
		m_pAppContext = pAppContext;
	}

	// Get the Disposed
	inline BOOL GetDisposed() const
	{
		return m_bDisposed;
	}

	// Set the Disposed
	inline None SetDisposed(BOOL bDisposed)
	{
		m_bDisposed = bDisposed;
	}

private:
	// AppFramework self
	static AppFramework* m_pInstance;

	// Lock for the instance
	static Lock m_pInstanceLock;

	// AppFramework's context
	IApplicationContext* m_pAppContext;

	// Plugin loader
	Loader m_PluginLoader;

	// AppFramework close state
	BOOL m_bDisposed;
};

#endif // APPFRAMEWORK_H