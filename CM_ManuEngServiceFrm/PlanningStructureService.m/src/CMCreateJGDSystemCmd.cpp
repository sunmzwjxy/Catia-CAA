//===================================================================
// COPYRIGHT  2022/02/10
//===================================================================
// CMCreateJGDSystemCmd.cpp
// Header definition of class CMCreateJGDSystemCmd
//===================================================================
//
// Usage notes: Create JGD
//
//===================================================================
//  2022/02/10 Creation: Code generated by the 3DS wizard
//===================================================================

#include "CMCreateJGDSystemCmd.h"

#include "CATCreateExternalObject.h"
CATCreateClass( CMCreateJGDSystemCmd);

#include "CUSCAAUtilService.h"
#include "PPRUtity.h"
#include "CAAUtility.h"

//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
CMCreateJGDSystemCmd::CMCreateJGDSystemCmd() :
CATStateCommand ("CMCreateJGDSystemCmd", CATDlgEngOneShot, CATCommandModeShared)
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
, _OKAgent(NULL),
_ApplyAgent(NULL),
_CloseAgent(NULL),
_CancleAgent(NULL)
{
	CATDlgWindow *pWnd = (CATApplicationFrame::GetFrame())->GetMainWindow();
	_Panel = new CMSystemJGDDlg(pWnd, "JGD System");
	_Panel->Build();
	_Panel->SetFather(this);

	pZWFatherRef = nullptr;
	pZWFatherOcc = nullptr;
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
CMCreateJGDSystemCmd::~CMCreateJGDSystemCmd()
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
void CMCreateJGDSystemCmd::BuildGraph()
{
// TODO: Define the StateChart
// ---------------------------
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

	CATAcquisitionFilter* pFilter = Filter((FilterMethod)&CMCreateJGDSystemCmd::SelectionCheck, (void*)NULL);
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
	AddTransition(pSelectionState, NULL, AndCondition(IsOutputSetCondition(_OKAgent), Condition((ConditionMethod)&CMCreateJGDSystemCmd::OKAction)), NULL);

	// Transition from Input state to NULL, when click on Cancel button
	AddTransition(pSelectionState, pSelectionState, IsOutputSetCondition(_ApplyAgent), Action((ActionMethod)&CMCreateJGDSystemCmd::ApplyAction));

	// Transition from Input state to NULL, when click on Close button
	AddTransition(pSelectionState, NULL, IsOutputSetCondition(_CloseAgent), Action((ActionMethod)&CMCreateJGDSystemCmd::CancelAction));

	AddTransition(pSelectionState, NULL, IsOutputSetCondition(_CancleAgent), Action((ActionMethod)&CMCreateJGDSystemCmd::CancelAction));

	AddTransition(pSelectionState, pSelectionState, IsOutputSetCondition(_pSelectAgent), Action((ActionMethod)&CMCreateJGDSystemCmd::ElementSelection, NULL, NULL, (void*)1));


	CUSCAAUtilService::ShowComboValue(_Panel->GetCombo(ID_TypeCombo), "CMSystemJGDDlg", "JGDCode.Range", ",");

// 	_Panel->SetVisibility(CATDlgShow);

}

HRESULT CMCreateJGDSystemCmd::CreateDELJGDSystem()
{
	if (pZWFatherRef == NULL)
	{
		CATUnicodeString Title = CATMsgCatalog::BuildMessage((CATString)"CMSystemJGDDlg", (CATString)"msg.Title");
		CATUnicodeString msg = CATMsgCatalog::BuildMessage((CATString)"CMSystemJGDDlg", (CATString)"msg.nodeFatherNull");
		CUSCAAUtilService::ErrorMessage(Title, msg);
		return S_FALSE;
	}

	PPRUtity spPPRUtity;
	CATIPLMNavInstance * spNewGTOSystemInstance = nullptr;
	HRESULT rc = spPPRUtity.CreateSubSystemOrOperation("CUS_HeaderOperation_JGD",
		pZWFatherRef, spNewGTOSystemInstance);


	if (spNewGTOSystemInstance == NULL) {
		cout << "Failed to create operation under the system" << endl;
		return S_FALSE;
	}

	CATIPLMNavReference * spNewJGDSystemRef = nullptr;
	rc = spNewGTOSystemInstance->GetReferenceInstanceOf(spNewJGDSystemRef);
	if (spNewJGDSystemRef == NULL)
	{
		cout << "Failed to Get new AO system Reference" << endl;
		return S_FALSE;
	}

/*
ID_NameEditor,
ID_WorkTypeEditor,
ID_AirCraftNoEdiror,
ID_VersionEditor,
ID_CommentsEditor,
ID_TypeCombo
*/

	CATDlgEditor *pCodeEditor = _Panel->GetEditor(ID_NameEditor);
	CATUnicodeString sInputName = pCodeEditor->GetText();

	CATDlgEditor *pWorkTypeEditor = _Panel->GetEditor(ID_WorkTypeEditor);
	CATUnicodeString sInputWorkType = pWorkTypeEditor->GetText();

	CATDlgEditor *pAirCraftNoEditor = _Panel->GetEditor(ID_AirCraftNoEdiror);
	CATUnicodeString sInputAirCraftNo = pAirCraftNoEditor->GetText();

	CATDlgEditor *pVersionEditor = _Panel->GetEditor(ID_VersionEditor);
	CATUnicodeString sInputVersion = pVersionEditor->GetText();

	CATDlgEditor *pCommentsEditor = _Panel->GetEditor(ID_CommentsEditor);
	CATUnicodeString sInputComments = pCommentsEditor->GetText();

	CATUnicodeString sInputComboTypes = CUSCAAUtilService::GetSelectComboValue(_Panel->GetCombo(ID_TypeCombo));
	CATUnicodeString sInputTypes = "";
	if (sInputComboTypes == "CR929")
		sInputTypes = "W";
	else if (sInputComboTypes == "C919")
		sInputTypes = "C";
	else sInputTypes = "A";


	CATUnicodeString sInputCode = "JGD" + sInputTypes + sInputAirCraftNo;

	// Query JGD type from DB
	CATListOfCATUnicodeString olistExistID;
	rc = CUSCAAUtilService::QueryDBExistID("CUS_HeaderOperation_JGD", sInputCode + "*", olistExistID);
	if (FAILED(rc) && olistExistID.Size() <= 0)
	{
		CUSCAAUtilService::ErrorMessage(CATUnicodeString("Info"), CATUnicodeString("Query JGD sequence number failed!"));
		return S_FALSE;
	}


	CATUnicodeString sSequenceNo("");
	sSequenceNo.BuildFromNum(olistExistID.Size() + 1, "%04d");
	sInputCode = sInputCode + sSequenceNo;

	//rc = CUSCAAUtilService::SetObjectAttrString(spNewGTOSystemRef, "CUS_Code", sInputCode);	// merge

	rc = CUSCAAUtilService::SetObjectAttrString(spNewJGDSystemRef, "PLM_ExternalID", sInputCode);

	rc = CUSCAAUtilService::SetObjectAttrString(spNewJGDSystemRef, "CUS_JGD_Name", sInputName);
	rc = CUSCAAUtilService::SetObjectAttrString(spNewJGDSystemRef, "CUS_JGD_Card", sInputCode);

	rc = CUSCAAUtilService::SetObjectAttrString(spNewJGDSystemRef, "V_Name", sInputCode);

	rc = CUSCAAUtilService::SetObjectAttrString(spNewJGDSystemRef, "CUS_JGD_WORKTYPE", sInputWorkType);

	rc = CUSCAAUtilService::SetObjectAttrString(spNewJGDSystemRef, "CUS_JGD_EFF", sInputAirCraftNo);

// 	rc = CUSCAAUtilService::SetObjectAttrString(spNewJGDSystemRef, "revision", sInputVersion);
	rc = CUSCAAUtilService::SetObjectAttrString(spNewJGDSystemRef, "V_description", sInputComments);

	rc = CUSCAAUtilService::SetObjectAttrString(spNewJGDSystemRef, "CUS_ReleaseStatus", "PendingRelease");		//


	CUSCAAUtilService::SetObjectAttrString(spNewJGDSystemRef, "CUS_JGD_Type", sInputComboTypes);

	CATUnicodeString strMsg = CAAUtility::PLMSave();
	return rc;

}

CATBoolean CMCreateJGDSystemCmd::ElementSelection(void * data)
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

void CMCreateJGDSystemCmd::FilterSelectObject()
{
	/*
	ID_NameEditor,
	ID_WorkTypeEditor,
	ID_AirCraftNoEdiror,
	ID_VersionEditor,
	ID_CommentsEditor,
	ID_TypeCombo
	*/
	CATUnicodeString sSelectObjectType = CUSCAAUtilService::GetObjectKnowledgeType(_pSelectedReference);
// 	if (sSelectObjectType == "DELLmiWorkPlanSystemReference" || )
	{
		pZWFatherOcc = _pSelectedOccurrence;
		pZWFatherRef = _pSelectedReference;

// 		CATDlgEditor *pZWFaEditor = _Panel->GetEditor(ID_NameEditor);
// 		pZWFaEditor->SetText(CUSCAAUtilService::GetAliasName(pZWFatherRef));

		_Panel->SetVisibility(CATDlgShow);

	}
}

CATBoolean CMCreateJGDSystemCmd::SelectionCheck()
{
	CATPathElement *pPath = _pSelectAgent->GetValue();
	CATIPLMNavOccurrence* piOccurrence = (CATIPLMNavOccurrence*)(pPath->FindElement(IID_CATIPLMNavOccurrence));
	if (piOccurrence == NULL)
	{
		return FALSE;
	}
	CATIPLMNavReference *piNavReference = nullptr;
	piOccurrence->GetRelatedReference(piNavReference);
	if (piNavReference == NULL)
	{
		return FALSE;
	}

	CATUnicodeString strObjType = CAAUtility::GetObjectTypeName(piNavReference);

	if (strObjType != "DELLmiWorkPlanSystemReference" && strObjType != "CUS_Workplan_FTZW")
	{
		return FALSE;
	}

	return TRUE;
}


CATBoolean CMCreateJGDSystemCmd::CheckInputCode()
{

	/*
	ID_NameEditor,
	ID_WorkTypeEditor,
	ID_AirCraftNoEdiror,
	ID_VersionEditor,
	ID_CommentsEditor,
	ID_TypeCombo
	*/
	// begin code 
	CATDlgEditor *pNameEditor = _Panel->GetEditor(ID_NameEditor);
	CATUnicodeString sInputName = pNameEditor->GetText();

	CATDlgEditor *pAirCraftNoEditor = _Panel->GetEditor(ID_AirCraftNoEdiror);
	CATUnicodeString sInputAirCraftNo = pAirCraftNoEditor->GetText();


	if (sInputName == "" || sInputAirCraftNo == "")
	{
		CATUnicodeString Title = CATMsgCatalog::BuildMessage((CATString)"CMSystemJGDDlg", (CATString)"msg.Title");
		CATUnicodeString msg = CATMsgCatalog::BuildMessage((CATString)"CMSystemJGDDlg", (CATString)"msg.nodeFatherNull");
		CUSCAAUtilService::ErrorMessage(Title, msg);
		return TRUE;
	}

	if (sInputAOExternalID == sInputName)
	{
		CATUnicodeString Title = CATMsgCatalog::BuildMessage((CATString)"CMSystemJGDDlg", (CATString)"msg.Title");
		CATUnicodeString msg = CATMsgCatalog::BuildMessage((CATString)"CMSystemJGDDlg", (CATString)"msg.nodeFatherNull");
		CUSCAAUtilService::ErrorMessage(Title, msg);
		return TRUE;
	}

	sInputAOExternalID = sInputName;

	return FALSE;

}

//-------------------------------------------------------------------------
// ActionOne ()
//-------------------------------------------------------------------------
CATBoolean CMCreateJGDSystemCmd::ActionOne( void *data )
{
// TODO: Define the action associated with the transition
// ------------------------------------------------------

return TRUE;
}

CATBoolean CMCreateJGDSystemCmd::OKAction(void *data)
{
	cout << "ZWConnectCmd::OKAction() - INFO: Entering OKAction()... " << endl;
	if (_OKAgent)
	{
		_OKAgent->InitializeAcquisition();
	}

	// check input
	if (CheckInputCode())
	{
		return FALSE;
	}

	CreateDELJGDSystem();

	return TRUE;
}

CATBoolean CMCreateJGDSystemCmd::ApplyAction(void *data)
{
	cout << "JGDConnectCmd::ApplyAction() - INFO: Entering ApplyAction()... " << endl;
	if (_ApplyAgent)
	{
		_ApplyAgent->InitializeAcquisition();
	}

	// check input
	if (CheckInputCode())
	{
		return FALSE;
	}

	CreateDELJGDSystem();

	return FALSE;
}

CATBoolean CMCreateJGDSystemCmd::CancelAction(void *data)
{
	cout << "CMConnectCmd::CancelAction() - INFO: Entering CancelAction()... " << endl;

	if (_Panel != NULL)  _Panel->SetVisibility(CATDlgHide);

	return TRUE;
}
