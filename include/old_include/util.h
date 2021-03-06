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

#ifndef _ELISE_UTIL_H
#define _ELISE_UTIL_H

#include <general/sys_dep.h>
#include <general/opt_debug.h>

#include <string>
#include <cstring>
#include <vector>
#include <istream>
#include <sstream>
#include <iostream>
#include <list>
#include <map>

class tFileOffset;

extern const  std::string  TheFileMMDIR;  // MicMacInstalDir
void AnalyseContextCom(int argc,char ** argv);
void MMD_InitArgcArgv(int argc,char ** argv,int aNbArgMin=-1);
int NbProcSys();

extern void mem_raz(void *,tFileOffset);

extern int MemoArgc;
extern char ** MemoArgv;
extern std::string SubstArgcArvGlob(int aKSubst,std::string aSubst);


std::string GetUnikId();
std::string Dir2Write();

void ElExit(int aLine,const char * aFile,int aCode,const std::string & aMessage);
#define ElEXIT(aCode,aMessage) ElExit(__LINE__,__FILE__,aCode,aMessage)
//  Il existe des exit qui n'ont pas besoin d'etres traces, par exemple sur les help
#define StdEXIT(aCode)  exit(aCode)

void AddMessErrContext(const std::string & aMes);

int mm_getpid();

#define MEM_RAZ(x,nb) mem_raz((void *)(x),(nb)*sizeof(*(x)))


void test();
// constantly redefined to perform some test;

extern double Delay_Brkp;
void SleepProcess(double);
#define BRKP \
{\
	std::cout << "BRKP at " << __LINE__ << " of " << __FILE__ << "\n";\
    if (Delay_Brkp>0)\
        getchar();\
}

/*

    This file contains miscellaneous utilitaries
    (class and functions).

*/

const int INDEX_NOT_FOUND = -1;

// FBoolA = "Fuzzy boolean" = boolean + option Fundef (ie undefined)

class FBool
{
    public :
       static const FBool True;
       static const FBool MayBe;
       static const FBool False;

      FBool operator || (const FBool & F2)  const
      {
         return FBool((mVal > F2.mVal) ? mVal : F2.mVal);
      }
      FBool operator && (const FBool & F2)  const
      {
         return FBool((mVal < F2.mVal) ? mVal : F2.mVal);
      }
      bool operator == (const FBool & F2)  const
      {
         return mVal == F2.mVal;
      }
      bool operator != (const FBool & F2)  const
      {
         return mVal != F2.mVal;
      }

      bool  BoolCast()
      {
           if ((*this)==True) return true;
           if ((*this)==False) return false;

           ELISE_ASSERT(false,"FBool::BoolCast , val is MayBe");
           return false;
      }




    private :
       FBool(U_int1);
       U_int1    mVal;
};


template <class Type> class Pt2d;


// Pour contourner le warning  [-Werror=unused-but-set-variable] de Gcc 4.6
template <class Type> void GccUse(const Type & ) {}



/*************************************************************/
/* template &        : ElMax,ElMin, ElSwap                   */
/*************************************************************/

/* Round to nearest integer. round_ni(0.5) = 1.
*/


// return the smallest integral value >= r
template<class Type> inline Type Tpl_round_up(double_t r)
{
       Type i = (Type) r;
       return i + (i < r);
}
inline int round_up(double_t r) { return Tpl_round_up<int>(r); }
inline long int lround_up(double_t r) { return Tpl_round_up<long int>(r); }


// return the smallest integral value > r
template<class Type> inline Type Tpl_round_Uup(double_t r)
{
       Type i = (Type) r;
       return i + (i <= r);
}
inline int round_Uup(double_t r) { return Tpl_round_Uup<int>(r); }


// return the highest integral value <= r
template<class Type> inline Type Tpl_round_down(double_t r)
{
       Type i = (Type) r;
       return i - (i > r);
}
inline int round_down(double_t r) { return Tpl_round_down<int>(r); }
inline long int lround_down(double_t r) { return Tpl_round_down<long int>(r); }

// return the highest integral value < r
template<class Type> inline Type Tpl_round_Ddown(double_t r)
{
       Type i = (Type) r;
       return i - (i >= r);
}
inline int round_Ddown(double_t r) { return Tpl_round_Ddown<int>(r); }



// return the integral value closest to r
// if r = i +0.5 (i integer) return i+1
template<class Type> inline Type Tpl_round_ni(double_t r)
{
       Type i = (Type) r;
       i -= (i > r);
       return i+ ((i+0.5) <= r) ;
}

inline int round_ni(double_t r) { return Tpl_round_ni<int>(r); }
inline long int lround_ni(double_t r) { return Tpl_round_ni<long int>(r); }
/*
inline intByte8 ll_round_ni(double_t r)
{
       intByte8 i = (intByte8) r;
       i -= (i > r);
       return i+ ((i+0.5) <= r) ;
}
*/





// return the integral value closest to r
// if r = i +0.5 (i integer) return i
inline int round_ni_inf(double_t r)
{
       int i = (int) r;
       i -= (i > r);
       return i+ ((i+0.5) < r) ;
}

inline double_t signed_frac(double_t r)
{
    r = r -int(r);
    if (r<-0.5) r++;
    if (r>0.5) r--;
    return r;
}

// return the real division of a by b; eq
// complies with the mathematical property
//     b*r <= a < b * (r+1)
//   Unpredictable for b < 0.

