

// BEGIN OF HEADER CODE
// ----------------------------------------
    
#ifndef CMSystemGTOBOMDlg_h
#define CMSystemGTOBOMDlg_h

#include "CATDlgDialog.h"
class CATDlgLabel;
class CATDlgEditor;
class CATDlgLabel;
class CATDlgEditor;
class CATDlgLabel;
class CATDlgCombo;
class CATDlgLabel;
class CATDlgCombo;
class CATDlgLabel;
class CATDlgCombo;
class CATDlgLabel;
class CATDlgEditor;
class CATDlgLabel;
class CATDlgEditor;

// Begin of User Code
enum {
	ID_NumberEditor,			//CUS_GTOPart_PartCode
	ID_PartNameEditor,			//CUS_GTOPart_PartName
	ID_VersionEditor,			//
	ID_DescriptionEditor,		//CUS_GTOPart_Description
	ID_PartCodeCombo,			//CUS_GTOPart_Number
	ID_MFGDEPTCombo,			//CUS_GTOPart_Department
	ID_APLDEPTCombo				//CUS_GTOPart_Application
};
// End of User Code

class  CMSystemGTOBOMDlg : public CATDlgDialog {
DeclareResource(CMSystemGTOBOMDlg, CATDlgDialog)

public:
	CMSystemGTOBOMDlg(CATDialog * iParent, const CATString& iDialogName);
	
	virtual ~CMSystemGTOBOMDlg();
	void Build();

	// Copy ctor and assignment operators are declared but not defined by infra
	CMSystemGTOBOMDlg(const CMSystemGTOBOMDlg&);
	CMSystemGTOBOMDlg& operator= (const CMSystemGTOBOMDlg&);
	
private:
CATDlgLabel* _Label1;
CATDlgEditor* _Editor4;
CATDlgLabel* _Label7;
CATDlgEditor* _Editor3;
CATDlgLabel* _Label6;
CATDlgCombo* _Combo3;
CATDlgLabel* _Label5;
CATDlgCombo* _Combo2;
CATDlgLabel* _Label4;
CATDlgCombo* _Combo1;
CATDlgLabel* _Label3;
CATDlgEditor* _Editor2;
CATDlgLabel* _Label2;
CATDlgEditor* _Editor1;

// Begin of User Code
public:
	CATDlgEditor* GetEditor(int iCtrlID);
	CATDlgCombo* GetCombo(int iCtrlID);
// End of User Code

};

#endif
