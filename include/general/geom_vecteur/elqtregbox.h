#ifndef _ELISE_GENERAL_GEOM_VECTEUR_ELQTREGBOX_H
#define _ELISE_GENERAL_GEOM_VECTEUR_ELQTREGBOX_H

#include "general/sys_dep.h"

class ElQTRegBox : public ElQTRegionPlan
{
      public :

         virtual REAL D2(const Box2dr &)  const ;
         virtual REAL D2(const Pt2dr & )  const ;
         virtual REAL D2(const SegComp &)  const;
         ElQTRegBox (const Box2dr &box);
     virtual ~ElQTRegBox() {}
      private :

          Box2dr _box;
};

#endif
