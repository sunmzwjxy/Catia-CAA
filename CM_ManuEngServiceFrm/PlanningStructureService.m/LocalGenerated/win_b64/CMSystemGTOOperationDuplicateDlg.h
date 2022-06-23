

// BEGIN OF HEADER CODE
// ----------------------------------------
    
#ifndef CMSystemGTOOperationDuplicateDlg_h
#define CMSystemGTOOperationDuplicateDlg_h

#include "CATDlgDialog.h"
class CATDlgFrame;
class CATDlgEditor;
class CATDlgLabel;
class CATDlgLabel;
class CATDlgEditor;
class CATDlgEditor;
class CATDlgLabel;
class CATDlgPushButton;
class CATDlgFrame;
class CATDlgLabel;
class CATDlgLabel;
class CATDlgLabel;
class CATDlgPushButton;
class CATDlgPushButton;
class CATDlgPushButton;
class CATDlgSelectorList;
class CATDlgSelectorList;

// Begin of User Code
#include <vector>
#include <algorithm>
#include <functional>
#include "CATIPLMNavReference.h"
#include "CATIPLMNavInstance.h"
enum COMDuplicateGTOOPDlg_ControlID
{
	ID_GTOPartCodeEditor,					//CUS_GTOPart_PartCode
	ID_GTOPartNameEdiror,					//CUS_GTOPart_PartName
	ID_GTOTargetEditor,
	ID_GTOOperatoinsDupSelectorList,		//_SelectorList_GTOOperatoinsDup
	ID_GTOOperationsSelectorList,			//_SelectorList_GTOOperations
	ID_GTOSearchButton,						//_PushButton_Search;
	ID_GTOAddButton,						//_PushButton_Add;
	ID_GTODeleteButton,						//_PushButton_Delete;
	ID_GTODeleteAll							// _PushButton_DeleteAll;
};


struct DuplicateOPStruct
{
	DuplicateOPStruct(void)
	{
		this->isDuplicate = FALSE;
		this->pOperationOcc = NULL;
		this->pOperationRef = NULL;
		this->sOPExternalID = "";
		this->sOperationName = "";
	}
	DuplicateOPStruct(CATUnicodeString sOPExternalID)
	{
		this->isDuplicate = FALSE;
		this->sOPExternalID = sOPExternalID;
		this->sOperationName = "";
		this->pOperationOcc = NULL;
		this->pOperationRef = NULL;
	}
	CATBoolean operator() (DuplicateOPStruct& item)
	{
		if (this->sOPExternalID == item.sOPExternalID)
		{
			item.isDuplicate = TRUE;
			return TRUE;
		}
		return FALSE;
	}
	CATBoolean operator==(const DuplicateOPStruct& item)
	{
		if (this->sOPExternalID == item.sOPExternalID)
		{
			return TRUE;
		}
		return FALSE;
	}
	void operator= (const DuplicateOPStruct& item)
	{
		this->isDuplicate = FALSE;
		this->pOperationOcc = item.pOperationOcc;
		this->pOperationRef = item.pOperationRef;
		this->sOPExternalID = item.sOPExternalID;
		this->sOperationName = item.sOperationName;
	}
	CATIPLMNavOccurrence* pOperationOcc;
	CATIPLMNavReference* pOperationRef;
	CATUnicodeString	sOPExternalID;
	CATUnicodeString	sOperationName;
	CATBoolean			isDuplicate;
};
typedef std::vector<DuplicateOPStruct> VECDUPOpeartion;
typedef VECDUPOpeartion::iterator	VEC_DUPOperation_ITER;
// End of User Code

class  CMSystemGTOOperationDuplicateDlg : public CATDlgDialog {
DeclareResource(CMSystemGTOOperationDuplicateDlg, CATDlgDialog)

public:
	CMSystemGTOOperationDuplicateDlg(CATDialog * iParent, const CATString& iDialogName);
	
	virtual ~CMSystemGTOOperationDuplicateDlg();
	void Build();

	// Copy ctor and assignment operators are declared but not defined by infra
	CMSystemGTOOperationDuplicateDlg(const CMSystemGTOOperationDuplicateDlg&);
	CMSystemGTOOperationDuplicateDlg& operator= (const CMSystemGTOOperationDuplicateDlg&);
	
private:
CATDlgFrame* _Frame1;
CATDlgEditor* _Editor_GTOName;
CATDlgLabel* _Label2;
CATDlgLabel* _Label6;
CATDlgEditor* _Editor_GTOTarget;
CATDlgEditor* _Editor_GTOCode;
CATDlgLabel* _Label1;
CATDlgPushButton* _PushButton_Search;
CATDlgFrame* _Frame2;
CATDlgLabel* _Label4;
CATDlgLabel* _Label5;
CATDlgLabel* _Label3;
CATDlgPushButton* _PushButton_DeleteAll;
CATDlgPushButton* _PushButton_Delete;
CATDlgPushButton* _PushButton_Add;
CATDlgSelectorList* _SelectorList_GTOOperatoinsDup;
CATDlgSelectorList* _SelectorList_GTOOperations;

// Begin of User Code
public:
	CATDlgEditor* GetEditor(int iCtrlID);
	CATDlgSelectorList* GetSelector(int iCtrlID);
	CATDlgPushButton* GetPushBtn(int iCtrlID);
// End of User Code

};

#endif