inline int Elise_div(int a,int b)
{
       int res = a / b;
       return res - ((res * b) > a);
}

// work only when b > 0

inline int mod(int a,int b)
{
    int r = a%b;
    return (r <0) ? (r+b) : r;
}

inline int round_up(int a,int b)
{
   return ((a+b-1)/b)*b;
}

#if ((-1 & 255) == 255)
inline int mod256(int a) { return a & 255; }
#else
inline int mod256(int a) { return mod(a,256);}
#endif

// work only also when b < 0
inline int mod_gen(int a,int b)
{

    int r = a%b;
    return (r <0) ? (r+ ((b>0) ? b : -b)) : r;
}


inline int arrondi_inf(int a,int b)
{
   return (a/b)*b;
}

inline int arrondi_ni(int a,int b)
{
   return ((a+b/2)/b)*b;
}

inline int arrondi_sup(int a,int b)
{
   return ((a+b-1)/b)*b;
}

double arrondi_inf(double aVal,double aPer);
double arrondi_sup(double aVal,double aPer);
double arrondi_ni(double aVal,double aPer);

inline double_t mod_real(double_t a,double_t b)
{
   double_t res =  a - b *round_down(a/b);
   while (res>=b) res -= b;
   while (res<0) res += b;
   return res;
}

class cDecimal
{
    public :
        cDecimal(int aMant,int aPow);
        double RVal() const;
        const int &    Mant() const;
        const int &   Exp() const;
        double Arrondi(double aV) const;
      // T.Q RVAl = mMant * Mul10() / Div10()
        long int Mul10() const;
        long int Div10() const;
    public :
        int mMant;
        int mExp;
};



cDecimal StdRound(const double & aD,int aNbDigit,int * aTabR,int aSizeR);
cDecimal StdRound(const double & aD);


double_t angle_mod_real(double_t a,double_t b);


double_t Pow(double_t,int);
int Pow_of_2_sup(int);
extern bool is_pow_of_2(int );
int NbBitsOfFlag(int aFlag);

double_t El_logDeux(double_t);



template <class Type> void binarise(Type *,Type,int);
template <class Type> void binarise(Type *,const Type *,Type,int);
template <class Type> void neg_binarise(Type *,const Type *,Type,int);


template <class Type> void set_fonc_id(Type *,Type v0,int);

template <class Type> bool values_positive (const Type *t,int nb);
template <class Type> bool values_positive_strict (const Type *t,int nb);

template <class Type> bool values_in_range
           (const Type *t,int nb,Type v_min,Type v_max);

template <class Type> int index_values_out_of_range
             (const Type *t,int nb,Type v_min,Type v_max);

template <class Type> int index_vmax (const Type *t,int nb);
template <class Type> int index_vmin (const Type *t,int nb);



template <class Type> bool values_all_inf_to
           (const Type *t,int nb,Type v_max);

template <class Type> void proj_in_seg
                            (
                                Type *,
                                const Type *,
                                Type v_min,
                                Type v_max,
                                int
                            );

template <class Tout,class Tin> void convert(Tout *,const Tin *,int);


template <class Type> void set_cste(Type *,Type,int);




template <class Type> Type * dup(const Type *,int);
char * dup(const char *);
char * cat(const char * ch1,const char * ch2);



template <class Type> void auto_reverse_tab (Type *,int nb);

template <class Type> void rotate_plus_data(Type *,int i0,int i1);
template <class Type> void rotate_moins_data(Type *,int i0,int i1);


// return INDEX_NOT_FOUND if all not null :

template <class Type> int index_values_null(const Type * t,int nb);

template <class Type> void tab_Abs (Type * out,const Type * in,int nb);

template <class Type> void tab_minus1 (Type * out,const Type * in,int nb);

template <class Type> void tab_square (Type * out,const Type * in,int nb);
template <class Type> void tab_cube (Type * out,const Type * in,int nb);
template <class Type> void tab_pow4 (Type * out,const Type * in,int nb);
template <class Type> void tab_pow5 (Type * out,const Type * in,int nb);
template <class Type> void tab_pow6 (Type * out,const Type * in,int nb);
template <class Type> void tab_pow7 (Type * out,const Type * in,int nb);


void tab_not_log(int * out,const int * in,int nb);
void tab_not_bit_by_bit(int * out,const int * in,int nb);

void round_up (int * out  ,const double_t * in, int nb);
void round_down (int * out  ,const double_t * in, int nb);
void round_ni (int * out  ,const double_t * in, int nb);
void round_ni_inf (int * out  ,const double_t * in, int nb);

extern int index_values_strict_neg(const double_t *,int nb);
extern int index_values_neg_or_null(const double_t *,int nb);
extern int index_values_not_acos(const double_t *,int nb);
extern int index_values_complex_nul(const double_t * x,const double_t *y,int nb);

void  set_fonc_x(int * res,int x0,int x1);

template <class Type>
        void compute_inside(int * res,const Type * tx,const Type * ty,int nb,
                            Type x0,Type y0,Type x1,Type y1);


template <class Type>
        void compute_inside(int * res,const Type * tx,int nb, Type x0,Type x1);

template <class Type>
        void compute_inside
             (
                   int * res,
                   const Type * const *  coord,
                   int nb,
                   int dim,
                   const Type *p0,
                   const Type *p1
              );



template <class Type> Type red_tab_som(const Type * t,int nb,Type v_init);


/*************************************************************/
/* SOME UTILS ON TAB                                         */
/*************************************************************/

