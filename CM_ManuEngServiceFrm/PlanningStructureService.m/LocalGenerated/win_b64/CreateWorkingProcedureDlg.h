

// BEGIN OF HEADER CODE
// ----------------------------------------
    
#ifndef CreateWorkingProcedureDlg_h
#define CreateWorkingProcedureDlg_h

#include "CATDlgDialog.h"
class CATDlgLabel;
class CATDlgEditor;
class CATDlgLabel;
class CATDlgEditor;
class CATDlgFrame;
class CATDlgRadioButton;
class CATDlgRadioButton;
class CATDlgRadioButton;
class CATDlgCheckButton;

// Begin of User Code
#include "CATUnicodeString.h"
// End of User Code

class  CreateWorkingProcedureDlg : public CATDlgDialog {
DeclareResource(CreateWorkingProcedureDlg, CATDlgDialog)

public:
	CreateWorkingProcedureDlg(CATDialog * iParent, const CATString& iDialogName);
	
	virtual ~CreateWorkingProcedureDlg();
	void Build();

	// Copy ctor and assignment operators are declared but not defined by infra
	CreateWorkingProcedureDlg(const CreateWorkingProcedureDlg&);
	CreateWorkingProcedureDlg& operator= (const CreateWorkingProcedureDlg&);
	
private:
CATDlgLabel* _Label1;
CATDlgEditor* _Editor1;
CATDlgLabel* _Label3;
CATDlgEditor* _Editor2;
CATDlgFrame* _Frame1;
CATDlgRadioButton* _RadioButton2;
CATDlgRadioButton* _RadioButton1;
CATDlgRadioButton* _RadioButton3;
CATDlgCheckButton* _CheckButton1;

// Begin of User Code
public:
	void SetAOTitle(CATUnicodeString iTitle);
	CATUnicodeString GetGXTypeName();
	CATUnicodeString GetGXTtitle();
	CATBoolean IsReorder();
// End of User Code

};

#endif
