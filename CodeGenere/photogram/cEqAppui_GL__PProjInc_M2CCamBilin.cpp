// File Automatically generated by eLiSe
#include "StdAfx.h"
#include "cEqAppui_GL__PProjInc_M2CCamBilin.h"


cEqAppui_GL__PProjInc_M2CCamBilin::cEqAppui_GL__PProjInc_M2CCamBilin():
    cElCompiledFonc(2)
{
   AddIntRef (cIncIntervale("Bil0_0",3,5));
   AddIntRef (cIncIntervale("Bil0_1",7,9));
   AddIntRef (cIncIntervale("Bil1_0",5,7));
   AddIntRef (cIncIntervale("Bil1_1",9,11));
   AddIntRef (cIncIntervale("Intr",0,3));
   AddIntRef (cIncIntervale("Orient",11,17));
   AddIntRef (cIncIntervale("Tmp_PTer",17,20));
   Close(false);
}



void cEqAppui_GL__PProjInc_M2CCamBilin::ComputeVal()
{
   double tmp0_ = mCompCoord[11];
   double tmp1_ = mCompCoord[12];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = cos(tmp0_);
   double tmp4_ = tmp3_*tmp2_;
   double tmp5_ = sin(tmp0_);
   double tmp6_ = tmp5_*tmp2_;
   double tmp7_ = sin(tmp1_);
   double tmp8_ = mCompCoord[17];
   double tmp9_ = mCompCoord[18];
   double tmp10_ = mCompCoord[19];
   double tmp11_ = mCompCoord[13];
   double tmp12_ = sin(tmp11_);
   double tmp13_ = -(tmp12_);
   double tmp14_ = -(tmp7_);
   double tmp15_ = cos(tmp11_);
   double tmp16_ = mLocProjI_x*tmp8_;
   double tmp17_ = mLocProjP0_x+tmp16_;
   double tmp18_ = mLocProjJ_x*tmp9_;
   double tmp19_ = tmp17_+tmp18_;
   double tmp20_ = mLocProjK_x*tmp10_;
   double tmp21_ = tmp19_+tmp20_;
   double tmp22_ = mCompCoord[14];
   double tmp23_ = (tmp21_)-tmp22_;
   double tmp24_ = -(tmp5_);
   double tmp25_ = tmp24_*tmp13_;
   double tmp26_ = tmp3_*tmp14_;
   double tmp27_ = tmp26_*tmp15_;
   double tmp28_ = tmp25_+tmp27_;
   double tmp29_ = tmp3_*tmp13_;
   double tmp30_ = tmp5_*tmp14_;
   double tmp31_ = tmp30_*tmp15_;
   double tmp32_ = tmp29_+tmp31_;
   double tmp33_ = tmp2_*tmp15_;
   double tmp34_ = mLocProjI_y*tmp8_;
   double tmp35_ = mLocProjP0_y+tmp34_;
   double tmp36_ = mLocProjJ_y*tmp9_;
   double tmp37_ = tmp35_+tmp36_;
   double tmp38_ = mLocProjK_y*tmp10_;
   double tmp39_ = tmp37_+tmp38_;
   double tmp40_ = mCompCoord[15];
   double tmp41_ = (tmp39_)-tmp40_;
   double tmp42_ = mLocProjI_z*tmp8_;
   double tmp43_ = mLocProjP0_z+tmp42_;
   double tmp44_ = mLocProjJ_z*tmp9_;
   double tmp45_ = tmp43_+tmp44_;
   double tmp46_ = mLocProjK_z*tmp10_;
   double tmp47_ = tmp45_+tmp46_;
   double tmp48_ = mCompCoord[16];
   double tmp49_ = (tmp47_)-tmp48_;
   double tmp50_ = tmp24_*tmp15_;
   double tmp51_ = tmp26_*tmp12_;
   double tmp52_ = tmp50_+tmp51_;
   double tmp53_ = tmp3_*tmp15_;
   double tmp54_ = tmp30_*tmp12_;
   double tmp55_ = tmp53_+tmp54_;
   double tmp56_ = tmp2_*tmp12_;
   double tmp57_ = mCompCoord[0];
   double tmp58_ = (tmp28_)*mLocGL_0_0;
   double tmp59_ = (tmp32_)*mLocGL_1_0;
   double tmp60_ = tmp58_+tmp59_;
   double tmp61_ = tmp33_*mLocGL_2_0;
   double tmp62_ = tmp60_+tmp61_;
   double tmp63_ = (tmp62_)*(tmp23_);
   double tmp64_ = (tmp28_)*mLocGL_0_1;
   double tmp65_ = (tmp32_)*mLocGL_1_1;
   double tmp66_ = tmp64_+tmp65_;
   double tmp67_ = tmp33_*mLocGL_2_1;
   double tmp68_ = tmp66_+tmp67_;
   double tmp69_ = (tmp68_)*(tmp41_);
   double tmp70_ = tmp63_+tmp69_;
   double tmp71_ = (tmp28_)*mLocGL_0_2;
   double tmp72_ = (tmp32_)*mLocGL_1_2;
   double tmp73_ = tmp71_+tmp72_;
   double tmp74_ = tmp33_*mLocGL_2_2;
   double tmp75_ = tmp73_+tmp74_;
   double tmp76_ = (tmp75_)*(tmp49_);
   double tmp77_ = tmp70_+tmp76_;
   double tmp78_ = tmp57_/(tmp77_);
   double tmp79_ = tmp4_*mLocGL_0_0;
   double tmp80_ = tmp6_*mLocGL_1_0;
   double tmp81_ = tmp79_+tmp80_;
   double tmp82_ = tmp7_*mLocGL_2_0;
   double tmp83_ = tmp81_+tmp82_;
   double tmp84_ = (tmp83_)*(tmp23_);
   double tmp85_ = tmp4_*mLocGL_0_1;
   double tmp86_ = tmp6_*mLocGL_1_1;
   double tmp87_ = tmp85_+tmp86_;
   double tmp88_ = tmp7_*mLocGL_2_1;
   double tmp89_ = tmp87_+tmp88_;
   double tmp90_ = (tmp89_)*(tmp41_);
   double tmp91_ = tmp84_+tmp90_;
   double tmp92_ = tmp4_*mLocGL_0_2;
   double tmp93_ = tmp6_*mLocGL_1_2;
   double tmp94_ = tmp92_+tmp93_;
   double tmp95_ = tmp7_*mLocGL_2_2;
   double tmp96_ = tmp94_+tmp95_;
   double tmp97_ = (tmp96_)*(tmp49_);
   double tmp98_ = tmp91_+tmp97_;
   double tmp99_ = (tmp98_)*(tmp78_);
   double tmp100_ = mCompCoord[1];
   double tmp101_ = tmp99_+tmp100_;
   double tmp102_ = mLocPts1_x-(tmp101_);
   double tmp103_ = mLocPts1_x-mLocPts0_x;
   double tmp104_ = (tmp102_)/(tmp103_);
   double tmp105_ = (tmp52_)*mLocGL_0_0;
   double tmp106_ = (tmp55_)*mLocGL_1_0;
   double tmp107_ = tmp105_+tmp106_;
   double tmp108_ = tmp56_*mLocGL_2_0;
   double tmp109_ = tmp107_+tmp108_;
   double tmp110_ = (tmp109_)*(tmp23_);
   double tmp111_ = (tmp52_)*mLocGL_0_1;
   double tmp112_ = (tmp55_)*mLocGL_1_1;
   double tmp113_ = tmp111_+tmp112_;
   double tmp114_ = tmp56_*mLocGL_2_1;
   double tmp115_ = tmp113_+tmp114_;
   double tmp116_ = (tmp115_)*(tmp41_);
   double tmp117_ = tmp110_+tmp116_;
   double tmp118_ = (tmp52_)*mLocGL_0_2;
   double tmp119_ = (tmp55_)*mLocGL_1_2;
   double tmp120_ = tmp118_+tmp119_;
   double tmp121_ = tmp56_*mLocGL_2_2;
   double tmp122_ = tmp120_+tmp121_;
   double tmp123_ = (tmp122_)*(tmp49_);
   double tmp124_ = tmp117_+tmp123_;
   double tmp125_ = (tmp124_)*(tmp78_);
   double tmp126_ = mCompCoord[2];
   double tmp127_ = tmp125_+tmp126_;
   double tmp128_ = mLocPts2_y-(tmp127_);
   double tmp129_ = mLocPts2_y-mLocPts0_y;
   double tmp130_ = (tmp128_)/(tmp129_);
   double tmp131_ = 1-tmp104_;
   double tmp132_ = 1-tmp130_;
   double tmp133_ = (tmp104_)*(tmp130_);
   double tmp134_ = (tmp131_)*(tmp130_);
   double tmp135_ = (tmp104_)*(tmp132_);
   double tmp136_ = (tmp131_)*(tmp132_);

  mVal[0] = ((mCompCoord[3]*tmp133_+mCompCoord[5]*tmp134_+mCompCoord[7]*tmp135_+mCompCoord[9]*tmp136_)-mLocXIm)*mLocScNorm;

  mVal[1] = ((mCompCoord[4]*tmp133_+mCompCoord[6]*tmp134_+mCompCoord[8]*tmp135_+mCompCoord[10]*tmp136_)-mLocYIm)*mLocScNorm;

}