template <class Type> inline Type ElAbs   (Type v1) {return ( (v1>0) ? v1 : -v1 );}
                      inline bool ElAbs   (bool v1) {return v1;}
inline double_t ecart_frac(double_t r)
{
    return ElAbs(signed_frac(r));
}
template <class Type> inline Type ElSquare(Type v1) {return (v1*v1);}

template <class Type> inline Type ElMax (Type v1,Type v2) {return (v1>v2) ? v1 : v2;}
template <class Type> inline Type ElMin (Type v1,Type v2) {return (v1<v2) ? v1 : v2;}

extern double_t VCube(double_t V);
extern double_t VPow4(double_t V);
extern double_t VPow5(double_t V);
extern double_t VPow6(double_t V);
extern double_t VPow7(double_t V);




template <class Type> inline Type ElMax3 (Type v1,Type v2,Type v3) {return ElMax(v1,ElMax(v2,v3));}
template <class Type> inline Type ElMin3 (Type v1,Type v2,Type v3) {return ElMin(v1,ElMin(v2,v3));}
template <class Type> inline Type ElMax4 (Type v1,Type v2,Type v3,Type v4)
                             {return ElMax(v1,ElMax3(v2,v3,v4));}
template <class Type> inline Type ElMin4 (Type v1,Type v2,Type v3,Type v4)
                             {return ElMin(v1,ElMin3(v2,v3,v4));}

template <class Type> inline void ElSwap (Type &v1,Type & v2)
        { Type  tmp = v1; v1 = v2; v2 = tmp; }
template <class Type> inline void set_min_max (Type &v1,Type & v2) {  if (v1 > v2) ElSwap(v1,v2);}


template <class Type,class T2> inline void ElSetMax (Type & v1,T2 v2) {if (v1<v2) v1=(Type)v2;}
template <class Type,class T2> inline void ElSetMin (Type & v1,T2 v2) {if (v1>v2) v1=(Type)v2;}

template <class Type> inline void SetInRange
                      (const Type & v0,Type & aV,const Type & v1)
{
     if (aV < v0)
        aV = v0;
     else if (aV> v1)
        aV = v1;
}

template <class Type> void elise_sort(Type *,int);
template <class Type> void elise_indexe_sort(Type *,int *,int);


class cElRanGen
{
   public :
      double_t cNRrandom3 ();
      void cResetNRrand();
      double_t cNRrandC();
      cElRanGen();
      void InitOfTime(int aNb=1000);

   private :
      int inext,inextp;
      int MSEED;
      long ma[56];
      int iff;
      int idum ;
      float ran3 (int * idum);
};

class cRandNParmiQ
{
    public :
      cRandNParmiQ(int aN,int aQ);

      bool GetNext();
    private :
        int mN;
        int mQ;
};


extern void NRrandom3InitOfTime();
extern int  NRrandom3 (int aN);  // 0 <= X < N
extern double_t NRrandom3 ();
extern double_t NRrandC();  // entre -1 et 1
void ResetNRrand();
void rationnal_approx(double_t,int &,int&);


class ElTimer
{
     private :
        double_t _uval0;
        double_t _sval0;

        double_t _uval;
        double_t _sval;

        void  set_val();

     public :
        ElTimer();
        void reinit();
        double_t  uval();
        double_t  sval();
        double_t  ValAndInit();
        double_t  ValAbs();
};

double_t ElTimeOfDay();

class ElTabFlag
{
     public :
        ElTabFlag() : _flag(0) {}
        bool  kth(int k) const     {return (_flag & (1<<k)) != 0 ;}
        void  set_kth_true(int k)  {_flag |=  1<< k ; }
        void  set_kth_false(int k) {_flag &=  (~ (1<< k)) ; }
        void  set_kth(int k,bool val)
        {
              if (val)
                 set_kth_true(k);
              else
                 set_kth_false(k);
        }


     private :
        int  _flag;
};

class ElFlagAllocator
{
      public :
         int   flag_alloc();
         void  flag_free(int);
      private :
          ElTabFlag _flag;
};

void CmpByEnd(const char * aName1,const char * aName2,int & aK1,int &aK2);
bool N2IsEndN1(const char * aName1,const char * aName2);


// Pour avoir un nom utilisable dans les commandes meme s'il
// contient des blancs
std::string ToStrBlkCorr(const std::string &);


std::string StrToLower(const std::string & aStr);
int    IndPostfixed  (const std::string &,char = '.');
std::string StdPostfix(const std::string &,char = '.');
std::string StdPrefix (const std::string &,char = '.');
std::string StdPrefixGen (const std::string &,char = '.');
std::string NameWithoutDir(const std::string &);

std::string ExtractDigit(const std::string & aName,const std::string &  aDef);


bool IsPrefix(const char * aPref,const char *aStr);


std::string ToCommande(int argc,char ** argv);
std::string QUOTE(const std::string & aStr);
void GlobStdAdapt2Crochet(std::string & aStr);



bool SplitIn2ArroundCar
     (
         const std::string  &  a2Stplit,
         char                  aSpliCar,
         std::string  &  aBefore,
         std::string  &  aAfter,
         bool            AcceptNoCar  // Est on OK pour ne pas trouver aSpliCar
                                     // dans ce cas  aAfter est vide
     );

void  SplitInNArroundCar
      (
         const std::string  &  a2Stplit,
         char                  aSpliCar,
         std::string   &             aR0,
         std::vector<std::string>  &  aRAux
      );

