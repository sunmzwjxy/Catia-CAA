

// BEGIN OF HEADER CODE
// ----------------------------------------
    
#ifndef CMSystemJGDDlg_h
#define CMSystemJGDDlg_h

#include "CATDlgDialog.h"
class CATDlgFrame;
class CATDlgLabel;
class CATDlgLabel;
class CATDlgLabel;
class CATDlgLabel;
class CATDlgLabel;
class CATDlgLabel;
class CATDlgEditor;
class CATDlgEditor;
class CATDlgCombo;
class CATDlgEditor;
class CATDlgEditor;
class CATDlgEditor;

// Begin of User Code
enum COMJGDAssemDlg_ControlID
{
	ID_NameEditor,
	ID_WorkTypeEditor,
	ID_AirCraftNoEdiror,
	ID_VersionEditor,
	ID_CommentsEditor,
	ID_TypeCombo
};
// End of User Code

class  CMSystemJGDDlg : public CATDlgDialog {
DeclareResource(CMSystemJGDDlg, CATDlgDialog)

public:
	CMSystemJGDDlg(CATDialog * iParent, const CATString& iDialogName);
	
	virtual ~CMSystemJGDDlg();
	void Build();

	// Copy ctor and assignment operators are declared but not defined by infra
	CMSystemJGDDlg(const CMSystemJGDDlg&);
	CMSystemJGDDlg& operator= (const CMSystemJGDDlg&);
	
private:
CATDlgFrame* _Frame1;
CATDlgLabel* _Label1;
CATDlgLabel* _Label2;
CATDlgLabel* _Label3;
CATDlgLabel* _Label4;
CATDlgLabel* _Label5;
CATDlgLabel* _Label6;
CATDlgEditor* _Editor1;
CATDlgEditor* _Editor2;
CATDlgCombo* _Combo1;
CATDlgEditor* _Editor3;
CATDlgEditor* _Editor4;
CATDlgEditor* _Editor5;

// Begin of User Code
public:
CATDlgEditor* GetEditor(int iCtrlID);
CATDlgCombo* GetCombo(int iCtrlID);
// End of User Code

};

#endif
