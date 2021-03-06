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



#ifndef _ELISE_PRIVATE_TIFF_H
#define _ELISE_PRIVATE_TIFF_H

class Pseudo_Tiff_Arg;
class DATA_tiff_header;
class D_Tiff_ifd_Arg_opt;
class DATA_Tiff_Ifd;
class Tiff_file_2d;
class Tiff_Tiles;
class Tiff_Tiles_NC;


class Pseudo_Tiff_Arg
{
     public :

        Pseudo_Tiff_Arg();
        Pseudo_Tiff_Arg
        (
              tFileOffset      offs0,
              Pt2di            sz,
              GenIm::type_el   type_im,
              int              nb_chan,
              bool             chunk_conf,
              Pt2di            sz_tile,
              bool             clip_tile,
              bool             create
        );

        bool             _bidon;
        tFileOffset      _offs0;
        Pt2di            _sz;
        GenIm::type_el   _type_im;
        int              _nb_chan;
        bool             _chunk_conf;
        Pt2di            _sz_tile;
        bool             _clip_tile;
        bool             _create;

        int  byte_sz_tile(Pt2di Ktile) const;
        int  nb_tile() const;
        int  nb_tile_x() const;
        int  nb_tile_y() const;
        int  nb_plan() const;
        int  chan_by_plan() const;
        tFileOffset  sz_tot() const;

};




class DATA_tiff_header : public  RC_Object
{
      friend class  Tiff_File;

      public :


      private :

         Tiff_Im kth_im(int kth);


         DATA_tiff_header (const char * name);
         virtual ~DATA_tiff_header();

         bool           _byte_ordered;
         Tprov_char *   _tprov_name;
         char *         _name;

         ELISE_fp   kth_file(int & nb,bool read); 
         int        nb_im(); 
         
};

/*
     "Ancillary" class D_Tiff_ifd_Arg_opt. The argopt
    class D_Tiff_ifd_Arg_opt do not modify directly 
    a DATA_Tiff_Ifd, but a D_Tiff_ifd_Arg_opt. This allow :

       - 1) Not to declare many much new friend to DATA_Tiff_Ifd;

       - 2) To post-treat the possible incompatible request
       in Arg_Opt (such as fixing both Tilings and stripping);
*/


class D_Tiff_ifd_Arg_opt
{
      friend class DATA_Tiff_Ifd;

      public :
          int     _predictor;
          Pt2di   _sz_tile;
          int     _row_per_strip;
          int     _no_strip;
          int     _plan_conf;

          bool    _init_min_maxs;
          int     _maxs;
          int     _mins;

          int     _res_unit;
          Pt2dr   _resol;
          int     _orientation;
	  Pt2di   mSzFileTile;

          double       mExifTiff_FocalEqui35Length;
          double       mExifTiff_FocalLength;
          double       mExifTiff_ShutterSpeed;
          double       mExifTiff_Aperture;
          double       mExifTiff_IsoSpeed;
          cElDate      mExifTiff_Date;
          std::string  mExifTiff_Camera;

      private :
          D_Tiff_ifd_Arg_opt();
          void modif(L_Arg_Opt_Tiff);
};



template <class Type> class UnLoadPackBit
{
	public :
		static PackB_IM<Type>  Do(DATA_Tiff_Ifd &,Tiff_Im::COMPR_TYPE);
};

class DATA_Tiff_Ifd : public ElDataGenFileIm
{

      


      friend class Tiff_Tiles_MPD_T6;
      friend class Tiff_Tiles_Ccit4_2D_T6;
      friend class Tiff_Tiles_Ccit3_1D;
      friend class Tiff_Tiles_LZW;
      friend class  Tiff_File;
      friend class  Tiff_file_2d;
      friend class  Tiff_Tiles;
      friend class  Tiff_Tiles_NC;
      friend class  Tiff_Tiles_Cpr;
      friend class  Tiff_Im;
      friend class  Elise_Tiled_File_Im_2D;
      friend class  DATA_tiff_header;
      friend class  Tiff_Im_Not_Comp;

