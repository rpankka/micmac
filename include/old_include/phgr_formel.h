/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr

   
    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in 
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte 
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/

#ifndef  _PHGR_FORMEL_H_
#define  _PHGR_FORMEL_H_

#include <photogram_defs.h>

#include <ElProjStenopeGen>
#include <CamStenopeIdeale>

#include <string>
#include <vector>
#include <set>

#define DIRECTORY_GENCODE_FORMEL "CodeGenere/photogram/"


// Pour mettre au point les pb de conditionnement
extern double aSeuilMaxCondSubstFaiseau;
extern bool DebugPbCondFaisceau ;
extern bool BugUPL;
void ReinitStatCondFaisceau();
void ShowStatCondFaisceau(bool ShowVect);

extern bool DBFActiveProf6 ;

// Appuis
// Croisee
// Liaison
//  cEqDirecteDistorsion
//

extern const bool AFocalAcceptNoDist;

extern bool TestPermutVar;
extern bool ShowPermutVar;
extern bool ShowCholesky;
// Devrait toujours etre true, mais il y a un bug pour l'instant, avant
// d'assurer une reversibilite tant que le bug n'est pas trouve ....

extern Pt2dr aDebugPIm;
extern Pt2dr aDebugPL3;


void DebugLaser(const std::string & aName);

// dans exemple_phgr_formel.h
 
      // Qc classe simple liee aux equation directe entre calib,
      // aussi a but "didactique"
class cEqObsRotVect;
class cEqCalibCroisee;
class cEqDirecteDistorsion;


class cEqf1IncTmp;   // 1 Inconnue temporaire
class cEqfBlocIncTmp;  // 1 Bloc d'inconnue temporaire
class cEqfP3dIncTmp;  // Une specialisation de cEqfBlocIncTmp pour point terrain

class cParamPtProj;
class cP3d_Etat_PhgrF;
class cP2d_Etat_PhgrF;
class cMatr_Etat_PhgrF;

// -----------------------------
//class cMapIncInterv;
class cElCompiledFonc ;

class cIncIntervale;
class cIncListInterv;

class cNameSpaceEqF;
class cSetEqFormelles;
class cHomogFormelle;
class cDistRadialeFormelle;
class cEqHomogFormelle;
class cEqOneHomogFormelle;
class cParamIntrinsequeFormel;
class cRotationFormelle;
class cCameraFormelle;
class cCpleCamFormelle;
class cParamIFDistRadiale;
class cParamIFDistPolynXY ;
class cTriangulFormelle;
class cCpleGridEq;
class cEqEllipseImage;
class cParamIFHomogr;
class cLIParam_Image;
class cEqVueLaserImage;
class cEqCorrelGrid;
class cEqFormelleLineaire;
class cParamIFDistStdPhgr;
class cAppuiGridEq;
class cEqPlanInconnuFormel;
class cTFI_Triangle;

class cTFI_AttrSom;

class cInterfSurfaceAnalytique ;
class cInterfSurfAn_Formelle;
class cCylindreRevolution;
class cCylindreRevolFormel;


class cL2EqObsBascult;
class cSolBasculeRig;

class cPIF_Bilin;


class cEqOffsetGPS;
class cBaseGPS;
class cEqObsBlockCam;


//   Il n'avait pas ete prevu de renumeroter les intervales. Quand le besoin
//   est apparu, pour la resolution des systemes par cholesky creux, on a gere
//   ca par une double numerotation :
//         - I0Init : numerotation initiale, lie a l'ordre d'allocation des inconnues
//         - I0Final : systeme de numerotation  optumisie pour les matrices
//    En premiere phase, on duplique touts les numero, sans doute certains deviendront
//   inutiles.
// 

class cSsBloc;

class cIncIntervale
{
    public :
       cSsBloc  SsBlocComplet();

       bool operator == (const cIncIntervale &) const;
       typedef std::string tId;

       cIncIntervale(bool isTmp,const tId & anId,cSetEqFormelles     &,int aNbInc=-1);
       cIncIntervale(const tId & anId,int anI0,int anI1,bool isTmp=false);
    // Copie, avec renommage
       cIncIntervale(const cIncIntervale &,const tId &);

       void SetName(const tId &);
       void SetI0I1Alloc(int I0,int I1);

       int I0Alloc()  const ;
       int I1Alloc()  const ;
       int NumBlocAlloc() const {return mNumBlocAlloc;}
       int I0Solve()  const ;
       int I1Solve()  const ;
       int NumBlocSolve() const {return mNumBlocSolve;}


       int Sz()  const ;
       const tId & Id() const;
       void Close();
       void SetNumAlloc(int aNum);

       bool Overlap(const cIncIntervale &) const;
    // bool operator < (const cIncIntervale &) const; // Compare les Id

       void SetFiged(bool);
       bool IsFiged() const;  // Est ce que TOUTES les var sont figees dans l'int
       double Order() const;
       void SetOrder(double) ;
       void SetFirstIntervalSolve();
       void InitntervalSolve(const cIncIntervale &);
       bool IsTmp() const;
    private :

       int mI0Alloc;
       int mI1Alloc;
       int mI0Solve;
       int mI1Solve;

       cSetEqFormelles     * mSet;
       tId                    mId;
       int                    mNumBlocAlloc;
       int                    mNumBlocSolve;
       bool                   mFiged;
       double                 mOrder;
       bool                   mIsTmp;
};

class cCmpI0PtrII
{
    public :
     bool operator () (const cIncIntervale * aI1,const cIncIntervale *aI2)
     {
          return aI1->I0Alloc() < aI2->I0Alloc();
     }
};


class cSsBloc
{
     public :
         bool operator ==(const cSsBloc &) const;
         bool disjoint (const cSsBloc &) const;
         int  I0AbsAlloc() const;
         int  I1AbsAlloc() const;
         int  I0AbsSolve() const;
         int  I1AbsSolve() const;

         int  I0Brut() const;
         int  I1Brut() const;
         int  Nb() const;

         cSsBloc(int aI0,int aI1);
         // cSsBloc(int aI0,int aI1,cIncIntervale *);

         void AssertIntInit() const;
         void BlocSetInt(cIncIntervale &);
         inline const cIncIntervale *  Intervale() const {return mInt;}
          
        int Cpt() const;
         
     private :
         int              mI0;  // Relatif au ss bloc
         int              mNb;  // Nb d'elet
         cIncIntervale *  mInt;
         int              mCpt;
         static int       theCptGlob;
};


class cIdIntCmp
{
     public :
          bool operator()(const cIncIntervale & anII1,const cIncIntervale & anII2) const;
};

typedef std::set<cIncIntervale,cIdIntCmp> cMapIncInterv;
/*
class cMapIncInterv  : public std::set<cIncIntervale,cIdIntCmp>
{
};
*/




class  cIncListInterv
{
    public :

       cIncListInterv();
       bool Equal(const cIncListInterv&) const;
       cIncListInterv(bool isTmp,const cIncIntervale::tId & anId,int anI0,int anI1);

       ~cIncListInterv();
       void AddInterv(const cIncIntervale &,bool CanOverlap=false);
       void ResetInterv(const cIncIntervale &);
       bool IsConnexe0N() const;

       int I0Min() const;
       int I1Max() const;
       int Surf()  const;
       const cIncIntervale & FindEquiv(const cIncIntervale &) const;

       const cMapIncInterv &Map() const;
       bool  MayOverlap() const;

       void Init();
    private :

       // cIncListInterv  (const cIncListInterv &) ; // Un imlemanted
       void operator = (const cIncListInterv &) ; // Un imlemanted

       int          mI0Min;
       int          mI1Max;
       int          mSurf;
       cMapIncInterv mMap;
       bool          mMayOverlap;  // Est-ce que l'overlap est possible
};


class cNameSpaceEqF
{
        public :

             typedef std::vector<cElCompiledFonc  *>     tContFcteur;

	     typedef enum
	     {
		     eNoAqqAppui,
		     eAqqAppuiSimple,
		     eAqqAppuiPtInc
	     } eTypeEqAppui;

	     typedef enum
	     {
		     eSysPlein,
		     eSysCreuxMap,
		     eSysCreuxFixe,
		     eSysL1Barrodale,
		     eSysL2BlocSym
	     } eTypeSysResol;

	     typedef enum
             {
                     eHomLibre,
                     eHomFigee,
                     eHomStdBloqueRot  // Bloquage en rotation en 0,0 et axe des X
             } eModeContrHom;

	     typedef enum
	     {
                  eRotLibre,
	          eRotFigee,
	          eRotBaseU,
	          eRotPseudoBaseU,
                  eRotCOptFige
	     } eModeContrRot;
	     typedef enum
	     {
                  eResiduCoplan,
	          eResiduIm1,
	          eResiduIm2
	     } eModeResidu;
	     static std::string & NameOfTyRes(eModeResidu);

             // Nom donne a partir des usages
	     typedef enum
	     {
		     eTEDD_Reformat,
		     eTEDD_Bayer,
		     eTEDD_Interp
	     } eTypeEqDisDirecre;
	 public :
	     static std::string TheNameEcCoplan;
	     static std::string TheNameResiduIm1;
	     static std::string TheNameResiduIm2;
};


class cContrainteEQF
{
    public :
        static const double  theContrStricte;// = -1;

        cContrainteEQF(cElCompiledFonc * mFCtr,double aTol);
	cElCompiledFonc * FctrContrEQF() const;

         bool   ContrainteIsStricte() const;
	 double PdsOfEcart(double anEcart) const;
    private :
         cElCompiledFonc* mFctr;
	 double           mTol;
	 double           mMin;
         double           mMax;
         double           mPds;
};

class cMultiContEQF
{
    public :
        cMultiContEQF();
	void AddAcontrainte(cElCompiledFonc * mFCtr,double aTol);
	int NbC() const;
	const cContrainteEQF & KthC(int aKth) const;
	void Add(const cMultiContEQF &);

    private :
     // Parties univ
/*
    EN FAIT PAS UTILISE CAR :
         -1-  apres simplif, les fct cSetVar, ne coutent pas tres chers;
         -2-  si ont veut avoir des contraintes non strictes, on est
         obliges de maintenir l'ancien mecanisme, donc au final redondance ...

        void AddContrainteUniv(int aKV,double aVal,double aTol);
        int    NbUniv() const;
        int    KthIndUniv(int aK) const;
        double KthValUniv(int aK) const;
        double KthTolUniv(int aK) const;


        std::vector<int>             mKV;
        std::vector<double>          mVals;
        std::vector<double>          mTols;
*/
        std::vector<cContrainteEQF>  mContraintes;
};



class cObjFormel2Destroy
{
    public :
      virtual ~cObjFormel2Destroy();
      virtual void Update_0F2D();
};


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
	    void  AddFoncRappInit(cMultiContEQF &,int i0,int i1,double aTol);
            double_t AddRappViscosite
                 (
                      const std::string  & aContexte,
                      bool OnCur,
                      int aK,
                      double   aTol,
                      bool     AdEq
                 );


            // void AddFoncRappOnCur(cMultiContEQF &,int i0,int i1,double * aTol );

            void AssertClosed();
            void AssertUnClosed();
            void AssertSameSet(const cElemEqFormelle &);

	    virtual void SetValAndInit(double_t,int IndGlob);
	    // Les contraintes se referent au valeur init,
	    // d'ou l'interet eventuel de les remettre sur 
	    // sur les valeur courantes si c'est elles que l'on
	    // veut figer
	    virtual void SetValInitOnValCur();
	    int NbInc();


        protected :

	    void AddFoncteurEEF(cElCompiledFonc *);
            void CloseEEF(bool asIntervBlock = true);
            // Au cas ou des inconnues ont ete modifiee,
            // remet a jour mSet.Alloc()
            void ReinitOnCur();
            tContFcteur  FoncRapp(int i0,int i1,const double * vals);
            tContFcteur  FoncRappInit(int i0,int i1);

            cSetEqFormelles & mSet;
            // Foncteur de Rappel sur Valeur Init
            int                    mNumInc0;
            cIncIntervale          mIncInterv;
            int                    mNumIncN;

            tContFcteur                mFoncRap;
            tContFcteur                mAllFonct;
            std::vector<double *>      mAdrFR;
            std::vector<double  >      mValsInit;
            bool                       mClosed;
       private :
	    cElemEqFormelle (const cElemEqFormelle &) ; // Prohib
	    void operator =  (const cElemEqFormelle &) ; // Prohib
};

