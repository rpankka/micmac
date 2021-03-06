#ifndef _SDATA2CORREL_H
#define _SDATA2CORREL_H

#include "GpGpu/GpGpu_ParamCorrelation.cuh"

extern "C" textureReference&    getMaskGlobal();
extern "C" textureReference&	getMask();
extern "C" textureReference&	getImage();
extern "C" textureReference&	getProjection(int TexSel);
extern "C" textureReference&    getTexL_MaskImages();

#define SYNC    false
#define ASYNC   true


///
/// \brief The cellules struct
/// Structure de cellules 3D
struct cellules
{
    ///
    /// \brief Zone
    /// La zone 2d
    ///
    Rect Zone;
    ///
    /// \brief Dz
    /// delta Z de la zone
    ///
	ushort Dz;

    cellules():
        Zone(MAXIRECT),
        Dz(intERZ)
    {}
};

///
/// \brief The SData2Correl struct
///
struct SData2Correl
{

public:
    SData2Correl();

    ~SData2Correl();

    void    SetImages( float* dataImage, uint2 dimImage, int nbLayer );

    void    SetGlobalMask( pixel* dataMask, uint2 dimMask );

    void    MemsetHostVolumeProj(int iDef);

    float*  HostVolumeCost(uint id);

    float2* HostVolumeProj();

	uint2*	HostRect();

    uint*   DeviVolumeNOK(uint s);

    float*  DeviVolumeCache(uint s);

    float*  DeviVolumeCost(uint s);

	uint2*	DeviRect();

    void    copyHostToDevice(pCorGpu param, uint s = 0);

    void    CopyDevicetoHost(uint idBuf, uint s = 0);

    void    UnBindTextureProj(uint s = 0);

    void    DeallocHostData();

    void    DeallocDeviceData();

    void    ReallocHostData(uint zInter, pCorGpu param);

    void    ReallocHostData(uint zInter, pCorGpu param, uint idBuff);

    void    ReallocDeviceData(pCorGpu &param);   

    ushort2 *HostClassEqui();

	void    ReallocConstData(uint nbImages);

	void    SyncConstData();

	void	SetZoneImage(const ushort& idImage, const uint2& sizeImage, const ushort2& r);

    ushort2 *DeviClassEqui();

    void    SetMaskImages(pixel *dataMaskImages, uint2 dimMaskImage, int nbLayer);

private:

    void    ReallocDeviceData(int nStream, pCorGpu param);

    void    MallocInfo();

    textureReference& GetTeXProjection( int TexSel );

    CuHostData3D<float>         _hVolumeCost[2];
    CuHostData3D<float2>        _hVolumeProj;

    // TODO il semblerait qu'un uint2 suffirai....
    ///
    /// \brief _hRect   HOST     gestion des bords d'images
    ///
//    CuHostData3D<Rect>          _hRect;
    ///
    /// \brief _dRect   Device   gestion des bords d'images
    ///
//    CuDeviceData3D<Rect>        _dRect;

	CuUnifiedData3D<uint2>		_uRect;

    ///
    /// \brief _hClassEqui HOST     gestion des classes d'images
    ///
	//CuHostData3D<ushort2>       _hClassEqui;
    ///
    /// \brief _dClassEqui DEVICE    gestion des classes d'images
    ///
	//CuDeviceData3D<ushort2>     _dClassEqui;
	CuUnifiedData3D<ushort2>     _uClassEqui;


    CuDeviceData3D<float>       _d_volumeCost[NSTREAM];	// volume des couts
    CuDeviceData3D<float>       _d_volumeCach[NSTREAM];	// volume des calculs intermédiaires
    CuDeviceData3D<uint>        _d_volumeNIOk[NSTREAM];	// nombre d'image correct pour une vignette

    ImageGpGpu<pixel,cudaContext>           _dt_GlobalMask;
    ImageLayeredGpGpu<float,cudaContext>    _dt_LayeredImages;
    ImageLayeredGpGpu<pixel,cudaContext>    _dt_LayeredMaskImages;
    ImageLayeredGpGpu<float2,cudaContext>   _dt_LayeredProjection[NSTREAM];

    textureReference&           _texMaskGlobal;
    textureReference&           _TexMaskImages;
    textureReference&           _texImages;
    textureReference&           _texProjections_00;
    textureReference&           _texProjections_01;

    void DeviceMemset(pCorGpu &param, uint s = 0);
};

#endif
