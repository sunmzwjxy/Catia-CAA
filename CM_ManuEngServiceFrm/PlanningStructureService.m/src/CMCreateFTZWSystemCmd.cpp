﻿//===================================================================
// COPYRIGHT  2022/02/09
//===================================================================
// CMCreateFTZWSystemCmd.cpp
// Header definition of class CMCreateFTZWSystemCmd
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2022/02/09 Creation: Code generated by the 3DS wizard
//===================================================================

#include "CMCreateFTZWSystemCmd.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;

//#include "CATIndicationAgent.h"
//#include "CATMathPlane.h"
#include "CATApplicationFrame.h"

#include "CATCreateExternalObject.h"
CATCreateClass( CMCreateFTZWSystemCmd);

#include "CUSCAAUtilService.h"
#include "PPRUtity.h"
#include "CAAUtility.h"
//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
CMCreateFTZWSystemCmd::CMCreateFTZWSystemCmd() :
CATStateCommand ("CMCreateFTZWSystemCmd", CATDlgEngOneShot, CATCommandModeShared)
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
, _OKAgent(NULL),
_ApplyAgent(NULL),
_CloseAgent(NULL),
_CancleAgent(NULL)
{
	//TODO: Add the constructor code here
	CATDlgWindow *pWnd = (CATApplicationFrame::GetFrame())->GetMainWindow();
	_Panel = new CMSystemFTZWDlg(pWnd, "FTZW System");
	_Panel->Build();
	_Panel->SetFather(this);

	pZWFatherRef = NULL;
	pZWFatherOcc = NULL;

}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
CMCreateFTZWSystemCmd::~CMCreateFTZWSystemCmd()
{
	if (_OKAgent != NULL)
	{
		_OKAgent->RequestDelayedDestruction();
		_OKAgent = NULL;
	}

	if (_ApplyAgent != NULL)
	{
		_ApplyAgent->RequestDelayedDestruction();
		_ApplyAgent = NULL;
	}

	if (_CloseAgent != NULL)
	{
		_CloseAgent->RequestDelayedDestruction();
		_CloseAgent = NULL;
	}

	if (_CancleAgent != NULL)
	{
		_CancleAgent->RequestDelayedDestruction();
		_CancleAgent = NULL;
	}


	if (_Panel != NULL)
	{
		_Panel->RequestDelayedDestruction();
		_Panel = NULL;
	}



	_RELEASE_PTR_(pZWFatherRef);
	_RELEASE_PTR_(pZWFatherOcc);

}