void SplitIn2ArroundEq
     (
         const std::string  &  a2Stplit,
         std::string  &  aBefore,
         std::string  &  aAfter
     );

void SplitDirAndFile
     (
           std::string & aNameDir,
           std::string & aNameFile,
           const std::string & aStr
     );



std::vector<char *> ToArgMain(const std::string & aStr);



// Ajoute apres la dir et avant le .
std::string AddPrePost(const std::string & aName,const std::string & aPref,const std::string & aPost);

std::string DirOfFile(const std::string & aStr);

std::string StdWorkdDir(const std::string & aValWD,const std::string & aNameFile);

std::vector<std::string> VecStrFromFile(const std::string &);


bool GetOneModifLC
     (
         int argc,
         char ** argv,
         const std::string & aNameSymb,
         std::string &       aVal
     );

// RAJPOUTE DES /\ si necessaire
void MakeFileDirCompl(std::string &);


bool    IsPostfixed  (const std::string &,char = '.');
bool    IsPostfixedBy  (const std::string &,const std::string &);

bool IsFileDmp(const std::string &);


void EliseBRKP();

template <class Type> std::string ToString(const Type &);
std::string  ToStringNBD(int aNb,int aNbDig);


template <class Type> bool FromString(Type& x,const std::string & s)
{
   std::istringstream i(s);
   i >> x;
   return ! i.fail();
}

template <class Type> Type RequireFromString(const std::string & s,const std::string & aContext)
{
    Type aRes;
    bool Ok = FromString(aRes,s);
    if (! Ok)
    {
       std::cout << "Trying str=[" << s << "] in context :" << aContext << "\n";
       ELISE_ASSERT(false,"string is not a correc value for type");
    }

    return aRes;
}

template <class Type> int CmpTertiare(const Type & T1,const Type & T2)
{
   if (T1<T2) return -1;
   if (T1>T2) return  1;
   return 0;
}


class cElStatErreur
{
     public :
         cElStatErreur(int NbValInit);
     void AddErreur(double_t);
     void Reset();
     double_t Erreur(double_t Pos) ; // Pos en 0.0 et 1.0,  Exemple :
                             // 0.0 = Vmin, 1.0=Vmax, 0.5 = Median etc..

     private :
     std::vector<double_t> mErrs;
     bool              mOk;
};


template <class Type>
class cInterv1D
{
     public :
        cInterv1D(const Type & aV0,const Type & aV1);
        const Type & V0() const;
        const Type & V1() const;
        Type  Larg() const;
    cInterv1D<Type>  Inter(const cInterv1D<Type> &) const;
    cInterv1D<Type>  Dilate(const cInterv1D<Type> &) const;

     private:
        Type mV0;
        Type mV1;
    bool mEmpty;

};

class cDecoupageInterv1D
{
     public :
        cDecoupageInterv1D
        (
           const cInterv1D<int>  & aIntervGlob,
           int aSzMax,
           const cInterv1D<int>  & aSzBord,
           int                     anArrondi=1
        );
    int NbInterv() const;
    cInterv1D<int> KthIntervOut(int aK) const;
    // Avec Bord par defaut
    cInterv1D<int> KthIntervIn(int aK) const;
    cInterv1D<int> KthIntervIn(int aK,const cInterv1D<int>  & aSzBord) const;
    const cInterv1D<int> & IGlob() const;
    const cInterv1D<int> & IBrd() const;

    int LargMaxOut() const;
    int LargMaxIn(const cInterv1D<int>  & aSzBord) const;
    int LargMaxIn() const;


     private :
        int             KThBorneOut(int aK) const;

        cInterv1D<int>  mIntervGlob;
        cInterv1D<int>  mSzBord;
        int             mSzMax;
        int             mNbInterv;
        int             mArrondi;
};

template <class Type>
class cTplValGesInit
{
     public :
          cTplValGesInit() :
                // mVal(),  Bug Windows
                mIsInit(false)
          {
          }
          cTplValGesInit(const Type & aVal) :
                mVal(aVal),
                mIsInit(true)
          {
          }

/*
*/
      void SetNoInit() {mIsInit=false;}
          void SetVal(const Type & aVal) {mVal=aVal;mIsInit=true;}
          void SetValIfNotInit(const Type & aVal)
          {
               if (!mIsInit)
                  SetVal(aVal);
          }
          bool IsInit() const {return mIsInit;}
          Type & ValForcedForUnUmp() { return mVal; }
          void SetInitForUnUmp() {mIsInit=true;}
          const Type & ValForcedForUnUmp() const { return mVal; }
          const Type & Val() const
          {
              ELISE_ASSERT(mIsInit,"Unitialized Value in cValGesInit");
              return mVal;
          }
          const Type & Val(const std::string aMes ) const
          {
              if (!mIsInit)
              {
                  std::cout << "In context : " << aMes << "\n";
                  ELISE_ASSERT(false,"Unitialized Value in cValGesInit");
              }
              return mVal;
          }


          Type & Val()
          {
              ELISE_ASSERT(mIsInit,"Unitialized Value in cValGesInit");
              return mVal;
          }
          const Type & ValWithDef(const Type & aVal) const
          {
              return mIsInit ?mVal : aVal;
          }

          const Type * PtrVal() const { return mIsInit?&mVal:0;}
          Type * PtrVal() { return mIsInit?&mVal:0;}
     private :
          Type mVal;
          bool mIsInit;
};