void cEqAppui_GL__PProjInc_M2CCamBilin::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[11];
   double tmp1_ = mCompCoord[12];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = cos(tmp0_);
   double tmp4_ = tmp3_*tmp2_;
   double tmp5_ = sin(tmp0_);
   double tmp6_ = tmp5_*tmp2_;
   double tmp7_ = sin(tmp1_);
   double tmp8_ = mCompCoord[17];
   double tmp9_ = mCompCoord[18];
   double tmp10_ = mCompCoord[19];
   double tmp11_ = mCompCoord[13];
   double tmp12_ = sin(tmp11_);
   double tmp13_ = -(tmp12_);
   double tmp14_ = -(tmp7_);
   double tmp15_ = cos(tmp11_);
   double tmp16_ = mLocProjI_x*tmp8_;
   double tmp17_ = mLocProjP0_x+tmp16_;
   double tmp18_ = mLocProjJ_x*tmp9_;
   double tmp19_ = tmp17_+tmp18_;
   double tmp20_ = mLocProjK_x*tmp10_;
   double tmp21_ = tmp19_+tmp20_;
   double tmp22_ = mCompCoord[14];
   double tmp23_ = (tmp21_)-tmp22_;
   double tmp24_ = -(tmp5_);
   double tmp25_ = tmp24_*tmp13_;
   double tmp26_ = tmp3_*tmp14_;
   double tmp27_ = tmp26_*tmp15_;
   double tmp28_ = tmp25_+tmp27_;
   double tmp29_ = tmp3_*tmp13_;
   double tmp30_ = tmp5_*tmp14_;
   double tmp31_ = tmp30_*tmp15_;
   double tmp32_ = tmp29_+tmp31_;
   double tmp33_ = tmp2_*tmp15_;
   double tmp34_ = mLocProjI_y*tmp8_;
   double tmp35_ = mLocProjP0_y+tmp34_;
   double tmp36_ = mLocProjJ_y*tmp9_;
   double tmp37_ = tmp35_+tmp36_;
   double tmp38_ = mLocProjK_y*tmp10_;
   double tmp39_ = tmp37_+tmp38_;
   double tmp40_ = mCompCoord[15];
   double tmp41_ = (tmp39_)-tmp40_;
   double tmp42_ = mLocProjI_z*tmp8_;
   double tmp43_ = mLocProjP0_z+tmp42_;
   double tmp44_ = mLocProjJ_z*tmp9_;
   double tmp45_ = tmp43_+tmp44_;
   double tmp46_ = mLocProjK_z*tmp10_;
   double tmp47_ = tmp45_+tmp46_;
   double tmp48_ = mCompCoord[16];
   double tmp49_ = (tmp47_)-tmp48_;
   double tmp50_ = tmp24_*tmp15_;
   double tmp51_ = tmp26_*tmp12_;
   double tmp52_ = tmp50_+tmp51_;
   double tmp53_ = tmp3_*tmp15_;
   double tmp54_ = tmp30_*tmp12_;
   double tmp55_ = tmp53_+tmp54_;
   double tmp56_ = tmp2_*tmp12_;
   double tmp57_ = mCompCoord[0];
   double tmp58_ = (tmp28_)*mLocGL_0_0;
   double tmp59_ = (tmp32_)*mLocGL_1_0;
   double tmp60_ = tmp58_+tmp59_;
   double tmp61_ = tmp33_*mLocGL_2_0;
   double tmp62_ = tmp60_+tmp61_;
   double tmp63_ = (tmp62_)*(tmp23_);
   double tmp64_ = (tmp28_)*mLocGL_0_1;
   double tmp65_ = (tmp32_)*mLocGL_1_1;
   double tmp66_ = tmp64_+tmp65_;
   double tmp67_ = tmp33_*mLocGL_2_1;
   double tmp68_ = tmp66_+tmp67_;
   double tmp69_ = (tmp68_)*(tmp41_);
   double tmp70_ = tmp63_+tmp69_;
   double tmp71_ = (tmp28_)*mLocGL_0_2;
   double tmp72_ = (tmp32_)*mLocGL_1_2;
   double tmp73_ = tmp71_+tmp72_;
   double tmp74_ = tmp33_*mLocGL_2_2;
   double tmp75_ = tmp73_+tmp74_;
   double tmp76_ = (tmp75_)*(tmp49_);
   double tmp77_ = tmp70_+tmp76_;
   double tmp78_ = tmp57_/(tmp77_);
   double tmp79_ = tmp4_*mLocGL_0_0;
   double tmp80_ = tmp6_*mLocGL_1_0;
   double tmp81_ = tmp79_+tmp80_;
   double tmp82_ = tmp7_*mLocGL_2_0;
   double tmp83_ = tmp81_+tmp82_;
   double tmp84_ = (tmp83_)*(tmp23_);
   double tmp85_ = tmp4_*mLocGL_0_1;
   double tmp86_ = tmp6_*mLocGL_1_1;
   double tmp87_ = tmp85_+tmp86_;
   double tmp88_ = tmp7_*mLocGL_2_1;
   double tmp89_ = tmp87_+tmp88_;
   double tmp90_ = (tmp89_)*(tmp41_);
   double tmp91_ = tmp84_+tmp90_;
   double tmp92_ = tmp4_*mLocGL_0_2;
   double tmp93_ = tmp6_*mLocGL_1_2;
   double tmp94_ = tmp92_+tmp93_;
   double tmp95_ = tmp7_*mLocGL_2_2;
   double tmp96_ = tmp94_+tmp95_;
   double tmp97_ = (tmp96_)*(tmp49_);
   double tmp98_ = tmp91_+tmp97_;
   double tmp99_ = (tmp98_)*(tmp78_);
   double tmp100_ = mCompCoord[1];
   double tmp101_ = tmp99_+tmp100_;
   double tmp102_ = mLocPts1_x-(tmp101_);
   double tmp103_ = mLocPts1_x-mLocPts0_x;
   double tmp104_ = (tmp102_)/(tmp103_);
   double tmp105_ = (tmp52_)*mLocGL_0_0;
   double tmp106_ = (tmp55_)*mLocGL_1_0;
   double tmp107_ = tmp105_+tmp106_;
   double tmp108_ = tmp56_*mLocGL_2_0;
   double tmp109_ = tmp107_+tmp108_;
   double tmp110_ = (tmp109_)*(tmp23_);
   double tmp111_ = (tmp52_)*mLocGL_0_1;
   double tmp112_ = (tmp55_)*mLocGL_1_1;
   double tmp113_ = tmp111_+tmp112_;
   double tmp114_ = tmp56_*mLocGL_2_1;
   double tmp115_ = tmp113_+tmp114_;
   double tmp116_ = (tmp115_)*(tmp41_);
   double tmp117_ = tmp110_+tmp116_;
   double tmp118_ = (tmp52_)*mLocGL_0_2;
   double tmp119_ = (tmp55_)*mLocGL_1_2;
   double tmp120_ = tmp118_+tmp119_;
   double tmp121_ = tmp56_*mLocGL_2_2;
   double tmp122_ = tmp120_+tmp121_;
   double tmp123_ = (tmp122_)*(tmp49_);
   double tmp124_ = tmp117_+tmp123_;
   double tmp125_ = (tmp124_)*(tmp78_);
   double tmp126_ = mCompCoord[2];
   double tmp127_ = tmp125_+tmp126_;
   double tmp128_ = mLocPts2_y-(tmp127_);
   double tmp129_ = mLocPts2_y-mLocPts0_y;
   double tmp130_ = (tmp128_)/(tmp129_);
   double tmp131_ = 1-tmp104_;
   double tmp132_ = 1-tmp130_;
   double tmp133_ = ElSquare(tmp77_);
   double tmp134_ = (tmp77_)/tmp133_;
   double tmp135_ = mCompCoord[3];
   double tmp136_ = (tmp134_)*(tmp98_);
   double tmp137_ = -(tmp136_);
   double tmp138_ = tmp137_*(tmp103_);
   double tmp139_ = ElSquare(tmp103_);
   double tmp140_ = (tmp138_)/tmp139_;
   double tmp141_ = (tmp134_)*(tmp124_);
   double tmp142_ = -(tmp141_);
   double tmp143_ = tmp142_*(tmp129_);
   double tmp144_ = ElSquare(tmp129_);
   double tmp145_ = (tmp143_)/tmp144_;
   double tmp146_ = mCompCoord[5];
   double tmp147_ = mCompCoord[7];
   double tmp148_ = -(tmp140_);
   double tmp149_ = -(tmp145_);
   double tmp150_ = mCompCoord[9];
   double tmp151_ = -(1);
   double tmp152_ = tmp151_*(tmp103_);
   double tmp153_ = (tmp152_)/tmp139_;
   double tmp154_ = -(tmp153_);
   double tmp155_ = tmp151_*(tmp129_);
   double tmp156_ = (tmp155_)/tmp144_;
   double tmp157_ = -(tmp156_);
   double tmp158_ = (tmp104_)*(tmp130_);
   double tmp159_ = (tmp131_)*(tmp130_);
   double tmp160_ = (tmp104_)*(tmp132_);
   double tmp161_ = (tmp131_)*(tmp132_);
   double tmp162_ = tmp151_*tmp5_;
   double tmp163_ = tmp162_*tmp2_;
   double tmp164_ = -(tmp3_);
   double tmp165_ = tmp164_*tmp13_;
   double tmp166_ = tmp162_*tmp14_;
   double tmp167_ = tmp166_*tmp15_;
   double tmp168_ = tmp165_+tmp167_;
   double tmp169_ = tmp162_*tmp13_;
   double tmp170_ = tmp169_+tmp27_;
   double tmp171_ = tmp164_*tmp15_;
   double tmp172_ = tmp166_*tmp12_;
   double tmp173_ = tmp171_+tmp172_;
   double tmp174_ = tmp162_*tmp15_;
   double tmp175_ = tmp174_+tmp51_;
   double tmp176_ = (tmp168_)*mLocGL_0_0;
   double tmp177_ = (tmp170_)*mLocGL_1_0;
   double tmp178_ = tmp176_+tmp177_;
   double tmp179_ = (tmp178_)*(tmp23_);
   double tmp180_ = (tmp168_)*mLocGL_0_1;
   double tmp181_ = (tmp170_)*mLocGL_1_1;
   double tmp182_ = tmp180_+tmp181_;
   double tmp183_ = (tmp182_)*(tmp41_);
   double tmp184_ = tmp179_+tmp183_;
   double tmp185_ = (tmp168_)*mLocGL_0_2;
   double tmp186_ = (tmp170_)*mLocGL_1_2;
   double tmp187_ = tmp185_+tmp186_;
   double tmp188_ = (tmp187_)*(tmp49_);
   double tmp189_ = tmp184_+tmp188_;
   double tmp190_ = tmp57_*(tmp189_);
   double tmp191_ = -(tmp190_);
   double tmp192_ = tmp191_/tmp133_;
   double tmp193_ = tmp163_*mLocGL_0_0;
   double tmp194_ = tmp4_*mLocGL_1_0;
   double tmp195_ = tmp193_+tmp194_;
   double tmp196_ = (tmp195_)*(tmp23_);
   double tmp197_ = tmp163_*mLocGL_0_1;
   double tmp198_ = tmp4_*mLocGL_1_1;
   double tmp199_ = tmp197_+tmp198_;
   double tmp200_ = (tmp199_)*(tmp41_);
   double tmp201_ = tmp196_+tmp200_;
   double tmp202_ = tmp163_*mLocGL_0_2;
   double tmp203_ = tmp4_*mLocGL_1_2;
   double tmp204_ = tmp202_+tmp203_;
   double tmp205_ = (tmp204_)*(tmp49_);
   double tmp206_ = tmp201_+tmp205_;
   double tmp207_ = (tmp206_)*(tmp78_);
   double tmp208_ = (tmp192_)*(tmp98_);
   double tmp209_ = tmp207_+tmp208_;
   double tmp210_ = -(tmp209_);
   double tmp211_ = tmp210_*(tmp103_);
   double tmp212_ = (tmp211_)/tmp139_;
   double tmp213_ = (tmp173_)*mLocGL_0_0;
   double tmp214_ = (tmp175_)*mLocGL_1_0;
   double tmp215_ = tmp213_+tmp214_;
   double tmp216_ = (tmp215_)*(tmp23_);
   double tmp217_ = (tmp173_)*mLocGL_0_1;
   double tmp218_ = (tmp175_)*mLocGL_1_1;
   double tmp219_ = tmp217_+tmp218_;
   double tmp220_ = (tmp219_)*(tmp41_);
   double tmp221_ = tmp216_+tmp220_;
   double tmp222_ = (tmp173_)*mLocGL_0_2;
   double tmp223_ = (tmp175_)*mLocGL_1_2;
   double tmp224_ = tmp222_+tmp223_;
   double tmp225_ = (tmp224_)*(tmp49_);
   double tmp226_ = tmp221_+tmp225_;
   double tmp227_ = (tmp226_)*(tmp78_);
   double tmp228_ = (tmp192_)*(tmp124_);
   double tmp229_ = tmp227_+tmp228_;
   double tmp230_ = -(tmp229_);
   double tmp231_ = tmp230_*(tmp129_);
   double tmp232_ = (tmp231_)/tmp144_;
   double tmp233_ = -(tmp212_);
   double tmp234_ = -(tmp232_);
   double tmp235_ = tmp151_*tmp7_;
   double tmp236_ = tmp235_*tmp3_;
   double tmp237_ = tmp235_*tmp5_;
   double tmp238_ = -(tmp2_);
   double tmp239_ = tmp238_*tmp3_;
   double tmp240_ = tmp239_*tmp15_;
   double tmp241_ = tmp238_*tmp5_;
   double tmp242_ = tmp241_*tmp15_;
   double tmp243_ = tmp235_*tmp15_;
   double tmp244_ = tmp239_*tmp12_;
   double tmp245_ = tmp241_*tmp12_;
   double tmp246_ = tmp235_*tmp12_;
   double tmp247_ = tmp240_*mLocGL_0_0;
   double tmp248_ = tmp242_*mLocGL_1_0;
   double tmp249_ = tmp247_+tmp248_;
   double tmp250_ = tmp243_*mLocGL_2_0;
   double tmp251_ = tmp249_+tmp250_;
   double tmp252_ = (tmp251_)*(tmp23_);
   double tmp253_ = tmp240_*mLocGL_0_1;
   double tmp254_ = tmp242_*mLocGL_1_1;
   double tmp255_ = tmp253_+tmp254_;
   double tmp256_ = tmp243_*mLocGL_2_1;
   double tmp257_ = tmp255_+tmp256_;
   double tmp258_ = (tmp257_)*(tmp41_);
   double tmp259_ = tmp252_+tmp258_;
   double tmp260_ = tmp240_*mLocGL_0_2;
   double tmp261_ = tmp242_*mLocGL_1_2;
   double tmp262_ = tmp260_+tmp261_;
   double tmp263_ = tmp243_*mLocGL_2_2;
   double tmp264_ = tmp262_+tmp263_;
   double tmp265_ = (tmp264_)*(tmp49_);
   double tmp266_ = tmp259_+tmp265_;
   double tmp267_ = tmp57_*(tmp266_);
   double tmp268_ = -(tmp267_);
   double tmp269_ = tmp268_/tmp133_;
   double tmp270_ = tmp236_*mLocGL_0_0;
   double tmp271_ = tmp237_*mLocGL_1_0;
   double tmp272_ = tmp270_+tmp271_;
   double tmp273_ = tmp2_*mLocGL_2_0;
   double tmp274_ = tmp272_+tmp273_;
   double tmp275_ = (tmp274_)*(tmp23_);
   double tmp276_ = tmp236_*mLocGL_0_1;
   double tmp277_ = tmp237_*mLocGL_1_1;
   double tmp278_ = tmp276_+tmp277_;
   double tmp279_ = tmp2_*mLocGL_2_1;
   double tmp280_ = tmp278_+tmp279_;
   double tmp281_ = (tmp280_)*(tmp41_);
   double tmp282_ = tmp275_+tmp281_;
   double tmp283_ = tmp236_*mLocGL_0_2;
   double tmp284_ = tmp237_*mLocGL_1_2;
   double tmp285_ = tmp283_+tmp284_;
   double tmp286_ = tmp2_*mLocGL_2_2;
   double tmp287_ = tmp285_+tmp286_;
   double tmp288_ = (tmp287_)*(tmp49_);
   double tmp289_ = tmp282_+tmp288_;
   double tmp290_ = (tmp289_)*(tmp78_);
   double tmp291_ = (tmp269_)*(tmp98_);
   double tmp292_ = tmp290_+tmp291_;
   double tmp293_ = -(tmp292_);
   double tmp294_ = tmp293_*(tmp103_);
   double tmp295_ = (tmp294_)/tmp139_;
   double tmp296_ = tmp244_*mLocGL_0_0;
   double tmp297_ = tmp245_*mLocGL_1_0;
   double tmp298_ = tmp296_+tmp297_;
   double tmp299_ = tmp246_*mLocGL_2_0;
   double tmp300_ = tmp298_+tmp299_;
   double tmp301_ = (tmp300_)*(tmp23_);
   double tmp302_ = tmp244_*mLocGL_0_1;
   double tmp303_ = tmp245_*mLocGL_1_1;
   double tmp304_ = tmp302_+tmp303_;
   double tmp305_ = tmp246_*mLocGL_2_1;
   double tmp306_ = tmp304_+tmp305_;
   double tmp307_ = (tmp306_)*(tmp41_);
   double tmp308_ = tmp301_+tmp307_;
   double tmp309_ = tmp244_*mLocGL_0_2;
   double tmp310_ = tmp245_*mLocGL_1_2;
   double tmp311_ = tmp309_+tmp310_;
   double tmp312_ = tmp246_*mLocGL_2_2;
   double tmp313_ = tmp311_+tmp312_;
   double tmp314_ = (tmp313_)*(tmp49_);
   double tmp315_ = tmp308_+tmp314_;
   double tmp316_ = (tmp315_)*(tmp78_);
   double tmp317_ = (tmp269_)*(tmp124_);
   double tmp318_ = tmp316_+tmp317_;
   double tmp319_ = -(tmp318_);
   double tmp320_ = tmp319_*(tmp129_);
   double tmp321_ = (tmp320_)/tmp144_;
   double tmp322_ = -(tmp295_);
   double tmp323_ = -(tmp321_);
   double tmp324_ = -(tmp15_);
   double tmp325_ = tmp151_*tmp12_;
   double tmp326_ = tmp324_*tmp24_;
   double tmp327_ = tmp325_*tmp26_;
   double tmp328_ = tmp326_+tmp327_;
   double tmp329_ = tmp324_*tmp3_;
   double tmp330_ = tmp325_*tmp30_;
   double tmp331_ = tmp329_+tmp330_;
   double tmp332_ = tmp325_*tmp2_;
   double tmp333_ = tmp325_*tmp24_;
   double tmp334_ = tmp15_*tmp26_;
   double tmp335_ = tmp333_+tmp334_;
   double tmp336_ = tmp325_*tmp3_;
   double tmp337_ = tmp15_*tmp30_;
   double tmp338_ = tmp336_+tmp337_;
   double tmp339_ = tmp15_*tmp2_;
   double tmp340_ = (tmp328_)*mLocGL_0_0;
   double tmp341_ = (tmp331_)*mLocGL_1_0;
   double tmp342_ = tmp340_+tmp341_;
   double tmp343_ = tmp332_*mLocGL_2_0;
   double tmp344_ = tmp342_+tmp343_;
   double tmp345_ = (tmp344_)*(tmp23_);
   double tmp346_ = (tmp328_)*mLocGL_0_1;
   double tmp347_ = (tmp331_)*mLocGL_1_1;
   double tmp348_ = tmp346_+tmp347_;
   double tmp349_ = tmp332_*mLocGL_2_1;
   double tmp350_ = tmp348_+tmp349_;
   double tmp351_ = (tmp350_)*(tmp41_);
   double tmp352_ = tmp345_+tmp351_;
   double tmp353_ = (tmp328_)*mLocGL_0_2;
   double tmp354_ = (tmp331_)*mLocGL_1_2;
   double tmp355_ = tmp353_+tmp354_;
   double tmp356_ = tmp332_*mLocGL_2_2;
   double tmp357_ = tmp355_+tmp356_;
   double tmp358_ = (tmp357_)*(tmp49_);
   double tmp359_ = tmp352_+tmp358_;
   double tmp360_ = tmp57_*(tmp359_);
   double tmp361_ = -(tmp360_);
   double tmp362_ = tmp361_/tmp133_;
   double tmp363_ = (tmp362_)*(tmp98_);
   double tmp364_ = -(tmp363_);
   double tmp365_ = tmp364_*(tmp103_);
   double tmp366_ = (tmp365_)/tmp139_;
   double tmp367_ = (tmp335_)*mLocGL_0_0;
   double tmp368_ = (tmp338_)*mLocGL_1_0;
   double tmp369_ = tmp367_+tmp368_;
   double tmp370_ = tmp339_*mLocGL_2_0;
   double tmp371_ = tmp369_+tmp370_;
   double tmp372_ = (tmp371_)*(tmp23_);
   double tmp373_ = (tmp335_)*mLocGL_0_1;
   double tmp374_ = (tmp338_)*mLocGL_1_1;
   double tmp375_ = tmp373_+tmp374_;
   double tmp376_ = tmp339_*mLocGL_2_1;
   double tmp377_ = tmp375_+tmp376_;
   double tmp378_ = (tmp377_)*(tmp41_);
   double tmp379_ = tmp372_+tmp378_;
   double tmp380_ = (tmp335_)*mLocGL_0_2;
   double tmp381_ = (tmp338_)*mLocGL_1_2;
   double tmp382_ = tmp380_+tmp381_;
   double tmp383_ = tmp339_*mLocGL_2_2;
   double tmp384_ = tmp382_+tmp383_;
   double tmp385_ = (tmp384_)*(tmp49_);
   double tmp386_ = tmp379_+tmp385_;
   double tmp387_ = (tmp386_)*(tmp78_);
   double tmp388_ = (tmp362_)*(tmp124_);
   double tmp389_ = tmp387_+tmp388_;
   double tmp390_ = -(tmp389_);
   double tmp391_ = tmp390_*(tmp129_);
   double tmp392_ = (tmp391_)/tmp144_;
   double tmp393_ = -(tmp366_);
   double tmp394_ = -(tmp392_);
   double tmp395_ = tmp151_*(tmp62_);
   double tmp396_ = tmp57_*tmp395_;
   double tmp397_ = -(tmp396_);
   double tmp398_ = tmp397_/tmp133_;
   double tmp399_ = tmp151_*(tmp83_);
   double tmp400_ = tmp399_*(tmp78_);
   double tmp401_ = (tmp398_)*(tmp98_);
   double tmp402_ = tmp400_+tmp401_;
   double tmp403_ = -(tmp402_);
   double tmp404_ = tmp403_*(tmp103_);
   double tmp405_ = (tmp404_)/tmp139_;
   double tmp406_ = tmp151_*(tmp109_);
   double tmp407_ = tmp406_*(tmp78_);
   double tmp408_ = (tmp398_)*(tmp124_);
   double tmp409_ = tmp407_+tmp408_;
   double tmp410_ = -(tmp409_);
   double tmp411_ = tmp410_*(tmp129_);
   double tmp412_ = (tmp411_)/tmp144_;
   double tmp413_ = -(tmp405_);
   double tmp414_ = -(tmp412_);
   double tmp415_ = tmp151_*(tmp68_);
   double tmp416_ = tmp57_*tmp415_;
   double tmp417_ = -(tmp416_);
   double tmp418_ = tmp417_/tmp133_;
   double tmp419_ = tmp151_*(tmp89_);
   double tmp420_ = tmp419_*(tmp78_);
   double tmp421_ = (tmp418_)*(tmp98_);
   double tmp422_ = tmp420_+tmp421_;
   double tmp423_ = -(tmp422_);
   double tmp424_ = tmp423_*(tmp103_);
   double tmp425_ = (tmp424_)/tmp139_;
   double tmp426_ = tmp151_*(tmp115_);
   double tmp427_ = tmp426_*(tmp78_);
   double tmp428_ = (tmp418_)*(tmp124_);
   double tmp429_ = tmp427_+tmp428_;
   double tmp430_ = -(tmp429_);
   double tmp431_ = tmp430_*(tmp129_);
   double tmp432_ = (tmp431_)/tmp144_;
   double tmp433_ = -(tmp425_);
   double tmp434_ = -(tmp432_);
   double tmp435_ = tmp151_*(tmp75_);
   double tmp436_ = tmp57_*tmp435_;
   double tmp437_ = -(tmp436_);
   double tmp438_ = tmp437_/tmp133_;
   double tmp439_ = tmp151_*(tmp96_);
   double tmp440_ = tmp439_*(tmp78_);
   double tmp441_ = (tmp438_)*(tmp98_);
   double tmp442_ = tmp440_+tmp441_;
   double tmp443_ = -(tmp442_);
   double tmp444_ = tmp443_*(tmp103_);
   double tmp445_ = (tmp444_)/tmp139_;
   double tmp446_ = tmp151_*(tmp122_);
   double tmp447_ = tmp446_*(tmp78_);
   double tmp448_ = (tmp438_)*(tmp124_);
   double tmp449_ = tmp447_+tmp448_;
   double tmp450_ = -(tmp449_);
   double tmp451_ = tmp450_*(tmp129_);
   double tmp452_ = (tmp451_)/tmp144_;
   double tmp453_ = -(tmp445_);
   double tmp454_ = -(tmp452_);
   double tmp455_ = mLocProjI_x*(tmp62_);
   double tmp456_ = mLocProjI_y*(tmp68_);
   double tmp457_ = tmp455_+tmp456_;
   double tmp458_ = mLocProjI_z*(tmp75_);
   double tmp459_ = tmp457_+tmp458_;
   double tmp460_ = tmp57_*(tmp459_);
   double tmp461_ = -(tmp460_);
   double tmp462_ = tmp461_/tmp133_;
   double tmp463_ = mLocProjI_x*(tmp83_);
   double tmp464_ = mLocProjI_y*(tmp89_);
   double tmp465_ = tmp463_+tmp464_;
   double tmp466_ = mLocProjI_z*(tmp96_);
   double tmp467_ = tmp465_+tmp466_;
   double tmp468_ = (tmp467_)*(tmp78_);
   double tmp469_ = (tmp462_)*(tmp98_);
   double tmp470_ = tmp468_+tmp469_;
   double tmp471_ = -(tmp470_);
   double tmp472_ = tmp471_*(tmp103_);
   double tmp473_ = (tmp472_)/tmp139_;
   double tmp474_ = mLocProjI_x*(tmp109_);
   double tmp475_ = mLocProjI_y*(tmp115_);
   double tmp476_ = tmp474_+tmp475_;
   double tmp477_ = mLocProjI_z*(tmp122_);
   double tmp478_ = tmp476_+tmp477_;
   double tmp479_ = (tmp478_)*(tmp78_);
   double tmp480_ = (tmp462_)*(tmp124_);
   double tmp481_ = tmp479_+tmp480_;
   double tmp482_ = -(tmp481_);
   double tmp483_ = tmp482_*(tmp129_);
   double tmp484_ = (tmp483_)/tmp144_;
   double tmp485_ = -(tmp473_);
   double tmp486_ = -(tmp484_);
   double tmp487_ = mLocProjJ_x*(tmp62_);
   double tmp488_ = mLocProjJ_y*(tmp68_);
   double tmp489_ = tmp487_+tmp488_;
   double tmp490_ = mLocProjJ_z*(tmp75_);
   double tmp491_ = tmp489_+tmp490_;
   double tmp492_ = tmp57_*(tmp491_);
   double tmp493_ = -(tmp492_);
   double tmp494_ = tmp493_/tmp133_;
   double tmp495_ = mLocProjJ_x*(tmp83_);
   double tmp496_ = mLocProjJ_y*(tmp89_);
   double tmp497_ = tmp495_+tmp496_;
   double tmp498_ = mLocProjJ_z*(tmp96_);
   double tmp499_ = tmp497_+tmp498_;
   double tmp500_ = (tmp499_)*(tmp78_);
   double tmp501_ = (tmp494_)*(tmp98_);
   double tmp502_ = tmp500_+tmp501_;
   double tmp503_ = -(tmp502_);
   double tmp504_ = tmp503_*(tmp103_);
   double tmp505_ = (tmp504_)/tmp139_;
   double tmp506_ = mLocProjJ_x*(tmp109_);
   double tmp507_ = mLocProjJ_y*(tmp115_);
   double tmp508_ = tmp506_+tmp507_;
   double tmp509_ = mLocProjJ_z*(tmp122_);
   double tmp510_ = tmp508_+tmp509_;
   double tmp511_ = (tmp510_)*(tmp78_);
   double tmp512_ = (tmp494_)*(tmp124_);
   double tmp513_ = tmp511_+tmp512_;
   double tmp514_ = -(tmp513_);
   double tmp515_ = tmp514_*(tmp129_);
   double tmp516_ = (tmp515_)/tmp144_;
   double tmp517_ = -(tmp505_);
   double tmp518_ = -(tmp516_);
   double tmp519_ = mLocProjK_x*(tmp62_);
   double tmp520_ = mLocProjK_y*(tmp68_);
   double tmp521_ = tmp519_+tmp520_;
   double tmp522_ = mLocProjK_z*(tmp75_);
   double tmp523_ = tmp521_+tmp522_;
   double tmp524_ = tmp57_*(tmp523_);
   double tmp525_ = -(tmp524_);
   double tmp526_ = tmp525_/tmp133_;
   double tmp527_ = mLocProjK_x*(tmp83_);
   double tmp528_ = mLocProjK_y*(tmp89_);
   double tmp529_ = tmp527_+tmp528_;
   double tmp530_ = mLocProjK_z*(tmp96_);
   double tmp531_ = tmp529_+tmp530_;
   double tmp532_ = (tmp531_)*(tmp78_);
   double tmp533_ = (tmp526_)*(tmp98_);
   double tmp534_ = tmp532_+tmp533_;
   double tmp535_ = -(tmp534_);
   double tmp536_ = tmp535_*(tmp103_);
   double tmp537_ = (tmp536_)/tmp139_;
   double tmp538_ = mLocProjK_x*(tmp109_);
   double tmp539_ = mLocProjK_y*(tmp115_);
   double tmp540_ = tmp538_+tmp539_;
   double tmp541_ = mLocProjK_z*(tmp122_);
   double tmp542_ = tmp540_+tmp541_;
   double tmp543_ = (tmp542_)*(tmp78_);
   double tmp544_ = (tmp526_)*(tmp124_);
   double tmp545_ = tmp543_+tmp544_;
   double tmp546_ = -(tmp545_);
   double tmp547_ = tmp546_*(tmp129_);
   double tmp548_ = (tmp547_)/tmp144_;
   double tmp549_ = -(tmp537_);
   double tmp550_ = -(tmp548_);
   double tmp551_ = (tmp140_)*(tmp130_);
   double tmp552_ = (tmp145_)*(tmp104_);
   double tmp553_ = tmp551_+tmp552_;
   double tmp554_ = mCompCoord[4];
   double tmp555_ = tmp148_*(tmp130_);
   double tmp556_ = (tmp145_)*(tmp131_);
   double tmp557_ = tmp555_+tmp556_;
   double tmp558_ = mCompCoord[6];
   double tmp559_ = (tmp140_)*(tmp132_);
   double tmp560_ = tmp149_*(tmp104_);
   double tmp561_ = tmp559_+tmp560_;
   double tmp562_ = mCompCoord[8];
   double tmp563_ = tmp148_*(tmp132_);
   double tmp564_ = tmp149_*(tmp131_);
   double tmp565_ = tmp563_+tmp564_;
   double tmp566_ = mCompCoord[10];
   double tmp567_ = (tmp153_)*(tmp130_);
   double tmp568_ = tmp154_*(tmp130_);
   double tmp569_ = (tmp153_)*(tmp132_);
   double tmp570_ = tmp154_*(tmp132_);
   double tmp571_ = (tmp156_)*(tmp104_);
   double tmp572_ = (tmp156_)*(tmp131_);
   double tmp573_ = tmp157_*(tmp104_);
   double tmp574_ = tmp157_*(tmp131_);
   double tmp575_ = tmp158_*mLocScNorm;
   double tmp576_ = tmp159_*mLocScNorm;
   double tmp577_ = tmp160_*mLocScNorm;
   double tmp578_ = tmp161_*mLocScNorm;
   double tmp579_ = (tmp212_)*(tmp130_);
   double tmp580_ = (tmp232_)*(tmp104_);
   double tmp581_ = tmp579_+tmp580_;
   double tmp582_ = tmp233_*(tmp130_);
   double tmp583_ = (tmp232_)*(tmp131_);
   double tmp584_ = tmp582_+tmp583_;
   double tmp585_ = (tmp212_)*(tmp132_);
   double tmp586_ = tmp234_*(tmp104_);
   double tmp587_ = tmp585_+tmp586_;
   double tmp588_ = tmp233_*(tmp132_);
   double tmp589_ = tmp234_*(tmp131_);
   double tmp590_ = tmp588_+tmp589_;
   double tmp591_ = (tmp295_)*(tmp130_);
   double tmp592_ = (tmp321_)*(tmp104_);
   double tmp593_ = tmp591_+tmp592_;
   double tmp594_ = tmp322_*(tmp130_);
   double tmp595_ = (tmp321_)*(tmp131_);
   double tmp596_ = tmp594_+tmp595_;
   double tmp597_ = (tmp295_)*(tmp132_);
   double tmp598_ = tmp323_*(tmp104_);
   double tmp599_ = tmp597_+tmp598_;
   double tmp600_ = tmp322_*(tmp132_);
   double tmp601_ = tmp323_*(tmp131_);
   double tmp602_ = tmp600_+tmp601_;
   double tmp603_ = (tmp366_)*(tmp130_);
   double tmp604_ = (tmp392_)*(tmp104_);
   double tmp605_ = tmp603_+tmp604_;
   double tmp606_ = tmp393_*(tmp130_);
   double tmp607_ = (tmp392_)*(tmp131_);
   double tmp608_ = tmp606_+tmp607_;
   double tmp609_ = (tmp366_)*(tmp132_);
   double tmp610_ = tmp394_*(tmp104_);
   double tmp611_ = tmp609_+tmp610_;
   double tmp612_ = tmp393_*(tmp132_);
   double tmp613_ = tmp394_*(tmp131_);
   double tmp614_ = tmp612_+tmp613_;
   double tmp615_ = (tmp405_)*(tmp130_);
   double tmp616_ = (tmp412_)*(tmp104_);
   double tmp617_ = tmp615_+tmp616_;
   double tmp618_ = tmp413_*(tmp130_);
   double tmp619_ = (tmp412_)*(tmp131_);
   double tmp620_ = tmp618_+tmp619_;
   double tmp621_ = (tmp405_)*(tmp132_);
   double tmp622_ = tmp414_*(tmp104_);
   double tmp623_ = tmp621_+tmp622_;
   double tmp624_ = tmp413_*(tmp132_);
   double tmp625_ = tmp414_*(tmp131_);
   double tmp626_ = tmp624_+tmp625_;
   double tmp627_ = (tmp425_)*(tmp130_);
   double tmp628_ = (tmp432_)*(tmp104_);
   double tmp629_ = tmp627_+tmp628_;
   double tmp630_ = tmp433_*(tmp130_);
   double tmp631_ = (tmp432_)*(tmp131_);
   double tmp632_ = tmp630_+tmp631_;
   double tmp633_ = (tmp425_)*(tmp132_);
   double tmp634_ = tmp434_*(tmp104_);
   double tmp635_ = tmp633_+tmp634_;
   double tmp636_ = tmp433_*(tmp132_);
   double tmp637_ = tmp434_*(tmp131_);
   double tmp638_ = tmp636_+tmp637_;
   double tmp639_ = (tmp445_)*(tmp130_);
   double tmp640_ = (tmp452_)*(tmp104_);
   double tmp641_ = tmp639_+tmp640_;
   double tmp642_ = tmp453_*(tmp130_);
   double tmp643_ = (tmp452_)*(tmp131_);
   double tmp644_ = tmp642_+tmp643_;
   double tmp645_ = (tmp445_)*(tmp132_);
   double tmp646_ = tmp454_*(tmp104_);
   double tmp647_ = tmp645_+tmp646_;
   double tmp648_ = tmp453_*(tmp132_);
   double tmp649_ = tmp454_*(tmp131_);
   double tmp650_ = tmp648_+tmp649_;
   double tmp651_ = (tmp473_)*(tmp130_);
   double tmp652_ = (tmp484_)*(tmp104_);
   double tmp653_ = tmp651_+tmp652_;
   double tmp654_ = tmp485_*(tmp130_);
   double tmp655_ = (tmp484_)*(tmp131_);
   double tmp656_ = tmp654_+tmp655_;
   double tmp657_ = (tmp473_)*(tmp132_);
   double tmp658_ = tmp486_*(tmp104_);
   double tmp659_ = tmp657_+tmp658_;
   double tmp660_ = tmp485_*(tmp132_);
   double tmp661_ = tmp486_*(tmp131_);
   double tmp662_ = tmp660_+tmp661_;
   double tmp663_ = (tmp505_)*(tmp130_);
   double tmp664_ = (tmp516_)*(tmp104_);
   double tmp665_ = tmp663_+tmp664_;
   double tmp666_ = tmp517_*(tmp130_);
   double tmp667_ = (tmp516_)*(tmp131_);
   double tmp668_ = tmp666_+tmp667_;
   double tmp669_ = (tmp505_)*(tmp132_);
   double tmp670_ = tmp518_*(tmp104_);
   double tmp671_ = tmp669_+tmp670_;
   double tmp672_ = tmp517_*(tmp132_);
   double tmp673_ = tmp518_*(tmp131_);
   double tmp674_ = tmp672_+tmp673_;
   double tmp675_ = (tmp537_)*(tmp130_);
   double tmp676_ = (tmp548_)*(tmp104_);
   double tmp677_ = tmp675_+tmp676_;
   double tmp678_ = tmp549_*(tmp130_);
   double tmp679_ = (tmp548_)*(tmp131_);
   double tmp680_ = tmp678_+tmp679_;
   double tmp681_ = (tmp537_)*(tmp132_);
   double tmp682_ = tmp550_*(tmp104_);
   double tmp683_ = tmp681_+tmp682_;
   double tmp684_ = tmp549_*(tmp132_);
   double tmp685_ = tmp550_*(tmp131_);
   double tmp686_ = tmp684_+tmp685_;

  mVal[0] = ((tmp135_*tmp158_+tmp146_*tmp159_+tmp147_*tmp160_+tmp150_*tmp161_)-mLocXIm)*mLocScNorm;

  mCompDer[0][0] = ((tmp553_)*tmp135_+(tmp557_)*tmp146_+(tmp561_)*tmp147_+(tmp565_)*tmp150_)*mLocScNorm;
  mCompDer[0][1] = (tmp567_*tmp135_+tmp568_*tmp146_+tmp569_*tmp147_+tmp570_*tmp150_)*mLocScNorm;
  mCompDer[0][2] = (tmp571_*tmp135_+tmp572_*tmp146_+tmp573_*tmp147_+tmp574_*tmp150_)*mLocScNorm;
  mCompDer[0][3] = tmp575_;
  mCompDer[0][4] = 0;
  mCompDer[0][5] = tmp576_;
  mCompDer[0][6] = 0;
  mCompDer[0][7] = tmp577_;
  mCompDer[0][8] = 0;
  mCompDer[0][9] = tmp578_;
  mCompDer[0][10] = 0;
  mCompDer[0][11] = ((tmp581_)*tmp135_+(tmp584_)*tmp146_+(tmp587_)*tmp147_+(tmp590_)*tmp150_)*mLocScNorm;
  mCompDer[0][12] = ((tmp593_)*tmp135_+(tmp596_)*tmp146_+(tmp599_)*tmp147_+(tmp602_)*tmp150_)*mLocScNorm;
  mCompDer[0][13] = ((tmp605_)*tmp135_+(tmp608_)*tmp146_+(tmp611_)*tmp147_+(tmp614_)*tmp150_)*mLocScNorm;
  mCompDer[0][14] = ((tmp617_)*tmp135_+(tmp620_)*tmp146_+(tmp623_)*tmp147_+(tmp626_)*tmp150_)*mLocScNorm;
  mCompDer[0][15] = ((tmp629_)*tmp135_+(tmp632_)*tmp146_+(tmp635_)*tmp147_+(tmp638_)*tmp150_)*mLocScNorm;
  mCompDer[0][16] = ((tmp641_)*tmp135_+(tmp644_)*tmp146_+(tmp647_)*tmp147_+(tmp650_)*tmp150_)*mLocScNorm;
  mCompDer[0][17] = ((tmp653_)*tmp135_+(tmp656_)*tmp146_+(tmp659_)*tmp147_+(tmp662_)*tmp150_)*mLocScNorm;
  mCompDer[0][18] = ((tmp665_)*tmp135_+(tmp668_)*tmp146_+(tmp671_)*tmp147_+(tmp674_)*tmp150_)*mLocScNorm;
  mCompDer[0][19] = ((tmp677_)*tmp135_+(tmp680_)*tmp146_+(tmp683_)*tmp147_+(tmp686_)*tmp150_)*mLocScNorm;
  mVal[1] = ((tmp554_*tmp158_+tmp558_*tmp159_+tmp562_*tmp160_+tmp566_*tmp161_)-mLocYIm)*mLocScNorm;

  mCompDer[1][0] = ((tmp553_)*tmp554_+(tmp557_)*tmp558_+(tmp561_)*tmp562_+(tmp565_)*tmp566_)*mLocScNorm;
  mCompDer[1][1] = (tmp567_*tmp554_+tmp568_*tmp558_+tmp569_*tmp562_+tmp570_*tmp566_)*mLocScNorm;
  mCompDer[1][2] = (tmp571_*tmp554_+tmp572_*tmp558_+tmp573_*tmp562_+tmp574_*tmp566_)*mLocScNorm;
  mCompDer[1][3] = 0;
  mCompDer[1][4] = tmp575_;
  mCompDer[1][5] = 0;
  mCompDer[1][6] = tmp576_;
  mCompDer[1][7] = 0;
  mCompDer[1][8] = tmp577_;
  mCompDer[1][9] = 0;
  mCompDer[1][10] = tmp578_;
  mCompDer[1][11] = ((tmp581_)*tmp554_+(tmp584_)*tmp558_+(tmp587_)*tmp562_+(tmp590_)*tmp566_)*mLocScNorm;
  mCompDer[1][12] = ((tmp593_)*tmp554_+(tmp596_)*tmp558_+(tmp599_)*tmp562_+(tmp602_)*tmp566_)*mLocScNorm;
  mCompDer[1][13] = ((tmp605_)*tmp554_+(tmp608_)*tmp558_+(tmp611_)*tmp562_+(tmp614_)*tmp566_)*mLocScNorm;
  mCompDer[1][14] = ((tmp617_)*tmp554_+(tmp620_)*tmp558_+(tmp623_)*tmp562_+(tmp626_)*tmp566_)*mLocScNorm;
  mCompDer[1][15] = ((tmp629_)*tmp554_+(tmp632_)*tmp558_+(tmp635_)*tmp562_+(tmp638_)*tmp566_)*mLocScNorm;
  mCompDer[1][16] = ((tmp641_)*tmp554_+(tmp644_)*tmp558_+(tmp647_)*tmp562_+(tmp650_)*tmp566_)*mLocScNorm;
  mCompDer[1][17] = ((tmp653_)*tmp554_+(tmp656_)*tmp558_+(tmp659_)*tmp562_+(tmp662_)*tmp566_)*mLocScNorm;
  mCompDer[1][18] = ((tmp665_)*tmp554_+(tmp668_)*tmp558_+(tmp671_)*tmp562_+(tmp674_)*tmp566_)*mLocScNorm;
  mCompDer[1][19] = ((tmp677_)*tmp554_+(tmp680_)*tmp558_+(tmp683_)*tmp562_+(tmp686_)*tmp566_)*mLocScNorm;
}


