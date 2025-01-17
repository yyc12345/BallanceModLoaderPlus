#ifndef BML_EXECUTEBB_H
#define BML_EXECUTEBB_H

#include <utility>

#include "CKAll.h"

#include "Export.h"

#define TEXT_SCREEN        1
#define TEXT_BACKGROUND    2
#define TEXT_CLIP          4
#define TEXT_RESIZE_VERT   8
#define TEXT_RESIZE_HORI   16
#define TEXT_WORDWRAP      32
#define TEXT_JUSTIFIED     64
#define TEXT_COMPILED      128
#define TEXT_MULTIPLE      256
#define TEXT_SHOWCARET     512
#define TEXT_3D            1024
#define TEXT_SCREENCLIP    2048

#define ALIGN_CENTER       0
#define ALIGN_LEFT         1
#define ALIGN_RIGHT        2
#define ALIGN_TOP          4
#define ALIGN_TOPLEFT      5
#define ALIGN_TOPRIGHT     6
#define ALIGN_BOTTOM       8
#define ALIGN_BOTTOMLEFT   9
#define ALIGN_BOTTOMRIGHT  10

namespace ExecuteBB {
    enum FontType {
        NOFONT,
        GAMEFONT_01,            // Normal
        GAMEFONT_02,            // Larger
        GAMEFONT_03,            // Small
        GAMEFONT_03A,           // Small, Gray
        GAMEFONT_04,            // Large
        GAMEFONT_CREDITS_SMALL,
        GAMEFONT_CREDITS_BIG
    };

    BML_EXPORT void PhysicalizeConvex(CK3dEntity *target = nullptr, CKBOOL fixed = false, float friction = 0.7f,
                                      float elasticity = 0.4f, float mass = 1.0f, const char *collGroup = "",
                                      CKBOOL startFrozen = false, CKBOOL enableColl = true,
                                      CKBOOL calcMassCenter = false, float linearDamp = 0.1f, float rotDamp = 0.1f,
                                      const char *collSurface = "", VxVector massCenter = VxVector(0, 0, 0),
                                      CKMesh *mesh = nullptr);

    BML_EXPORT void PhysicalizeBall(CK3dEntity *target = nullptr, CKBOOL fixed = false, float friction = 0.7f,
                                    float elasticity = 0.4f, float mass = 1.0f, const char *collGroup = "",
                                    CKBOOL startFrozen = false, CKBOOL enableColl = true, CKBOOL calcMassCenter = false,
                                    float linearDamp = 0.1f, float rotDamp = 0.1f, const char *collSurface = "",
                                    VxVector massCenter = VxVector(0, 0, 0), VxVector ballCenter = VxVector(0, 0, 0),
                                    float ballRadius = 2.0f);

    BML_EXPORT void PhysicalizeConcave(CK3dEntity *target = nullptr, CKBOOL fixed = false, float friction = 0.7f,
                                       float elasticity = 0.4f, float mass = 1.0f, const char *collGroup = "",
                                       CKBOOL startFrozen = false, CKBOOL enableColl = true,
                                       CKBOOL calcMassCenter = false, float linearDamp = 0.1f, float rotDamp = 0.1f,
                                       const char *collSurface = "", VxVector massCenter = VxVector(0, 0, 0),
                                       CKMesh *mesh = nullptr);

    BML_EXPORT void Unphysicalize(CK3dEntity *target);

    BML_EXPORT void SetPhysicsForce(CK3dEntity *target = nullptr,
                                    VxVector position = VxVector(0, 0, 0), CK3dEntity *posRef = nullptr,
                                    VxVector direction = VxVector(0, 0, 0), CK3dEntity *directionRef = nullptr,
                                    float force = 0.0f);

    BML_EXPORT void UnsetPhysicsForce(CK3dEntity *target = nullptr);

    BML_EXPORT void PhysicsImpulse(CK3dEntity *target = nullptr,
                                   VxVector position = VxVector(0, 0, 0), CK3dEntity *posRef = nullptr,
                                   VxVector direction = VxVector(0, 0, 0), CK3dEntity *dirRef = nullptr,
                                   float impulse = 0.0f);

    BML_EXPORT void PhysicsWakeUp(CK3dEntity *target = nullptr);

