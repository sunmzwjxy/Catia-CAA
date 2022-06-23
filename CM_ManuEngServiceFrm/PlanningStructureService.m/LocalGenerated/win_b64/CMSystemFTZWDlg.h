

// BEGIN OF HEADER CODE
// ----------------------------------------
    
#ifndef CMSystemFTZWDlg_h
#define CMSystemFTZWDlg_h

#include "CATDlgDialog.h"
class CATDlgLabel;
class CATDlgLabel;
class CATDlgLabel;
class CATDlgLabel;
class CATDlgLabel;
class CATDlgEditor;
class CATDlgCombo;
class CATDlgEditor;
class CATDlgCombo;
class CATDlgEditor;

// Begin of User Code
enum COMACGTOAssemDlg_ControlID
{
	ID_PartCodeEditor,
	ID_NameEditor,
	ID_ValidEditor,
	ID_MachineCodeCombo,		// Combo2
	ID_JobStylesCombo			// Combo1
};
// End of User Code

class  CMSystemFTZWDlg : public CATDlgDialog {
DeclareResource(CMSystemFTZWDlg, CATDlgDialog)

public:
	CMSystemFTZWDlg(CATDialog * iParent, const CATString& iDialogName);
	
	virtual ~CMSystemFTZWDlg();
	void Build();

	// Copy ctor and assignment operators are declared but not defined by infra
	CMSystemFTZWDlg(const CMSystemFTZWDlg&);
	CMSystemFTZWDlg& operator= (const CMSystemFTZWDlg&);
	
private:
CATDlgLabel* _Label1;
CATDlgLabel* _Label2;
CATDlgLabel* _Label3;
CATDlgLabel* _Label4;
CATDlgLabel* _Label5;
CATDlgEditor* _Editor1;
CATDlgCombo* _Combo2;
CATDlgEditor* _Editor3;
CATDlgCombo* _Combo1;
CATDlgEditor* _Editor4;

// Begin of User Code
public:
CATDlgEditor* GetEditor(int iCtrlID);
CATDlgCombo* GetCombo(int iCtrlID);
// End of User Code

};

#endif
