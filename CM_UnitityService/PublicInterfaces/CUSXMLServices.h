
//===================================================================
// COPYRIGHT DS 2018/05/31
//===================================================================
// CUSXMLServices.cpp
// Header definition of class CUSXMLServices
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2018/05/31 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CUSXMLServices_H
#define CUSXMLServices_H

#include "CUS_UtilFunc.h"
#include "CATBaseUnknown.h"
#include "CATIDOMDocument.h"
#include "CATUnicodeString.h"
#include "CATIXMLDOMDocumentBuilder.h"
#include "CATIDOMNode.h"

//-----------------------------------------------------------------------

class ExportedByCUS_UtilFunc CUSXMLServices: public CATBaseUnknown

{
CATDeclareClass;

public:

// Standard constructors and destructors
// -------------------------------------
CUSXMLServices ();
virtual ~CUSXMLServices ();
static HRESULT ReadXmlFile(CATUnicodeString iPath,CATIDOMDocument_var &oDoc,CATIXMLDOMDocumentBuilder_var & oBuilder);
static HRESULT ReadDeviceNodesFromXml(CATIDOMDocument_var &iDocument,CATIDOMNodeList_var &oListDeviceNode);
static HRESULT RemoveDeviceNodeFromXml(CATIDOMDocument* &iDocument,CATIDOMNode_var &iDeviceNode);
static HRESULT RemoveParameterNodeFromDevice(CATIDOMNode_var &iDeviceNode,CATIDOMNode_var &iParameter);
static HRESULT CheckDeviceinXML(CATIDOMNodeList_var &iListDeviceNode,CATUnicodeString& usrDeviceTitle,CATUnicodeString& usrNodeName,CATUnicodeString& usrTextName);
static HRESULT addXMLNode(const CATIDOMDocument_var& m_pXMLDoc,
						const CATIDOMElement_var& pParentElem,
						CATIDOMElement_var& iopNewElm,
						const CATUnicodeString    uName,
						const CATUnicodeString    uValue,
						const CATListOfCATUnicodeString listAttNames,
						const CATListOfCATUnicodeString listAttValues,
						CATBoolean flagHasSon );
static HRESULT  ModXMLNode(CATIDOMElement_var& ispModElm,
						   const CATListOfCATUnicodeString listAttNames, 
						   const CATListOfCATUnicodeString listAttValues);

static HRESULT ReadXmlStream(CATUnicodeString iXMLString, CATIDOMDocument_var &oDoc,
							CATIXMLDOMDocumentBuilder_var & oBuilder);

static CATUnicodeString GetNodeValue(CATIDOMNode_var spNode, CATUnicodeString iNodeAtt);

//
// TODO: Add your methods for this class here.
//

private:
// Copy constructor and equal operator
// -----------------------------------
};

//-----------------------------------------------------------------------

#endif

