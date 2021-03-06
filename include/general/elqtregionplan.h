#ifndef _ELISE_GENERAL_GEOM_VECTEUR_ELQTREGIONPLAN_H
#define _ELISE_GENERAL_GEOM_VECTEUR_ELQTREGIONPLAN_H



class ElQTRegionPlan
{
      public :

         virtual double_t D2(const Box2dr &) const = 0;
         virtual double_t D2(const Pt2dr &)  const = 0;
         virtual double_t D2(const SegComp &)  const = 0;
         virtual double_t D2(const cElTriangleComp &)  const ; // Def = err fatale
     virtual ~ElQTRegionPlan() {}
};

#endif