//-------------------------------------------------------------------------
// BuildGraph()
//-------------------------------------------------------------------------
void CMCreateFTZWSystemCmd::BuildGraph()
{
// TODO: Define the StateChart
// ---------------------------
	// Define the OK button agent
	_OKAgent = new CATDialogAgent("OK Agent");
	_OKAgent->AcceptOnNotify(_Panel, _Panel->GetDiaOKNotification());

	// Define the Cancel button agent
	_ApplyAgent = new CATDialogAgent("Apply Agent");
	_ApplyAgent->AcceptOnNotify(_Panel, _Panel->GetDiaAPPLYNotification());   //GetDiaAPPLYNotification     //GetDiaCANCELNotification 

	// Define the Close button agent
	_CloseAgent = new CATDialogAgent("Close Agent");
	_CloseAgent->AcceptOnNotify(_Panel, _Panel->GetWindCloseNotification());    //GetMDICloseNotification    //GetWindCloseNotification

		// Define the Close button agent
	_CancleAgent = new CATDialogAgent("Cancel Agent");
	_CancleAgent->AcceptOnNotify(_Panel, _Panel->GetDiaCANCELNotification());    //GetMDICloseNotification    //GetWindCloseNotification


	// Define the selection agent
	_pSelectAgent = new CATPathElementAgent("SelectionAgent");

	// Define the behaviors
	_pSelectAgent->SetBehavior(CATDlgEngWithCSO | CATDlgEngWithPrevaluation | CATDlgEngNewHSOManager);   //CATDlgEngMultiAcquisitionCtrl

	CATAcquisitionFilter* pFilter = Filter((FilterMethod)&CMCreateFTZWSystemCmd::SelectionCheck, (void*)NULL);
	_pSelectAgent->SetFilter(pFilter);

	AddCSOClient(_pSelectAgent);

	// Define the states
	CATDialogState * pSelectionState = GetInitialState("ElementSelection");
	pSelectionState->AddDialogAgent(_OKAgent);
	pSelectionState->AddDialogAgent(_CloseAgent);
	pSelectionState->AddDialogAgent(_CancleAgent);
	pSelectionState->AddDialogAgent(_ApplyAgent);
	pSelectionState->AddDialogAgent(_pSelectAgent);

	// Transition from Input state to NULL, when click on OK button
	AddTransition(pSelectionState, NULL, AndCondition(IsOutputSetCondition(_OKAgent), Condition((ConditionMethod)&CMCreateFTZWSystemCmd::OKAction)), NULL);

	// Transition from Input state to NULL, when click on Cancel button
	AddTransition(pSelectionState, pSelectionState, IsOutputSetCondition(_ApplyAgent), Action((ActionMethod)&CMCreateFTZWSystemCmd::ApplyAction));

	// Transition from Input state to NULL, when click on Close button
// 	AddTransition(pSelectionState, NULL, IsOutputSetCondition(_CloseAgent), Action((ActionMethod)&CMCreateFTZWSystemCmd::CancelAction));
	AddTransition(pSelectionState, NULL, IsOutputSetCondition(_CloseAgent), Action((ActionMethod)&CMCreateFTZWSystemCmd::CancelAction));

	AddTransition(pSelectionState, NULL, IsOutputSetCondition(_CancleAgent), Action((ActionMethod)&CMCreateFTZWSystemCmd::CancelAction));

	AddTransition(pSelectionState, pSelectionState, IsOutputSetCondition(_pSelectAgent), Action((ActionMethod)&CMCreateFTZWSystemCmd::ElementSelection, NULL, NULL, (void*)1));

	CUSCAAUtilService::ShowComboValue(_Panel->GetCombo(ID_JobStylesCombo), "CMSystemFTZWDlg", "JobStyles.Range", ",");
	CUSCAAUtilService::ShowComboValue(_Panel->GetCombo(ID_MachineCodeCombo), "CMSystemFTZWDlg", "MachineCode.Range", ",");


}

CATBoolean CMCreateFTZWSystemCmd::SelectionCheck()
{
	CATPathElement *pPath = _pSelectAgent->GetValue();
	CATIPLMNavOccurrence* piOccurrence = (CATIPLMNavOccurrence*)(pPath->FindElement(IID_CATIPLMNavOccurrence));
	if (piOccurrence == NULL)
	{
		return FALSE;
	}
	CATIPLMNavReference *piNavReference = NULL;
	piOccurrence->GetRelatedReference(piNavReference);
	if (piNavReference == NULL)
	{
		return FALSE;
	}

	CATUnicodeString strObjType = CAAUtility::GetObjectTypeName(piNavReference);

	if (strObjType != "DELLmiWorkPlanSystemReference")
	{
		return FALSE;
	}

	return TRUE;
}

CATBoolean CMCreateFTZWSystemCmd::ElementSelection(void * data)
{
	CATBoolean returnCode = FALSE;
	if (_pSelectAgent != NULL)
	{
		returnCode = TRUE;
		CATPathElement * pPathElement = _pSelectAgent->GetValue();

		if (pPathElement != NULL)
		{
			_pSelectedElement = pPathElement->FindElement(IID_CATBaseUnknown);
			_pSelectedOccurrence = (CATIPLMNavOccurrence*)(pPathElement->FindElement(IID_CATIPLMNavOccurrence));
			if (_pSelectedOccurrence)
			{
				_pSelectedOccurrence->GetRelatedReference(_pSelectedReference);
// 				_pSelectedOccurrence->GetRelatedInstance(_pSelectedInstance);
			}
		}

		_pSelectAgent->InitializeAcquisition();

		if (_pSelectedElement != NULL)
		{
			// Highlight the selected Element
			if (FAILED(CUSCAAUtilService::HighlightElement(_pSelectedOccurrence, _pSelectedRepInstance, _pSelectedElement)))
				returnCode = FALSE;

			FilterSelectObject();
		}
		else returnCode = FALSE;
	}
	return returnCode;
}

