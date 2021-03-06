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



/*
    As I do not know standards for manipulating "Images" of
   dimention "1,2,3,..." (== array), we define a simple format.
*/

//    Elis_File_Im is actually a smart pointer to Data_Elis_File_Im 
//  that realy contain  the information.

#ifndef _ELISE_FILEIM_H  // general
#define _ELISE_FILEIM_H

#include <general/bitm.h>


class ElDataGenFileIm;
class Data_GifIm;

class ElGenFileIm :  public PRC0,
        public Rectang_Object
{
public :

    virtual ~ElGenFileIm();

    // caracteristique logique :

    int              Dim()       const;
    const int *      Sz()        const;
    int              NbChannel() const;
    Pt2di 			Sz2() const;  // Error if Dim != 1


    // caracteristique physique liees a la  representation
    // des valeurs numeriques

    bool       SigneType()      const;
    bool       IntegralType()   const ;
    int        NbBits()         const;
    GenIm::type_el type_el();

    // carateristique d'organisation du fichier

    const int *      SzTile() const;
    bool       Compressed() const;

    Fonc_Num in();
    Fonc_Num in(double_t val);
    Output   out();


protected :

    ElGenFileIm(ElDataGenFileIm *);

private :

    virtual Elise_Rect box() const;
    const ElDataGenFileIm * edgfi() const;
    ElDataGenFileIm * edgfi();

};

template <class Type>  Im2D<Type,typename El_CTypeTraits<Type>::tBase> LoadFileIm(ElGenFileIm,Type * = 0);

class Elise_Tiled_File_Im_2D;
class Data_Elise_File_Im;

class Elise_File_Im : public ElGenFileIm 
{
    friend class DataGenIm;
    friend class Data_Elise_File_Im;

public :
    /* Use this constructor for :
       1- Declare a file from another compatible format;
       2- To specify the paramater of a file to create.
   */
    virtual ~Elise_File_Im();
    Elise_File_Im
    (
            const char *     name,
            int        dim,        // 2 for usual images
            int *      sz,         // tx,ty for usual images
            GenIm::type_el,        // U_int1,int ....
            int        dim_out,    // 1 for gray level, 3 for RVB ...
            tFileOffset        offset_0,   // size of header to pass
            int        _szd0 = -1,  // see just down
            bool       create = false      // if does not exist
            );


    // _szd0 : the "physical" size in first dim,  currently
    //        _szd0 = sz[0] and this  assumed when _szd0 is given
    //         the default values -1; however, it can differ
    //         for padding reason (for example, with a 1 bits images,
    //         padded for each line, we may have _szd0 = 16, when
    //         sz[0] = 13


    // to create a pnm,pgm,ppm file
    static Elise_File_Im pbm (const char *,Pt2di  sz,char ** comment = 0);
    static Elise_File_Im pgm (const char *,Pt2di  sz,char ** comment = 0);
    static Elise_File_Im ppm (const char *,Pt2di  sz,char ** comment = 0);


    // to open an alreaduy created  file
    static Elise_File_Im pnm(const char *);


    // for simple 1d-file
    Elise_File_Im
    (
            const char *     name,
            int        sz,      // tx,ty for usual images
            GenIm::type_el,      // U_int1,int ....
            tFileOffset    offset_0 = 0,  // size of header to pass
            bool       create = false      // if does not exist
            );
    // for simple 2d-file
    Elise_File_Im
    (
            const char *     name,
            Pt2di       sz,      // tx,ty for usual images
            GenIm::type_el,      // U_int1,int ....
            tFileOffset    offset_0 = 0,  // size of header to pass
            bool       create = false      // if does not exist
            );

    // for simple 3d-file
    Elise_File_Im
    (
            const char *     name,
            Pt3di       sz,      // tx,ty for usual images
            GenIm::type_el,      // U_int1,int ....
            tFileOffset    offset_0 = 0,  // size of header to pass
            bool       create = false      // if does not exist
            );

    /* Use this constructor for a file created under Elise.
         Elise_File_Im(const char * name);
     */

    Fonc_Num in();
    Fonc_Num in(double_t);

    // Image file are, by default, always cliped when used as
    // output.
    Output out();

    // Use this if you really do not want cliping. BUT, be sure
    // that you do not get out of the file.
    Output onotcl();

    virtual Elise_Rect box() const;

    Elise_Tiled_File_Im_2D  to_elise_tiled(bool byte_ordered = true);
    Tiff_Im to_tiff(bool byte_ordered = true);

private  :

    Elise_File_Im(Data_Elise_File_Im *);

    static Elise_File_Im pnm
    (
            const char *,
            char **   comment,
            Pt2di  sz,
            GenIm::type_el,
            int    dim,
            int    mode_pnm
            );
    Data_Elise_File_Im * defi() const
    {
        return SAFE_DYNC(Data_Elise_File_Im *,_ptr);
    }
};

class Elise_Tiled_File_Im_2D : public ElGenFileIm 
{

public :
    /* Use this constructor for :
       1- Declare a file from another compatible format;
       2- To specify the paramater of a file to create.
   */
    virtual ~Elise_Tiled_File_Im_2D();
    static const bool DefCLT         = false;
    static const bool DefChunk       = true;
    static const int  DefOffset0     = 0;
    static const bool DefCreate      = false;
    static const bool DefByteOrdered = true;

