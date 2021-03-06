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
/* Ceci est commentaire */

#include <cctype>

const double cReadObject::TheDUnDef = 1.3478659e67;
const std::string cReadObject::TheStrUnDef = "#Yuy@y{ur$8-5M}Ml%&[]";
bool cReadObject::IsDef(const double &aVal) const {return aVal !=TheDUnDef;}
bool cReadObject::IsDef(const std::string &aVal) const {return aVal !=TheStrUnDef;}
bool cReadObject::IsDef(const Pt3dr & aP) const
{
   return IsDef(aP.x) && IsDef(aP.y) &&IsDef(aP.z);
}

double  cReadObject::GetDef(const double & aVal,const double & aDef)
{
    return IsDef(aVal) ? aVal : aDef;
}
Pt3dr   cReadObject::GetDef(const Pt3dr  & aVal,const double  & aDef)
{
    return Pt3dr ( GetDef(aVal.x,aDef), GetDef(aVal.y,aDef), GetDef(aVal.z,aDef));
}
std::string  cReadObject::GetDef(const std::string & aVal,const std::string & aDef)
{
    return IsDef(aVal) ? aVal : aDef;
}

std::string cReadObject::GetNextStr(tCharPtr & aStr)
{
   std::string aRes;
   while ((*aStr) && std::isblank(*aStr))
        aStr++;
   if (*aStr==0)
      return aRes;

   while  ((*aStr) && (!std::isblank(*aStr)))
      aRes += *(aStr++);

   return aRes;
}

bool LineIsBlank(const char * aLine)
{
    while (*aLine)
    {
        if (!std::isblank(*aLine)) return false;
        aLine ++;
    }
    return true;
}

bool cReadObject::Decode(const char * aLine)
{
   mNumLine++;
   if (aLine[0] == mComC)
      return false;
    if (LineIsBlank(aLine))
      return false;
    const char * aL = aLine;
    const char * aF = mFormat.c_str();
    while (true)
    {
        // const char * aL0 = aL;
        // const char * aF0 = aF;
        std::string aSymb = GetNextStr(aF);
        std::string aVal = GetNextStr(aL);

        if ((aSymb=="") != (aVal==""))
        {
            std::cout << "\n\nAT LINE " << mNumLine << "\n";
            std::cout << "Format =[" << mFormat << "]\n";
            std::cout << "Line =[" <<  aLine << "]\n";
            ELISE_ASSERT(false,"Incoherence between format and line");
        }

        if (aSymb=="")
        {
           return true;
        }

        if (aSymb!=mSymbUnknown)
        {
           std::map<std::string,double *>::iterator iTD = mDoubleLec.find(aSymb);
           std::map<std::string,std::string *>::iterator iTS = mStrLec.find(aSymb);
           if (iTD!=mDoubleLec.end())
           {
                   sscanf(aVal.c_str(),"%lf",iTD->second);
           }
           else if (iTS!=mStrLec.end())
           {
                *(iTS->second) = aVal;
           }
           else
           {
                std::cout << "\n\nAT LINE " << mNumLine << "\n";
                std::cout << "For Symb=[" << aSymb << "]\n";
                ELISE_ASSERT(false,"Symbole is not is not handled");
           }
        }
    }
}

cReadObject::cReadObject(char aComCar,const std::string & aFormat,const std::string & aSymbUnknown) :
    mComC        (aComCar),
    mFormat      (aFormat),
    mSymbUnknown (aSymbUnknown),
    mNumLine     (0)
{
    const char * aF = aFormat.c_str();

    std::string aSF;
    bool cont = true;
    while (cont)
    {
        aSF = GetNextStr(aF);
        if (aSF!="")
            mSFormat.insert(aSF);
        else
          cont = false;
    }
}

void cReadObject::VerifSymb(const std::string &aS,bool Required)
{
     if (mSymbs.find(aS) != mSymbs.end())
     {
        std::cout << "Symbole=" << aS << "\n";
        ELISE_ASSERT(false,"Symbole multiple defined");
     }
     mSymbs.insert(aS);
     if (Required)
     {
         if (mSFormat.find(aS) == mSFormat.end())
         {
             std::cout << "Symbole=" << aS << "\n";
             ELISE_ASSERT(false,"Symbole is not in format");
         }
     }
}
void cReadObject::AddDouble(const std::string & aS,double * anAdr,bool Required)
{
     VerifSymb(aS,Required);
     mDoubleLec[aS] = anAdr;
     *anAdr = TheDUnDef;
}



void cReadObject::AddDouble(char aC,double * anAdr,bool Required)
{
     std::string aS;
     aS += aC;
     AddDouble(aS,anAdr,Required);
}
void cReadObject::AddPt3dr(const std::string & aS,Pt3dr * aP,bool Required)
{
     ELISE_ASSERT(aS.size()==3,"AddPt3dr bad size");
     AddDouble(aS[0],&(aP->x),Required);
     AddDouble(aS[1],&(aP->y),Required);
     AddDouble(aS[2],&(aP->z),Required);
}
void cReadObject::AddString(const std::string & aS,std::string * aName,bool Required)
{
     VerifSymb(aS,Required);
     mStrLec[aS] = aName;
     *aName = TheStrUnDef;
}

bool cReadObject::ReadFormat(char  & aCom,std::string & aFormat,const std::string &aFileOrLine,bool IsFile)
{
    const char * aLine =  aFileOrLine.c_str();
    if (IsFile)
    {
        ELISE_fp aFIn(aFileOrLine.c_str(),ELISE_fp::READ);
        aLine = aFIn.std_fgets();
    }



    if (! aLine) return false;

    if (
              (aLine[0] == 0)
          ||  (aLine[1] != 'F')
          ||  (aLine[2] != '=')
       )
       return false;

   aCom = aLine[0];
   aFormat = aLine+3;
   for (char * aC=(char *)aFormat.c_str() ; *aC ; aC++)
       if (*aC=='_')
           *aC= ' ' ;
   return true;
}