void CMCreateFTZWSystemCmd::FilterSelectObject()
{
	CATUnicodeString sSelectObjectType = CUSCAAUtilService::GetObjectKnowledgeType(_pSelectedReference);
	if (sSelectObjectType == "DELLmiWorkPlanSystemReference")
	{
		pZWFatherOcc = _pSelectedOccurrence;
		pZWFatherRef = _pSelectedReference;

		CATDlgEditor *pZWFaEditor = _Panel->GetEditor(ID_PartCodeEditor);
		CATUnicodeString sName = CUSCAAUtilService::GetObjectAttrValue(pZWFatherRef, "V_Name");
		pZWFaEditor->SetText(sName);

		_Panel->SetVisibility(CATDlgShow);
	}
}

HRESULT CMCreateFTZWSystemCmd::CreateDELFTZWSystem()
{
	if (pZWFatherRef == NULL)
	{
		CATUnicodeString Title = CATMsgCatalog::BuildMessage((CATString)"CMSystemFTZWDlg", (CATString)"msg.Title");
		CATUnicodeString msg = CATMsgCatalog::BuildMessage((CATString)"CMSystemFTZWDlg", (CATString)"msg.nodeFatherNull");
		CUSCAAUtilService::ErrorMessage(Title, msg);
		return S_FALSE;
	}

	PPRUtity spPPRUtity;
	CATIPLMNavInstance * spNewFTZWSystemInstance = nullptr;
	HRESULT rc = spPPRUtity.CreateSubSystemOrOperation("CUS_Workplan_FTZW",
		pZWFatherRef, spNewFTZWSystemInstance);


	if (spNewFTZWSystemInstance == NULL) {
		cout << "Failed to create operation under the system" << endl;
		return S_FALSE;
	}

	CATIPLMNavReference * spNewFTZWSystemRef = nullptr;
	rc = spNewFTZWSystemInstance->GetReferenceInstanceOf(spNewFTZWSystemRef);
	if (spNewFTZWSystemRef == NULL)
	{
		cout << "Failed to Get new FTZW system Reference" << endl;
		return S_FALSE;
	}
	

	CATDlgEditor *pPartCodeEditor = _Panel->GetEditor(ID_PartCodeEditor);
	CATUnicodeString sInputPartCode = pPartCodeEditor->GetText();

	CATDlgEditor *pNameEditor = _Panel->GetEditor(ID_NameEditor);
	CATUnicodeString sInputName = pNameEditor->GetText();

	CATDlgEditor *pValidEditor = _Panel->GetEditor(ID_ValidEditor);
	CATUnicodeString sInputValid = pValidEditor->GetText();


	CATUnicodeString sInputMachineCode = CUSCAAUtilService::GetSelectComboValue(_Panel->GetCombo(ID_MachineCodeCombo));
	CATUnicodeString sMachineCode = "";
	if (sInputMachineCode == "CR929")
		sMachineCode = "W";
	else if (sInputMachineCode == "C919")
		sMachineCode = "C";
	else sMachineCode = "A";

	CATUnicodeString sInputJobStyle = CUSCAAUtilService::GetSelectComboValue(_Panel->GetCombo(ID_JobStylesCombo));
	CATUnicodeString sJobStyle = "";
	if (sInputJobStyle == "InstrumentTest")
		sJobStyle = "IT";
	else if (sInputJobStyle == "Maintenance")
		sJobStyle = "ME";
	else sJobStyle = "MA";


	CATUnicodeString sInputFTZWCode = sInputPartCode + sMachineCode + sJobStyle + sInputName;

	rc = CUSCAAUtilService::SetObjectAttrString(spNewFTZWSystemRef, "V_Name", sInputFTZWCode);		//title
	rc = CUSCAAUtilService::SetObjectAttrString(spNewFTZWSystemRef, "PLM_ExternalID", sInputFTZWCode);	//name


	rc = CUSCAAUtilService::SetObjectAttrString(spNewFTZWSystemRef, "CUS_BUNumber", sInputPartCode);			//CUS_BUNumber
	rc = CUSCAAUtilService::SetObjectAttrString(spNewFTZWSystemRef, "CUS_Code", sInputPartCode);			//cus_code
	// 站位号自动生成 CUS_Title
	rc = CUSCAAUtilService::SetObjectAttrString(spNewFTZWSystemRef, "CUS_Title", sInputName);			//cus_title
	rc = CUSCAAUtilService::SetObjectAttrString(spNewFTZWSystemRef, "CUS_Eff", sInputValid);				//
	rc = CUSCAAUtilService::SetObjectAttrString(spNewFTZWSystemRef, "CUS_Model", sInputMachineCode);				//CUS_Model
	rc = CUSCAAUtilService::SetObjectAttrString(spNewFTZWSystemRef, "CUS_WORKTYPE", sInputJobStyle);				//CUS_WORKTYPE


	//CATUnicodeString sInstanceName = GetObjectAttrValue(spNewZWSystemInstance, "PLM_ExternalID");
	//rc = CUSCAAUtilService::SetObjectAttrString(spNewFTZWSystemInstance, "CUS_Eff", "21210");


	rc = CUSCAAUtilService::CopyDictionariesModel(pZWFatherRef, spNewFTZWSystemRef);
	if (FAILED(rc) || spNewFTZWSystemRef == NULL)
	{
		cout << "Failed to Copy model from workplan to FTZW" << endl;
		return S_FALSE;
	}

	return rc;
}