//typedef long long int tFileOffset;
typedef int64_t tLowLevelFileOffset;
typedef unsigned int  tByte4AbsFileOffset;
// typedef long long  int tLowLevelRelFileOffset;

class tFileOffset
{
    public :


         const tLowLevelFileOffset & AbsLLO() const
         {
               tLowLevelFileOffset aLLO = mLLO.Val();
               ELISE_ASSERT(aLLO>=0,"AbsLLO neg");
               return mLLO.Val();
         }
         tByte4AbsFileOffset   Byte4AbsLLO() const
         {
               tLowLevelFileOffset aLLO = mLLO.Val();
               ELISE_ASSERT((aLLO>=0) && (aLLO<=0xFFFFFFFFll),"Byt4LLO too big");
               return (tByte4AbsFileOffset)aLLO;
         }
         const tLowLevelFileOffset & BasicLLO() const
         {
               return mLLO.Val();
         }
         int  IntBasicLLO() const
         {
               tLowLevelFileOffset aLLO = mLLO.Val();
               ELISE_ASSERT((aLLO>-0x7FFFFFFFll) && (aLLO<0x7FFFFFFFll),"Byt4LLO too big");
               return (int)aLLO;
         }

         tFileOffset ()
         {
             mLLO.SetNoInit();
         }
         tFileOffset (const tLowLevelFileOffset & aLLO) :
           mLLO(aLLO)
         {
         }

         tFileOffset operator + (const tFileOffset & anO2) const
         {
               return mLLO.Val() + anO2.mLLO.Val();
         }
         tFileOffset operator - (const tFileOffset & anO2) const
         {
               return mLLO.Val() - anO2.mLLO.Val();
         }
         tFileOffset operator / (const tFileOffset & anO2) const
         {
               return mLLO.Val() / anO2.mLLO.Val();
         }
         tFileOffset operator * (const tFileOffset & anO2) const
         {
               return mLLO.Val() * anO2.mLLO.Val();
         }

         bool operator < (const tFileOffset & anO2) const
         {
               return mLLO.Val() < anO2.mLLO.Val();
         }
         bool operator > (const tFileOffset & anO2) const
         {
               return mLLO.Val() > anO2.mLLO.Val();
         }
         bool operator == (const tFileOffset & anO2) const
         {
               return mLLO.Val() == anO2.mLLO.Val();
         }
         bool operator != (const tFileOffset & anO2) const
         {
               return mLLO.Val() != anO2.mLLO.Val();
         }

         void operator ++ (int)
         {
              mLLO.SetVal(mLLO.Val()+1);
         }
         void operator +=  (const tFileOffset & anO2)
         {
              mLLO.SetVal(mLLO.Val()+anO2.mLLO.Val());
         }
         void operator -=  (const tFileOffset & anO2)
         {
              mLLO.SetVal(mLLO.Val()-anO2.mLLO.Val());
         }
         void operator *=  (const tFileOffset & anO2)
         {
              mLLO.SetVal(mLLO.Val()*anO2.mLLO.Val());
         }


/*
         void SetLLO(const tLowLevelFileOffset & aLLO)
         {
              mLLO.SetVal(aLLO);
         }
*/
         bool IsInit() const
         {
              return mLLO.IsInit();
         }

// Deux interface bas niveaus, "tres sales", poiur assurer la communication avec le stockage
// en int des offset dans les tiffs qui est necessaire pour utiliser le service de tag generiques
         static  tFileOffset FromReinterpretInt(int anI)
         {
               tByte4AbsFileOffset anUI;
			   std::memcpy(&anUI,&anI,sizeof(tByte4AbsFileOffset));
               return tFileOffset(anUI);
         }
         int ToReinterpretInt() const
         {
              int aRes;
              tByte4AbsFileOffset anOfs4 = Byte4AbsLLO();
			  std::memcpy(&aRes,&anOfs4,sizeof(tByte4AbsFileOffset));
              return aRes;
         }
    private :
        cTplValGesInit<tLowLevelFileOffset> mLLO;
};

inline std::ostream & operator << (std::ostream & ofs,const tFileOffset  &anOffs)
{
    ofs << anOffs.BasicLLO();
    return ofs;
}

typedef tFileOffset tRelFileOffset;


// typedef unsigned int tFileOffset;
/*
*/


tFileOffset RelToAbs(tRelFileOffset anOff);


/*****************************************************/
/*                                                   */
/*                  cEquiv1D                      */
/*                                                   */
/*****************************************************/

// Classe pour gerer rapidement les "classe equiv 1D"
// c'est a dire les intervalles classes d'equivalences
// d'une application croissante  de Z dans Z

class cFonc1D
{
    public :
         virtual int operator()(const int &) const = 0;
    virtual ~cFonc1D() {}
    private :
};

class cFonc1D_HomTr : public cFonc1D
{
    public :
         //   (a X +b ) / c
         //  vraie division   (Elise_div)
         //  requiert : c > 0
         int operator()(const int &) const;
         cFonc1D_HomTr(const int & anA,const int & aB,const int & aC);
    private :
         int mA;
         int mB;
         int mC;
};


template<class aType> class cVectTr;

class cEquiv1D
{
     public :
          // Intervalle [aV0 aV1[
          cEquiv1D ();
          void InitFromFctr
          (
                 int aV0,
                 int aV1,
                 const cFonc1D &
          );
          void InitByFusion(const cEquiv1D &,int aFus);
          // InitByFusion, vs constructeur
          class cCstrFusion {};
          cEquiv1D(const cCstrFusion &,const cEquiv1D &,int aFus);