void cEqAppui_GL__PProjInc_M2CCamBilin::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqAppui_GL__PProjInc_M2CCamBilin Has no Der Sec");
}

void cEqAppui_GL__PProjInc_M2CCamBilin::SetGL_0_0(double aVal){ mLocGL_0_0 = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetGL_0_1(double aVal){ mLocGL_0_1 = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetGL_0_2(double aVal){ mLocGL_0_2 = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetGL_1_0(double aVal){ mLocGL_1_0 = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetGL_1_1(double aVal){ mLocGL_1_1 = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetGL_1_2(double aVal){ mLocGL_1_2 = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetGL_2_0(double aVal){ mLocGL_2_0 = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetGL_2_1(double aVal){ mLocGL_2_1 = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetGL_2_2(double aVal){ mLocGL_2_2 = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetProjI_x(double aVal){ mLocProjI_x = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetProjI_y(double aVal){ mLocProjI_y = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetProjI_z(double aVal){ mLocProjI_z = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetProjJ_x(double aVal){ mLocProjJ_x = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetProjJ_y(double aVal){ mLocProjJ_y = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetProjJ_z(double aVal){ mLocProjJ_z = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetProjK_x(double aVal){ mLocProjK_x = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetProjK_y(double aVal){ mLocProjK_y = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetProjK_z(double aVal){ mLocProjK_z = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetProjP0_x(double aVal){ mLocProjP0_x = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetProjP0_y(double aVal){ mLocProjP0_y = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetProjP0_z(double aVal){ mLocProjP0_z = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetPts0_x(double aVal){ mLocPts0_x = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetPts0_y(double aVal){ mLocPts0_y = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetPts1_x(double aVal){ mLocPts1_x = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetPts2_y(double aVal){ mLocPts2_y = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetScNorm(double aVal){ mLocScNorm = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetXIm(double aVal){ mLocXIm = aVal;}
void cEqAppui_GL__PProjInc_M2CCamBilin::SetYIm(double aVal){ mLocYIm = aVal;}



double * cEqAppui_GL__PProjInc_M2CCamBilin::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "GL_0_0") return & mLocGL_0_0;
   if (aName == "GL_0_1") return & mLocGL_0_1;
   if (aName == "GL_0_2") return & mLocGL_0_2;
   if (aName == "GL_1_0") return & mLocGL_1_0;
   if (aName == "GL_1_1") return & mLocGL_1_1;
   if (aName == "GL_1_2") return & mLocGL_1_2;
   if (aName == "GL_2_0") return & mLocGL_2_0;
   if (aName == "GL_2_1") return & mLocGL_2_1;
   if (aName == "GL_2_2") return & mLocGL_2_2;
   if (aName == "ProjI_x") return & mLocProjI_x;
   if (aName == "ProjI_y") return & mLocProjI_y;
   if (aName == "ProjI_z") return & mLocProjI_z;
   if (aName == "ProjJ_x") return & mLocProjJ_x;
   if (aName == "ProjJ_y") return & mLocProjJ_y;
   if (aName == "ProjJ_z") return & mLocProjJ_z;
   if (aName == "ProjK_x") return & mLocProjK_x;
   if (aName == "ProjK_y") return & mLocProjK_y;
   if (aName == "ProjK_z") return & mLocProjK_z;
   if (aName == "ProjP0_x") return & mLocProjP0_x;
   if (aName == "ProjP0_y") return & mLocProjP0_y;
   if (aName == "ProjP0_z") return & mLocProjP0_z;
   if (aName == "Pts0_x") return & mLocPts0_x;
   if (aName == "Pts0_y") return & mLocPts0_y;
   if (aName == "Pts1_x") return & mLocPts1_x;
   if (aName == "Pts2_y") return & mLocPts2_y;
   if (aName == "ScNorm") return & mLocScNorm;
   if (aName == "XIm") return & mLocXIm;
   if (aName == "YIm") return & mLocYIm;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqAppui_GL__PProjInc_M2CCamBilin::mTheAuto("cEqAppui_GL__PProjInc_M2CCamBilin",cEqAppui_GL__PProjInc_M2CCamBilin::Alloc);


cElCompiledFonc *  cEqAppui_GL__PProjInc_M2CCamBilin::Alloc()
{  return new cEqAppui_GL__PProjInc_M2CCamBilin();
}

