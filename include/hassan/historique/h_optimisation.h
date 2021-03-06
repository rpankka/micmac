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
#ifndef _HASSAN_H_OPTIMISATION_H
#define _HASSAN_H_OPTIMISATION_H


class Histograme;
//////////////////////////////////////////////////////////////////////

class H_Optimisation : public virtual  H_Graphe
{
    public:


      ElFilo<int>             _seg_facet_vot_gauche;
      ElFilo<int>             _seg_facet_vot_droite;

      ElFilo< ElFilo<int>* >  _solution;
      ElFilo< double_t >          _solution_poids;

      H_Optimisation(H_Graphe& graphe );
      H_Optimisation( H_Optimisation& opt );

      virtual ~H_Optimisation();

   protected:

      void deteruir();
      void copyer(H_Optimisation&);


    public:

      H_Optimisation& operator = (H_Optimisation&);

      void recherche_meil_combinaison_pour_chaque_segment();
      void recherche_solutions();
      void rejete_solutions(int n_sol);
      void rejete_solutions();
      void garder_n_premieres_solutions(int n);
      void rejete_solutions_non_compatibles();
      void difusion_continuite();

      void facette_poids(int n_f, Boite& coef_cor);
      void facette_poids(Boite& coef_cor);
      void facette_poids(ElFilo<Boite>& coef_cor_plan);
      void facette_poids(Boite& b_mne, Im2D_U_int1 masq, int decal = 1, int test_stab = 0);
      void facette_poids(Mne& mne, int decal = 1, int test_stab = 0);
      void facette_poids(ElFilo<Pt3dr>& f_pt, double_t surf_pt, double_t sigma, double_t delta, double_t distance);

      void segment_poids(int n_s, WcorVis W1, Im2D_U_int1 grad1, WcorVis W2, Im2D_U_int1 grad2);
      void segment_poids(WcorVis W1, Im2D_U_int1 grad1, WcorVis W2, Im2D_U_int1 grad2);
      void segment_poids(ElFilo<Boite>& coef_cor_plan);
      void segment_poids(Boite& b_mne, int decal = 1);
      void segment_poids_mne(int n_s, Boite& b_mne, int decal = 1);
      void segment_poids_coef(int n_s, Boite& b_coef);
      void segment_interne_poids_coef(Boite& b_coef);

      void select_meil_composante();
      double_t explorer();   //retour le temps de calcul

      double_t merite(int n_sol);
      double_t merite_cont(int n_sol);
      double_t merite_cont(int n_sol, Boite& b_a, Boite& b_b, int s_t_f, Output);
      double_t merite_coef(int n_sol, Boite& b_a, Boite& b_b, int s_t_f, int type_correl, Output);
      void solution_poids_coef(Boite& b_a, Boite& b_b, int s_t_f, int type_correl, Output w);
      void solution_poids_cont(Boite& b_a, Boite& b_b, int s_t_f, Output w);
      void solution_poids_cont();
      void solution_poids();
      void arrange_solutions(double_t alpha = .005);

      double_t heuristic(double_t alpha = .1, double_t seuil_sup = .5, double_t seuil_inf = .1, int nb_min = 60, double_t surafce_min = 1.6);
      

                                            //methode d'affichage

      void affiche_solution(int n_sol, int color);
      void parcour_solution(bool debut = false);

      void interface();

   private:

     double_t calcul_poids(double_t f_int, double_t f_ext, double_t seuil, double_t p_min)
                      {
                         if(f_int < seuil && f_ext < seuil) return p_min;
                         if(!f_int) f_int = 1e-10;
                         return f_int/(f_int + f_ext + 4);
                      }
};


#endif //_HASSAN_H_OPTIMISATION_H

/*Footer-MicMac-eLiSe-25/06/2007

Ce logiciel est un programme informatique servant à la mise en
correspondances d'images pour la reconstruction du relief.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA 
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant 
donné sa spécificité de logiciel libre, qui peut le rendre complexe à 
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement, 
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité. 

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez 
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
Footer-MicMac-eLiSe-25/06/2007*/