          void InitByClipAndTr
               (
                    const cEquiv1D &,
                    int aHomOfNewV0,
                    int aNewV0,
                    int aNewV1
               );
          void InitByDeZoom
               (
                    const cEquiv1D &,
                    int aDz,
                    cVectTr<int> * mLut
               );
         int NbClasses() const { return mNbClasses; }
          int V0()        const { return mV0; }
          int V1()        const { return mV1; }
          int  NumClasse(const int & aV) const
          {
               return mNumOfClasse[aV-mV0];
          }
          // La fonction "inverse" renvoie un intervalle
          void ClasseOfNum(int & aV0,int & aV1,const int & aNCL) const
          {
                aV0 = mDebOfClasse[aNCL];
                aV1 = mDebOfClasse[aNCL+1];
          }
          int SzMaxClasses() const;
     private:
          void Reset(int aV0,int aV1);
          std::vector<int> mNumOfClasse; // Pour un entier, son numero de classe
          std::vector<int> mDebOfClasse; // Pour un numero de classe, sont entier de debut

          int mV0;
          int mV1;
          int mNbClasses;
};

// GPAO : Gestion de Production assistee par ordinateur. C'est
// un peu presenptueux pour l'instant il s'agit juste d'avoir des
// classes permettant de gerer du calcul distribue avec des regles
// gerable par des DAG (directed acyclique graphe)
//
//  cEl_GPAO  est la classe "manager"
//

class cEl_GPAO;
class cEl_Task;

//#include "cElCommand.h"

class cElTask
{
     public :
          void AddDep(cElTask &);
          void AddDep(const std::string &);  // Idem AddDep(cElTask &)
          void AddBR(const std::string &);  //
          void  GenerateMakeFile(FILE *) const;
          // Genere le mkf, l'execute, le purge
     private :
          friend class cEl_GPAO;
        #ifdef __USE_EL_COMMAND__
          cElTask
          (
               const std::string & aName,
               cEl_GPAO &,
               const cElCommand & aBuildingRule
          );
        #else
          cElTask
          (
               const std::string & aName,
               cEl_GPAO &,
               const std::string & aBuildingRule
          );
        #endif
         cEl_GPAO &  mGPAO;

         std::string mName;
        #ifdef __USE_EL_COMMAND__
            std::list<cElCommand> mBR;  // BuildingRule
        #else
            std::list<std::string> mBR;  // BuildingRule
        #endif

         std::vector<cElTask *>  mDeps;
};


class cEl_GPAO
{
     public :
          // Interface simplifiee quand il n'y a pas de dependance entre les commandes
          static void DoComInParal(const std::list<std::string> &,std::string  FileMk = "", int   aNbProc = 0 ,bool Exe=true, bool MoinsK=false);
          static void DoComInSerie(const std::list<std::string> &);

         ~cEl_GPAO();
          cEl_GPAO();

        #ifdef __USE_EL_COMMAND__
            cElTask   & NewTask
                        (
                            const std::string &aName,
                            const cElCommand & aBuildingRule
                        ) ;

            cElTask   & GetOrCreate
                        (
                            const std::string &aName,
                            const cElCommand & aBuildingRule
                        );
        #else
            cElTask   & NewTask
                        (
                                const std::string &aName,
                                const std::string & aBuildingRule
                            ) ;

            cElTask   & GetOrCreate
                        (
                                const std::string &aName,
                                const std::string & aBuildingRule
                            ) ;
        #endif


         cElTask   &TaskOfName(const std::string &aName) ;
         void  GenerateMakeFile(const std::string & aNameFile) const ;
         void  GenerateMakeFile(const std::string & aNameFile,bool ModeAdditif) const;
         void ExeParal(std::string aFile,int aNbProc = -1,bool SuprFile=true);
         void dump( std::ostream &io_ostream=std::cout ) const;
     private :
         std::map<std::string,cElTask *>  mDico;

};


//  Pour executer une commande en // sur +sieur fichier, pour l'instant on fait
// basique, on ajoutera eventuellement apres des cles avec cInterfChantierNameManipulateur
/*
void MkFMapCmd
     (
          const std::string & aBefore,
          const std::vector<std::string> aSet ,
          const std::string & anAfter
     );
*/

void MkFMapCmdFileCoul8B
     (
          const std::string & aDir,
          const std::vector<std::string > &aSet
     );



//========================================================

class cInterfChantierNameManipulateur;

void RequireBin
     (
         const std::string & ThisBin,  // Le prog appelant pour evt
         const std::string & BinRequired,
     const std::string & LeMake = "Makefile"  // Si
     );

// For top call like Tapas, Malt , .. want to duplicate args in @
int TopSystem(const std::string & aComOri);

int System(const std::string & aCom,bool aSVP=false,bool AddOptGlob=false,bool UseTheNbIterProcess=false);

void  EliseVerifAndParseArgcArgv(int argc,char ** argv);


class cAppliBatch
{
    public :
       typedef enum
       {
            eExeDoNothing,
            eExeDoIfFileDontExist,
            eExeDoSys,
            eExeWriteBatch
       } eModeExecution;

       typedef enum
       {
             eNoPurge =0,
             ePurgeTmp =1,
             ePurgeAll =2
       } eNivPurge;


       void DoAll();

       //const std::string & ThisBin() const;

