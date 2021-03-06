/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.
    Refactoring: Helio Chissini de Castro <helio@kde.org>

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


#ifndef _ELISE_GENERAL_UTIL_CTPLVALGESINIT_H
#define _ELISE_GENERAL_UTIL_CTPLVALGESINIT_H


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

#endif