class cEqFPtLiaison
{
     public  :
          virtual double_t AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2) = 0;
          double_t AddPackLiaisonP1P2
	       (
		    const ElPackHomologue & aPack,
		    bool WithD2,
		    cElStatErreur * = 0,
                    double_t aPdsGlob  = 1.0,
		    double_t * SomPdsTot = 0
	       );
	  virtual double_t ResiduNonSigneP1P2(Pt2dr aP1,Pt2dr aP2) = 0;
	  void PondereFromResidu
	       (ElPackHomologue & aPack,double_t Ecart,double_t Coupure = -1);


          ElPackHomologue & StdPack();
     protected :
          ElPackHomologue  & mStdPack;
	  virtual ~cEqFPtLiaison();
          cEqFPtLiaison();

	  // Ce qui suit n'est pas toujours utilise
          std::string           mMemberX1;
          std::string           mMemberY1;
          std::string           mMemberX2;
          std::string           mMemberY2;
          Pt2d<Fonc_Num>        mP1;
          Pt2d<Fonc_Num>        mP2;
};

class cSignedEqFPtLiaison  : public cEqFPtLiaison
{
     public :
	  virtual double_t ResiduSigneP1P2(Pt2dr aP1,Pt2dr aP2) = 0;
	  // Par Defaut, renvoie la valeur abs    
	  double_t ResiduNonSigneP1P2(Pt2dr aP1,Pt2dr aP2) ;
     private :
};




class cDicoHomogSEF;
class cDicoCameraSEF;
class cDicoRotSEF;

// But est de reutiliser celles qui existe
// Pas d'associer un nom a chaque
class cDicoEqCorrGrid; 


class cManipOrdInc
{
     public :
        
        cManipOrdInc();
        void Init(const std::vector<cIncIntervale *> &aBlocsIncAlloc);
        Im1D_double_t8 ReordonneSol(Im1D_double_t8 aIm);
        std::vector<cIncIntervale *> &  BlocsIncSolve();
        std::vector<int>             &  I02NblSolve();
        std::vector<int>             &  Alloc2Solve();
        std::vector<int>             &  Solve2Alloc();
     private :
        std::vector<cIncIntervale *> mBlocsIncSolve;
        std::vector<int>              mI02NblSolve;

        std::vector<int>              mAlloc2Solve;
        std::vector<int>              mSolve2Alloc;
};


class AllocateurDInconnues;
class CamStenope;
class cFormQuadCreuse;
class cCamStenopeDistRadPol;
class cCamStenopeDistPolyn;
class cCamStenopeModStdPhpgr;
class cCamStenopeDistHomogr;
class cCamStenopeBilin;
class cGenSysSurResol;
class cMirePolygonEtal;
class cElHomographie;
class ElDistRadiale_PolynImpair;

class cSetEqFormelles : public cNameSpaceEqF
{
        public :


              //  Som Coef[K] X(Inde[K]) = B
              double AddEqEqualVar(double aPds,int aK1,int aK2,bool  AddEq);
              double AddEqLineaire (
                          double aPds, const std::vector<int>  &    indexe,
                          const std::vector<double>  & aCoeff,double aB);
              double ResiduEqLineaire (
                          double aPds, const std::vector<int>  &    indexe,
                          const std::vector<double>  & aCoeff,double aB);



              const std::vector<cIncIntervale *> &  BlocsIncAlloc() const;
              int NbBloc() const;
              void SetTmpBegun();
              void ShowVar() ;
              static void VerifC2MForPIF(bool isDC2M,CamStenope *);
              void SetPhaseEquation();
              // evite les duplicatas


              cGenSysSurResol * Sys();
	      cFormQuadCreuse*  FQC();  // Evtlt 0
              cEqFormelleLineaire * NewEqLin(int aNInc,int aNbVt,bool GenCode = false);
              cEqCorrelGrid * NewEqCorrelGrid(int aNbPix, bool Im2MoyVar, bool GenCode = false);
	      cEqCorrelGrid * ReuseEqCorrelGrid(int aNbPix, bool Im2MoyVar);


              // Valeur par defaut, correspondant ancienne
              // utilisation PosInit=0, 
              // 
              //   DMax en valeur relative de la boite englobante
              //
              cTriangulFormelle * NewTriangulFormelle
                                 ( int aDim,
				   const std::list<Pt2dr> &,double_t Dmax,
                                  ElDistortion22_Gen * PosInit= 0
                                  );
              cTriangulFormelle * NewTriangulFormelle
                                  ( int aDim,
				    Box2dr aBox,int aNb,double_t Dmax,
                                    ElDistortion22_Gen * PosInit= 0
                                  );
              cTriangulFormelle * NewTriangulFormelleUnitaire(int aDim);
              cCpleGridEq * NewCpleGridEq
              (
                  cTriangulFormelle &, cRotationFormelle &,
                  cTriangulFormelle &, cRotationFormelle &,
                  eModeResidu = eResiduCoplan,
		  bool Code2Gen=false
              );
	  

              ~cSetEqFormelles();
              cSetEqFormelles(eTypeSysResol = eSysPlein,int aNbEq=1);
              AllocateurDInconnues & Alloc();
              cHomogFormelle * NewHomF
		      (const cElHomographie &,
		       eModeContrHom aModeControle,
		       const std::string & = "");
              cHomogFormelle * GetHomFromName(const std::string &);
	      cCameraFormelle * GetCamFromName(const std::string &);
	      cRotationFormelle * GetRotFromName(const std::string &);


              cParamIFHomogr  * NewDistHomF(bool isDistC2M,cCamStenopeDistHomogr *,eModeContrHom);

              cDistRadialeFormelle * NewDistF(bool CloseEEF,bool isCFige,int aDegFig,
			                      const ElDistRadiale_PolynImpair &);
              cEqHomogFormelle * NewEqHomog
                         (
                             bool InSpaceInit,
                             cHomogFormelle &,
                             cHomogFormelle &,
                             cDistRadialeFormelle *,
			     bool Code2Gen = false
                         );
              cEqOneHomogFormelle * NewOneEqHomog
                         (
                             cHomogFormelle &,
			     bool Code2Gen = false
                         );




	       cParamIntrinsequeFormel * NewParamIntrNoDist(bool isDC2M,CamStenope * aCamInit,bool ParamVar=true);

               cBaseGPS * NewBaseGPS(const Pt3dr & aV0);
               cEqOffsetGPS * NewEqOffsetGPS(cRotationFormelle & aRF,cBaseGPS  &aBase,bool Code2Gen = false);
               cEqOffsetGPS * NewEqOffsetGPS(cCameraFormelle & aRF,cBaseGPS  &aBase);

               cEqObsBlockCam * NewEqBlockCal( cRotationFormelle & aRotRT0,
                                               cRotationFormelle & aRotLT0,
                                               cRotationFormelle & aRotRT1,
                                               cRotationFormelle & aRotLT1,
                                               bool                doGenerateCode
                                           );


	       cRotationFormelle * NewRotation
                                   (
                                        eModeContrRot,
		                        ElRotation3D aRC2MInit,
                                        cRotationFormelle *  = 0, // Rot Attach
		                        const std::string & aName = ""
                                   );

              cRotationFormelle * NewRotationEvol
                                  (
                                        ElRotation3D aRC2MInit,
                                        int aDegre,
                                        const std::string & aName = ""
                                  );

                cCpleCamFormelle *NewCpleCam
			         (
				      cCameraFormelle &,
				      cCameraFormelle &,
				      eModeResidu = eResiduCoplan,
				      bool Code2Gen=false
				 );

                cParamIFDistRadiale * NewIntrDistRad
                                      (
				           bool isDistC2M,
					   cCamStenopeDistRadPol *,
                                           int aDegFig
                                      );
		cParamIFDistPolynXY  * NewIntrPolyn(bool isDistC2M,cCamStenopeDistPolyn *);
                cParamIFDistStdPhgr * NewIntrDistStdPhgr
			              (bool isDistC2M,cCamStenopeModStdPhpgr *, int aDegFig);

                cPIF_Bilin *  NewPIFBilin(cCamStenopeBilin * aCSB);
                cParamIntrinsequeFormel *  AsPIF_NewPIFBilin(cCamStenopeBilin * aCSB); // Pour utiliser sans connaitre cPIF_Bilin


                cEqEllipseImage * NewEqElIm
                (
	           const cMirePolygonEtal &,
                   Pt2dr aCentre, double_t  anA, double_t  aB, double_t  aC,
                   double_t  aLarg, double_t  aBlanc, double_t  aNoir,
		   bool  Code2Gen = false
                );
                cAppuiGridEq * NewEqAppuiGrid
                (
                       cTriangulFormelle &,
                       cRotationFormelle &,
                       bool Code2Gen = false
                );
                cL2EqObsBascult  * NewEqObsBascult
                                   (
                                      const cSolBasculeRig &  aVInit,
                                      bool                    Cod2Gen
                                   );
             
              // dans phgr_cEqObsRotVect.cpp
                cEqObsRotVect * NewEqObsRotVect
                                (
                     // Si nulle, la rotation est allouee
                     // le seul cas envisage aujourd'hui une seule rot 1
                     // seule equation
                                    cRotationFormelle * aRot=0,
                                    bool Code2Gen = false
                                );
                cEqCalibCroisee * NewEqCalibCroisee
                                (
				    bool    SensC2M,
			            cParamIntrinsequeFormel & aPIF,
                                    cRotationFormelle * aRot=0,
                                    bool Code2Gen = false
				);
                cEqDirecteDistorsion * NewEqDirecteDistorsion
                                       (
			                   cParamIntrinsequeFormel & aPIF,
                                           eTypeEqDisDirecre   Usage,
                                           bool Code2Gen = false
				       );

                 cEqPlanInconnuFormel * NewEqPlanIF(cTFI_Triangle * aTri,bool Code2Gen);
                 cEqPlanInconnuFormel * NewEqPlanIF(const Pt3dr &aP0,const Pt3dr &aP1,const Pt3dr &aP2);
		 cTFI_AttrSom *         AttrP3(const Pt3dr &aP0);

		// VALEURS INIT BIDON , car souvent usage multiple
		// du meme objet, donc initialise
                cEqEllipseImage * NewEqElIm(const cMirePolygonEtal &,bool  Code2Gen = false);
	               



		cLIParam_Image *  NewLIParamImage
                                 (
                                    Im2D_double_t4 anIm,
                                    double_t  aZoom,
                                    CamStenope & aCam,
                                    cNameSpaceEqF::eModeContrRot
                                 );
		cEqVueLaserImage * NewLIEqVueLaserIm
                                   ( cRotationFormelle * aRotPts,
			             bool Multi,
			             bool Normalize,
				     int aNbPts,
				     cLIParam_Image &,cLIParam_Image &,
				     bool GenCode = false);
	               

                cCylindreRevolFormel & AllocCylindre
                                       (
                                         const  cCylindreRevolution &,
				         bool GenCode = false
                                       );
	               
		// Par defaut, centre figee, PP fige, foc fige