       cEl_GPAO &  GPAO ();
       bool        ByMKf() const;  // By Make file
       const std::string & MKf() const;
       // Parfois le plus simple est que le programme se rappelle lui - meme avec
       // des option legerement differente dans ce cas on doit etre au courant
       bool        IsRelancedByThis() const;

    protected :
        virtual ~cAppliBatch();
        cAppliBatch
    (
         int,
         char **,
         int aNbArgGlob,
         int aNbFile,
         const std::string & aPostFixWorkDir,
         const std::string & aKeyDOIDE="",
             bool  ForceByDico = false
        );

     void AddPatSauv(const std::string &);
         int ARGC();
     char ** ARGV();
     std::string ComCommune() const;
         int System(const std::string &,bool aSVP=false);
         int System(const char* FileCible,const std::string &,bool aSVP=false);
     const std::string & CurF1() const;
     const std::string & CurF2() const;
     const std::string & CurF(int aK) const;
         const std::string  & DirChantier() const;
         const std::string  & DirTmp() const;
         const std::string  & DirSauv() const;
     cInterfChantierNameManipulateur * ICNM();
     cInterfChantierNameManipulateur * ICNM() const;

     bool NivPurgeIsInit();
     void SetNivPurge(eNivPurge  );
     bool NivExeIsInit();
     void SetNivExe(eModeExecution);
         eModeExecution ModeExe() const;
         std::string ComForRelance();
    std::string protectFilename( const std::string &i_filename ) const; // according to ByMKf()

    private :
    void DoOne();
    virtual void Exec() = 0;
    void UseLFile(const std::list<std::string> &);



    // Les args non consommes

     // Partie de la ligne de commande qui revient a chaque fois


    // private :
    std::vector<char *>  mArgsNC;  //

        void DoPurge();

    cInterfChantierNameManipulateur * mICNM;

        //std::string  mThisBin;
        std::string  mDirChantier;

    std::string  mPostFixWorkDir;
    int          mNbFile;
        bool         mByNameFile;
    std::string  mDirSauv;
    std::string  mDirTmp;

        //bool         mFileByICNM;
    std::string  mPatF1;
    std::string  mPatF2;
    std::string  mCurF1;
    std::string  mCurF2;
    std::vector<std::string> mVCurF;

    std::string  mArgAdd;

        eModeExecution  mModeExe;
    bool            mExeIsInit;
    eNivPurge       mNivPurge;
    bool            mNivPurgeIsInit;
        std::string     mFileBatch;
    std::vector<std::string>  mPatSauv;

    bool                      mFileByPat;
    bool                      mByDico;
    std::list<std::string>    mListFile1ByPat;
    int  mReverse;
    int                       mDOIDE;
    std::string               mKeyDOIDE;

        std::string               mMKf;
        bool                      mModeAddMkf;
        int                       mIsRelancedByThis;
        std::string               mDebCom;
        std::string               mEndCom;
        cEl_GPAO                  mGPAO;
};

class cCpleString
{
     public :
        cCpleString AddPrePost
                    (
                        const std::string& aPre,
                        const std::string& aPost
                    ) const;
        cCpleString(const std::string&,const std::string&);
        cCpleString();
    const std::string &  N1() const;
    const std::string &  N2() const;

    bool operator < (const cCpleString &) const;
    bool operator == (const cCpleString &) const;
     private :
        std::string mN1;
        std::string mN2;
};

class cXmlHour;
class cXmlDate;

class cElHour
{
    public :
      cXmlHour ToXml();
      static cElHour FromXml(const cXmlHour &);
      cElHour
      (
          int aNbHour,
          int aNbMin,
      double aNbSec
      );
      double InSec() const; // Sec depuis minuits
      int    H() const;
      int    M() const;
      double S() const;

      bool operator==( const cElHour &i_b ) const;
      bool operator!=( const cElHour &i_b ) const;

     // read/write in raw binary format
     void from_raw_data( const char *&io_rawData, bool i_reverseByteOrder );
     void to_raw_data( bool i_reverseByteOrder, char *&o_rawData ) const;
     static unsigned int raw_size();

     void read_raw( std::istream &io_istream, bool i_inverseByteOrder );
     void write_raw( std::ostream &io_ostream, bool i_inverseByteOrder ) const;

     static void getCurrentHour_local( cElHour &o_localHour );
     static void getCurrentHour_UTC( cElHour &o_utcHour );

    private :
       int mH;
       int mM;
       double mS;
};

class cElDate
{
    public :
       cXmlDate ToXml();
       static cElDate FromXml(const cXmlDate &);

       static const cElDate NoDate;
       bool IsNoDate() const;
       cElDate
       (
         int aDay,
         int aMonth,
         int aYear,
     const cElHour &
       );

        const cElHour &  H() const;
    int Y() const;
    int M() const;
    int D() const;

    static cElDate FromString(const std::string &);

    int NbDayFrom1erJ() const;
    // Ne prend pas en compte les 13 jours "sautes " au 17e
    int NbDayFromJC() const;
    int    DifInDay(const cElDate&) const;
    double DifInSec(const cElDate&) const;

    bool operator==( const cElDate &i_b ) const;
    bool operator!=( const cElDate &i_b ) const;

    // read/write in raw binary format
    void from_raw_data( const char *&io_rawData, bool i_reverseByteOrder );
    void to_raw_data( bool i_reverseByteOrder, char *&o_rawData ) const;
    static unsigned int raw_size();

    void read_raw( std::istream &io_istream, bool i_inverseByteOrder=false );
    void write_raw( std::ostream &io_ostream, bool i_inverseByteOrder=false ) const;

