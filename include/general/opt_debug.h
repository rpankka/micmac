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



#ifndef _ELISE_OPT_DEBUG_H
#define _ELISE_OPT_DEBUG_H




#define DEBUG_SMART_POINTEUR 0
#define DEBUG_DYN_CAST  0
#define DEBUG_INTERNAL  0

#if (DEBUG_DYN_CAST)
#include <std/typeinfo.h>
#endif


#define CPP_OPTIMIZE 0   // because of problems with inlining when
                         //  compiling with -g



/*************************************************/

#if (CPP_OPTIMIZE)
#define ELISE_INLINE inline
#else   // CPP_OPTIMIZE
#define ELISE_INLINE 
#endif  // CPP_OPTIMIZE


class ELISE_ERROR
{
    public :
       ELISE_ERROR(char * mes,char * file,int line);
       void treat(void);
    private :
        char *  file;
        char *  mes;
        int     line;
};


class cEliseFatalErrorHandler
{
    public :
        static void SetCurHandler(cEliseFatalErrorHandler *);
        static cEliseFatalErrorHandler *  CurHandler();

        virtual void cEFEH_OnErreur(const char * mes,const char * file,int line);
	virtual ~cEliseFatalErrorHandler() {}
    protected :
    private :
   
        static cEliseFatalErrorHandler *  CurHandler(cEliseFatalErrorHandler *aH);

};

extern void elise_internal_error(const char * mes,const char * file,int line);
extern void elise_test_error(const char * mes,const char * file,int line);
extern void elise_fatal_error(const char * mes,const char * file,int line);


#if (DEBUG_INTERNAL)
#define ASSERT_INTERNAL(expr,mes)\
((expr)?((void) 0) : elise_internal_error(mes,__FILE__,__LINE__))
#else
#define ASSERT_INTERNAL(expr,mes) ((void) 0)
#endif

#define OLD_BUG_CARD_VAL_FONC(pck1,pck2)\
ASSERT_INTERNAL(((pck1)->nb()==(pck2)->nb()),"Inchorence in values cardinals")



#define BENCH_ASSERT(expr)\
((expr)?((void) 0) : elise_internal_error("assertion dans un bench",__FILE__,__LINE__))

#define ASSERT_TJS_USER(expr,mes)\
((expr)?((void) 0) : elise_fatal_error(mes,__FILE__,__LINE__))


extern bool ELISE_DEBUG_USER;
extern bool ELISE_DEBUG_INTERNAL;

#define ASSERT_USER(expr,mes)\
(((!ELISE_DEBUG_USER) || (expr))?((void) 0) : elise_fatal_error(mes,__FILE__,__LINE__))

#define WHEN_DEBUG_USER(expr) (ELISE_DEBUG_USER ? (expr) : ((void)0))

extern void message_copy_where_error();



#define ASSERT_TJS(expr,mes)\
if (! (expr))\
   throw ERROR(mes,__FILE__,__LINE__);

/*
    The SAFE_DYNC(type,val) macro has the follosing effect :

       * when DEBUG_DYN_CAST is true, the value val is casted  
         in type  if  type is really one of its base-class;
         else a fatale error will occur;

       * else it just performs a usual cast. 
*/


#if (DEBUG_DYN_CAST)
inline void * sdnc_ptr_identity(void * ptr,char *f,int l)\
{\
   if (! ptr)\
      elise_internal_error("incorrect dynamic cast",f,l);\
   return ptr;\
}
#define SAFE_DYNC(type,val)\
 ((type) sdnc_ptr_identity(dynamic_cast <type>(val),__FILE__,__LINE__))
#else  /* DEBUG_DYN_CAST */
#define SAFE_DYNC(type,val) ((type) val)
#endif  /* DEBUG_DYN_CAST */

// The macro C_CAST, just performs a "classical C-cast". This macro aims to distinguishe
// the cast, between built-in types, that are (relatively ...) safe from "horrible"
// reINTErpret_cast (as cast from base class to virtual derivate).

#define C_CAST(un_type,une_val) ((un_type) une_val)

#endif /* ! _ELISE_OPT_DEBUG_H */