              void AddFonct(cElCompiledFonc *);
              void SolveResetUpdate(double aExpectedResidu=-1,bool *OK=0);
              void Solve(double aExpectedResidu,bool *OK);
              void ResetUpdate(double aLambda);  // aLambda "absicse" sur le droite de grad
              void SetSol(double aLambda);
              void DebugResetSys();

              void SetClosed();
              void AssertClosed();
              void AssertUnClosed();
              bool IsClosed() const;


	  void AddContrainte(const cContrainteEQF &,bool Strictes);
	  void AddContrainte(const cMultiContEQF &,bool Strictes);

	  // VAddEqFonctToSys est la plus utile,
	  // AddEqFonctToSys est connservee pour compatibilite

	  const std::vector<double_t> & VAddEqFonctToSys
               (
                  cElCompiledFonc * aFonct,
                  const std::vector<double> & aVPds,
                  bool WithDerSec
               );
	  const std::vector<double_t> & VAddEqFonctToSys
               (
                  cElCompiledFonc * aFonct,
                  double_t aPds,
                  bool WithDerSec
               );



          double_t AddEqFonctToSys
               (
                  cElCompiledFonc * aFonct,
                  double_t aPds,
                  bool WithDerSec
               );

	   const std::vector<double_t> & AddEqIndexeToSys
		                     (  
                                         cElCompiledFonc * aFonct,
                                         double_t aPds,const std::vector<int>  & VIncs
				     );
	  
          double_t ResiduSigne ( cElCompiledFonc * aFonct);
	  const std::vector<double_t> & VResiduSigne ( cElCompiledFonc * aFonct);


          double_t AddEqFonctToSys
               (
                  const tContFcteur &,
                  double_t aPds,
                  bool WithDerSec
               );

          void Reinit(int k0,int k1);
          void AddElem(cElemEqFormelle & anEq);
          void  AddObj2Kill(cObjFormel2Destroy *);

	//  Gestion des subsitutions
          cEqfP3dIncTmp * Pt3dIncTmp( );

          void AddABlocAlloc(cIncIntervale *);
           // return le Bloc avec le bon intervalle
          cSsBloc GetBlocOfI0Alloc(int aI0Alloc,int aI1Alloc) const;
          cSsBloc GetBlocOfI0Alloc(const cIncIntervale & aBl) const;
          // cSsBloc GetBlocOfI0(const cIncIntervale & aBl) const;
          int    GetNumBlocInclusIAlloc(int anI) const;
          cIncIntervale *  GetIntervInclusIAlloc(int anI) const;

          int   Alloc2Solve(const int aK){return mMOI.Alloc2Solve()[aK];}
          void TestPbFaisceau(bool doCheck,bool doSVD,bool doV0);
        private :
           Im1D_double_t8 ReordonneSol(Im1D_double_t8 aIm);
           void NumeroteBloc();


           cEqCorrelGrid * NewEqCorrelGridGen
		              (int aNbPix, bool Im2MoyVar, bool GenCode,bool Reuse);
	  friend class cParamIntrinsequeFormel;  // pour AddCamFormelle
          void  AddCamFormelle(cCameraFormelle  *,const std::string &);


          void SetPtCur(const double * aPt);
          void UpdateFctr();
          AllocateurDInconnues  & mAlloc;
          tContFcteur             mLFoncteurs;
          int                     mNbVar;
          // L2SysSurResol *      mSys;
          cGenSysSurResol *       mSys;
	  cFormQuadCreuse*        mFQC;
          bool                    mClosed;
          cDicoHomogSEF &         mDicHom;
	  cDicoCameraSEF &        mDicCam;
	  cDicoRotSEF &           mDicRot;
          cDicoEqCorrGrid &       mDicEqCorGrid; 
          // cDicoEqHomogSEF *       mDicEqHom;

          std::list<cObjFormel2Destroy *> mLobj2Kill;
	  eTypeSysResol mTypeSys;
          int   mEstimNbEq;

	   cRotationFormelle * NewRotationGen
                               (
                                        eModeContrRot,
		                        ElRotation3D aRC2MInit,
                                        cRotationFormelle *  , // Rot Attach
		                        const std::string & aName ,
                                        int   aDegre,
                                        bool aVraiBaseU
                               );

          cEqfP3dIncTmp  *  mPt3dIncTmp;
          bool              mTmpBegun;
          int               mIndIncTmp;
	  // Sert, avant un solve a mettre a Id les coeffs
	  std::list<cEqfBlocIncTmp *>  mLBlocTmp;
          std::list<cElemEqFormelle *>  mLEEF;


          std::vector<cIncIntervale *>  mBlocsIncAlloc;
          // std::vector<cIncIntervale *>  mBlocsIncSolve;
          std::vector<int>              mI02NblAlloc;
          // std::vector<int>              mI02NblSolve;

          // std::vector<int>              mAlloc2Solve;
          // std::vector<int>              mSolve2Alloc;
          cManipOrdInc                  mMOI;
          Im1D_double_t8                    mSolQuad;
          Im1D_double_t8                    mCurSol;


          cSetEqFormelles(const cSetEqFormelles &); // N.I.
          cSetEqFormelles operator = (const cSetEqFormelles &); // N.I.
};

extern void ShowSpectrSys(cSetEqFormelles & aSetEq);



#if (0)
class cHomogFormelle : public cElemEqFormelle,
                       public cObjFormel2Destroy
{
        public :
            friend class cSetEqFormelles;
            Pt2d< Fonc_Num>  operator ()(Pt2d< Fonc_Num>);
            cMultiContEQF      StdContraintes() ;

           const cElHomographie & HomInit() const;
           const cElHomographie & HomCur() const;
           void ReinitHom(const cElHomographie &);

	   void SetModeCtrl(eModeContrHom);
        private :
            cHomogFormelle(const cElHomographie &,cSetEqFormelles &,eModeContrHom);

            class cComp
            {
                 public :
                    cComp
                    (
                         cElComposHomographie &,
                         cSetEqFormelles &,
                         bool IsDenom
                    );
                    Fonc_Num operator ()(Pt2d< Fonc_Num>);


                  private :
                    Fonc_Num  mX;
                    Fonc_Num  mY;
                    Fonc_Num  m1;
            };

            // Foncteur de Rappel sur Valeur Init
            cElHomographie  mHomInit;
            cElHomographie  mCurHom;

            cComp           mCX;
            cComp           mCY;
            cComp           mCZ;
            eModeContrHom   mModeContr;
	    double          mHomFTol;
};
#endif

class cElComposHomographie;
class cHomogFormelle : public cElemEqFormelle,
                       public cObjFormel2Destroy
{
        public :
            friend class cSetEqFormelles;
            Pt2d< Fonc_Num>  operator ()(Pt2d< Fonc_Num>);
            Pt2d< Fonc_Num>  ImRec(Pt2d< Fonc_Num>);

            cMultiContEQF      StdContraintes() ;

           const cElHomographie & HomInit() const;
           const cElHomographie & HomCur() const;
           void ReinitHom(const cElHomographie &);

	   void SetModeCtrl(eModeContrHom);
        private :
            cHomogFormelle(const cElHomographie &,cSetEqFormelles &,eModeContrHom);

            class cComp
            {
                 public :
                    cComp
                    (
                         cElComposHomographie &,
                         cSetEqFormelles &,
                         bool IsDenom
                    );
                    Fonc_Num operator ()(Pt2d< Fonc_Num>);


                  // private :
                    Fonc_Num  mX;
                    Fonc_Num  mY;
                    Fonc_Num  m1;
            };

            // Foncteur de Rappel sur Valeur Init
            cElHomographie  &mHomInit;
            cElHomographie  &mCurHom;

            cComp           mCX;
            cComp           mCY;
            cComp           mCZ;
            eModeContrHom   mModeContr;
	    double          mHomFTol;
};

class cDistModStdPhpgr;
class cDistRadialeFormelle : public cElemEqFormelle,
                             public cObjFormel2Destroy
{
        public :

           friend class cSetEqFormelles;
           friend class cParamIFDistRadiale;
           Pt2d< Fonc_Num>  operator ()(Pt2d< Fonc_Num>);
           Pt2d<Fonc_Num>  FCentre() const;

           const ElDistRadiale_PolynImpair & DistInit() const;
           const ElDistRadiale_PolynImpair & DistCur() const;
           void ReinitDist(const ElDistRadiale_PolynImpair & );
           cMultiContEQF      StdContraintes() ;
	   void SetCentreFige(bool);
           void SetDegreFige(int aDF,double aTol=cContrainteEQF::theContrStricte);

	   int   IndCentre() const;

           cDistModStdPhpgr & DistCurStd();
           const cDistModStdPhpgr & DistCurStd() const;
           cDistModStdPhpgr & DistInitStd();
           const cDistModStdPhpgr & DistInitStd() const;

	   double RMax() const;
           void ActuRMax(CamStenope *,bool C2M);

	   void SetTolCDist(double aTol);
	   void SetTolCoeff(double aTol);

           bool IsFiged() const;


        protected :
	   void  AddContrCentre(cMultiContEQF & aContr);
	   void  AddContrCoeff(cMultiContEQF & aContr);

           cMultiContEQF   CentreFRapInit() ;
           cMultiContEQF   CoeffsRapInit(int aCoef0);
           cDistRadialeFormelle
           (
                bool closeEEF,
	        bool isCFige,
		int aDegFig,
		const ElDistRadiale_PolynImpair &,
		cSetEqFormelles &,
                cCamStenopeModStdPhpgr * aDP = 0
	   );


	   bool                       mCentreFige;
	   int                        mDegreFige;
           cDistModStdPhpgr           &mDistInitStd;
           cDistModStdPhpgr           &mCurDistStd;
	   ElDistRadiale_PolynImpair& mDistInit;
	   ElDistRadiale_PolynImpair& mCurDist;
	   int                        mIndCentre;
           Pt2d<Fonc_Num>             mFCentre;
           std::vector<Fonc_Num>      mFCoeffs;

	   double                     mTolCDist;
	   double                     mTolCoeffs;
};


class cCamStenopeGrid;

