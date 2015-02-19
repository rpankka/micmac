#ifndef _ELISE_GENERAL_PHGR_FORMEL_CELEMEQFORMELLE_H
#define _ELISE_GENERAL_PHGR_FORMEL_CELEMEQFORMELLE_H

#include "general/sys_dep.h"

class  cElemEqFormelle :  public cNameSpaceEqF
{
        public :
            // virtual tContFcteur & Foncteurs() = 0;
            virtual ~cElemEqFormelle ();
            cElemEqFormelle (cSetEqFormelles &,bool isTmp);

            cSetEqFormelles * Set();
            bool IsTmp() const;
            const  cIncIntervale & IncInterv() const;
            cIncIntervale & IncInterv() ;
            tContFcteur & AllFonct();
	    void  AddFoncRappInit(cMultiContEQF &,INT i0,INT i1,double aTol);
            REAL AddRappViscosite
                 (
                      const std::string  & aContexte,
                      bool OnCur,
                      int aK,
                      double   aTol,
                      bool     AdEq
                 );


            // void AddFoncRappOnCur(cMultiContEQF &,INT i0,INT i1,double * aTol );

            void AssertClosed();
            void AssertUnClosed();
            void AssertSameSet(const cElemEqFormelle &);

	    virtual void SetValAndInit(REAL,INT IndGlob);
	    // Les contraintes se referent au valeur init,
	    // d'ou l'interet eventuel de les remettre sur 
	    // sur les valeur courantes si c'est elles que l'on
	    // veut figer
	    virtual void SetValInitOnValCur();
	    INT NbInc();


        protected :

	    void AddFoncteurEEF(cElCompiledFonc *);
            void CloseEEF(bool asIntervBlock = true);
            // Au cas ou des inconnues ont ete modifiee,
            // remet a jour mSet.Alloc()
            void ReinitOnCur();
            tContFcteur  FoncRapp(INT i0,INT i1,const double * vals);
            tContFcteur  FoncRappInit(INT i0,INT i1);

            cSetEqFormelles & mSet;
            // Foncteur de Rappel sur Valeur Init
            INT                    mNumInc0;
            cIncIntervale          mIncInterv;
            INT                    mNumIncN;

            tContFcteur                mFoncRap;
            tContFcteur                mAllFonct;
            std::vector<double *>      mAdrFR;
            std::vector<double  >      mValsInit;
            bool                       mClosed;
       private :
	    cElemEqFormelle (const cElemEqFormelle &) ; // Prohib
	    void operator =  (const cElemEqFormelle &) ; // Prohib
};

#endif
