//===================================================================
// COPYRIGHT  2022/02/14
//===================================================================
// CMDuplicateGTOOperationCmd.cpp
// Header definition of class CMDuplicateGTOOperationCmd
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2022/02/14 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CMDuplicateGTOOperationCmd_H
#define CMDuplicateGTOOperationCmd_H

#include "CATStateCommand.h"
#include "CATSysBoolean.h"

#include "CMSystemGTOOperationDuplicateDlg.h "

#include "CATIPLMNavReference.h"
#include "CATIPLMNavOccurrence.h"
#include "CATIPLMNavRepInstance.h"
#include "CATListPtrCATIPLMNavEntity.h"
#include "CATPathElementAgent.h"
#include "CATOtherDocumentAgent.h"
#include "CATIMmiMechanicalFeature.h"
#include "CATIMmiUseCreateImport.h"
#include "CATMmiUseServicesFactory.h"
#include "CATAdpDuplicator.h"
#include "CATAdpComponentsAssociation.h"
#include "DELPPRResourceNavAccess.h"
#include "DELIPPRResourceNav.h"
//----------------------------------------------------------------------

/**
* Describe your command here.
* <p>
* Using this prefered syntax will enable mkdoc to document your class.
* <p>
* refer to programming resources of Dialog engine framework.
* (consult base class description).
*/
class CMDuplicateGTOOperationCmd: public CATStateCommand
{
// Allows customization/internationalization of command's messages
// ---------------------------------------------------------------
DeclareResource( CMDuplicateGTOOperationCmd, CATStateCommand )

public:
	CMDuplicateGTOOperationCmd();
virtual ~CMDuplicateGTOOperationCmd();

/**
* Defines the command automata.
* <br>
* <i>(states, transitions and agents)</i>
*/
virtual void     BuildGraph();

/**
* Action associated to state transitions.
*/
virtual CATBoolean  ActionOne(void * data);

virtual CATBoolean OKAction(void *data);

virtual CATBoolean ApplyAction(void *data);

virtual CATBoolean CancelAction(void *data);

CATBoolean SelectSourceElement(void *data);
CATBoolean SelectTargetElement(void *data);
CATBoolean SelectionCheck();
CATBoolean SelectionSourceCheck();


void PushButtonSearch_Pressed(void * data);
void PushButton_Add_Pressed(void * data);
void PushButton_Delete_Pressed(void * data);
void PushButton_DeleteAll_Pressed(void * data);

void DuplicateOP();
HRESULT insertOP(DuplicateOPStruct newOP);
void ReBuildOperationRelationShip(CATIPLMNavOccurrence_var spSourceOperationOcc, CATIPLMNavOccurrence_var spNewOperationOcc);


private:
	CMSystemGTOOperationDuplicateDlg * _Panel;		// Duplicate GTO Op Dialog

	CATDialogAgent *_OKAgent;		// OK Button
	CATDialogAgent *_ApplyAgent;	// Apply Button
	CATDialogAgent *_CloseAgent;	// Close Button
	CATDialogAgent *_CancleAgent;	// Cancel Button

	CATDlgPushButton *PushSearchButton;	// Push Search Button
	CATDlgPushButton *PushAddButton;
	CATDlgPushButton *PushDeleteButton;
	CATDlgPushButton *PushDeleteAllButton;

	CATOtherDocumentAgent * _pSelectSourceAgent;				// Source
	CATPathElementAgent* _pSelectAgent;			// Target  


	CATDialogState * pSelectionState;
	CATDialogState *stSecondState;

	CATIPLMNavReference * pZWFatherRef;
	CATIPLMNavOccurrence * pZWFatherOcc;

	VECDUPOpeartion m_vecOperation;

};

//----------------------------------------------------------------------

#endif