class cParamIntrinsequeFormel : public cElemEqFormelle,
                                public cObjFormel2Destroy
{
	public  :
           // certaine camera (par exe de type grid def) ont besoin de "changer l'état" des equations ou
           // elle interviennet notamment sur la numeroration  dans les inconnues des variable
           virtual void PrepareEqFForPointIm(const cIncListInterv &,cElCompiledFonc *,const Pt2dr &,bool EqDroite,int aKCam); 

           // Avant il y avait en dur :   mLInterv.AddInterv(mCam.PIF().IncInterv());
           // Pour prendre en compte les camera grilles avec des intervalles d'inconnues non connexes
           // (et evolutif) on ajoute cette fonction virtuelle qui pemet de specialiser
           virtual void AddToListInterval( cIncListInterv &);


           bool UseAFocal() const;
           bool   AllParamIsFiged() const;
           virtual bool IsDistFiged() const;
           friend class cSetEqFormelles;
	   virtual ~cParamIntrinsequeFormel();

           void Update_0F2D();
	   virtual CamStenope * CurPIF();
	   virtual CamStenope * DupCurPIF();
	   virtual void    UpdateCurPIF();
	   void    NV_UpdateCurPIF();   // Non virtuel, pour appel constructeur

           double StdScaleN() const;
           double StdScaleNNoGrid() const;
	   CamStenope * CamInit();  // Utilisee pour pre-corriger les distortions
           cCamStenopeGrid * CamGrid();
           void              UpdateCamGrid( double aTol );

	   virtual  std::string  NameType() const;
	    // Direction rayon ,  Cam->Monde
            Pt3d<Fonc_Num>   Cam2DirRayMonde(Pt2d<Fonc_Num>,int aKCam);
	    Pt3d<Fonc_Num>   CorrDist2DirRayMonde(Pt2d<Fonc_Num> aP);
	    Pt2d<Fonc_Num>   DirRayMonde2CorrDist(Pt3d<Fonc_Num> aP);
	    Pt2d<Fonc_Num>   DirRayMonde2Cam(Pt3d<Fonc_Num> aP,int aKCam);

             virtual Fonc_Num  NormGradC2M(Pt2d<Fonc_Num>);
             virtual bool UseSz() const;
	    // DOIT se CHARGER DE Foc et PP si necessaire


            cCameraFormelle * NewCam
                              (
                                   eModeContrRot,
                                   ElRotation3D,
                                   cCameraFormelle *  = 0, // Cam Att,
				   const std::string &  aName = "",
				   bool  CompEqAppui = false,
				   bool  GenCodeAppui = false,
                                   bool  HasEqDroite  = false
                              );

            double_t  CurFocale() const;
            Pt2dr CurPP() const;
            const tParamAFocal  & CurAFoc() const;
            virtual cMultiContEQF  StdContraintes();

            void  SetFocFree(bool);
            void  SetFocFigee(double aTol);

            void  SetAF1Free(bool);
            void  SetAF2Free(bool);
            virtual void  SetPPFree(bool);
            void  SetPPFFige(double aTol);


	    int IndPP() const;
	    // Lorsque le PIF possede des variables d'etats et que plusieurs PIF sont
	    // impliques dans une equation, il importe de pouvoir distinguer les variables,
	    // d'ou le role de KCam
	    
            Pt2d<Fonc_Num> DistC2M(Pt2d<Fonc_Num>,int aKCam);
            Pt2d<Fonc_Num> DistM2C(Pt2d<Fonc_Num>,int aKCam);
	    bool  DistIsC2M() const;


	    Pt2d<Fonc_Num> FPP();
	    Fonc_Num       FFoc();

	    virtual void InitStateOfFoncteur(cElCompiledFonc *,int aKCam);

	    Pt2dr  CorrigePFromDAdd(const Pt2dr & aP1,bool UseGrid);


            // Nom horrible coherent avec un usage prohibee en dehors du cas tres particulier de
	    // la conversion de format; on utilise la distorsion dans le sens M->C ce qui est
	    // contraire aux usages d'Elise
	    //
	    // Rajoute un Z nul uniquement pour la compat avec ce qui a ete fait dans le sens standard
	    // C2M de cEqCalibCroisee
	    //
            // Pt2d<Fonc_Num>   DirCam_2_PtCam_AssumingDistDirecte(Pt3d<Fonc_Num>,int aKCam);


            void AssertNoAFocalParam(const std::string &);
            void AddRapViscosite(double aTol);


        protected :

            // Par defaut focale et PP sont figes
	    // Ne fait pas "Close", doit etre fait pres construction
	    // des derives, donc est fait par l'allocateur static
	    // de cSetEqFormelles
            cParamIntrinsequeFormel
		    (
                         bool isDC2M,
		         CamStenope *,
			 cSetEqFormelles &,
			 bool ParamVar
                   );

            // Dist Cam->Monde, Def = Id


             bool                       isDistC2M;
             bool                       isFocaleFree;
             bool                       isPPFree;

             bool                       isAFoc1Free;
             bool                       isAFoc2Free;

	     CamStenope *               mCamInit;
	     CamStenopeIdeale *         mCurPIF;
             cCamStenopeGrid *          mCamGrid;
             bool                       mFiged;
             double                     mRayonGrid;
             double_t                       mFocaleInit;
	     double_t                       mCurFocale;
	     Pt2dr                      mPPInit;
	     Pt2dr                      mCurPP;
             tParamAFocal               mAFocInit;
             tParamAFocal               mCurAFoc;
	     Fonc_Num                   mFFoc;
	     int                        mIndPP;
	     Pt2d<Fonc_Num>             mFPP;
	     int                        mIndAF;
             std::vector<Fonc_Num>      mFAFoc;
             bool                       mParamVar;
	     double                     mTolFoc;
	     double                     mTolPP;
	     double                     mTolAF1;
	     double                     mTolAF2;
             ElProjStenopeGen<Fonc_Num> mProjStenF;
      private :
            virtual  Pt2d<Fonc_Num> VDist(Pt2d<Fonc_Num>,int aKCam);
};

// class cHomogFormelle;
// class cParamIntrinsequeFormel : public cElemEqFormelle,

class cParamIFHomogr  : public cParamIntrinsequeFormel 
{ 
	public :
           friend class cSetEqFormelles;
	   void SetFigee();
	   void SetLibre();
	   void SetStdBloqueRot();
	   CamStenope * CurPIF() ;
	   CamStenope * DupCurPIF();
	   cCamStenopeDistHomogr *  CurPIFHom();
	   virtual void    UpdateCurPIF();
	   void    NV_UpdateCurPIF();   // Non virtuel, pour appel constructeur
	private  :
            cParamIFHomogr(bool isDC2M,cCamStenopeDistHomogr *,cSetEqFormelles &,eModeContrHom);
	    virtual ~cParamIFHomogr();
            virtual cMultiContEQF  StdContraintes();
	    virtual  std::string  NameType() const;
            virtual  Pt2d<Fonc_Num> VDist(Pt2d<Fonc_Num>,int aKCam);
            // virtual  Pt2d<Fonc_Num> DistM2C(Pt2d<Fonc_Num>);

	    cHomogFormelle *  mHF;
	    cCamStenopeDistHomogr * mCurPIF;
};


class cParamIFDistRadiale : public cParamIntrinsequeFormel 
{
      public :

           bool IsDistFiged() const;
           friend class cSetEqFormelles;
	   virtual std::string  NameType() const;

           // La distortion est toujours ramenee a un degre 5
           const ElDistRadiale_PolynImpair & DistInit() const;
           const ElDistRadiale_PolynImpair & DistCur() const;

            cMultiContEQF  StdContraintes();

	   CamStenope * CurPIF() ;
	   CamStenope * DupCurPIF();
	   cCamStenopeDistRadPol  * CurPIFPolRad();
	   virtual void    UpdateCurPIF();
	   void    NV_UpdateCurPIF();   // Non virtuel, pour appel constructeur

            // L'option PP-CDist lie est exclusive des options
            // PP lie ou CDist lie
                    void  SetLibertePPAndCDist(bool,bool,double aTol=cContrainteEQF::theContrStricte);
                    void  SetCDistPPLie(double aTol=cContrainteEQF::theContrStricte);


           void SetDRFDegreFige(int aDF,double aTol=cContrainteEQF::theContrStricte);
	   virtual void SetValInitOnValCur();

      protected :

           cParamIFDistRadiale
           (
                bool isDC2M,
                cCamStenopeDistRadPol *,
                cSetEqFormelles&,
                int aDegFig,
                cCamStenopeModStdPhpgr * = 0
           );

            bool                    mCDistPPLie;
	    cElCompiledFonc *       mFoncEqPPCDistX;
	    cElCompiledFonc *       mFoncEqPPCDistY;

            virtual  Pt2d<Fonc_Num> VDist(Pt2d<Fonc_Num>,int aKCam);
            cDistRadialeFormelle    mDRF;
	    cCamStenopeDistRadPol * mCurPIF;
      private :
            virtual void  SetPPFree(bool);
};

// Classe pour modeliser ma distortion telle que
//  decrite dans Fraser, ISPRS 97, Vol 52, 149-159
//  i.e.  : Radiale + Decentrique + Affine

class cParamIFDistStdPhgr : public cParamIFDistRadiale 
{
	public :
            friend class cSetEqFormelles;
	    virtual std::string  NameType() const;
            cMultiContEQF  StdContraintes();
	    cDistModStdPhpgr & CurDist();
	    const cDistModStdPhpgr & CurDist() const;

	   CamStenope * CurPIF() ;
	   CamStenope * DupCurPIF();
	   cCamStenopeModStdPhpgr *  CurPIFStdPhgr();
	   virtual void    UpdateCurPIF();
	   void    NV_UpdateCurPIF();   // Non virtuel, pour appel constructeur

	   void SetParam_Aff_Fige(double aTol=cContrainteEQF::theContrStricte);
	   void SetParam_Dec_Fige(double aTol=cContrainteEQF::theContrStricte);

	   void SetParam_Aff_Free();
	   void SetParam_Dec_Free();

           bool IsDistFiged() const;

	private :
           virtual  Pt2d<Fonc_Num> VDist(Pt2d<Fonc_Num>,int aKCam);
           cParamIFDistStdPhgr(bool isDC2M,cCamStenopeModStdPhpgr *,cSetEqFormelles &,int aDegFig);

	   cDistModStdPhpgr &      mDStd;
	   cDistModStdPhpgr &      mInitDStd;

	   bool                    mParamDecentreFree;
	   bool                    mParamAffineFree;

	   Fonc_Num                mFP1;
	   Fonc_Num                mFP2;
	   Fonc_Num                mFb1;
	   Fonc_Num                mFb2;
	   double                  mTol_Dec_PhgStdPIF;
	   double                  mTol_Aff_PhgStdPIF;
	   cCamStenopeModStdPhpgr * mCurPIF;
};

class  cPolynome1VarFormel
{
     public :
        cPolynome1VarFormel
        (
                cSetEqFormelles    &,
                cVarSpec           aVarTime,
                double_t *             aV0,
                int                aDegre
        );
        Fonc_Num  Fonc();
        double_t  Val(double_t aTime);

     private :
        double_t *                  mV0;
        int                     mDegre;
        Fonc_Num                mFonc;
        std::vector<double_t>       mValsCur;

        cPolynome1VarFormel(const cPolynome1VarFormel &);  // Non Implemante
        void    operator = (const cPolynome1VarFormel &);  // Non Implemante
};


// Pour le GL (Gimbal-Lock) ,c'est la rotation qui transforme Cam->Monde
//   cRotationFormelle::C2M  mFMatr * aP + mFCOpt;
//    mFMatrInv * (aP - mFCOpt);