    BML_EXPORT ::std::pair<XObjectArray *, CKObject *> ObjectLoad(const char *file = "", bool rename = true,
                                                                  const char *mastername = "",
                                                                  CK_CLASSID filter = CKCID_3DOBJECT,
                                                                  CKBOOL addToScene = true, CKBOOL reuseMesh = true,
                                                                  CKBOOL reuseMtl = true, CKBOOL dynamic = true);

    BML_EXPORT CKBehavior *Create2DText(CKBehavior *script, CK2dEntity *target = nullptr, FontType font = NOFONT, const char *text = "",
                                        int align = ALIGN_CENTER, VxRect margin = {2, 2, 2, 2},
                                        Vx2DVector offset = {0, 0}, Vx2DVector pindent = {0, 0},
                                        CKMaterial *bgmat = nullptr,float caretsize = 0.1f,
                                        CKMaterial *caretmat = nullptr, int flags = TEXT_SCREEN);

    BML_EXPORT CKBehavior *CreatePhysicalizeConvex(CKBehavior *script, CK3dEntity *target = nullptr, CKBOOL fixed = false,
                                                   float friction = 0.7f, float elasticity = 0.4f, float mass = 1.0f,
                                                   const char *collGroup = "", CKBOOL startFrozen = false,
                                                   CKBOOL enableColl = true, CKBOOL calcMassCenter = false,
                                                   float linearDamp = 0.1f, float rotDamp = 0.1f,
                                                   const char *collSurface = "", VxVector massCenter = VxVector(0, 0, 0),
                                                   CKMesh *mesh = nullptr);

    BML_EXPORT CKBehavior *CreatePhysicalizeBall(CKBehavior *script, CK3dEntity *target = nullptr, CKBOOL fixed = false,
                                                 float friction = 0.7f, float elasticity = 0.4f, float mass = 1.0f,
                                                 const char *collGroup = "", CKBOOL startFrozen = false,
                                                 CKBOOL enableColl = true, CKBOOL calcMassCenter = false,
                                                 float linearDamp = 0.1f, float rotDamp = 0.1f,
                                                 const char *collSurface = "", VxVector massCenter = VxVector(0, 0, 0),
                                                 VxVector ballCenter = VxVector(0, 0, 0), float ballRadius = 2.0f);

    BML_EXPORT CKBehavior *CreatePhysicalizeConcave(CKBehavior *script, CK3dEntity *target = nullptr, CKBOOL fixed = false,
                                                    float friction = 0.7f, float elasticity = 0.4f, float mass = 1.0f,
                                                    const char *collGroup = "", CKBOOL startFrozen = false,
                                                    CKBOOL enableColl = true, CKBOOL calcMassCenter = false,
                                                    float linearDamp = 0.1f, float rotDamp = 0.1f,
                                                    const char *collSurface = "", VxVector massCenter = VxVector(0, 0, 0),
                                                    CKMesh *mesh = nullptr);

    BML_EXPORT CKBehavior *CreateSetPhysicsForce(CKBehavior *script, CK3dEntity *target = nullptr,
                                                 VxVector position = VxVector(0, 0, 0), CK3dEntity *posRef = nullptr,
                                                 VxVector direction = VxVector(0, 0, 0), CK3dEntity *directionRef = nullptr,
                                                 float force = 0.0f);

    BML_EXPORT CKBehavior *CreatePhysicsImpulse(CKBehavior *script, CK3dEntity *target = nullptr,
                                                VxVector position = VxVector(0, 0, 0), CK3dEntity *posRef = nullptr,
                                                VxVector direction = VxVector(0, 0, 0), CK3dEntity *dirRef = nullptr,
                                                float impulse = 0.0f);

    BML_EXPORT CKBehavior *CreatePhysicsWakeUp(CKBehavior *script, CK3dEntity *target = nullptr);

    BML_EXPORT CKBehavior *CreateObjectLoad(CKBehavior *script, const char *file = "", const char *mastername = "",
                                            CK_CLASSID filter = CKCID_3DOBJECT, CKBOOL addToScene = true,
                                            CKBOOL reuseMesh = true, CKBOOL reuseMtl = true, CKBOOL dynamic = true);

    BML_EXPORT CKBehavior *CreateSendMessage(CKBehavior *script, const char *msg, CKBeObject *dest);

    typedef int (*CKBehaviorCallback)(const CKBehaviorContext *behcontext, void *arg);
    BML_EXPORT CKBehavior *CreateHookBlock(CKBehavior *script, CKBehaviorCallback callback, void *arg = nullptr, int inCount = 1, int outCount = 1);
}

#endif // BML_EXECUTEBB_H