    Elise_Tiled_File_Im_2D
    (
            const char *     name                   ,
            Pt2di            sz                     ,
            GenIm::type_el   type                   ,
            int              dim_out                ,
            Pt2di            sz_tiles               ,
            bool             clip_last_tile = DefCLT,         // false ,
            bool             chunk          = DefChunk,       // true  ,
            tFileOffset              offset_0       = DefOffset0,     // 0     ,
            bool             create         = DefCreate,      // false ,
            bool             byte_ordered   = DefByteOrdered  // true
            );

    Fonc_Num in();
    Fonc_Num in(double_t def_out);
    Output out();

    static Elise_Tiled_File_Im_2D HDR(const std::string & aNameHdr);
    static Elise_Tiled_File_Im_2D XML(const std::string & aNameHdr);
    static Elise_Tiled_File_Im_2D Saphir
    (const char * name_file,const char * name_header);
    static Elise_Tiled_File_Im_2D  sun_raster(const char *);
    static Elise_Tiled_File_Im_2D Thom (const char * name_file);

    Tiff_Im to_tiff();

private  :

    class DATA_Tiff_Ifd * dtifd();
};



/*************************************************************/
/*************************************************************/
/*************************************************************/
/*************************************************************/

class Video_Win;
class Video_Display;
class Disc_Pal;
class Elise_colour;

void test_gif(char  * name, Video_Win, Video_Display);

class Gif_Im : public ElGenFileIm
{
    friend class Data_Giff;
    friend class Data_GifIm;
    friend class Gif_Im_Not_Comp;
    friend void instatiate_liste();

public :
    Gif_Im(const char * name);
    Im2D_U_int1     im();
    Disc_Pal              pal();
    Fonc_Num              in();
    Fonc_Num              in(int);
    Pt2di                 sz();

    static  Output create  (
            const char *             name,
            Pt2di              sz,
            Elise_colour *     tec,
            int                nbb
            );


private :
    Gif_Im(const char * name,class ELISE_fp fp,class Data_Giff *gh);
    Gif_Im(Data_GifIm *);
    class Data_GifIm * dgi()
    { return SAFE_DYNC(class Data_GifIm *,_ptr);}

};

typedef ElList<Gif_Im> L_Gif_Im;



class Gif_File : public PRC0
{
public :
    Gif_File(const char * name);

    int      nb_im   ()        const;
    Gif_Im   kth_im  (int)     const;


private :
    class Data_Giff * dgi() const
    {return SAFE_DYNC(Data_Giff *,_ptr);}
};



/*************************************************************/
/*************************************************************/
/*************************************************************/
/*************************************************************/


class  Tga_Im : public PRC0
{
    friend class Tga_Im_Not_Comp;
public :

    typedef enum
    {
        col_maped = 0,
        true_col  = 1,
        bw_image  = 2
    } type_of_image;

    typedef enum
    {
        no_compr,
        rle_compr
    } mode_compr;






    Tga_Im(const char * name);
    Fonc_Num              in();
    Fonc_Num              in(int);

    bool                im_present() const;
    type_of_image       toi()        const;


private :
    class Data_TGA_File * dtga() const
    {return SAFE_DYNC(Data_TGA_File *,_ptr);}
};



/*************************************************************/
/*************************************************************/
/*************************************************************/
/*************************************************************/

class  Bmp_Im : public PRC0
{
    friend class Bmp_Im_Not_Comp;
    friend class Bmp_Out_Not_Comp;
public :


    typedef enum
    {
        col_maped,
        true_col
    } type_of_image;

    typedef enum
    {
        no_compr  = 0,
        rle_8bits = 1,
        rle_4bits = 2
    } mode_compr;

    Bmp_Im(const char * name);
    Output              out();
    Fonc_Num              in();
    Fonc_Num              in(int);
    int      bpp() const;   // bits per pixel
    Disc_Pal   pal() const ;  // error when bpp() == 24
    mode_compr  compr();
    Pt2di       sz();

    bool                im_present() const;
    // type_of_image       toi()        const;


private :
    class Data_BMP_File * dbmp() const
    {return SAFE_DYNC(class Data_BMP_File *,_ptr);}
};

extern void test_ps();

class  ThomParam
{
public :
    ThomParam(const char * name_file);
    Elise_Tiled_File_Im_2D   file(const char * );

    //private :
    std::string ORIGINE,OBJECTIF,DATE,FORMAT;
    int MAXIMG,MINIMG,mCOULEUR,mCAMERA;
    int FOCALE,TDI,TAILLEPIX,NBCOL,NBLIG;
    std::string NOM;
    double_t EXPOTIME,DIAPHRAGME;
    int OFFSET;
    std::string MERE;
    int BLANC;
    int BIDON;
    int BYTEORD;
};

void MakeFileThomVide
(
        const std::string & aNameVide,
        const std::string& aNamePlein
        );

Im2D_Bits<1> MasqImThom
(
        const std::string & aNameThom,
        const std::string & aNameFileXML,
        Box2di &
        );

void ThomCorrigeCourrantObscur(Im2D_U_int2,const Box2di&);

#endif  //  _ELISE_FILEIM_H
