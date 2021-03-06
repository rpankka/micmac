#ifndef _ELISE_GENERAL_PHOTOGRAM_CSETNIMSETPOintES_H
#define _ELISE_GENERAL_PHOTOGRAM_CSETNIMSETPOintES_H



class cSetNImSetPointes
{
public :
    cSetNImSetPointes
    (
            const cPolygoneEtal &,
            const std::string &,
            bool  SVP = false  // Si true et fichier inexistant cree set vide
            );
    typedef std::list<cSetPointes1Im> tCont;
    tCont  & Pointes() ;
    int NbPointes();
private :
    tCont mLPointes;

};

#endif