class cRotationFormelle : public cElemEqFormelle,
                          public cObjFormel2Destroy
{
	// Sauf eventuel cas contraire explicite,
	// toutes les rotations sont passees, memorisees
	// et stockees dans le sens Cam->Monde
	//
	// Donc si ca ne correspond pas une orientation de camera
	// C2M est le sens direct et M2C le sens reciproque
	public  :
          bool IsFiged() const;


          double AddRappelOnAngles(bool OnCur,int aK,double aTol,bool AddEq);
          double AddRappelOnAngles(bool OnCur,const std::list<int> & ,double aTol,bool AddEq);
          double AddRappelOnCentre(bool OnCur,Pt3dr aTol,bool AddEq) ;

          friend class cSetEqFormelles;
          cMultiContEQF      StdContraintes() ;
	  Pt3d<Fonc_Num>   C2M(Pt3d<Fonc_Num>,int  aKForceGL=-1);  // ImAff
	  Pt3d<Fonc_Num>   M2C(Pt3d<Fonc_Num>,int  aKForceGL=-1);

	  Pt3d<Fonc_Num>   VectM2C(Pt3d<Fonc_Num>,int  aKForceGL=-1);
	  Pt3d<Fonc_Num>   VectC2M(Pt3d<Fonc_Num>,int  aKForceGL=-1); // == ImVect
	  // Monde -> Cam
	  Pt3d<Fonc_Num>   ImVect(Pt3d<Fonc_Num>,int aKForceGL=-1);
          Pt3d<Fonc_Num>   COpt();
	  ElRotation3D     CurRot();
	  void     SetCurRot(const ElRotation3D & aR2CM);
	  ElRotation3D     CurRot(double_t aT);

	   ~cRotationFormelle();

           int IndexeAllocationCOpt();
           // cRotationFormelle * RotAttach();
           eModeContrRot  ModeRot() const;
	   void SetModeRot(eModeContrRot);
           const std::string & Name() const;
	   virtual void SetValInitOnValCur();
	   Pt3dr  CurCOpt() const;
	   Pt3dr  CurCOpt(double_t aT) const;
           int    Degre() const;

           const std::string & NameParamTime();
           void  SetFlagAnglFige(int aFlag);
	   void  SetTolAng(double);
	   void  SetTolCentre(double);

           Pt3dr AddRappOnCentre(const Pt3dr & aVal,const Pt3dr & aPds,bool WithDerSec);
           void ReactuFcteurRapCoU();

           // cMatr_Etat_PhgrF &  MatGL(bool) ;     // Mode Gimbal Lock
           void SetGL(bool aModeGL);
           const ElMatrix<Fonc_Num> & MatFGL(int ForceGL);
           ElMatrix<Fonc_Num>  MatFGLComplete(int ForceGL);
           const ElMatrix<double_t> &       MGL() const;
           bool IsGL() const;
           // void InitEtatGL(bool isP);
           int NumCentre(int aK) const;
           int NumTeta(int aK) const;
           void SetRotPseudoBaseU (cRotationFormelle *);
        private :
	   cElCompiledFonc *    FcteurRapCoU();
	   cRotationFormelle
           (
                eModeContrRot,
		ElRotation3D aRC2MInit,
                cSetEqFormelles &,
                cRotationFormelle *,  // Rotation de ratachement eventuelle
		const std::string & aName,
                int   aDegre,            // Cas des parametre variables dans le temps
                                         // -1 correspond au cas non employe
                bool  aUseVraiBaseU
           );



           cPolynome1VarFormel  * AllocPol(double_t * ValCste);
           void AssertDegre0() const;


	   eModeContrRot mModeContr;
         

           std::string    mNameParamTime;
           cVarSpec       mVarTime;
           int            mDegre;


	   double_t           mTeta01Init;
	   double_t           mTeta02Init;
	   double_t           mTeta12Init;

	   double_t           mCurTeta01;
	   double_t           mCurTeta02;
	   double_t           mCurTeta12;

           cPolynome1VarFormel * mPolTeta01;
           cPolynome1VarFormel * mPolTeta02;
           cPolynome1VarFormel * mPolTeta12;

	   Fonc_Num       mFTeta01;
	   Fonc_Num       mFTeta02;
	   Fonc_Num       mFTeta12;
           ElMatrix<Fonc_Num> mFMatr;
           ElMatrix<Fonc_Num> mFMatrInv;

	   Pt3dr          mCOptInit;
	   Pt3dr          mCurCOpt;
	   int            mIndAllocCOpt;
           cPolynome1VarFormel * mPolCoptX;
           cPolynome1VarFormel * mPolCoptY;
           cPolynome1VarFormel * mPolCoptZ;
	   Pt3d<Fonc_Num> mFCOpt;

           cRotationFormelle *  pRotAttach;
           // Le pRotAttach est assez lourd et en gal inutile grace au nouveau mode
           // de controle par fixage d'une des var en mode pseudo  .. ; pour ne
           // pas interferer avec on rajoute
           cRotationFormelle *  pRotPseudoBaseU;
	   cElCompiledFonc *    mFcteurRapCoU;
	   std::string          mName;
           int                  mFlagAnglFig;

	   double                mTolAng;
	   double                mTolCentre;
           bool                  mModeGL;     // Mode Gimbal Lock
           // cMatr_Etat_PhgrF *    mSMatriceGL;     // Mode Gimbal Lock -Stantard
           // cMatr_Etat_PhgrF *    mPMatriceGL;     // Mode Gimbal Lock -Proj
           ElMatrix<double_t>        mMGL;
           bool                  mVraiBaseU;
};

// eTypeEqAppui
class cPoint3DInc : public cNameSpaceEqF,
                    public cObjFormel2Destroy
{
      public :
           cPoint3DInc(Pt3dr );
};


class cCameraFormelle :  public cNameSpaceEqF ,
                         public cObjFormel2Destroy
{
     public :
          
          void PrepareEqFForPointIm(const cIncListInterv &,cElCompiledFonc *,const Pt2dr &,bool EqDroite,int aKCam);  // Transmet a Intrinseque
          ElAffin2D & ResiduM2C();


	  void     SetCurRot(const ElRotation3D & aR2CM);
          friend class cParamIntrinsequeFormel;

	  Pt3d<Fonc_Num>   DirRayonF(Pt2d<Fonc_Num>,int aKCam);
          Pt3d<Fonc_Num>   COptF();
	  virtual ~cCameraFormelle();
	  ElRotation3D     CurRot();

	  //
	  //
	  //  Ne refait pas le calcul a chaque fois, est memorise
	  //  dans mCameraCourante ; C'est CalcCameraCourante qui 
	  //  refait le calc
	  //
	  const CamStenope * CameraCourante() const;
	  CamStenope * NC_CameraCourante() ;

          bool SameIntr(const cCameraFormelle &) const;
          cRotationFormelle &       RF();
          cParamIntrinsequeFormel & PIF();

          cSetEqFormelles & Set();
          const std::string & Name() const;
          eModeContrRot  ModeRot() const;
	  void SetModeRot(eModeContrRot);

	  // static void GenAllCode();

	  // Le resultat est un point renvoyant le vecteur de residu
	  Pt2dr  AddAppui(Pt3dr aP,Pt2dr aPIm,double_t aPds);
	         // Donne le residu mais n'ajoute pas au systeme
	  Pt2dr  ResiduAppui(Pt3dr aP,Pt2dr aPIm);

	   Pt2dr  CorrigePFromDAdd(const Pt2dr & aP1,bool UseGrid,bool ModeDr);

           class cEqAppui ;
	   cEqAppui * AddFctrEqAppuisInc(bool aGenCode,bool Proj,bool isGL,bool wDist,bool EqDr);  // Initialise si nec le fcteur
	   cEqAppui * AddForUseFctrEqAppuisInc(bool aGenCode,bool Proj,bool wDist,bool IsEqDr);  // Initialise si nec le fcteur
	   cIncListInterv & IntervAppuisPtsInc(); 
	   Pt2dr AddEqAppuisInc(const Pt2dr & aPIm,double aPds, cParamPtProj &,bool IsEqDroite);
           virtual void Update_0F2D();
           void TestVB10(const std::string& aMes) const;
           void SetGL(bool aModeGL);
           // cMatr_Etat_PhgrF &  MatRGL(bool isP) ;     // Mode Gimbal Lock
           bool IsGL() const;

	  class cEqAppui
	  {
		  public :
                      void PrepareEqFForPointIm(const Pt2dr &);  // Transmet a Camera Formelle
                      friend class cCameraFormelle;
                      cEqAppui
		      (
		           bool wDist,
		           bool isGL,
		           bool isProj,
		           bool isPTerrainFixe,
		           bool Comp,
			   cCameraFormelle &,
			   bool GenCode, 
                           bool IsEqDroite
                      );
		      void GenCode();
                      cIncListInterv & LInterv();

		      // Si P <0, n'ajoute pas au sys
		      Pt2dr Residu(Pt3dr aP1,Pt2dr aP2,double_t Pds);
		      Pt2dr ResiduPInc(Pt2dr aP2,double_t Pds,const cParamPtProj & aPPP);
		  private :

                      cCameraFormelle & mCam;
                      bool            mUseEqNoVar;
                      cIncListInterv  mLInterv;
		      bool            mIsPTerrainFixe;
		      std::string     mNameType;
		      std::string     mNameTerX;
		      std::string     mNameTerY;
		      std::string     mNameTerZ;
		      std::string     mNameStdScaleN;
		      cEqfP3dIncTmp * mEqP3I;

		      std::string     mNameImX;
		      std::string     mNameImY;

		      Pt3d<Fonc_Num>  mPTerrain;
		      Pt2d<Fonc_Num>  mPIm;
                      Fonc_Num         mFScN;
		      std::vector<Fonc_Num>        mEcarts;
                      cElCompiledFonc * mFoncEqResidu ;

		      double          * pAdrXTer;
		      double          * pAdrYTer;
		      double          * pAdrZTer;
		      double          * pAdrXIm;
		      double          * pAdrYIm;
		      double          * pAdrScN;

                      cP3d_Etat_PhgrF * mProjP0;
                      cP3d_Etat_PhgrF * mProjI;
                      cP3d_Etat_PhgrF * mProjJ;
                      cP3d_Etat_PhgrF * mProjK;
                      cMatr_Etat_PhgrF * mMatriceGL;

                      cP2d_Etat_PhgrF *  mNDP0;
                      cP2d_Etat_PhgrF *  mNDdx;
                      cP2d_Etat_PhgrF *  mNDdy;
                      bool               mEqDroite;

	  };
	  CamStenope *  DuplicataCameraCourante();
     private :
	  CamStenope *  CalcCameraCourante();
	  friend class cEqAppui;

          cCameraFormelle
          (
                 eModeContrRot,
                 ElRotation3D,
                 cParamIntrinsequeFormel &,
                 cCameraFormelle * CamAttach ,
		 const std::string & aName,
		 bool   CompEqAppui,
		 bool   GenCodeAppui,
                 bool   HasEqDroite
          );
          cCameraFormelle   *         pCamAttach;
          cParamIntrinsequeFormel &   mIntr;
          cSetEqFormelles &           mSet;
          cRotationFormelle *         mRot;
	  std::string                 mName;

          cEqAppui *                    mEqAppuiTerNoGL;
          cEqAppui *                    mEqAppuiTerGL;

          cEqAppui *                    mEqAppuiIncXY ;
          cEqAppui *                    mEqAppuiProjIncXY ;
          cEqAppui *                    mEqAppuiGLIncXY ;
          cEqAppui *                    mEqAppuiGLProjIncXY ;


          cEqAppui *                    mEqAppuiSDistIncXY ;
          cEqAppui *                    mEqAppuiSDistProjIncXY ;
          cEqAppui *                    mEqAppuiSDistGLIncXY ;
          cEqAppui *                    mEqAppuiSDistGLProjIncXY ;

          static const int TheNbEqDr = 8;
          cEqAppui *                    mEqAppuiDroite[TheNbEqDr] ; // Dist X Proj X Gl

	  CamStenope *                  mCameraCourante;


        // S'ajoute eventuellement a mGlobOrImaM2C pour  ResiduMond2Cam
         // permet de gerer les marques fiduciaire qui etant integre par modif
         // des points homols, n'interviennent pas dans la camera
         ElAffin2D                      mResiduM2C;
         bool                           mHasEqDroite;


};

class cCpleCamFormelle : public cNameSpaceEqF,
                         public cSignedEqFPtLiaison,
                         public cObjFormel2Destroy
{
     public :

          friend class cSetEqFormelles;
	  static void GenAllCode();
         // WithD2 : avec derivees secondes
          double_t AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2);

          double_t ResiduSigneP1P2(Pt2dr P1,Pt2dr P2); 
	  // Pondere en 1 / (1+ square(Residu/Ecart))
	  // Si Residu > Coupure > 0 , poids = 0


          cCameraFormelle & Cam1();
          cCameraFormelle & Cam2();
       
	  ~cCpleCamFormelle();

	  void CorrigeP1P2FromDAdd(Pt2dr & aP1,Pt2dr & aP2);
     private :

	  void GenCode();
          cCpleCamFormelle
	  (
              cCameraFormelle & aCam1,
              cCameraFormelle & aCam2,
	      eModeResidu,
	      bool Code2Gen
          );

          cCameraFormelle & mCam1;
          cCameraFormelle & mCam2;
          cSetEqFormelles & mSet;
          Pt3d<Fonc_Num>    mBaseNN;
          Pt3d<Fonc_Num>    mBaseU;
          cIncListInterv    mLInterv;
	  eModeResidu       mModeResidu;
	  Fonc_Num          mEqResidu;
	  std::string       mNameType;

          cElCompiledFonc * mFoncEqResidu ;
          double          * pAdrX1;
          double          * pAdrY1;
          double          * pAdrX2;
          double          * pAdrY2;
};