CATBoolean CMCreateFTZWSystemCmd::CheckZWSelect()
{
	//Check ZW facther system if select pZWFatherOcc
	if (pZWFatherOcc)
		return TRUE;
	return FALSE;
}

CATBoolean CMCreateFTZWSystemCmd::CheckInputCode()
{
	/*
	ID_PartCodeEditor,
	ID_NameEditor,
	ID_ValidEditor,
	ID_MachineCodeCombo,		// Combo2
	ID_JobStylesCombo			// Combo1
	*/
	CATDlgEditor *pPartCodeEditor = _Panel->GetEditor(ID_PartCodeEditor);
	CATUnicodeString sInputPartCode = pPartCodeEditor->GetText();

	CATDlgEditor *pNameEditor = _Panel->GetEditor(ID_NameEditor);
	CATUnicodeString sInputName = pNameEditor->GetText();

	CATDlgEditor *pValidEditor = _Panel->GetEditor(ID_ValidEditor);
	CATUnicodeString sInputValid = pValidEditor->GetText();


//////////////////////////////////////////////////////////////////////////

	CATUnicodeString sInputMachineCode = CUSCAAUtilService::GetSelectComboValue(_Panel->GetCombo(ID_MachineCodeCombo));
	CATUnicodeString sInputJobStyle = CUSCAAUtilService::GetSelectComboValue(_Panel->GetCombo(ID_JobStylesCombo));


	CATUnicodeString sInputFTZWCode = sInputPartCode + sInputMachineCode + sInputJobStyle + sInputName;

//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// Valiate sInputValid


	if (sInputPartCode == "" || sInputName == "" || sInputValid == "")
	{
		CATUnicodeString Title = CATMsgCatalog::BuildMessage((CATString)"CMSystemFTZWDlg", (CATString)"msg.Title");
		CATUnicodeString msg = CATMsgCatalog::BuildMessage((CATString)"CMSystemFTZWDlg", (CATString)"msg.inputCodeNull");
		CUSCAAUtilService::ErrorMessage(Title, msg);
		return TRUE;
	}

	if (sInputAOExternalID == sInputPartCode)
	{
		CATUnicodeString Title = CATMsgCatalog::BuildMessage((CATString)"CMSystemFTZWDlg", (CATString)"msg.Title");
		CATUnicodeString msg = CATMsgCatalog::BuildMessage((CATString)"CMSystemFTZWDlg", (CATString)"msg.uniqueIDError");
		CUSCAAUtilService::ErrorMessage(Title, msg);
		return TRUE;
	}

	CATListPtrCATIPLMNavReference opilistIDComp;
	HRESULT hr = CUSCAAUtilService::GetObjReference(sInputFTZWCode, "", opilistIDComp, "CUS_Workplan_FTZW");
	if (opilistIDComp.Size() > 0)
	{
		CATUnicodeString Title = CATMsgCatalog::BuildMessage((CATString)"CMSystemFTZWDlg", (CATString)"msg.Title");
		CATUnicodeString msg = CATMsgCatalog::BuildMessage((CATString)"CMSystemFTZWDlg", (CATString)"msg.uniqueIDError");
		CUSCAAUtilService::ErrorMessage(Title, msg);
		return TRUE;
	}

	//////////////////////////////////////////////////////////////////////////
	std::regex reg("^2\\d{4}-2\\d{4}$|2\\d{4},2\\d{4}$|^2\\d{4}$");
	CATBoolean bMatched = std::regex_match(sInputValid.ConvertToChar(), reg);
	if (bMatched == FALSE)
	{
		CUSCAAUtilService::ErrorMessage(CATUnicodeString("Error"), CATUnicodeString("Effectivity code is invalid!"));
		return TRUE;
	}
	//////////////////////////////////////////////////////////////////////////

	sInputAOExternalID = sInputFTZWCode;

	return FALSE;

}

