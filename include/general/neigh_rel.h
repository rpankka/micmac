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


#ifndef _ELISE_GENERAL_ABSTRACT_TYPES_NEIGH_REL_H
#define _ELISE_GENERAL_ABSTRACT_TYPES_NEIGH_REL_H

#include <PRC0>
#include <Neighbourhood>

class Neigh_Rel : public PRC0
{
     public :
        Neigh_Rel(class Neigh_Rel_Not_Comp *);
        Neigh_Rel(Neighbourhood);
        class Neigh_Rel_Compute * compute (const class Arg_Neigh_Rel_Comp &);

        Fonc_Num red_op(const OperAssocMixte &  op,Fonc_Num f);
        Fonc_Num red_sum(Fonc_Num f);
        Fonc_Num red_max(Fonc_Num f);
        Fonc_Num red_min(Fonc_Num f);
        Fonc_Num red_mul(Fonc_Num f);
};

#endif
