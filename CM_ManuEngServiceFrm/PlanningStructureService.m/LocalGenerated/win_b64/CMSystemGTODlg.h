

// BEGIN OF HEADER CODE
// ----------------------------------------
    
#ifndef CMSystemGTODlg_h
#define CMSystemGTODlg_h

#include "CATDlgDialog.h"
class CATDlgLabel;
class CATDlgEditor;
class CATDlgEditor;
class CATDlgLabel;
class CATDlgLabel;
class CATDlgCombo;
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
enum COMGTOAssemDlg_ControlID
{
	ID_WorkLevelCombo,				//Combo1
	ID_SafetyidentifyCombo,			//Combo2
	ID_WorkAreaCombo,				//Combo3
	ID_SkillCombo,					//Combo4
	ID_CodeEditor,					//Editor1
	ID_NameEditor,					//Editor2
	ID_EffectivityEditor,			//Editor3
	ID_CommentsEditor				//Editor4
};
// End of User Code

class  CMSystemGTODlg : public CATDlgDialog {
DeclareResource(CMSystemGTODlg, CATDlgDialog)

public:
	CMSystemGTODlg(CATDialog * iParent, const CATString& iDialogName);
	
	virtual ~CMSystemGTODlg();
	void Build();

	// Copy ctor and assignment operators are declared but not defined by infra
	CMSystemGTODlg(const CMSystemGTODlg&);
	CMSystemGTODlg& operator= (const CMSystemGTODlg&);
	
private:
CATDlgLabel* _Label1;
CATDlgEditor* _Editor4;
CATDlgEditor* _Editor3;
CATDlgLabel* _Label8;
CATDlgLabel* _Label7;
CATDlgCombo* _Combo4;
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
