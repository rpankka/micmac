// File Automatically generated by eLiSe
#include "general/all.h"
#include "private/all.h"


class cEqAppui_PTInc_C2MPolyn3: public cElCompiledFonc
{
   public :

      cEqAppui_PTInc_C2MPolyn3();
      void ComputeVal();
      void ComputeValDeriv();
      void ComputeValDerivHessian();
      double * AdrVarLocFromString(const std::string &);
      void SetPolyn3_State_0_0(double);
      void SetXIm(double);
      void SetYIm(double);


      static cAutoAddEntry  mTheAuto;
      static cElCompiledFonc *  Alloc();
   private :

      double mLocPolyn3_State_0_0;
      double mLocXIm;
      double mLocYIm;
};