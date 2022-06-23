//===================================================================
// COPYRIGHT  2022/03/01
//===================================================================
// CMSampleMultiDocumentGTOOperationCmd.cpp
// Header definition of class CMSampleMultiDocumentGTOOperationCmd
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2022/03/01 Creation: Code generated by the 3DS wizard
//===================================================================

#include "CMSampleMultiDocumentGTOOperationCmd.h"
#include "CAAUtility.h"

#include "CATCreateExternalObject.h"
CATCreateClass( CMSampleMultiDocumentGTOOperationCmd);


//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
CMSampleMultiDocumentGTOOperationCmd::CMSampleMultiDocumentGTOOperationCmd()
// CATStateCommand ("CMSampleMultiDocumentGTOOperationCmd", CATDlgEngOneShot, CATCommandModeShared)
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
{
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
CMSampleMultiDocumentGTOOperationCmd::~CMSampleMultiDocumentGTOOperationCmd()
{
}


//-------------------------------------------------------------------------
// BuildGraph()
//-------------------------------------------------------------------------
void CMSampleMultiDocumentGTOOperationCmd::BuildGraph()
{


// TODO: Define the StateChart
// ---------------------------
// _Indication = new CATIndicationAgent ("Indication");
// CATMathPlane PlaneXY;
// _Indication -> SetMathPlane (PlaneXY);
// CATDialogState * initialState = GetInitialState("initialState");
// initialState -> AddDialogAgent (_Indication);
// 
// AddTransition( initialState, NULL,
// IsOutputSetCondition (_Indication),
// Action ((ActionMethod) &statecmd::ActionOne));

		// Define the selection agent
	_AcquisitionAgent = new CATPathElementAgent("SelectionAgent");

	// Define the behaviors
	_AcquisitionAgent->SetBehavior(CATDlgEngWithCSO | CATDlgEngWithPrevaluation | CATDlgEngNewHSOManager);   //CATDlgEngMultiAcquisitionCtrl

	CATAcquisitionFilter* pFilter = Filter((FilterMethod)&CMSampleMultiDocumentGTOOperationCmd::SelectionCheck, (void*)NULL);
	_AcquisitionAgent->SetFilter(pFilter);

	AddCSOClient(_AcquisitionAgent);

	CATDialogState * pInitialState = GetInitialState("ElementSelection");
	pInitialState->AddDialogAgent(_AcquisitionAgent);

	CATDialogTransition *pTransition = AddTransition(pInitialState,NULL,NULL,Action((ActionMethod)&CMSampleMultiDocumentGTOOperationCmd::ActionOne));

}

CATBoolean CMSampleMultiDocumentGTOOperationCmd::SelectionCheck()
{
	CATPathElement *pPath = _AcquisitionAgent->GetValue();
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

	if (strObjType != "CUS_HeaderOperation_GTO" && strObjType != "CUS_HeaderOperation_JGD")
	{
		return FALSE;
	}

	return TRUE;
}

//-------------------------------------------------------------------------
// ActionOne ()
//-------------------------------------------------------------------------
CATBoolean CMSampleMultiDocumentGTOOperationCmd::ActionOne( void *data )
{
// TODO: Define the action associated with the transition
// ------------------------------------------------------
	CATBoolean OKCode = FALSE;

	if (_AcquisitionAgent != NULL)
	{
		CATIPLMNavReference * _pSelectedReference = NULL;

		CATPathElement * pPathElement = _AcquisitionAgent->GetValue();

		if (pPathElement != NULL)
		{
			CATBaseUnknown * _pSelectedElement = NULL;
			CATIPLMNavOccurrence * _pSelectedOccurrence = NULL;
			_pSelectedElement = pPathElement->FindElement(IID_CATBaseUnknown);
			_pSelectedOccurrence = (CATIPLMNavOccurrence*)(pPathElement->FindElement(IID_CATIPLMNavOccurrence));
			if (_pSelectedOccurrence != NULL)
			{
				_pSelectedOccurrence->GetRelatedReference(_pSelectedReference);

				if (_pSelectedReference != NULL)
				{
					CATUnicodeString strObjType = CAAUtility::GetObjectTypeName(_pSelectedReference);
					if (strObjType == "CUS_HeaderOperation_GTO" || strObjType == "CUS_HeaderOperation_JGD")
					{
						ReturnValue(_AcquisitionAgent->GetValue());
						OKCode = TRUE;
					}

				}
			}

		}

	}


	return OKCode;
}