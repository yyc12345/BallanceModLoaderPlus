//////////////////////////////////
//////////////////////////////////
//
//        Hook Block
//
//////////////////////////////////
//////////////////////////////////
#include "CKAll.h"

#define BML_GUID CKGUID(0x3a086b4d, 0x2f4a4f01)

CKObjectDeclaration *FillBehaviorHookBlockDecl();

CKERROR CreateHookBlockProto(CKBehaviorPrototype **pproto);

int HookBlock(const CKBehaviorContext &behcontext);

CKObjectDeclaration *FillBehaviorHookBlockDecl() {
    CKObjectDeclaration *od = CreateCKObjectDeclaration("HookBlock");
    od->SetDescription("Hook building blocks");
    od->SetCategory("BML/Hook");
    od->SetType(CKDLL_BEHAVIORPROTOTYPE);
    od->SetGuid(CKGUID(0x19038c0, 0x663902da));
    od->SetAuthorGuid(BML_GUID);
    od->SetAuthorName("Kakuty");
    od->SetVersion(0x00010000);
    od->SetCreationFunction(CreateHookBlockProto);
    od->SetCompatibleClassId(CKCID_BEOBJECT);
    return od;
}

CKERROR CreateHookBlockProto(CKBehaviorPrototype **pproto) {
    CKBehaviorPrototype *proto = CreateCKBehaviorPrototype("HookBlock");
    if (!proto) return CKERR_OUTOFMEMORY;

    proto->DeclareLocalParameter("Callback", CKPGUID_POINTER);
    proto->DeclareLocalParameter("Argument", CKPGUID_POINTER);

    proto->SetBehaviorFlags((CK_BEHAVIOR_FLAGS) (CKBEHAVIOR_VARIABLEINPUTS | CKBEHAVIOR_VARIABLEOUTPUTS));
    proto->SetFlags(CK_BEHAVIORPROTOTYPE_NORMAL);
    proto->SetFunction(HookBlock);

    *pproto = proto;
    return CK_OK;
}

int HookBlock(const CKBehaviorContext &behcontext) {
    CKBehavior *beh = behcontext.Behavior;

    int i, count = beh->GetInputCount();
    for (i = 0; i < count; ++i) {
        beh->ActivateInput(i, FALSE);
    }

    typedef void (*Callback)(void *arg);
    Callback cb = nullptr;
    beh->GetLocalParameterValue(0, &cb);
    if (cb) {
        void *arg = nullptr;
        beh->GetLocalParameterValue(1, &arg);
        cb(arg);
    }

    count = beh->GetOutputCount();
    for (i = 0; i < count; ++i) {
        beh->ActivateOutput(i);
    }

    return CKBR_OK;
}