#if (0)

class cEqHomogFormelle : public  cNameSpaceEqF ,
                         public cEqFPtLiaison,
                         public cObjFormel2Destroy
{
      public :
          ~cEqHomogFormelle();
          cEqHomogFormelle
          (
                cHomogFormelle &,
                cHomogFormelle &,
                cDistRadialeFormelle &,
		bool Code2Gen
          );

         // WithD2 : avec derivees secondes
          double_t AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2);
	  double_t ResiduNonSigneP1P2(Pt2dr aP1,Pt2dr aP2);
	  Pt2dr  PtResidu(Pt2dr aP1,Pt2dr aP2);

          cHomogFormelle&       HF1();
          cHomogFormelle&       HF2();
          cDistRadialeFormelle& DRF();
          cSetEqFormelles &       Set();

          void StdRepondere(ElPackHomologue &,double_t aCoeff);
          void StdRepondere(double_t aCoeff);
          double_t MoyErreur(ElPackHomologue &);
          double_t MoyErreur();

      private :
          struct cEq
          {
              cEqHomogFormelle & mEQF;
              cElCompiledFonc * pFEq;
              double          * pAdrX1;
              double          * pAdrY1;
              double          * pAdrX2;
              double          * pAdrY2;
              std::string     mName;

	      ~cEq();
              cEq(Fonc_Num F,cEqHomogFormelle &,bool isX,bool Code2Gen);
              double_t AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2);
	      double_t ResiduSigneP1P2(Pt2dr aP1,Pt2dr aP2);
          };
          friend struct cEq;

           bool  mInSpaceInit;


          cSetEqFormelles & mSet;
          cHomogFormelle&       mHF1;
          cHomogFormelle&       mHF2;
          cDistRadialeFormelle* mDRF;

          Pt2d<Fonc_Num>        mEqHom;
          cIncListInterv        mLInterv;
          cEq*                  pFEqX;
          cEq*                  pFEqY;
};
#endif



class cEqOneHomogFormelle : public  cNameSpaceEqF ,
                         public cEqFPtLiaison,
                         public cObjFormel2Destroy
{
      public :
          ~cEqOneHomogFormelle();
          cEqOneHomogFormelle
          (
                cHomogFormelle &,
                bool Code2Gen
          );

         // WithD2 : avec derivees secondes
          double_t AddLiaisonP1P2(Pt2dr P1, Pt2dr aP2, double_t aPds,bool WithD2);
          Pt2dr StdAddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2); // Version moderne type camera
          double_t ResiduNonSigneP1P2(Pt2dr aP1,Pt2dr aP2);
          Pt2dr  PtResidu(Pt2dr aP1,Pt2dr aP2);

          cHomogFormelle&       HF();
          cSetEqFormelles &       Set();
      private :
          struct cOneHEq
          {
              cEqOneHomogFormelle & mEQF;
              cElCompiledFonc * pFEq;
              double          * pAdrX1;
              double          * pAdrY1;
              double          * pAdrX2;
              double          * pAdrY2;
              std::string     mName;

              ~cOneHEq();
              cOneHEq(Fonc_Num F,cEqOneHomogFormelle &,bool isX,bool Code2Gen);

              double_t AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2);
              double_t ResiduSigneP1P2(Pt2dr aP1,Pt2dr aP2);
              void  InitPts(Pt2dr P1,Pt2dr P2);
          };
          friend struct cOneHEq;

          cSetEqFormelles & mSet;
          cHomogFormelle&       mHF;

          Pt2d<Fonc_Num>        mEqHom;
          cIncListInterv        mLInterv;
          cOneHEq*                  pFEqX;
          cOneHEq*                  pFEqY;
};






class cEqHomogFormelle : public  cNameSpaceEqF ,
                         public cEqFPtLiaison,
                         public cObjFormel2Destroy
{
      public :
          ~cEqHomogFormelle();
          cEqHomogFormelle
          (
                bool InSpaceInit, // Si true equation H1 H2-1
                cHomogFormelle &,
                cHomogFormelle &,
                cDistRadialeFormelle *,
		bool Code2Gen
          );

         // WithD2 : avec derivees secondes
          double_t AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2);
          Pt2dr StdAddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2); // Version moderne type camera
	  double_t ResiduNonSigneP1P2(Pt2dr aP1,Pt2dr aP2);
	  Pt2dr  PtResidu(Pt2dr aP1,Pt2dr aP2);

          cHomogFormelle&       HF1();
          cHomogFormelle&       HF2();
          cDistRadialeFormelle& DistRF();
          cDistRadialeFormelle*   DRF();
          cSetEqFormelles &       Set();

          void StdRepondere(ElPackHomologue &,double_t aCoeff);
          void StdRepondere(double_t aCoeff);
          double_t MoyErreur(ElPackHomologue &);
          double_t MoyErreur();

      private :
          Pt2d<Fonc_Num> ComposeDRF (Pt2d<Fonc_Num> aP);
          struct cEq
          {
              cEqHomogFormelle & mEQF;
              cElCompiledFonc * pFEq;
              double          * pAdrX1;
              double          * pAdrY1;
              double          * pAdrX2;
              double          * pAdrY2;
              std::string     mName;

	      ~cEq();
              cEq(Fonc_Num F,cEqHomogFormelle &,bool isX,bool Code2Gen);
              double_t AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2);
	      double_t ResiduSigneP1P2(Pt2dr aP1,Pt2dr aP2);
          };
          friend struct cEq;

                          
          bool              mInSpaceInit;
          cSetEqFormelles & mSet;
          cHomogFormelle&       mHF1;
          cHomogFormelle&       mHF2;
          cDistRadialeFormelle* mDRF;

          Pt2d<Fonc_Num>        mEqHom;
          cIncListInterv        mLInterv;
          cEq*                  pFEqX;
          cEq*                  pFEqY;
};




// Class pour resoudre de maniere simplifiee, l'equation homographique

/*
    Cette classe se specialise dans la resolution
   de l'equation

       Hom1 (Dist(P1)) =  Hom2 (Dist(P2))

*/




class  cLEqHomOneDist
{
      public :
         cLEqHomOneDist(double_t aDiag);
         void AddCple(const ElPackHomologue &);

         // Calcul un score, en mettant tous les parametres a leur valeur
         // initiale sauf le centre fige a aCentre


         cDistRadialeFormelle *    DRF();


         double_t  NStepOpt(int aNb,bool CentreFiged);
         void PondereFromErreur(double_t aDCut);
         void CloseSet();

      protected :
         // Met dans le systeme toute les equation de laison + contrainte
         // renvoie la moyenne des equation de liaisons

         void AddLiaisonOnTop(Pt2dr aP1,Pt2dr aP2,double_t aPds);
         double_t AddAllEquationsToSet();
         cSetEqFormelles * Set();

         void AddHomogF(cHomogFormelle *);
         void AddEqF(cEqHomogFormelle *);

         double_t                              mDiag;
         std::vector<cEqHomogFormelle *>   mEqFs;
         std::vector<ElPackHomologue *>    mLiaisons;

         std::vector<cHomogFormelle *>     mHomFs;
         std::vector<cElHomographie >      mHomInits;

         cSetEqFormelles              mSet;
         ElDistRadiale_PolynImpair mDistInit;
         bool                      mCentreFige;
         int                       mDegreDRFFiged;
         cDistRadialeFormelle *    mDRF;

         bool                      mDerSec;

};




class cPolynFormelXY;
class cDistFormelPolXY  : public cNameSpaceEqF
{
       public :
           cDistFormelPolXY
           (
	       const ElDistortionPolynomiale & aDist,
               cSetEqFormelles & aSet
           );
           ~cDistFormelPolXY();
           Pt2d<Fonc_Num> operator () (Pt2d<Fonc_Num> aP);
              
           int Degre() const;
           cMultiContEQF      StdContraintes() ;
           void SetFige(int DegreMax,bool Std);
	              
	   ElDistortionPolynomiale DistCur() const;
       private :
           int              mDegre;
           int              mDegreFige;
           cPolynFormelXY * mPolX;
           cPolynFormelXY * mPolY;
};


class cParamIFDistPolynXY : public cParamIntrinsequeFormel
{
      public :
          virtual std::string  NameType() const;
          virtual ~cParamIFDistPolynXY();

          cMultiContEQF      StdContraintes() ;
          void SetFige(int DegreMax);
	   ElDistortionPolynomiale DistCur() const;

	  friend class cSetEqFormelles;

	   CamStenope * CurPIF() ;
	   CamStenope * DupCurPIF();
	   cCamStenopeDistPolyn *  CurPIFPolyn();
	   virtual void    UpdateCurPIF();
	   void    NV_UpdateCurPIF();   // Non virtuel, pour appel constructeur
      private :
          cParamIFDistPolynXY(bool IsC2M,cCamStenopeDistPolyn *,cSetEqFormelles & aSet);
          cDistFormelPolXY  mDist;

	  cCamStenopeDistPolyn * mCurPIF;
          virtual  Pt2d<Fonc_Num> VDist(Pt2d<Fonc_Num>,int aKCam);
};



class  cTFI_AttrSom
{
       public :
              

          // static cTFI_AttrSom * Som2D(cSetEqFormelles &,Pt2dr aPos,Pt2dr aVal);
	  cTFI_AttrSom (cSetEqFormelles &,Pt2dr aPosistion,const std::vector<double> & aVInit);



	  const cIncIntervale &   Interv() const;
	  int Dim() const;
	  const Pt2dr &                 PosPt() const;
	  const std::vector<Fonc_Num> & Incs() const;
	  const std::vector<double> &   ValsInc() const;

	  Pt2dr                   ValCurAsPt()  const;
	  Pt2d<Fonc_Num>          ValsIncAsPt()  const;


	  Fonc_Num   ValsIncAsScal() const;
	  Pt3dr  P3ValAsZ() const;

          void SetValCurPt(cSetEqFormelles & aSet,const Pt2dr &); // SetPCur
              
          cSetEqFormelles &     Set();
       private :
          void AssertD1() const;
          void AssertD2() const;


          cTFI_AttrSom(const cTFI_AttrSom &);

          cSetEqFormelles &     mSet;
	  cIncIntervale         mInterv;
          Pt2dr                 mPos;
	  std::vector<double>   mValsInc;
          int                   mNumInc;
	  int                   mDim;
	  std::vector<Fonc_Num> mIncs;

	  /*
          Pt2dr          mPtInit;
          Pt2dr          mPtCur;
          int            mNumInc;
          Pt2d<Fonc_Num> mPtInc;
	  */
};

class cTFI_Triangle
{
      public :
         static cTFI_Triangle * NewOne(cTFI_AttrSom & ,cTFI_AttrSom & ,cTFI_AttrSom &);
         const cElTriangleComp & TriGeom() const;

         std::vector<double>  InterpolVals(const Pt2dr & aP) const;

          const std::vector<Fonc_Num> & Inc1() const;
          const std::vector<Fonc_Num> & Inc2() const;
          const std::vector<Fonc_Num> & Inc3() const;

	  const cIncIntervale &   IntervA1 () const;
	  const cIncIntervale &   IntervA2 () const;
	  const cIncIntervale &   IntervA3 () const;

	  const cIncIntervale &   IntervB1 () const;
	  const cIncIntervale &   IntervB2 () const;
	  const cIncIntervale &   IntervB3 () const;
	  int Dim() const;
         cSetEqFormelles &     Set();

     // Si dim=1 et les inconnue sont des Z, renvoie le plan passant par
     // les trois points
	 cElPlan3D CalcPlancCurValAsZ() const;
	 cTFI_AttrSom & S1();
	 cTFI_AttrSom & S2();
	 cTFI_AttrSom & S3();