      friend class   TAG_TIF;
      friend class   TAG_TIF_SZX;
      friend class   TAG_TIF_SZY;
      friend class   TAG_TIF_BIT_P_CHAN;
      friend class   TAG_TIF_COMPR;
      friend class   TAG_TIF_PHIT_int;
      friend class   TAG_TIF_FILL_ORDER;
      friend class   TAG_TIF_STRIP_OFFS;
      friend class   TAG_TIF_ORIENTATION;
      friend class   TAG_TIF_NB_CHAN;
      friend class   TAG_TIF_ROW_P_STR;
      friend class   TAG_TIF_STRIP_BYTEC;
      friend class   TAG_TIF_VMIN_SAMP;
      friend class   TAG_TIF_VMAX_SAMP;
      friend class   TAG_TIF_XRESOL;
      friend class   TAG_TIF_YRESOL;
      friend class   TAG_TIF_PLAN_CONFIG;
      friend class   TAG_TIF_RESOL_UNIT;
      friend class   TAG_TIF_PREDICTOR;
      friend class   TAG_TIF_TILE_WIDTH;
      friend class   TAG_TIF_TILE_LENGTH;
      friend class   TAG_TIF_TILE_OFFS;
      friend class   TAG_TIF_TILE_BYTEC;
      friend class   TAG_TIF_DATA_FORMAT;
      friend class   TAG_T6_OPTIONS;
      friend class   TAG_TIF_RGB_PALETTE;
      friend class   cTAG_TIF_TileFileWidth;
      friend class   cTAG_TIF_TileFileLength;

      friend class   cTAG_TIF_ExifTiff_IsoSpeed;
      friend class   cTAG_TIF_ExifTiff_Aperture;
      friend class   cTAG_TIF_ExifTiff_FocalLength;
      friend class   cTAG_TIF_ExifTiff_FocalEqui35Length;
      friend class   cTAG_TIF_ExifTiff_ShutterSpeed;
      friend class   cTAG_TIF_ExifTiff_Camera;
      friend class   cTAG_TIF_ExifTiff_Date;

      friend class   Pseudo_Tiff_Arg;


/*
#if (STRICT_ANSI_FRIEND_TPL)
	  template <class Type> friend class UnLoadPackBit<Type>;
#else
#endif
*/
	   friend class UnLoadPackBit<U_int1>;
	   friend class UnLoadPackBit<U_int2>;
	  bool  OkFor_un_load_pack_bit(int Nbb,Tiff_Im::COMPR_TYPE);


     public :
           const char *  name() const {return  _name;}
           cMetaDataPhoto  MDP();
      private :

           class  vmodif
           {
              public :
                  vmodif ();
                  void flush();
                  void init(int v0,int nb);
                  void init_if_0(int v0,int nb);
                  void init(int *v,int nb);

                  int   * _vals;
                  int     _nb;
                  tFileOffset     _offs;
           };

           void            show();
           bool            refuse_for_ever();
           const char *    why_elise_cant_use();
           void            post_init(const char * name);
	   std::string     NameTileFile(Pt2di aITF);
           Disc_Pal              pal();

           tFileOffset   offset_tile(int x,int y,int kth_ch);
           tFileOffset   byte_count_tile(int x,int y,int kth_ch);
           inline int   num_tile(int x,int y,int kth_ch);

           GenIm::type_el  type_el();
           void set_value_tile
                (
                    ELISE_fp & fp,
                    int x,
                    int y,
                    int kth_ch,
                    tFileOffset value,
                    tFileOffset offset_file,
                    tFileOffset * tab_val 
                );
           void set_offs_tile
                (
                    ELISE_fp & fp,
                    int x,
                    int y,
                    int kth_ch,
                    tFileOffset offs
                );

           void set_count_tile
                (
                    ELISE_fp & fp,
                    int x,
                    int y,
                    int kth_ch,
                    tFileOffset nb_byte
                );



           virtual ~DATA_Tiff_Ifd(); 
           DATA_Tiff_Ifd
           (
                   bool     byte_ordered,
                   ELISE_fp fp,
                   const char *,
                   const Pseudo_Tiff_Arg &
           );

           DATA_Tiff_Ifd
           (     const char                  *,
                 Pt2di                       sz,
                 GenIm::type_el              type,
                 Tiff_Im::COMPR_TYPE         compr,
                 Tiff_Im::PH_intER_TYPE      phot_interp,
		 Disc_Pal *                      aPal,
                 Elise_colour                    *,
                 int                             nb,
                 L_Arg_Opt_Tiff            l = Tiff_Im::Empty_ARG
           );




           bool           _byte_ordered;
           Tprov_char *   _tprov_name;
           char *         _name;
           bool           _msbit_first;
           bool           _clip_last;
           
           Pt2di                       _sz;
           Pt2di                       _sz_tile;
	   int                         mUseFileTile;
	   Pt2di                       mSzFileTile;
	   // Nombre de sous-dalle Tiff par dalle de fichier
	   Pt2di                       mNbTTByTF;

              //  This three values are to be understood
              // once uncompressed, padding included

                        // number of numerical values
           tFileOffset                         _padded_line_el_sz_tiles;  
           tFileOffset                         _line_el_sz_tiles;  
           tFileOffset                         _line_byte_sz_tiles;  
           tFileOffset                         _byte_sz_tiles;  
           int                                 _nb_chan_per_tile;
           

           int    *                    _palette;
           int                         _nb_pal_entry;


