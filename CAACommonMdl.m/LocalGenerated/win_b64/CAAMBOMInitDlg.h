

// BEGIN OF HEADER CODE
// ----------------------------------------
    
#ifndef CAAMBOMInitDlg_h
#define CAAMBOMInitDlg_h

#include "CATDlgDialog.h"
class CATDlgFrame;
class CATDlgLabel;
class CATDlgEditor;
class CATDlgFrame;
class CATDlgMultiList;

// Begin of User Code
#include "CATUnicodeString.h"
#include <vector>
class FOTask
{
public:
	CATUnicodeString MPRFormNum;
	CATUnicodeString MPRType;
	CATUnicodeString MPRRevision;
	CATUnicodeString MPRTime;
	CATUnicodeString PartNumber;
	CATUnicodeString PartRevision;
	CATUnicodeString FOName;
	CATUnicodeString FORevision;
	CATUnicodeString FODisRevision;
	CATUnicodeString FOState;
	CATUnicodeString MPRId;
	CATUnicodeString IsRevise;
};
// End of User Code

class  CAAMBOMInitDlg : public CATDlgDialog {
DeclareResource(CAAMBOMInitDlg, CATDlgDialog)

public:
	CAAMBOMInitDlg(CATDialog * iParent, const CATString& iDialogName);
	
	virtual ~CAAMBOMInitDlg();
	void Build();

	// Copy ctor and assignment operators are declared but not defined by infra
	CAAMBOMInitDlg(const CAAMBOMInitDlg&);
	CAAMBOMInitDlg& operator= (const CAAMBOMInitDlg&);
	
private:
CATDlgFrame* _Frame1;
CATDlgLabel* _Label1;
CATDlgEditor* _Editor1;
CATDlgFrame* _Frame2;
CATDlgMultiList* _MultiList1;

// Begin of User Code
public:
	void SetUserName(CATUnicodeString iUserName);
	void InitMultiList(std::vector<FOTask> foVect);
	int GetSelectRow();
// End of User Code

};

#endif