          // Indexes de  x1 y1 x2 y2 x3 y3
          // const std::vector<int> &  VecOfIndexe() const;

      private :

         cTFI_Triangle(cTFI_AttrSom & ,cTFI_AttrSom & ,cTFI_AttrSom &);
         cTFI_Triangle(const cTFI_Triangle &) ; // Not Implemanted

         int              mDim;
	 cTFI_AttrSom &   mA1;
	 cIncIntervale    mIntervA1;
	 cIncIntervale    mIntervB1;

	 cTFI_AttrSom &   mA2;
	 cIncIntervale    mIntervA2;
	 cIncIntervale    mIntervB2;

	 cTFI_AttrSom &   mA3;
	 cIncIntervale    mIntervA3;
	 cIncIntervale    mIntervB3;


         cElTriangleComp  mTri;
         // std::vector<int>   mVIndexe;
};



// Classe d'Interface
//
//  Une triangulation formelle peut etre de dimension qcq sur les attribut
//  (parametre Dim), ce n'est que lorsque Dim=2 qu'elle herite pertinement
//  de ElDistortion22_Gen 
//
class cTriangulFormelle : public ElDistortion22_Gen,
	                  public cElemEqFormelle,
                          public cObjFormel2Destroy
{
      public :
        virtual void SetAllPtCur(const ElDistortion22_Gen &) =0;
        virtual ~cTriangulFormelle() ;
        std::vector<double> ValsOfPt(const Pt2dr &  aP) const;  // Direct
	Pt2dr Direct(Pt2dr  aP) const;  // En dim 2 pour heriter de ElDistortion22_Gen,

	static void Test();
	virtual cTFI_Triangle & GetTriFromP(const Pt2dr & aP) const = 0;
	virtual void TestOneTri() = 0;
	// Renvoie un point  dans la tri, + ou - au centre, a priori
	// le barry mais sans garantie
	virtual Pt2dr APointInTri() const =0;
	virtual void Show() =0;
	virtual void Show(ElPackHomologue) =0;

	// Renvoie un sommet central, le plus proche de la  BBbox
	// virtual cTFI_AttrSom  & SomCentral() =0;
	// Renvoie un sommet aS2 tq (aS1 aS2) soit horizontal et assez grand
	// virtual cTFI_AttrSom  & SomVecHorz(cTFI_AttrSom & aS1) =0;
	// 
	// int 

          cSetEqFormelles & Set();
	  // Contraintes pour bloquer un mouvement de rotation
          cMultiContEQF      ContraintesRot() ;
	  // Contraintes pour bloquer tous les sommets
          cMultiContEQF      ContraintesAll() ;
	  virtual void SetTolMax(double_t) =0;
          const  std::vector<cTFI_Triangle *> & VTri() const;

	  void AssertD2() const;
      protected :
          cTriangulFormelle(int aDim,cSetEqFormelles & aSet);

	  cSetEqFormelles & mSet;
          std::vector<cTFI_Triangle *> mVTri;
	  const int     mDim;
      private :
	  virtual cTFI_AttrSom * SomCentral() = 0;
	  virtual cTFI_AttrSom * VecHorz() = 0;
	  void  Diff(ElMatrix<double_t> &,Pt2dr) const ; // Non implantee

	  double  mTrianFTol;
};







// Les Grids ne peuvent pas (simplement) etre utlisees comme
// les autres distorsions parce qu'elle necessite un manipulation
// non standard des indices (le jeux des indices d'inconnues
// intervennant dans les equation depends du (ou des) triangles
// en jeux. Par ailleurs, il n'ont pas de raison d'avoir une
// focale ou un point principal variable.



class cAppuiGridEq : public cNameSpaceEqF,
                     public cObjFormel2Destroy
{
     public :
	  void   GenCode();
	  Pt2dr  AddAppui(Pt3dr aP,Pt2dr aPIm,double_t aPds);
	         // Donne le residu mais n'ajoute pas au systeme
	  Pt2dr  ResiduAppui(Pt3dr aP,Pt2dr aPIm);

     private  :
          cAppuiGridEq
          (
              cTriangulFormelle &, 
	      cRotationFormelle &,
	      bool Code2Gen
	  );
         friend class cSetEqFormelles;
	 Pt2d<Fonc_Num>        ResiduForm();

	 static const std::string NamePds1;
	 static const std::string NamePds2;
	 static const std::string NamePds3;
	 static const std::string NameTerX;
	 static const std::string NameTerY;
	 static const std::string NameTerZ;

	 cSetEqFormelles &     mSet;
	 cTriangulFormelle &   mTri;
	 cRotationFormelle &   mRot;
         double          *     pAdrPds1;
         double          *     pAdrPds2;
         double          *     pAdrPds3;
         double          *     pAdrXTer;
         double          *     pAdrYTer;
         double          *     pAdrZTer;
         cIncListInterv        mLInterv;
         cElCompiledFonc *     mFoncEq;
	 std::string           mNameType;
};

class cCpleGridEq : public cNameSpaceEqF,
                    public cSignedEqFPtLiaison,
                    public cObjFormel2Destroy
{
      public :
          double_t AddLiaisonP1P2(Pt2dr P1,Pt2dr P2,double_t aPds,bool WithD2);
          double_t ResiduSigneP1P2(Pt2dr P1,Pt2dr P2); 

	  void   GenCode();
	  // static void   GenAllCode();
	  // static void   GenAllCode(eModeResidu);

         friend class cSetEqFormelles;


      private :


          void  SetP1P2(Pt2dr P1,Pt2dr P2); 
	  Fonc_Num   EqCoPlan();
          cCpleGridEq
          (
              cTriangulFormelle &, cRotationFormelle &,
              cTriangulFormelle &, cRotationFormelle &,
	      eModeResidu aModeResidu,
	      bool Code2Gen
          );
	  
	  static const std::string NamePdsA1;
	  static const std::string NamePdsA2;
	  static const std::string NamePdsA3;
	  static const std::string NamePdsB1;
	  static const std::string NamePdsB2;
	  static const std::string NamePdsB3;


	  cSetEqFormelles & mSet;
	  cTriangulFormelle &   mTriA;
	  cRotationFormelle &   mRotA;
	  cTriangulFormelle &   mTriB;
	  cRotationFormelle &   mRotB;
          cIncListInterv        mLInterv;
          cElCompiledFonc *     mFoncEqCoP;

          double          *     pAdrPdsA1;
          double          *     pAdrPdsA2;
          double          *     pAdrPdsA3;

          double          *     pAdrPdsB1;
          double          *     pAdrPdsB2;
          double          *     pAdrPdsB3;
	  eModeResidu           mModeResidu;
	  std::string           mNameType;
};



class cEqEllipseImage : public cElemEqFormelle,
	                public cObjFormel2Destroy
{
      public :
          double_t GraySynt(double_t aX,double_t aY);
          double_t AddEq(double_t aX,double_t aY,double_t aGray,double_t Pds=1, bool WithD2=false);
	  Pt2dr CurCentre() const;
	  double_t  CurA() const;
	  double_t  CurB() const;
	  double_t  CurC() const;
	  double_t  CurLarg() const;
	  double_t  CurBlanc() const;
	  double_t  CurNoir() const;
	  bool OkCurEllispe() const;

	  void SetCentre(Pt2dr);
	  void SetA(double_t);
	  void SetB(double_t);
	  void SetC(double_t);
	  void SetLarg(double_t);
	  void SetBlanc(double_t);
	  void SetNoir(double_t);

          cMultiContEQF  ContrFigeABC();
          cMultiContEQF  ContrFigeLarg();

	  const cMirePolygonEtal & Mire() const;
	  // Si Fact > 1 donne ellipse plus grande
	  Box2dr  BoxCurEllipse(double_t Fact=1.0) const;
	  double_t SurfIER(Pt2dr aP,double_t Fact=1.0,double_t Larg=-1) const;

      private :
	  struct  cVarRay
	  {
		  cVarRay(int aNum);

		  cVarSpec    mFRay;
		  double *    mAdrVar;

	  };

          void GenCode();
          friend class  cSetEqFormelles ;
          cEqEllipseImage
          (
             cSetEqFormelles &,
	     const cMirePolygonEtal &,
             Pt2dr aCentre,
             double_t  anA,
             double_t  aB,
             double_t  aC,
             double_t  aLarg,
             double_t  aBlanc,
             double_t  aNoir,
	     bool  Code2Gen
          );
	               
	      
	  const cMirePolygonEtal & mMire;
          std::string mNameType;
          cSetEqFormelles &       mEq;
          AllocateurDInconnues &  mAlloc;
	  int   mI0;
	  int   mIndCentre;
          Pt2dr mCentre;
          Pt2d<Fonc_Num> fCentre;
	  int      mIndA;
          double_t     mA;
          Fonc_Num fA;
	  int      mIndB;
          double_t     mB;
          Fonc_Num fB;
	  int      mIndC;
          double_t     mC;
          Fonc_Num fC;
	  int      mIndLarg;
          double_t     mLarg;
          Fonc_Num fLarg;
          Pt2d<Fonc_Num> fPLarg;
          std::string mNPX;
          std::string mNPY;


          Pt2d<Fonc_Num> fCPIX;
          Pt2d<Fonc_Num> fP0;
          Pt2d<Fonc_Num> fP1;
	  int       mIndBlanc;
          double_t      mBlanc;
          Fonc_Num  fBlanc;
	  int       mIndNoir;
          double_t      mNoir;
          Fonc_Num  fNoir;
          std::string mNGR;
          Fonc_Num    fGray;
	  std::vector<cVarRay>    mVarsRays;
          Fonc_Num    fNumEqResidu;
          cElCompiledFonc * mFctrEqResidu;
          cIncListInterv    mLInterv;
          double *          pAdrX;
          double *          pAdrY;
          double *          pGray;
	            
          // static const int theNbDiam = 7;
          // static double theDiams[theNbDiam];
          
	  std::vector<cVarRay>  VarsRays();
          Fonc_Num              EqResidu();
};







class cLIParam_Image : public cObjFormel2Destroy
{
	public :
		friend class cSetEqFormelles;
		cRotationFormelle & Rot();
		cSetEqFormelles & Set();
		void UpdateCam();
		Im2D_double_t4 Im();
	        Pt2dr  Ray2Im(Pt3dr);
	        Pt3dr  Im2Ray(Pt2dr);

		void SetImZ(Im2D_double_t4 anIm,double_t aZ);


	private  :
		
                void Update_0F2D();
		cLIParam_Image
	        (
		    cSetEqFormelles &,
		    Im2D_double_t4   anIm,
		    double_t         aZoom,
		    CamStenope & aCam,
                    cNameSpaceEqF::eModeContrRot
		);

		CamStenope &      Cam();
		cLIParam_Image (const cLIParam_Image &); // NI
		cSetEqFormelles &    mSet;
		cRotationFormelle *  pRot;
		Im2D_double_t4           mIm;
		double_t                 mZoom;
		CamStenope &        mCam;
};


class cLI_MakeEqIm
{
      public :
	      friend class cEqVueLaserImage;
      private:
	      cLI_MakeEqIm
	      (
	           const std::string &      aPref,
		   cLIParam_Image &              anIm,
                   bool Normalize, // Si faux pas de normalisation Moy/Ect
		   int        aNbPts,
                   cRotationFormelle * aRotPts
	      );
	      Fonc_Num     FRad();
	      Fonc_Num              KthRad(int aK);
              void InitAdr(cElCompiledFonc *);
	      bool  InitEquations(std::vector<Pt3dr>,int Offset,const ElRotation3D &);


              struct  cPts
	      {
                    cPts
                    ( 
                          const std::string &   aPref,
                          int,
                          cRotationFormelle &,
                          cRotationFormelle * aRotPts
                    );
		    void InitAdr(cElCompiledFonc *);
		    Fonc_Num  RadiomOfP(Pt3d<Fonc_Num> aP);