           bool                        _tiled;
           Pt2dr                       _resol;
           int                         _res_unit;
           Pt2di                       _nb_tile;
           tFileOffset                 _nb_tile_tot;

           int *                       _bits_p_chanel;
           int                         _nbb_ch0;
           int                         _nbb_tot;// sum of _bits_p_chanel
           tFileOffset *               _tiles_offset;
           tFileOffset                 _offs_toffs;
           tFileOffset *               _tiles_byte_count;
           tFileOffset                 _offs_bcount;
           int                         _nb_chanel;
           int                         _mode_compr;
           int                         _phot_interp;
           int                         _plan_conf;
           int *                       _data_format;
           int                         _predict;
           bool                        _ccitt_ucomp;
           int                         _orientation;
           double                       mExifTiff_FocalLength;
           double                       mExifTiff_FocalEqui35Length;
           double                       mExifTiff_ShutterSpeed;
           double                       mExifTiff_Aperture;
           double                       mExifTiff_IsoSpeed;
           cElDate                      mExifTiff_Date;
           std::string                  mExifTiff_Camera;

           vmodif                      _maxs;
           vmodif                      _mins;
           
           int                          _padding_constr;
                      // the number of "physical" el by line must ne
                      // multiple of padding

           int                         _sz_byte_pel_unpacked;
           GenIm::type_el              _type_el;
           GenIm::type_el              _unpacked_type_el; 
                                       // _type_el if  bits per pixel >= 8
                                       // u_int1 elsewhere

          virtual   Fonc_Num in()     ;
          virtual   Fonc_Num in(double_t) ;
          virtual   Output out()    ;

};

extern void  lire_all_tiff_tag(DATA_Tiff_Ifd *,ELISE_fp);
extern void  lire_all_tiff_tag(DATA_Tiff_Ifd *,const Pseudo_Tiff_Arg &);
extern void  write_all_tiff_tag(DATA_Tiff_Ifd *,ELISE_fp);


class Tiff_file_2d : public Std_Bitm_Fich_Im_2d
{
      friend class Tiff_Tiles_NC;
      friend class Tiff_Tiles_Cpr;
      friend class Tiff_Tiles;
      friend class Tiff_Tiles_LZW;
      friend class Tiff_Tiles_Ccit3_1D;
      friend class Tiff_Tiles_Ccit4_2D_T6;
      friend class Tiff_Tiles_MPD_T6;

      public :
          Tiff_file_2d
          (
              Flux_Pts_Computed *,
              DATA_Tiff_Ifd *,
              bool read_mode,
              int  nb_chan,
              int  kth_channel,
              Tiff_file_2d * princ = 0
          );

      private :

          virtual ~Tiff_file_2d();

          Tiff_Tiles * alloc_tile();

           DATA_Tiff_Ifd *              _dti;
           int                          _nb_chan;
           int                          _kth_ch;
           Tiff_file_2d               * _princ;

           //  will there have only one tiles open  at each moment
           bool                         _single_tile;

           // For compressed Writable-File, it is however
           // safer to have a single opened files so put it in
           // common via the File.

           void init_stdpf();

               Std_Packed_Flux_Of_Byte * _stdpf;
               ELISE_fp &                _fp;
               bool                      _read;

           static ELISE_fp  _Bidon_for_ref;

    static bool is_tile_front 
                (
                    int x,
                    int tx,
                    int sz_tile,
                    int & num
                );

    static bool is_tile_corner 
                (
                    Pt2di  p,
                    Pt2di  sz,
                    Pt2di  tile,
                    Pt2di  & num
                );
};



class Tiff_Tiles : public Tile_F2d
{
     public :
          // DECLAR_DTI_THIS;
          Tiff_Tiles();
          ~Tiff_Tiles();

          void new_tile(class Fich_Im2d *,bool read_mode) ;

          Std_Packed_Flux_Of_Byte * 
             init_pfob(DATA_Tiff_Ifd *,class Tiff_file_2d *,bool read);

	  int             mCurNumYTileFile;
	  Tiff_Im *       mTifTile;
	  DATA_Tiff_Ifd * mDTITile;
};


class Tiff_Tiles_NC : public Tiff_Tiles
{
     public :
          Tiff_Tiles_NC() : Tiff_Tiles(){}


          virtual  void r_use_this_tile(class Fich_Im2d *);
          virtual  void w_use_this_tile(class Fich_Im2d *);
          virtual  void use_this_tile(class Fich_Im2d *,bool read);

          virtual  void r_new_tile(class Fich_Im2d *) ;
          virtual  void w_new_tile(class Fich_Im2d *) ;


          virtual void seek_pack_line
                                 (Fich_Im2d *,int y0,int y1,bool read_mode);

};






#endif  // _ELISE_PRIVATE_TIFF_H





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