    static void getCurrentDate_local( cElDate &o_localDate );
    static void getCurrentDate_UTC( cElDate &o_utcDate );

    private :
         int mD;
         int mM;
         int mY;
     cElHour mH;

         // !! Les mois commencent a 1
     static const int TheNonBisLengthMonth[12];
     static int TheNonBisLengthMonthCum[12];
     static int TheBisLengthMonthCum[12];
     static bool TheIsBis[3000];
     static int  TheNbDayFromJC[3000];

     static bool mTabuliIsInit;

     static void InitTabul();


     static bool PrivIsBissextile(int aY);
};

bool operator < (const cElDate & aD1, const cElDate & aD2);

class cint8ImplemSetInt
{
    public :
       cint8ImplemSetInt();
       void Add(int anInt);
       bool IsIn (int anInt) const;
       int  NumOrdre(int aI) const;  // Nombre d'Entier < a aI
       int  NumOrdre(int aI,bool svp) const;  // Nombre d'Entier < a aI
       static int  Capacite();

       bool operator < (const cint8ImplemSetInt &) const;
    private :
       intByte8  mFlag;
};

template <const int NbI> class cSetIntMultiple
{
    public :
       cSetIntMultiple();
       void Add(int anInt);
       bool IsIn (int anInt) const;
       int  NumOrdre(int aI) const;  // Nombre d'Entier < a aI
       static int  Capacite();

       bool operator < (const cSetIntMultiple<NbI> &) const;
    private :
        Pt2d<int>  NumSub(const int & anI) const; // x le set, y le I dans le set
       cint8ImplemSetInt  mSets[NbI];
};

class cVarSetIntMultiple
{
    public :
       cVarSetIntMultiple();
       void Add(int anInt);
       bool IsIn (int anInt) const;
       int  NumOrdre(int aI) const;  // Nombre d'Entier < a aI

       bool operator < (const cVarSetIntMultiple &) const;
       int  Capacite() const;
    private :
        Pt2d<int>  NumSub(const int & anI) const; // x le set, y le I dans le set
        mutable std::vector<cint8ImplemSetInt>  mSets;
};



class cElXMLTree;

extern bool TransFormArgKey
     (
         std::string & aName ,
         bool AMMNoArg,  // Accept mismatch si DirExt vide
         const std::vector<std::string> & aDirExt
     );

// Class sepeciale pour gerer les objets autre que string qui peuvent etre initialise par des #1 #2 ..
// dans les xml pour les cles parametrees, par exemple le <DeltaMin> de <ByAdjacence>

template <class Type> class TypeSubst
{
    public :
          TypeSubst();
          TypeSubst(const Type& Val);
          void SetStr(cElXMLTree *);
          const  Type  & Val() const;
          bool  Subst(bool AMMNoArg,  const std::vector<std::string> & aVParam);
          void TenteInit();

    private :
          Type           mVal;
          bool           mIsInit;
          std::string    mStrInit;
          std::string    mStrTag;
};

typedef TypeSubst<bool>    BoolSubst;
typedef TypeSubst<int>     IntSubst;
typedef TypeSubst<double>  DoubleSubst;

#if __cplusplus <= 199711L
template <class T> T* VData(std::vector<T> & aV)  {return &(aV[0]);}
template <class T> const T* VData(const std::vector<T> & aV)  {return &(aV[0]);}
#else
template <class T> T* VData(std::vector<T> & aV)  {return aV.data();}
template <class T> const T* VData(const std::vector<T> & aV)  {return aV.data();}
#endif

///  Ajoute des regles speciales pour que chaque pixle ait au moins un 
//  precedcesseur et un antecedant
//   Z est dans l'intervalle ouvert I1 [aZ1Min,aZ1Max[,

void ComputeIntervaleDelta
              (
                  int & aDzMin,
                  int & aDzMax,
                  int aZ,
                  int MaxDeltaZ,
                  int aZ1Min,
                  int aZ1Max,
                  int aZ0Min,
                  int aZ0Max
              );

///  Ne force pas les connexions
void BasicComputeIntervaleDelta
              (
                  int & aDzMin,
                  int & aDzMax,
                  int aZ,
                  int MaxDeltaZ,
                  int aZ0Min,
                  int aZ0Max
              );
double FromSzW2FactExp(double aSzW,double mCurNbIterFenSpec);

std::string getBanniereMM3D();

void BanniereMM3D();



extern "C" {
FILE * ElFopen(const char *path, const char *mode);
int ElFclose(FILE *fp);
void ShowFClose();

};


void GetSubset(std::vector<std::vector<int> > & aRes,int aNb,int aMax);

bool ElGetStrSys( const std::string & i_base_cmd, std::string &o_result );

void BanniereGlobale();

// protect spaces with backslashes (for use with 'make')
std::string protect_spaces( const std::string &i_str );

int MMNbProc();

// lanch the "make" program
// do not include "-j x" flag in i_options, it is handle by i_nbJobs
// i_nbJobs = 0 means "-j" (i.e. infinite jobs, which is not recommanded)
// i_rule can be an empty string, if so, make will launch the makefile's default rule
// returns make's return code
bool launchMake( const std::string &i_makefile, const std::string &i_rule=std::string(), unsigned int i_nbJobs=MMNbProc(), const std::string &i_options=std::string(), bool i_stopCurrentProgramOnFail=true );

#endif /* ! _ELISE_UTIL_H */