//-------------------------------------------------------------------------
// ActionOne ()
//-------------------------------------------------------------------------
CATBoolean CMCreateFTZWSystemCmd::ActionOne( void *data )
{
// TODO: Define the action associated with the transition
// ------------------------------------------------------

return TRUE;
}

CATBoolean CMCreateFTZWSystemCmd::OKAction(void *data)
{
	cout << "ZWConnectCmd::OKAction() - INFO: Entering OKAction()... " << endl;
	if (_OKAgent)
	{
		_OKAgent->InitializeAcquisition();
	}

	// check select 
	if (!CheckZWSelect())
	{
		return FALSE;
	}

	//input code null or code is repeat/ Check input
	if (CheckInputCode())
	{
		return FALSE;
	}

	// Create FTZW
	CreateDELFTZWSystem();
	CATUnicodeString strMsg = CAAUtility::PLMSave();
	if (strMsg != "Success")
		CUSCAAUtilService::ErrorMessage(CATUnicodeString("Error"), CATUnicodeString("Save FTZE failed,Plase check FTZE name!"));


	return TRUE;
}

CATBoolean CMCreateFTZWSystemCmd::ApplyAction(void *data)
{
	cout << "ZWConnectCmd::ApplyAction() - INFO: Entering ApplyAction()... " << endl;
	if (_ApplyAgent)
	{
		_ApplyAgent->InitializeAcquisition();
	}

	// check select 
	if (!CheckZWSelect())
	{
		return FALSE;
	}

	//input code null or code is repeat/ Check input
	if (CheckInputCode())
	{
		return FALSE;
	}

	// Create FTZW
	CreateDELFTZWSystem();
	CATUnicodeString strMsg = CAAUtility::PLMSave();

	return FALSE;
}

CATBoolean CMCreateFTZWSystemCmd::CancelAction(void *data)
{
	cout << "CMConnectCmd::CancelAction() - INFO: Entering CancelAction()... " << endl;

	if (_Panel != NULL)  _Panel->SetVisibility(CATDlgHide);

	return TRUE;
}