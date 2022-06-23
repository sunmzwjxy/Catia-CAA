//===================================================================
// COPYRIGHT CAA 2021/12/29
//===================================================================
// CAAPLMReorderCmd.cpp
// Header definition of class CAAPLMReorderCmd
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2021/12/29 Creation: Code generated by the 3DS wizard
//===================================================================

#include "CAAPLMReorderCmd.h"
#include "CUSCAAUtilService.h"
#include "fengyHelper.h"

#include "CATAfrCommandHeader.h"

#include "CATCreateExternalObject.h"
CATCreateClass( CAAPLMReorderCmd);


#include <direct.h>


//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
CAAPLMReorderCmd::CAAPLMReorderCmd() :
CATCommand (NULL, "CAAPLMReorderCmd")
{
	const char * pstrPrefix = "C:/temp/";
	if (_access(pstrPrefix, 0) == -1)	//如果文件夹不存在
		_mkdir(pstrPrefix);				//则创建
										// 先应对obj 链接 bug
	CATUnicodeString str_logTime;
	CATTime logTime = CATTime::GetCurrentLocalTime();
	str_logTime = logTime.ConvertToString("%Y-%m-%d_%H%M%S");			// 月-日 时分秒格式
	logFilePath = "C:\\temp\\log_TreeReordering_" + str_logTime + ".txt";

RequestStatusChange (CATCommandMsgRequestSharedMode);
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
CAAPLMReorderCmd::~CAAPLMReorderCmd()
{
}


//  Overload this method: when your command gains focus
//
// Activates a command.
//   iFromClient :The command that requests to activate the current one.
//   iEvtDat :The notification sent.
// ----------------------------------------------------

//CATStatusChangeRC CAAPLMReorderCmd::Activate( CATCommand * iFromClient, CATNotification * iEvtDat)
//{
//	//CUSCAAUtilService::CAACallOOTBCmd("PLMReorder");
//
//	CATUnicodeString tmpMsg = "CAAPLMReorderCmd::   Activate！";
//	cout << tmpMsg << endl;
//	fengyHelper::AppendContentToFile(logFilePath, tmpMsg);
//
//	cout << "********************CUSCAAUtilService::CAACallOOTBCmd  START *******************" << endl;
//	CATString cmdHdr = "PLMReorder";
//	CATCommand * pCATCommand = NULL;
//	tmpMsg = "CAAPLMReorderCmd::   Activate  11111111！";
//	fengyHelper::AppendContentToFile(logFilePath, tmpMsg);
//	HRESULT hr = CATAfrStartCommand(cmdHdr, pCATCommand);
//
//	if ( FAILED(hr) && pCATCommand == NULL)
//	{
//		tmpMsg = "CAAPLMReorderCmd::   CATAfrStartCommand  KO 1！";
//		fengyHelper::AppendContentToFile(logFilePath, tmpMsg);
//
//		cout << "Failed find the command, the command Hdr is wrong" << endl;
//
//		//hr = CATAfrStartCommand("DELMSDAssignmentAssistantHdr", pCATCommand);
//		hr = CATAfrStartCommand(cmdHdr, pCATCommand);
//		if (FAILED(hr))
//		{
//			tmpMsg = "CAAPLMReorderCmd::   CATAfrStartCommand  KO 2";
//			fengyHelper::AppendContentToFile(logFilePath, tmpMsg);
//		}
//
//		tmpMsg = "CAAPLMReorderCmd::   Activate  222222222222 ！";
//		fengyHelper::AppendContentToFile(logFilePath, tmpMsg);
//
//		RequestDelayedDestruction();
//		return (CATStatusChangeRCCompleted);
//
//		//hr = CATAfrStartCommand("DELMSDAssignmentAssistantHdr", pCATCommand);
//	}
//
//	cout << "Success find the command, the command Hdr is OK" << endl;
//
//	tmpMsg = "CAAPLMReorderCmd::   Activate  3333333333！";
//	fengyHelper::AppendContentToFile(logFilePath, tmpMsg);
//
//	CATStatusChangeRC rcStatus = pCATCommand->Activate(NULL, NULL);		// No Way !
//	cout << "********************CUSCAAUtilService::CAACallOOTBCmd  END *******************" << endl;
//
//	tmpMsg = "CAAPLMReorderCmd::   Activate  4444444444！";
//	fengyHelper::AppendContentToFile(logFilePath, tmpMsg);
//
//
//	//CATUnicodeString msg2 = "1. CAAPLMReorderCmd Action 成功！ ";			 
//	//msg2.Append("2. 处理过程日志保存在" + logFilePath);
//	//msg2.Append(" 。【打开该文件吗？】");
//	//fengyHelper::NotifyWithOpen(msg2, logFilePath);
//
//	RequestDelayedDestruction();
//	return (CATStatusChangeRCCompleted);
//}

CATStatusChangeRC CAAPLMReorderCmd::Activate(CATCommand * iFromClient, CATNotification * iEvtDat)
{
	CATUnicodeString tmpMsg = "CATAfrStartCommand::   Activate  11111111！";
	fengyHelper::AppendContentToFile(logFilePath, tmpMsg);
	CATCommand *pCmd = NULL;
	HRESULT rc = ::CATAfrStartCommand("PLMReorder", pCmd);					// 我的开发机器 中英文下 各个app下都能运行，但是别的机器只能在 装配app下运行，其他app不行！
	//HRESULT rc = ::CATAfrStartCommand("GenericReorder", pCmd);		// 尝试 ootb调用！
	//HRESULT rc = ::CATAfrStartCommand("PLMReorderdHdr", pCmd);
	//HRESULT rc = ::CATAfrStartCommand("CATLPCmdNewReorder", pCmd);
	

	if (SUCCEEDED(rc) && !!pCmd)
	{
		tmpMsg = "CATAfrStartCommand::   Activate  22222222！";
		fengyHelper::AppendContentToFile(logFilePath, tmpMsg);
		pCmd->RequestStatusChange(CATCommandMsgRequestSharedMode);
	}
	else
	{
		tmpMsg = "CATAfrStartCommand::   Activate  KO！";
		fengyHelper::AppendContentToFile(logFilePath, tmpMsg);
		RequestDelayedDestruction();
		return (CATStatusChangeRCAborted);
	}

	RequestDelayedDestruction();
	return (CATStatusChangeRCCompleted);
}


//  Overload this method: when your command loses focus
//
// Deactivates a command.
//   iFromClient :The command that requests to activate the current one.
//   iEvtDat :The notification sent.
// ----------------------------------------------------
CATStatusChangeRC CAAPLMReorderCmd::Desactivate( CATCommand * iFromClient, CATNotification * iEvtDat)
{
	RequestDelayedDestruction();
	return (CATStatusChangeRCCompleted);
}

//  Overload this method: when your command is canceled
//
// Cancel a command.
//   iFromClient :The command that requests to activate the current one.
//   iEvtDat :The notification sent.
// ----------------------------------------------------
CATStatusChangeRC CAAPLMReorderCmd::Cancel( CATCommand * iFromClient, CATNotification * iEvtDat)
{
RequestDelayedDestruction();
return (CATStatusChangeRCCompleted);
}