	            cRotationFormelle &   mRotIm;
	            cRotationFormelle *   mRotPts;
		    cVarSpec  m0;
		    cVarSpec  mU;
		    cVarSpec  mV;
		    cVarSpec  mX;
		    cVarSpec  mY;
		    cVarSpec  mZ;
		    Fonc_Num  mRad;

		    double * mAdr0;
		    double * mAdrU;
		    double * mAdrV;
		    double * mAdrX;
		    double * mAdrY;
		    double * mAdrZ;
	      };


	      cLI_MakeEqIm(const cLI_MakeEqIm &); // NI
	      bool InitOneEquation(Pt3dr aP,cPts &,const ElRotation3D & aRot);

	      std::string           mPref;
	      cLIParam_Image &      mIm;
	      cRotationFormelle &   mRot;
	      std::vector<cPts*>    mIncPts;
	      Fonc_Num              mMoy;
	      Fonc_Num              mEct;
	      Fonc_Num              mRadC;
              ElMatrix<double_t>        mMat;
              bool                  mNormalize;
};


class cEqVueLaserImage : public cObjFormel2Destroy
{
	public :
		friend class cSetEqFormelles;
		double_t AddAllEquations(std::vector<Pt3dr>,double_t aPds,double_t aTime=0);
	private:

                ElRotation3D       CurRotPtsOfT(double_t aT);
                void Update_0F2D();
	        cEqVueLaserImage
	        (
                        cRotationFormelle * aRotPts,
                        bool Multi,
                        bool Normal, // Si faux pas de normalisation Moy/Ect
                        int aNbPts,
                        cLIParam_Image &,
                        cLIParam_Image &,
                        bool GenCode = false
                );
		cEqVueLaserImage(const cEqVueLaserImage &); // Non Implemenate

		cSetEqFormelles &  mSet;
		cLI_MakeEqIm       mMakA;
		cLI_MakeEqIm       mMakB;
                cRotationFormelle * mRotPts;
		std::string        mName;
		Fonc_Num           mEq;
		cIncListInterv     mLInterv;
		cElCompiledFonc *  mFoncEq;
                bool               mMulti;
                double_t *             mAdrTimeRot;
                bool               mNormalize;

};


struct  cElemEqCorrelGrid 
{
            cElemEqCorrelGrid
            (
	         cSetEqFormelles & aSet,
		 int               aNum,
                 bool              GenCode
            );
	    void InitAdr(cElCompiledFonc *,bool Im2MoyVar);

	    std::string    mNN;  // Name Num
	    cIncIntervale  mInterv;
	    std::string    mNameGr1;
	    std::string    mNameGr2of0;
	    std::string    mNameDGr2Dz;
	    std::string    mNameZCur;

	    cVarSpec       mGr1;
	    cVarSpec       mGr2of0;
            cVarSpec       mDGr2Dz;
            cVarSpec       mZCur;
	    double *       mAdrGr1;
	    double *       mAdrGr2Of0;
	    double *       mAdrDGr2Dz;
	    double *       mAdrZCur;
            Fonc_Num       mZ;
            Fonc_Num       mGr2ofZ;
            Fonc_Num       mGr2ofZCur;
};

class cEqCorrelGrid  : public cObjFormel2Destroy
{
	public :
            friend class cSetEqFormelles;
	    static std::string NameType(int aNbPix,bool Im2MoyVar);
	    cElemEqCorrelGrid & KthElem(int aK);
            cElCompiledFonc * Fctr();
	private :
	    cEqCorrelGrid(const cEqCorrelGrid &); // Not Impl
	    cEqCorrelGrid
            (
	        cSetEqFormelles & aSet,
	        int aNbPix,
		bool Im2MoyVar,
		bool GenCode
            );
	    cSetEqFormelles &              mSet;
            cIncListInterv                 mLInterv;
	    int                            mNbPix;
	    std::vector<cElemEqCorrelGrid> mVPix;
	    bool                           mIm2MoyVar;
	    bool                           mGenCode;
	    std::string                    mNameType;
            cElCompiledFonc *              mFoncEq;
};

/*
class cEqRegulD1  : public cObjFormel2Destroy
{
     public :
	    friend class cSetEqFormelles;
     private :
	    std::string                    mNameType;
            cElCompiledFonc *              mFoncEq;

};
*/

class cGridIncImageMnt  : public cObjFormel2Destroy
{
	public :
             cGridIncImageMnt
		     (
		          Pt2di    aSzI1,
			  Fonc_Num fZCur,
		          Fonc_Num fHomZ0,
		          Fonc_Num fDzHom,
			  Fonc_Num fI1,
		          Pt2di    aSzI2,
			  Fonc_Num fI2
		     );

	     static  cGridIncImageMnt * StdFromFile(const std::string &  aPref);

	     void MakeI2G1();

	     Flux_Pts  All1();
	     Flux_Pts  All2();
	     Fonc_Num  fHomOfZ0();
             Fonc_Num  fDerZ();
             Fonc_Num  fHomOfZ(Fonc_Num fZ);
	     Fonc_Num  fHomOfCurZ();
	     Fonc_Num  fI2GeoI1();
	     Fonc_Num  fSupI1I2();
	     void SauvAll(const std::string & aPrefix);

	     void OneStepEqCorrel(double_t aPds,int aSzVgn,bool Im2Var,int anEcart=1);
	     void OneStepRegulD2 (double_t aPds);
	     void OneStepRegulD1 (double_t aPds);
	     void OneStepRapCur  (double_t aPds);

	     void SolveSys();
	     void InitIncs(double_t);
	     void SetEps(double_t);

             Im2D_double_t8   CurZ();

	protected :
	     inline double_t CurZ(Pt2di aP) const;
	     inline double_t XHomZ0(Pt2di aP) const;
	     inline double_t YHomZ0(Pt2di aP) const;
	     inline double_t Hom_dXdZ(Pt2di aP) const;
	     inline double_t Hom_dYdZ(Pt2di aP) const;
	     inline Pt2dr  HomOfZ0(Pt2di aP) const;
	     inline Pt2dr DerZ(Pt2di aP) const;
	     inline Pt2dr HomOfZ(Pt2di aP,double_t aZ) const;
	     inline Pt2dr HomOfCurZ(Pt2di aP) const;

	     void SetSizeGeom();
	     void CalcGeomI1();


	     Pt2di        mSzI1;
             Im2D_double_t8   mCurZ;
	     double_t8 **     mDCurZ;

             Im2D_double_t4   mXHomZ0;
	     double_t4 **     mDXHomZ0;
             Im2D_double_t4   mYHomZ0;
	     double_t4 **     mDYHomZ0;

             Im2D_double_t4   mHom_dXdZ;
	     double_t4 **     mDHom_dXdZ;
             Im2D_double_t4   mHom_dYdZ;
	     double_t4 **     mDHom_dYdZ;

             Im2D_U_int1  mIm1;
	     U_int1 **    mDIm1;

	     Pt2di        mSzI2;
             Im2D_U_int1  mIm2;
	     U_int1 **    mDIm2;

             Im2D_double_t4   mI2G1;
	     double_t4 **     mDI2G1;
             Im2D_double_t4   mDi2g1Dz;
	     double_t4 **     mDDi2g1Dz;
             Im2D_U_int1  mOK;
             U_int1 **    mDOK;
 
	     cSetEqFormelles  * pSetIncs;
	     Im2D_int4          mNumsZInc;
	     int4 **            mDNZI;

	     cElCompiledFonc * pRegD1;
	     cElCompiledFonc * pRegD2;
	     cElCompiledFonc * pRapCur;
	     static cCIKTabul  TheCIK;
};

class cAllocNameFromInt;
class cEqFormelleLineaire
{
     public :
	     friend class cSetEqFormelles;
	     void AddEqNonIndexee
		  (
                        double_t Cste,
                        double_t * Val,
                        double_t aPds,
                        const std::vector<int>  & VIncs
                   );
	     void AddEqIndexee
		  (
                        double_t Cste,
                        double_t * Val,
                        double_t aPds,
                        const std::vector<int>  & VIncs
                   );


     private :
	     cEqFormelleLineaire(const cEqFormelleLineaire &); // NI
	     cEqFormelleLineaire(cSetEqFormelles &,int aNbInc,int aNbVT,bool GenCode);
	     static cAllocNameFromInt    TheNK;
	     static std::string          TheNameCste;

	     int                         mNbInc;
	     cSetEqFormelles &           mSet;
	     std::vector<cIncIntervale>  mIntervs;
	     cIncListInterv              mLInterv;
	     double *                    mAdrCste;
	     std::vector<double *>       mAdrCoeff;
	     std::string                 mNameType;
             cElCompiledFonc *           mFctr ;

};

class cSomBilin
{
     public :
        cSomBilin(cSetEqFormelles &,Pt2dr &,const cIncIntervale & anInt);

        Pt2d<Fonc_Num>   mPtF;
        cIncIntervale    mInterv;

};

class cQuadrangle
{
      public :
           cQuadrangle
           (
                   const cIncIntervale & aI00,
                   const cIncIntervale & aI10,
                   const cIncIntervale & aI01,
                   const cIncIntervale & aI11
           );
           cIncIntervale    mInt00;
           cIncIntervale    mInt10;
           cIncIntervale    mInt01;
           cIncIntervale    mInt11;
};


class cPIF_Bilin : public cParamIntrinsequeFormel
{
     public :
         cPIF_Bilin(cCamStenopeBilin *,cSetEqFormelles &);
         static cPIF_Bilin * Alloc(const cPIF_Bilin &,cSetEqFormelles &);

         void SetDistFigee();
         void SetDistFree(int aDegree);

     private  :
          // virtual Fonc_Num  NormGradC2M(Pt2d<Fonc_Num>); a priori inutile
          virtual void PrepareEqFForPointIm(const cIncListInterv &,cElCompiledFonc *,const Pt2dr &,bool EqDroite,int aKCam);
          virtual  Pt2d<Fonc_Num> VDist(Pt2d<Fonc_Num>,int aKCam);
          void    NV_UpdateCurPIF();   // Non virtuel, pour appel constructeur ????
          virtual void    UpdateCurPIF();
          virtual bool IsDistFiged() const;
          virtual std::string  NameType() const;
          virtual ~cPIF_Bilin();
          virtual CamStenope * CurPIF(); ;
          virtual CamStenope * DupCurPIF(); ;
          virtual cMultiContEQF  StdContraintes();

          virtual void AddToListInterval(cIncListInterv & aLInterv);
          // virtual bool UseSz() const; ==> A priori 
/*




*/

          cSomBilin & FDist(const Pt2di & aP);

       // ==============================================
          static const std::string TheNameType ;
       // ==============================================
          cSetEqFormelles &                            mSet;
          std::vector<cP2d_Etat_PhgrF>                 mCornF; // Size 8, pour eventuelleme,t gerer aKCam=1
          bool                                         mFiged;
          int                                          mDegreFree;
          cDistorBilin                                 mDistInit;
          cDistorBilin                                 mDistCur;
          cCamStenopeBilin *                           mCurPIF;
          // std::vector<Pt2d<Fonc_Num>  >                mFVDist;
          std::vector<std::vector<cSomBilin > >        mFVDist;
          std::vector<std::vector<cQuadrangle > >      mQuads;

          std::vector<cElCompiledFonc* >               mFctrRegul;

          // Index des deux point qui doivent etre figee arbirtairemnt pour fixer PP,Focale, Rotation
          // situes sur les extre de la ligne horiz coupant la capteur en 2
          int                                          mIndFrozen0;
          int                                          mIndFrozen1;

          Pt2di                                        mLastCase;
          // cIncListInterv                               mLInterv;
          // cCamStenopeBilin                             
};



#endif  // _PHGR_FORMEL_H_
